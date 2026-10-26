#include <globaldefs.h>
#include "NitroSDK/Matrix.h"
#include "GameState/GameState.h"
#include "Input/Input.h"
#include "Resource/GameResources.h"

struct Fields020407b4;
struct Obj02033874;
struct ShortField0x22e_020968c4;
struct Obj020968d0 {
    char unknown_0_[0x224];
    unsigned char active;
};
struct Struct_020adaac {
    char unknown_0_[0x44];
    Vector3i position;
    char unknown_50_[4];
    int heading;
    char unknown_58_[0x5a];
    short unknown_b2_;
    short unknown_b4_;
    char unknown_b6_[0x7e];
    int mode;
    char unknown_138_[0xc];
    int speed;
    int turnSpeed;
    char unknown_14c_[0x18];
    Vector3i unknown_164_;
    char unknown_170_[4];
    Vector3i unknown_174_;
    char unknown_180_[0x1c];
    unsigned char enabled;
    char unknown_19d_[3];
    unsigned char direction;
};
extern "C" void Zone3D_GetInstance();
extern "C" void func_020407b4(Fields020407b4*, int, int, int);
extern "C" void* GameResources_GetTouchWalk(void*);
extern "C" int Camera_GetOrbitYaw(void*);
extern "C" int TouchWalk_GetHeading(ShortField0x22e_020968c4*);
int fix32ReduceAngle0To2Pi(int);
int fix32SignedAngleDistance(int, int);
extern "C" int func_020968d0(Obj020968d0*, int*);
extern "C" void GameObject_SnapFacing(Obj02033874*, int);
extern const int data_020e9118[8];

// USA: func_020adaac
extern "C" ARM void func_020adaac(Struct_020adaac* self) {
    void* camera = GameState::GetInstance()->GetCamera();
    void* manager = GetGameResources();
    int targetHeading;
    Zone3D_GetInstance();
    func_020407b4((Fields020407b4*)self, self->position.x, 0xa000, self->position.z);
    Vector3i first = self->unknown_164_;
    first.y = 0xa000;
    self->unknown_164_ = first;
    Vector3i second = self->unknown_174_;
    second.y = 0xa000;
    self->unknown_174_ = second;
    self->mode = 0;
    if (g_keyManager.IsUpHeld() && g_keyManager.IsLeftHeld()) {
        self->mode = 1;
        self->direction = 12;
    } else if (g_keyManager.IsUpHeld() && g_keyManager.IsRightHeld()) {
        self->mode = 1;
        self->direction = 13;
    } else if (g_keyManager.IsDownHeld() && g_keyManager.IsLeftHeld()) {
        self->mode = 1;
        self->direction = 14;
    } else if (g_keyManager.IsDownHeld() && g_keyManager.IsRightHeld()) {
        self->mode = 1;
        self->direction = 15;
    } else if (g_keyManager.IsUpHeld()) {
        self->mode = 1;
        self->direction = 8;
    } else if (g_keyManager.IsDownHeld()) {
        self->mode = 1;
        self->direction = 9;
    } else if (g_keyManager.IsLeftHeld()) {
        self->mode = 1;
        self->direction = 10;
    } else if (g_keyManager.IsRightHeld()) {
        self->mode = 1;
        self->direction = 11;
    }
    if (g_touchInput.timeHeld_ > 5) self->mode = 2;
    if (!self->enabled) {
        self->mode = 0;
        return;
    }
    if (self->mode == 1 || self->mode == 2) {
        Obj020968d0* target = (Obj020968d0*)GameResources_GetTouchWalk(manager);
        if (self->mode == 1) {
            int offset = data_020e9118[self->direction - 8];
            targetHeading = offset + Camera_GetOrbitYaw(camera);
        } else if (target->active) {
            targetHeading = TouchWalk_GetHeading((ShortField0x22e_020968c4*)target);
        }
        int heading = self->heading;
        targetHeading = fix32ReduceAngle0To2Pi(targetHeading);
        heading = fix32ReduceAngle0To2Pi(heading);
        int turnSpeed = self->turnSpeed;
        int distance = fix32SignedAngleDistance(heading, targetHeading);
        if (distance > 0) {
            if (distance < turnSpeed) heading = targetHeading;
            else heading += turnSpeed;
        } else if (distance < 0) {
            if (-distance < turnSpeed) heading = targetHeading;
            else heading -= turnSpeed;
        }
        heading = fix32ReduceAngle0To2Pi(heading);
        if (func_020968d0(target, 0) || !target->active)
            GameObject_SnapFacing((Obj02033874*)self, heading);
    }
    self->unknown_b2_ = self->speed;
    self->unknown_b4_ = self->speed;
}
