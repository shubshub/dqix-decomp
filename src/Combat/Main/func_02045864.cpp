#include <globaldefs.h>

struct Struct_02045864_2 {
    char unk0[4];
    signed char width;
    char unknown_5_;
    short unknown_6_;
};

struct Struct_02045864 {
    char unk0[4];
    unsigned short unknown_4_;
    char unknown_6_[6];
    unsigned char* data;
};

extern Struct_02045864* data_02107834[];

// USA: func_02045864
extern "C" ARM void func_02045864(int x, int y, Struct_02045864_2* glyph, unsigned char* dst, int width, int height,
                                  unsigned char color, unsigned char font) {
    if (glyph == NULL || dst == NULL) {
        return;
    }
    int off = glyph->unknown_6_;
    Struct_02045864* f = data_02107834[font];
    unsigned char hi = color << 4;
    unsigned char lo = color & 0x0f;
    int stride = f->unknown_4_ >> 3;
    signed char var5 = 7 - (off & 7);
    int pitch = width >> 1;
    for (int i = 0; i < 12; i++) {
        signed char bit = var5;
        unsigned char* src = f->data + stride * i + (off >> 3);
        int var10 = y + i;
        int var11 = pitch * var10;
        if (var10 < 0 || height <= var10) {
            continue;
        }
        for (int j = 0; j < glyph->width; j++) {
            int px = x + j;
            if (px < 0 || width <= px) {
                continue;
            }
            if (*src & (1 << bit)) {
                if (px & 1) {
                    (dst + var11)[px >> 1] &= 0x0f;
                    (dst + var11)[px >> 1] |= hi;
                } else {
                    (dst + var11)[px >> 1] &= 0xf0;
                    (dst + var11)[px >> 1] |= lo;
                }
            }
            if (--bit < 0) {
                bit = 7;
                src++;
            }
        }
    }
}
