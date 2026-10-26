#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/ActiveGrottoClass.h"
#include "Resource/GameResources.h"


#if defined(jpn)
#include "std_library_functions.h"
extern const char data_020f1438[];
#endif

struct ZoneState { unsigned short zoneId; unsigned short nextZoneId; };
struct TailList020469b4;
struct TailNode020469b4;
struct Struct_0205faf4_7;
struct Struct_0205faf4_8 { unsigned int unknown_0_0_:14, b14:1; };
struct Struct_0208fc30 { char unknown_0_[8]; unsigned short h8; };

extern "C" ZoneState* Zone3D_GetInstance();
extern "C" int* LinkSession_GetInstance();
extern "C" unsigned char* Scenario_GetInstance();
extern "C" int LinkSession_IsHostOrSolo(void* obj);
extern "C" void func_ov017_021baedc(void* obj, int flag);
extern "C" struct Struct_0205faf4_7* func_02094d6c();
extern "C" struct Struct_0205faf4_8* func_02096134(struct Struct_0205faf4_7*, int);
extern "C" void func_020469b4(struct TailList020469b4*, struct TailNode020469b4*);
extern "C" int Scenario_TestFlag(int, unsigned char*, int);
extern "C" void Scenario_SetFlag(void*, unsigned char*, int, int);
extern "C" void func_ov017_021beba4(char*);
extern "C" int ZoneId_IsGrotto(int);
extern "C" void* GameState_GetZoneTransition(GameState* battleStruct);

// JPN: func_02090544
// USA: func_0208fc30
extern "C" ARM void func_0208fc30(ActiveGrottoClass* obj) {
#if defined(jpn)
    unsigned char* state;
    GameResources* resources;
    bool changed;
    int* session;
    const char* var0;
    int nextZoneId;
    struct TailList020469b4* list;
    int zoneId;
    void* node;
#else
    int* session;
    unsigned char* state;
    GameResources* resources;
    GrottoStruct* grotto;
    int zoneId;
    int nextZoneId;
    struct TailList020469b4* list;
#endif
    ZoneState* zone = Zone3D_GetInstance();
    zoneId = zone->zoneId;
    nextZoneId = zone->nextZoneId;
    session = LinkSession_GetInstance();
    state = Scenario_GetInstance();
    GameState* game = GameState::GetInstance();
    GameState_GetZoneTransition(game);
    resources = GetGameResources();
    list = (struct TailList020469b4*)resources->fieldTaskQueue_;
#if !defined(jpn)
    grotto = game->GetGrottoStruct();
#endif

    if (ZoneId_IsGrotto(zoneId) && !ZoneId_IsGrotto(nextZoneId) &&
        (nextZoneId < 0x7530 || nextZoneId > 0x9c3f)) {
#if defined(jpn)
        changed = false;
#else
        void* node;
        bool changed = false;
#endif
        if (LinkSession_IsHostOrSolo(session)) {
            node = resources->unknown_ptr_array_371c[6];
            func_ov017_021baedc(node, 1);
            struct Struct_0205faf4_7* table = func_02094d6c();
#if defined(jpn)
            var0 = "\x96\xb2";
            const char* var13 = obj->GetPopupName();
            if (strstr(var13, var0) != NULL &&
#else
            if (*(unsigned short*)grotto->unk_a == 6 &&
#endif
                Scenario_TestFlag((int)state, state + 0x8c, 0x12) &&
                !Scenario_TestFlag((int)state, state + 0x8c, 0x2d) &&
                !func_02096134(table, 0xae)->b14) {
                ((struct Struct_0208fc30*)node)->h8 = 0x5105;
                func_020469b4(list, (struct TailNode020469b4*)node);
                changed = true;
                Scenario_SetFlag(state, state + 0x8c, 0x2d, 1);
            } else if (obj->GetActiveGrottoEnviron() == 2 &&
                       Scenario_TestFlag((int)state, state + 0x8c, 0x13) &&
                       !Scenario_TestFlag((int)state, state + 0x8c, 0x2e) &&
                       !func_02096134(table, 0xc1)->b14) {
                ((struct Struct_0208fc30*)node)->h8 = 0x51c3;
                func_020469b4(list, (struct TailNode020469b4*)node);
                changed = true;
                Scenario_SetFlag(state, state + 0x8c, 0x2e, 1);
            }
        }
        if (!changed && (unsigned char)obj->unknown_260_[0] == 0) {
            void* node = resources->fieldTasks_[28];
            func_ov017_021beba4((char*)node);
            func_020469b4(list, (struct TailNode020469b4*)node);
        }
    } else {
        if ((unsigned char)obj->unknown_260_[1] != 0) {
            void* node = resources->fieldTasks_[28];
            func_ov017_021beba4((char*)node);
            func_020469b4(list, (struct TailNode020469b4*)node);
            obj->unknown_260_[1] = 0;
        }
    }
}
