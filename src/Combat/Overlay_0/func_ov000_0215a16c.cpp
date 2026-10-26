#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov000_0215a16c
extern "C" ARM short func_ov000_0215a16c(void* unused, int id, int delta, short* arg3) {
    GameObject* c = GameState::GetInstance()->GetCombatantByIndex(id);
    if (c == 0) {
        return 0;
    }
    int cur = c->currentStats_->primaryStats.currHP;
    *arg3 = (short)delta;
    int newVal = cur + delta;
    if (newVal > c->currentStats_->primaryStats.maxHP) {
        int var3 = c->currentStats_->primaryStats.maxHP - c->currentStats_->primaryStats.currHP;
        *arg3 = (short)var3;
        newVal = c->currentStats_->primaryStats.maxHP;
    }
    c->currentStats_->primaryStats.currHP = (unsigned short)newVal;
    return (short)newVal;
}
