/*
 * ArClock
 * 
 * (c) Matt Aubury 2020
 */
 
#pragma once

#include "clock_fonts.h"
#include "settings.h"

/**************************************************************************/
bool binary_mode = false;
int by = 0;

void applyColorToPixel(int ix, int iy, std::function<RgbColor(int, int)> color)
{
  auto pixel = topo.Map(ix, iy);
  auto text_color = color(ix, iy);
  auto effect_color = effect_state[iy][ix];
  auto addsat = [](int a, int b) { return a + b > 255 ? 255 : a + b; };
  strip.SetPixelColor(pixel, RgbColor(
                                 addsat(text_color.R, effect_color.R),
                                 addsat(text_color.G, effect_color.G),
                                 addsat(text_color.B, effect_color.B)));
}

void printBinary(int &x, int &y,int value, const Font &font, std::function<RgbColor (int, int)> color) {

  int mX = &font == &fonts[0] || &font == &fonts[2] ? 2 : 1;
  int mY = &font == &fonts[0] || &font == &fonts[1] ? 2 : 1;

  if (value >= 0)
  {
    String binary("");
    int mask = 1;
    for (int i = 0; i < 31; i++)
    {
      if ((mask & value) >= 1)
        binary = binary + "1";
      else
        binary = binary + "0";
      mask <<= 1;
      if (mask > value)
        break;
    }

    int z = 0;
    int b = settings.at (F("masterBrightness")).toInt ();
    RgbColor pkolor = RgbColor (0, 0, 256/b); // following background
    for (auto it = binary.begin(); it != binary.end(); it++, z++)
    {
      for (int i = 0; i < mX; i++)
      {
        for (int j = 0; j < mY; j++)
        {
          auto ix = x + i + mX * z;
          auto iy = y + j;
          auto p = topo.Map(ix, iy);
          strip.SetPixelColor(p, pkolor);
          if (*it == '1')
          {
            applyColorToPixel(ix, iy, color);
          }
        }
      }
    }
  }

  y += mY;
  if (y > 7)
  {
    y = 0;
    x += 5 * mX;
  }
}

/*
 * Draw a single glyph
 */
void print (int &x, int &y, int digit, const Font &font, std::function<RgbColor (int, int)> color)
{
  if(binary_mode) {
      if(digit < 10) {
        printBinary(x, by, (int)digit, font, color);
      } else { 
        printBinary(x, by, -1, font, color);
      }

      return;
  }

  const auto &glyph = font.glyphs[digit];
  for (int i = 0; i < glyph.width; ++i)
  {
    for (int j = 0; j < font.height; ++j)
    {
      auto ix = x + i;
      auto iy = y + j;
      if (ix >= 0 && ix < PanelWidth && iy >= 0 && iy < PanelHeight)
      {
        auto pixel = topo.Map (ix, iy);
        if (glyph.data[j] & (1 << ((glyph.width - 1) - i)))
        {
          applyColorToPixel(ix, iy, color);
        } else {
          //strip.SetPixelColor (pixel, RgbColor (100,100,100));
        }
      } 
    }
  }

  /*
   * Shift cursor position
   */
  x += glyph.width + 1;
}


void printFloat(int &x, int &y, float value, const Font &font, std::function<RgbColor (int, int)> color, char  *fmt)
{
  char bb[20];
  snprintf(bb, sizeof(bb), fmt, value);
  int d;
  for(int ii = 0; ii < strlen(bb); ii++) {
    if(bb[ii]==' ') d = BLANK;
    else if(bb[ii]=='.') d = PERIOD;
    else if(bb[ii]=='-') d = MINUS;
    else d = bb[ii] - '0';

    print (x, y, d, font, color);
  }
}

