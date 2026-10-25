#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"
#include "Combat/SearchEntry.h"
#include "Resource/GameResources.h"
struct Struct_0202b2f0 {
    int unknown_0_;
    unsigned short unknown_4_;
    unsigned char unknown_6_[0x7ba];
    struct Struct_0202b2f0_3 {
        unsigned short unknown_0_;
        unsigned short unknown_2_0_:1;
        unsigned short unknown_2_1_:4;
        unsigned short unknown_2_5_:11;
    } unknown_7c0_;
    unsigned char unknown_7c4_[0x7fc];
    int unknown_fc0_;
    unsigned char unknown_fc4_[0x4a];
    unsigned char unknown_100e_;
    unsigned char unknown_100f_;
    unsigned char unknown_1010_;
    unsigned char unknown_1011_;
    unsigned char unknown_1012_[0x26];
    signed char unknown_1038_[16];
    signed char unknown_1048_[16];
    int inline_0202b2f0() const {
        return unknown_0_ != 0;
    }
};
struct FlagWord02046708;
unsigned short GetGlobalHalf0x0_0202df58();
void* GlobalFlags_GetInstance();
int TestFlags02046708(FlagWord02046708*, unsigned int);
int GetGlobalField0x10_0202d6a8();
extern "C" int func_0202d8e8();
extern "C" void func_0202db64(int, int, int);
extern "C" void func_0202bc00(Struct_0202b2f0*, int);
extern "C" void func_0202bf40(Struct_0202b2f0*);
extern "C" void func_0202c04c(Struct_0202b2f0*);
extern "C" int func_0202c508(Struct_0202b2f0*);
extern "C" unsigned short func_0202bc8c(Struct_0202b2f0*);
extern "C" signed char func_0202bcbc(Struct_0202b2f0*, int);
extern "C" int func_0202bd34(Struct_0202b2f0*, int);
extern "C" void func_0202c21c(Struct_0202b2f0*, int);
extern "C" int func_0202c1c0(Struct_0202b2f0*, int);
extern "C" void func_0202c5bc(Struct_0202b2f0*, int);
extern "C" void func_0202c1e8(Struct_0202b2f0*, int);
extern "C" void func_0202c660(Struct_0202b2f0*, int);
extern "C" int func_0202d6b8();

