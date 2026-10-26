#include <globaldefs.h>
#include "NitroSDK/Matrix.h"

extern "C" int rand(void);
extern "C" void func_0203ef7c(void*);

// The NpcWalker fields past its sprite part (func_0203ef7c initialises +0..+0x5b)
struct NpcWalker0203c794 {
    char pad0[0x5c];
    int flags;            // 1 walking to target, 2 turning, 4 walks without turning, 0x10/0x20 talk poses
    int angle;            // turns towards facing
    int facing;           // NpcWalker_SetFacing
    int angularSpeed;     // per movement tick
    char pad6c[0x84 - 0x6c];
    int unknown84;
    int idleTicks;        // ticks since it last walked
    int speed;            // distance per step towards the target
    int angleOffset;      // added to the angle while lying down (NpcWalker_SelectDirectionAnimation)
    unsigned char talkReturnFrames; // frames left of the talk-return pose (NpcWalker_UpdateTalkAnimation counts it down)
    unsigned char fourDirections;   // only four facing animations (NpcWalker_SelectDirectionAnimation)
    char pad96[2];
    int talkerX;          // the leader's x when the talk pose was set (SetCombatFlags0x5c)
};

enum {
    kTurnSpeed = FIX_2PI / 32,   // 0x324: a 32nd of a turn per movement tick
    kWalkSpeed = 0x7a,           // 0.03 in fx32: NpcWalker_MoveTowardTarget plays the walk at 1x at this speed
    kTalkReturnFrames = 0xf
};

// Main, originally InitializeRandomMotion0203c794 (USA 0x0203c794, EUR 0x0203c7a4, JPN 0x0203cccc)
ARM void NpcWalker_Init(void* rawWalker) {
    NpcWalker0203c794* walker = (NpcWalker0203c794*)rawWalker;
    func_0203ef7c(walker);
    walker->angle = 0;
    walker->facing = 0;
    walker->angularSpeed = kTurnSpeed;
    walker->unknown84 = (int)(((float)(rand() % 200) / 100.0f) * 4096.0f);
    walker->flags = 0;
    walker->idleTicks = 0;
    walker->speed = kWalkSpeed;
    walker->angleOffset = 0;
    walker->talkReturnFrames = kTalkReturnFrames;
    walker->fourDirections = 0;
    walker->talkerX = 0;
}
