#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov017_021c7334_14104 = 0x3508 };
#else
enum { Enum_ov017_021c7334_14104 = 0x3718 };
#endif
#include "GameState/GameState.h"

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void* func_ov017_021b8468(void* obj);
ARM void* GetField6b0_021b8470(void* obj);
ARM int GameState_GetProtagonistIndex(GameState* battleStruct);

struct Struct_ov017_021c7334 {
    char unknown_0_[4];
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    char unknown_8_[9];
    struct {
        unsigned char unknown_0_0_ : 1;
        unsigned char unknown_0_1_ : 1;
        unsigned char unknown_0_2_ : 1;
        unsigned char unknown_0_3_ : 1;
        unsigned char unknown_0_4_ : 4;
    } unknown_11_;
    char unknown_12_;
    struct {
        unsigned char unknown_0_0_ : 7;
        unsigned char unknown_0_7_ : 1;
    } unknown_13_;
};

struct Struct_ov017_021c7334_2 {
    char unknown_0_[0x3a];
    unsigned char unknown_3a_;
    struct {
        unsigned char unknown_0_0_ : 1;
        unsigned char unknown_0_1_ : 1;
        unsigned char unknown_0_2_ : 1;
        unsigned char unknown_0_3_ : 1;
        unsigned char unknown_0_4_ : 4;
    } unknown_3b_;
};

// USA: func_ov017_021c7334
extern "C" ARM void func_ov017_021c7334(void* arg0, struct Struct_ov017_021c7334* arg1, GameState* arg2, char* arg3) {
    void* var0 = *(void**)(arg3 + Enum_ov017_021c7334_14104);
    void* var1 = func_ov017_021b8478(var0);
    if (!var1) {
        return;
    }
    if (!func_ov017_021b8468(var0)) {
        return;
    }
    if (!func_ov017_021b8470(var0)) {
        return;
    }
    int val = GameState_GetProtagonistIndex(battleStruct);
    if (*(signed char*)((char*)p1c + 0x2a) == val) {
        return;
    }
    if (*(unsigned short*)((char*)var1 + 0x8) != arg1->unknown_4_) {
        return;
    }
    GameObject* var3 = arg2->GetCombatantByIndex(arg1->unknown_6_);
    if (!var3) {
        return;
    }
    ((struct Struct_ov017_021c7334_2*)var3->currentStats_)->unknown_3b_.unknown_0_0_ = arg1->unknown_11_.unknown_0_0_;
    ((struct Struct_ov017_021c7334_2*)var3->currentStats_)->unknown_3b_.unknown_0_1_ = arg1->unknown_11_.unknown_0_1_;
    ((struct Struct_ov017_021c7334_2*)var3->currentStats_)->unknown_3b_.unknown_0_2_ = arg1->unknown_11_.unknown_0_2_;
    ((struct Struct_ov017_021c7334_2*)var3->currentStats_)->unknown_3b_.unknown_0_3_ = arg1->unknown_11_.unknown_0_3_;
    ((struct Struct_ov017_021c7334_2*)var3->currentStats_)->unknown_3b_.unknown_0_4_ = arg1->unknown_11_.unknown_0_4_;
    ((struct Struct_ov017_021c7334_2*)var3->currentStats_)->unknown_3a_ = arg1->unknown_13_.unknown_0_7_ != 0;
}
