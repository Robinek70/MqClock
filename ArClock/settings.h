/*
 * ArClock
 * 
 * (c) Matt Aubury 2020
 */
 
#pragma once

#include <sstream>
#include <list>

/**************************************************************************/

using Settings = std::map<String, String>;

using Sequence = std::list<String>;

Settings settings;
Sequence sequence;

String qValues[] = {"-", "-", "-", "-", "-", "-"};
bool bValues[] = {false, false, false, false, false, false};
ssize_t lastSelectedPreset = 0;

/**************************************************************************/

/*
 * Default settings
 */
const char default_settings[] PROGMEM = 
R""(OWMAPIKey=
effect=None
effectColor=#ff0022
effectColorMode=Varying
effectDecay=0
effectSpeed=50
masterBrightness=32
autoBrightness=
messageColor=#1ab500
messageRepeat=
password=
message=
pingTarget=8.8.8.8
d=5
pC=#408080
pCM=Constant
pFt=Medium
pFmt=H!:M
pX=1
pY=0
pT=
sC=#364ca0
sCM=Constant
sFt=Small
sFmt=
sX=23
sY=1
sT=
ssid=
timezone=Etc/UTC
weatherLocation=
mqttHost=
useSequence=
q1=RPSensors/out/General/4
q2=
q3=
q4=
q5=
q6=
sOn1=
sOff1=
sOn2=
sOff2=
sOn3=
sOff3=
sOn4=
sOff4=
sOn5=
sOff5=
sOn6=
sOff6=
sChange1=
sChange2=
sChange3=
sChange4=
sChange5=
sChange6=
sequence=a=y0:8;pFmt=H:M|a=x0:-30;pFmt=d-m
a=
aSeq=
useAnime=1
)"";

/**************************************************************************/

/*
 * Standard presets
 */
 
const char *preset_names[] PROGMEM =
{
  "",
  "Vanilla",
  "Minimalist",
  "Utility",
  "Perpetual",
  "Pride",
  "Ping",
  "1990s",
  "Sequence",
  "Icons",
  "User1",
  "User2"
};

const char null_preset[] PROGMEM = "";

const char vanilla_preset[] PROGMEM =
R""(effect=None
pC=#505030
pCM=Constant
pFt=Medium
pFmt=H:M
pX=6
pY=0
sFmt=
useSequence=
useAnime=0
)"";

const char minimalist_preset[] PROGMEM =
R""(effect=None
pC=#184640
pCM=Varing
pFt=Small
pFmt=H:M
pX=14
pY=2
sFmt=
useSequence=
useAnime=0
)"";

const char utility_preset[] PROGMEM =
 R""(effect=None
pC=#20440f
pCM=Constant
pFt=Medium
pFmt=H:M
pX=0
pY=0
sC=#364ca0
sCM=Constant
sFt=Small
sFmt=C*
sX=23
sY=2
useSequence=
useAnime=0
)"";

const char perpetual_preset[] PROGMEM =
R""(effect=None
pC=#204284
pCM=Plasma
pFt=Small
pFmt=y.m.d
pX=3
pY=1
sFmt=
useSequence=
useAnime=0
)"";

const char pride_preset[] PROGMEM =
R""(effect=None
pC=#82166c
pCM=Rainbow
pFt=Extra large
pFmt=H:M
pX=1
pY=0
sFmt=
useSequence=
useAnime=0
)"";

const char ping_preset[] PROGMEM =
R""(effect=Ping graph
effectColor=#320000
effectColorMode=Constant
effectDecay=58
effectSpeed=500
pingTarget=8.8.8.8
pC=#6b6b6b
pCM=Constant
pFt=Small
pFmt=p
pX=10
pY=1
sFmt=
useSequence=
useAnime=0
)"";

const char nineties_preset[] PROGMEM =
R""(effect=Rain
effectColor=#00e000
effectColorMode=Constant
effectDecay=0
effectSpeed=305
pC=#600000
pCM=Constant
pFt=7-segment
pFmt=H:M
pX=3
pY=1
sFmt=
useSequence=
useAnime=0
)"";

