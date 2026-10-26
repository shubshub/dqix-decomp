#include <globaldefs.h>

struct Struct_020437bc {
    short x, y, width, height;
};

#if defined(jpn)
extern const unsigned char data_020e8453[][8];

extern "C" ARM void func_020437bc(unsigned short* map, const Struct_020437bc* arg1, int style) {
    if (map == NULL || arg1 == NULL) return;
    if (arg1->width == 0 || arg1->height == 0) return;
    short bottom;
    short left = arg1->x;
    short top = arg1->y;
    const unsigned char* tiles = data_020e8453[style];
    short right = left + arg1->width;
    bottom = top + arg1->height;
    left >>= 3;
    top >>= 3;
    right >>= 3;
    bottom >>= 3;
    (map + top * 32)[left] = tiles[0] - 0x1d;
    (map + top * 32)[right] = tiles[1] - 0x1d;
    (map + bottom * 32)[left] = tiles[2] - 0x1d;
    (map + bottom * 32)[right] = tiles[3] - 0x1d;
    for (short x = left + 1; x < right; x++) {
        (map + top * 32)[x] = tiles[4] - 0x1d;
        (map + bottom * 32)[x] = tiles[5] - 0x1d;
    }
    for (short y = top + 1; y < bottom; y++) {
        (map + y * 32)[left] = tiles[6] - 0x1d;
        (map + y * 32)[right] = tiles[7] - 0x1d;
    }
    for (short y = top + 1; y < bottom; y++) {
        for (short x = left + 1; x < right; x++) {
            (map + y * 32)[x] = 1;
        }
    }
}
#else
extern const unsigned char data_020e7ade[][8];

// USA: func_020437bc
extern "C" ARM void func_020437bc(unsigned short* map, const Struct_020437bc* arg1, int style) {
    if (map == NULL || arg1 == NULL) return;
    if (arg1->width == 0 || arg1->height == 0) return;
    short bottom;
    const unsigned char* tiles = data_020e7ade[style];
    short left = arg1->x;
    short top = arg1->y;
    short right = left + arg1->width;
    bottom = top + arg1->height;
    left >>= 3;
    top >>= 3;
    right >>= 3;
    bottom >>= 3;
    short var14 = top * 32;
    short var15 = bottom * 32;
    (map + var14)[left] = tiles[0] - 0x13;
    (map + var14)[right] = tiles[1] - 0x13;
    (map + var15)[left] = tiles[2] - 0x13;
    (map + var15)[right] = tiles[3] - 0x13;
    for (short x = left + 1; x < right; x++) {
        (map + var14)[x] = tiles[4] - 0x13;
        (map + var15)[x] = tiles[5] - 0x13;
    }
    for (short y = top + 1; y < bottom; y++) {
        short row = y * 32;
        (map + row)[left] = tiles[6] - 0x13;
        (map + row)[right] = tiles[7] - 0x13;
    }
    for (short y = top + 1; y < bottom; y++) {
        short row = y * 32;
        for (short x = left + 1; x < right; x++) {
            (map + row)[x] = 1;
        }
    }
}
#endif
