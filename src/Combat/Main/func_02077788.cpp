#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
#define func_020341e0 func_02034104
#endif

struct Struct_02077788 {
    Object3D object;
    char unknown_ac_[2];
    short unknown_ae_;
    char unknown_b0_[0xb2 - 0xb0];
    unsigned short unknown_b2_;
    unsigned short unknown_b4_;
    char unknown_b6_[0x154 - 0xb6];
    int f154;
    char unknown_158_[0x166 - 0x158];
    unsigned short unknown_166_;
    char unknown_168_[0x17b - 0x168];
    unsigned char unknown_17b_;
};

extern "C" void* LinkSession_GetInstance(void);
extern "C" Vector3fix func_020341e0(void* obj);
extern "C" int func_020322c0(int a, int* b, int c);
extern "C" void func_020794f8(void* obj, int a, int b);
extern "C" int LinkSession_IsActive(int* obj);
struct SearchStruct0202c1a4;
struct BitFlag02033f44;
struct Obj02033834;
struct Obj02033b68;
struct Struct_02077788_2;
extern "C" int LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
extern "C" int GameObject_GetWallHit(struct BitFlag02033f44* obj);
extern "C" void GameObject_SetFacing(struct Obj02033834* obj, int angle);
extern "C" void GameObject_SetMotionState(struct Obj02033b68* obj, int value);
extern "C" void func_02076ccc(void* obj, int mode);
extern "C" int func_02077a20(struct Struct_02077788_2* obj);
extern "C" int func_02039760(void* obj);

// USA: func_02077788
extern "C" ARM void func_02077788(struct Struct_02077788* self) {
    GameState* battleStruct = GameState::GetInstance();
    void* g = LinkSession_GetInstance();
    GameObject* combatant = battleStruct->GetPartyMemberByIndex(self->unknown_166_);
    if (combatant == 0) {
        return;
    }

    Vector3fix pos = func_020341e0(combatant);
    Vector3fix delta;
    Vector3fix_Subtract(&pos, &self->object.position_, &delta);
    Vector3fix_Normalize(&delta, &delta);
    int angle = fix32_Atan2(delta.x, delta.z);
    GameObject_SetFacing((struct Obj02033834*)self, angle);

    self->unknown_b4_ = 0x1c2;
    self->unknown_b2_ = 0x1c2;
    GameObject_SetMotionState((struct Obj02033b68*)self, 1);

    int flag = GameObject_GetWallHit((struct BitFlag02033f44*)self);
    int inRange = 0;
    if (flag != 0) {
        int v = self->unknown_ae_;
        if (func_020322c0(flag, &v, v) < 0x199) {
            inRange = 1;
        }
    }
    if (inRange) {
        func_02076ccc(self, 1);
        self->f154 = 0;
        if (LinkSession_IsActive((int*)g)) {
            func_020794f8(self, 0, 0);
        }
        return;
    }

    unsigned short index = self->unknown_166_;
    if (combatant->obj3D_.unknown_0_ & 0x1000) {
        index = 0;
    }
    if (!LinkSession_IsActive((int*)g) || index == LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)g)) {
        Vector3fix pos2 = func_020341e0(combatant);
        int radius = combatant->obj3D_.GetRadius();
        int var12 = self->object.GetScale().x * 15;
        int var13 = func_02077a20((struct Struct_02077788_2*)self) >> 1;
        long long var14 = (long long)var13 * var12;
        int var15 = (radius >> 1) + (int)((var14 + 0x800) >> 12);
        int dist = Vector3fix_Distance(&pos2, &self->object.position_);
        if ((dist != 0 && var15 > dist) || dist > 0x7800) {
            func_02076ccc(self, 1);
            self->f154 = 0;
            self->unknown_17b_ = 1;
            if (LinkSession_IsActive((int*)g)) {
                func_020794f8(self, 1, 0);
            }
            return;
        }
    }

    if (LinkSession_IsActive((int*)g) && LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)g) != 0) {
        return;
    }
    if (static_cast<unsigned char>(combatant->unk_ac[0xc0 - 0xac]) == 6 ||
        func_02039760(battleStruct->GetProtagonist()) == 2) {
        func_02076ccc(self, 1);
        self->f154 = 0;
        if (LinkSession_IsActive((int*)g) && LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)g) == 0) {
            func_020794f8(self, 0, 0);
        }
    }
}
