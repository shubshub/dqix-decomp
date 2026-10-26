#include <globaldefs.h>
#include "std_library_functions.h"
#include "Resource/Font.h"

// One rectangle of a glyph destination: where its 4bpp pixels start, and its place and size in the text
struct Struct02020520 {
    int pixelOffset;
    short x;
    short y;
    short width;
    short height;
};

// A glyph destination: the pixel buffer and its rectangles
struct S_b20c {
    int pixels;
    int rects;
    unsigned char rectCount;
};

extern "C" void GlyphDestination_Clear(struct S_b20c* destination);
extern "C" void GlyphDestination_SetPixels(void* destination, int pixels);
extern "C" void GlyphDestination_SetRects(void* destination, int rects, unsigned char rectCount);
extern "C" void* MessageSystem_GetInstance(void);
extern "C" FontCharacter* Font_GetCharacter(int index, int font);
extern "C" int Font_GetKerning(int previousCharacter, int character, int font);
extern "C" int Font_GetFallbackWidth(int font);
void CleanInvalidateCacheRange(const void* p, unsigned int len);
extern "C" void LoadToSubObjVRAM(const void* data, unsigned int offset, unsigned int length);
extern "C" int GlyphDestination_DrawCharacter(void* destination, void* character, short x, int y, unsigned char color, unsigned char font);

#if defined(jpn)
#include "Resource/FontGlyphTable.h"
#include "NitroSDK/Graphics.h"
#include "NitroSDK/Cache.h"
#include "NitroSDK/LoadToVRAM.h"

struct CachedTextEntry0203bebc {
    short advanceX;
    short tileIndex;
    char text[10];
    unsigned char references;
    unsigned char unknownf;
};

struct CachedTextTable0203bebc {
    void* drawingBuffer;
    CachedTextEntry0203bebc entries[96];
    int engine;
    char* bitmapStorage;
    unsigned int unknown_60c_;
    unsigned short nextOamEntry;
    unsigned short allocatedEntries;
    unsigned char workBuffer[256];
};

struct Struct_020e8200 {
    unsigned int offsets[8];
};

extern CachedTextTable0203bebc* data_02105244;
extern const Struct_020e8200 data_020e8200;
extern "C" void __clear(void*, int);

enum { kFontPixelSize = 10 };  // the 10-pixel font
#else
// One CachedTextTable entry
struct CachedTextEntry0203bebc {
    unsigned char glyphIndices[0x20];  // the text as font character indices (Font_EncodeText)
    unsigned char length;              // characters in glyphIndices
    unsigned char width;               // in pixels
    short tileIndex;                   // first OBJ tile of the rendered text
    unsigned char references;
};

// The MessageSystem's 0x800-byte tile scratch buffer at +0x60
struct MessageSystem0203bebc {
    char pad[0x60];
    void* tileBuffer;
};

// The text is drawn into four 32 x 16 rectangles (128 x 16 pixels, 4bpp): the four OBJs
// CachedTextEntry_WriteOam places
enum {
    kRectCount = 4,
    kRectWidth = 0x20,
    kRectHeight = 0x10,
    kBitmapSize = 0x400,
    kTextColor = 0xf,              // palette colour 15, the text colour CachedTextTable_LoadPalettes sets
    kNoPreviousCharacter = 0xff    // no kerning before the first character (as in Font_GetTextWidth)
};
#endif

// Main, originally func_0203bebc (USA 0x0203bebc, EUR 0x0203becc, JPN 0x0203b914)
#if defined(jpn)
extern "C" ARM void CachedTextEntry_Render(void* rawEntry, int engine, char* text, char** glyphs,
                                int characterAdvance, void* vramOffset)
