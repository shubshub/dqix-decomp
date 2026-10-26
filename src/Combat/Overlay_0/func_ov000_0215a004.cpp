#include <globaldefs.h>
#include "GameState/GameState.h"

struct Obj02088e80;
struct Struct_020a0608;
struct Struct_020a0294;

struct Struct_02000c9c_31 {
    char data[0x48];
};

struct Struct_ov000_0215a004 {
    char data[0x68];
    struct Struct_02000c9c_31 sub;
};

extern "C" void func_ov000_021554f4(void* self, int id, void* arg, int a3, unsigned char a4, int a5);
extern "C" void func_ov000_02155184(void* self, int id, int a2);
extern "C" void func_02088e80(Obj02088e80*, int);
extern "C" int GameState_GetProtagonistIndex(GameState* gs);
extern "C" void func_020ac4c0(void*);
extern "C" void func_020a0608(Struct_020a0608*, unsigned int);
extern "C" void func_020a0294(Struct_020a0294*, unsigned int);
extern "C" void func_020ac494(void*);

// USA: func_ov000_0215a004
extern "C" ARM short func_ov000_0215a004(void* self, void* arg, int id, int arg3, unsigned long long* result,
                                          int a5, unsigned char a6, int a7) {
    int hp;
    GameObject* c = GameState::GetInstance()->GetCombatantByIndex(id);
    if (c == 0) {
        return 0;
    }
    hp = c->currentStats_->primaryStats.currHP - arg3;
    if (hp <= 0) {
        hp = 0;
        *result = 0;
        *result |= 4;
        func_ov000_021554f4(self, id, arg, a5, a6, a7);
        func_02088e80((Obj02088e80*)c->currentStats_, (signed char)c->obj3D_.actorIndex_);
        func_ov000_02155184(self, id, a7);
        if (id == GameState_GetProtagonistIndex(GameState::GetInstance())) {
            struct Struct_ov000_0215a004 blk;
            func_020ac4c0(&blk);
            func_020a0608((Struct_020a0608*)&blk, 1);
            func_020a0294((Struct_020a0294*)&blk.sub, 1);
            func_020ac494(&blk);
        }
    }
    if (arg3 > 0) {
        *result |= 2;
    }
    c->currentStats_->primaryStats.currHP = hp;
    return (short)hp;
}
