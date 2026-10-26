#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

struct Struct_02000c9c_30 {
#if defined(jpn)
    char pad0[0x144];
#else
    char pad0[0x150];
#endif
    unsigned char* status;
};

struct Struct_ov000_02156e30 {
    char pad0[0x2cc];
    short hp;
};

struct Struct_ov000_02156e30_2 {
    char pad0[4];
    unsigned int id : 12;
    unsigned int rest : 20;
    char pad1[0x10 - 8];
    unsigned int flags;
};

extern "C" Struct_ov000_02156e30* func_02053c6c(unsigned char* obj);
extern "C" int func_02085154(unsigned char* obj);
extern "C" int func_02083b00(unsigned char* obj, int index);
extern "C" int func_ov000_02155f9c(struct Random* arg0, int combatantId, int arg2);
extern "C" float func_ov000_02156118(struct Random* arg0, int combatantId);

static inline unsigned char* inline_ov000_02156cc4(GameObject* c) {
    return ((Struct_02000c9c_30*)c)->status;
}

static inline int inline_ov000_02156cc4_2(int id) {
    return id >= 0 && id <= 3;
}

// USA: func_ov000_02156e30
extern "C" ARM int func_ov000_02156e30(struct Random* arg0, int arg1, int targetId, Struct_ov000_02156e30_2* action) {
    GameState* bs = GameState::GetInstance();
    if (!(action->flags & 0x40)) {
        return 0;
    }
    if (func_ov000_02155f9c(arg0, targetId, 0) != 0) {
        return 0;
    }
    if (inline_ov000_02156cc4_2(arg1)) {
        GameObject* attacker = func_0200ff1c(bs, arg1);
        if (attacker != NULL && (action->flags & 0x80000)) {
            if (func_02085154(inline_ov000_02156cc4(attacker))) {
                return 0;
            }
        }
    }
    if (GameState::GetInstance()->GetCombatantByIndex(targetId) == NULL) {
        return 0;
    }
    float var2 = func_ov000_02156118(arg0, targetId);
    if (inline_ov000_02156cc4_2(targetId) && (action->id == 0xf4 || action->id == 0xf5)) {
        GameObject* target = func_0200ff1c(GameState::GetInstance(), targetId);
        Struct_ov000_02156e30* var4 = func_02053c6c((unsigned char*)target);
        if (target != NULL && var4 != NULL && var4->hp > 0) {
            if (func_02083b00(inline_ov000_02156cc4(target), 0x28)) {
                var2 = 100.0f;
            }
        }
    }
    return NextRandomMax(arg0, 100) < var2;
}
