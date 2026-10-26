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

struct Struct_ov001_021592bc {
    int x;
    int y;
    int z;
};
struct Vector3i;
void Vector3fixMultiplyScalar(Vector3i const*, int, Vector3i*);

struct Obj02033b68;
extern "C" void GameObject_SetMotionState(struct Obj02033b68* obj, int newVal);

struct U16Field0x6_020375f8;

extern "C" int _s32_div_f(int a, int b);

extern "C" void func_ov017_021c927c(int a, int b, int c, struct Vec3 v, int d, int e, int f);

struct Struct_020781e8 {
    char pad0[0x2];
    short f2;
    short f4;
    char pad1[0x3e];
    struct Vec3 unknown_44_;
    char pad2[0x62];
    short unknown_b2_;
    short unknown_b4_;
    char pad3[0xa2];
    struct Vec3 unknown_158_;
    char pad4[0x2];
    unsigned short f166;
    char pad5[0x12];
    unsigned char unknown_17a_;
};

// USA: func_020781e8
extern "C" ARM int func_020781e8(struct Struct_020781e8* e) {
    GameState* battleStruct = GameState::GetInstance();
    GameObject* combatant = battleStruct->GetPartyMemberByIndex(e->f166);
    if (combatant == NULL) {
        return 0;
    }

    int scale = 0;
    void* g = LinkSession_GetInstance();
    if (!LinkSession_IsActive((int*)g) || LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)g) == 0) {
        struct Vec3 var4 = func_02034104(combatant);
        struct Vec3 delta;
        Vector3fix_Subtract((const Vector3fix*)&var4, (const Vector3fix*)&e->unknown_44_, (Vector3fix*)&delta);
        Vector3fix_Normalize((const Vector3fix*)&delta, (Vector3fix*)&delta);
        delta.x = -delta.x;
        delta.y = -delta.y;
        delta.z = -delta.z;
        scale = fix32_Atan2(delta.x, delta.z);
        GameObject_SetFacing((struct Obj02033834*)e, scale);
        delta.y = 0;
        Vector3fixMultiplyScalar((Vector3i const*)&delta, 0x5000, (Vector3i*)&delta);
        Vector3fix_Add((const Vector3fix*)&e->unknown_44_, (const Vector3fix*)&delta, (Vector3fix*)&e->unknown_158_);
    }

    e->unknown_b4_ = 0x1c2;
    e->unknown_b2_ = 0x1c2;
    GameObject_SetMotionState((struct Obj02033b68*)e, 1);
    ((Object3D*)((unsigned char*)e))->DisableFlag(0x80);
    e->unknown_17a_ = 0;

    if (LinkSession_IsActive((int*)g) && LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)g) == 0) {
        int c1 = ((Object3D*)((struct U16Field0x6_020375f8*)e))->GetField06();
        int var7 = e->f2;
        struct Vec3* var8 = &e->unknown_158_;
        int rem = (e->f4 - 0x70) % 0xc;
        if (rem >= 0 && rem < 0xc) {
            struct Vec3 v = *var8;
            func_ov017_021c927c(c1, rem, var7, v, scale, 7, e->f166);
        }
    }
    return 1;
}