// USA: func_0202b2f0
extern "C" ARM void func_0202b2f0(Struct_0202b2f0* arg0) {
    Struct_0202b2f0::Struct_0202b2f0_3* var0;
    unsigned short var1[4];
    unsigned short var2[4];
    for (int var3 = 0; var3 < 4; var3++) {
        if (var3 == arg0->unknown_1038_[func_0202df58()]) {
            continue;
        }
        Struct_0202b2f0_2* var4 = func_0202c178(arg0, var3);
        if (!var4) {
            continue;
        }
        unsigned int var5 = var4->unknown_0_.unknown_0_0_;
        var4->unknown_0_.unknown_0_0_ = 0;
        unsigned short var6 = var4->unknown_4_;
        var1[var3] = var5;
        var2[var3] = var4->unknown_4_;
        var4->unknown_4_ = var6 & ~0xffff;
    }
    GameState::GetInstance();
    if (TestFlags02046708((FlagWord02046708*)GlobalFlags_GetInstance(), 0x1000000)) {
        object->state = -1;
        return;
    }
    switch (func_0202d6a8()) {
    case 7: {
        int var7 = func_0202d8e8();
        arg0->unknown_4_++;
        func_0202db64(4, arg0->unknown_4_, var7);
        break;
    }
    case 9:
        arg0->unknown_0_ = -1;
        break;
    }
    switch (arg0->unknown_0_) {
    case 2:
        func_0202bc00(arg0, 1);
        break;
    case 3:
        func_0202c478(arg0);
        break;
    case 5:
        func_0202bc00(arg0, 1);
        func_0202bf40(arg0);
        func_0202c04c(arg0);
        break;
    case 6:
        func_0202bf40(arg0);
        func_0202c04c(arg0);
        break;
    }
    if (arg0->unknown_fc0_) {
        for (int var8 = 0; var8 < 4; var8++) {
            if (var8 == arg0->unknown_1038_[func_0202df58()]) {
                continue;
            }
            Struct_0202b2f0_2* var9 = func_0202c178(arg0, var8);
            if (!var9) {
                continue;
            }
            var9->unknown_0_.unknown_0_0_ = var1[var8];
            var9->unknown_4_ = (var9->unknown_4_ & ~0xffff) | var2[var8];
        }
    } else if (func_0202c508(arg0)) {
        if (arg0->unknown_1011_) {
            unsigned int var10 = func_0202bc8c(arg0);
            var0 = &arg0->unknown_7c0_;
            unsigned int var11 = var0->unknown_2_1_;
            for (int var12 = 1; var12 < 4; var12++) {
                if (!(var10 & (1 << var12)) || arg0->unknown_1038_[var12] != 0) {
                    continue;
                }
                for (int var13 = 1; var13 < 4; var13++) {
                    if (var11 & (1 << var13)) {
                        continue;
                    }
                    int var14;
                    for (int var15 = 1; var15 < 4; var15++) {
                        if ((signed char)var13 == arg0->unknown_1038_[var15]) {
                            var14 = 1;
                            goto selectorFound;
                        }
                    }
                    var14 = 0;
selectorFound:
                    if (!var14) {
                        arg0->unknown_1038_[var12] = var13;
                        break;
                    }
                }
            }
        }
        arg0->unknown_100e_ = 0;
        int var16 = func_0202bcbc(arg0, 0);
        if (!(arg0->unknown_100f_ & (1 << var16))) {
            var0 = &arg0->unknown_7c0_;
            for (int var17 = 1; var17 < 4; var17++) {
                int var18 = func_0202bcbc(arg0, var17);
                if ((arg0->unknown_100f_ & (1 << var18)) && !(var0->unknown_2_1_ & (1 << var17))) {
                    if (!func_0202bd34(arg0, var17)) {
                        func_0202c21c(arg0, var17);
                    }
                } else if (func_0202c1c0(arg0, var17)) {
                    if (!func_0202bd34(arg0, var17)) {
                        func_0202c5bc(arg0, var17);
                    }
                } else if (func_0202bd34(arg0, var17)) {
                    func_0202c1e8(arg0, var17);
                    func_0202c660(arg0, var17);
                    if (arg0->inline_0202b2f0()) {
                        GameResources* var19 = GetGameResources();
                        memset(var19->unknown_435c_[var17], 0, sizeof(var19->unknown_435c_[var17]));
                    }
                }
            }
        } else {
            for (int var20 = 1; var20 < 4; var20++) {
                if (func_0202c1c0(arg0, var20) && !func_0202bd34(arg0, var20)) {
                    func_0202c21c(arg0, var20);
                }
            }
        }
    } else {
        Struct_0202b2f0_2* var21 = func_0202c178(arg0, 0);
        arg0->unknown_1038_[1] = var21->unknown_2_5_;
        arg0->unknown_1038_[2] = var21->unknown_2_7_;
        arg0->unknown_1038_[3] = var21->unknown_3_1_;
        if (var21->unknown_2_5_) {
            arg0->unknown_1048_[1] = var21->unknown_2_5_;
        }
        if (var21->unknown_2_7_) {
            arg0->unknown_1048_[2] = var21->unknown_2_7_;
        }
        if (var21->unknown_3_1_) {
            arg0->unknown_1048_[3] = var21->unknown_3_1_;
        }
    }
    if (arg0->unknown_1038_[func_0202df58()] != 0 && func_0202d6b8() == 20) {
        func_0202c5bc(arg0, 0);
    }
}