#else
extern "C" ARM void CachedTextEntry_Render(void* rawEntry, void* encodedText, void* vramOffset)
#endif
{
#if defined(jpn)
    CachedTextEntry0203bebc* entry = static_cast<CachedTextEntry0203bebc*>(rawEntry);
    if (text == NULL) return;
    memset(entry->text, 0, 10);
    memcpy(entry->text, text, 6);
    entry->text[6] = 0;

    switch (DISPCNTSUB & 0x300010) {
    case 0x10:
        entry->tileIndex = (unsigned int)vramOffset >> 5;
        break;
    case 0x100010:
        entry->tileIndex = (unsigned int)vramOffset >> 6;
        break;
    case 0x200010:
        entry->tileIndex = (unsigned int)vramOffset >> 7;
        break;
    }
    entry->advanceX = characterAdvance;
    FontGlyphTable* font = Font_GetGlyphTable(kFontPixelSize);
    if (font == NULL) return;
    int height = font->unknown_3_;
    unsigned char var3[256];
    __clear(var3, 256);
    for (unsigned char glyph = 0; glyph < 3; ++glyph) {
        unsigned char bit = 0;
        const unsigned char* var6 = reinterpret_cast<const unsigned char*>(glyphs[glyph]);
        if (var6 == NULL) continue;
        unsigned char* row = var3 + glyph * 5;
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < 10; ++x) {
                if (*var6 & (1 << bit)) {
                    if (x & 1) {
                        row[x >> 1] = (row[x >> 1] & 0xf) | 0xf0;
                    } else {
                        row[x >> 1] &= 0xf0;
                        row[x >> 1] |= 0xf;
                    }
                }
                ++bit;
                if (bit >= 8) {
                    bit = 0;
                    ++var6;
                }
            }
            row += 16;
        }
    }

    unsigned int var10;
    unsigned int var11;
    unsigned int tile;
    unsigned int var13;
    unsigned char* const work = data_02105244->workBuffer;
    memset(work, 0, 256);
    Struct_020e8200 offsets = data_020e8200;
    var11 = 0;
    for (tile = 0; tile < 8; ++tile) {
        var10 = 0;
        for (var13 = 0; var13 < 8; ++var13) {
            memcpy(work + var11, var3 + offsets.offsets[tile] + var10, 4);
            var10 += 16;
            var11 += 4;
        }
    }
    CleanInvalidateCacheRange(work, 256);
    if (engine == 0) {
        LoadToMainObjVRAM(work, (unsigned int)vramOffset, 256);
    } else if (engine == 1) {
        LoadToSubObjVRAM(work, (unsigned int)vramOffset, 256);
    }
#else
    int length;
    void* pixels = ((MessageSystem0203bebc*)MessageSystem_GetInstance())->tileBuffer;
    memset(pixels, 0, kBitmapSize);

    struct Struct02020520 rects[kRectCount];
    int pixelOffset = 0;
    int x = 0;
    for (int i = 0; i < kRectCount; i++) {
        struct Struct02020520* rect = &rects[i];
        rect->pixelOffset = pixelOffset;
        rect->x = x;
        rect->y = 0;
        rect->width = kRectWidth;
        rect->height = kRectHeight;
        pixelOffset += kRectWidth * kRectHeight / 2;
        x += rect->width;
    }

    struct S_b20c destination;
    GlyphDestination_Clear(&destination);
    GlyphDestination_SetPixels(&destination, (int)pixels);
    GlyphDestination_SetRects(&destination, (int)rects, kRectCount);

    CachedTextEntry0203bebc* entry = static_cast<CachedTextEntry0203bebc*>(rawEntry);
    entry->tileIndex = (short)((unsigned int)vramOffset >> 7);
    memset(entry->glyphIndices, 0, sizeof(entry->glyphIndices));
    memcpy(entry->glyphIndices, encodedText, entry->length);

    int penX = 0;
    length = entry->length;
    int previousCharacter = kNoPreviousCharacter;
    int fallbackWidth = Font_GetFallbackWidth(0);
    unsigned char character;
    int count = 0;
    unsigned char* cursor = (unsigned char*)encodedText;
    for (; count < length; count++) {
        character = *cursor;
        if (character == 0) break;
        int characterWidth = fallbackWidth;
        FontCharacter* glyph = Font_GetCharacter(character, 0);
        if (glyph != 0) {
            characterWidth = glyph->width_;
            GlyphDestination_DrawCharacter(&destination, glyph, (short)penX, 0, kTextColor, 0);
        }
        int kernedX = penX + Font_GetKerning(previousCharacter, character, 0);
        penX = kernedX + (characterWidth + 1);
        previousCharacter = character;
        cursor++;
    }

    CleanInvalidateCacheRange(pixels, kBitmapSize);
    LoadToSubObjVRAM(pixels, (unsigned int)vramOffset, kBitmapSize);
    entry->width = penX - 1;
#endif
}