void printText(String s, int &x, int &y, std::function<RgbColor (int, int)> color) {
  /*if(s.length()==0) {
    s="-";
  }*/
  message_canvas.writeFillRect (0, 0, message_canvas.width (), message_canvas.height (), 0);
  message_canvas.setFont (&TextFont);
  message_canvas.setCursor (0, 7);
  message_canvas.println (s);
  int16_t sx, sy;
  uint16_t sh, sw;
  message_canvas.getTextBounds (s, 0, 0, &sx, &sy, &sw, &sh);
  
  HtmlColor html_color;
  html_color.Parse<HtmlColorNames> (settings.at (F("messageColor")));
  for (int i = 0; i != PanelWidth; ++i)
  {
    for (int j = 0; j != PanelHeight; ++j)
    {
      auto ix = x + i;
      auto iy = y + j;
      if (ix >= 0 && ix < PanelWidth && iy >= 0 && iy < PanelHeight) {
        auto pixel = topo.Map (ix, iy);
        if (message_canvas.getPixel (i, j))
        { 
            auto text_color = color (ix, iy);
            auto effect_color = effect_state[iy][ix];
            auto addsat = [] (int a, int b) { return a + b > 255 ? 255 : a + b; };
            strip.SetPixelColor (pixel, RgbColor (
              addsat (text_color.R, effect_color.R),
              addsat (text_color.G, effect_color.G),
              addsat (text_color.B, effect_color.B)));
        }
        else
        { 
          //strip.SetPixelColor (pixel, RgbColor (0, 0, 0));
        }
      }
    }
  }
  x += sw + 1;
}

int dayofweek(int d, int m, int y)  
{  
    static int t[] = { 0, 3, 2, 5, 0, 3, 
                       5, 1, 4, 6, 2, 4 };  
    y -= m < 3;  
    return ( y + y / 4 - y / 100 +  
             y / 400 + t[m - 1] + d) % 7;  
}

char const daysOfTheWeek[7][3] = {"Ni", "Pn", "Wt", "Sr", "Cz", "Pt", "So"};


/**************************************************************************/

/*
 * Generate one of the clocks (using settings from prefix "item")
 */
