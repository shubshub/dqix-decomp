#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/FieldActorState.h"
#include "Graphics/Vector.h"

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsHostOrSolo(void*);
extern "C" int LinkSession_IsActive(int* obj);

struct SearchStruct0202c1a4;
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);

extern "C" Vector3fix func_02034104(void* combatant);
struct Obj02033834;
extern "C" void GameObject_SetFacing(struct Obj02033834* obj, int arg);
struct Obj02033b68;
extern "C" void GameObject_SetMotionState(struct Obj02033b68* obj, int newVal);
extern "C" int _s32_div_f(int a, int b);
extern "C" void func_ov017_021c927c(int a, int b, int c, Vector3fix v, int d, int e, int f);

// USA: func_02077e80
extern "C" ARM int func_02077e80(FieldMonsterState* self) {
    GameState* battleStruct = GameState::GetInstance();
    GameObject* combatant = battleStruct->GetPartyMemberByIndex(self->combatantId);
    if (combatant == NULL) {
        return 0;
    }

    self->flags |= 0x40;
    int angle = 0;
    void* g = LinkSession_GetInstance();
    if (LinkSession_IsHostOrSolo(g)) {
        Vector3fix var4 = func_02034104(combatant);
        Vector3fix delta;
        Vector3fix_Subtract(&var4, &self->actor.base.object.position_, &delta);
        Vector3fix_Normalize(&delta, &delta);
        delta.x = -delta.x;
        delta.y = -delta.y;
        delta.z = -delta.z;
        angle = fix32_Atan2(delta.x, delta.z);
        GameObject_SetFacing((struct Obj02033834*)self, angle);
        delta.y = 0;
        Vector3fixMultiplyScalar(&delta, 0xa000, &delta);
        Vector3fix_Add(&self->actor.base.object.position_, &delta, &self->targetPosition);
    }

    self->actor.base.fieldB4 = 0x1c2;
    self->actor.base.fieldB2 = 0x1c2;
    GameObject_SetMotionState((struct Obj02033b68*)self, 1);

    GameObject* protagonist = battleStruct->GetProtagonist();
    unsigned short a = protagonist->obj3D_.GetField06();
    unsigned short b = self->actor.base.object.GetField06();
    if (a == b) {
        self->actor.base.object.DisableFlag(0x80);
    }
    self->unknown_17a_ = 0;

    if (LinkSession_IsActive((int*)g)) {
        if (LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)g) == 0) {
            int cid = self->actor.base.object.GetField06();
            int var10 = self->actor.base.object.unknown_2_;
            Vector3fix* var11 = &self->targetPosition;
            int rem = (self->actor.base.object.actorIndex_ - 0x70) % 0xc;
            if (rem >= 0 && rem < 0xc) {
                Vector3fix v = *var11;
                func_ov017_021c927c(cid, rem, var10, v, angle, 6, self->combatantId);
            }
        }
    }
    return 1;
}
