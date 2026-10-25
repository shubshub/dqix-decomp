#include <globaldefs.h>
#include "Resource/ActionDataTables.h"
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"

struct Struct_ov024_021fb91c_4 {
    unsigned int unknown_0_;
    unsigned int unknown_4_0_ : 12;
    unsigned int unknown_5_4_ : 20;
    unsigned int unknown_8_0_ : 8;
    unsigned int unknown_9_0_ : 2;
    unsigned int unknown_9_2_ : 22;
    unsigned int unknown_c_;
    unsigned int unknown_10_;
    unsigned int unknown_14_0_ : 28;
    unsigned int unknown_17_4_ : 4;
    unsigned int unknown_18_0_ : 5;
    unsigned int unknown_18_5_ : 7;
    unsigned int unknown_19_4_ : 20;
};
struct Struct_ov024_021fb91c_5 {
    float unknown_0_;
    unsigned char unknown_4_, unknown_5_, unknown_6_, unknown_7_, unknown_8_, unknown_9_;
    unsigned char unknown_a_[2];
};
struct Struct_ov024_021f6a1c {
    Struct_ov024_021fb91c_5 unknown_0_[16];
    int unknown_c0_;
    float unknown_c4_;
    Struct_ov024_021f6a1c() { memset(this, 0, sizeof(*this)); }
};
struct Struct_ov024_021fb91c_6 {
    unsigned char unknown_0_[0x3ec];
    int unknown_3ec_;
    Struct_ov024_021fb91c_4* unknown_3f0_;
    unsigned char unknown_3f4_[5];
    unsigned char unknown_3f9_;
    unsigned char unknown_3fa_[2];
    Struct_ov024_021f6a1c* unknown_3fc_;
    Struct_ov024_021fb91c_5 unknown_400_;
    GameObject* unknown_40c_;
    int unknown_410_;
};
struct Struct_ov024_021fb91c {
    unsigned char unknown_0_[0x8e18];
    unsigned char* unknown_8e18_;
};
struct Struct_ov024_021fb91c_2 {
    Struct_ov024_021fb91c* unknown_0_;
    short unknown_4_;
    unsigned short unknown_6_;
    GameObject* unknown_8_;
    unsigned char unknown_c_[0x114 - 0xc];
    float unknown_114_[4];
    float unknown_124_;
    int unknown_128_;
    unsigned char unknown_12c_[0x25c - 0x12c];
    Struct_ov024_021fb91c_6 unknown_25c_;
};
struct Struct_ov024_021fb91c_3 {
    PrimaryCombatStats unknown_0_;
    unsigned int unknown_14_;
    unsigned char unknown_18_[0x24 - 0x18];
    signed char unknown_24_;
};
struct Struct_ov024_021da670_6;
struct Struct_ov024_021dd028_5;
struct Struct_02010088;
extern "C" int func_02053c6c(unsigned char*);
extern "C" int func_020a35e0(unsigned char*, unsigned char);
extern "C" int func_02010088(Struct_02010088*);
extern "C" int func_ov024_021da998(Struct_ov024_021da670_6*);
extern "C" int func_ov024_021dd260(Struct_ov024_021dd028_5*);
extern "C" float func_02074738(int, int);
extern "C" void func_ov024_021f6a1c(Struct_ov024_021f6a1c*, void*);
extern "C" void func_ov024_021f8938(void*, float*, float*, int, void*, GameObject*);
extern "C" void func_ov024_021f6a4c(void*, void*);
extern "C" void func_ov024_021fd858(void*);
extern "C" void func_ov024_021f9874(void*, void*, int, int);

static inline unsigned int inline_ov024_021fb91c(GameObject* arg0) { return arg0->currentStats_->primaryStats.maxHP; }

