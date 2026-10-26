#include <globaldefs.h>
#include "GameState/GameState.h"

struct ActionEntry {
    char pad0[0x20];
    short combatantId;
};

struct Struct_ov000_0215ab88_2 {
    char pad0[0xc];
    short combatantId;
};

struct Struct_ov000_0215440c_2 {
    char pad0[0x28];
};

struct Struct_ov000_0215440c;
struct S_10088;

struct Struct_ov000_0215ab88 {
    char pad0[0x138];
    unsigned char* stats;
    char unknown_13c_[0x181 - 0x13c];
    unsigned char unknown_181_;
};

struct Struct_ov000_0215767c_2 {
    char pad0[0x6060];
    Struct_ov000_0215440c_2 actions[1];
    char unknown_6088_[0x8e08 - 0x6088];
    unsigned char unknown_8e08_;
    char unknown_8e09_[0x8e0b - 0x8e09];
    unsigned char unknown_8e0b_;
    char unknown_8e0c_[0x8e24 - 0x8e0c];
    int unknown_8e24_;
};

extern "C" void* memcpy(void* dst, const void* src, unsigned int n);
extern "C" void* func_ov000_0215e9d8(void* work);
extern "C" void func_ov000_02160030(void* obj);
extern "C" ActionEntry* func_ov000_02160094(Struct_ov000_0215440c_2* list, int index);
extern "C" Struct_ov000_0215ab88_2* func_ov000_021600f8(Struct_ov000_0215440c* list, int index);
extern "C" GameObject* func_0200fea4(GameState* battleStruct, int combatantId);
extern "C" int func_02010088(S_10088* obj);
extern "C" int func_ov000_02153c0c(GameObject* combatant);
extern "C" void func_02088e64(unsigned char* obj);

static inline GameObject* inline_ov000_0215ab88(int id) {
    GameState* gs = GameState::GetInstance();
    return func_0200fea4(gs, id);
}

static inline GameObject* inline_ov000_02153aa4(int id) {
    GameState* gs = GameState::GetInstance();
    return gs->GetCombatantByIndex(id);
}

// USA: func_ov000_0215ab88
extern "C" ARM void func_ov000_0215ab88(Struct_ov000_0215767c_2* battle) {
    int i;
    void* work;
    Struct_ov000_0215440c_2* action;
    ActionEntry* entry;
    Struct_ov000_0215ab88_2* target;
    GameObject* c;
    GameObject* t;
    for (i = battle->unknown_8e08_; i < battle->unknown_8e0b_; i++) {
        work = func_ov000_0215e9d8(battle);
        if (work == 0) {
            return;
        }
        func_ov000_02160030(work);
        action = &battle->actions[i];
        entry = func_ov000_02160094(action, 0);
        if (entry == 0) {
            continue;
        }
        target = func_ov000_021600f8((Struct_ov000_0215440c*)action, 0);
        if (target == 0) {
            continue;
        }
        c = inline_ov000_0215ab88(entry->combatantId);
        if (c == 0) {
            continue;
        }
        ((Struct_ov000_0215ab88*)c)->unknown_181_ = 0;
        if (func_02010088((S_10088*)c)) {
            continue;
        }
        if (func_ov000_02153c0c(c)) {
            continue;
        }
        t = inline_ov000_02153aa4(target->combatantId);
        if (t == 0 || func_02010088((S_10088*)t) || func_ov000_02153c0c(t)) {
            func_02088e64(((Struct_ov000_0215ab88*)c)->stats);
            continue;
        }
        memcpy(work, action, sizeof(Struct_ov000_0215440c_2));
        battle->unknown_8e24_++;
    }
    battle->unknown_8e08_ = battle->unknown_8e0b_;
}
