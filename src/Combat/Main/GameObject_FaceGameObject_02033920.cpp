#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int Vector3fix_HeadingToward(Vector3fix*, Vector3fix*);
struct Obj02033834;
void GameObject_SetFacing(struct Obj02033834*, int);
int fix32SignedAngleDistance(int a, int b);
int fix32abs(int x);
extern char data_020efa3c;

struct GameObjectTimerBits {
    unsigned short sinkTimer : 15;
    unsigned short turningInPlace : 1;
};

struct GameObjectFields {
    char pad0[4];
    short actorIndex;
    char pad1[0x3e];
    Vector3fix position;
    char pad2[4];
    int rotationY;
    char pad3[0x56];
    short facing;
    short turnSpeed;
    char pad4[0xc];
    unsigned char motionState;
    char pad5[5];
    struct GameObjectTimerBits timerBits;
};

// Main, originally func_02033920 (USA 0x02033920, EUR 0x02033930, JPN 0x02033458)
extern "C" ARM void GameObject_FaceGameObject(struct GameObjectFields* self, int targetIndex, int animateTurn) {
    GameState* game = GameState::GetInstance();
    if (targetIndex == self->actorIndex) return;
    GameObject* target = game->GetGameObjectByIndex(targetIndex);
    if (target == 0) return;
    int angle = Vector3fix_HeadingToward(&target->obj3D_.position_, &self->position);
    GameObject_SetFacing((struct Obj02033834*)self, angle);
    if (animateTurn == 0) return;
    if (self->motionState != 0) return;
    int turnLeft = fix32SignedAngleDistance(self->rotationY, self->facing);
    int turnAngle = fix32abs(turnLeft);
    if (turnAngle <= 0x1000) return;
    if (self->turnSpeed > 0x10c) return;
    int started = ((Object3D*)self)->SetAnimationByName(&data_020efa3c, 0x11);
    if (started != 0) {
        self->timerBits.turningInPlace = 1;
    }
}
