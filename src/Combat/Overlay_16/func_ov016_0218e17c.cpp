#include <globaldefs.h>

struct Struct_ov016_0218e17c_2 {
    char pad0[4];
    unsigned short unknown_4_;
    char pad6[6];
    unsigned char* unknown_c_;
};

struct Struct_ov016_0218e17c {
    char pad0[4];
    signed char width;
    char pad5;
    short unknown_6_;
};

extern "C" int func_02042638(int idx);

// USA: func_ov016_0218e17c
extern "C" ARM void func_ov016_0218e17c(unsigned short* dst, int x, int y, struct Struct_ov016_0218e17c* glyph, unsigned short color, unsigned char arg5) {
    struct Struct_ov016_0218e17c_2* font = (struct Struct_ov016_0218e17c_2*)func_02042638(arg5);
    short var1 = glyph->unknown_6_;
    int stride = font->unknown_4_ >> 3;
    signed char var3 = 7 - (var1 & 7);
    for (int row = 0; row < 12; row++) {
        signed char bit;
        unsigned char* src = font->unknown_c_ + stride * row + (var1 >> 3);
        int line = (y + row) << 8;
        bit = var3;
        for (int col = 0; col < glyph->width; col++) {
            if (*src & (1 << bit)) {
                (dst + line + x)[col] = color;
            }
            bit--;
            if (bit < 0) {
                bit = 7;
                src++;
            }
        }
    }
}
