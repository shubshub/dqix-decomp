#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
#define func_020341e0 func_02034104
#endif

struct Struct_02077788 {
    Object3D unknown_0_;
    char unknown_ac_[2];
    short unknown_ae_;
    char unknown_b0_[0xb2 - 0xb0];
    unsigned short unknown_b2_;
    unsigned short unknown_b4_;
    char unknown_b6_[0x154 - 0xb6];
    int unknown_154_;
    char unknown_158_[0x166 - 0x158];
    unsigned short unknown_166_;
    char unknown_168_[0x17b - 0x168];
    unsigned char unknown_17b_;
};

extern "C" void* LinkSession_GetInstance(void);
extern "C" Vector3fix func_020341e0(void* obj);
extern "C" int func_020322c0(int a, int* b, int c);
extern "C" void func_020794f8(void* obj, int a, int b);
int LinkSession_IsActive(int* obj);
struct SearchStruct0202c1a4;
struct BitFlag02033f44;
struct Obj02033834;
struct Obj02033b68;
struct Outer02077a20;
int LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
int GameObject_GetWallHit(struct BitFlag02033f44* obj);
void GameObject_SetFacing(struct Obj02033834* obj, int angle);
void GameObject_SetMotionState(struct Obj02033b68* obj, int value);
void TrySetMode02076ccc(void* obj, int mode);
int GetField0x8OrDefault02077a20(struct Outer02077a20* obj);
int GetIntField0x264_02039760(void* obj);

// USA: func_02077788
extern "C" ARM void func_02077788(struct Entity02077788* self) {
    GameState* battleStruct = GameState::GetInstance();
    void* g = LinkSession_GetInstance();
    GameObject* combatant = battleStruct->GetPartyMemberByIndex(self->partyMemberIndex);
    if (combatant == 0) {
        return;
    }

    Vector3fix pos = func_020341e0(combatant);
    Vector3fix delta;
    Vector3fix_Subtract(&pos, &self->object.position_, &delta);
    Vector3fix_Normalize(&delta, &delta);
    int angle = fix32_Atan2(delta.x, delta.z);
    GameObject_SetFacing((struct Obj02033834*)self, angle);

    self->fb4 = 0x1c2;
    self->fb2 = 0x1c2;
    GameObject_SetMotionState((struct Obj02033b68*)self, 1);

    int flag = GameObject_GetWallHit((struct BitFlag02033f44*)self);
    int inRange = 0;
    if (flag != 0) {
        int v = self->fae;
        if (func_020322c0(flag, &v, v) < 0x199) {
            inRange = 1;
        }
    }
    if (inRange) {
        TrySetMode02076ccc(self, 1);
        self->f154 = 0;
        if (LinkSession_IsActive((int*)g)) {
            func_020794f8(self, 0, 0);
        }
        return;
    }

    unsigned short var9 = arg0->unknown_166_;
    if (var2->obj3D_.unknown_0_ & 0x1000) {
        var9 = 0;
    }
    if (!LinkSession_IsActive((int*)g) || index == LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)g)) {
        Vector3fix pos2 = func_020341e0(combatant);
        int radius = combatant->obj3D_.GetRadius();
        int scaledSpacing = self->object.GetScale().x * 15;
        int halfSpacingFactor = GetField0x8OrDefault02077a20((struct Outer02077a20*)self) >> 1;
        long long spacingProduct = (long long)halfSpacingFactor * scaledSpacing;
        int distanceThreshold = (radius >> 1) + (int)((spacingProduct + 0x800) >> 12);
        int dist = Vector3fix_Distance(&pos2, &self->object.position_);
        if ((dist != 0 && distanceThreshold > dist) || dist > 0x7800) {
            TrySetMode02076ccc(self, 1);
            self->f154 = 0;
            self->f17b = 1;
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
        GetIntField0x264_02039760(battleStruct->GetProtagonist()) == 2) {
        TrySetMode02076ccc(self, 1);
        self->f154 = 0;
        if (LinkSession_IsActive((int*)g) && LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)g) == 0) {
            func_020794f8(self, 0, 0);
        }
    }
}
