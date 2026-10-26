#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* LinkSession_GetInstance(void);
int LinkSession_IsActive(int* obj);

struct SearchStruct0202c1a4;
signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);

struct Struct_ov009_0218aa28 {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
};

extern "C" struct Struct_ov009_0218aa28 func_02034104(GameObject* arg0);

struct Obj02033834;
void GameObject_SetFacing(struct Obj02033834* obj, int arg);

struct Obj02033b68;
void GameObject_SetMotionState(struct Obj02033b68* obj, int newVal);

struct Struct_02037d88_8;

struct Struct_02039df4;

extern "C" int _s32_div_f(int a, int b);

extern "C" void func_ov017_021c9400(int arg0, int arg1, int arg2, struct Struct_ov009_0218aa28 arg3, struct Struct_ov009_0218aa28 arg4, int arg5);

struct Struct_02078754 {
    char unknown_0_[2];
    short unknown_2_;
    short unknown_4_;
    char unknown_6_[0x3e];
    struct Struct_ov009_0218aa28 unknown_44_;
    struct Struct_ov009_0218aa28 unknown_50_;
    char unknown_5c_[0x56];
    short unknown_b2_;
    char unknown_b4_[0x166 - 0xb4];
    unsigned short unknown_166_;
    char unknown_168_[0x12];
    unsigned char unknown_17a_;
};

// USA: func_02078754
extern "C" ARM int func_02078754(struct Entity02078754* self) {
    GameState* battleStruct = GameState::GetInstance();
    GameObject* combatant = battleStruct->GetWanderingMonsterByIndex(self->f166);
    if (combatant == 0) {
        return 0;
    }

    struct Vec3 posCopy = func_02034104(combatant);
    struct Vec3 delta;
    Vector3fix_Subtract((const Vector3fix*)&posCopy, (const Vector3fix*)&self->f44, (Vector3fix*)&delta);
    Vector3fix_Normalize((const Vector3fix*)&delta, (Vector3fix*)&delta);
    int angle = fix32_Atan2(delta.x, delta.z);
    GameObject_SetFacing((struct Obj02033834*)self, angle);

    self->fb2 = 0;
    GameObject_SetMotionState((struct Obj02033b68*)self, 0);
    ((Object3D*)((unsigned char*)self))->EnableFlag(0x80);
    ((Object3D*)((struct S02037418*)self))->SetInheritedAlpha(0x1f);
    self->f17a = 0;

    void* g = LinkSession_GetInstance();
    if (LinkSession_IsActive((int*)g) && LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)g) == 0) {
        int c1 = ((Object3D*)((struct U16Field0x6_020375f8*)self))->GetField06();
        int f2val = self->f2;
        struct Vec3* p44 = &self->f44;
        struct Vec3* p50 = &self->f50;
        int rem = (self->f4 - 0x70) % 0xc;
        if (rem >= 0 && rem < 0xc) {
            func_ov017_021c9400(c1, rem, f2val, *p44, *p50, -1);
        }
    }
    return 1;
}
