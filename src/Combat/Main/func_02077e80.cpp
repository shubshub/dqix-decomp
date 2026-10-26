#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/FieldActorState.h"
#include "Graphics/Vector.h"

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsHostOrSolo(void*);
int LinkSession_IsActive(int* obj);

struct SearchStruct0202c1a4;
signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);

extern "C" Vector3fix func_02034104(void* combatant);
struct Obj02033834;
void GameObject_SetFacing(struct Obj02033834* obj, int arg);
struct Obj02033b68;
void GameObject_SetMotionState(struct Obj02033b68* obj, int newVal);
extern "C" int _s32_div_f(int a, int b);
extern "C" void func_ov017_021c927c(int arg0, int arg1, int arg2, Vector3fix arg3, int arg4, int arg5, int arg6);

// USA: func_02077e80
extern "C" ARM int func_02077e80(Struct_02076a8c* arg0) {
    GameState* var0 = GameState::GetInstance();
    GameObject* var1 = var0->GetPartyMemberByIndex(arg0->unknown_166_);
    if (var1 == NULL) {
        return 0;
    }

    self->flags |= 0x40;
    int angle = 0;
    void* g = LinkSession_GetInstance();
    if (LinkSession_IsHostOrSolo(g)) {
        Vector3fix posCopy = func_02034104(combatant);
        Vector3fix delta;
        Vector3fix_Subtract(&posCopy, &self->actor.base.object.position_, &delta);
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

    GameObject* var6 = var0->GetProtagonist();
    unsigned short var7 = var6->obj3D_.GetField06();
    unsigned short var8 = arg0->unknown_0_.unknown_0_.unknown_0_.GetField06();
    if (var7 == var8) {
        arg0->unknown_0_.unknown_0_.unknown_0_.DisableFlag(0x80);
    }
    arg0->unknown_17a_ = 0;

    if (LinkSession_IsActive((int*)g)) {
        if (LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)g) == 0) {
            int cid = self->actor.base.object.GetField06();
            int f2val = self->actor.base.object.unknown_2_;
            Vector3fix* vp = &self->targetPosition;
            int rem = (self->actor.base.object.actorIndex_ - 0x70) % 0xc;
            if (rem >= 0 && rem < 0xc) {
                Vector3fix v = *vp;
                func_ov017_021c927c(cid, rem, f2val, v, angle, 6, self->combatantId);
            }
        }
    }
    return 1;
}
