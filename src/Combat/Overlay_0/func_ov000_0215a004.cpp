#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_02088e80;
struct Struct_020a0608;
struct Struct_020a0294;

struct Struct_02000c9c_31 {
    char unknown_0_[0x48];
};

struct Struct_ov000_0215a004 {
    char unknown_0_[0x68];
    struct Struct_02000c9c_31 unknown_68_;
};

extern "C" void func_ov000_021554f4(void* self, int id, void* arg, int a3, unsigned char a4, int a5);
extern "C" void func_ov000_02155184(void* self, int id, int a2);
void InitObj02088e80(Obj02088e80*, int);
int GameState_GetProtagonistIndex(GameState* gs);
void LoadBattleBlock020ac4c0(void*);
void AddClamped16BitLowAt0x24_020a0608(S_a0608*, unsigned int);
void AddClamped16BitFieldMidAt0x1c_020a0294(S_a0294*, unsigned int);
void CopyInBattleField0x7540_020ac494(void*);

// USA: func_ov000_0215a004
extern "C" ARM short func_ov000_0215a004(void* arg0, void* arg1, int arg2, int arg3, unsigned long long* arg4,
                                          int arg5, unsigned char arg6, int arg7) {
    int var0;
    GameObject* var1 = GameState::GetInstance()->GetCombatantByIndex(arg2);
    if (var1 == 0) {
        return 0;
    }
    hp = c->currentStats_->primaryStats.currHP - damage;
    if (hp <= 0) {
        hp = 0;
        *result = 0;
        *result |= 4;
        func_ov000_021554f4(self, id, arg, a5, a6, a7);
        InitObj02088e80((Obj02088e80*)c->currentStats_, (signed char)c->obj3D_.actorIndex_);
        func_ov000_02155184(self, id, a7);
        if (id == GameState_GetProtagonistIndex(GameState::GetInstance())) {
            struct BattleBlk_0215a004 blk;
            LoadBattleBlock020ac4c0(&blk);
            AddClamped16BitLowAt0x24_020a0608((S_a0608*)&blk, 1);
            AddClamped16BitFieldMidAt0x1c_020a0294((S_a0294*)&blk.sub, 1);
            CopyInBattleField0x7540_020ac494(&blk);
        }
    }
    if (arg3 > 0) {
        *arg4 |= 2;
    }
    var1->currentStats_->primaryStats.currHP = var0;
    return (short)var0;
}
