#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov000_02160094 { char unknown_0_[0x20]; unsigned short unknown_20_; };
struct Struct_ov000_021600f8 { char unknown_0_[0xe]; short unknown_e_; };
struct Struct_ov000_0215440c_2 { char unknown_0_[0x10]; Struct_ov000_02160094* unknown_10_; };
struct Struct_ov000_0215440c;
struct Struct_ov025_021e2ca4 { char unknown_0_[8]; short unknown_8_; short unknown_a_; int unknown_c_; };
struct Struct_ov025_021dcf14_8 {
    int unknown_0_;
    int unknown_4_;
    unsigned short unknown_8_;
    unsigned short unknown_a_;
    union { Vector3i unknown_0_; unsigned short unknown1_0_; } unknown_c_;
    Struct_ov025_021dcf14_8* unknown_18_;
};
struct Struct_ov025_021dcf14_7;
extern "C" Struct_ov000_02160094* func_ov000_02160094(Struct_ov000_0215440c_2*, int);
extern "C" Struct_ov000_021600f8* func_ov000_021600f8(Struct_ov000_0215440c*, int);
extern "C" void func_ov025_021de110(void*);
extern "C" void func_ov025_021eee48(Struct_ov025_021dcf14_7*, Struct_ov025_021dcf14_8*);
extern "C" int func_ov025_021df9f4(GameObject*);
extern "C" void GameObject_FaceGameObject(GameObject*, int, int);

// USA: func_ov025_021e2ca4
extern "C" ARM int func_ov025_021e2ca4(Struct_ov025_021e2ca4* arg0, Struct_ov000_0215440c_2* arg1, Struct_ov025_021dcf14_7* arg2) {
    Struct_ov000_02160094* var0 = func_ov000_02160094(arg1, 0);
    if (!var0) return 0;
    int var1 = var0->unknown_20_;
    GameState* var2 = GameState::GetInstance();
    GameObject* var3 = var2->GetCombatantByIndex(var1);
    BCFG* var4 = var3->obj3D_.GetCurrentAnimationConfig();
    int var5 = var3->obj3D_.activeAnimationIndex_;
    if (!var4) return 1;
    BCFG::AnimationRecord* var6 = var4->GetAnimationRecord(var5);
    if (!var6) return 0;
    Struct_ov000_021600f8* var7 = func_ov000_021600f8((Struct_ov000_0215440c*)arg1, 0);
    if (!var7) return 1;
    GameObject* var8 = var2->GetCombatantByIndex(var7->unknown_e_);
    if (var6 && var8) {
        int var9 = (int)(16.666f * (float)fix32_Divide(var6->endTime - var6->startTime, var6->frameRate) / 4096.0f);
        short var10 = arg0->unknown_8_;
        int var11 = (int)((float)var9 * ((float)(arg0->unknown_a_ - var10) / 4096.0f));
        int var12 = 0;
        if (var3->obj3D_.normalizedAnimationTime_ < var10) {
            var12 = (int)(((long long)var9 * (var10 - var3->obj3D_.normalizedAnimationTime_) + 0x800) >> 12);
        }
        Vector3fix targetPosition = other->obj3D_.position_;
        Vector3fix actorPosition = actor->obj3D_.position_;
        int actorRadius = actor->obj3D_.GetRadius() / 2;
        int targetRadius = other->obj3D_.GetRadius() / 2;
        int distance = Vector3fix_Distance(&actorPosition, &targetPosition) - actorRadius - targetRadius - command->margin;
        Vector3fix direction;
        Vector3fix_Subtract(&targetPosition, &actorPosition, &direction);
        Vector3fix_Normalize(&direction, &direction);
        Vector3fix movement;
        Vector3fixMultiplyScalar(&direction, distance, &movement);
        Vector3fix destination;
        Vector3fix_Add(&actorPosition, &movement, &destination);
        Rec021eee48 entry;
        ResetFields_021de110(&entry);
        entry.type = 0;
        entry.delay = delay;
        entry.id = node->id;
        entry.duration = duration;
        entry.target.position = destination;
        PushNodeFromFreeList_021eee48(queue, &entry);
        int angle = fix32_Atan2(direction.x, direction.z);
        int turnDuration = 250;
        if (duration < turnDuration) turnDuration = duration;
        entry.type = 1;
        entry.duration = turnDuration;
        entry.target.angle = angle;
        if (list->head) entry.id = list->head->id;
        else entry.id = 0;
        PushNodeFromFreeList_021eee48(queue, &entry);
        entry.type = 1;
        entry.id = node->id;
        entry.duration = duration;
        entry.target.angle = fix32_Atan2(direction.x, direction.z);
        PushNodeFromFreeList_021eee48(queue, &entry);
        if (func_ov025_021df9f4(other)) GameObject_FaceGameObject(other, node->id, 1);
    }
    return 1;
}
