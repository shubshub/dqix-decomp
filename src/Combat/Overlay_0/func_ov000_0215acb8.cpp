#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct S_10088;
extern "C" int func_02010088(struct S_10088* obj);
extern "C" int func_ov000_02153c0c(GameObject* combatant);

struct Struct_ov000_0215acb8 {
    unsigned short action;
    char pad2[0x28 - 0x2];
};

struct Struct_ov000_0215acb8_2 {
    char pad0[0x1c];
    short field1c;
    short pad1e;
    unsigned short combatantId;
    unsigned short unknown_22_;
    unsigned short unknown_24_;
    char unknown_26_[0x30 - 0x26];
    int unknown_30_;
};

struct Struct_ov000_0215acb8_3 {
    char pad0[0xe];
    short combatantId;
    char pad10[0x17 - 0x10];
    unsigned char active;
    char pad18[0x24 - 0x18];
};

struct Struct_ov000_021584e8 {
    char pad0[0x20];
    int field20;
};

struct Struct_ov000_0215acb8_4 {
    char pad0[0x7770];
    struct Struct_ov000_0215acb8 actions[0x10];
    struct Struct_ov000_0215acb8_2 entries[0x10];
    struct Struct_ov000_0215acb8_3 targets[0x10];
    struct Struct_ov000_021584e8 outs[0x10];
    char unknown_81b0_[0x8e0f - 0x81b0];
    unsigned char unknown_8e0f_;
};

extern "C" void func_ov000_02160030(void* obj);
extern "C" void func_ov000_02157cdc(void* obj);
extern "C" void func_ov000_0215ccbc(int unused, struct Struct_ov000_021584e8* out, GameObject* combatant,
                            short arg3, short valA, short valB, unsigned long long words, unsigned char arg7);
extern "C" void func_ov000_0215a88c(void* objRaw, void* arg1, int c);
extern "C" void func_ov000_0215ffc4(void* obj, void* node, int idx);

struct Struct_ov000_0215767c_7;
struct Struct_ov000_0215767c_6;
extern "C" void func_ov000_02160068(struct Struct_ov000_0215767c_7* obj, struct Struct_ov000_0215767c_6* arg1);
struct Struct_ov000_0215767c_5;
struct Struct_ov000_0215767c_4;
extern "C" void func_ov000_021600cc(struct Struct_ov000_0215767c_5* obj, struct Struct_ov000_0215767c_4* arg1);

// USA: func_ov000_0215acb8
extern "C" ARM void func_ov000_0215acb8(struct Struct_ov000_0215acb8_4* battle, int combatantId, short amount, short valB) {
    if (battle->unknown_8e0f_ >= 0x10) {
        return;
    }
    GameObject* c = GameState::GetInstance()->GetCombatantByIndex(combatantId);
    if (c == NULL) {
        return;
    }
    if (func_02010088((struct S_10088*)c)) {
        return;
    }
    if (func_ov000_02153c0c(c)) {
        return;
    }
    struct Struct_ov000_0215acb8* action = &battle->actions[battle->unknown_8e0f_];
    func_ov000_02160030(action);
    struct Struct_ov000_0215acb8_2* entry = &battle->entries[battle->unknown_8e0f_];
    memset(entry, 0, 0x30);
    entry->field1c = -1;
    entry->unknown_30_ = 0;
    struct Struct_ov000_0215acb8_3* target = &battle->targets[battle->unknown_8e0f_];
    func_ov000_02157cdc(target);
    struct Struct_ov000_021584e8* out = &battle->outs[battle->unknown_8e0f_];
    memset(out, 0, 0x20);
    out->field20 = 0;
    action->action = 0x3af;
    entry->combatantId = combatantId;
    entry->unknown_22_ = c->currentStats_->primaryStats.currHP;
    entry->unknown_24_ = c->currentStats_->primaryStats.currMP;
    func_ov000_0215ccbc((int)battle, out, c, -amount, c->currentStats_->primaryStats.currHP, valB, 0x800000000ULL, 0);
    func_ov000_0215a88c(battle, out, 0x243);
    target->combatantId = combatantId;
    target->active = 1;
    func_ov000_0215ffc4(target, out, 0);
    func_ov000_02160068((struct Struct_ov000_0215767c_7*)action, (struct Struct_ov000_0215767c_6*)entry);
    func_ov000_021600cc((struct Struct_ov000_0215767c_5*)action, (struct Struct_ov000_0215767c_4*)target);
    battle->unknown_8e0f_++;
}
