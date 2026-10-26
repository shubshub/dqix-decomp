#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct0203cedc {
    char pad0[0xc];
    int fieldC;
    char pad1[0x5c - 0x10];
    int flags5c;
    char pad2[0x98 - 0x60];
    int field98;
};

// USA: func_0203cedc
ARM void SetCombatFlags0x5c(struct Struct0203cedc* obj, int b, int c) {
    GameState* battleStruct;
    GameObject* combatant;

    battleStruct = GameState::GetInstance();
    combatant = battleStruct->GetLeader();

    if (combatant->obj3D_.position_.z >= obj->fieldC) {
        return;
    }

    obj->field98 = combatant->obj3D_.position_.x;
    obj->flags5c &= ~0x20;
    obj->flags5c &= ~0x10;

    if (b != 0) {
        if (c == 0) {
            obj->flags5c |= 0x10;
            return;
        }
    }

    if ((b & c) != 0) {
        obj->flags5c |= 0x20;
    }
}
