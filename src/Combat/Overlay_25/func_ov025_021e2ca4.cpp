#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov000_02160094 { char pad0[0x20]; unsigned short id; };
struct Struct_ov000_021600f8 { char pad0[0xe]; short id; };
struct Struct_ov000_0215440c_2 { char pad0[0x10]; Struct_ov000_02160094* head; };
struct Struct_ov000_0215440c;
struct Struct_ov025_021e2ca4 { char pad0[8]; short start; short end; int margin; };
struct Struct_ov025_021dcf14_8 {
    int type;
    int delay;
    unsigned short id;
    unsigned short duration;
    union { Vector3i position; unsigned short angle; } target;
    Struct_ov025_021dcf14_8* next;
};
struct Struct_ov025_021dcf14_7;
extern "C" Struct_ov000_02160094* func_ov000_02160094(Struct_ov000_0215440c_2*, int);
extern "C" Struct_ov000_021600f8* func_ov000_021600f8(Struct_ov000_0215440c*, int);
extern "C" void func_ov025_021de110(void*);
extern "C" void func_ov025_021eee48(Struct_ov025_021dcf14_7*, Struct_ov025_021dcf14_8*);
extern "C" int func_ov025_021df9f4(GameObject*);
extern "C" void GameObject_FaceGameObject(GameObject*, int, int);

// USA: func_ov025_021e2ca4
extern "C" ARM int func_ov025_021e2ca4(Struct_ov025_021e2ca4* command, Struct_ov000_0215440c_2* list, Struct_ov025_021dcf14_7* queue) {
    Struct_ov000_02160094* node = func_ov000_02160094(list, 0);
    if (!node) return 0;
    int id = node->id;
    GameState* game = GameState::GetInstance();
    GameObject* actor = game->GetCombatantByIndex(id);
    BCFG* config = actor->obj3D_.GetCurrentAnimationConfig();
    int animation = actor->obj3D_.activeAnimationIndex_;
    if (!config) return 1;
    BCFG::AnimationRecord* record = config->GetAnimationRecord(animation);
    if (!record) return 0;
    Struct_ov000_021600f8* target = func_ov000_021600f8((Struct_ov000_0215440c*)list, 0);
    if (!target) return 1;
    GameObject* other = game->GetCombatantByIndex(target->id);
    if (record && other) {
        int time = (int)(16.666f * (float)fix32_Divide(record->endTime - record->startTime, record->frameRate) / 4096.0f);
        short start = command->start;
        int duration = (int)((float)time * ((float)(command->end - start) / 4096.0f));
        int delay = 0;
        if (actor->obj3D_.normalizedAnimationTime_ < start) {
            delay = (int)(((long long)time * (start - actor->obj3D_.normalizedAnimationTime_) + 0x800) >> 12);
        }
        Vector3fix targetPosition = other->obj3D_.position_;
        Vector3fix actorPosition = actor->obj3D_.position_;
        int var15 = actor->obj3D_.GetRadius() / 2;
        int var16 = other->obj3D_.GetRadius() / 2;
        int distance = Vector3fix_Distance(&actorPosition, &targetPosition) - var15 - var16 - command->margin;
        Vector3fix direction;
        Vector3fix_Subtract(&targetPosition, &actorPosition, &direction);
        Vector3fix_Normalize(&direction, &direction);
        Vector3fix movement;
        Vector3fixMultiplyScalar(&direction, distance, &movement);
        Vector3fix destination;
        Vector3fix_Add(&actorPosition, &movement, &destination);
        Struct_ov025_021dcf14_8 entry;
        func_ov025_021de110(&entry);
        entry.type = 0;
        entry.delay = delay;
        entry.id = node->id;
        entry.duration = duration;
        entry.target.position = destination;
        func_ov025_021eee48(queue, &entry);
        int angle = fix32_Atan2(direction.x, direction.z);
        int var23 = 250;
        if (duration < var23) var23 = duration;
        entry.type = 1;
        entry.duration = var23;
        entry.target.angle = angle;
        if (list->head) entry.id = list->head->id;
        else entry.id = 0;
        func_ov025_021eee48(queue, &entry);
        entry.type = 1;
        entry.id = node->id;
        entry.duration = duration;
        entry.target.angle = fix32_Atan2(direction.x, direction.z);
        func_ov025_021eee48(queue, &entry);
        if (func_ov025_021df9f4(other)) GameObject_FaceGameObject(other, node->id, 1);
    }
    return 1;
}
