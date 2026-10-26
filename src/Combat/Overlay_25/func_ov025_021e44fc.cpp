#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov000_02160094 {
    char pad0[0x20];
    unsigned short combatantId;
    char unknown_22_[2];
    unsigned short value;
};
struct Struct_ov000_0215440c_2;

struct Obj02176150 {
    char pad0[0xe];
    short val;
};

struct Struct_ov025_021e44fc {
    struct Obj02176150 gauge;
    char pad10[0x4c - 0x10];
    int combatantId;
#if defined(jpn)
    char unknown_50_[0x488 - 0x50];
#else
    char unknown1_50_[0x448 - 0x50];
#endif
};

struct Struct_ov025_021e44fc_2 {
    char pad0[0x958];
    struct Struct_ov025_021e44fc slots[4];
};

struct Struct_ov025_021e44fc_3 {
    char pad0[6];
    unsigned short value;
};

struct Struct_ov025_021e44fc_4 {
    char pad0[0x130];
    struct Struct_ov025_021e44fc_3* stats;
};

extern "C" struct Struct_ov000_02160094* func_ov000_02160094(struct Struct_ov000_0215440c_2* list, int index);
extern "C" void* func_ov000_02160130(void);
extern "C" void* func_ov000_02160f08(void* obj);
extern "C" void func_ov000_02176150(struct Obj02176150* obj, unsigned short val);

static inline int inline_ov000_02156cc4_2(int id) {
    return id >= 0 && id <= 3;
}

// USA: func_ov025_021e44fc
extern "C" ARM int func_ov025_021e44fc(void* unused, struct Struct_ov000_0215440c_2* list) {
    struct Struct_ov000_02160094* node = func_ov000_02160094(list, 0);
    GameState* gs = GameState::GetInstance();
    struct Struct_ov025_021e44fc_2* work = (struct Struct_ov025_021e44fc_2*)func_ov000_02160f08(func_ov000_02160130());
    struct Struct_ov025_021e44fc* slot;
    if (inline_ov000_02156cc4_2(node->combatantId)) {
        for (int i = 0; i < 4; i++) {
            if (node->combatantId == work->slots[i].combatantId) {
                slot = &work->slots[i];
                goto found;
            }
        }
    }
    slot = 0;
found:
    struct Struct_ov025_021e44fc_4* c = (struct Struct_ov025_021e44fc_4*)gs->GetCombatantByIndex(node->combatantId);
    if (slot != 0) {
        unsigned short value = node->value;
        func_ov000_02176150(&slot->gauge, value);
        slot->gauge.val = value;
    }
    if (c != 0) {
        c->stats->value = node->value;
    }
    return 1;
}
