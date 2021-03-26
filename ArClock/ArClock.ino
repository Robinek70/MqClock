/*
 * ArClock
 * 
 * (c) Matt Aubury 2020
 */
 
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <ESP8266WebServer.h>
#include <DNSServer.h>
#include <PubSubClient.h>
//#include <WebSocketsServer.h>

#include <Pinger.h>
#include <PinButton.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-compare" /* rolls eyes */
#include <Adafruit_GFX.h>
#include <Fonts/Picopixel.h>
#pragma GCC diagnostic pop

#include <LittleFS.h>

#include <NeoPixelBrightnessBus.h>

#define FASTLED_INTERNAL /* suppress warnings */
#include <FastLED.h>

#include <time.h>
#include <sys/time.h>

/**************************************************************************/

/*
 * Definition of the LED matrix layout 
 */
constexpr uint8_t PanelWidth = 32;
constexpr uint8_t PanelHeight = 8;
constexpr uint16_t PixelCount = PanelWidth * PanelHeight;

NeoTopology<ColumnMajorAlternating180Layout> topo (PanelWidth, PanelHeight);
NeoPixelBrightnessBus<NeoGrbFeature, Neo800KbpsMethod> strip (PixelCount);

/**************************************************************************/

/*
 * Networking globals
 */
DNSServer dnsServer;
ESP8266WebServer server (80);
//WebSocketsServer webSocket(81);
IPAddress APIP (192, 168, 4, 1);
WiFiClient client;
Pinger pinger;
WiFiClient wifi4mqttClient;
PubSubClient mqttClient(wifi4mqttClient);

/**************************************************************************/

/*
 * Additional global state
 */
int16_t year = 0;
int8_t month = 0;
int8_t day = 0;
int8_t dow = 0;
int8_t hours = 0;
int8_t minutes = 0;
int8_t seconds = 0;
int16_t ping_time = 1000;
int16_t ping_history[PanelWidth];
float celsius = -99; /* bit nippy */
float tempLocal = -127;
float prevTempLocal = -127;
float light = 20;
bool autoBright = false;
int current_seq = 0;
uint32_t nextSequenceTime = 10000;
PinButton myButton(13);
  
/**************************************************************************/

/*
 * Include the functionality
 */
#include "text_font.h"
#include "timezones.h"
#include "icons.h"
#include "image.h"
#include "web.h"
#include "clock.h"
#include "effect.h"
#include "settings.h"
#include "weather.h"
#include "message.h"
#include "wifi_logo.h"
#include "mqtt.h"

/**************************************************************************/

/*
 * Dallas
 */
#include <OneWire.h>
#include <DallasTemperature.h>
// GPIO where the DS18B20 is connected to
const int oneWireBus = 2;   
int numberOfDevices = 0;  

uint32_t lastSendTemp;

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(oneWireBus);

// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature sensors(&oneWire);

// Lighting
int LDRpin = A0; 
uint32_t lastSendLight;

/*void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length) {

    switch(type) {
        case WStype_DISCONNECTED:
            Serial.printf("[%u] Disconnected!\n", num);
            break;
        case WStype_CONNECTED: {
            IPAddress ip = webSocket.remoteIP(num);
            Serial.printf("[%u] Connected from %d.%d.%d.%d url: %s\n", num, ip[0], ip[1], ip[2], ip[3], payload);

            // send message to client
            webSocket.sendTXT(num, "Connected");
        }
            break;
        case WStype_TEXT:
            Serial.printf("[%u] get Text: %s\n", num, payload);

            break;
    }

}*/

/**************************************************************************/

