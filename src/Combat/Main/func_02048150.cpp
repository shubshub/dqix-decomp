#include <globaldefs.h>
#include "Combat/CombatantRecovery.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
struct ArrayContainsByteStruct;
extern "C" int func_02086ef0(ArrayContainsByteStruct*, int);
extern "C" void Party_ReformLine(GameResources*, int, int, int, int);

// USA: func_02048150
extern "C" ARM void func_02048150(GameObject* object, int hp, int notify) {
    GameState* state = GameState::GetInstance();
    GameResources* resources = GetGameResources();
    ArrayContainsByteStruct* list = (ArrayContainsByteStruct*)GameState_GetParty(state);
    Struct_020200c0* var3 = object->combatFields_.savedState_130_;
    int hadFlag = 0;
    if (var3->flags & 1) hadFlag = 1;
    int maxHP = object->baseStats_->primaryStats.maxHP;
    if (hp > 0) {
        if (hp > maxHP) hp = maxHP;
        var3->hp = hp;
    } else if (var3->hp == 0) var3->hp = maxHP;
    int var6 = 0;
    Struct_020200c0* current = object->combatFields_.savedState_130_;
    if (current->flags & 4) var6 = 1;
    current->flags = 0;
    if (var6) object->combatFields_.savedState_130_->flags |= 4;
    if (hadFlag && func_02086ef0(list, object->obj3D_.actorIndex_) && notify)
        Party_ReformLine(resources, 1, 1, 1, 1);
}
