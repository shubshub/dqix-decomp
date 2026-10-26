#include <globaldefs.h>

extern "C" void* OamManager_GetInstance(void);
extern "C" void* OamManager_GetMainOamBuffer(void* base);
extern "C" void* OamManager_GetSubOamBuffer(void* base);
extern "C" unsigned int func_020937f0(int engine);
int GetDisplayModeCode0209378c(int engine);

struct Struct_020e1780_2 {
    unsigned int unknown_0_;
    unsigned short unknown_4_;
};
extern "C" void func_020e197c(struct Struct_020e1780_2* arg0, int arg1, int arg2, int arg3,
        int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11);

struct Struct_020e1780_3 {
    unsigned int unknown_0_;
    unsigned int unknown_4_;
    unsigned char unknown_8_;
    unsigned char unknown_9_;
    unsigned char unknown_a_;
    unsigned char unknown_b_;
};

struct Struct_020e1780_4 {
    char unknown_0_[8];
    struct Struct_020e1780_3* unknown_8_;
    char unknown_c_[0x24 - 0xc];
    unsigned int unknown_24_;
    char unknown_28_[0x2e - 0x28];
    unsigned char unknown_2e_;
    unsigned char unknown_2f_;
    unsigned int unknown_30_;
    unsigned int unknown_34_;
    unsigned char unknown_38_;
    unsigned char unknown_39_;
    unsigned char unknown_3a_;
    unsigned char unknown_3b_;
    unsigned char unknown_3c_;
    unsigned char unknown_3d_;
    unsigned char unknown_3e_;
    unsigned char unknown_3f_0_ : 1;
};

struct Struct_020e1780 {
    char unknown_0_[4];
    struct Struct_020e1780_4* unknown_4_;
};

// USA: func_020e1780
extern "C" ARM void func_020e1780(struct Struct_020e1780* arg0) {
    int var0;
    int var1;
    struct Struct_020e1780_4* var2;
    struct Struct_020e1780_2* var3;
    int var4;
    int var5;
    int var6;
    unsigned int var7;
    struct Struct_020e1780_3* var8;
    int var9;
    int var10;
    int var11;
    unsigned int var12;
    int var13;
    void* var14;

    if (arg0->unknown_4_ == 0) return;
    if (!arg0->unknown_4_->unknown_3f_0_ || (var8 = arg0->unknown_4_->unknown_8_) == 0) return;

    base = OamManager_GetInstance();
    OamManager_GetMainOamBuffer(base);
    display = obj->panel->display;
    x = obj->panel->x;
    y = obj->panel->y;
    func_020937f0(display);
    shift = GetDisplayModeCode0209378c(display);
    pack = (struct Pack020e197c*)OamManager_GetMainOamBuffer(base);
    if (display != 0) {
        pack = (struct Pack020e197c*)OamManager_GetSubOamBuffer(base);
    }

    var3 += arg0->unknown_4_->unknown_3d_;
    var12 = arg0->unknown_4_->unknown_30_;
    var5 = arg0->unknown_4_->unknown_3c_;
    for (var9 = 0; var9 < var5; var9++) {
        struct Struct_020e1780_3* var15 = &var8[var9];
        unsigned int var16 = var12 + var15->unknown_4_;
        var16 >>= var6;
        func_020e197c(var3, var0 + var15->unknown_8_, var4 + var15->unknown_9_, 0, 0, 0, 0, var15->unknown_0_, 0,
                var16, 0xe, 0);
        var3++;
    }

    var2 = arg0->unknown_4_;
    var7 = (var12 + var2->unknown_34_) >> var6;
    var11 = var2->unknown_3a_ - 4;
    var13 = var2->unknown_3b_ - 4;
    var9 = 0;
    for (var10 = 0; var10 < var13; var10 += var2->unknown_2f_) {
        if (var13 < var10 + var2->unknown_2f_) var10 = var13 - var2->unknown_2f_;
        for (; var9 < var11; var9 += var2->unknown_2e_) {
            if (var11 < var9 + var2->unknown_2e_) var9 = var11 - var2->unknown_2e_;
            func_020e197c(var3, var0 + var9 + 2, var4 + var10 + 2, 0, 1, 0, 0, var2->unknown_24_, 0, var7, 0xe, 0);
            var3++;
        }
        var9 = 0;
    }
}
