#include <globaldefs.h>
#include "GameState/GameState.h"
#include "World/Zone3D.h"
#include "Filesystem/BackgroundLoader.h"
#include "Resource/Brightness.h"
#include "Combat/Main/CopyRecord0200fbb4.h"


struct Struct_ov009_0218aa28 { int unknown_0_, unknown_4_, unknown_8_; };
struct Struct_02000c9c_56 { Vector3fix unknown_0_, unknown_c_; };
struct Struct_02046b38;
struct Struct_02046b38_2;
struct Struct_02015438;
struct Struct_0201bdac_2;
struct Struct_0201bdac;
struct Struct_ov017_0219ca88_2 {
    int unknown_0_;
    Struct_02000c9c_56 unknown_4_;
    int unknown_1c_;
    Vector3fix unknown_20_;
    Vector3fix unknown_2c_, unknown_38_, unknown_44_;
    short unknown_50_, unknown_52_;
    int unknown_54_;
    Vector3fix unknown_58_;
    unsigned char unknown_64_[8];
    int unknown_6c_;
};
#if defined(jpn)
enum { Enum_ov017_0219ca88_396 = 0x180 };
#else
enum { Enum_ov017_0219ca88_396 = 0x18c };
#endif
struct Struct_ov017_0219ca88_3 { unsigned char unknown_0_, unknown_1_; unsigned short unknown_2_; unsigned char unknown_4_; Struct_ov017_0219ca88_2* unknown_8_; int unknown_c_; unsigned short unknown_10_, unknown_12_; };
struct Struct_ov017_0219ca88 { unsigned int unknown_0_, unknown_4_, unknown_8_, unknown_c_; unsigned char unknown_10_[0x24]; };

extern "C" Zone3D* Zone3D_GetInstance();
void* GameState_GetZoneTransition(GameState*);
extern "C" void* Scenario_GetInstance(void*);
int ListContainsNode(ListHead02046b38*, ListNode02046b38*);
int FieldTaskQueue_GetCurrentKind(HeadNode02046b24**);
int FieldTaskQueue_IsEmpty(void**);
void SetObjFieldIfFound_0219bed0(void*);
unsigned char GetByte0x4_0200fb9c(char*);
int GetWord0x7f6c_0201201c(void*);
int GameState_GetProtagonistIndex(GameState*);
extern "C" int Bounds3D_ContainsPointRotated(const Vector3fix*, Bounds*, int, const Vector3fix*, int);
extern "C" void* func_ov017_0219c6f4(void*);
unsigned char GameObject_IsControlEnabled(void*);
void InitObj0219a674(unsigned char*);
short GetAbsAngleDeltaBetween_021a4754(Vector3fix*, int, Vector3fix*);
extern "C" void func_ov017_0219b33c(GameResources*, Event0219ca88*);
void FieldTask_InitEnterZone(unsigned char*, int);
void AppendNodeToTail(TailList020469b4*, TailNode020469b4*);
int Scenario_RunTrigger(void*, int, void*);
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
    if (ListContainsNode((ListHead02046b38*)resources->fieldTaskQueue_, (ListNode02046b38*)resources->unknown_ptr_array_3700[3])) return;
    if (FieldTaskQueue_GetCurrentKind((HeadNode02046b24**)resources->fieldTaskQueue_) == 4) return;
    if (FieldTaskQueue_GetCurrentKind((HeadNode02046b24**)resources->fieldTaskQueue_) == 10) return;
    if (TestFlags08(resources, 8)) {
        if (static_cast<unsigned char*>(resources->unknown_ptr_array_3700[4])[3]) return;
        if (IsMainBrightnessTransitionActive(resources)) return;
        ClearFlags08(resources, 8);
    }
    if (ListContainsNode((ListHead02046b38*)resources->fieldTaskQueue_, (ListNode02046b38*)resources->unknown_ptr_array_371c[0])) return;
    if (FieldTaskQueue_IsEmpty((void**)resources->fieldTaskQueue_) && !IsBrightnessTransitionActive(resources) && ((unsigned char*)resources->unknown_42e3)[6]) {
        if (state[2]) state[0xa] = 0;
        else SetObjFieldIfFound_0219bed0((void*)1);
        resources->unknown_42e3[6] = 0;
    }
    int eligible = 1;
    if (GetByte0x4_0200fb9c((char*)game) != 6 && GetWord0x7f6c_0201201c(game) != 5) {
        if (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(actor) + ActorFlagsOffset) & 1) eligible = 0;
        else if (state[2]) eligible = 0;
        if (eligible) {
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
                    Event0219ca88 event;
                    InitObj0219a674((unsigned char*)&event);
                    event.kind = 8;
                    event.entry = entry;
                    event.angle = GetAbsAngleDeltaBetween_021a4754(actorPosition, (short)actor->obj3D_.rotation_.y, &entry->pivot);
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
    if (var3[2]) {
        var3[2] = 0;
        var5 = 1;
    }
    if (!handled) return;
    GameState_SetZoneTransition(game, state);
    FieldTask_InitEnterZone((unsigned char*)resources->unknown_ptr_array_3700[3], 0);
    AppendNodeToTail((TailList020469b4*)resources->fieldTaskQueue_, (TailNode020469b4*)resources->unknown_ptr_array_3700[3]);
    if (!state[0xa]) {
        Header0219ca88 header;
        header.id = container->currentZoneID_;
        if (Scenario_RunTrigger(lookup, 6, &header)) EventQuery_RunQueuedCommands(&header);
    }
}
