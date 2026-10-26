#include <globaldefs.h>
#include "NitroSDK/Matrix.h"
#include "World/Object3D.h"
#include "GameState/GameState.h"
#include "Input/Input.h"
#include "Resource/Brightness.h"

struct Struct_020a212c {
    int active;
    Vector3i result;
    Vector3i source;
};

struct BattleCamera {
    char pad0[0x10];
    Vector3i eye;
    char unknown_1c_[0x70 - 0x1c];
    Vector3i target;
    char unknown_7c_[0x21c - 0x7c];
    short unknown_21c_;
    char unknown_21e_[2];
    Vector3i angles;
    Vector3i offset;
    int unknown_238_;
    int unknown_23c_;
    int unknown_240_;
    unsigned char unknown_244_;
    unsigned char unknown_245_;
    short homeAngle;
    Struct_020a212c dispatch;
    char unknown_264_[0x2c4 - 0x264];
    unsigned char unknown_2c4_;
    char unknown_2c5_;
    short zoom;
};

extern "C" int Camera_GetOrbitYaw(void* obj);
int IsBrightnessTransitionActive(GameResources* resources);
int fix32SignedAngleDistance(int a, int b);
int fix32abs(int x);
int fix32ReduceAngle0To2Pi(int angle);
extern "C" void Camera_SetOrbitYaw(struct GlobalObj0202e6a8* obj, int value);
extern "C" void Camera_SetOrbitHeight(struct CamState0202e6c0* obj, int value);
extern "C" void Camera_SetOrbitDistance(struct Obj0202e71c* obj, int value);
extern "C" int Vec3Ease_IsRunning(int* obj);
extern "C" void Vec3Ease_Step(struct DispatchObj020a0dec* obj);
extern "C" void Camera_SetTargetKeepOrbit(char* obj, int* vec);
void Vector3fixMultiplyScalar(const Vector3i* in, int scale, Vector3i* out);
extern "C" void __clear(void* ptr, int size);
extern "C" void Vector3fix_Add(const Vector3i* a, const Vector3i* b, Vector3i* out);
extern "C" void Vector3fix_Subtract(const Vector3i* a, const Vector3i* b, Vector3i* out);
extern "C" int Vector3fix_Length(const Vector3i* v);
extern "C" int func_020a299c(struct BattleCamera* obj, const Vector3i* v, const Object3D* target);
extern "C" void Camera_SetOrbitFromPosition(void* obj);
extern "C" void Camera_SetOrbit(void* obj, int x, int y, int z);

static inline int FxMul(int a, int b) {
    return (int)(((long long)a * b + 0x800) >> 12);
}

// USA: func_020a212c
extern "C" ARM void func_020a212c(BattleCamera* self, int arg1) {
    GameState* gs = GameState::GetInstance();
    GameObject* target = gs->GetGameObjectByIndex(self->unknown_21c_);
    GameResources* res = gs->GetResources();
    int angle = Camera_GetOrbitYaw(self);
    int left = 0;
    int right = 0;
    if (arg1) {
        left = g_keyManager.TestKeysHeld(0x200);
        right = g_keyManager.TestKeysHeld(0x100);
    }
    if (IsBrightnessTransitionActive(res) || IsScreenFullyFaded((GameResources*)res, false)) {
        left = 0;
        right = 0;
    }
    if (self->unknown_244_ & 2) {
        left = 0;
        right = 0;
    }
    if (self->unknown_244_ & 0x10) {
        left = 0;
        right = 0;
    }
    if (self->unknown_23c_ == 0) {
        left = 0;
        right = 0;
    }
    if (self->unknown_240_ == 0) {
        left = 0;
        right = 0;
    }
    if (self->unknown_245_ & 2) {
        if (left == 0 && right == 0 && angle == self->homeAngle) {
            self->unknown_245_ &= ~2;
        }
        left = 0;
        right = 0;
    }
    unsigned int var6 = gs->GetEffectiveDeltaTime();
    if (self->unknown_245_ & 2) {
        int dist = fix32SignedAngleDistance(angle, self->homeAngle);
        int var8 = fix32abs(dist);
        int step = (int)(4096.0f * (0.00225f * (float)var6));
        if (step > var8 >> 1) {
            step = var8 >> 1;
        }
        if (var8 < 0x28) {
            Camera_SetOrbitYaw((struct GlobalObj0202e6a8*)self, self->homeAngle);
            self->angles.x = self->homeAngle;
        } else {
            if (dist < 0) {
                step = -step;
            }
            int a = fix32ReduceAngle0To2Pi(angle + step);
            Camera_SetOrbitYaw((struct GlobalObj0202e6a8*)self, a);
            self->angles.x = a;
        }
    } else if (right && left) {
        self->unknown_245_ |= 2;
        Camera_SetOrbitHeight((struct CamState0202e6c0*)self, self->angles.y);
        Camera_SetOrbitDistance((struct Obj0202e71c*)self, self->angles.z);
    } else if (left) {
        angle = fix32ReduceAngle0To2Pi(angle + (int)(4096.0f * (0.0015f * (float)var6)));
        if (angle > 0xc91 && angle < 0x57f7) {
            angle = 0xc91;
        }
        Camera_SetOrbitYaw((struct GlobalObj0202e6a8*)self, angle);
        self->angles.x = angle;
    } else if (right) {
        angle = fix32ReduceAngle0To2Pi(angle - (int)(4096.0f * (0.0015f * (float)var6)));
        if (angle > 0xc91 && angle < 0x57f7) {
            angle = 0x57f7;
        }
        Camera_SetOrbitYaw((struct GlobalObj0202e6a8*)self, angle);
        self->angles.x = angle;
    }

    Vector3i pos;
    int var12 = 0;
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
        var12 = func_020a299c(self, &pos, &target->obj3D_);
    }
    if (self->unknown_245_ & 0x10) {
        Vector3fixMultiplyScalar(&self->offset, 0xccc, &self->offset);
        if (Vector3fix_Length(&self->offset) < 0x28) {
            self->offset.x = 0;
            self->offset.y = 0;
            self->offset.z = 0;
            self->unknown_245_ &= ~0x10;
        }
    }
    if (self->unknown_2c4_ == 0) {
        return;
    }
    Vector3i look = self->angles;
    if (var12) {
        look = self->target;
    }
    int update = 1;
    if (self->unknown_2c4_ == 1) {
        self->zoom += (0x1000 - self->zoom) / 10;
    } else if (self->unknown_2c4_ == 2) {
        self->zoom += -self->zoom / 10;
        if (self->zoom < 0x28) {
            self->unknown_2c4_ = 0;
            Camera_SetOrbitDistance((struct Obj0202e71c*)self, look.z);
            Camera_SetOrbitHeight((struct CamState0202e6c0*)self, look.y);
            update = 0;
        }
    }
    if (update == 0) {
        return;
    }
    if (var12) {
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
