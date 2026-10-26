#include <globaldefs.h>

extern "C" int WindowPane_IsOpen(unsigned char* obj);
extern "C" int func_0204fd00(void* ctx, int mask);
extern "C" void Background_FillRect(void* target, int type, short a, short b, short c, short d, int flags);

struct Struct_0205da88 {
    char pad0[0x1c];
    unsigned char unknown_1c_0_ : 4;
    unsigned char unknown_1c_4_ : 4;
    char pad1[0x20 - 0x1d];
};

struct Struct_0205da88_2 {
    char pad0[0x4];
    struct Struct_0205da88* matched;
    char pad1[0xa8 - 0x8];
    short unknown_a8_;
    short unknown_aa_;
    short unknown_ac_;
    short unknown_ae_;
    char pad2[0xc0 - 0xb0];
    short fc0;
    char pad3[0xc5 - 0xc2];
    unsigned char unknown_c5_;
    char pad4[0xe0 - 0xc6];
};

struct Struct_0205da88_3 {
    char pad0[0x98];
    struct Struct_0205da88* entries;
    struct Struct_0205da88_2* elems;
    char pad1[0xb2 - 0xa0];
    unsigned char unknown_b2_;
    unsigned char unknown_b3_;
};

// USA: func_0205da88
extern "C" ARM void func_0205da88(struct Struct_0205da88_3* obj, int keyA, int arg2, unsigned short tile) {
    struct Struct_0205da88* target;
    struct Struct_0205da88* source;
    struct Struct_0205da88* e;
    struct Struct_0205da88_2* el;
    unsigned char i;

    if (obj->entries != 0 && obj->elems != 0) {
        keyA &= 3;
        arg2 &= 3;
        if (keyA == arg2) return;

        target = 0;
        source = 0;
        for (i = 0; i < obj->unknown_b2_; i++) {
            e = &obj->entries[i];
            if (keyA == e->unknown_1c_4_) target = e;
            if (arg2 == e->unknown_1c_4_) source = e;
        }
        if ((target == 0) | (source == 0)) return;

        tile &= 0x3ff;
        for (i = 0; i < obj->unknown_b3_; i++) {
            el = &obj->elems[i];
            if (!WindowPane_IsOpen((unsigned char*)el)) continue;
            if (el->unknown_c5_ & 0x20) continue;
            if (el->unknown_c5_ & 0x80) continue;
            if (source != el->matched) continue;
            short x = el->unknown_ac_;
            short y = el->unknown_ae_;
            short w = el->unknown_a8_;
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
