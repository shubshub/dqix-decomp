#include <globaldefs.h>
#include "NitroSDK/Matrix.h"
#include "World/Object3D.h"
#include "GameState/GameState.h"
#include "Input/Input.h"
#include "Resource/Brightness.h"

struct Struct_020a212c {
    int unknown_0_;
    Vector3i unknown_4_;
    Vector3i unknown_10_;
};

struct Struct_020a212c_2 {
    char unknown_0_[0x10];
    Vector3i unknown_10_;
    char unknown_1c_[0x70 - 0x1c];
    Vector3i unknown_70_;
    char unknown_7c_[0x21c - 0x7c];
    short unknown_21c_;
    char unknown_21e_[2];
    Vector3i unknown_220_;
    Vector3i unknown_22c_;
    int unknown_238_;
    int unknown_23c_;
    int unknown_240_;
    unsigned char unknown_244_;
    unsigned char unknown_245_;
    short unknown_246_;
    Struct_020a212c unknown_248_;
    char unknown_264_[0x2c4 - 0x264];
    unsigned char unknown_2c4_;
    char unknown_2c5_;
    short unknown_2c6_;
};

int GetField0x70_0202e7f0(void* obj);
int IsBrightnessTransitionActive(GameResources* resources);
int fix32SignedAngleDistance(int a, int b);
int fix32abs(int x);
int fix32ReduceAngle0To2Pi(int angle);
void ApplyField0x70Tail(struct GlobalObj0202e6a8* obj, int value);
void ClampField74BySign(struct CamState0202e6c0* obj, int value);
void SetField78Clamped0202e71c(struct Obj0202e71c* obj, int value);
int Vec3Ease_IsRunning(int* obj);
void DispatchMemberFn020a0dec(struct DispatchObj020a0dec* obj);
void CopyVec3ToField0x10AndCall0202e5d8_0202ec5c(char* obj, int* vec);
void Vector3fixMultiplyScalar(const Vector3i* in, int scale, Vector3i* out);
extern "C" void __clear(void* arg0, int arg1);
extern "C" void Vector3fix_Add(const Vector3i* arg0, const Vector3i* arg1, Vector3i* arg2);
extern "C" void Vector3fix_Subtract(const Vector3i* arg0, const Vector3i* arg1, Vector3i* arg2);
extern "C" int Vector3fix_Length(const Vector3i* arg0);
extern "C" int func_020a299c(struct Struct_020a212c_2* arg0, const Vector3i* arg1, const Object3D* arg2);
extern "C" void func_0202eab8(void* arg0);
extern "C" void func_0202e5d8(void* arg0, int arg1, int arg2, int arg3);

static inline int inline_02061c04_5(int arg0, int arg1) {
    return (int)(((long long)arg0 * arg1 + 0x800) >> 12);
}

