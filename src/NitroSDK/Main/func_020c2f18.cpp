#include <globaldefs.h>

struct Struct_020c2f18 { int x, y, z; };

struct Struct_020c2f18_2 {
    volatile unsigned short unknown_0_;
    unsigned char pad0[0xe];
    unsigned int unknown_10_;
    unsigned int unknown_14_;
    unsigned int unknown_18_;
    unsigned int unknown_1c_;
    unsigned char pad1[0x30 - 0x20];
    volatile unsigned short unknown_30_;
    unsigned char pad2[0x38 - 0x32];
    unsigned int unknown_38_;
    unsigned int unknown_3c_;
};

// USA: func_020c2f18
extern "C" ARM void Vector3fix_Normalize(struct Struct_020c2f18* v, struct Struct_020c2f18* out) {
    long long var0 = (long long)v->x * v->x;
    int var1 = v->y;
    var0 += (long long)var1 * var1;
    var0 += (long long)v->z * v->z;

    struct Struct_020c2f18_2* var2 = (struct Struct_020c2f18_2*)0x4000280;
    var2->unknown_0_ = 2;
    var2->unknown_10_ = 0;
    var2->unknown_14_ = 0x1000000;
    var2->unknown_18_ = (unsigned int)var0;
    var2->unknown_1c_ = (unsigned int)(var0 >> 32);
    var2->unknown_30_ = 1;
    var2->unknown_38_ = (unsigned int)var0 << 2;
    var2->unknown_3c_ = (unsigned int)(((unsigned long long)var0 << 2) >> 32);

    while (var2->unknown_30_ & 0x8000) {}
    int var3 = *(volatile int*)0x40002b4;

    while (*(volatile unsigned short*)0x4000280 & 0x8000) {}
    long long var4 = *(volatile long long*)0x40002a0;

    long long scale = var4 * (long long)var3;
    out->x = (int)((scale * (long long)v->x + (1LL << 44)) >> 45);
    out->y = (int)((scale * (long long)v->y + (1LL << 44)) >> 45);
    out->z = (int)((scale * (long long)v->z + (1LL << 44)) >> 45);
}
