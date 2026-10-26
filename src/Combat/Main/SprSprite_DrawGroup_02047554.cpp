#include <globaldefs.h>

extern "C" void func_02047718(void* arg0, void* arg1, int arg2);

struct Struct_02047554 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    unsigned char* unknown_4_;
};

struct Struct_02047554_2 {
    unsigned char unknown_0_0_ : 1;
    unsigned char unknown_0_1_ : 1;
    unsigned char unknown_0_2_ : 6;
};

struct Struct_02047554_3 {
    char unknown_0_[0x8];
    struct Struct_02047554* unknown_8_;
    char unknown_c_[0x1c - 0x8 - 4];
    int unknown_1c_;
    int unknown_20_;
    int unknown_24_;
    char unknown_28_[0x34 - 0x28];
    int unknown_34_;
    int unknown_38_;
    int unknown_3c_;
    char unknown_40_[0x82 - 0x40];
    short unknown_82_;
    struct Struct_02047554_2 unknown_84_;
};

// Main, originally func_02047554 (USA 0x02047554, EUR 0x02047564, JPN 0x02048374)
extern "C" ARM void SprSprite_DrawGroup(struct Obj02047554* obj, int idx, int something) {
    if (!obj->f84.bit0) return;
    if (!obj->f84.bit1) return;
    if (obj->f82 <= 0) return;

    struct Struct_02047554* var0 = arg0->unknown_8_ + arg1;
    if (var0->unknown_4_ == 0 || var0->unknown_2_ == 0) return;

    volatile int* var1 = (volatile int*)0x4000444;
    *var1 = 0;
    *(volatile int*)((char*)var1 + 0x7c) = 0x7fffffff;
    *(volatile int*)((char*)var1 + 0x80) = 0x4210;

    int var2 = arg0->unknown_1c_;
    int var3 = arg0->unknown_20_ + var0->unknown_1_ * arg0->unknown_38_;
    int var4 = arg0->unknown_24_;
    *(volatile int*)((char*)var1 + 0x2c) = var2;
    *(volatile int*)((char*)var1 + 0x2c) = var3;
    *(volatile int*)((char*)var1 + 0x2c) = var4;

    int var5 = arg0->unknown_3c_;
    int var6 = arg0->unknown_34_;
    int var7 = -arg0->unknown_38_;
    *(volatile int*)((char*)var1 + 0x28) = var6;
    *(volatile int*)((char*)var1 + 0x28) = var7;
    *(volatile int*)((char*)var1 + 0x28) = var5;

    unsigned char* var8 = var0->unknown_4_;
    int var9;
    for (var9 = 0; var9 < var0->unknown_2_; ) {
        func_02047718(arg0, var8, arg2);
        var9++;
        var8 += 8;
    }
    *(volatile int*)0x4000448 = 1;
}
