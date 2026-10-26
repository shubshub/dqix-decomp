#include <globaldefs.h>
#include "NitroSDK/Matrix.h"
#include "GameState/GameState.h"
#include "Input/Input.h"
#include "Resource/GameResources.h"

struct Struct_02040774_2;
struct Struct_02033834;
struct Struct_02038138;
struct Struct_020968d0 {
    char unknown_0_[0x224];
    unsigned char unknown_224_;
};
struct Struct_020adaac {
    char unknown_0_[0x44];
    Vector3i unknown_44_;
    char unknown_50_[4];
    int unknown_54_;
    char unknown_58_[0x5a];
    short unknown_b2_;
    short unknown_b4_;
    char unknown_b6_[0x7e];
    int unknown_134_;
    char unknown_138_[0xc];
    int unknown_144_;
    int unknown_148_;
    char unknown_14c_[0x18];
    Vector3i unknown_164_;
    char unknown_170_[4];
    Vector3i unknown_174_;
    char unknown_180_[0x1c];
    unsigned char unknown_19c_;
    char unknown_19d_[3];
    unsigned char unknown_1a0_;
};
extern "C" void Zone3D_GetInstance();
void SetFields0x44(Fields020407b4*, int, int, int);
void* GameResources_GetTouchWalk(void*);
int Camera_GetOrbitYaw(void*);
int TouchWalk_GetHeading(ShortField0x22e_020968c4*);
int fix32ReduceAngle0To2Pi(int);
int fix32SignedAngleDistance(int, int);
int CheckAndComputeDistance020968d0(Obj020968d0*, int*);
void GameObject_SnapFacing(Obj02033874*, int);
extern const int data_020e9118[8];

// USA: func_020adaac
extern "C" ARM void func_020adaac(SteeringObject* self) {
    void* camera = GameState::GetInstance()->GetCamera();
    void* manager = GetGameResources();
    int targetHeading;
    Zone3D_GetInstance();
    SetFields0x44((Fields020407b4*)self, self->position.x, 0xa000, self->position.z);
    Vector3i first = self->vector164;
    first.y = 0xa000;
    self->vector164 = first;
    Vector3i second = self->vector174;
    second.y = 0xa000;
    self->vector174 = second;
    self->mode = 0;
    if (g_keyManager.IsUpHeld() && g_keyManager.IsLeftHeld()) {
        arg0->unknown_134_ = 1;
        arg0->unknown_1a0_ = 12;
    } else if (g_keyManager.IsUpHeld() && g_keyManager.IsRightHeld()) {
        arg0->unknown_134_ = 1;
        arg0->unknown_1a0_ = 13;
    } else if (g_keyManager.IsDownHeld() && g_keyManager.IsLeftHeld()) {
        arg0->unknown_134_ = 1;
        arg0->unknown_1a0_ = 14;
    } else if (g_keyManager.IsDownHeld() && g_keyManager.IsRightHeld()) {
        arg0->unknown_134_ = 1;
        arg0->unknown_1a0_ = 15;
    } else if (g_keyManager.IsUpHeld()) {
        arg0->unknown_134_ = 1;
        arg0->unknown_1a0_ = 8;
    } else if (g_keyManager.IsDownHeld()) {
        arg0->unknown_134_ = 1;
        arg0->unknown_1a0_ = 9;
    } else if (g_keyManager.IsLeftHeld()) {
        arg0->unknown_134_ = 1;
        arg0->unknown_1a0_ = 10;
    } else if (g_keyManager.IsRightHeld()) {
        arg0->unknown_134_ = 1;
        arg0->unknown_1a0_ = 11;
    }
    if (g_touchInput.timeHeld_ > 5) arg0->unknown_134_ = 2;
    if (!arg0->unknown_19c_) {
        arg0->unknown_134_ = 0;
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
        int var7 = arg0->unknown_54_;
        var2 = fix32ReduceAngle0To2Pi(var2);
        var7 = fix32ReduceAngle0To2Pi(var7);
        int var8 = arg0->unknown_148_;
        int var9 = fix32SignedAngleDistance(var7, var2);
        if (var9 > 0) {
            if (var9 < var8) var7 = var2;
            else var7 += var8;
        } else if (var9 < 0) {
            if (-var9 < var8) var7 = var2;
            else var7 -= var8;
        }
        heading = fix32ReduceAngle0To2Pi(heading);
        if (CheckAndComputeDistance020968d0(target, 0) || !target->active)
            GameObject_SnapFacing((Obj02033874*)self, heading);
    }
    arg0->unknown_b2_ = arg0->unknown_144_;
    arg0->unknown_b4_ = arg0->unknown_144_;
}
