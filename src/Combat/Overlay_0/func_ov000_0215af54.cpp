#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct S_10088;
struct Struct_ov000_021584e8;

struct Struct_ov000_0215af54 {
    unsigned short unknown_0_;
    char pad2[0xb - 0x2];
    unsigned char flags;
    char unknown_c_[0x28 - 0xc];
};

struct Struct_ov000_0215af54_2 {
    char pad0[0x1c];
    short unknown_1c_;
    char unknown_1e_[0x20 - 0x1e];
    short combatantId;
    unsigned short hp;
    unsigned short mp;
    char unknown_26_[0x30 - 0x26];
    int unknown_30_;
};

struct Struct_ov000_0215af54_3 {
    char pad0[0xe];
    short combatantId;
    char pad10[0x17 - 0x10];
    unsigned char unknown_17_;
    char pad18[0x24 - 0x18];
};

struct Struct_ov000_0215af54_4 {
    char pad0[0x20];
    int field20;
};

struct Struct_ov000_0215af54_5 {
    char pad0[0x6d30];
    struct Struct_ov000_0215af54 actions[16];
    struct Struct_ov000_0215af54_2 actors[16];
    struct Struct_ov000_0215af54_3 targets[16];
    struct Struct_ov000_0215af54_4 effects[16];
    char unknown_7770_[0x8e10 - 0x7770];
    unsigned char unknown_8e10_;
    unsigned char unknown_8e11_;
    unsigned char unknown_8e12_;
    unsigned char unknown_8e13_;
};

extern "C" int func_02010088(struct S_10088* obj);
extern "C" int func_ov000_02153c0c(GameObject* combatant);
extern "C" void func_ov000_02160030(void* obj);
extern "C" void func_ov000_02157cdc(void* obj);
extern "C" void func_ov000_0215a88c(void* objRaw, void* arg1, int c);
extern "C" void func_ov000_0215ccbc(int unused, struct Struct_ov000_021584e8* out, GameObject* combatant,
                            short arg3, short valA, short valB, unsigned long long words, unsigned char arg7);
extern "C" void func_ov000_0215ffc4(void* obj, void* node, int idx);
struct Struct_ov000_0215767c_7;
struct Struct_ov000_0215767c_6;
struct Struct_ov000_0215767c_5;
struct Struct_ov000_0215767c_4;
extern "C" void func_ov000_02160068(struct Struct_ov000_0215767c_7* obj, struct Struct_ov000_0215767c_6* arg1);
extern "C" void func_ov000_021600cc(struct Struct_ov000_0215767c_5* obj, struct Struct_ov000_0215767c_4* arg1);

static inline int inline_ov000_02156cc4_2(int index) {
    return index >= 0 && index <= 3;
}

static inline short inline_ov000_021584e8(GameObject* c) { SDK_NULL_ASSERT(c); return c->currentStats_->primaryStats.currHP; }
static inline short inline_ov000_021584e8_2(GameObject* c) { SDK_NULL_ASSERT(c); return c->currentStats_->primaryStats.currMP; }

// USA: func_ov000_0215af54
extern "C" ARM void func_ov000_0215af54(struct Struct_ov000_0215af54_5* battle, int index, int mode) {
    struct Struct_ov000_0215af54* action;
    struct Struct_ov000_0215af54_2* actor;
    struct Struct_ov000_0215af54_3* target;
    struct Struct_ov000_0215af54_4* effect;
    if (battle->unknown_8e10_ >= 16 || battle->unknown_8e11_ >= 16 || battle->unknown_8e12_ >= 16 || battle->unknown_8e13_ >= 16) {
        return;
    }
    GameObject* c = GameState::GetInstance()->GetCombatantByIndex(index);
    if (c == NULL) {
        return;
    }
    if (func_02010088((struct S_10088*)c)) {
        return;
    }
    if (func_ov000_02153c0c(c)) {
        return;
    }

    action = &battle->actions[battle->unknown_8e10_];
    func_ov000_02160030(action);
    actor = &battle->actors[battle->unknown_8e11_];
    memset(actor, 0, 0x30);
    actor->unknown_1c_ = -1;
    actor->unknown_30_ = 0;
    target = &battle->targets[battle->unknown_8e12_];
    func_ov000_02157cdc(target);
    effect = &battle->effects[battle->unknown_8e13_];
    memset(effect, 0, 0x20);
    effect->field20 = 0;

    if (mode == 0) {
        if (inline_ov000_02156cc4_2(index)) {
            action->unknown_0_ = 0x39c;
        } else {
            action->unknown_0_ = 0x39d;
        }
        func_ov000_0215a88c(battle, effect, 0x35);
    } else {
        action->unknown_0_ = 0x39a;
        func_ov000_0215a88c(battle, effect, 0x213);
    }
    action->flags |= 4;

    actor->combatantId = index;
    actor->hp = c->currentStats_->primaryStats.currHP;
    actor->mp = c->currentStats_->primaryStats.currMP;
    func_ov000_0215ccbc((int)battle, (struct Struct_ov000_021584e8*)effect, c, 0, inline_ov000_021584e8(c), inline_ov000_021584e8_2(c), 0, 0);
    target->combatantId = index;
    target->unknown_17_ = 1;
    func_ov000_0215ffc4(target, effect, 0);
    func_ov000_02160068((struct Struct_ov000_0215767c_7*)action, (struct Struct_ov000_0215767c_6*)actor);
    func_ov000_021600cc((struct Struct_ov000_0215767c_5*)action, (struct Struct_ov000_0215767c_4*)target);

    battle->unknown_8e10_++;
    battle->unknown_8e11_++;
    battle->unknown_8e12_++;
    battle->unknown_8e13_++;
}
