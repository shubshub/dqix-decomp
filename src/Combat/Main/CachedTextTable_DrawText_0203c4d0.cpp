#include <globaldefs.h>

#if defined(jpn)
#include "std_library_functions.h"

struct Struct_0203bdf4_2 {
    short unknown_0_;
    short unknown_2_;
    char unknown_4_[10];
    unsigned char unknown_e_;
    unsigned char unknown_f_;
};

struct Struct_0201099c_21 {
    unsigned int unknown_0_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
};

struct Struct_0203bdf4 {
    Struct_0201099c_21* unknown_0_;
    Struct_0203bdf4_2 unknown_4_[96];
    unsigned char unknown_604_[8];
    unsigned int unknown_60c_;
    unsigned short unknown_610_;
};


enum { kLineBreak = -2 };  // a slot that starts a new line

extern "C" void func_0203bb6c(const CachedTextEntry* entry, TextOamEntry* output,
                              int affineMode, int priority, int affineIndex,
                              int x, int y, int palette);

// Main, originally func_0203c4d0 (USA 0x0203c4d0, EUR 0x0203c4e0, JPN 0x0203c634)
extern "C" ARM void CachedTextTable_DrawText(CachedTextTable* cache, int count, const short* slots,
                                int affineMode, int priority, int affineIndex,
                                int x, int y, int palette, int characterAdvance,
                                int lineHeight) {
    if (slots == NULL || cache->drawingBuffer == NULL) return;
    int textPalette = ((cache->paletteControl >> 5) + palette) & 0xf;
    int penX = x;
    int penY = y;
    for (int i = 0; i < count; ++i) {
        short index = slots[i];
        if (index >= 0) {
            func_0203bb6c(&cache->entries[index],
                         &cache->drawingBuffer[cache->nextOamEntry],
                         affineMode, priority, affineIndex, penX, penY, textPalette);
            ++cache->nextOamEntry;
            cache->nextOamEntry &= 0x7f;
            penX += cache->entries[index].advanceX;
        }
        if (index == kLineBreak) {
            penX = x;
            penY += lineHeight;
        } else {
            var1 += arg9;
        }
    }
}

#else

// A CachedTextTable entry (only its first OBJ tile is read)
struct Source0203c05c {
    char pad[0x22];
    short tileIndex;
};

// One OAM object
struct Entry0203c05c {
    unsigned int attributes01;
    unsigned short attribute2;
    unsigned short affineParameter;
};

void CachedTextEntry_WriteOam(struct Source0203c05c* entry, struct Entry0203c05c* objects,
                                int priority, int x, int y, int palette);

// The CachedTextTable from +0x500
struct Sub0203c4d0 {
    unsigned char pad[0xc];
    unsigned int paletteOffset;    // byte offset of the text palettes; >> 5 is the first one's number
    unsigned short nextOamEntry;
};

struct Obj0203c4d0 {
    struct Entry0203c05c* drawingBuffer;
    unsigned char pad[0x4fc];
    struct Sub0203c4d0 sub;
};

enum {
    kEntries = 4,
    kEntrySize = 0x28,
    kObjectsPerText = 4,   // CachedTextEntry_WriteOam writes four 32 x 16 OBJs
    kOamEntryMask = 0x7f   // 128 OAM entries
};

// USA: CachedTextTable_DrawText
extern "C" ARM void CachedTextTable_DrawText(void* rawTable, short entryIndex, int priority, int x, int y,
                                 int palette) {
    struct Obj0203c4d0* table = (struct Obj0203c4d0*)rawTable;
    int textPalette;

    if (entryIndex < 0) {
        return;
    }

    if (table->drawingBuffer == 0) {
        return;
    }

    textPalette = (table->sub.paletteOffset >> 5) + palette;
    textPalette = textPalette & 0xf;

    CachedTextEntry_WriteOam(
        (struct Source0203c05c*)((char*)table + kEntries + entryIndex * kEntrySize),
        table->drawingBuffer + table->sub.nextOamEntry,
        priority, x, y,
        textPalette & 0xf);

    table->sub.nextOamEntry = table->sub.nextOamEntry + kObjectsPerText;
    table->sub.nextOamEntry = table->sub.nextOamEntry & kOamEntryMask;
}
#endif
