/*
 * MqClock
 * 
 * (c) Robert Pelczarski 2021
 */

#pragma once

uint32_t mqttConnectionTime = 0;
String mqttClientName;

void setMqttClientName() {
  mqttClientName = ("MqClock_"+String(ESP.getChipId(), HEX));
}

void subscribeSensors()
{
  Serial.println("Subscribe MQTT sensors:");
  for (const auto &key_value : settings)
  {
    if (key_value.first[0] == 'q')
    {
      Serial.println(key_value.second);
      if (key_value.second.length() > 0)
      {
        mqttClient.subscribe(key_value.second.c_str());
      }
    }
  }
}

void callback(String topic, byte* message, unsigned int length) {
  Serial.print("Arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String messageTemp;
  
  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();

  // webSocket.sendTXT(0, messageTemp);
  if(topic=="mqclock/message") {
    show_message (messageTemp);
    return;
  }
  if(topic=="mqclock/save") {
    save_settings ();
    return;
  }
  if(topic=="mqclock/preset") {
    load_preset (messageTemp);
    apply();
    return;
  }
  if(topic=="mqclock/reboot") {
    ESP.restart ();
    return;
  }

  String t = String(topic);
  if(t.startsWith("mqclock/settings/")) {
     int pos = t.lastIndexOf("/") ;
     String key = t.substring(pos+1);
     Serial.print(key);
     Serial.print("=");
     Serial.println(messageTemp);
     settings[key.c_str()] = messageTemp.c_str ();
     apply();
  }
  for (const auto &key_value : settings) {
        if(key_value.first[0]=='q') {
          
          if(key_value.second == t) {
            Serial.print('v');
            Serial.print(key_value.first[1]);
            Serial.print(": ");
            Serial.println(messageTemp);

            qValues[key_value.first[1]-'1']=messageTemp;

            break;
          }
        }
      }
}

bool reconnect() {
  if(settings.at (F("mqttHost")).length()==0) {
    return false;
  }
  if(mqttConnectionTime+5000 > millis()) {
    return mqttClient.connected();
  }
  
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    Serial.print("MQTT client name: ");
    Serial.println(mqttClientName);
    mqttConnectionTime = millis();
    if (mqttClient.connect(mqttClientName.c_str())) {
      Serial.println("connected"); 
      mqttConnectionTime = 0;

      mqttClient.subscribe("mqclock/message");
      mqttClient.subscribe("mqclock/save");
      mqttClient.subscribe("mqclock/reboot");
      mqttClient.subscribe("mqclock/preset");
      mqttClient.subscribe("mqclock/settings/#");

      subscribeSensors();
    } else {
      Serial.print("failed, rc=");
      Serial.print(mqttClient.state());
      Serial.println(" try again in 5 seconds");
    }

  return mqttClient.connected();
}
