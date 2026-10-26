#include <globaldefs.h>

#if defined(jpn)
#define RG(u, j) (j)
#else
#define RG(u, j) (u)
#endif

struct Struct0203c1c8 {
    int x;
    int y;
    int paletteOffset;
    int alignment;
    int priority;
    short entryIndex;
#if defined(jpn)
    char unknown_16_[0x20];
#endif
};

struct Obj0203c108;

extern "C" void func_ov000_021704d8(struct Struct0203c1c8* obj, int* arr1, int* arr2, int* arg3);
extern "C" int func_ov000_021719f8(int* obj);
#if defined(jpn)
struct Container020e0310;
extern "C" int KeyTable_Get(struct Container020e0310* c, int key);
#endif
extern "C" void CachedTextLabel_SetText(struct Obj0203c108* obj, char* fmt);
extern "C" void CachedTextLabel_Release(char* obj);

extern "C" void __clear(void* buf, int count);

struct Struct_ov000_02170538_2 {
    char pad0[0x10];
    signed char states[8];
    signed char index;
    char unknown_19_[0x1c - 0x19];
    signed char unknown_1c_;
    signed char unknown_1d_;
    char pad1e[0x24 - 0x1e];
    unsigned char flags;
    char unknown_25_;
    unsigned short unknown_26_;
    int f28;
    short unknown_2c_;
    signed char unknown_2e_;
    char unknown_2f_[0x3c - 0x2f];
    int f3c;
    char unknown_40_[0x44 - 0x40];
    int x;
    int y;
    int idx;
    struct Struct0203c1c8 label;
    struct Struct0203c1c8 text;
    char unknown_80_[RG(0x87 - 0x80, 0xc7 - 0xc0)];
    unsigned char visible;
    char unknown_88_[RG(0x443 - 0x88, 0x483 - 0xc8)];
    signed char unknown_443_;
};

extern "C" int func_ov000_0217f5dc(struct Struct_ov000_02170538_2* e);
extern "C" int func_ov000_02170c7c(struct Struct_ov000_02170538_2* e);
#if defined(jpn)
extern "C" int func_ov000_02171a74(struct Struct_ov000_02170538_2* e);
#else
extern "C" int func_ov000_02171a74(struct Struct_ov000_02170538_2* e, char* buf);
#endif

struct Struct_ov000_02170538 {
    int v[2];
};

extern const struct Struct_ov000_021832f4 {
    char pad0[RG(0x7c, 0x70)];
    struct Struct_ov000_02170538 large;
    struct Struct_ov000_02170538 unknown_84_;
} data_ov000_021832f4;

// USA: func_ov000_02170538
extern "C" ARM void func_ov000_02170538(struct Struct_ov000_02170538_2* e, int arg1, int arg2, int mode) {
    if (e->idx < 0) return;
    if (!func_ov000_0217f5dc(e)) return;
    int var0 = func_ov000_02170c7c(e);
    if (e->flags & 4) {
        int a2[2] = { e->x + 0x25, e->x + 0x26 };
        int b2[2] = { e->y + 0xb, e->y + 0xb };
        struct Struct_ov000_02170538 c2 = data_ov000_021832f4.large;
        c2.v[0] = var0;
        func_ov000_021704d8(&e->text, a2, b2, c2.v);
        return;
    }
    int a[2] = { e->x + RG(0x28, 0x2f) + arg1, e->x + 0x30 + arg1 };
    int b[2] = { e->y + 8 + arg2, e->y + 8 + arg2 };
    struct Struct_ov000_02170538 c = data_ov000_021832f4.unknown_84_;
    c.v[0] = var0;
    func_ov000_021704d8(&e->text, a, b, c.v);
    if (e->states[e->index] == 0x67) return;
    int d[2] = { e->x + 0xb3 + arg1, e->x + 0xb4 + arg1 };
    int f[2][2] = { { e->y + 0xf + arg2, e->y + 0xf + arg2 }, { e->y + 8 + arg2, e->y + 8 + arg2 } };
    int sel = 1;
    unsigned int cur = e->f3c & 0x80019;
    unsigned int var11 = e->f28 & 0x80019;
    if (func_ov000_021719f8((int*)e)) {
        if (cur != var11) {
#if defined(jpn)
            char* str = (char*)KeyTable_Get(*(struct Container020e0310**)((char*)e + 4), func_ov000_02171a74(e));
            if (str != NULL) {
                CachedTextLabel_SetText((struct Obj0203c108*)&e->label, str);
            }
#else
            char buf[0x80];
            __clear(buf, sizeof(buf));
            if (func_ov000_02171a74(e, buf) >= 0) {
                CachedTextLabel_SetText((struct Obj0203c108*)&e->label, buf);
            }
#endif
            e->f3c = e->f28;
        }
        func_ov000_021704d8(&e->label, d, f[0], c.v);
        return;
    }
    if (cur != var11 && (e->f3c & 0x80019)) {
        CachedTextLabel_Release((char*)&e->label);
        e->f3c = e->f28;
        e->unknown_1d_ = -1;
        e->unknown_2c_ = -1;
        e->unknown_2e_ = -1;
        e->unknown_26_ = 0;
    }
    int k = 3;
    if (e->states[e->index] != 0x66) k = 0;
    if (e->unknown_26_ == 3) sel = 0;
    if (e->unknown_1c_ == 6) sel = 0;
    if (e->states[e->index] < 0x64) {
        if (e->visible) {
            sel = 0;
        } else {
            return;
        }
    }
    c.v[0] = k;
    if (mode == 2) return;
    if (e->unknown_443_ != 5) sel = 0;
    func_ov000_021704d8(&e->label, d, f[sel], c.v);
}
