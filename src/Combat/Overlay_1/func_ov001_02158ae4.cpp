#include <globaldefs.h>
#include <GameState/GameState.h>
#include <NitroSDK/Matrix.h>
#include <std_library_functions.h>

struct Struct_ov001_02158ae4 { int type; };
struct Struct_ov001_02158ae4_2 { Struct_ov001_02158ae4* head; Struct_ov001_02158ae4* tail; };
struct CameraState {
    char pad0[8];
    Struct_ov001_02158ae4_2 unknown_8_;
    Struct_ov001_02158ae4_2 unknown_10_;
    Struct_ov001_02158ae4_2 unknown_18_;
    Struct_ov001_02158ae4_2 unknown_20_;
    Struct_ov001_02158ae4_2 unknown_28_;
    Struct_ov001_02158ae4* unknown_30_;
    Struct_ov001_02158ae4* unknown_34_;
    char pad1[0x14];
    Vector3i position;
    Vector3i target;
    int yaw;
    int pitch;
    int roll;
    char pad2[0xc4];
    int unknown_134_;
    char pad3[0xc];
    Vector3i unknown_144_;
    Vector3i unknown_150_;
    char pad4[0x8c8];
    int unknown_a24_;
};
struct Camera { int field0; Vector3i position; Vector3i target; };
extern "C" void func_ov001_021588e4(CameraState*);
extern "C" void Camera_GetOrbit(unsigned char*, int*, int*, int*);
extern "C" Struct_ov001_02158ae4* func_ov001_02158e8c(CameraState*, Struct_ov001_02158ae4*, int);
extern "C" void Camera_SetOrbit(Camera*, int, int, int);
extern "C" void Camera_SetOrbitFromPosition(Camera*);
typedef int (*Type_01ff8b48_10)(Struct_ov001_02158ae4*, CameraState*);
extern Type_01ff8b48_10 data_ov001_02164c54[20];

// USA: func_ov001_02158ae4
extern "C" ARM void func_ov001_02158ae4(CameraState* state) {
    Struct_ov001_02158ae4* command;
    GameState* game = GameState::GetInstance();
    if (!game) { func_ov001_021588e4(state); return; }
    Camera* camera = (Camera*)game->GetCamera();
    if (!camera) { func_ov001_021588e4(state); return; }
    state->position = camera->position;
    state->target = camera->target;
    Camera_GetOrbit((unsigned char*)camera, &state->yaw, &state->pitch, &state->roll);
    Vector3i var3 = state->position;
    Vector3i var4 = state->target;
    int oldYaw = state->yaw;
    int oldPitch = state->pitch;
    int oldRoll = state->roll;
    if (state->unknown_134_) {
        memcpy(&state->position, &state->unknown_144_, sizeof(Vector3i));
        memcpy(&state->target, &state->unknown_150_, sizeof(Vector3i));
    }
    for (int queue = 0; queue < 5; queue++) {
        Struct_ov001_02158ae4** head;
        Struct_ov001_02158ae4** tail;
        switch (queue) {
        case 0: head = &state->unknown_8_.head; tail = &state->unknown_8_.tail; break;
        case 1: head = &state->unknown_10_.head; tail = &state->unknown_10_.tail; break;
        case 2: head = &state->unknown_18_.head; tail = &state->unknown_18_.tail; break;
        case 3: head = &state->unknown_20_.head; tail = &state->unknown_20_.tail; break;
        case 4: head = &state->unknown_28_.head; tail = &state->unknown_28_.tail; break;
        }
        command = *head;
        while (command) {
            if (command->type > 0 && command->type < 19) {
                int result = data_ov001_02164c54[command->type](command, state);
                if (result == 0) {
                } else if (result == 1) break;
                else if (result == 2) {
                    switch (queue) {
                    case 0: command = state->unknown_30_; break;
                    case 1: command = state->unknown_34_; break;
                    case 2: break;
                    }
                }
            } else {
                command = 0;
                break;
            }
            command = func_ov001_02158e8c(state, command, queue);
        }
        *head = command;
        if (!command) *tail = 0;
    }
    if (var4.x != state->target.x || var4.y != state->target.y || var4.z != state->target.z) camera->target = state->target;
    if (oldYaw != state->yaw || oldPitch != state->pitch || oldRoll != state->roll) Camera_SetOrbit(camera, state->yaw, state->pitch, state->roll);
    if (var3.x != state->position.x || var3.y != state->position.y || var3.z != state->position.z) {
        camera->position = state->position;
        Camera_SetOrbitFromPosition(camera);
    }
    if (state->unknown_a24_) {
        Camera_SetOrbit(camera, state->yaw, state->pitch, state->roll);
        state->unknown_a24_ = 0;
    }
}
