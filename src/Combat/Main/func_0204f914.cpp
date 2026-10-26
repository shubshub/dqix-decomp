#include <globaldefs.h>

struct Struct_0204f914 {
    unsigned char padding0[8];
    unsigned char* pixels;
    unsigned char unknown_c_[0x9c];
    short width;
    short height;
};

static inline int inline_0204f914(short column) { return column >> 1; }

// USA: func_0204f914
extern "C" ARM void func_0204f914(Struct_0204f914* arg0, unsigned char color, short originX, short originY, short endX, short endY) {
    if (endX < 0 || endY < 0) return;
    short var0 = arg0->height * 8;
    short var1 = arg0->width * 8;
    if (endX > var1) return;
    if (var0 < endY) return;
    if (originX == endX || originY == endY) return;
    unsigned char var2;
    unsigned char var3;
    var3 = color & 15;
    var2 = var3 << 4;
    for (short y = originY; y < endY; ++y) {
        short var5 = y & 7;
        short var6 = var5 * 4;
        int var7 = (short)(y >> 3) * arg0->width;
        for (short x = originX; x < endX; ++x) {
            short tile = var7 + (short)(x >> 3);
            short var10 = x & 7;
            short offset = inline_0204f914(var10) + (short)(tile * 32);
            offset += var6;
            unsigned char& var12 = arg0->pixels[offset];
            if (x & 1) {
                var12 &= 15;
                var12 |= var2;
            } else {
                var12 &= 0xf0;
                var12 |= var3;
            }
        }
    }
}
