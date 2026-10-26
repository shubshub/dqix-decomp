#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"
#include "NitroSDK/Matrix.h"
#include "Input/Input.h"

extern "C" void func_020968a4(unsigned char* src, int* out);

struct Camera0218d8cc {
    int field_0x0;
    Vector3fix position;
};

struct Struct_ov017_0218d8cc_2 {
    char pad0[0x224];
    unsigned char unknown_224_;
};

struct Struct_ov017_0218d8cc_3 {
#if defined(jpn)
    char pad0[0x4108];
#else
    char pad0[0x4328];
#endif
    Struct_ov017_0218d8cc_2* input;
#if defined(jpn)
    char unknown_410c_[0x4188 - 0x410c];
#else
    char unknown_432c_[0x4438 - 0x432c];
#endif
    Vector3fix unknown_4438_;
};

// USA: func_ov017_0218d8cc
extern "C" ARM void func_ov017_0218d8cc(Struct_ov017_0218d8cc_3* self) {
    GameState* gs = GameState::GetInstance();
    GameObject* player = gs->GetLeader();
    Camera0218d8cc* camera = (Camera0218d8cc*)gs->GetCamera();
    if (player == 0 || camera == 0) {
        return;
    }

    Vector3fix diff;
    Vector3fix_Subtract(&player->obj3D_.position_, &camera->position, &diff);

    Vector3fix forward;
    forward.x = diff.x;
    forward.y = 0;
    forward.z = diff.z;
    Vector3fix back;
    back.x = -diff.x;
    back.y = 0;
    back.z = -diff.z;
    Vector3fix left;
    left.x = diff.z;
    left.y = 0;
    left.z = -diff.x;
    Vector3fix right;
    right.x = -diff.z;
    right.y = 0;
    right.z = diff.x;

    self->unknown_4438_.x = 0;
    self->unknown_4438_.y = 0;
    self->unknown_4438_.z = 0;

    if (g_keyManager.TestKeysHeld(0x40)) {
        Vector3fix_Add(&self->unknown_4438_, &forward, &self->unknown_4438_);
    } else if (g_keyManager.TestKeysHeld(0x80)) {
        Vector3fix_Add(&self->unknown_4438_, &back, &self->unknown_4438_);
    }

    if (g_keyManager.TestKeysHeld(0x20)) {
        Vector3fix_Add(&self->unknown_4438_, &left, &self->unknown_4438_);
    } else if (g_keyManager.TestKeysHeld(0x10)) {
        Vector3fix_Add(&self->unknown_4438_, &right, &self->unknown_4438_);
    }

    if (self->input->unknown_224_) {
        func_020968a4((unsigned char*)self->input, &self->unknown_4438_.x);
    }
    Vector3fix_Normalize(&self->unknown_4438_, &self->unknown_4438_);
}
