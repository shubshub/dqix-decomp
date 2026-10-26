#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_02048150;

extern "C" int *LinkSession_GetInstance(void);
int ArrayContainsByte_02086ef0(ArrayContainsByteStruct *arr, int value);
int LinkSession_IsActive(int *p);
int HasPositiveField304Short4_02154a34(void *self, int id);
int HasPositiveField256Short178_02154b94(void *self, int id);
void *LookupElementByKey02079ee0(void *table, int key);

struct Struct_ov002_02153ccc {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned short unknown_2_;
    unsigned char unknown_4_;
    unsigned char unknown_5_;
};

struct Struct_ov002_02153ccc_2 {
    short unknown_0_;
    signed char unknown_2_;
    unsigned char unknown_3_;
    signed char unknown_4_[4];
    Struct_ov002_02153ccc unknown_8_[4];
    Struct_ov002_02153ccc unknown_20_[4];
};

struct Struct_ov002_02153ccc_3 {
    unsigned char unknown_0_[8];
    unsigned int unknown_8_0_ : 14;
    unsigned int unknown_9_6_ : 8;
    unsigned int unknown_a_6_ : 10;
};

extern "C" void func_ov002_02153e90(Struct_ov002_02153ccc *arg0);
extern "C" int func_ov002_02154a6c(void *arg0, int arg1, int arg2);
extern "C" int func_ov002_021538e4(void *arg0, Struct_ov002_02153ccc_3 *arg1, void *arg2, int arg3);
extern "C" unsigned short func_ov002_021548c4(void *arg0, int arg1, int arg2, Struct_ov002_02153ccc *arg3);
extern "C" void func_ov017_021c9e00(int arg0, int arg1, int arg2, int arg3);

// USA: func_ov002_02153ccc
extern "C" ARM int func_ov002_02153ccc(void **self, Info02153ccc *info, Action02153ccc *action, int alt) {
    if (info == 0) return 0;
    if (action == 0) return 0;
    ArrayContainsByteStruct *party = (ArrayContainsByteStruct *)GameState_GetParty(GameState::GetInstance());
    int *g                         = LinkSession_GetInstance();
    Entry02153ccc *entries         = info->entries;
    int changed                    = 0;
    if (alt) entries = info->altEntries;
    for (int i = 0; i < 4; i++) {
        func_ov002_02153e90(&entries[i]);
    }
    for (int var5 = 0; var5 < arg1->unknown_3_; var5++) {
        Struct_ov002_02153ccc *var6 = &var2[var5];
        int var7           = arg1->unknown_4_[var5];
        int var8;
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
        if (arg1->unknown_0_ == 0x21) {
            var8 = 999;
        } else {
            void *var9 = func_02079ee0(*arg0, arg2->unknown_9_6_);
            if (var9 == 0) continue;
            var8 = func_ov002_021538e4(arg0, arg2, var9, arg1->unknown_2_);
        }
        if (var6->unknown_4_) {
            var6->unknown_2_ = var8;
            var6->unknown_0_ = 3;
        } else {
            var6->unknown_2_ = func_ov002_021548c4(arg0, var7, var8, var6);
        }
        if (e->state == 0) continue;
        if (LinkSession_IsActive(g) && ArrayContainsByte_02086ef0(party, id)) {
            func_ov017_021c9e00(id, 0, 0, 1);
        }
        var3 = 1;
    }
    return var3;
}
