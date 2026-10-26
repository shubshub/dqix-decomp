#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_0204f174 {
    char pad0[8];
    unsigned char* pixels;
    char unknown_c_[0x9c - 0xc];
    int dirty;
    int offset;
    int pixelSize;
    short width;
    short height;
    short x;
    short y;
    char unknown_b0_[0xc2 - 0xb0];
    short frame;
    char unknown_c4_;
    unsigned char flags;
    char unknown_c6_[2];
    short unknown_c8_;
    short unknown_ca_;
    char unknown_cc_[4];
    int unknown_d0_;
    unsigned short* indices;
};

extern "C" void func_0204f914(Struct_0204f174* window, int color, short arg2, short arg3, short x1, short arg5);
extern "C" void func_0204ea5c(Struct_0204f174* window);
extern "C" void func_0204ecb4(Struct_0204f174* window, int x, int y, short w, short h, signed char* arg5);

// USA: func_0204f174
extern "C" ARM void func_0204f174(Struct_0204f174* window, short x, short y, short width, short height,
                                  unsigned char frame, unsigned char arg6, unsigned char arg7,
                                  signed char* arg8) {
    window->x = x;
    window->y = y;
    window->frame = frame;
    if (arg6) {
        window->flags |= 4;
    } else {
        window->flags &= ~4;
    }
    if (arg7) {
        window->flags |= 0x10;
    } else {
        window->flags &= ~0x10;
    }
    int var0 = width * height * 2;
    if (window->flags & 1) {
        if (window->width < width) width = window->width;
        if (window->height < height) height = window->height;
        window->unknown_c8_ = width;
        window->unknown_ca_ = height;
        window->unknown_d0_ = var0;
        memset(window->pixels, 0, window->pixelSize);
        if (!arg6) {
            short left = 0;
            short top = 0;
            short right = width << 3;
            short bottom = height << 3;
            if (arg8) {
                top += arg8[0];
                bottom -= arg8[0] + arg8[1];
                left += arg8[2];
                right -= arg8[2] + arg8[3];
            }
            func_0204f914(window, 0x11, left, top, right, bottom);
        }
    } else {
        window->flags |= 1;
        window->width = width;
        window->height = height;
        window->pixelSize = width * height * 32;
        memset(window->pixels, 0, window->pixelSize);
        if (!arg6) {
            short left = 0;
            short top = 0;
            short right = width << 3;
            short bottom = height << 3;
            if (arg8) {
                top += arg8[0];
                bottom -= arg8[0] + arg8[1];
                left += arg8[2];
                right -= arg8[2] + arg8[3];
            }
            func_0204f914(window, 0x11, left, top, right, bottom);
        }
        memset(window->indices, 0, var0);
        short w = window->width;
        short h = window->height;
        window->unknown_c8_ = w;
        window->unknown_ca_ = h;
        window->unknown_d0_ = var0;
        window->dirty = 1;
    }
    if (!arg7) {
        if (!arg6) func_0204ea5c(window);
        func_0204ecb4(window, 0, 0, width, height, arg8);
    } else {
        window->flags |= 0x80;
    }
}
