#include <globaldefs.h>
#include "World/Zone3D.h"
#include "Combat/MapDisplay.h"

// A glyph destination's rectangle (GlyphDestinationRect_InitArray) and the destination GlyphDestination_DrawText draws text into
struct Struct02020520 {
    int pixelOffset;
    short x;
    short y;
    short width;
    short height;
};

struct S_b20c {
    int pixels;
    int rects;
    unsigned char rectCount;
};

// The map name area: 18 OBJ tiles of 8 x 16 pixels, 144 pixels wide; a longer name scrolls (scrollOffset,
// MapDisplay_ScrollMapName)
enum {
    kNameTileCount = 18,
    kNameTileWidth = 8,
    kNameTileHeight = 16,
    kNameAreaWidth = 0x90,
};

extern "C" void* Zone3D_GetInstance(void);
int STD_GetStringLength(const char* text);
extern "C" void* __clear(void* dst, int count);
void GlyphDestinationRect_InitArray(struct Struct02020520* rects, unsigned int count, short* xs, short* ys, short* widths, short* heights);
void GlyphDestination_Clear(struct S_b20c* obj);
void GlyphDestination_SetPixels(void* obj, int value);
void GlyphDestination_SetRects(void* obj, int value, unsigned char flag);
extern "C" int GlyphDestination_DrawText(void* destination, short x, int y, char* text, int color, int font);

// Main, originally func_020230fc (USA 0x020230fc, EUR 0x0202310c, JPN 0x02022b7c)
extern "C" ARM void MapDisplay_DrawMapNameText(MapDisplay* self, char* buffer, int offset) {
    short xs[kNameTileCount];
    short ys[kNameTileCount];
    short widths[kNameTileCount];
    short heights[kNameTileCount];
    struct Struct02020520 rects[kNameTileCount];
    struct S_b20c destination;
    int i;
    int textX;
    int nameWidth;
    int areaWidth;

#if defined(jpn)
    Zone3D* zone = (Zone3D*)Zone3D_GetInstance();
#else
    Zone3D_GetInstance();
    __clear(ys, 0x24);
#endif
    for (i = 0; i < kNameTileCount; i++) {
        xs[i] = i * kNameTileWidth;
#if defined(jpn)
        ys[i] = 0;
#endif
        widths[i] = kNameTileWidth;
        heights[i] = kNameTileHeight;
    }

    self->field5a8 = 0;
#if defined(jpn)
    if (zone->substruct_c_.jpbuffer[0] != 0) {
#else
    if (self->scriptName[0] != 0) {
#endif
        self->field5a8 = 1;
        GlyphDestinationRect_InitArray(rects, kNameTileCount, xs, ys, widths, heights);

#if defined(jpn)
        int tileCount = (STD_GetStringLength(zone->substruct_c_.jpbuffer) / 2 * 10) / 8 + 1;
        textX = tileCount * 8 - STD_GetStringLength(zone->substruct_c_.jpbuffer) / 2 * 10;
        textX /= 2;
#else
        nameWidth = self->scriptNameWidth;
        areaWidth = (nameWidth + 7) & ~7;
        if (nameWidth > kNameAreaWidth) {
            textX = -self->fieldb3c;
        } else {
            textX = (areaWidth - nameWidth) >> 1;
        }
#endif

        GlyphDestination_Clear(&destination);
        GlyphDestination_SetPixels(&destination, (int)(buffer + offset));
        GlyphDestination_SetRects(&destination, (int)rects, kNameTileCount);

#if defined(jpn)
        GlyphDestination_DrawText(&destination, (short)textX, 3, zone->substruct_c_.jpbuffer, 10, 15);
#else
        GlyphDestination_DrawText(&destination, (short)textX, 3, self->scriptName, 0xf, 0);
#endif
    }
}
