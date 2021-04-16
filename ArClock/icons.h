/*
 * MqClock
 * 
 * (c) Robert Pelczarski 2021
 */

#pragma once

#include <stdint.h>

#include "icons_data.h"

const defIcon icons[] = {
    iArrowGreenLeftData,
    iArrowGreenUpData,
    iRedArrowDownData,
    iRedArrowRightData,
    iPolandFlagData,
    iPikachuData,
    iMarioData,
    iCreeperData,
    iBathtubeData,
    iFireworksData,
    iCandleData,
    iHeartData,
    iFireData,
    iHalloweenData,
    iEmoHappyData,
    iEmoData,
    iEmoSadData,
    iEmo2HappyData,
    iEmo2Data,
    iEmo2SadData,
    iMMotionData,
    iChristmasData,
    iVirusData,
    iCaffeData,
    iBeerData,
    iCalendarData,
    ihomeData,
    iSunCloudyAnimData,
    iMoonData,
    iMoonCloudyData,
    iRainData,
    iSnowData,
    iSunData,
    iBulbOffData,
    iBulbOnData,
    iHeaterOffData,
    iHeaterOnData,
    iChargeData
};

int frame = 0;
unsigned long last_icon_time = 0;

void print_icon (int &x, int &y, int iIndex, std::function<RgbColor (int, int)> color1)
{
  
  const auto &iconData = icons[iIndex];

  int frameSize = iconData.hight*iconData.width;
  const uint32_t* glyph = (iconData.data + (frame%iconData.frames)*frameSize);

  for (int i = 0; i < iconData.width; ++i)
  {
    for (int j = 0; j < iconData.hight; ++j)
    {
      auto ix = x + i;
      auto iy = y + j;
      if (ix >= 0 && ix < PanelWidth && iy >= 0 && iy < PanelHeight)
      {
        auto pixel = topo.Map (ix, iy);
        int idx = j*iconData.width + i;
        
        auto data = *(glyph + idx) & 0x00ffffff;

        uint8_t r = data;
        uint8_t g = data>>8;
        uint8_t b = data>>16;
        if (data > 0)
        {
          auto color = RgbColor(r, g, b);
          //applyColorToPixel(ix, iy, color);
          strip.SetPixelColor (pixel, color);
        } else {
          //strip.SetPixelColor (pixel, RgbColor (100,100,100));
        }
      } 
    }
  }

  x += iconData.width;
  auto now = millis (); 
  if(last_icon_time+100 > now) 
    return;

  last_icon_time = now;
  ++frame;
}

void draw_icon() {

}
