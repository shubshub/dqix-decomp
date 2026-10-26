#include <globaldefs.h>
#include "NitroSDK/Matrix.h"
#include "World/Object3D.h"
#include "GameState/GameState.h"

struct Random;
int NextRandomMax(Random*, int);
float NextRandomFloat01(Random*);
int fix32ReduceAngle0To2Pi(int);
void Vector3fixMultiplyScalar(const Vector3i*, int, Vector3i*);
extern "C" int func_ov000_0216f728(unsigned short*);
extern "C" void Camera_SetOrbitVector(void*, int*);
extern "C" {
void Vector3fix_Subtract(const Vector3i*, const Vector3i*, Vector3i*);
int Vector3fix_Length(const Vector3i*);
int fix32_Divide(int,int);
void Vector3fix_Add(const Vector3i*, const Vector3i*, Vector3i*);
void func_ov000_0216d370(void*,int,int,int);
int func_ov000_0216f210(void*,int*);
extern int data_ov000_02183fc8;
struct Struct_ov000_02184270 { unsigned short unknown_0_,kind; int unknown_4_,value8,valueC,value10,unknown_14_; };
extern Struct_ov000_02184270 data_ov000_02184270;
struct Struct_ov000_021832c4 { Vector3i v[4]; };
extern const Struct_ov000_021832c4 data_ov000_021832c4;
}
struct Struct_ov000_0216e678 {
    char p0[0x10]; Vector3i position; char p1[0x21c-0x1c]; Random* unknown_21c_;
    char p2[0x258-0x220]; int unknown_258_, count;
    unsigned char initialized, state, first, second;
    char p3[0x27c-0x264]; unsigned short* info;
};

// USA: func_ov000_0216e678
extern "C" ARM void func_ov000_0216e678(Struct_ov000_0216e678* obj, int first, int second, int arg3, int active) {
    GameState* gs = GameState::GetInstance();
    if (!obj->initialized) data_ov000_02183fc8 = 1;
    else data_ov000_02183fc8 = 0;
    if (arg3) data_ov000_02183fc8 = 0;
    func_ov000_0216d370(obj, 0, 1, 1);
    obj->initialized = 1;
    obj->state = 0;
    obj->first = first;
    obj->second = second;
    data_ov000_02184270.value10 = 0;
    data_ov000_02184270.unknown_14_ = 0;
    data_ov000_02184270.unknown_4_ = 0;
    data_ov000_02184270.kind = 0;
    Random* var1 = obj->unknown_21c_;
    data_ov000_02184270.unknown_0_ = NextRandomMax(var1, 100);
    if (obj->count >= 1 && (obj->count == 5 || NextRandomMax(var1, 5 - obj->count) == 0)) active = 1;
    if (active) {
        GameObject* a = gs->GetGameObjectByIndex(obj->first);
        GameObject* b = gs->GetGameObjectByIndex(obj->second);
        if (!a || !b) return;
        Vector3i pa(a->obj3D_.position_), pb(b->obj3D_.position_), direction, result, offset;
        int height = b->obj3D_.GetHeight();
        Vector3fix_Subtract(&pb, &pa, &direction);
        int length = Vector3fix_Length(&direction);
        if (length != 0) Vector3fixMultiplyScalar(&direction, fix32_Divide(0x1000, length), &direction);
        if (length / 2 > 0x3000) Vector3fixMultiplyScalar(&direction, 0x2000, &offset);
        else Vector3fixMultiplyScalar(&direction, length / 2, &offset);
        Vector3fix_Add(&pa, &offset, &result);
        int var11 = a->obj3D_.GetHeight();
        result.y = (int)((float)result.y + 0.75f * (float)var11);
        obj->position = result;
        Struct_ov000_021832c4 var12(data_ov000_021832c4);
        var12.v[0].x = fix32ReduceAngle0To2Pi(0x2d3c);
        var12.v[1].x = fix32ReduceAngle0To2Pi(-0x2d3c);
        var12.v[2].x = fix32ReduceAngle0To2Pi(0x505);
        var12.v[3].x = fix32ReduceAngle0To2Pi(-0x505);
        int inRange;
        Random* rng = obj->unknown_21c_;
        int index = NextRandomMax(rng, 4);
        inRange = func_ov000_0216f728(obj->info);
        Vector3i selected(var12.v[index]);
        if (height > 0x2800) {
            result.y = height / 2;
            if (result.y < 0x2800) result.y = 0x2800;
            selected.y = (int)(4096.0f * (-1.8f + (0.6f - 0.8f * NextRandomFloat01(rng))));
            data_ov000_02184270.value8 = selected.y;
            if (!inRange) data_ov000_02184270.valueC = (int)(4096.0f * (1.0995574f - 0.7f * (3.1415927f * NextRandomFloat01(rng))));
            if (selected.z < 0x8000) selected.z = 0x8000;
        }
        Camera_SetOrbitVector(obj, &selected.x);
        obj->count = 0;
        data_ov000_02184270.kind = 5;
        int out;
        obj->unknown_258_ = func_ov000_0216f210(obj, &out);
    } else obj->count++;
}
