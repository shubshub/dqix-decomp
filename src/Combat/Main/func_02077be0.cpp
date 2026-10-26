#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/FieldActorState.h"
#include "Graphics/Vector.h"

struct Struct_02077788_2;
extern "C" int func_02077a20(struct Struct_02077788_2* p);

struct SearchStruct0202c1a4;
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);

struct BitFlag02033f44;
extern "C" int* GameObject_GetWallHit(struct BitFlag02033f44* self);

extern "C" void func_02076ccc(void* self, int mode);
extern "C" void func_020794f8(void* self, int a, int b);

extern "C" int LinkSession_IsActive(int* obj);

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsHostOrSolo(void* obj);
extern "C" int func_020322c0(void* p, int* v);
extern "C" Vector3fix func_02034104(void* combatant);

struct Obj02033834;
extern "C" void GameObject_SetFacing(struct Obj02033834* obj, int arg);

struct Obj02033b68;
extern "C" void GameObject_SetMotionState(struct Obj02033b68* obj, int newVal);

// USA: func_02077be0
extern "C" ARM void func_02077be0(FieldMonsterState* self) {
    GameState* battleStruct = GameState::GetInstance();
    void* mgr = LinkSession_GetInstance();
    GameObject* combatant = battleStruct->GetPartyMemberByIndex(self->combatantId);
    if (combatant == NULL) {
        return;
    }

    Vector3fix var3 = self->actor.base.object.position_;
    var3.y = 0;
    int flag = 0;
    Vector3fix var5 = self->targetPosition;
    var5.y = 0;
    Vector3fix delta;
    Vector3fix_Subtract(&var5, &var3, &delta);
    Vector3fix_Normalize(&delta, &delta);
    int angle = fix32_Atan2(delta.x, delta.z);
    GameObject_SetFacing((struct Obj02033834*)self, angle);
    self->actor.base.fieldB4 = 0x1c2;
    self->actor.base.fieldB2 = 0x1c2;
    GameObject_SetMotionState((struct Obj02033b68*)self, 1);

    int* p = GameObject_GetWallHit((struct BitFlag02033f44*)self);
    if (p != NULL) {
        int v = (short)self->actor.base.fieldAe;
        if (func_020322c0(p, &v) < 0x199) {
            flag = 1;
        }
    }

    if (flag != 0) {
        func_02076ccc(self, 1);
        self->actor.unknown_154_ = 0;
        if (LinkSession_IsActive((int*)mgr) == 0) {
            return;
        }
        func_020794f8(self, 0, 0);
        return;
    }

    int dist = Vector3fix_Distance(&var3, &var5);
    unsigned short id = self->combatantId;
    if (combatant->obj3D_.unknown_0_ & 0x1000) {
        id = 0;
    }

    if (LinkSession_IsActive((int*)mgr) == 0 ||
        id == LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)mgr)) {
        Vector3fix var12 = func_02034104(combatant);
        int radius = combatant->obj3D_.GetRadius();
        int var14 = self->actor.base.object.GetScale().x * 15;
        int half = func_02077a20((struct Struct_02077788_2*)self) >> 1;
        int threshold = (int)(((long long)half * var14 + 0x800) >> 12) + (radius >> 1);
        int d = Vector3fix_Distance(&var12, &self->actor.base.object.position_);
        if (d != 0 && threshold > d) {
            func_02076ccc(self, 1);
            self->actor.unknown_154_ = 0;
            self->unknown_17b_ = 1;
            if (LinkSession_IsActive((int*)mgr) != 0) {
                func_020794f8(self, 1, 0);
            }
            return;
        }
    }

    if (LinkSession_IsActive((int*)mgr) != 0 &&
        LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)mgr) != 0) {
        return;
    }
    if (dist >= 0x1800 && self->unknown_17b_ == 0) {
        return;
    }
    func_02076ccc(self, 1);
    self->actor.unknown_154_ = 0;
    if (LinkSession_IsActive((int*)mgr) == 0) {
        return;
    }
    if (LinkSession_IsHostOrSolo(mgr) == 0) {
        return;
    }
    func_020794f8(self, 0, 0);
}
