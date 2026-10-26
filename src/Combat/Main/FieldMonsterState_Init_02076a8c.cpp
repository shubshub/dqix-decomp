#include <globaldefs.h>

#include "Combat/FieldActorState.h"

// Main, originally func_02076a8c (USA 0x02076a8c, EUR 0x02076a9c, JPN 0x020779a8)
extern "C" ARM void FieldMonsterState_Init(FieldMonsterState* p) {
    GameObject_Initialize(&p->actor.base);

    p->actor.base.object.unknown_0_ |= 0x20;
    p->actor.base.fieldB4 = 0x1c2;
    p->actor.phase = 1;
    p->actor.unknown_134_ = 1;
    p->actor.unknown_138_ = 1;
    p->actor.unknown_139_ = 2;
    p->actor.unknown_13a_ = 1;
    p->actor.unknown_13b_ = 3;
    p->actor.unknown_13c_ = 1;
    p->actor.unknown_140_ = 0x1e;
    p->actor.unknown_144_ = 5;
    p->actor.unknown_148_ = 0x1000;
    p->actor.unknown_14c_ = 0;
    p->actor.unknown_150_ = 0;
    p->actor.unknown_154_ = 0;
    p->unknown_164_ = 0;
    p->combatantId = 0;
    p->unknown_168_ = 0;
    p->flags = 0;
    p->height = 0;
    p->unknown_174_ = 0;
    p->unknown_176_ = 0;
    p->unknown_17a_ = 0;
    p->unknown_17b_ = 0;
    p->unknown_17c_ = 0;
    p->unknown_180_ = 0;
    p->attributes = 0;
    p->unknown_16a_ = 0;
    p->unknown_17e_ = 0;
    p->targetPosition.x = 0;
    p->targetPosition.y = 0;
    p->targetPosition.z = 0;

    p->actor.base.object.DisableFlag(0x80);
}
