#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"
#include "NitroSDK/Matrix.h"
#include "Input/Input.h"

extern "C" void func_020968a4(unsigned char* arg0, int* arg1);

struct Struct_ov017_0218d8cc {
    int unknown_0_;
    Vector3fix unknown_4_;
};

struct Struct_ov017_0218d8cc_2 {
    char unknown_0_[0x224];
    unsigned char unknown_224_;
};

struct Struct_ov017_0218d8cc_3 {
#if defined(jpn)
    char unknown_0_[0x4108];
#else
    char unknown1_0_[0x4328];
#endif
    Struct_ov017_0218d8cc_2* unknown_4328_;
#if defined(jpn)
    char unknown_410c_[0x4188 - 0x410c];
#else
    char unknown_432c_[0x4438 - 0x432c];
#endif
    Vector3fix unknown_4438_;
};

// USA: func_ov017_0218d8cc
extern "C" ARM void func_ov017_0218d8cc(Battle0218d8cc* self) {
    GameState* gs = GameState::GetInstance();
    GameObject* player = gs->GetLeader();
    Camera0218d8cc* camera = (Camera0218d8cc*)gs->GetCamera();
    if (player == 0 || camera == 0) {
        return;
    }

    Vector3fix var3;
    Vector3fix_Subtract(&var1->obj3D_.position_, &var2->unknown_4_, &var3);

    Vector3fix var4;
    var4.x = var3.x;
    var4.y = 0;
    var4.z = var3.z;
    Vector3fix var5;
    var5.x = -var3.x;
    var5.y = 0;
    var5.z = -var3.z;
    Vector3fix var6;
    var6.x = var3.z;
    var6.y = 0;
    var6.z = -var3.x;
    Vector3fix var7;
    var7.x = -var3.z;
    var7.y = 0;
    var7.z = var3.x;

    arg0->unknown_4438_.x = 0;
    arg0->unknown_4438_.y = 0;
    arg0->unknown_4438_.z = 0;

    if (g_keyManager.TestKeysHeld(0x40)) {
        Vector3fix_Add(&arg0->unknown_4438_, &var4, &arg0->unknown_4438_);
    } else if (g_keyManager.TestKeysHeld(0x80)) {
        Vector3fix_Add(&arg0->unknown_4438_, &var5, &arg0->unknown_4438_);
    }

    if (g_keyManager.TestKeysHeld(0x20)) {
        Vector3fix_Add(&arg0->unknown_4438_, &var6, &arg0->unknown_4438_);
    } else if (g_keyManager.TestKeysHeld(0x10)) {
        Vector3fix_Add(&arg0->unknown_4438_, &var7, &arg0->unknown_4438_);
    }

    if (arg0->unknown_4328_->unknown_224_) {
        func_020968a4((unsigned char*)arg0->unknown_4328_, &arg0->unknown_4438_.x);
    }
    Vector3fix_Normalize(&arg0->unknown_4438_, &arg0->unknown_4438_);
}
