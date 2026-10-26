#include <globaldefs.h>

struct Sub0207fe80 {
    char pad0[0x1c];
    unsigned char lo : 4;
    unsigned char hi : 4;
    char pad1[0x20 - 0x1d];
};

struct Struct_0207fe80 {
    char pad0[4];
    struct Sub0207fe80* f4;
    char pad1[0xa8 - 8];
    short unknown_a8_;
    char pad2[2];
    short unknown_ac_;
    short unknown_ae_;
    char pad3[0xc0 - 0xb0];
    short fc0;
    char pad4[0xc4 - 0xc2];
    unsigned char key;
    unsigned char flags;
    char pad5[0xe0 - 0xc6];
};

struct Struct_0207fe80_3 {
#if defined(jpn)
    char pad0[0x20];
#else
    char pad0[0x2c];
#endif
    struct Sub0207fe80* unknown_2c_;
    struct Struct_0207fe80* elems;
    char pad1[0x38 - 0x34];
    unsigned char unknown_38_;
    unsigned char unknown_39_;
};

extern "C" int WindowPane_IsOpen(unsigned char*);
extern "C" void Background_FillRect(struct Sub0207fe80* s, int mode, short ac, short ae, short a8, short c0, int flag);
extern "C" int func_0204fd00(struct Struct_0207fe80* e, int mask);

// USA: func_0207fe80
extern "C" ARM void func_0207fe80(struct Struct_0207fe80_3* obj, int a, int b, unsigned short c) {
    struct Sub0207fe80* sa;
    struct Sub0207fe80* sb;
    struct Sub0207fe80* p;
    unsigned char i;
    struct Struct_0207fe80* e;
    unsigned char j;
    short ac;
    short ae;
    short a8;
    short c0;

    a &= 3;
    b &= 3;
    if (a == b) {
        return;
    }
    sa = NULL;
    sb = NULL;
    for (i = 0; i < obj->unknown_38_; i++) {
        p = &obj->unknown_2c_[i];
        if (a == p->hi) {
            sa = p;
        }
        if (b == p->hi) {
            sb = p;
        }
    }
    if ((sa == NULL) | (sb == NULL)) {
        return;
    }
    c &= 0x3ff;
    for (j = 0; j < obj->unknown_39_; j++) {
        e = &obj->elems[j];
        if (WindowPane_IsOpen((unsigned char*)e) && e->key != 0xff) {
            if (!(e->flags & 0x20) && !(e->flags & 0x80) && sb == e->f4) {
                ae = e->unknown_ae_;
                ac = e->unknown_ac_;
                a8 = e->unknown_a8_;
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
