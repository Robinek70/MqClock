/*
 * ArClock
 * 
 * (c) Matt Aubury 2020
 */
 
#pragma once

#include <iostream>
#include <sstream>
#include "settings.h"
#include "color.h"

/*
 * Effect states
 */
static RgbColor effect_state[PanelHeight][PanelWidth];
static uint8_t effect_x[8], effect_y[8];

/**************************************************************************/

void effect_decay (float rate)
{
  for (int i = 0; i != PanelWidth; ++i)
  {
    for (int j = 0; j != PanelHeight; ++j)
    {
      auto &color = effect_state[j][i];
      color.R *= rate;
      color.G *= rate;
      color.B *= rate;
    }
  }
}

/**************************************************************************/

void effect_show ()
{
  for (int i = 0; i != PanelWidth; ++i)
  {
    for (int j = 0; j != PanelHeight; ++j)
    {
      auto pixel = topo.Map (i, j);
      strip.SetPixelColor (pixel, effect_state[j][i]);
    }
  }
}

/**************************************************************************/

RgbColor effect_color (int x, int y)
{
  HtmlColor html_color;
  html_color.Parse<HtmlColorNames> (settings.at ("effectColor"));
  return color_mode (settings.at ("effectColorMode")) (RgbColor (html_color), x, y);
}

/**************************************************************************/

/*void effect_fill_color (RgbColor color)
{
  for (int i = 0; i != PanelWidth; ++i)
  {
    for (int j = 0; j != PanelHeight; ++j)
    {
      effect_state[j][i] = color;
    }
  }
}*/

void effect_blank ()
{
  for (int i = 0; i != PanelWidth; ++i)
  {
    for (int j = 0; j != PanelHeight; ++j)
    {
      effect_state[j][i] = RgbColor (0x00, 0x00, 0x00);
    }
  }
}

void effect_fill ()
{
  for (int i = 0; i != PanelWidth; ++i)
  {
    for (int j = 0; j != PanelHeight; ++j)
    {
      effect_state[j][i] = effect_color (i, j);
    }
  }
}


/**************************************************************************/

void effect_pulse ()
{
  int x = rand () % PanelWidth;
  int y = rand () % PanelHeight;
  effect_state[y][x] = effect_color (x, y);    
}

/**************************************************************************/

void effect_chase ()
{
  auto &x = effect_x[0];
  static uint8_t dx = 1;
  effect_state[PanelHeight - 1][x] = effect_color (x, PanelHeight - 1);    
  x += dx;
  if (x == 0 || x == PanelWidth - 1)
  {
    dx = -dx;
  }
}

/**************************************************************************/

void effect_rain ()
{
  for (ssize_t i = 0; i != std::end (effect_x) - std::begin (effect_x); ++i)
  {
    auto &x = effect_x[i];
    auto &y = effect_y[i];
    if (y < PanelHeight)
    {
      //auto pixel = topo.Map (x, y);
      //auto c = strip.GetPixelColor (pixel);
      //if(!c.CalculateBrightness())
        effect_state[y][x] = effect_color (x, y);
      ++y;
    }
    else
    {
      if ((rand () & 0x7) == 0)
      {
        y = 0;
        x = rand () % PanelWidth;
      }
    }
  }
}

/**************************************************************************/

void effect_snow ()
{ 
  /*
   * Shift snow down, where possible
   */
  for (int j = PanelHeight - 1; j > 0; --j)
  {
    for (int i = 0; i != PanelWidth; ++i)
    {
      auto di = i;
      if ((rand () & 0x3) == 0 && i > 0 &&  i < PanelWidth - 1)
      {
        di += ((rand () & 0x1) ? 1 : -1);
      }
      if (effect_state[j][i].R < 0x10)
      {
        effect_state[j][i].R += effect_state[j - 1][di].R;
        effect_state[j][i].G += effect_state[j - 1][di].G;
        effect_state[j][i].B += effect_state[j - 1][di].B;
        effect_state[j - 1][di] = RgbColor (0, 0, 0);
      }
    }
  }

  /*
   * Spawn new snow
   */
  effect_state[0][rand () % PanelWidth] = RgbColor (0xa0, 0xa0, 0xa0);
}

/**************************************************************************/

