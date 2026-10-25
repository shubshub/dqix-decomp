#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" int memcmp(unsigned char* a, unsigned char* b, int n);
extern "C" void memcpy(void* dst, const void* src, int n);

extern unsigned char data_ov023_021fdc90;

struct Struct_ov023_021e20f0_4 {
    char unknown_0_[4];
    int unknown_4_;
    char unknown_8_[0xc - 0x8];
    int unknown_c_;
    char unknown_10_[0x14 - 0x10];
    int unknown_14_;
    int unknown_18_;
};

struct Struct_ov023_021e20f0_5 {
    char unknown_0_[8];
    void* unknown_8_;   // 0x8
    void* unknown_c_;   // 0xc
    char unknown_10_[0x14 - 0x10];
    unsigned short unknown_14_; // 0x14
    unsigned short unknown_16_;    // 0x16
};

struct Struct_ov023_021e20f0_6 {
    char unknown_0_[4];
    int unknown_4_;
    short unknown_8_;
    short unknown_a_;
    char unknown_c_[0xe - 0xc];
    unsigned short unknown_e_;
    unsigned short unknown_10_;
    unsigned short unknown_12_;
    unsigned short unknown_14_;
    unsigned short unknown_16_;
    unsigned short unknown_18_;
};

struct Struct_ov023_021e20f0_7 {
    signed short unknown_0_;
    unsigned short unknown_2_;
    void* unknown_4_;
    signed short unknown_8_;
    signed short unknown_a_;
    signed short unknown_c_;
    signed short unknown_e_;
    signed short unknown_10_;
    signed short unknown_12_;
    unsigned short unknown_14_;
    unsigned char unknown_16_;
    unsigned char unknown_17_;
};

struct Struct_ov023_021e20f0 {
    int unknown_0_;
    short unknown_4_;
    short unknown_6_;
    signed short unknown_8_;
    char unknown_a_[0x10 - 0xa];
    unsigned short unknown_10_;
    unsigned short unknown_12_;
};

struct Struct_ov023_021e20f0_2 { unsigned char unknown_0_0_ : 4; unsigned char unknown_0_4_ : 4; };

struct Struct_ov023_021e20f0_3 {
    short unknown_0_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    signed short unknown_4_;
    signed short unknown_6_;
    signed short unknown_8_;
    signed short unknown_a_;
    int unknown_c_;
    unsigned char unknown_10_;
};

// USA: func_ov023_021e20f0
extern "C" ARM int func_ov023_021e20f0(struct Struct_ov023_021e20f0_5* arg0, SafeAllocator* arg1,
        struct Struct_ov023_021e20f0_4* arg2, void* arg3) {
    short var0 = -1;
    if (arg1 == 0) return 1;
    if (arg2 == 0) return 1;
    if (arg3 == 0) return 1;

    if (memcmp((unsigned char*)((char*)header + 8), &data_ov023_021fdc90, 3) != 0) {
        return 1;
    }

    arg2->unknown_c_ = (int)((char*)arg2 + arg2->unknown_c_);
    arg2->unknown_14_ = (int)((char*)arg2 + arg2->unknown_14_);
    arg0->unknown_14_ = 0;
    arg0->unknown_16_ = 0;
    arg0->unknown_14_ = arg2->unknown_18_;
    arg0->unknown_8_ = arg1->Allocate(arg0->unknown_14_ * 0x18);
    struct Struct_ov023_021e20f0_6* var1 = (struct Struct_ov023_021e20f0_6*)((char*)arg2 + arg2->unknown_4_);
    unsigned short var2 = arg0->unknown_14_;

    unsigned short var3;
    for (var3 = 0; var3 < var2; var3++) {
        struct Struct_ov023_021e20f0_6* var4 = (struct Struct_ov023_021e20f0_6*)((char*)var1 + var3 * 0x1c);
        struct Struct_ov023_021e20f0_7* var5 = (struct Struct_ov023_021e20f0_7*)((char*)arg0->unknown_8_ + var3 * 0x18);

        var5->unknown_0_ = var0;
        var5->unknown_2_ = 0;
        var5->unknown_4_ = 0;
        var5->unknown_a_ = 0;
        var5->unknown_8_ = var5->unknown_a_;
        var5->unknown_c_ = var0;
        var5->unknown_e_ = var0;
        var5->unknown_10_ = var0;
        var5->unknown_12_ = var0;
        var5->unknown_14_ = 0;
        var5->unknown_16_ = 3;
        var5->unknown_17_ = 0xff;

        var5->unknown_8_ = var4->unknown_8_;
        var5->unknown_a_ = var4->unknown_a_;
        var5->unknown_2_ = var4->unknown_e_;
        var5->unknown_4_ = arg1->Allocate(var4->unknown_e_ * 2);
        char* var6 = (char*)arg2->unknown_14_ + var4->unknown_4_;
        if (var6 != 0) {
            memcpy(var5->unknown_4_, var6, var4->unknown_e_ * 2);
        }
        var5->unknown_0_ = var4->unknown_10_;
        var5->unknown_c_ = var4->unknown_12_;
        var5->unknown_e_ = var4->unknown_14_;
        var5->unknown_10_ = var4->unknown_16_;
        var5->unknown_12_ = var4->unknown_18_;
        arg0->unknown_16_ = arg0->unknown_16_ + var5->unknown_2_;
    }

    arg0->unknown_c_ = arg1->Allocate(arg0->unknown_16_ * 0x14);
    struct Struct_ov023_021e20f0* var7 = (struct Struct_ov023_021e20f0*)arg2->unknown_c_;

    unsigned short var8;
    for (var8 = 0; var8 < arg0->unknown_16_; var8++) {
        struct Struct_ov023_021e20f0* var9 = (struct Struct_ov023_021e20f0*)((char*)var7 + var8 * 0x28);
        struct Struct_ov023_021e20f0_3* var10 = (struct Struct_ov023_021e20f0_3*)((char*)arg0->unknown_c_ + var8 * 0x14);

        var10->unknown_0_ = -1;
        var10->unknown_2_ = 0;
        struct Struct_ov023_021e20f0_2* var11 = (struct Struct_ov023_021e20f0_2*)&var10->unknown_3_;
        var11->unknown_0_0_ = 0xa;
        var11->unknown_0_4_ = 0xf;
        var10->unknown_6_ = 0;
        var10->unknown_4_ = var10->unknown_6_;
        var10->unknown_a_ = 0;
        var10->unknown_8_ = var10->unknown_a_;
        var10->unknown_c_ = 0;
        var10->unknown_10_ = 0;

        var10->unknown_4_ = var9->unknown_4_;
        var10->unknown_6_ = var9->unknown_6_;
        var10->unknown_0_ = var9->unknown_8_;

        switch (var9->unknown_0_) {
        case 0:
            var10->unknown_2_ = 2;
            var10->unknown_8_ = *(unsigned short*)((char*)var9 + 0xc);
            var10->unknown_a_ = *(unsigned short*)((char*)var9 + 0xe);
            break;
        case 1:
            var10->unknown_2_ = 1;
            var10->unknown_8_ = *(unsigned short*)((char*)var9 + 0xc);
            var10->unknown_a_ = *(unsigned short*)((char*)var9 + 0xe);
            break;
        case 3:
            if (*(int*)((char*)var9 + 0xc) == 0) {
                var10->unknown_8_ = var9->unknown_10_;
                var10->unknown_a_ = var9->unknown_12_;
            }
            break;
        case 2:
        default:
            break;
        }
    }

    return 0;
}
