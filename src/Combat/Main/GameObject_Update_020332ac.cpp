#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"

struct Obj02033710;
struct GameObjectFields : Object3D {
    short field_ac, facing, turnSpeed;
    short speed, maximumSpeed, acceleration;
    char paddingb8[6];
    unsigned char motionState, previousMotionState;
    char paddingc0[3];
    unsigned char delay;
    unsigned short flagsc4;
    short glideSpeed;
    Vector3fix glideTarget;
    Vector3fix moveTarget;
    unsigned char reserved0 : 2;
    unsigned char paused : 1;
    unsigned char reserved3 : 1;
    unsigned char stepTowardTarget : 1;
    unsigned char snapToTarget : 1;
    unsigned char reserved6 : 2;
};
struct MotionStateRow { signed char nextState; char padding1[12]; };
extern MotionStateRow data_020ef9d0[];
void GameObject_TurnTowardFacing(Obj02033710*);
void GameObject_UpdateGlide(void*);
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
                        arg0->unknown_b2_ -= var3;
                        if (arg0->unknown_b2_ < 0) arg0->unknown_b2_ = 0;
                    }
                    int var5 = arg0->unknown_b2_ * var2->GetTickCount();
                    if (var1 < var5) var5 = var1;
                    Vector3fix var6;
                    Vector3fixMultiplyScalar(&var4, var5, &var6);
                    Vector3fix var7;
                    Vector3fix_Add(&arg0->position_, &var6, &var7);
                    arg0->position_ = var7;
                } else arg0->unknown_b2_ = 0;
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
    int var9 = arg0->unknown_c3_;
    if (var9) {
        var9 -= GameState::GetInstance()->GetTickCount();
        if (var9 < 0) var9 = 0;
        arg0->unknown_c3_ = var9;
    }
    GameObject_UpdateGraphNode(object);
    object->AdvanceEffects();
}
