#include <globaldefs.h>
#include "Resource/ActionDataTables.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/Brightness.h"
#include "NitroSDK/Graphics.h"
#include "World/ZoneLootableRecord.h"


#if defined(jpn)
enum { Enum_ov000_0216873c_5 = 4 };
#else
enum { Enum_ov000_0216873c_5 = 5 };
#endif

extern "C" void func_ov000_02160fbc(void* work, int mask);
extern "C" void func_ov000_02160fa8(void* work, int mask);
extern "C" int func_ov000_02160fd4(void* work, int mask);
extern "C" void Zone3D_Unload(void* obj, int flag);
extern "C" void func_ov000_02172720(void* obj);

extern "C" void func_02079f9c(char* obj);
struct Struct_020d6f0c;
struct Struct_020d6d18_2;
extern "C" void func_020d6f0c(struct Struct_020d6f0c* self);
extern "C" void func_020d6d18(struct Struct_020d6d18_2* self);
extern "C" void* func_02057924(void);
extern "C" void func_02057f00(void* self, int code);
extern "C" void func_ov017_021a05a8(GameResources* res);
extern "C" void func_ov017_0219b624(GameResources* res);
extern "C" void func_ov017_0219ba0c(GameResources* res, int v);
extern "C" void* Scenario_GetInstance(void);
extern "C" unsigned short* Zone3D_GetInstance(void);
struct SearchTable;
struct SearchEntry;
extern "C" struct SearchTable* GameState_GetZoneTable(void* obj);
extern "C" struct SearchEntry* ZoneTable_FindEntry(struct SearchTable* table, int key);
extern "C" void Scenario_LoadZoneTriggers(void* a, struct SearchEntry* b);
extern "C" void func_ov000_02160d80(void* p, int val);

extern int data_ov000_0218321c[];

struct Struct_ov000_0216873c {
    int unknown_0_;
    char unknown_4_[4];
    SafeAllocator unknown_8_[Enum_ov000_0216873c_5];
#if defined(jpn)
    char unknown_58_[0xe20 - 0x58];
#else
    char unknown_6c_[0xea4 - 0x6c];
#endif
    struct Struct_020d6d18_2* entryManager;
    int state;
    int step;
#if defined(jpn)
    char unknown_e2c_[0xe44 - 0xe2c];
#else
    char unknown_eb0_[0xec8 - 0xeb0];
#endif
#if defined(jpn)
    char bigStruct[0x371c - 0xe44];
#else
    char bigStruct[0x3760 - 0xec8];
#endif
#if defined(jpn)
    char unknown_3760_[0x57f0 - 0x371c];
#else
    char unknown_3760_[0x5600 - 0x3760];
#endif
    Foo02048004 model0;
    Foo02048004 model1;
#if defined(jpn)
    char unknown_5900_[0x793c - 0x5900];
#else
    char unknown_5710_[0x774c - 0x5710];
#endif
    SafeAllocator heap;
};

// USA: func_ov000_0216873c
extern "C" ARM void func_ov000_0216873c(struct Struct_ov000_0216873c* scene) {
    GameState* gs = GameState::GetInstance();
    GameResources* res = gs->GetResources();
    if (scene->step == 0) {
        SetBrightness(res, -16, 15);
        scene->step++;
        return;
    }
    if (IsBrightnessTransitionActive(res)) {
        return;
    }
    func_ov000_02160fbc(scene, 0x200);
    Zone3D_Unload(scene->bigStruct, 1);
    func_ov000_02172720(scene->unknown_3760_);
    func_ov000_02160fa8(scene, 0x800);
    func_02079f9c((char*)func_020797dc());
    SprSprite_Unload(&scene->model0);
    SprSprite_Unload(&scene->model1);
    if (scene->entryManager != 0) {
        func_020d6f0c((struct Struct_020d6f0c*)scene->entryManager);
        func_020d6d18(scene->entryManager);
        scene->entryManager = 0;
    }
    void* combat = func_02057924();
    for (int* code = data_ov000_0218321c; *code >= 0; code++) {
        func_02057f00(combat, *code);
    }
    scene->heap.Destroy();
    for (int i = 0; i < Enum_ov000_0216873c_5; i++) {
        scene->unknown_8_[i].Destroy();
    }
    if (func_ov000_02160fd4(scene, 1)) {
        func_ov017_021a05a8(res);
    }
    func_ov017_0219b624(res);
#if !defined(jpn)
    func_ov017_0219ba0c(res, 0);
#endif
    void* target = Scenario_GetInstance();
    unsigned short* key = Zone3D_GetInstance();
    Scenario_LoadZoneTriggers(target, ZoneTable_FindEntry(GameState_GetZoneTable(gs), *key));
    if (scene->unknown_0_ != 0) {
        DISPCNT = (DISPCNT & ~0x1f00) | (scene->unknown_0_ << 8);
    }
    func_ov000_02160d80(scene, 6);
}
