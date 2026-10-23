#include <globaldefs.h>

struct Struct_0207fe80_2 {
    char unknown_0_[0x1c];
    unsigned char unknown_1c_0_ : 4;
    unsigned char unknown_1c_4_ : 4;
    char unknown_1d_[0x20 - 0x1d];
};

struct Struct_0207fe80 {
    char unknown_0_[4];
    struct Struct_0207fe80_2* unknown_4_;
    char unknown_8_[0xa8 - 8];
    short unknown_a8_;
    char unknown_aa_[2];
    short unknown_ac_;
    short unknown_ae_;
    char unknown_b0_[0xc0 - 0xb0];
    short unknown_c0_;
    char unknown_c2_[0xc4 - 0xc2];
    unsigned char unknown_c4_;
    unsigned char unknown_c5_;
    char unknown_c6_[0xe0 - 0xc6];
};

struct Struct_0207fe80_3 {
#if defined(jpn)
    char unknown_0_[0x20];
#else
    char unknown1_0_[0x2c];
#endif
    struct Struct_0207fe80_2* unknown_2c_;
    struct Struct_0207fe80* unknown_30_;
    char unknown_34_[0x38 - 0x34];
    unsigned char unknown_38_;
    unsigned char unknown_39_;
};

int CheckField0x9cSetWhenField0xd4Present_0204c7e0(unsigned char*);
extern "C" void Background_FillRect(struct Sub0207fe80* s, int mode, short ac, short ae, short a8, short c0, int flag);
extern "C" int func_0204fd00(struct Elem0207fe80* e, int mask);

// USA: func_0207fe80
extern "C" ARM void func_0207fe80(struct Struct_0207fe80_3* arg0, int arg1, int arg2, unsigned short arg3) {
    struct Struct_0207fe80_2* var0;
    struct Struct_0207fe80_2* var1;
    struct Struct_0207fe80_2* var2;
    unsigned char var3;
    struct Struct_0207fe80* var4;
    unsigned char var5;
    short var6;
    short var7;
    short var8;
    short var9;

    arg1 &= 3;
    arg2 &= 3;
    if (arg1 == arg2) {
        return;
    }
    var0 = NULL;
    var1 = NULL;
    for (var3 = 0; var3 < arg0->unknown_38_; var3++) {
        var2 = &arg0->unknown_2c_[var3];
        if (arg1 == var2->unknown_1c_4_) {
            var0 = var2;
        }
        if (arg2 == var2->unknown_1c_4_) {
            var1 = var2;
        }
    }
    if ((var0 == NULL) | (var1 == NULL)) {
        return;
    }
    c &= 0x3ff;
    for (j = 0; j < obj->count39; j++) {
        e = &obj->elems[j];
        if (CheckField0x9cSetWhenField0xd4Present_0204c7e0((unsigned char*)e) && e->key != 0xff) {
            if (!(e->flags & 0x20) && !(e->flags & 0x80) && sb == e->f4) {
                ae = e->fae;
                ac = e->fac;
                a8 = e->fa8;
                c0 = e->fc0;
                Background_FillRect(sa, c, ac, ae, a8, c0, 0);
                if (c0 && c) {
                    if (!func_0204fd00(e, 1)) {
                        Background_FillRect(sa, 2, ac, ae, 1, 1, 0);
                    }
                    if (!func_0204fd00(e, 2)) {
                        Background_FillRect(sa, 0x402, (short)(ac + a8 - 1), ae, 1, 1, 0);
                    }
                    if (!func_0204fd00(e, 4)) {
                        Background_FillRect(sa, 0x802, ac, (short)(ae + c0 - 1), 1, 1, 0);
                    }
                    if (!func_0204fd00(e, 8)) {
                        Background_FillRect(sa, 0xc02, (short)(ac + a8 - 1), (short)(ae + c0 - 1), 1, 1, 0);
                    }
                }
            }
        }
    }
}
