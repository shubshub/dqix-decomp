#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Graphics/Vector.h>

int IsValueInRange0216f728(unsigned short*);
void Camera_SetOrbitVector(void*, int*);
int Camera_GetRoll(void*);
extern "C" void _Z14Camera_SetRollPht(unsigned char*, int);
extern "C" {
void Camera_SetOrbit(void*,int,int,int);
extern int data_ov000_02183fc8;
struct Struct_ov000_02184270_2 { unsigned short unknown_0_,unknown_2_; int unknown_4_,unknown_8_,unknown_c_,unknown_10_,unknown_14_; };
extern Struct_ov000_02184270_2 data_ov000_02184270;
extern const int data_ov000_02183268[];
extern const int data_ov000_02183298[];
extern const short data_ov000_0218325c[];
}
struct Struct_ov000_0216ea38 {
    char unknown_0_[0x10]; Vector3i unknown_10_; char unknown_1c_[0x70-0x1c]; Vector3i unknown_70_;
    char unknown_7c_[0x260-0x7c]; unsigned char unknown_260_,unknown_261_,unknown_262_,unknown_263_;
    char unknown_264_[0x27c-0x264]; unsigned short* unknown_27c_;
};

// USA: func_ov000_0216ea38
extern "C" ARM void func_ov000_0216ea38(Struct_ov000_0216ea38* arg0) {
    if (!arg0->unknown_260_) return;
    GameState* var0 = GameState::GetInstance();
    data_ov000_02184270.unknown_10_ += 0xcc;
    data_ov000_02184270.unknown_14_ += 0x14;
    data_ov000_02184270.unknown_4_ += 4;
    GameObject* var1 = var0->GetGameObjectByIndex(arg0->unknown_262_);
    GameObject* var2 = var0->GetGameObjectByIndex(arg0->unknown_263_);
    if (!var1 || !var2) return;
    int var3 = var1->obj3D_.GetHeight(), var4 = var2->obj3D_.GetHeight();
    int var5 = 0;
    if (var3 >= 0x2000) var5 = 1;
    if (var4 >= 0x2000) var5 = 0;
    if (var4 < 0x2000 && var3 < 0x2000) var5 = data_ov000_02184270.unknown_0_ % 2;
    Vector3i var6(var1->obj3D_.position_), var7(var2->obj3D_.position_), var8, var9, var10;
    Vector3fix_Subtract(&var7, &var6, &var8);
    int var11 = Vector3fix_Length(&var8);
    if (var11) Vector3fixMultiplyScalar(&var8, fix32_Divide(0x1000,var11), &var8);
    if (var11 / 2 > 0x3000) Vector3fixMultiplyScalar(&var8,0x2000,&var10);
    else Vector3fixMultiplyScalar(&var8,var11/2,&var10);
    if (!var5) {
        Vector3fix_Add(&var6,&var10,&var9);
        int var12 = var1->obj3D_.GetHeight();
        var9.y = (int)((float)var9.y + 0.75f*(float)var12);
    } else {
        Vector3fixMultiplyScalar(&var10,-0x1000,&var10);
        Vector3fix_Add(&var7,&var10,&var9);
        int var13 = var2->obj3D_.GetHeight();
        var9.y = (int)((float)var9.y + 0.75f*(float)var13);
    }
    if (var9.y > 0x1000) var9.y = 0x1000;
    Vector3i var14, var15, var16(arg0->unknown_10_);
    Vector3fix_Subtract(&var9,&var16,&var15);
    int var17 = Vector3fix_Length(&var15);
    Vector3fixMultiplyScalar(&var15,0xcc,&var15);
    int var18 = Vector3fix_Length(&var15);
    if (data_ov000_02184270.unknown_10_ < var18)
        Vector3fixMultiplyScalar(&var15,fix32_Divide(data_ov000_02184270.unknown_10_,var18),&var15);
    Vector3fix_Add(&var16,&var15,&var14);
    if (data_ov000_02184270.unknown_2_ == 0) {
        if (var17 < 0x5000) arg0->unknown_261_ = 1;
    } else data_ov000_02184270.unknown_2_--;
    Vector3i var19(arg0->unknown_70_);
    int var20,var21,var22,var23;
    if (!var5) {
        int var24 = fix32_Atan2(var8.x,var8.z);
        var20 = fix32ReduceAngle0To2Pi((int)(11581.19921875f + (float)var24));
        var22 = fix32ReduceAngle0To2Pi((int)((float)var24 - 11581.19921875f));
        var21 = fix32abs(fix32SignedAngleDistance(var19.x,var20));
        var23 = fix32abs(fix32SignedAngleDistance(var19.x,var22));
    } else {
        int var25 = fix32_Atan2(var8.x,var8.z);
        var20 = fix32ReduceAngle0To2Pi((int)(12868.0f + (11581.19921875f + (float)var25)));
        var22 = fix32ReduceAngle0To2Pi((int)(12868.0f + ((float)var25 - 11581.19921875f)));
        var21 = fix32abs(fix32SignedAngleDistance(var19.x,var20));
        var23 = fix32abs(fix32SignedAngleDistance(var19.x,var22));
    }
    if (var21 >= var23) var20 = var22;
    int var26 = 0x1000;
    int var27;
    if (data_ov000_02184270.unknown_0_ < 30) {
        float var28 = (float)Vector3fix_Distance(&var6,&var7);
        var28 *= 1.6f;
        var27 = (int)var28;
        if (var27 < 0x7000) var27 = 0x7000;
    } else {
        int var29 = (arg0->unknown_262_ + arg0->unknown_263_) % 3;
        var27 = data_ov000_02183268[var29];
        var26 = data_ov000_02183298[var29];
    }
    int var30 = func_ov000_0216f728(arg0->unknown_27c_);
    if (var4 > 0x2800) {
        var9.y = var4 / 2;
        if (var9.y < 0x2800) var9.y = 0x2800;
        var14.y = var9.y;
        var26 = data_ov000_02184270.unknown_8_;
        if (!var30) var20 = fix32ReduceAngle0To2Pi(var20 + data_ov000_02184270.unknown_c_);
        if (var27 < 0x8000) var27 = 0x8000;
    }
    int var31 = data_ov000_0218325c[(arg0->unknown_262_ + arg0->unknown_263_) % 5];
    if (data_ov000_02183fc8) {
        obj->position = result;
        Camera_SetOrbit(obj,firstAngle,desiredY,desiredZ);
        _Z14Camera_SetRollPht((unsigned char*)obj,desiredTail);
        data_ov000_02183fc8 = 0;
    } else {
        if (var14.y > 0x2000) var14.y = 0x2000;
        arg0->unknown_10_ = var14;
        Vector3i var32(var19);
        int var33 = (int)(0.05f*(float)fix32SignedAngleDistance(var19.x,var20));
        int var34 = data_ov000_02184270.unknown_14_;
        if (var34 < fix32abs(var33)) {
            if (var33 > 0) var33 = var34;
            else var33 = -var34;
        }
        next.x = fix32ReduceAngle0To2Pi(angles.x+difference);
        next.y = (int)((float)angles.y + 0.02f*(float)(desiredY-angles.y));
        next.z = (int)((float)angles.z + 0.02f*(float)(desiredZ-angles.z));
        Camera_SetOrbitVector(obj,&next.x);
        int change, tailLimit;
        int tail = Camera_GetRoll(obj);
        float scaledChange = (float)fix32SignedAngleDistance(tail,desiredTail);
        scaledChange *= 0.1f;
        change = (int)scaledChange;
        tailLimit = data_ov000_02184270.value4;
        if (tailLimit < fix32abs(change)) {
            if (change > 0) change = tailLimit;
            else change = -tailLimit;
        }
        if (change) _Z14Camera_SetRollPht((unsigned char*)obj,(short)fix32ReduceAngle0To2Pi(change+tail));
    }
}
