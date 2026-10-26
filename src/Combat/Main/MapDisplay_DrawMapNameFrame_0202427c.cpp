#include <globaldefs.h>
#include "World/Zone3D.h"

extern "C" void *Zone3D_GetInstance(void);
extern "C" int ZoneId_IsGrotto(int zoneId);
extern "C" int STD_GetStringLength(const char *text);
extern "C" void MapDisplay_DrawSprite(void *receiver, int x, int y, int spriteIndex, unsigned char oamSlot, unsigned char priority,
                              unsigned short palette, unsigned char matrixIndex, int scaleX, int scaleY);

// MapDisplay offsets (header: field5a8, scriptNameWidth, and records[25]'s object count)
enum { kMapNameWidthOffset = 0xbe4 }; // usa/eur only
enum {
    kHasMapNameOffset = 0x5a8,        // MapDisplay_DrawMapNameText sets it when the map has a name
    kMiddleObjectCountOffset = 0x4d0, // records[25].count: the middle piece is that many 8-pixel objects
    kRightSprite = 26,
    kRightOamSlot = 0x53,
    kMiddleSprite = 25,
    kMiddleOamSlot = 0x41,
    kLeftSprite = 24,
    kLeftOamSlot = 0x40,
    kFramePalette = 8,
    kMaxNameWidth = 144,
};

static inline int PixelsToFixed(int pixels) {
    return pixels << 12;
}

// Main, originally func_0202427c (USA 0x0202427c, EUR 0x0202428c, JPN 0x02023c44)
extern "C" ARM void MapDisplay_DrawMapNameFrame(void *receiver) {
    unsigned char *self = static_cast<unsigned char *>(receiver);
    Zone3D *zone = static_cast<Zone3D *>(Zone3D_GetInstance());
    unsigned short zoneId = zone->currentZoneID_;
    if (!self[kHasMapNameOffset] || ZoneId_IsGrotto(zoneId) || zoneId == 10000 || zoneId == 10100) {
        return;
    }

    int x = 256;
#if defined(jpn)
    int textWidth = 10 * (STD_GetStringLength(zone->substruct_c_.jpbuffer) / 2);
    int objectCount = textWidth / 8 + 1;
    *reinterpret_cast<unsigned short *>(self + kMiddleObjectCountOffset) = objectCount;
    int width = objectCount * 8;
#else
    int width = (*reinterpret_cast<int *>(self + kMapNameWidthOffset) + 7) & ~7;
    if (width > kMaxNameWidth) {
        width = kMaxNameWidth;
    }
    *reinterpret_cast<unsigned short *>(self + kMiddleObjectCountOffset) = static_cast<unsigned short>(width) >> 3;
#endif

    x -= 8;
    MapDisplay_DrawSprite(receiver, PixelsToFixed(x), 0, kRightSprite, kRightOamSlot, 0, kFramePalette, 0xff, 4096, 4096);
    x -= width;
    MapDisplay_DrawSprite(receiver, PixelsToFixed(x), 0, kMiddleSprite, kMiddleOamSlot, 0, kFramePalette, 0xff, 4096, 4096);
    MapDisplay_DrawSprite(receiver, PixelsToFixed(x - 8), 0, kLeftSprite, kLeftOamSlot, 0, kFramePalette, 0xff, 4096, 4096);
}
