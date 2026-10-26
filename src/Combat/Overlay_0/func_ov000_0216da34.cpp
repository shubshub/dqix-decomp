#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"
#include "Util/Random.h"

extern "C" void func_ov000_0216d370(void* obj, int flagA, int arg2, int flagC);
extern "C" void func_ov000_0216d234(void* forward, void* position, void* dest);

struct Struct_0202ecc8 { unsigned int v[12]; };
struct Struct_0202ecc8_2;
extern "C" void func_0202ecc8(struct Struct_0202ecc8_2* dst, struct Struct_0202ecc8* src);
extern "C" void func_0202ecec(unsigned char* obj);
extern "C" void Camera_SetOrbitVector(void* obj, int* vec);

extern Vector3i data_ov000_02183274;

struct Struct_ov000_0216da34 {
    char pad0[0x10];
    Vector3i field10;
    char unknown_1c_[0x21c - 0x1c];
    struct Random* unknown_21c_;
    char unknown_220_[0x23c - 0x220];
    int unknown_23c_;
};

// USA: func_ov000_0216da34
extern "C" ARM void func_ov000_0216da34(struct Struct_ov000_0216da34* obj, int arg1, int arg2) {
    GameState* gs = GameState::GetInstance();
    GameObject* a = gs->GetCombatantByIndex(arg1);
    GameObject* b = gs->GetCombatantByIndex(arg2);
    if (a == NULL || b == NULL) {
        return;
    }
    func_ov000_0216d370(obj, 1, 1, 1);
    Vector3fix var3 = a->obj3D_.position_;
    Vector3fix var4 = b->obj3D_.position_;
    Vector3fix dir;
    Vector3fix center;
    if (arg1 != arg2) {
        Vector3fix_Subtract(&var4, &var3, &dir);
        Vector3fix_Normalize(&dir, &dir);
        Vector3fix_Add(&var4, &var3, &center);
        Vector3fixMultiplyScalar(&center, 0x800, &center);
    } else {
        fix32_t angle = a->obj3D_.rotation_.y;
        fix32_t c = fix32cos(angle);
        dir.x = fix32sin(angle);
        dir.y = 0;
        dir.z = c;
        center = var3;
    }
    struct Struct_0202ecc8 block;
    func_ov000_0216d234(&dir, &center, &block);
    func_0202ecc8((struct Struct_0202ecc8_2*)obj, &block);
    func_0202ecec((unsigned char*)obj);
    Vector3i v = data_ov000_02183274;
    int base;
    struct Random* var12 = obj->unknown_21c_;
    base = 0;
    if (NextRandomMax(var12, 2) == 0) {
        base = 0x3244;
    }
    int angle;
    if (NextRandomMax(var12, 2) == 0) {
        angle = fix32ReduceAngle0To2Pi(base + 0x4cc);
    } else {
        angle = fix32ReduceAngle0To2Pi(base - 0x4cc);
    }
    int tail[3];
    tail[0] = angle;
    tail[1] = 0x1000;
    tail[2] = 0x8000;
    obj->field10 = v;
    Camera_SetOrbitVector(obj, tail);
    obj->unknown_23c_ = -20;
}
