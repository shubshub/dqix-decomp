#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_0203ca24 {
    char pad0[0xc];
    int fieldC;
    char pad1[0x5c - 0x10];
    int unknown_5c_;
    char pad2[0x98 - 0x60];
    int field98;
};

// USA: func_0203cedc
extern "C" ARM void func_0203cedc(struct Struct_0203ca24* obj, int b, int c) {
    GameState* battleStruct;
    GameObject* combatant;

    battleStruct = GameState::GetInstance();
    combatant = battleStruct->GetLeader();

    if (combatant->obj3D_.position_.z >= obj->fieldC) {
        return;
    }

    obj->field98 = combatant->obj3D_.position_.x;
    obj->unknown_5c_ &= ~0x20;
    obj->unknown_5c_ &= ~0x10;

    if (b != 0) {
        if (c == 0) {
            obj->unknown_5c_ |= 0x10;
            return;
        }
    }

    if ((b & c) != 0) {
        obj->unknown_5c_ |= 0x20;
    }
}
