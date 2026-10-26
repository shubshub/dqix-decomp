#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"
#include "Util/Random.h"

extern "C" void func_ov000_0216d370(void* arg0, int arg1, int arg2, int arg3);
extern "C" void func_ov000_0216d234(void* arg0, void* arg1, void* arg2);

struct Block0202ecc8 { unsigned int v[12]; };
struct Dst0202ecc8;
void CopyBlockToField0xf0(struct Dst0202ecc8* dst, struct Block0202ecc8* src);
void SetFlag0x1At0x168_0202ecec(unsigned char* obj);
void Camera_SetOrbitVector(void* obj, int* vec);

extern Vector3i data_ov000_02183274;

struct Struct_ov000_0216da34 {
    char unknown_0_[0x10];
    Vector3i unknown_10_;
    char unknown_1c_[0x21c - 0x1c];
    struct Random* unknown_21c_;
    char unknown_220_[0x23c - 0x220];
    int unknown_23c_;
};

// USA: func_ov000_0216da34
extern "C" ARM void func_ov000_0216da34(struct Struct_ov000_0216da34* arg0, int arg1, int arg2) {
    GameState* var0 = GameState::GetInstance();
    GameObject* var1 = var0->GetCombatantByIndex(arg1);
    GameObject* var2 = var0->GetCombatantByIndex(arg2);
    if (var1 == NULL || var2 == NULL) {
        return;
    }
    func_ov000_0216d370(arg0, 1, 1, 1);
    Vector3fix var3 = var1->obj3D_.position_;
    Vector3fix var4 = var2->obj3D_.position_;
    Vector3fix var5;
    Vector3fix var6;
    if (arg1 != arg2) {
        Vector3fix_Subtract(&var4, &var3, &var5);
        Vector3fix_Normalize(&var5, &var5);
        Vector3fix_Add(&var4, &var3, &var6);
        Vector3fixMultiplyScalar(&var6, 0x800, &var6);
    } else {
        fix32_t var7 = var1->obj3D_.rotation_.y;
        fix32_t var8 = fix32cos(var7);
        var5.x = fix32sin(var7);
        var5.y = 0;
        var5.z = var8;
        var6 = var3;
    }
    struct Struct_0202ecc8 var9;
    func_ov000_0216d234(&var5, &var6, &var9);
    func_0202ecc8((struct Struct_0202ecc8_2*)arg0, &var9);
    func_0202ecec((unsigned char*)arg0);
    Vector3i var10 = data_ov000_02183274;
    int var11;
    struct Random* var12 = arg0->unknown_21c_;
    var11 = 0;
    if (NextRandomMax(var12, 2) == 0) {
        var11 = 0x3244;
    }
    int var13;
    if (NextRandomMax(var12, 2) == 0) {
        var13 = fix32ReduceAngle0To2Pi(var11 + 0x4cc);
    } else {
        var13 = fix32ReduceAngle0To2Pi(var11 - 0x4cc);
    }
    int tail[3];
    tail[0] = angle;
    tail[1] = 0x1000;
    tail[2] = 0x8000;
    obj->field10 = v;
    Camera_SetOrbitVector(obj, tail);
    obj->field23c = -20;
}