void clockInner (String item, String ff, int& x, int& y )
{
  /*
   * Position 
   */ 
  // int x = settings.at (item + "X").toInt ();
  // int y = settings.at (item + "Y").toInt ();
  
  // binary_mode = false;
  // by = y;

  /*
   * Font 
   */
  const auto &font = clock_font (settings.at (item + "Ft"));

  /*
   * Colour generating function
   */
  HtmlColor html_color;
  html_color.Parse<HtmlColorNames> (settings.at (item + "C"));
  auto base = RgbColor (html_color);
  auto color_function = color_mode (settings.at (item + "CM"));
  std::function<RgbColor (int, int)> color;
  std::function<RgbColor (int, int)> colorSelected =
  [&] (int x, int y)
  {
    return color_function (base, x, y);
  };
  std::function<RgbColor (int, int)> colorBlack =
  [&] (int x, int y)
  {
    return RgbColor (0,0,0);
  };
  auto text = settings.at (item + "T");
      
  /*
   * Print each item
   */
  static uint32_t lastFlash = millis();
  char fmt02[7] = "%02.0f";

  //auto ff = settings.at (item + "Fmt");
  auto it = ff.begin();

  for(;it!=ff.end();++it)
  {
    auto format = (*it);
    color = colorSelected;
    if(format=='!' || format=='f') {
      if(seconds & 1) {
        color = colorBlack;
      }
      it++;
      if(it == ff.end()) break;
      format = (*it);
    }
    switch (format)
    {
      case 'Y':
        printFloat (x, y, year, font, color, fmt02);
        break;
        
      case 'y':
        printFloat (x, y, year%100, font, color, fmt02);
        break;
        
      case 'm':
        printFloat (x, y, month, font, color, fmt02);
        break;
        
      case 'd':
        printFloat (x, y, day, font, color, fmt02);
        break;
      case 'w':
        printText(daysOfTheWeek[dow], x, y, color); 
        break;
        
      case 'H': /* 24-hour */
        if (hours < 10)
        {
          print (x, y, BLANK, font, color);
        }
        else
        {
          print (x, y, hours / 10, font, color);
        }
        print (x, y, hours % 10, font, color);
        break;

      case 'h': /* 12-hour */
        if (hours > 12) /* PM */
        {
          hours -= 12;
        }
        if (hours == 0) /* 12 AM */
        {
          hours = 12;
        }
        if (hours < 10)
        {
          print (x, y, BLANK, font, color);
        }
        else
        {
          print (x, y, hours / 10, font, color);
        }
        print (x, y, hours % 10, font, color);
        break;

      case 'M':
        printFloat (x, y, minutes, font, color, fmt02);
        break;

      case 'S':
        printFloat (x, y, seconds, font, color, fmt02);
        break;

      case ':':
        print (x, y, COLON, font, color);
        break;
      
      case '.':
        print (x, y, PERIOD, font, color);
        break;

      case '\'':
      case '*': /* for iOS */
        print (x, y, DEGREES, font, color);
        break;

      case '-':
        print (x, y, MINUS, font, color);
        break;

      case 'p':
        if (ping_time < 1000)
        {
          printFloat (x, y, ping_time, font, color, "%3.0f");
        }
        break;

      case 'C':
      case 'F':
        if (celsius == -99)
        {
          /*
           * No current value
           */
          print (x, y, MINUS, font, color);
          print (x, y, MINUS, font, color);
        }
        else
        {
          auto temp = static_cast<int> (round (format == 'C' ? celsius : 32 + ((celsius *9) / 5)));
          if (temp >= 0 && temp < 10)
          {
            print (x, y, BLANK, font, color);
          }
          if (temp < 0) 
          {
            print (x, y, MINUS, font, color);
            temp = -temp;
          }
          if (temp >= 100)
          {
            print (x, y, temp / 100, font, color);
          }
          if (temp >= 10)
          {
            print (x, y, (temp / 10) % 10, font, color);
          }
          print (x, y, temp % 10, font, color);
        }
        break;
        
      case 'T':
        if (tempLocal == -127)
        {
          /*
           * No current value
           */
          print (x, y, MINUS, font, color);
          print (x, y, MINUS, font, color);
        }
        else
        {
          auto temp = static_cast<int> (round (format == 'T' ? 10*tempLocal : 32 + ((10*tempLocal *9) / 5)));
          
          if (temp >= 0 && temp < 100)
          {
            print (x, y, BLANK, font, color);
          }
          if (temp < 0) 
          {
            print (x, y, MINUS, font, color);
            temp = -temp;
          }
          if (temp >= 100)
          {
            print (x, y, (temp / 100), font, color);
            temp = temp - (temp /100)*100;
          }
          print (x, y, temp / 10, font, color);
          temp = temp - (temp /10)*10;
          print (x, y, PERIOD, font, color);
          print (x, y, temp % 10, font, color);
        }
        break;
        
      case 'L':
        printFloat (x, y, round(light), font, color, "%.0f");
        break;
      case 'b':
          binary_mode = true;
          continue;
        break;
      case 'X':
        printText(text, x, y, color); 
        break;
      case 'x':
        if(++it != ff.end()) {
          //std::advance(it, 1);
          format = (*it);
          printText(String(format), x, y, color); 
        }
        break;
      case 'i':
        {
          auto ii = 0;
          char fmt[10];
          while (++it != ff.end() && *it >= '0' && *it <= '9')
          {
            fmt[ii++] = *it;
          };
          fmt[ii] = '\0';
          if (ii > 0)
          {
            int ic = atoi(fmt);
            print_icon(x, y, ic, color);
          }
          --it;
        }
        break;
      case 'V':
      case 'v':
        if(++it != ff.end()) {
          auto ch = (*it);
          auto val = qValues[ch-'1'];
          if(format == 'v') {
            printText(val, x, y, color);
          } else {
            char fmt[10] = "%f"; char* fmt_p = fmt;
            while (it != ff.end()) {
              it++;
              *fmt_p=*it;
              fmt_p++;
              if(*it=='f' || *it=='d') {
                *fmt_p='\0';
                break;
              }
            }
 
            float f = atof(val.c_str());
            printFloat (x, y, f, font, color, fmt);
          }
        }
        break;
      case 's':
        if(++it != ff.end()) {
          auto ch = (*it);
          auto p = const_cast<char*>(qValues[ch-'1'].c_str());
          for ( ; *p; ++p) *p = tolower(*p);
          String st = qValues[ch-'1'];

          if((st == "on") || (st == "1")) {
           st = settings.at ("sOn" + String(ch));
          } else { 
            st = settings.at ("sOff" + String(ch));
          }

          clockInner(item, st, x , y);
        }
      case ' ':
        ++x;
        break;
    }

    binary_mode = false;
  }
}

void clock(String item) {

  /*
   * Position 
   */ 
  int x = settings.at (item + "X").toInt ();
  int y = settings.at (item + "Y").toInt ();

  binary_mode = false;
  by = y;

  auto ff = settings.at (item + "Fmt");

  clockInner(item, ff, x, y);

}

/**************************************************************************/
