#include <globaldefs.h>
#include "NitroSDK/Matrix.h"
#include "World/Object3D.h"
#include "GameState/GameState.h"

struct Random;
int NextRandomMax(Random*, int);
float NextRandomFloat01(Random*);
int fix32ReduceAngle0To2Pi(int);
void Vector3fixMultiplyScalar(const Vector3i*, int, Vector3i*);
int IsValueInRange0216f728(unsigned short*);
void Camera_SetOrbitVector(void*, int*);
extern "C" {
void Vector3fix_Subtract(const Vector3i*, const Vector3i*, Vector3i*);
int Vector3fix_Length(const Vector3i*);
int fix32_Divide(int,int);
void Vector3fix_Add(const Vector3i*, const Vector3i*, Vector3i*);
void func_ov000_0216d370(void*,int,int,int);
int func_ov000_0216f210(void*,int*);
extern int data_ov000_02183fc8;
struct Struct_ov000_02184270 { unsigned short unknown_0_,unknown_2_; int unknown_4_,unknown_8_,unknown_c_,unknown_10_,unknown_14_; };
extern Struct_ov000_02184270 data_ov000_02184270;
struct Struct_ov000_021832c4 { Vector3i unknown_0_[4]; };
extern const Struct_ov000_021832c4 data_ov000_021832c4;
}
struct Struct_ov000_0216e678 {
    char unknown_0_[0x10]; Vector3i unknown_10_; char unknown_1c_[0x21c-0x1c]; Random* unknown_21c_;
    char unknown_220_[0x258-0x220]; int unknown_258_, unknown_25c_;
    unsigned char unknown_260_, unknown_261_, unknown_262_, unknown_263_;
    char unknown_264_[0x27c-0x264]; unsigned short* unknown_27c_;
};

// USA: func_ov000_0216e678
extern "C" ARM void func_ov000_0216e678(Struct_ov000_0216e678* arg0, int arg1, int arg2, int arg3, int arg4) {
    GameState* var0 = GameState::GetInstance();
    if (!arg0->unknown_260_) data_ov000_02183fc8 = 1;
    else data_ov000_02183fc8 = 0;
    if (arg3) data_ov000_02183fc8 = 0;
    func_ov000_0216d370(arg0, 0, 1, 1);
    arg0->unknown_260_ = 1;
    arg0->unknown_261_ = 0;
    arg0->unknown_262_ = arg1;
    arg0->unknown_263_ = arg2;
    data_ov000_02184270.unknown_10_ = 0;
    data_ov000_02184270.unknown_14_ = 0;
    data_ov000_02184270.unknown_4_ = 0;
    data_ov000_02184270.unknown_2_ = 0;
    Random* var1 = arg0->unknown_21c_;
    data_ov000_02184270.unknown_0_ = NextRandomMax(var1, 100);
    if (arg0->unknown_25c_ >= 1 && (arg0->unknown_25c_ == 5 || NextRandomMax(var1, 5 - arg0->unknown_25c_) == 0)) arg4 = 1;
    if (arg4) {
        GameObject* var2 = var0->GetGameObjectByIndex(arg0->unknown_262_);
        GameObject* var3 = var0->GetGameObjectByIndex(arg0->unknown_263_);
        if (!var2 || !var3) return;
        Vector3i var4(var2->obj3D_.position_), var5(var3->obj3D_.position_), var6, var7, var8;
        int var9 = var3->obj3D_.GetHeight();
        Vector3fix_Subtract(&var5, &var4, &var6);
        int var10 = Vector3fix_Length(&var6);
        if (var10 != 0) Vector3fixMultiplyScalar(&var6, fix32_Divide(0x1000, var10), &var6);
        if (var10 / 2 > 0x3000) Vector3fixMultiplyScalar(&var6, 0x2000, &var8);
        else Vector3fixMultiplyScalar(&var6, var10 / 2, &var8);
        Vector3fix_Add(&var4, &var8, &var7);
        int var11 = var2->obj3D_.GetHeight();
        var7.y = (int)((float)var7.y + 0.75f * (float)var11);
        arg0->unknown_10_ = var7;
        Struct_ov000_021832c4 var12(data_ov000_021832c4);
        var12.unknown_0_[0].x = fix32ReduceAngle0To2Pi(0x2d3c);
        var12.unknown_0_[1].x = fix32ReduceAngle0To2Pi(-0x2d3c);
        var12.unknown_0_[2].x = fix32ReduceAngle0To2Pi(0x505);
        var12.unknown_0_[3].x = fix32ReduceAngle0To2Pi(-0x505);
        int var13;
        Random* var14 = arg0->unknown_21c_;
        int var15 = NextRandomMax(var14, 4);
        var13 = func_ov000_0216f728(arg0->unknown_27c_);
        Vector3i var16(var12.unknown_0_[var15]);
        if (var9 > 0x2800) {
            var7.y = var9 / 2;
            if (var7.y < 0x2800) var7.y = 0x2800;
            var16.y = (int)(4096.0f * (-1.8f + (0.6f - 0.8f * NextRandomFloat01(var14))));
            data_ov000_02184270.unknown_8_ = var16.y;
            if (!var13) data_ov000_02184270.unknown_c_ = (int)(4096.0f * (1.0995574f - 0.7f * (3.1415927f * NextRandomFloat01(var14))));
            if (var16.z < 0x8000) var16.z = 0x8000;
        }
        Camera_SetOrbitVector(obj, &selected.x);
        obj->count = 0;
        data_ov000_02184270.kind = 5;
        int out;
        obj->value258 = func_ov000_0216f210(obj, &out);
    } else obj->count++;
}
