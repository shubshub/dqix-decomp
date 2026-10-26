#include <globaldefs.h>

struct Struct_0207dfc8 {
    unsigned int v[10];
};

struct Struct_0207dfc8_2 {
    unsigned int v[2];
};

struct State0207dfc8 {
    struct Struct_0207dfc8 a;   // 0x00
    struct Struct_0207dfc8 b;   // 0x28
    unsigned int unknown_50_;         // 0x50
    unsigned int unknown_54_;         // 0x54
    struct Struct_0207dfc8_2 v58; // 0x58
    struct Struct_0207dfc8_2 v60; // 0x60
    unsigned int f68;         // 0x68
    unsigned int f6c;         // 0x6c
};

// Main, originally CopyState0207dfc8 (USA 0x0207dfc8, EUR 0x0207dfd8, JPN 0x0207ed48)
extern "C" ARM void VramState_CopyCurrentTo(struct State0207dfc8* src, struct State0207dfc8* dst) {
    dst->a = src->b;
    dst->b = src->b;
    dst->unknown_54_ = src->unknown_54_;
    dst->unknown_50_ = src->unknown_50_;
    dst->v58 = src->v60;
    dst->v60 = src->v60;
    dst->f6c = src->f6c;
    dst->f68 = src->f68;
}
