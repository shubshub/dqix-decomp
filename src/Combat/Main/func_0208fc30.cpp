#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/ActiveGrottoClass.h"
#include "Resource/GameResources.h"


#if defined(jpn)
#include "std_library_functions.h"
extern const char data_020f1438[];
#endif

struct Struct_0208fa8c { unsigned short unknown_0_; unsigned short unknown_2_; };
struct Struct_0201bdac_2;
struct Struct_0201bdac;
struct Struct_0205faf4_7;
struct Struct_0205faf4_8 { unsigned int unknown_0_0_:14, unknown_1_6_:1; };
struct Struct_0208fc30 { char unknown_0_[8]; unsigned short unknown_8_; };

extern "C" ZoneState* Zone3D_GetInstance();
extern "C" int* func_0202ae18();
extern "C" unsigned char* Scenario_GetInstance();
extern "C" int func_0202c508(void* obj);
extern "C" void func_ov017_021baedc(void* obj, int flag);
struct FindEntryById02096134Table* GetGlobal02109418_02094d6c();
struct FindEntryById02096134Elem* FindEntryById02096134(struct FindEntryById02096134Table*, int);
void AppendNodeToTail(struct TailList020469b4*, struct TailNode020469b4*);
int Scenario_TestFlag(int, unsigned char*, int);
extern "C" void Scenario_SetFlag(void*, unsigned char*, int, int);
void InitObj021beba4(char*);
int IsInRange0201b588(int);
void* GetField0x3f8Address_0200fd0c(GameState* battleStruct);

// JPN: func_02090544
// USA: func_0208fc30
extern "C" ARM void func_0208fc30(ActiveGrottoClass* arg0) {
#if defined(jpn)
    unsigned char* var2;
    GameResources* var3;
    bool var11;
    int* var1;
    const char* var0;
    int var6;
    struct Struct_0201bdac_2* var7;
    int var5;
    void* var10;
#else
    int* var1;
    unsigned char* var2;
    GameResources* var3;
    GrottoStruct* var4;
    int var5;
    int var6;
    struct Struct_0201bdac_2* var7;
#endif
    ZoneState* zone = Zone3D_GetInstance();
    zoneId = zone->zoneId;
    nextZoneId = zone->nextZoneId;
    session = func_0202ae18();
    state = Scenario_GetInstance();
    GameState* game = GameState::GetInstance();
    GetField0x3f8Address_0200fd0c(game);
    resources = GetGameResources();
    list = (struct TailList020469b4*)resources->fieldTaskQueue_;
#if !defined(jpn)
    var4 = var9->GetGrottoStruct();
#endif

    if (func_0201b588(var5) && !func_0201b588(var6) &&
        (var6 < 0x7530 || var6 > 0x9c3f)) {
#if defined(jpn)
        var11 = false;
#else
        void* var10;
        bool var11 = false;
#endif
        if (func_0202c508(var1)) {
            var10 = var3->unknown_ptr_array_371c[6];
            func_ov017_021baedc(var10, 1);
            struct Struct_0205faf4_7* var12 = func_02094d6c();
#if defined(jpn)
            var0 = "\x96\xb2";
            const char* var13 = arg0->GetPopupName();
            if (strstr(var13, var0) != NULL &&
#else
            if (*(unsigned short*)var4->unk_a == 6 &&
#endif
                Scenario_TestFlag((int)state, state + 0x8c, 0x12) &&
                !Scenario_TestFlag((int)state, state + 0x8c, 0x2d) &&
                !FindEntryById02096134(table, 0xae)->b14) {
                ((struct GrottoListNode*)node)->h8 = 0x5105;
                AppendNodeToTail(list, (struct TailNode020469b4*)node);
                changed = true;
                Scenario_SetFlag(state, state + 0x8c, 0x2d, 1);
            } else if (obj->GetActiveGrottoEnviron() == 2 &&
                       Scenario_TestFlag((int)state, state + 0x8c, 0x13) &&
                       !Scenario_TestFlag((int)state, state + 0x8c, 0x2e) &&
                       !FindEntryById02096134(table, 0xc1)->b14) {
                ((struct GrottoListNode*)node)->h8 = 0x51c3;
                AppendNodeToTail(list, (struct TailNode020469b4*)node);
                changed = true;
                Scenario_SetFlag(state, state + 0x8c, 0x2e, 1);
            }
        }
        if (!changed && (unsigned char)obj->unknown_260_[0] == 0) {
            void* node = resources->fieldTasks_[28];
            InitObj021beba4((char*)node);
            AppendNodeToTail(list, (struct TailNode020469b4*)node);
        }
    } else {
        if ((unsigned char)obj->unknown_260_[1] != 0) {
            void* node = resources->fieldTasks_[28];
            InitObj021beba4((char*)node);
            AppendNodeToTail(list, (struct TailNode020469b4*)node);
            obj->unknown_260_[1] = 0;
        }
    }
}
