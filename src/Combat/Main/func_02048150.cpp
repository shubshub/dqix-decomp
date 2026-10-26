#include <globaldefs.h>
#include "Combat/CombatantRecovery.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
struct ArrayContainsByteStruct;
int ArrayContainsByte_02086ef0(ArrayContainsByteStruct*, int);
extern "C" void Party_ReformLine(GameResources*, int, int, int, int);

// USA: func_02048150
extern "C" ARM void func_02048150(GameObject* object, int hp, int notify) {
    GameState* state = GameState::GetInstance();
    GameResources* resources = GetGameResources();
    ArrayContainsByteStruct* list = (ArrayContainsByteStruct*)GameState_GetParty(state);
    CombatantStatus* runtime = object->combatFields_.savedState_130_;
    int hadFlag = 0;
    if (runtime->flags & 1) hadFlag = 1;
    int maxHP = object->baseStats_->primaryStats.maxHP;
    if (hp > 0) {
        if (hp > maxHP) hp = maxHP;
        runtime->hp = hp;
    } else if (runtime->hp == 0) runtime->hp = maxHP;
    int keepFlag = 0;
    CombatantStatus* current = object->combatFields_.savedState_130_;
    if (current->flags & 4) keepFlag = 1;
    current->flags = 0;
    if (keepFlag) object->combatFields_.savedState_130_->flags |= 4;
    if (hadFlag && ArrayContainsByte_02086ef0(list, object->obj3D_.actorIndex_) && notify)
        Party_ReformLine(resources, 1, 1, 1, 1);
}
