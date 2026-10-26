#include <globaldefs.h>

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

enum {
    kObjectCount = 4,            // a text is four 32 x 16 OBJs (CachedTextEntry_Render renders 128 x 16 pixels)
    kObjectWidth = 0x20,
    kTilesPerObject = 2,         // 32 x 16 at 4bpp is 256 bytes: two 128-byte tile units
    kShapeWide = 0x4000,         // attribute 0: horizontal shape
    kSize32x16 = 0x80000000      // attribute 1 size 2: 32 x 16 for the horizontal shape
};

// Main, originally BuildPackedEntries0203c05c (USA 0x0203c05c, EUR 0x0203c06c; JPN not identified)
ARM void CachedTextEntry_WriteOam(struct Source0203c05c* entry, struct Entry0203c05c* objects,
                                    int priority, int x, int y, int palette) {
    short tile = entry->tileIndex;
    int i;
    if (tile < 0) {
        return;
    }
    for (i = 0; i < kObjectCount; i++) {
        objects->attributes01 = kSize32x16 | kShapeWide | (y & 0xff) | ((x & 0x1ff) << 16);
        objects->attribute2 = (unsigned short)(tile | ((priority & 3) << 10) | ((palette & 0xf) << 12));
        objects++;
        x += kObjectWidth;
        tile = (short)(tile + kTilesPerObject);
    }
}
