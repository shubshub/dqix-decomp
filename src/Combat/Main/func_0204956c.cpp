#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/FormationPosition.h"
#include "Graphics/Vector.h"
#include "std_library_functions.h"

struct Struct_0204956c {
    unsigned char unknown_0_[0x20];
    unsigned int flags;
    unsigned char unknown_24_[0x2a];
    unsigned char direction, remaining;
    short speed;
    unsigned short delay;
    unsigned char unknown_54_, unknown_55_, enabled;
};
struct Struct_0204956c_2 { GameObject base; Struct_0204956c* state; };
struct Struct_02107850 { Vector3i start, end; int radius; unsigned char enabled; };
struct S_10088;
struct Struct_02048f64_2;
extern "C" int func_02048c68(unsigned char*);
extern "C" int func_02010088(S_10088*);
extern "C" void func_02049ae4(unsigned char*);
extern "C" int func_02049ee8(unsigned char*);
extern "C" int func_020494a0(unsigned char*);
extern "C" int func_020493a4(unsigned char*);
extern "C" void func_020494c0(Struct_02048f64_2*);
extern "C" int Vector3fix_DistanceToSegment(Vector3i*, Vector3i*, Vector3i*, Vector3i*);
extern "C" Struct_02107850 data_02107850;
namespace ClipAlias0204956c { extern "C" Struct_02107850 data_02107850; }
extern const Vector3i data_020e7b3c;
extern const Vector3i data_020e7b30;
struct Struct_020e7b54 { int values[3]; };
extern const Struct_020e7b54 data_020e7b54;
extern const char data_020f01a4[];
void Vector3fixMultiplyScalar(const Vector3i*, int, Vector3i*);

static inline Struct_02048cf0 inline_0204956c(const int& cell) {
    return func_ov000_0216f74c(const_cast<int*>(&cell));
}

// USA: func_0204956c
extern "C" ARM void func_0204956c(Struct_0204956c_2* actor) {
    unsigned char* bytes = reinterpret_cast<unsigned char*>(actor);
    if (!(actor->state->flags & 4)) return;
    if (!actor->state->enabled || func_02048c68(bytes) || func_02010088(reinterpret_cast<S_10088*>(actor))) {
        func_02049ae4(bytes);
        return;
    }
    if (!func_02049ee8(bytes)) return;
    GameState* game = GameState::GetInstance();
    Struct_0204956c* state = actor->state;
    Object3D* object = &actor->base.obj3D_;
    if (state->delay) {
        int elapsed = game->GetEffectiveDeltaTime();
        if (elapsed < state->delay) {
            state->delay -= elapsed;
            return;
        }
        state->delay = 0;
    }
    if (!state->remaining) {
        int actorId = object->actorIndex_;
        int selection = actorId + func_020494a0(bytes) + state->unknown_54_;
        int targetId = func_020494a0(bytes);
        if (targetId == 0xff) { func_02049ae4(bytes); return; }
        GameObject* target = game->GetCombatantByIndex(targetId);
        if (!target) { func_02049ae4(bytes); return; }
        Struct_02107850* clip = &ClipAlias0204956c::data_02107850;
        if (data_02107850.enabled) {
            Vector3i start = clip->start;
            Vector3i end = clip->end;
            Vector3i position = object->position_;
            Vector3i closest;
            int distance = Vector3fix_DistanceToSegment(&start, &end, &position, &closest);
            if (distance < clip->radius + (object->GetRadius() >> 1) + 0x2000) {
                func_02049ae4(bytes);
                return;
            }
        }
        Struct_02048cf0 formation = inline_0204956c(func_020493a4(bytes));
        Vector3i origin = data_020e7b3c;
        origin.x = formation.x;
        origin.z = formation.y;
        Vector3i targetPosition = target->obj3D_.position_;
        Vector3i position = object->position_;
        Vector3i var19, var20;
        Vector3fix_Subtract(&position, &origin, &var19);
        Vector3fix_Subtract(&targetPosition, &origin, &var20);
        Vector3fix_Normalize(&var19, &var19);
        Vector3fix_Normalize(&var20, &var20);
        int var21 = selection % 2;
        if (var21) {
            if (Vector3fix_InnerProduct(&var19, &var20) > 0) state->direction = 1;
            else state->direction = 0;
        } else {
            Vector3i var22;
            Vector3fix_CrossProduct(&var19, &var20, &var22);
            if (var22.y > 0) state->direction = 2;
            else state->direction = 3;
        }
        state->remaining = var21 + 1;
        BCFG::AnimationRecord* animation = object->GetLoadedAnimationRecord(data_020f01a4);
        if (animation) {
            unsigned int frames = (unsigned int)((float)fix32_Divide(animation->endTime - animation->startTime, animation->frameRate) / 4096.0f);
            state->speed = 0xc00 / (frames * 17);
        }
        object->SetAnimationByName(data_020f01a4, 1);
        func_020494c0(reinterpret_cast<Struct_02048f64_2*>(actor));
        return;
    }
    int targetId = func_020494a0(bytes);
    if (targetId == 0xff) { func_02049ae4(bytes); return; }
    GameObject* target = game->GetCombatantByIndex(targetId);
    if (!target) { func_02049ae4(bytes); return; }
    Vector3i position = object->position_;
    Vector3i targetPosition = target->obj3D_.position_;
    Vector3i direction;
    Vector3fix_Subtract(&targetPosition, &position, &direction);
    Vector3i up = data_020e7b30;
    switch (state->direction) {
    case 0: Vector3fix_Normalize(&direction, &direction); break;
    case 1:
        Vector3fixMultiplyScalar(&direction, -0x1000, &direction);
        Vector3fix_Normalize(&direction, &direction);
        break;
    case 2:
        Vector3fix_Normalize(&direction, &direction);
        Vector3fix_CrossProduct(&direction, &up, &direction);
        Vector3fixMultiplyScalar(&direction, -0x1000, &direction);
        break;
    case 3:
        Vector3fix_Normalize(&direction, &direction);
        Vector3fix_CrossProduct(&direction, &up, &direction);
        break;
    default: func_02049ae4(bytes); break;
    }
    int elapsed = game->GetEffectiveDeltaTime();
    Vector3i delta;
    Vector3fixMultiplyScalar(&direction, state->speed * elapsed, &delta);
    Vector3fix_Add(&position, &delta, &position);
    object->position_ = position;
    if (object->HasAnimationStopped()) {
        --state->remaining;
        if (!state->remaining) {
            int actorId = object->actorIndex_;
            int selection = actorId + func_020494a0(bytes) + state->unknown_54_;
            Struct_020e7b54 var35 = data_020e7b54;
            state->delay = var35.values[selection % 3];
            ++state->unknown_54_;
        } else {
            object->StopCurrentAnimation();
            object->SetAnimationByName(data_020f01a4, 1);
            func_020494c0(reinterpret_cast<Struct_02048f64_2*>(actor));
        }
    } else if (object->activeAnimationRecord_ && strcmp(object->activeAnimationRecord_->name, data_020f01a4)) {
        func_02049ae4(bytes);
    }
}
