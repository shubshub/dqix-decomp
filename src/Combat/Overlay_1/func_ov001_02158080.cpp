#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov001_02158080_2 {
    int field_0;
    int angle;
    int pitch;
    int roll;
    char unknown_10_[0xc];
    int duration;
    int direction;
    int snap;
};
struct Struct_ov001_02158080 {
    char field_0[0x3c];
    int elapsed;
    char unknown_40_[0x24];
    int angle;
    int pitch;
    int roll;
    int linked;
    char unknown_74_[0x14];
    int unknown_88_;
    int unknown_8c_;
    int unknown_90_;
    char unknown_94_[0x38];
    int unknown_cc_;
    int field_d0;
    int unknown_d4_;
    int rollStep;
};

static inline int inline_ov001_02158080(int value, int scale) {
    return (int)(((long long)value * scale + 0x800) >> 12);
}

// USA: func_ov001_02158080
extern "C" ARM int func_ov001_02158080(Struct_ov001_02158080_2* command, Struct_ov001_02158080* state) {
    GameState* game = GameState::GetInstance();
    int scale = game->GetTickCount() << 12;
    int duration = command->duration;
    if (!duration) {
        state->angle = command->angle;
        state->pitch = command->pitch;
        state->roll = command->roll;
        if (state->linked) {
            state->unknown_88_ = command->angle;
            state->unknown_8c_ = command->pitch;
            state->unknown_90_ = command->roll;
        }
        state->elapsed = 0;
        return 0;
    }
    if (state->elapsed <= 0) {
        int var3 = duration << 13;
        if (command->direction == -1) {
            int forward = command->angle - state->angle;
            if (forward > 0x6488) forward -= 0x6488;
            else if (forward < 0) forward += 0x6488;
            int var5 = state->angle - command->angle;
            if (var5 > 0x6488) var5 -= 0x6488;
            else if (var5 < 0) var5 += 0x6488;
            if (forward < var5) state->unknown_cc_ = fix32_Divide(forward, var3);
            else state->unknown_cc_ = -fix32_Divide(var5, var3);
        } else {
            int distance;
            if (command->direction == 0) distance = state->angle - command->angle;
            else distance = command->angle - state->angle;
            if (distance > 0x6488) distance -= 0x6488;
            else if (distance < 0) distance += 0x6488;
            state->unknown_cc_ = fix32_Divide(distance, var3);
            if (command->direction == 0) state->unknown_cc_ = -state->unknown_cc_;
        }
        state->unknown_d4_ = fix32_Divide(command->pitch - state->pitch, var3);
        state->rollStep = fix32_Divide(command->roll - state->roll, var3);
    }
    state->angle += inline_ov001_02158080(state->unknown_cc_, scale);
    if (state->angle > 0x6488) state->angle -= 0x6488;
    else if (state->angle < 0) state->angle += 0x6488;
    state->pitch += inline_ov001_02158080(state->unknown_d4_, scale);
    state->roll += inline_ov001_02158080(state->rollStep, scale);
    state->elapsed += game->GetTickCount();
    if (state->elapsed >= (command->duration << 1)) {
        if (command->snap) {
            state->angle = command->angle;
            state->pitch = command->pitch;
            state->roll = command->roll;
            if (state->linked) {
                state->unknown_88_ = command->angle;
                state->unknown_8c_ = command->pitch;
                state->unknown_90_ = command->roll;
            }
        }
        state->elapsed = 0;
        return 0;
    }
    return 1;
}
