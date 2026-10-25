#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_0202ae18(void);
extern "C" int func_0202b7d8(int* arg0);

struct Struct_0202c1a4;
extern "C" signed char func_0202c1a4(struct Struct_0202c1a4* arg0);

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
extern "C" ARM int func_02078754(struct Struct_02078754* arg0) {
    GameState* var0 = GameState::GetInstance();
    GameObject* var1 = var0->GetMaybeWanderingMonsterByIndex(arg0->unknown_166_);
    if (var1 == 0) {
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

    void* var5 = func_0202ae18();
    if (func_0202b7d8((int*)var5) && func_0202c1a4((struct Struct_0202c1a4*)var5) == 0) {
        int var6 = ((Object3D*)((struct Struct_02039df4*)arg0))->GetField06();
        int var7 = arg0->unknown_2_;
        struct Struct_ov009_0218aa28* var8 = &arg0->unknown_44_;
        struct Struct_ov009_0218aa28* var9 = &arg0->unknown_50_;
        int var10 = (arg0->unknown_4_ - 0x70) % 0xc;
        if (var10 >= 0 && var10 < 0xc) {
            func_ov017_021c9400(var6, var10, var7, *var8, *var9, -1);
        }
    }
    return 1;
}
