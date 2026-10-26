#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"

struct Obj02033874;
extern "C" void GameObject_SnapFacing(struct Obj02033874* obj, int arg);

struct Struct_ov025_021eeca4 {
    char pad0[8];
    unsigned short unknown_8_;
    unsigned short unknown_a_;
    short targetAngle;
};

// USA: func_ov025_021eeca4
extern "C" ARM int func_ov025_021eeca4(struct Struct_ov025_021eeca4* task) {
    GameState* gs = GameState::GetInstance();
    unsigned int var1 = gs->GetEffectiveDeltaTime();
    GameObject* c = gs->GetCombatantByIndex(task->unknown_8_);
    if (task->unknown_a_ <= var1) {
        GameObject_SnapFacing((struct Obj02033874*)c, task->targetAngle);
        return 1;
    }
    fix32_t angle = c->obj3D_.rotation_.y;
    float diff = fix32SignedAngleDistance(angle, task->targetAngle);
    float t = (float)var1 / (float)task->unknown_a_;
    GameObject_SnapFacing((struct Obj02033874*)c, fix32ReduceAngle0To2Pi(angle + (int)(diff * t)));
    task->unknown_a_ -= var1;
    return 0;
}
