#include <globaldefs.h>
#include "GameState/GameState.h"
#include "World/Zone3D.h"
#include "Filesystem/BackgroundLoader.h"
#include "Resource/Brightness.h"
#include "Combat/Main/CopyRecord0200fbb4.h"


struct Vec3 { int x, y, z; };
struct Bounds { Vector3fix upper, lower; };
struct ListHead02046b38;
struct ListNode02046b38;
struct HeadNode02046b24;
struct TailList020469b4;
struct TailNode020469b4;
struct Entry0219ca88 {
    int kind;
    Bounds bounds;
    int destination;
    Vector3fix unknown_20_;
    Vector3fix unknown_2c_, unknown_38_, unknown44;
    short destinationAngle, boundsAngle;
    int radiusSquared;
    Vector3fix pivot;
    unsigned char unknown64[8];
    int unknown_6c_;
};
#if defined(jpn)
enum { Enum_ov017_0219ca88_396 = 0x180 };
#else
enum { Enum_ov017_0219ca88_396 = 0x18c };
#endif
struct Struct_ov017_0219ca88_3 { unsigned char kind, index; unsigned short id; unsigned char unknown4; Entry0219ca88* entry; int unknownC; unsigned short angle, unknown12; };
struct Struct_ov017_0219ca88 { unsigned int field0, field4, field8, id; unsigned char unknown_10_[0x24]; };

extern "C" Zone3D* Zone3D_GetInstance();
extern "C" void* GameState_GetZoneTransition(GameState*);
extern "C" void* Scenario_GetInstance(void*);
extern "C" int func_02046b38(ListHead02046b38*, ListNode02046b38*);
extern "C" int FieldTaskQueue_GetCurrentKind(HeadNode02046b24**);
extern "C" int FieldTaskQueue_IsEmpty(void**);
extern "C" void func_ov017_0219bed0(void*);
extern "C" unsigned char func_0200fb9c(char*);
extern "C" int func_0201201c(void*);
extern "C" int GameState_GetProtagonistIndex(GameState*);
extern "C" int Bounds3D_ContainsPointRotated(const Vector3fix*, Bounds*, int, const Vector3fix*, int);
extern "C" void* func_ov017_0219c6f4(void*);
extern "C" unsigned char GameObject_IsControlEnabled(void*);
extern "C" void func_ov017_0219a674(unsigned char*);
extern "C" short func_ov017_021a4754(Vector3fix*, int, Vector3fix*);
extern "C" void func_ov017_0219b33c(GameResources*, Struct_ov017_0219ca88_3*);
extern "C" void FieldTask_InitEnterZone(unsigned char*, int);
extern "C" void func_020469b4(TailList020469b4*, TailNode020469b4*);
extern "C" int Scenario_RunTrigger(void*, int, void*);
extern "C" void EventQuery_RunQueuedCommands(void*);

// USA: func_ov017_0219ca88
extern "C" ARM void func_ov017_0219ca88(GameResources* resources) {
    GameState* game = GameState::GetInstance();
    GameObject* actor = game->GetLeader();
    Zone3D* container = Zone3D_GetInstance();
    unsigned char* state = static_cast<unsigned char*>(GameState_GetZoneTransition(game));
    BackgroundLoader::GetInstance();
    Vector3fix* actorPosition;
    int handled = 0;
    void* lookup = Scenario_GetInstance(game->GetCamera());
    if (func_02046b38((ListHead02046b38*)resources->fieldTaskQueue_, (ListNode02046b38*)resources->unknown_ptr_array_3700[3])) return;
    if (FieldTaskQueue_GetCurrentKind((HeadNode02046b24**)resources->fieldTaskQueue_) == 4) return;
    if (FieldTaskQueue_GetCurrentKind((HeadNode02046b24**)resources->fieldTaskQueue_) == 10) return;
    if (TestFlags08(resources, 8)) {
        if (static_cast<unsigned char*>(resources->unknown_ptr_array_3700[4])[3]) return;
        if (IsMainBrightnessTransitionActive(resources)) return;
        ClearFlags08(resources, 8);
    }
    if (func_02046b38((ListHead02046b38*)resources->fieldTaskQueue_, (ListNode02046b38*)resources->unknown_ptr_array_371c[0])) return;
    if (FieldTaskQueue_IsEmpty((void**)resources->fieldTaskQueue_) && !IsBrightnessTransitionActive(resources) && ((unsigned char*)resources->unknown_42e3)[6]) {
        if (state[2]) state[0xa] = 0;
        else func_ov017_0219bed0((void*)1);
        resources->unknown_42e3[6] = 0;
    }
    int var7 = 1;
    if (func_0200fb9c((char*)game) != 6 && func_0201201c(game) != 5) {
        if (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(actor) + Enum_ov017_0219ca88_396) & 1) var7 = 0;
        else if (state[2]) var7 = 0;
        if (var7) {
            actorPosition = (Vector3fix*)&actor->obj3D_.position_;
            Vector3fix position = *actorPosition;
            for (int entryIndex = 0; entryIndex < container->substruct_6c_.arraySize68_; ++entryIndex) {
                GameState_GetProtagonistIndex(game);
                Entry0219ca88* entry = (Entry0219ca88*)ZoneFeatures_GetExit(&container->substruct_6c_, entryIndex);
                if (Bounds3D_ContainsPointRotated(&position, &entry->bounds, entry->boundsAngle, &entry->pivot, entry->radiusSquared)) {
                    func_ov017_0219c6f4(entry);
                    handled = 1;
                }
                if (handled && entry->kind == 1) {
                    handled = 0;
                    if (!GameObject_IsControlEnabled(actor)) continue;
                    Struct_ov017_0219ca88_3 event;
                    func_ov017_0219a674((unsigned char*)&event);
                    event.kind = 8;
                    event.entry = entry;
                    event.angle = func_ov017_021a4754(actorPosition, (short)actor->obj3D_.rotation_.y, &entry->pivot);
                    func_ov017_0219b33c(resources, &event);
                }
                if (handled) {
                    if (!static_cast<unsigned char*>(resources->unknown_ptr_array_3700[4])[3]) break;
                    SetFlags08(resources, 8);
                    return;
                }
            }
        }
    }
    if (state[2]) {
        state[2] = 0;
        handled = 1;
    }
    if (!handled) return;
    GameState_SetZoneTransition(game, state);
    FieldTask_InitEnterZone((unsigned char*)resources->unknown_ptr_array_3700[3], 0);
    func_020469b4((TailList020469b4*)resources->fieldTaskQueue_, (TailNode020469b4*)resources->unknown_ptr_array_3700[3]);
    if (!state[0xa]) {
        Struct_ov017_0219ca88 header;
        header.id = container->currentZoneID_;
        if (Scenario_RunTrigger(lookup, 6, &header)) EventQuery_RunQueuedCommands(&header);
    }
}
