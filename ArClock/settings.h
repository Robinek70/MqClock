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
  "Icons"
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
Sequence=d=5;pC=#184640;pX=0;pY=0;pCM=Plasma;pFt=Extra Large;pFmt=H!:M|pFmt=wd-m;pFt=Medium|a=x32;d=2|pFmt=i6i10i9 i11;d=6
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
sequence=a=x0:-210,d50;d=15;pFt=Medium;pFmt=Hi4 M    i0i1i2i4i5i6i7i8i9i10i11i12i13i14i15i16i17i18i19i20i21i22i23i24i26
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

void parse_sequence (const char *data)
{
  std::string string (data);
  std::istringstream iss (string);
  while (!iss.eof ())
  {
    std::string key;
    std::getline (iss, key, '|');
    if (!key.empty ())
    {
      sequence.push_back( key.c_str ());
    }
  }  
}

/**************************************************************************/

void load_settings ()
{
  /*
   * Load fall-back defaults
   */
  parse_settings (String (FPSTR (default_settings)).c_str ());
  
  /*
   * Read from flash
   */
  LittleFS.begin ();
  auto file = LittleFS.open (F("arclock_settings"), "r");
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
}

/**************************************************************************/

void save_settings ()
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
  auto file = LittleFS.open (F("arclock_settings"), "w");
  file.write (str.c_str (), str.length ());
  file.close ();
}

/**************************************************************************/

void load_preset (const String &name)
{
  for (ssize_t i = 0; i != std::end (preset_names) - std::begin (preset_names); ++i)
  {
    if (name == preset_names[i])
    {
      parse_settings (String (FPSTR (presets[i])).c_str ());
      lastSelectedPreset = i;
    }
  }  
}

void load_preset (ssize_t i)
{
  auto it = std::begin (preset_names);
  std::advance(it, i);
  if(it != std::end (preset_names)) {
      parse_settings (String (FPSTR (presets[i])).c_str ());
  } else { i = 0; }

  lastSelectedPreset = i;
}

/**************************************************************************/
