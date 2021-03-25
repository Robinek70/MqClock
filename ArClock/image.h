/*
 * MqClock
 * 
 * (c) Robert Pelczarski 2021
 */

#pragma once

#include <stdint.h>

void generate_image() 
{

    int iIndex = server.arg ("i").toInt();

    const auto &iconData = icons[iIndex];
    //auto bitmap = reinterpret_cast<uint8_t *> (malloc (14+40 + 3*8*8 + 4));

    unsigned char file[14] = {
        'B','M', // magic
        0,0,0,0, // size in bytes
        0,0, // app data
        0,0, // app data
        40+14,0,0,0 // start of data offset
    };
    unsigned char info[40] = {
        40,0,0,0, // info hd size
        0,0,0,0, // width
        0,0,0,0, // heigth
        1,0, // number color planes
        24,0, // bits per pixel
        0,0,0,0, // compression is none
        0,0,0,0, // image bits size
        0x13,0x0B,0,0, // horz resoluition in pixel / m
        0x13,0x0B,0,0, // vert resolutions (0x03C3 = 96 dpi, 0x0B13 = 72 dpi)
        0,0,0,0, // #colors in pallete
        0,0,0,0, // #important colors
        };

    int w=iconData.width;//waterfallWidth;
    int h=iconData.hight;//waterfallHeight;

    int padSize  = (4-(w*3)%4)%4;
    int sizeData = w*h*3 + h*padSize;
    int sizeAll  = sizeData + sizeof(file) + sizeof(info);

    file[ 2] = (unsigned char)( sizeAll    );
    file[ 3] = (unsigned char)( sizeAll>> 8);
    file[ 4] = (unsigned char)( sizeAll>>16);
    file[ 5] = (unsigned char)( sizeAll>>24);

    info[ 4] = (unsigned char)( w   );
    info[ 5] = (unsigned char)( w>> 8);
    info[ 6] = (unsigned char)( w>>16);
    info[ 7] = (unsigned char)( w>>24);

    info[ 8] = (unsigned char)( h    );
    info[ 9] = (unsigned char)( h>> 8);
    info[10] = (unsigned char)( h>>16);
    info[11] = (unsigned char)( h>>24);

    info[20] = (unsigned char)( sizeData    );
    info[21] = (unsigned char)( sizeData>> 8);
    info[22] = (unsigned char)( sizeData>>16);
    info[23] = (unsigned char)( sizeData>>24);

    //stream.write( (char*)file, sizeof(file) );
    //stream.write( (char*)info, sizeof(info) );

    unsigned char pad[3] = {0,0,0};

    auto bitmap = reinterpret_cast<uint8_t *> (malloc (sizeAll));

    memcpy(bitmap, file, sizeof(file));
    memcpy(bitmap+sizeof(file), info, sizeof(info));
    //memcpy(bitmap+14+40, info, sizeData);

    int dataOffset = 14+40;

    for ( int y=0; y<h; y++ )
    {
        for ( int x=0; x<w; x++ )
        {
            int idx = (h - y -1)*iconData.width + x;
            
            auto data = *(iconData.data + idx) & 0x00ffffff;

            uint8_t r = data;
            uint8_t g = data>>8;
            uint8_t b = data>>16;

            bitmap[dataOffset+0]=b;
            bitmap[dataOffset+1]=g;
            bitmap[dataOffset+2]=r;
            dataOffset +=3;
        }
        dataOffset += padSize;
    }
    server.send(200, "image/bmp", (uint8_t*)bitmap, sizeAll);
    free(bitmap);
}