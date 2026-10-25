#include <globaldefs.h>

int WindowPane_IsOpen(unsigned char* obj);
extern "C" int func_0204fd00(void* ctx, int mask);
extern "C" void Background_FillRect(void* target, int type, short a, short b, short c, short d, int flags);

struct Struct_0205da88 {
    char unknown_0_[0x1c];
    unsigned char unknown_1c_0_ : 4;
    unsigned char unknown_1c_4_ : 4;
    char unknown_1d_[0x20 - 0x1d];
};

struct Struct_0205da88_2 {
    char unknown_0_[0x4];
    struct Struct_0205da88* unknown_4_;
    char unknown_8_[0xa8 - 0x8];
    short unknown_a8_;
    short unknown_aa_;
    short unknown_ac_;
    short unknown_ae_;
    char unknown_b0_[0xc0 - 0xb0];
    short unknown_c0_;
    char unknown_c2_[0xc5 - 0xc2];
    unsigned char unknown_c5_;
    char unknown_c6_[0xe0 - 0xc6];
};

struct Struct_0205da88_3 {
    char unknown_0_[0x98];
    struct Struct_0205da88* unknown_98_;
    struct Struct_0205da88_2* unknown_9c_;
    char unknown_a0_[0xb2 - 0xa0];
    unsigned char unknown_b2_;
    unsigned char unknown_b3_;
};

// USA: func_0205da88
extern "C" ARM void func_0205da88(struct Struct_0205da88_3* arg0, int arg1, int arg2, unsigned short arg3) {
    struct Struct_0205da88* var0;
    struct Struct_0205da88* var1;
    struct Struct_0205da88* var2;
    struct Struct_0205da88_2* var3;
    unsigned char var4;

    if (arg0->unknown_98_ != 0 && arg0->unknown_9c_ != 0) {
        arg1 &= 3;
        arg2 &= 3;
        if (arg1 == arg2) return;

        var0 = 0;
        var1 = 0;
        for (var4 = 0; var4 < arg0->unknown_b2_; var4++) {
            var2 = &arg0->unknown_98_[var4];
            if (arg1 == var2->unknown_1c_4_) var0 = var2;
            if (arg2 == var2->unknown_1c_4_) var1 = var2;
        }
        if ((var0 == 0) | (var1 == 0)) return;

        tile &= 0x3ff;
        for (i = 0; i < obj->elemCount; i++) {
            el = &obj->elems[i];
            if (!WindowPane_IsOpen((unsigned char*)el)) continue;
            if (el->fc5 & 0x20) continue;
            if (el->fc5 & 0x80) continue;
            if (source != el->matched) continue;
            short x = el->fac;
            short y = el->fae;
            short w = el->fa8;
            short h = el->fc0;
            Background_FillRect(target, tile, x, y, w, h, 0);
            if (h == 0 || tile == 0) continue;
            if (!func_0204fd00(el, 1))
                Background_FillRect(target, 2, x, y, 1, 1, 0);
            if (!func_0204fd00(el, 2))
                Background_FillRect(target, 0x402, (short)(x + w - 1), y, 1, 1, 0);
            if (!func_0204fd00(el, 4))
                Background_FillRect(target, 0x802, x, (short)(y + h - 1), 1, 1, 0);
            if (!func_0204fd00(el, 8))
                Background_FillRect(target, 0xc02, (short)(x + w - 1), (short)(y + h - 1), 1, 1, 0);
        }
    }
}
