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

int Camera_GetOrbitYaw(void* obj);
int IsBrightnessTransitionActive(GameResources* resources);
int fix32SignedAngleDistance(int a, int b);
int fix32abs(int x);
int fix32ReduceAngle0To2Pi(int angle);
void Camera_SetOrbitYaw(struct GlobalObj0202e6a8* obj, int value);
void Camera_SetOrbitHeight(struct CamState0202e6c0* obj, int value);
void Camera_SetOrbitDistance(struct Obj0202e71c* obj, int value);
int Vec3Ease_IsRunning(int* obj);
void Vec3Ease_Step(struct DispatchObj020a0dec* obj);
void Camera_SetTargetKeepOrbit(char* obj, int* vec);
void Vector3fixMultiplyScalar(const Vector3i* in, int scale, Vector3i* out);
extern "C" void __clear(void* ptr, int size);
extern "C" void Vector3fix_Add(const Vector3i* a, const Vector3i* b, Vector3i* out);
extern "C" void Vector3fix_Subtract(const Vector3i* a, const Vector3i* b, Vector3i* out);
extern "C" int Vector3fix_Length(const Vector3i* v);
extern "C" int func_020a299c(struct BattleCamera* obj, const Vector3i* v, const Object3D* target);
extern "C" void Camera_SetOrbitFromPosition(void* obj);
extern "C" void Camera_SetOrbit(void* obj, int x, int y, int z);

static inline int inline_02061c04_5(int arg0, int arg1) {
    return (int)(((long long)arg0 * arg1 + 0x800) >> 12);
}

// USA: func_020a212c
extern "C" ARM void func_020a212c(BattleCamera* self, int checkInput) {
    GameState* gs = GameState::GetInstance();
    GameObject* target = gs->GetGameObjectByIndex(self->followIndex);
    GameResources* res = gs->GetResources();
    int angle = Camera_GetOrbitYaw(self);
    int left = 0;
    int right = 0;
    if (checkInput) {
        left = g_keyManager.TestKeysHeld(0x200);
        right = g_keyManager.TestKeysHeld(0x100);
    }
    if (IsBrightnessTransitionActive(res) || IsScreenFullyFaded((GameResources*)res, false)) {
        left = 0;
        right = 0;
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
        if (adist < 0x28) {
            Camera_SetOrbitYaw((struct GlobalObj0202e6a8*)self, self->homeAngle);
            self->angles.x = self->homeAngle;
        } else {
            if (var7 < 0) {
                var9 = -var9;
            }
            int a = fix32ReduceAngle0To2Pi(angle + step);
            Camera_SetOrbitYaw((struct GlobalObj0202e6a8*)self, a);
            self->angles.x = a;
        }
    } else if (right && left) {
        self->flags245 |= 2;
        Camera_SetOrbitHeight((struct CamState0202e6c0*)self, self->angles.y);
        Camera_SetOrbitDistance((struct Obj0202e71c*)self, self->angles.z);
    } else if (left) {
        angle = fix32ReduceAngle0To2Pi(angle + (int)(4096.0f * (0.0015f * (float)dt)));
        if (angle > 0xc91 && angle < 0x57f7) {
            angle = 0xc91;
        }
        Camera_SetOrbitYaw((struct GlobalObj0202e6a8*)self, angle);
        self->angles.x = angle;
    } else if (right) {
        angle = fix32ReduceAngle0To2Pi(angle - (int)(4096.0f * (0.0015f * (float)dt)));
        if (angle > 0xc91 && angle < 0x57f7) {
            angle = 0x57f7;
        }
        Camera_SetOrbitYaw((struct GlobalObj0202e6a8*)self, angle);
        self->angles.x = angle;
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
            Vec3Ease_Step((struct DispatchObj020a0dec*)&self->dispatch);
            eye = self->dispatch.result;
        }
        Camera_SetTargetKeepOrbit((char*)self, (int*)&eye);
        blended = func_020a299c(self, &pos, &target->obj3D_);
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
    int update = 1;
    if (self->zoomMode == 1) {
        self->zoom += (0x1000 - self->zoom) / 10;
    } else if (self->zoomMode == 2) {
        self->zoom += -self->zoom / 10;
        if (self->zoom < 0x28) {
            self->zoomMode = 0;
            Camera_SetOrbitDistance((struct Obj0202e71c*)self, look.z);
            Camera_SetOrbitHeight((struct CamState0202e6c0*)self, look.y);
            update = 0;
        }
    }
    if (var15 == 0) {
        return;
    }
    if (blended) {
        Vector3i eye = self->eye;
        eye.y = pos.y + FxMul(eye.y - pos.y, 0x1000 - self->zoom);
        Camera_SetTargetKeepOrbit((char*)self, (int*)&eye);
        Camera_SetOrbitFromPosition(self);
        look = self->target;
    }
    if (self->zoom != 0) {
        Vector3i eye = self->eye;
        Vector3i center = target->obj3D_.position_;
        center.y += target->obj3D_.GetHeight() / 2;
        Vector3i delta;
        Vector3fix_Subtract(&eye, &center, &delta);
        Vector3fixMultiplyScalar(&delta, self->zoom, &delta);
        Vector3fix_Subtract(&eye, &delta, &eye);
        Camera_SetTargetKeepOrbit((char*)self, (int*)&eye);
    }
    int t = 0x1000 - self->zoom;
    Camera_SetOrbit(self, look.x, FxMul(look.y - 0x34cc, t) + 0x34cc, FxMul(look.z - 0x6000, t) + 0x6000);
}
