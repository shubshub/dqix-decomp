#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

struct S_10088;
extern "C" int func_02010088(struct S_10088* obj);
extern "C" GameObject* func_0200fea4(GameState* gameState, int combatantId);

struct Struct_ov000_02154f30 {
    char pad0[0x3c];
    unsigned int unknown_3c_0_ : 30;
    unsigned int flag30 : 1;
    unsigned int unknown_3f_7_ : 1;
};

struct Struct_ov000_02154f30_2 {
    char pad0[0x2e];
    short targetId;
    char unknown_30_[0x32 - 0x30];
    short unknown_32_;
    short unknown_34_;
};

struct Struct_ov000_02154f30_3 {
    char pad0[0x10];
    unsigned int unknown_10_0_ : 26;
    unsigned int weighted : 1;
    unsigned int unknown_13_3_ : 5;
};

struct Struct_ov000_02154f30_4 {
    char pad0[0x134];
    struct Struct_ov000_02154f30* baseStats;
    struct Struct_ov000_02154f30_2* stats;
    char unknown_13c_[0x148 - 0x13c];
    struct Struct_ov000_02154f30_3* unknown_148_;
};

struct Struct_ov000_02182ca4 {
    int v[4];
};

struct Struct_ov000_02182c94 {
    short v[8];
};

extern "C" int func_ov000_02155154(GameObject* combatant);
extern "C" int func_ov000_02153c0c(GameObject* combatant);
extern "C" int func_ov000_0215516c(GameObject* combatant);

extern struct Struct_ov000_02182ca4 data_ov000_02182ca4;
extern struct Struct_ov000_02182c94 data_ov000_02182c94;

// USA: func_ov000_02154f30
extern "C" ARM short func_ov000_02154f30(struct Random* rng, int id, int count, short* ids) {
    struct Struct_ov000_02154f30_4* self = (struct Struct_ov000_02154f30_4*)func_0200fea4(GameState::GetInstance(), id);
    struct Struct_ov000_02154f30_3* var1 = self->unknown_148_;
    struct Struct_ov000_02182ca4 weights = data_ov000_02182ca4;
    int total = 0;
    if (func_ov000_02155154((GameObject*)self)) {
        short targetId = self->stats->targetId;
        GameState* gs = GameState::GetInstance();
        GameObject* target = gs->GetCombatantByIndex(targetId);
        if (target != NULL && !func_02010088((struct S_10088*)target) && !func_ov000_02153c0c(target)) {
            return self->stats->targetId;
        }
    }
    struct Struct_ov000_02182c94 list = data_ov000_02182c94;
    unsigned char n = 0;
    for (int i = 0; i < count; i++) {
        short cid = ids[i];
        GameState* gs = GameState::GetInstance();
        GameObject* c = gs->GetCombatantByIndex(cid);
        if (c == NULL || func_02010088((struct S_10088*)c) || func_ov000_02153c0c(c)) {
            continue;
        }
        weights.v[n] = (unsigned short)((struct Struct_ov000_02154f30_4*)c)->baseStats->flag30 == 0 ? 2 : 1;
        if (var1->weighted == 1) {
            struct Struct_ov000_02154f30_2* stats = self->stats;
            short cur = ids[i];
            if (cur == stats->unknown_32_) {
                weights.v[n] += 2;
            }
            if (cur == stats->unknown_34_) {
                weights.v[n] += 1;
            }
        }
        total += weights.v[n];
        list.v[n] = ids[i];
        if (func_ov000_0215516c(c)) {
            weights.v[n] >>= 1;
        }
        n++;
    }
    if (n == 0) {
        return -1;
    }
    int r = NextRandomMax(rng, total) + 1;
    for (int j = 0; j < n; j++) {
        if (weights.v[j] >= r) {
            return list.v[j];
        }
        r -= weights.v[j];
    }
    return list.v[NextRandomMax(rng, n)];
}