// USA: func_020a212c
extern "C" ARM void func_020a212c(BattleCamera* self, int checkInput) {
    GameState* gs = GameState::GetInstance();
    GameObject* target = gs->GetGameObjectByIndex(self->followIndex);
    GameResources* res = gs->GetResources();
    int angle = GetField0x70_0202e7f0(self);
    int left = 0;
    int right = 0;
    if (checkInput) {
        left = g_keyManager.TestKeysHeld(0x200);
        right = g_keyManager.TestKeysHeld(0x100);
    }
    if (IsBrightnessTransitionActive(var2) || IsBrightnessOutsideValidRange((GameResources*)var2, false)) {
        var4 = 0;
        var5 = 0;
    }
    if (arg0->unknown_244_ & 2) {
        var4 = 0;
        var5 = 0;
    }
    if (arg0->unknown_244_ & 0x10) {
        var4 = 0;
        var5 = 0;
    }
    if (arg0->unknown_23c_ == 0) {
        var4 = 0;
        var5 = 0;
    }
    if (arg0->unknown_240_ == 0) {
        var4 = 0;
        var5 = 0;
    }
    if (arg0->unknown_245_ & 2) {
        if (var4 == 0 && var5 == 0 && var3 == arg0->unknown_246_) {
            arg0->unknown_245_ &= ~2;
        }
        var4 = 0;
        var5 = 0;
    }
    unsigned int var6 = var0->GetEffectiveDeltaTime();
    if (arg0->unknown_245_ & 2) {
        int var7 = fix32SignedAngleDistance(var3, arg0->unknown_246_);
        int var8 = fix32abs(var7);
        int var9 = (int)(4096.0f * (0.00225f * (float)var6));
        if (var9 > var8 >> 1) {
            var9 = var8 >> 1;
        }
        if (var8 < 0x28) {
            func_0202e6a8((struct Struct_0202e6a8*)arg0, arg0->unknown_246_);
            arg0->unknown_220_.x = arg0->unknown_246_;
        } else {
            if (var7 < 0) {
                var9 = -var9;
            }
            int var10 = fix32ReduceAngle0To2Pi(var3 + var9);
            func_0202e6a8((struct Struct_0202e6a8*)arg0, var10);
            arg0->unknown_220_.x = var10;
        }
    } else if (var5 && var4) {
        arg0->unknown_245_ |= 2;
        func_0202e6c0((struct Struct_0202e6c0*)arg0, arg0->unknown_220_.y);
        func_0202e71c((struct Struct_0202e71c*)arg0, arg0->unknown_220_.z);
    } else if (var4) {
        var3 = fix32ReduceAngle0To2Pi(var3 + (int)(4096.0f * (0.0015f * (float)var6)));
        if (var3 > 0xc91 && var3 < 0x57f7) {
            var3 = 0xc91;
        }
        func_0202e6a8((struct Struct_0202e6a8*)arg0, var3);
        arg0->unknown_220_.x = var3;
    } else if (var5) {
        var3 = fix32ReduceAngle0To2Pi(var3 - (int)(4096.0f * (0.0015f * (float)var6)));
        if (var3 > 0xc91 && var3 < 0x57f7) {
            var3 = 0x57f7;
        }
        func_0202e6a8((struct Struct_0202e6a8*)arg0, var3);
        arg0->unknown_220_.x = var3;
    }

    Vector3i pos;
    int blended = 0;
    __clear(&pos, 0xc);
    if (target) {
        pos = target->obj3D_.position_;
        pos.y += target->obj3D_.GetHeight() / 2;
        Vector3fix_Add(&pos, &self->offset, &pos);
        Vector3i eye = pos;
        if (Vec3Ease_IsRunning(&self->dispatch.active)) {
            self->dispatch.source = eye;
            DispatchMemberFn020a0dec((struct DispatchObj020a0dec*)&self->dispatch);
            eye = self->dispatch.result;
        }
        func_0202ec5c((char*)arg0, (int*)&var13);
        var12 = func_020a299c(arg0, &var11, &var1->obj3D_);
    }
    if (arg0->unknown_245_ & 0x10) {
        Vector3fixMultiplyScalar(&arg0->unknown_22c_, 0xccc, &arg0->unknown_22c_);
        if (Vector3fix_Length(&arg0->unknown_22c_) < 0x28) {
            arg0->unknown_22c_.x = 0;
            arg0->unknown_22c_.y = 0;
            arg0->unknown_22c_.z = 0;
            arg0->unknown_245_ &= ~0x10;
        }
    }
    if (arg0->unknown_2c4_ == 0) {
        return;
    }
    Vector3i var14 = arg0->unknown_220_;
    if (var12) {
        var14 = arg0->unknown_70_;
    }
    int var15 = 1;
    if (arg0->unknown_2c4_ == 1) {
        arg0->unknown_2c6_ += (0x1000 - arg0->unknown_2c6_) / 10;
    } else if (arg0->unknown_2c4_ == 2) {
        arg0->unknown_2c6_ += -arg0->unknown_2c6_ / 10;
        if (arg0->unknown_2c6_ < 0x28) {
            arg0->unknown_2c4_ = 0;
            func_0202e71c((struct Struct_0202e71c*)arg0, var14.z);
            func_0202e6c0((struct Struct_0202e6c0*)arg0, var14.y);
            var15 = 0;
        }
    }
    if (var15 == 0) {
        return;
    }
    if (var12) {
        Vector3i var16 = arg0->unknown_10_;
        var16.y = var11.y + inline_02061c04_5(var16.y - var11.y, 0x1000 - arg0->unknown_2c6_);
        func_0202ec5c((char*)arg0, (int*)&var16);
        func_0202eab8(arg0);
        var14 = arg0->unknown_70_;
    }
    if (arg0->unknown_2c6_ != 0) {
        Vector3i var17 = arg0->unknown_10_;
        Vector3i var18 = var1->obj3D_.position_;
        var18.y += var1->obj3D_.GetHeight() / 2;
        Vector3i var19;
        Vector3fix_Subtract(&var17, &var18, &var19);
        Vector3fixMultiplyScalar(&var19, arg0->unknown_2c6_, &var19);
        Vector3fix_Subtract(&var17, &var19, &var17);
        func_0202ec5c((char*)arg0, (int*)&var17);
    }
    int var20 = 0x1000 - arg0->unknown_2c6_;
    func_0202e5d8(arg0, var14.x, inline_02061c04_5(var14.y - 0x34cc, var20) + 0x34cc, inline_02061c04_5(var14.z - 0x6000, var20) + 0x6000);
}
