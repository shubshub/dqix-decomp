#include <globaldefs.h>
#include "Combat/FormationPosition.h"
#include "GameState/GameState.h"
#include "Graphics/Vector.h"

struct Struct_02048e2c_2 {
    char unknown_0_[0x1c];
    unsigned char unknown_1c_;
    unsigned char unknown_1d_;
    unsigned char unknown_1e_;
    unsigned char unknown_1f_;
    unsigned int unknown_20_;
    unsigned char unknown_24_[0x10];
    unsigned char unknown_34_;
    char unknown_35_[0x3];
    int unknown_38_;
    short unknown_3c_;
    char unknown_3e_[0x2];
    int unknown_40_[3];
};

struct Struct_02048e2c {
    char unknown_0_[0x44];
    Vector3i unknown_44_;
    char unknown_50_[0x6e];
    unsigned char unknown_be_;
    char unknown_bf_[0x7d];
    Struct_02048e2c_2* unknown_13c_;
};

int GetSubstructByte0x56_02049ee8(unsigned char*);
struct Obj020494c0;
void DispatchTargetByte020494c0(Obj020494c0*);
struct Foo02033b58;
void SetByteSavingPrevious(Foo02033b58*, unsigned char);
struct Obj02033b68;
void GameObject_SetMotionState(Obj02033b68*, int);
struct Obj02049520;
void ClearSubFieldsAndFlag02049520(Obj02049520*);
struct Obj02049a74;
void ApplyFlag0x4IfEligible02049a74(Obj02049a74*);
struct Obj02048c90;
void ResetInnerState02048c90(Obj02048c90*);
void SetSubstructByte0x1c_02049390(unsigned char*, unsigned char);
struct Bytes02033b88;
void SetByte0xbeShiftPrev(Bytes02033b88*, int);
struct Obj02033834;
void GameObject_SetFacing(Obj02033834*, int);
extern "C" Vector3i func_ov025_021ee488(Vector3i* points, int count, int progress);

static inline Struct_02048cf0 inline_02048e2c_2(const int& arg0) {
    return func_ov000_0216f74c(const_cast<int*>(&arg0));
}

// USA: func_02048f64
extern "C" ARM void func_02048f64(Struct_02048e2c* arg0) {
    if (!(arg0->unknown_13c_->unknown_20_ & 0x10)) {
        return;
    }
    fix32_t var0;
    GameState* var1            = GameState::GetInstance();
    Struct_02048e2c_2* var2 = arg0->unknown_13c_;
    int var3                = var2->unknown_34_;
    unsigned char* var4     = var2->unknown_24_;
    if (var3 == 0) {
        var2->unknown_20_ &= ~0x10;
        return;
    }
    var0             = FIX32_MULTIPLY((short)var1->GetAnimationDeltaTime(), 0xcc);
    fix32_t var5 = var2->unknown_38_;
    if (var5 < 0) {
        var2->unknown_38_ = var5 + var0;
        return;
    }

    Vector3i var6[16];
    int var7;
    for (var7 = 0; var7 < var3; var7++) {
        Struct_02048cf0 var8 = inline_02048e2c_2(var4[var7]);
        var6[var7].x       = var8.unknown_0_;
        var6[var7].y       = 0xcc;
        var6[var7].z       = var8.unknown_4_;
    }
    int var9  = var2->unknown_40_[2];
    int var10  = var2->unknown_40_[0];
    var6[0].x = var10;
    var6[0].y = 0xcc;
    var6[0].z = var9;

    int var11 = var3;
    if (var2->unknown_1f_ != 0xff) {
        Struct_02048cf0 var12 = inline_02048e2c_2(var2->unknown_1f_);
        var6[var3].x   = var12.unknown_0_;
        var6[var3].y   = 0xcc;
        var6[var3].z   = var12.unknown_4_;
        var11                 = var3 + 1;
    }
    if (var11 < 4) {
        int var13 = var11 - 1;
        for (int var14 = var11; var14 < 4; var14++) {
            var6[var14] = var6[var13];
        }
        var11 = 4;
    }

    int var15       = (int)((float)var2->unknown_38_ / 4096.0f);
    Vector3i var16    = var6[var15];
    Vector3i var17    = var6[var15 + 1];
    fix32_t var18 = fix32_Divide(0x3000, Vector3fix_Distance(&var16, &var17));
    fix32_t var19   = FIX32_MULTIPLY(var18, var0);
    int var20  = var3 - 1;
    if (var2->unknown_3c_ < 0x1000) {
        var2->unknown_3c_ += 0xcc;
    }
    fix32_t var21   = FIX32_MULTIPLY(var19, var2->unknown_3c_);
    int var22    = 1;
    fix32_t var23 = FIX32_MULTIPLY((var20 << 12) - var5, 0x333);
    if (var23 < var21) {
        var21 = var23;
        if (func_02049ee8((unsigned char*)arg0)) {
            if (arg0->unknown_be_ != 0) {
                func_020494c0((Struct_02048f64_2*)arg0);
            }
            func_02033b58((Struct_02033b58*)arg0, 0);
            var22 = 0;
        }
    } else if (GetSubstructByte0x56_02049ee8((unsigned char*)actor)) {
        GameObject_SetMotionState((Obj02033b68*)actor, 1);
    }

    short var24 = var21 * 12;
    if (var24 < 0xc00) {
        var24 = 0xc00;
    } else if (var24 > 0x1400) {
        var24 = 0x1400;
    }
    ((Object3D*)arg0)->SetAnimationPlaybackSpeed(var24, 0);
    var2->unknown_38_ = var5 + var21;

    Vector3i var25;
    if (var23 > 4) {
        var25 = func_ov025_021ee488(var6, var11, var5 + var21);
    } else {
        var25 = var6[var20];
        if (func_02049ee8((unsigned char*)arg0) && (arg0->unknown_13c_->unknown_20_ & 0x40)) {
            func_02049520((Struct_02048f64_3*)arg0);
            func_02049a74((Struct_02048f64*)arg0);
        }
        func_02048c90((Struct_02048c90*)arg0);
        ((Object3D*)arg0)->SetAnimationPlaybackSpeed(0x1000, 500);
        func_02049390((unsigned char*)arg0, var2->unknown_1d_);
        if (func_02049ee8((unsigned char*)arg0) && arg0->unknown_be_ == 1) {
            func_02033b88((Struct_02010604*)arg0, 0);
        }
        func_020494c0((Struct_02048f64_2*)arg0);
        var22 = 0;
    }

    Vector3i current = actor->position;
    Vector3i delta;
    Vector3fix_Subtract(&target, &current, &delta);
    Vector3fix_Normalize(&delta, &delta);
    fix32_t angle   = fix32ReduceAngle0To2Pi(fix32_Atan2(delta.x, delta.z));
    actor->position = target;
    if (keepFacing) {
        GameObject_SetFacing((Obj02033834*)actor, angle);
    }
}
