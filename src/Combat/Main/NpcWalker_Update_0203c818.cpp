#include <globaldefs.h>
#include "NitroSDK/Matrix.h"

struct State0203f20c;
extern "C" void func_0203f20c(State0203f20c*);
extern "C" void NpcWalker_UpdateTalkAnimation(void* walker, void* camera);
struct MoverObj0203c960;
extern "C" void NpcWalker_MoveTowardTarget(MoverObj0203c960*);
int fix32ReduceAngle0To2Pi(int angle);

// An NpcWalker
struct Obj0203c818 {
    char pad0[4];
    Vector3fix position;
    char pad10[0x5c - 0x10];
    int flags;
    int angle;               // turns towards facing
    int facing;              // NpcWalker_SetFacing
    int angularSpeed;        // per movement tick
    Vector3fix previousPosition;
    char unknown_78_[0x88 - 0x78];
    int idleTicks;           // ticks since it last walked
};

enum {
    kWalking = 1,        // walking to its target (NpcWalker_WalkTo)
    kTurning = 2,        // angle has not reached facing yet
    kTalkPose = 0x10,    // func_0203cedc, when talked to
    kTalkReturn = 0x20   // func_0203cedc, when the talk ends
};

// Main, originally func_0203c818 (USA 0x0203c818, EUR 0x0203c828, JPN 0x0203cd50)
extern "C" ARM void NpcWalker_Update(Obj0203c818* walker, void* camera, int elapsedTicks, int movementTicks) {
    func_0203f20c((State0203f20c*)walker);

    if ((walker->flags & kTalkPose) || (walker->flags & kTalkReturn)) {
        NpcWalker_UpdateTalkAnimation(walker, camera);
    } else {
        int turned;
        int step;
        int difference;

        if (walker->flags & kWalking) {
            NpcWalker_MoveTowardTarget((MoverObj0203c960*)walker);
        }

        turned = 0;
        step = walker->angularSpeed * movementTicks;
        difference = 0;

        if (walker->angle < walker->facing) {
            difference = walker->facing - walker->angle;
            if (difference > FIX_2PI / 2) {
                difference -= FIX_2PI;
            }
        } else if (walker->facing < walker->angle) {
            difference = -(walker->angle - walker->facing);
            if (difference < -(FIX_2PI / 2)) {
                difference += FIX_2PI;
            }
        }

        if (difference > 0) {
            if (difference < step) {
                walker->angle = walker->facing;
            } else {
                walker->angle = walker->angle + step;
            }
            walker->flags |= kTurning;
            turned = 1;
        } else if (difference < 0) {
            if (-difference < step) {
                walker->angle = walker->facing;
            } else {
                walker->angle = walker->angle - step;
            }
            walker->flags |= kTurning;
            turned = 1;
        }

        if (turned == 0) {
            walker->flags &= ~kTurning;
        }

        walker->angle = fix32ReduceAngle0To2Pi(walker->angle);
        walker->previousPosition = walker->position;

        if (!(walker->flags & kWalking)) {
            walker->idleTicks = walker->idleTicks + elapsedTicks;
        } else {
            walker->idleTicks = 0;
        }
    }
}