void effect_bounce ()
{
  auto &x = effect_x[0];
  auto &y = effect_y[0];
  static uint8_t dx = 1, dy = 1;
  x += dx;
  y += dy;
  if (x >= PanelWidth || y >= PanelHeight)
  {
    x = rand () % PanelWidth;
    y = rand () % PanelHeight;
  }  
  if (x == 0 || x == PanelWidth - 1)
  {
    dx = -dx;    
  }
  if (y == 0 || y == PanelHeight - 1)
  {
    dy = -dy;
  }
  effect_state[y][x] = effect_color (x, y);
}

/**************************************************************************/

void effect_ping_graph ()
{
  for (int x = 0; x != PanelWidth; ++x)
  {
    int top = PanelHeight - (ping_history[x] / 16);
    if (top < 0) 
    {
      top = 0;
    }
    for (int y = top; y != PanelHeight; ++y)
    {
      effect_state[y][x] = effect_color (x, y);
    }
  }
}

/**************************************************************************/

const char *effect_names[] PROGMEM =
{
  "None",
  "Fill",
  "Pulse",
  "Rain",
  "Bounce",
  "Chase",
  "Ping graph",
  "Snow"
};

using EffectFunction = void (*)();

const EffectFunction effect_functions[] =
{
  effect_blank,
  effect_fill,
  effect_pulse,
  effect_rain,
  effect_bounce,
  effect_chase,
  effect_ping_graph,
  effect_snow
};

/**************************************************************************/

void effect (const String &name)
{
  auto timeout = [] (int count)
  {
    static auto next = millis ();
    auto now = millis ();
    if (now >= next)
    {
      next = now + count;
      return true;
    }
    else
    {
      return false;
    }
  };
    
  if (month == 12 && day == 25)
  {
    /* 
     * "Easter" egg. Apologies for obvious cultural insensitivity.
     */
    if (timeout (50))
    {
      effect_snow ();
      effect_decay (0.96);
    }
    effect_show ();
  }
  else
  {
    if (name == F("Ping graph"))
    {
      effect_ping_graph ();
    }
    else if (timeout (500 - settings["effectSpeed"].toInt ()))
    {
      for (ssize_t i = 0; i != std::end (effect_names) - std::begin (effect_names); ++i)
      {
        if (name == effect_names[i])
        {
          (effect_functions[i]) ();
        }
      }
    };    
    effect_show ();
    effect_decay (1.0 - (1.0 / (202 - settings.at (F("effectDecay")).toFloat ())));
  }
}

int ddx = 0;
int ddy = 0;
int adelay = 0;


void anime_pos()
{
  int x = settings.at("pX").toInt();
  int y = settings.at("pY").toInt();
  int dx, dy;
  if (x == ddx)
    dx = 0;
  else if (ddx > x)
    dx = 1;
  else
    dx = -1;
  if (y == ddy)
    dy = 0;
  else if (ddy > y)
    dy = 1;
  else
    dy = -1;

  if (dx != 0)
    settings["pX"] = x + dx;
  if (dy != 0)
    settings["pY"] = y + dy;
}

void applyAnime(const String &a) {
  int pos = 0;

  if ((a.length() > 0) && settings.at (F("useAnime")).toInt())
  {
    std::string aa(a.c_str());
    std::istringstream iss (aa);
    while (!iss.eof ())
    {
      std::string item;
      std::getline (iss, item, ',');
      char dir = item[0];
      int value = atoi(item.substr(1).c_str());

      if (dir == 'x') {
        ddx = value;
      }
      if (dir == 'y') {
        ddy = value;
      }
      if (dir == 'd') {
        adelay = value;
      }

      std::size_t pos = item.find(":");
      if(pos != -1) {
          value = atoi(item.substr(pos+1).c_str());
          if(dir == 'x')
            settings["pX"] = value;
          if(dir == 'y')
            settings["pY"] = value;
      }
    }
  }
}

unsigned long last_anime_time = 0;

void anime()
{
    if(settings.at (F("useAnime")).toInt()) {
      
      auto now = millis (); 
      if(last_anime_time + adelay > now) 
        return;

      anime_pos();
      last_anime_time = now;
    }
}

/**************************************************************************/
  
