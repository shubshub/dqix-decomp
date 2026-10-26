#include <globaldefs.h>
#include "Resource/MessageGlyphSlot.h"

extern "C" void func_020419f4(int s, int t);

#if defined(jpn)
#define data_021077fc data_0210773c
#endif
extern int data_021077fc;

struct Struct_020417b0 {
    int left;
    int top;
};

static inline void inline_020417b0(int x, int y, int z) {
    *(volatile unsigned int*)0x04000470 = x;
    *(volatile unsigned int*)0x04000470 = y;
    *(volatile unsigned int*)0x04000470 = z;
}

static inline void inline_020417b0_2(int x, int y, int z) {
    *(volatile unsigned int*)0x0400046c = x;
    *(volatile unsigned int*)0x0400046c = y;
    *(volatile unsigned int*)0x0400046c = z;
}

static inline void inline_020417b0_3(unsigned short x, unsigned short y, unsigned short z) {
    *(volatile unsigned int*)0x0400048c = (unsigned short)x | ((unsigned short)y << 16);
    *(volatile unsigned int*)0x0400048c = (unsigned short)z;
}

// USA: func_020417b0
extern "C" ARM void func_020417b0(Struct_0204166c* glyph, int color, Struct_020417b0* clip, int alpha) {
    if (glyph->unknown_8_ < 0) return;
    if (glyph->unknown_16_0_) return;
    if (alpha == 0) return;

    *(volatile unsigned int*)0x04000444 = 0;
#if defined(jpn)
    inline_020417b0(glyph->x << 12, glyph->y << 12, (glyph->depth + 0x400) << 12);
#else
    inline_020417b0(glyph->x << 12, glyph->y << 12, ((short)glyph->depth + 0x400) << 12);
#endif
    inline_020417b0_2(0x1000, 0x1000, 0x1000);

    *(volatile unsigned int*)0x04000444 = 0;
    inline_020417b0(0, 0x10000, 0);
    inline_020417b0_2(0x1000, -0x1000, 0x1000);

    *(volatile unsigned int*)0x04000444 = 0;
    *(volatile unsigned int*)0x040004c0 = 0x7fffffff;
    *(volatile unsigned int*)0x040004c4 = 0x4210;
    *(volatile unsigned int*)0x040004a8 = 0x6c900000u | (glyph->unknown_4_ >> 3);
    *(volatile unsigned int*)0x040004ac = (unsigned int)data_021077fc >> 4;
    *(volatile unsigned int*)0x040004a4 = 0x3e0000c0 | (alpha << 16);
    inline_020417b0_2(0x10000, 0x10000, 0x1000);

    *(volatile unsigned int*)0x04000500 = 1;
    *(volatile unsigned int*)0x04000480 = color;

    int size = 16;
    float t = 0.0f;
    int var2 = (int)(size * t);
    float height = 1.0f - t;
    if (clip != NULL) {
        if (glyph->y < clip->top) {
            var2 += clip->top - glyph->y;
        }
        if (var2 > 16) {
            var2 = 16;
        }
        height = (16.0f - var2) / 16.0f;
    }
    int var4 = var2 << 12;
    func_020419f4(0, var4);
    inline_020417b0_3(0, (int)(4096.0f * height), 0);
    func_020419f4(0x10000, var4);
    inline_020417b0_3(0x1000, (int)(4096.0f * height), 0);
    func_020419f4(0x10000, 0x10000);
    inline_020417b0_3(0x1000, 0, 0);
    func_020419f4(0, 0x10000);
    inline_020417b0_3(0, 0, 0);

    *(volatile unsigned int*)0x04000504 = 0;
    *(volatile unsigned int*)0x04000448 = 1;
    *(volatile unsigned int*)0x04000448 = 1;
    *(volatile unsigned int*)0x04000448 = 1;
}
