#include "GameState/GameState.h"
#include "Util/Random.h"
#include <globaldefs.h>
#include "Resource/GameResources.h"

struct Struct_02048150;
extern "C" int func_02086ef0(Struct_02048150 *arg0, int arg1);
extern "C" int func_0202b7d8(int *arg0);
extern "C" int func_ov002_02154b94(void *arg0, int arg1);
extern "C" int func_ov002_02154a34(void *arg0, int arg1);
extern "C" int *func_0202ae18(void);
extern "C" void func_ov002_02153e90(char *arg0);
extern "C" int func_ov002_02154a6c(char *arg0, int arg1, int arg2);
extern "C" int func_ov002_02153be0(char *arg0, int arg1, int arg2);
extern "C" void func_02048150(GameObject *arg0, int arg1, int arg2);
extern "C" void func_ov017_021c9e00(int arg0, int arg1, int arg2, int arg3);
extern "C" void func_ov017_02191108(GameResources *arg0, int arg1, int arg2, int arg3, int arg4);

struct Struct_ov002_02154230 {
    short unknown_0_;
    signed char unknown_2_;
    unsigned char unknown_3_;
    signed char unknown_4_[4];
};

struct Struct_ov002_02154230_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    short unknown_2_;
    unsigned char unknown_4_;
    unsigned char unknown_5_;
};

// USA: func_ov002_02154230
extern "C" ARM int func_ov002_02154230(char *base, struct Act02154230 *act, int target, int alt) {
    if (act == NULL) return 0;
    if (target == 0) return 0;
    GameState *gs                  = GameState::GetInstance();
    GameResources *res             = GetGameResources();
    ArrayContainsByteStruct *party = (ArrayContainsByteStruct *) GameState_GetParty(gs);
    int *ctx                       = func_0202ae18();
    struct Rec02154230 *recs       = (struct Rec02154230 *) ((char *) act + 8);
    unsigned char any              = 0;
    if (alt) recs = (struct Rec02154230 *) ((char *) act + 0x20);
    for (int i = 0; i < 4; i++) {
        func_ov002_02153e90((char *) &recs[i]);
    }
    for (int var7 = 0; var7 < arg1->unknown_3_; var7++) {
        struct Struct_ov002_02154230_2 *var8 = &var4[var7];
        int var9                  = arg1->unknown_4_[var7];
        if (!func_02086ef0(var2, var9)) var8->unknown_4_ = 1;
        if (!func_ov002_02154a6c(arg0, var9, arg1->unknown_2_)) {
            var8->unknown_0_ = 1;
            continue;
        }
        if (func_ov002_02154b94(arg0, var9)) {
            var8->unknown_0_ = 2;
            continue;
        }
        if (func_ov002_02154a34(arg0, var9)) continue;
        int var10       = 0;
        unsigned char var11 = 0;
        GameObject *var12    = func_0200ff1c(var0, var9);
        if (var12 == NULL) continue;
        if (arg1->unknown_0_ == 0x27) {
            var11     = 1;
            var10 = var12->baseStats_->primaryStats.maxHP / 2;
            if (var12->baseStats_->primaryStats.maxHP % 2) var10++;
        } else if (arg1->unknown_0_ == 0x26) {
            var11       = 0;
            int var13 = func_ov002_02153be0(arg0, arg2, arg1->unknown_2_);
            if (NextRandomMax(GetBTRandom(), 100) < var13) {
                var11     = 1;
                int var14  = var12->baseStats_->primaryStats.maxHP * (var13 - 25);
                var10 = var14 / 100;
                if (var14 % 100) var10++;
            }
        } else if (arg1->unknown_0_ == 0x197) {
            var11     = 1;
            var10 = 999;
        }
        if (!var11) continue;
        var8->unknown_0_ = 3;
        if (var8->unknown_4_) {
            var8->unknown_2_ = var10;
            var8->unknown_0_  = 3;
        } else {
            func_02048150(var12, var10, 1);
        }
        if (func_0202b7d8(var3) && func_02086ef0(var2, var9)) {
            func_ov017_021c9e00(var9, 1, 0, 1);
        }
        if (func_02086ef0(var2, var9)) {
            func_ov017_02191108(var1, 1, 1, 1, 1);
        }
        var5 = 1;
    }
    return var5;
}