void setup ()
{ 
  /*
   * Setup serial for debug
   */
  Serial.begin (115200);
  while (!Serial);

  /*
   * Configure strip
   */
  strip.Begin ();
  strip.SetPixelColor (0, RgbColor (0x40, 0x00, 0x00));
  strip.Show ();

  /*
   * Load settings from flash
   * 
   * Comment this out if you think you've corrupted your settings - 
   * e.g. if you're seeing a boot loop. Don't forget to put it back
   * when you've fixed the problem!
   */
  load_settings ();

  /*
   * Start WiFi in station mode if possible
   */
  WiFi.mode (WIFI_STA);
  WiFi.persistent (false);
  if (settings.at (F("ssid")) != "")
  {
    Serial.print (F("\nConnecting to "));
    Serial.print (settings.at (F("ssid")));
    WiFi.begin (settings.at (F("ssid")), settings.at (F("password")));
  
    /*
     * Wait for WiFi to connect before starting up MDNS
     */
    auto timeout = millis () + (30 * 1000);
    while (WiFi.status () != WL_CONNECTED && millis () < timeout)
    {
      wifi_logo (RgbColor (0x80, 0x80, 0x80));
      delay (15);
    }
  }

  /*
   * We either succeeded in connecting to a network, or failed (because
   * the details are wrong or missing)
   */
  if (WiFi.status () == WL_CONNECTED)
  {
    Serial.print (F("\nIP address: "));
    Serial.println (WiFi.localIP ());
    
    /*
     * Start mDNS responder, so we can be found as http://mqclock.local
     */
    MDNS.begin (F("mqclock"));

    /*
     * Setup pinger
     */
    pinger.OnReceive ([] (const PingerResponse &response)
    {
      if (response.DestIPAddress == IPAddress (255, 255, 255, 255))
      {
        /*
         * Bail if the target is invalid
         */
        return false;
      }

      /*
       * 1000 == failure
       */
      ping_time = response.ReceivedResponse ? response.ResponseTime : 1000;
      for (int x = 1; x != PanelWidth; ++x)
      {
        ping_history[x - 1] = ping_history[x];
      }
      ping_history[PanelWidth - 1] = ping_time;
      return true;
    });

    /*
     * Indicate to the user that WiFi is up
     */
    for (int N = 0x200; N >= 0; N -= 3)
    {
      wifi_logo (RgbColor (N > 0x180 ? N - 0x180 : 0, N > 0x100 ? 0x80 : (N > 0x80 ? N - 0x80 : 0), N > 0x180 ? N - 0x180 : 0));
      delay (15);
    }
    String message (F("Visit http://"));
    message += WiFi.localIP ().toString ();
    message += F(" to configure");
    show_message (message);
  }
  else
  {
    /*          
     * Start SoftAP mode with captive portal
     */
    WiFi.mode (WIFI_AP);
    WiFi.softAPConfig (APIP, APIP, IPAddress (255, 255, 255, 0));
    WiFi.softAP (F("MqClock"));
    dnsServer.start (53, "*", APIP);
    for (int N = 0x200; N >= 0; N -= 3)
    {
      wifi_logo (RgbColor (N > 0x180 ? N - 0x180 : 0, N > 0x180 ? N - 0x180 : 0, N > 0x100 ? 0x80 : (N > 0x80 ? N - 0x80 : 0)));
      delay (15);
    }
    show_message (F("Connect to MqClock WiFi network to setup"));
  }
  
  /*
   * Apply other settings
   */
  apply ();

  /*
   * Start the webserver
   */
  server.on (F("/"), handle_root);
  server.on (F("/mqtt"), handle_mqtt);
  server.on (F("/part"), handle_part);
  server.on (F("/save"), handle_save);
  server.on (F("/update"), handle_update);
  server.on (F("/change"), handle_change);
  server.on (F("/timezones"), handle_timezones);
  server.on (F("/reboot"), handle_reboot);
  server.on (F("/pure-min.css"), [] { server.send (200, "text/css", pure_min_css); });
  server.on (F("/grids-responsive-min.css"), [] { server.send (200, "text/css", grids_responsive_min_css); });
  server.on (F("/script.js"), [] { server.send (200, "text/js", script_js); });
  server.on (F("/show"), handle_show);
  server.on (F("/load_preset"), handle_load_preset);
  server.on (F("/icon"), generate_image);
  server.onNotFound (handle_root);
  server.begin ();

  //webSocket.begin();                          // start the websocket server
  //webSocket.onEvent(webSocketEvent);          // if there's an incomming websocket message, go to function 'webSocketEvent'
  //Serial.println("WebSocket server started.");

  sensors.begin();
  numberOfDevices = sensors.getDeviceCount();
  
  // locate devices on the bus
  Serial.print(F("Locating DS devices... Found: "));
  Serial.print(numberOfDevices, DEC);
  Serial.println(F(" device(s)."));
  Serial.print(F("Chip ID: "));
  Serial.println (String(ESP.getChipId(), HEX));

  auto mqtt_server = settings.at (F("mqttHost")).c_str();
  Serial.print(F("MQTT server: "));
  Serial.print (mqtt_server);
  Serial.println (F(":1883"));
 
  setMqttClientName();
  mqttClient.setServer(mqtt_server, 1883);
  mqttClient.setCallback(callback);

  // d=3;pX=0;pY=0;pCM=Plasma;pFt=Extra Large;pFmt=H!:M|pFmt=wd-m;pFt=Medium|pFmt=v2*xC;sFmt=S;sFt=Small;sX=25|pFmt=V4%5.1f*xC;sFmt=;pFmt=V1%4.0fxw
  //parse_sequence(command);
  //sequence.clear();
  //current_seq = 0;
}

