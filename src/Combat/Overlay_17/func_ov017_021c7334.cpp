#include <globaldefs.h>

#if defined(jpn)
enum { kRegionalFieldOffset = 0x3508 };
#else
enum { kRegionalFieldOffset = 0x3718 };
#endif
#include "GameState/GameState.h"

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void* func_ov017_021b8468(void* obj);
extern "C" ARM void* func_ov017_021b8470(void* obj);
extern "C" ARM int GameState_GetProtagonistIndex(GameState* battleStruct);

struct Struct_ov017_021c7334 {
    char pad0[4];
    unsigned short field4;
    unsigned short field6;
    char pad1[9];
    struct {
        unsigned char bit0 : 1;
        unsigned char unknown_0_1_ : 1;
        unsigned char bit2 : 1;
        unsigned char unknown_0_3_ : 1;
        unsigned char nibble : 4;
    } bits;
    char pad2;
    struct {
        unsigned char pad : 7;
        unsigned char unknown_0_7_ : 1;
    } unknown_13_;
};

struct Struct_ov017_021c7334_2 {
    char pad[0x3a];
    unsigned char unknown_3a_;
    struct {
        unsigned char bit0 : 1;
        unsigned char unknown_0_1_ : 1;
        unsigned char bit2 : 1;
        unsigned char unknown_0_3_ : 1;
        unsigned char nibble : 4;
    } unknown_3b_;
};

// USA: func_ov017_021c7334
extern "C" ARM void func_ov017_021c7334(void* unused0, struct Struct_ov017_021c7334* src, GameState* battleStruct, char* data) {
    void* obj = *(void**)(data + kRegionalFieldOffset);
    void* var1 = func_ov017_021b8478(obj);
    if (!var1) {
        return;
    }
    if (!func_ov017_021b8468(obj)) {
        return;
    }
    if (!func_ov017_021b8470(obj)) {
        return;
    }
    int val = GameState_GetProtagonistIndex(battleStruct);
    if (*(signed char*)((char*)var1 + 0x2a) == val) {
        return;
    }
    if (*(unsigned short*)((char*)var1 + 0x8) != src->field4) {
        return;
    }
    GameObject* combatant = battleStruct->GetCombatantByIndex(src->field6);
    if (!combatant) {
        return;
    }
    ((struct Struct_ov017_021c7334_2*)combatant->currentStats_)->unknown_3b_.bit0 = src->bits.bit0;
    ((struct Struct_ov017_021c7334_2*)combatant->currentStats_)->unknown_3b_.unknown_0_1_ = src->bits.unknown_0_1_;
    ((struct Struct_ov017_021c7334_2*)combatant->currentStats_)->unknown_3b_.bit2 = src->bits.bit2;
    ((struct Struct_ov017_021c7334_2*)combatant->currentStats_)->unknown_3b_.unknown_0_3_ = src->bits.unknown_0_3_;
    ((struct Struct_ov017_021c7334_2*)combatant->currentStats_)->unknown_3b_.nibble = src->bits.nibble;
    ((struct Struct_ov017_021c7334_2*)combatant->currentStats_)->unknown_3a_ = src->unknown_13_.unknown_0_7_ != 0;
}
