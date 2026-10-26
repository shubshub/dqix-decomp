#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include "globaldefs.h"

struct Struct_ov005_0215436c_4 { unsigned char unknown[0x70]; };
struct Struct_ov005_02155424 {
    unsigned char unknown_0_[0x1c];
    int x, y, z;
    unsigned char unknown28[0x88 - 0x28];
};
struct Struct_ov005_02155424_2 {
    int unknown_0_;
    Struct_ov005_0215436c_4* backing;
    Struct_ov005_02155424* unknown_8_;
    int x, y;
    unsigned char unknown14[8];
};
struct Struct_ov005_02155424_3 {
    unsigned char unknown_0_[0x304];
    Struct_ov005_0215436c_4 unknown_304_[24];
    unsigned char unknown_d84_[R(0x2d08, 0x2d90) - 0x304 - 24 * 0x70];
    Struct_ov005_02155424_2 entries[24];
    Struct_ov005_02155424 unknown_3030_[24];
};

extern "C" ARM void func_ov005_02155424(Struct_ov005_02155424_3* layout) {
    for (int i = 0; i < 8; ++i) {
        Struct_ov005_02155424_2* entry = &layout->entries[i];
        entry->backing = &layout->unknown_304_[i];
        entry->unknown_8_ = &layout->unknown_3030_[i];
        entry->x = 133 << 12;
        entry->y = 22 << 12;
        Struct_ov005_02155424* var2 = entry->unknown_8_;
        var2->x = 133 << 12;
        var2->y = 22 << 12;
        var2->z = 0;
    }
    for (int i = 0; i < 16; ++i) {
        Struct_ov005_02155424_2* entry = &layout->entries[i + 8];
        entry->backing = &layout->unknown_304_[i + 8];
        entry->unknown_8_ = &layout->unknown_3030_[i + 8];
        int column = (i % 16) % 4;
        int row = (i % 16) / 4;
        int x = (column * 26 + 141) << 12;
        int y = (row * 26 + 52) << 12;
        entry->x = x;
        entry->y = y;
        Struct_ov005_02155424* var9 = entry->unknown_8_;
        var9->x = x;
        var9->y = y;
        var9->z = 0;
    }
}
