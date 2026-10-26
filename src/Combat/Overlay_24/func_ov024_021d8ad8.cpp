#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

float CalculatePhysicalDamage(int attack, int defense, struct Random* random);

struct Struct_ov024_021d8ad8 {
    struct Random* unknown_0_;

    struct Random* inline_ov024_021d8ad8() { return unknown_0_; }
};

static inline unsigned short GetAttack(GameObject* obj) {
    return obj->currentStats_->primaryStats.attack;
}

static inline unsigned short inline_ov024_021d8ad8_3(GameObject* obj) {
    return obj->currentStats_->primaryStats.defense;
}

// USA: func_ov024_021d8ad8
extern "C" ARM int func_ov024_021d8ad8(struct Struct_ov024_021d8ad8* ctx, int arg1, int arg2, int c, int d, int arg5) {
    GameState* gameState = GameState::GetInstance();
    GameObject* attacker = gameState->GetCombatantByIndex(arg1);
    GameObject* var2 = gameState->GetCombatantByIndex(arg2);
    if (attacker == NULL || var2 == NULL) {
        return arg5;
    }
    struct Random* var3 = ctx->inline_ov024_021d8ad8();
    unsigned short var4 = inline_ov024_021d8ad8_3(var2);
    unsigned short attack = GetAttack(attacker);
    return (int)CalculatePhysicalDamage((int)(attack * 0.75f), (int)(float)var4, var3);
}