const char sequence_preset[] PROGMEM =
R""(effect=Pulse
effectColor=#ffffff
effectColorMode=Constant
effectDecay=118
effectSpeed=188s
pX=0
pY=0
sFmt=
useSequence=1
sequence=d=5;pC=#184640;pX=0;pY=0;pCM=Plasma;pFt=Extra Large;pFmt=H!:M|pFmt=wd-m;pFt=Medium|a=x32;d=2|pFmt=i6i10i9 i11;d=6
useAnime=1
)"";

const char icons_preset[] PROGMEM =
R""(effect=Pulse
effectColor=#ffffff
effectColorMode=Constant
effectDecay=118
effectSpeed=188s
pX=0
pY=0
sFmt=
useSequence=1
sequence=a=x0:-290,d50;d=17;pFt=Medium;pFmt=Hi4 M    i0i1i2i4i5i6i7i8i9i10i11i12i13i14i15i16i17i18i19i20i21i22i23i24i25i26i27i28i29i30i31i32i33i34
useAnime=1
)"";

const char *presets[] PROGMEM =
{
  null_preset,
  vanilla_preset,
  minimalist_preset,
  utility_preset,
  perpetual_preset,
  pride_preset,
  ping_preset,
  nineties_preset,
  sequence_preset,
  icons_preset
};

/**************************************************************************/

void parse_settings (const char *data, char splitter = '\n')
{
  /*
   * TODO: Arduino-ise this
   */
  std::string string (data);
  std::istringstream iss (string);
  while (!iss.eof ())
  {
    std::string key, value;
    std::getline (iss, key, '=');
    std::getline (iss, value, splitter);
    if (!key.empty ())
    {
      if(key[0]=='v') continue;
      settings[key.c_str ()] = value.c_str ();
    }
  }  
}

void split_items (std::list<String>& items, const char *data, char splitter)
{
  std::string string (data);
  std::istringstream iss (string);
  while (!iss.eof ())
  {
    std::string key;
    std::getline (iss, key, splitter);
    if (!key.empty ())
    {
      items.push_back( key.c_str ());
    }
  }
}

void parse_sequence (const char *data)
{
  split_items (sequence, data, '|');
}

/**************************************************************************/

void load_settings (const String& filename)
{
  /*
   * Load fall-back defaults
   */
  parse_settings (String (FPSTR (default_settings)).c_str ());
  
  /*
   * Read from flash
   */
  LittleFS.begin ();
  auto file = LittleFS.open (filename, "r");
  auto bytes = file.size ();
  auto buffer = reinterpret_cast<char *> (malloc (bytes + 1));
  file.read (reinterpret_cast<uint8_t *> (buffer), bytes);
  buffer[bytes] = '\0';
  file.close ();

  /*
   * Load them
   */
  parse_settings (buffer);
  free (buffer);

  Serial.print(F("Settings loaded from file: "));
  Serial.println(filename);
}

/**************************************************************************/

void save_settings (const String& filename)
{
  /*
   * Create settings string
   */
  String str;
  for (const auto &key_value : settings)
  {
    str += key_value.first;
    str += '=';
    str += key_value.second;
    str += '\n';
  }
  
  /*
   * Save changes to flash
   */
  auto file = LittleFS.open (filename, "w");
  file.write (str.c_str (), str.length ());
  file.close ();

  Serial.print(F("Settings stored to file: "));
  Serial.println(filename);
}

const char default_file[] PROGMEM = R""(mqclock_settings)"";

void load_settings() {
  load_settings(default_file);
}

void save_settings() {
  save_settings(default_file);
}

/**************************************************************************/

void load_preset (const String &name)
{
  if(name == F("User1") || name == "User2") {
    load_settings(name);
    return;
  }

  for (ssize_t i = 0; i != std::end (preset_names) - std::begin (preset_names); ++i)
  {
    if (name == preset_names[i])
    {
      parse_settings (String (FPSTR (presets[i])).c_str ());
      lastSelectedPreset = i;
    }
  }  
}

void load_preset(ssize_t i)
{
  auto it = std::begin(preset_names);
  it += i;
  if (it == std::end(preset_names))
  {
    i = 1;
  }
  lastSelectedPreset = i;
  
  Serial.print("Preset: ");
  Serial.print(lastSelectedPreset);
  Serial.print(",  ");
  Serial.println(preset_names[i]);

  load_preset(preset_names[i]);
}

/**************************************************************************/
