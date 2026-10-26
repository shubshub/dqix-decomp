#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct Struct_ov001_021594cc { int field_0; Vector3fix angles; int duration; int unknown_14_; };
struct Struct_ov001_021594cc_2 {
    char field_0[0x4c];
    int elapsed;
    char unknown_50_[0x30];
    Vector3fix angles;
    char unknown_8c_[0x14];
    Vector3fix unknown_a0_;
};

inline int inline_ov001_021594cc(int arg0, int tick) { return (int)(((long long)arg0 * tick + 0x800) >> 12); }

// USA: func_ov001_021594cc
extern "C" ARM int func_ov001_021594cc(Struct_ov001_021594cc* request, Struct_ov001_021594cc_2* state) {
    GameState* game = GameState::GetInstance();
    int tick = game->GetTickCount() << 12;
    if (request->duration < 0) {
        state->angles.x += request->angles.x;
        state->angles.y += request->angles.y;
        state->angles.z += request->angles.z;
        if (state->angles.x > 0x6487) state->angles.x -= 0x6487;
        else if (state->angles.x <= 0) state->angles.x += 0x6487;
        if (state->angles.y > 0x6487) state->angles.y -= 0x6487;
        else if (state->angles.y <= 0) state->angles.y += 0x6487;
        if (state->angles.z > 0x6487) state->angles.z -= 0x6487;
        else if (state->angles.z <= 0) state->angles.z += 0x6487;
    } else {
        if (state->elapsed >= request->duration * 2) {
            memcpy(&state->angles, &request->angles, 12);
            state->elapsed = 0;
            return 0;
        }
        if (state->elapsed <= 0) {
            int duration = request->duration << 13;
            int var3;
            if (request->unknown_14_) var3 = state->angles.x - request->angles.x;
            else var3 = request->angles.x - state->angles.x;
            if (var3 > 0x6487) var3 -= 0x6487;
            else if (var3 < 0) var3 += 0x6487;
            state->unknown_a0_.x = fix32_Divide(var3, duration);
            int var4;
            if (request->unknown_14_) var4 = state->angles.y - request->angles.y;
            else var4 = request->angles.y - state->angles.y;
            if (var4 > 0x6487) var4 -= 0x6487;
            else if (var4 < 0) var4 += 0x6487;
            state->unknown_a0_.y = fix32_Divide(var4, duration);
            int var5;
            if (request->unknown_14_) var5 = state->angles.z - request->angles.z;
            else var5 = request->angles.z - state->angles.z;
            if (var5 > 0x6487) var5 -= 0x6487;
            else if (var5 < 0) var5 += 0x6487;
            state->unknown_a0_.z = fix32_Divide(var5, duration);
            if (request->unknown_14_) {
                state->unknown_a0_.x = -state->unknown_a0_.x;
                state->unknown_a0_.y = -state->unknown_a0_.y;
                state->unknown_a0_.z = -state->unknown_a0_.z;
            }
        } else {
            state->angles.x += inline_ov001_021594cc(state->unknown_a0_.x, tick);
            if (state->angles.x > 0x6487) state->angles.x -= 0x6487;
            else if (state->angles.x <= 0) state->angles.x += 0x6487;
            state->angles.y += inline_ov001_021594cc(state->unknown_a0_.y, tick);
            if (state->angles.y > 0x6487) state->angles.y -= 0x6487;
            else if (state->angles.y <= 0) state->angles.y += 0x6487;
            state->angles.z += inline_ov001_021594cc(state->unknown_a0_.z, tick);
            if (state->angles.z > 0x6487) state->angles.z -= 0x6487;
            else if (state->angles.z <= 0) state->angles.z += 0x6487;
        }
        state->elapsed += game->GetTickCount();
    }
    return 1;
}
