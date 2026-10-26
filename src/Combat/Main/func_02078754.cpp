#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsActive(int* obj);

struct SearchStruct0202c1a4;
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);

struct Vec3 {
    int x;
    int y;
    int z;
};

extern "C" struct Vec3 func_02034104(GameObject* combatant);

struct Obj02033834;
extern "C" void GameObject_SetFacing(struct Obj02033834* obj, int arg);

struct Obj02033b68;
extern "C" void GameObject_SetMotionState(struct Obj02033b68* obj, int newVal);

struct S02037418;

struct U16Field0x6_020375f8;

extern "C" int _s32_div_f(int a, int b);

extern "C" void func_ov017_021c9400(int a, int b, int c, struct Vec3 v, struct Vec3 w, int d);

struct Struct_02078754 {
    char pad0[2];
    short f2;
    short f4;
    char pad6[0x3e];
    struct Vec3 unknown_44_;
    struct Vec3 unknown_50_;
    char unknown_5c_[0x56];
    short unknown_b2_;
    char unknown_b4_[0x166 - 0xb4];
    unsigned short f166;
    char unknown_168_[0x12];
    unsigned char unknown_17a_;
};

// USA: func_02078754
extern "C" ARM int func_02078754(struct Struct_02078754* self) {
    GameState* battleStruct = GameState::GetInstance();
    GameObject* combatant = battleStruct->GetWanderingMonsterByIndex(self->f166);
    if (combatant == 0) {
        return 0;
    }

    struct Vec3 var2 = func_02034104(combatant);
    struct Vec3 delta;
    Vector3fix_Subtract((const Vector3fix*)&var2, (const Vector3fix*)&self->unknown_44_, (Vector3fix*)&delta);
    Vector3fix_Normalize((const Vector3fix*)&delta, (Vector3fix*)&delta);
    int angle = fix32_Atan2(delta.x, delta.z);
    GameObject_SetFacing((struct Obj02033834*)self, angle);

    self->unknown_b2_ = 0;
    GameObject_SetMotionState((struct Obj02033b68*)self, 0);
    ((Object3D*)((unsigned char*)self))->EnableFlag(0x80);
    ((Object3D*)((struct S02037418*)self))->SetInheritedAlpha(0x1f);
    self->unknown_17a_ = 0;

    void* g = LinkSession_GetInstance();
    if (LinkSession_IsActive((int*)g) && LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)g) == 0) {
        int c1 = ((Object3D*)((struct U16Field0x6_020375f8*)self))->GetField06();
        int var7 = self->f2;
        struct Vec3* var8 = &self->unknown_44_;
        struct Vec3* var9 = &self->unknown_50_;
        int rem = (self->f4 - 0x70) % 0xc;
        if (rem >= 0 && rem < 0xc) {
            func_ov017_021c9400(c1, rem, var7, *var8, *var9, -1);
        }
    }
    return 1;
}
