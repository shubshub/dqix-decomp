#include <globaldefs.h>
#include "GameState/GameState.h"

struct ActionEntry {
    char pad0[0x20];
    short combatantId;
};

struct Struct_ov000_0215440c_2 {
    char pad0[8];
    unsigned char unknown_8_;
    unsigned char unknown_9_;
    char unknown_a_;
    unsigned char flags;
    char unknown_c_[0x28 - 0xc];
};

struct Struct_ov000_0215440c;
struct S_10088;

struct Struct_ov000_0215767c_2 {
    char pad0[0x6d30];
    Struct_ov000_0215440c_2 actions[1];
    char unknown_6d58_[0x8e09 - 0x6d58];
    unsigned char unknown_8e09_;
    char unknown_8e0a_[0x8e10 - 0x8e0a];
    unsigned char unknown_8e10_;
    char unknown_8e11_[0x8e24 - 0x8e11];
    int unknown_8e24_;
};

extern "C" void* memcpy(void* dst, const void* src, unsigned int n);
extern "C" void* func_ov000_0215e9d8(void* work);
extern "C" void func_ov000_02160030(void* obj);
extern "C" ActionEntry* func_ov000_02160094(Struct_ov000_0215440c_2* list, int index);
extern "C" void* func_ov000_021600f8(Struct_ov000_0215440c* list, int index);
extern "C" int func_02010088(S_10088* obj);
extern "C" int func_ov000_02153c0c(GameObject* combatant);

// USA: func_ov000_0215b198
extern "C" ARM void func_ov000_0215b198(Struct_ov000_0215767c_2* battle) {
    int i;
    for (i = battle->unknown_8e09_; i < battle->unknown_8e10_; i++) {
        void* work = func_ov000_0215e9d8(battle);
        if (work == 0) {
            return;
        }
        func_ov000_02160030(work);
        Struct_ov000_0215440c_2* action = &battle->actions[i];
        ActionEntry* entry = func_ov000_02160094(action, 0);
        if (entry == 0) {
            continue;
        }
        if (func_ov000_021600f8((Struct_ov000_0215440c*)action, 0) == 0) {
            continue;
        }
        int id = entry->combatantId;
        GameState* gs = GameState::GetInstance();
        GameObject* c = gs->GetCombatantByIndex(id);
        if (c == 0) {
            continue;
        }
        action->flags |= 4;
        if (func_02010088((S_10088*)c)) {
            continue;
        }
        if (func_ov000_02153c0c(c)) {
            continue;
        }
        memcpy(work, action, sizeof(Struct_ov000_0215440c_2));
        battle->unknown_8e24_++;
    }
    battle->unknown_8e09_ = battle->unknown_8e10_;
}
