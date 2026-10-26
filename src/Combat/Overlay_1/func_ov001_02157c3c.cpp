#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Graphics/Vector.h"

struct Struct_ov001_02157c3c {
    int field_0x0;
    Vector3fix eye;
    Vector3fix target;
    int duration;
    int unknown_20_;
    int unknown_24_;
};

struct Struct_ov001_02157c3c_2 {
    char unknown_0_[0x38];
    int timer;
    char unknown_3c_[0x10];
    Vector3fix eye;
    Vector3fix target;
    char unknown_64_[0x50];
    Vector3fix unknown_b4_;
    Vector3fix unknown_c0_;
    char unknown_cc_[0x44];
    Vector3fix unknown_110_;
    Vector3fix unknown_11c_;
    char unknown_128_[0x8fc];
    int unknown_a24_;
};

// USA: func_ov001_02157c3c
extern "C" ARM int func_ov001_02157c3c(Struct_ov001_02157c3c* cmd, Struct_ov001_02157c3c_2* cam) {
    GameState* gameState = GameState::GetInstance();
    int scale = gameState->GetTickCount() << 12;
    int duration = cmd->duration;
    if (duration == 0) {
        memcpy(&cam->eye, &cmd->eye, sizeof(Vector3fix));
        memcpy(&cam->target, &cmd->target, sizeof(Vector3fix));
        cam->timer = 0;
        return 0;
    }
    if (cam->timer <= 0) {
        Vector3fix diff;
        int var4 = duration << 13;
        Vector3fix_Subtract(&cmd->eye, &cam->eye, &diff);
        cam->unknown_b4_.x = fix32_Divide(diff.x, var4);
        cam->unknown_b4_.y = fix32_Divide(diff.y, var4);
        cam->unknown_b4_.z = fix32_Divide(diff.z, var4);
        Vector3fix_Subtract(&cmd->target, &cam->target, &diff);
        cam->unknown_c0_.x = fix32_Divide(diff.x, var4);
        cam->unknown_c0_.y = fix32_Divide(diff.y, var4);
        cam->unknown_c0_.z = fix32_Divide(diff.z, var4);
        memcpy(&cam->unknown_110_, &cam->unknown_b4_, sizeof(Vector3fix));
        memcpy(&cam->unknown_11c_, &cam->unknown_c0_, sizeof(Vector3fix));
        cam->unknown_a24_ = cmd->unknown_20_;
    }
    Vector3fix var5 = cam->unknown_b4_;
    Vector3fix var6 = cam->unknown_c0_;
    Vector3fixMultiplyScalar(&var5, scale, &var5);
    Vector3fixMultiplyScalar(&var6, scale, &var6);
    Vector3fix_Add(&cam->eye, &var5, &cam->eye);
    Vector3fix_Add(&cam->target, &var6, &cam->target);
    cam->unknown_a24_ = cmd->unknown_20_;
    cam->timer += gameState->GetTickCount();
    if (cam->timer >= cmd->duration << 1) {
        if (cmd->unknown_24_ != 0) {
            memcpy(&cam->eye, &cmd->eye, sizeof(Vector3fix));
            memcpy(&cam->target, &cmd->target, sizeof(Vector3fix));
        }
        cam->timer = 0;
        return 0;
    }
    return 1;
}
