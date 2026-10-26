#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

int fix32ReduceAngle0To2Pi(int angle);
struct Bytes02033b88;
extern "C" int GameObject_ForceMotionState(struct Bytes02033b88* p, int val);
int fix32SignedAngleDistance(int a, int b);
struct Vector3i;

extern char data_020efa3c;

struct RotationVector { int x; int y; int z; };
struct GameObjectTimerBits { unsigned short sinkTimer : 15; unsigned short turningInPlace : 1; };

struct Obj02033710 {
    char pad0[0x14];
    char* activeAnimationRecord;
    char pad1[0x38];
    struct RotationVector rotation;
    char pad2[0x52];
    short facing;
    short turnSpeed;
    char pad3[0xc];
    unsigned char motionState;
    char pad4[5];
    struct GameObjectTimerBits timerBits;
};

// Main, originally AdvanceFacingAngleTowardTarget (USA 0x02033710, EUR 0x02033720, JPN 0x02033248)
extern "C" ARM void GameObject_TurnTowardFacing(struct Obj02033710* self) {
    GameState* game = GameState::GetInstance();
    if (self->motionState == 4 || self->motionState == 6) {
        return;
    }
    unsigned int ticks = game->GetTickCount();
    int turnStep = self->turnSpeed * (int)ticks;
    struct RotationVector rotation = self->rotation;
    int turnLeft = fix32SignedAngleDistance(rotation.y, self->facing);
    int facingReached = 1;
    if (turnLeft > 0) {
        if (turnLeft < turnStep) {
            rotation.y = self->facing;
        } else {
            rotation.y += turnStep;
            facingReached = 0;
        }
    } else if (turnLeft < 0) {
        int turnLeftAbs = -turnLeft;
        if (turnLeftAbs < turnStep) {
            rotation.y = self->facing;
        } else {
            rotation.y -= turnStep;
            facingReached = 0;
        }
    }
    rotation.y = fix32ReduceAngle0To2Pi(rotation.y);
    *(Vector3i*)((int*)&self->rotation) = *(Vector3i const*)((int*)&rotation);
    if (facingReached) {
        if (self->timerBits.turningInPlace) {
            if (!((Object3D*)self)->IsTransitioningAnimations()) {
                self->timerBits.turningInPlace = 0;
                if (self->motionState == 0) {
                    if (self->activeAnimationRecord != NULL) {
                        if (strcmp(self->activeAnimationRecord, &data_020efa3c) == 0) {
                            GameObject_ForceMotionState((struct Bytes02033b88*)self, 0);
                        }
                    }
                }
            }
        }
    }
}
