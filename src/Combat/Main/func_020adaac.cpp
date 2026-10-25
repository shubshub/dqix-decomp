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
void* GetField4328_0218d268(void*);
int GetField0x70_0202e7f0(void*);
int GetShortAt0x22e(ShortField0x22e_020968c4*);
int fix32ReduceAngle0To2Pi(int);
int fix32SignedAngleDistance(int, int);
extern "C" int func_020968d0(Struct_020968d0*, int*);
extern "C" void func_02033874(Struct_02033834*, int);
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
    if (arg0->unknown_134_ == 1 || arg0->unknown_134_ == 2) {
        Struct_020968d0* var5 = (Struct_020968d0*)func_ov017_0218d268(var1);
        if (arg0->unknown_134_ == 1) {
            int var6 = data_020e9118[arg0->unknown_1a0_ - 8];
            var2 = var6 + func_0202e7f0(var0);
        } else if (var5->unknown_224_) {
            var2 = func_020968c4((Struct_02038138*)var5);
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
        var7 = fix32ReduceAngle0To2Pi(var7);
        if (func_020968d0(var5, 0) || !var5->unknown_224_)
            func_02033874((Struct_02033834*)arg0, var7);
    }
    arg0->unknown_b2_ = arg0->unknown_144_;
    arg0->unknown_b4_ = arg0->unknown_144_;
}
