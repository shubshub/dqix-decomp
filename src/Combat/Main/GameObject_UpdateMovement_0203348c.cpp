#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"

extern "C" float _fflt(int v);

struct GameObjectFall {
    char unknown_0_[0x24];
    int fallY;
    int fallLandY;
    unsigned short fallStep;
};

struct GameObjectTimerBits {
    unsigned short sinkTimer : 15;
    unsigned short turningInPlace : 1;
};

struct GameObjectFields : Object3D {
    short field_ac, facing, turnSpeed;
    short speed, maximumSpeed, acceleration;
    char unknown_b8_[6];
    unsigned char motionState, previousMotionState;
    char unknown_c0_;
    unsigned char c1_low : 2;
    unsigned char c1_bit2 : 1;
    unsigned char unknown_c1_3_ : 5;
    unsigned char c2_low : 5;
    unsigned char c2_bit5 : 1;
    unsigned char c2_high : 2;
    unsigned char delay;
    GameObjectTimerBits timerBits;
    short glideSpeed;
    Vector3fix glideTarget;
    Vector3fix moveTarget;
    unsigned char e0_bit0 : 1;
    unsigned char unknown_e0_1_ : 7;
    char unknown_e1_[0x1f];
    GameObjectFall fall;
};

// Main, originally func_0203348c (USA 0x0203348c, EUR 0x0203349c, JPN 0x02032fc4)
extern "C" ARM void GameObject_UpdateMovement(GameObjectFields* self) {
    if (self->e0_bit0 || self->c2_bit5 || self->c1_bit2) {
        return;
    }
    GameState* game = GameState::GetInstance();
    unsigned int elapsed = game->GetEffectiveDeltaTime();
    int ticks = game->GetTickCount();
    int sinking = self->timerBits.sinkTimer != 0;
    if (sinking) {
        if (elapsed >= self->timerBits.sinkTimer) {
            self->timerBits.sinkTimer = 0;
        } else {
            self->timerBits.sinkTimer -= elapsed;
        }
    }
    int speed = self->speed;
    int accel = self->acceleration * ticks;
    if (self->motionState == 1) {
        if (speed < self->maximumSpeed) {
            self->speed = accel + speed;
        } else if (speed - self->maximumSpeed < accel) {
            self->speed = self->maximumSpeed;
        } else {
            self->speed = speed - accel;
        }
    } else if (speed > 0) {
        self->speed = speed - accel;
    } else {
        self->speed = 0;
    }
    int stillSinking = self->timerBits.sinkTimer != 0;
    if (stillSinking || self->fall.fallY != 0) {
        speed = 0;
    }
    if (0.0f < _fflt(speed)) {
        int heading = self->rotation_.y;
        int maxSpeed = self->maximumSpeed;
        int turnLeft = fix32SignedAngleDistance(heading, self->facing);
        int turnAngle = fix32abs(turnLeft);
        int turningSpeedLimit = FIX32_MULTIPLY(maxSpeed, 0x1000 - fix32_Divide(turnAngle, FIX_2PI / 2));
        if (turningSpeedLimit < speed) {
            speed = turningSpeedLimit;
        }
        speed = speed * ticks;
        int moveAngle = heading;
        if (self->unknown_0_ & 0x100) {
            moveAngle = self->facing;
        }
        Vector3fix step;
        step.x = fix32sin(moveAngle);
        step.y = 0;
        step.z = fix32cos(moveAngle);
        Vector3fixMultiplyScalar(&step, speed, &step);
        Vector3fix moved;
        Vector3fix_Add(&self->position_, &step, &moved);
        self->position_ = moved;
    }
    Vector3fix position = self->position_;
    position.y = position.y - self->field_ac;
    if (position.y < -50 * 0x1000) {
        position.y = 50 * 0x1000;
    }
    self->position_ = position;
    if (self->fall.fallY != 0) {
        self->fall.fallStep++;
        self->fall.fallY -= self->fall.fallStep * 0x51;
        if (self->fall.fallY < self->fall.fallLandY) {
            self->fall.fallStep = 0;
            self->fall.fallY = 0;
            self->fall.fallLandY = 0;
        }
    }
}