// USA: func_ov024_021fb91c
extern "C" ARM void func_ov024_021fb91c(Struct_ov024_021fb91c_2* arg0) {
    Struct_ov024_021fb91c_4* var0 = arg0->unknown_25c_.unknown_3f0_;
    if (var0->unknown_9_0_ == 1) return;
    float var1 = arg0->unknown_124_;
    int var2 = 1;
    if (arg0->unknown_114_[arg0->unknown_128_] >= var1) var2 = 0;
    if (!var2 && var0->unknown_18_0_ == 0) return;
    GameObject* var3 = arg0->unknown_8_;
    func_02053c6c((unsigned char*)var3);
    func_020797dc();
    int var4 = arg0->unknown_25c_.unknown_3ec_;
    float var5 = 0;
    float var6 = 0;
    func_ov024_021f8938(arg0, &var5, &var6, var4, arg0->unknown_25c_.unknown_3f0_, var3);
    if (var0->unknown_4_0_ == 0x21) {
        var5 = 999.0f;
        var6 = 999.0f;
    }
    if ((var0->unknown_10_ & 0x2000) &&
        (func_ov024_021da998((Struct_ov024_021da670_6*)var3) ||
        func_ov024_021dd260((Struct_ov024_021dd028_5*)var3))) {
        float var7 = func_02074738(((Struct_ov024_021fb91c_3*)var3->currentStats_)->unknown_24_, 0);
        var5 *= var7;
        var6 *= var7;
    }
    Struct_ov024_021f6a1c var8;
    memset(&var8, 0, sizeof(var8));
    for (int var9 = 0; var9 < 4; ++var9) {
        if (!func_020a35e0(arg0->unknown_0_->unknown_8e18_, var9)) continue;
        if (var0->unknown_17_4_ == 1 && var9 != arg0->unknown_4_) continue;
        if (var0->unknown_17_4_ == 8 && var9 == arg0->unknown_4_) continue;
        GameObject* var10 = GetCombatantByID((int)arg0->unknown_0_, (short)var9);
        if (!var10) continue;
        if (func_02010088((Struct_02010088*)var10)) continue;
        arg0->unknown_25c_.unknown_3f9_ = 1;
        if (arg0->unknown_114_[var9] >= var1) arg0->unknown_25c_.unknown_3f9_ = 0;
        if (!arg0->unknown_25c_.unknown_3f9_ && var0->unknown_18_0_ == 0) continue;
        if ((var0->unknown_10_ & 0x400) && (((Struct_ov024_021fb91c_3*)var10->currentStats_)->unknown_14_ & 0x200)) continue;
        float var11 = var5;
        int var12 = var10->currentStats_->primaryStats.currHP;
        int var13 = var10->currentStats_->primaryStats.maxHP;
        if (var0->unknown_4_0_ == 0x1fa) var11 = 0.4f * (float)var13;
        if (var0->unknown_18_5_ == 14) {
            if ((float)var12 / (float)var13 > 0.08f) continue;
            unsigned int var14 = inline_ov024_021fb91c(var3);
            unsigned int var15 = var3->currentStats_->primaryStats.currHP;
            if (((float)var15 - var11) / (float)var14 < 0.5f) continue;
            var11 *= 0.3f;
        }
        var13 -= var12;
        if (var11 > (float)var13) var11 = (float)var13;
        Struct_ov024_021fb91c_6* var16 = &arg0->unknown_25c_;
        Struct_ov024_021fb91c_5 var17;
        var17.unknown_5_ = 0;
        var17.unknown_7_ = 100;
        var17.unknown_8_ = 3;
        var17.unknown_0_ = var11;
        var17.unknown_6_ = var9;
        func_ov024_021f6a1c(&var8, &var17);
        if (var0->unknown_18_0_ != 0) {
            arg0->unknown_25c_.unknown_3fc_ = &var8;
            func_ov024_021f6a4c(&var16->unknown_400_, &var17);
            arg0->unknown_25c_.unknown_40c_ = var10;
            arg0->unknown_25c_.unknown_410_ = var9;
            func_ov024_021fd858(arg0);
        }
        if (action->targetKind == 2 || action->targetKind == 1 || action->targetKind == 8) {
            func_ov024_021f9874(context, &list, 0, (unsigned char)target->obj3D_.actorIndex_);
            memset(&list, 0, sizeof(list));
        }
    }
    if (action->targetKind == 4 || action->targetKind == 3) {
        GetCombatantByID((int)context->battle, 0);
        int target = (unsigned char)actor->obj3D_.actorIndex_;
        if (action->targetKind == 3) target = 0xff;
        func_ov024_021f9874(context, &list, 0, target);
    }
}
