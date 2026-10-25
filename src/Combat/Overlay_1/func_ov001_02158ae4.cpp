#include <globaldefs.h>
#include <GameState/GameState.h>
#include <NitroSDK/Matrix.h>
#include <std_library_functions.h>

struct Struct_ov001_02158ae4 { int unknown_0_; };
struct Struct_ov001_02158ae4_2 { Struct_ov001_02158ae4* unknown_0_; Struct_ov001_02158ae4* unknown_4_; };
struct Struct_ov001_02158ae4_3 {
    char unknown_0_[8];
    Struct_ov001_02158ae4_2 unknown_8_;
    Struct_ov001_02158ae4_2 unknown_10_;
    Struct_ov001_02158ae4_2 unknown_18_;
    Struct_ov001_02158ae4_2 unknown_20_;
    Struct_ov001_02158ae4_2 unknown_28_;
    Struct_ov001_02158ae4* unknown_30_;
    Struct_ov001_02158ae4* unknown_34_;
    char unknown_38_[0x14];
    Vector3i unknown_4c_;
    Vector3i unknown_58_;
    int unknown_64_;
    int unknown_68_;
    int unknown_6c_;
    char unknown_70_[0xc4];
    int unknown_134_;
    char unknown_138_[0xc];
    Vector3i unknown_144_;
    Vector3i unknown_150_;
    char unknown_15c_[0x8c8];
    int unknown_a24_;
};
struct Camera { int field0; Vector3i position; Vector3i target; };
extern "C" void func_ov001_021588e4(CameraState*);
void ReadFields0x70To0x78_0202e7d4(unsigned char*, int*, int*, int*);
extern "C" CameraCommand* func_ov001_02158e8c(CameraState*, CameraCommand*, int);
extern "C" void func_0202e5d8(Camera*, int, int, int);
extern "C" void func_0202eab8(Camera*);
typedef int (*CameraCommandHandler)(CameraCommand*, CameraState*);
extern CameraCommandHandler data_ov001_02164c54[20];

// USA: func_ov001_02158ae4
extern "C" ARM void func_ov001_02158ae4(CameraState* state) {
    CameraCommand* command;
    GameState* game = GameState::GetInstance();
    if (!game) { func_ov001_021588e4(state); return; }
    Camera* camera = (Camera*)game->GetCamera();
    if (!camera) { func_ov001_021588e4(state); return; }
    state->position = camera->position;
    state->target = camera->target;
    ReadFields0x70To0x78_0202e7d4((unsigned char*)camera, &state->yaw, &state->pitch, &state->roll);
    Vector3i oldPosition = state->position;
    Vector3i oldTarget = state->target;
    int oldYaw = state->yaw;
    int oldPitch = state->pitch;
    int oldRoll = state->roll;
    if (state->overrideEnabled) {
        memcpy(&state->position, &state->overridePosition, sizeof(Vector3i));
        memcpy(&state->target, &state->overrideTarget, sizeof(Vector3i));
    }
    for (int var8 = 0; var8 < 5; var8++) {
        Struct_ov001_02158ae4** var9;
        Struct_ov001_02158ae4** var10;
        switch (var8) {
        case 0: var9 = &arg0->unknown_8_.unknown_0_; var10 = &arg0->unknown_8_.unknown_4_; break;
        case 1: var9 = &arg0->unknown_10_.unknown_0_; var10 = &arg0->unknown_10_.unknown_4_; break;
        case 2: var9 = &arg0->unknown_18_.unknown_0_; var10 = &arg0->unknown_18_.unknown_4_; break;
        case 3: var9 = &arg0->unknown_20_.unknown_0_; var10 = &arg0->unknown_20_.unknown_4_; break;
        case 4: var9 = &arg0->unknown_28_.unknown_0_; var10 = &arg0->unknown_28_.unknown_4_; break;
        }
        var0 = *var9;
        while (var0) {
            if (var0->unknown_0_ > 0 && var0->unknown_0_ < 19) {
                int var11 = data_ov001_02164c54[var0->unknown_0_](var0, arg0);
                if (var11 == 0) {
                } else if (var11 == 1) break;
                else if (var11 == 2) {
                    switch (var8) {
                    case 0: var0 = arg0->unknown_30_; break;
                    case 1: var0 = arg0->unknown_34_; break;
                    case 2: break;
                    }
                }
            } else {
                var0 = 0;
                break;
            }
            var0 = func_ov001_02158e8c(arg0, var0, var8);
        }
        *var9 = var0;
        if (!var0) *var10 = 0;
    }
    if (var4.x != arg0->unknown_58_.x || var4.y != arg0->unknown_58_.y || var4.z != arg0->unknown_58_.z) var2->unknown_10_ = arg0->unknown_58_;
    if (var5 != arg0->unknown_64_ || var6 != arg0->unknown_68_ || var7 != arg0->unknown_6c_) func_0202e5d8(var2, arg0->unknown_64_, arg0->unknown_68_, arg0->unknown_6c_);
    if (var3.x != arg0->unknown_4c_.x || var3.y != arg0->unknown_4c_.y || var3.z != arg0->unknown_4c_.z) {
        var2->unknown_4_ = arg0->unknown_4c_;
        func_0202eab8(var2);
    }
    if (arg0->unknown_a24_) {
        func_0202e5d8(var2, arg0->unknown_64_, arg0->unknown_68_, arg0->unknown_6c_);
        arg0->unknown_a24_ = 0;
    }
}
