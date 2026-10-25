#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_02048150;

extern "C" int *func_0202ae18(void);
extern "C" int func_02086ef0(Struct_02048150 *arg0, int arg1);
extern "C" int func_0202b7d8(int *arg0);
extern "C" int func_ov002_02154a34(void *arg0, int arg1);
extern "C" int func_ov002_02154b94(void *arg0, int arg1);

struct Struct_ov002_02153ea4 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned short unknown_2_;
    unsigned char unknown_4_;
    unsigned char unknown_5_;
};

struct Struct_ov002_02153ea4_2 {
    unsigned char unknown_0_[2];
    signed char unknown_2_;
    unsigned char unknown_3_;
    signed char unknown_4_[4];
    Struct_ov002_02153ea4 unknown_8_[4];
    Struct_ov002_02153ea4 unknown_20_[4];
};

extern "C" void func_ov002_02153e90(Struct_ov002_02153ea4 *arg0);
extern "C" int func_ov002_02154a6c(void *arg0, int arg1, int arg2);
extern "C" unsigned short func_ov002_021549c8(void *arg0, int arg1, int arg2, Struct_ov002_02153ea4 *arg3);
extern "C" void func_ov017_021c9e00(int arg0, int arg1, int arg2, int arg3);

// USA: func_ov002_02153ea4
extern "C" ARM int func_ov002_02153ea4(void *self, Info02153ea4 *info, int enabled, int alt) {
    if (info == 0) return 0;
    if (enabled == 0) return 0;
    ArrayContainsByteStruct *party = (ArrayContainsByteStruct *)GameState_GetParty(GameState::GetInstance());
    int *g                         = func_0202ae18();
    int changed                    = 0;
    Entry02153ea4 *entries         = info->entries;
    if (alt) entries = info->altEntries;
    for (int i = 0; i < 4; i++) {
        func_ov002_02153e90(&entries[i]);
    }
    for (int var5 = 0; var5 < arg1->unknown_3_; var5++) {
        Struct_ov002_02153ea4 *var6 = &var3[var5];
        int var7           = arg1->unknown_4_[var5];
        if (!func_02086ef0(var0, var7)) var6->unknown_4_ = 1;
        if (!func_ov002_02154a6c(arg0, var7, arg1->unknown_2_)) {
            var6->unknown_0_ = 1;
            continue;
        }
        if (func_ov002_02154b94(arg0, var7)) {
            var6->unknown_0_ = 2;
            continue;
        }
        if (!func_ov002_02154a34(arg0, var7)) continue;
        if (var6->unknown_4_) {
            var6->unknown_2_ = 1;
            var6->unknown_0_ = 3;
        } else {
            var6->unknown_2_ = func_ov002_021549c8(arg0, var7, 2, var6);
        }
        if (var6->unknown_0_ == 0) continue;
        if (func_0202b7d8(var1) && func_02086ef0(var0, var7)) {
            func_ov017_021c9e00(var7, 0, 0, 1);
        }
        var2 = 1;
    }
    return var2;
}
