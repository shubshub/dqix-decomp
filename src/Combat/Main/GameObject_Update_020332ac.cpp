#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"

struct Obj02033710;
struct GameObjectFields : Object3D {
    short field_ac, facing, turnSpeed;
    short speed, maximumSpeed, acceleration;
    char unknown_b8_[6];
    unsigned char motionState, previousMotionState;
    char unknown_c0_[3];
    unsigned char delay;
    unsigned short unknown_c4_;
    short glideSpeed;
    Vector3fix glideTarget;
    Vector3fix moveTarget;
    unsigned char unknown_e0_0_ : 2;
    unsigned char paused : 1;
    unsigned char unknown_e0_3_ : 1;
    unsigned char stepTowardTarget : 1;
    unsigned char snapToTarget : 1;
    unsigned char reserved6 : 2;
};
struct MotionStateRow { signed char nextState; char padding1[12]; };
extern MotionStateRow data_020ef9d0[];
extern "C" void GameObject_TurnTowardFacing(Obj02033710*);
extern "C" void GameObject_UpdateGlide(void*);
extern "C" void GameObject_UpdateMovement(GameObjectFields*);
extern "C" void GameObject_ApplyMotionState(GameObjectFields*);
extern "C" void GameObject_UpdateGraphNode(GameObjectFields*);

// Main, originally func_020332ac (USA 0x020332ac, EUR 0x020332bc, JPN 0x02032de4)
extern "C" ARM void GameObject_Update(GameObjectFields* object) {
    if (!object->paused) {
        GameObject_TurnTowardFacing((Obj02033710*)object);
        GameObject_UpdateMovement(object);
        if (object->stepTowardTarget) {
            object->stepTowardTarget = 0;
            if (object->snapToTarget) {
                object->snapToTarget = 0;
                object->position_ = object->moveTarget;
            } else {
                Vector3fix difference;
                Vector3fix_Subtract(&object->moveTarget, &object->position_, &difference);
                int distance = Vector3fix_Length(&difference);
                if (distance > 0) {
                    GameState* game = GameState::GetInstance();
                    int acceleration = object->acceleration * game->GetTickCount();
                    Vector3fix direction;
                    Vector3fixMultiplyScalar(&difference, fix32_Divide(0x1000, distance), &direction);
                    if (object->speed <= distance) {
                        object->speed += acceleration;
                        if (object->maximumSpeed < object->speed) object->speed = object->maximumSpeed;
                    } else {
                        object->speed -= acceleration;
                        if (object->speed < 0) object->speed = 0;
                    }
                    int speed = object->speed * game->GetTickCount();
                    if (distance < speed) speed = distance;
                    Vector3fix step;
                    Vector3fixMultiplyScalar(&direction, speed, &step);
                    Vector3fix position;
                    Vector3fix_Add(&object->position_, &step, &position);
                    object->position_ = position;
                } else object->speed = 0;
            }
        }
        GameObject_UpdateGlide(object);
        if (object->HasAnimationStopped() || object->HasAnimationReachedEnd()) {
            object->previousMotionState = object->motionState;
            int nextState = data_020ef9d0[(short)object->motionState].nextState;
            if (nextState > -1) object->motionState = nextState;
            GameObject_ApplyMotionState(object);
        }
    }
    int delay = object->delay;
    if (delay) {
        delay -= GameState::GetInstance()->GetTickCount();
        if (delay < 0) delay = 0;
        object->delay = delay;
    }
    GameObject_UpdateGraphNode(object);
    object->AdvanceEffects();
}
