#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern "C" void SprSprite_Init(void* obj, int flag);
extern "C" void func_02047f70(void* obj, void* buf, unsigned int size, SafeAllocator* alloc);

struct Struct_02047b40_4;
struct Struct_02017098_3;

extern "C" void func_02047ed4(struct Struct_02047b40_4* arg0, int* arg1, void* arg2, unsigned int arg3, SafeAllocator* arg4);
extern "C" void func_020478bc(struct Struct_02017098_3* arg0, int arg1);

struct Struct_02047b40_5 {
    int unknown_0_;
    void* unknown_4_;
};

extern "C" void func_02048090(struct Struct_02047b40_5* arg0, int arg1, SafeAllocator* arg2);

struct Struct_02047b40_6 {
    int unknown_0_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
};

struct Struct_02047b40_7 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    Struct_02047b40_6* unknown_4_;
};

struct Struct_02047b40_8 {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
};

struct Struct_02047b40_9 {
    unsigned int unknown_0_;
    Struct_02047b40_8* unknown_4_;
};

struct Struct_02047b40 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    unsigned int unknown_4_;
};

struct Struct_02047b40_2 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
};

struct Struct_02047b40_3 {
    char unknown_0_[4];
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    Struct_02047b40_7* unknown_8_;
    Struct_02047b40_9* unknown_c_;
    char unknown_10_[4];
    Struct_02047b40_5 unknown_14_;
    char unknown_1c_[0x84 - 0x1c];
    unsigned char unknown_84_0_ : 1;
    unsigned char unknown_84_1_ : 1;
    unsigned char unknown_84_2_ : 6;
};

// Main, originally func_02047b40 (USA 0x02047b40, EUR 0x02047b50, JPN 0x02048960)
extern "C" ARM void SprSprite_Parse(struct Obj02047b40* obj, unsigned char* src, SafeAllocator* alloc) {
    unsigned char* data;
    unsigned int tail;
    int flag;
    PackedGroup* group;
    PackedTexture* tex;
    int g;
    int k;
    int n;
    FileGroup* fg;
    FileTexture* ft;
    unsigned int w;
    unsigned int h;
    unsigned int shift;
    unsigned int size;
    if (src == 0) {
        return;
    }
    flag = obj->flag0;
    if (flag) {
        if (flag) {
            SprSprite_Init(obj, flag);
        }
        arg0->unknown_84_0_ = 0;
    }
    memcpy(&arg0->unknown_6_, arg1, 2);
    memcpy(&arg0->unknown_4_, arg1 + 2, 2);
    var0 = arg1 + 4;
    var3 = arg0->unknown_8_ = (Struct_02047b40_7*)arg2->Allocate(arg0->unknown_6_ * 8);
    for (var5 = 0; var5 < arg0->unknown_6_; var5++, var3++) {
        var8 = (Struct_02047b40*)var0;
        var0 += 8;
        var3->unknown_0_ = var8->unknown_0_;
        var3->unknown_1_ = var8->unknown_2_;
        var3->unknown_2_ = var8->unknown_4_;
        var4 = var3->unknown_4_ = (Struct_02047b40_6*)arg2->Allocate(var3->unknown_2_ * 8);
        for (var6 = 0; var6 < var3->unknown_2_; var6++) {
            var9 = (Struct_02047b40_2*)var0;
            var11 = 8 << var9->unknown_4_;
            var12 = 0;
            var0 += 8;
            var10 = 8 << var9->unknown_6_;
            if (arg0->unknown_4_ == 3) {
                var12 = 1;
                var13 = var11 * var10;
                func_02047ed4((Struct_02047b40_4*)arg0, &var4->unknown_0_, var0, var13 >> 1, arg2);
            } else {
                var13 = var11 * var10;
                func_02047ed4((Struct_02047b40_4*)arg0, &var4->unknown_0_, var0, var13, arg2);
            }
            var0 += var13 >> var12;
            var4->unknown_4_ = (var9->unknown_6_ << 4) | var9->unknown_4_;
            var4->unknown_6_ = var9->unknown_0_ | ((var3->unknown_1_ - var9->unknown_2_ - var10) << 8);
            var4++;
        }
    }
    memcpy(&var1, var0, 4);
    var0 += 4;
    if (var1 <= 0x10) {
        func_02047f70(arg0, var0, 0x20, arg2);
    } else if (var1 <= 0x100) {
        func_02047f70(arg0, var0, 0x200, arg2);
    } else {
        func_02047f70(arg0, var0, var1, arg2);
    }
    var0 += var1 * 2;
    var0 += 0x1e;
    memcpy(&arg0->unknown_14_, var0, 4);
    var0 += 4;
    func_02048090(&arg0->unknown_14_, arg0->unknown_14_.unknown_0_, arg2);
    if (arg0->unknown_14_.unknown_0_ > 0) {
        for (var7 = 0; var7 < arg0->unknown_14_.unknown_0_; var7++) {
            memcpy((char*)arg0->unknown_14_.unknown_4_ + var7 * 0x1e, var0, 0x1e);
            var0 += 0x1e;
        }
        Struct_02047b40_9* var14 = arg0->unknown_c_ = (Struct_02047b40_9*)arg2->Allocate(arg0->unknown_14_.unknown_0_ * 8);
        for (int var15 = 0; var15 < arg0->unknown_14_.unknown_0_; var15++, var14++) {
            memcpy(var14, var0, 4);
            var0 += 4;
            var14->unknown_4_ = (Struct_02047b40_8*)arg2->Allocate(var14->unknown_0_ * 12);
            Struct_02047b40_8* var16 = var14->unknown_4_;
            int* var17 = (int*)var0;
            var0 += var14->unknown_0_ * 4;
            int* var18 = (int*)var0;
            var0 += var14->unknown_0_ * 4;
            int* var19 = (int*)var0;
            var0 += var14->unknown_0_ * 4;
            for (unsigned int var20 = 0; var20 < var14->unknown_0_; var20++) {
                var16->unknown_0_ = *var17;
                var16->unknown_4_ = *var18;
                var16->unknown_8_ = *var19;
                var17++;
                var18++;
                var19++;
                var16++;
            }
        }
    }
    arg0->unknown_84_0_ = 1;
    arg0->unknown_84_1_ = 1;
    if (arg0->unknown_c_ != 0) {
        if (arg0->unknown_c_->unknown_0_ == 0 && arg0->unknown_14_.unknown_0_ == 1) {
            func_020478bc((Struct_02017098_3*)arg0, 0);
        } else {
            func_020478bc((Struct_02017098_3*)arg0, 1);
        }
    } else {
        func_020478bc((Struct_02017098_3*)arg0, 0);
    }
}