/**************************************************************************/
float lightTmp = 300;
void loop ()
{
  myButton.update();
  if (myButton.isSingleClick())
  {
    load_preset(lastSelectedPreset + 1);
  } else if (myButton.isDoubleClick()) {
    Serial.println("Double CLICK");
  } else if (myButton.isLongClick()) {
    Serial.println("Long CLICK");
  }
  
  if (!mqttClient.connected()) {
    reconnect();
  } else {
    mqttClient.loop();
  }

  /*
   * Banner messages take priority
   */
  if (!message ())
  {
     if((settings.at (F("useSequence")).toInt()) && millis() > nextSequenceTime) {
       auto it = sequence.begin();
       std::advance(it, current_seq);
       Serial.print(*it);
       Serial.print(',');
       Serial.print(current_seq);
       Serial.print(',');
       Serial.println(sequence.size());

       if(settings.at (F("aSeq")).length()>0) {
          settings["a"] = settings.at (F("aSeq"));
          currentAnimeHash = 0; // force apply new sequence for every step
       }

       parse_settings((*it).c_str(), ';');
       apply();
       current_seq++;
       if(current_seq >= sequence.size()) {
          current_seq = 0;
       }
       nextSequenceTime = millis() + settings.at (F("d")).toFloat()*1000;
     }

    anime();
    /*
     * Update the effect
     */
    effect (settings.at (F("effect")));
  
    /*
     * Get the temperature
     */
    fetch_weather ();
      
    /*
     * Get the time
     */
    auto now = ::time (nullptr);
    auto tm = ::localtime (&now);
    year = 1900 + tm->tm_year;
    month = tm->tm_mon + 1;
    day = tm->tm_mday;
    dow = tm->tm_wday;
    hours = tm->tm_hour;
    minutes = tm->tm_min;
    seconds = tm->tm_sec;
    
    /*
     * Display the clocks (suppressed for the first few seconds to allow NTP startup)
     */
    if (now > 5)
    {
      clock (F("p"));
      clock (F("s"));
    }  
  }
   
  /*
   * Display the data
   */
  strip.Show ();

  /*
   * Handle web server events
   */
  //webSocket.loop();
  server.handleClient ();
  MDNS.update ();
  dnsServer.processNextRequest ();

  // Dallas
  if(numberOfDevices>0) {
    uint32_t delta = millis() - lastSendTemp;
    if( delta > 30000) {
      sensors.requestTemperatures(); 
      if( delta > 31000) {
        tempLocal = round(10*sensors.getTempCByIndex(0))/10.;
        if(tempLocal == -127.00) {
          Serial.println("Failed to read from DS18B20 sensor");          
        } else {
          Serial.print("Temperature Celsius: ");
          Serial.println(tempLocal);
          if (prevTempLocal != tempLocal) {
              static char tempTemp[7];
              dtostrf(tempLocal, 6, 1, tempTemp);
              mqttClient.publish("mqclock/temp", tempTemp);
              prevTempLocal = tempLocal;
          }
        
        }
        lastSendTemp = millis();
      }
    }
  }

  // Lighting
  uint32_t delta = millis() - lastSendLight;
  int l = analogRead(LDRpin);
  lightTmp = (lightTmp*9 + l)/(9 + 1);
  if(delta>1000) {
    light = lightTmp;
    lastSendLight = millis();

    if(autoBright) {
        float x = max(400.f, light);
        x = min(x,1000.f);
        int b = map(x, 400.f, 1000.f, 4, 30);
        strip.SetBrightness(b);
    }
  }

}

/**************************************************************************/
