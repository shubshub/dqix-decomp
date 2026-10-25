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

void ClearCombatWorkFlags0x55f4_ov000_02160fbc(void* work, int mask);
void SetCombatWorkFlags0x55f4_ov000_02160fa8(void* work, int mask);
int GetCombatWorkFlags0x55f4_ov000_02160fd4(void* work, int mask);
void ResetBigStruct02013750(void* obj, int flag);
extern "C" void func_ov000_02172720(void* obj);

extern "C" void func_02079f9c(char* arg0);
struct Struct_020d6f0c;
struct Struct_020d6d18_2;
extern "C" void func_020d6f0c(struct Struct_020d6f0c* arg0);
extern "C" void func_020d6d18(struct Struct_020d6d18_2* arg0);
extern "C" void* func_02057924(void);
extern "C" void func_02057f00(void* self, int code);
extern "C" void func_ov017_021a05a8(GameResources* res);
extern "C" void func_ov017_0219b624(GameResources* res);
extern "C" void func_ov017_0219ba0c(GameResources* res, int v);
extern "C" void* Scenario_GetInstance(void);
extern "C" unsigned short* Zone3D_GetInstance(void);
struct SearchTable;
struct SearchEntry;
struct SearchTable* GetPtrField0x468_02011584(void* obj);
struct SearchEntry* FindEntryByHalfwordKey_02099950(struct SearchTable* table, int key);
extern "C" void Scenario_LoadZoneTriggers(void* a, struct SearchEntry* b);
void SetFieldsAndSignalData02184220_ov000_02160d80(void* p, int val);

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
    struct Struct_020d6d18_2* unknown_ea4_;
    int unknown_ea8_;
    int unknown_eac_;
#if defined(jpn)
    char unknown_e2c_[0xe44 - 0xe2c];
#else
    char unknown_eb0_[0xec8 - 0xeb0];
#endif
#if defined(jpn)
    char unknown_ec8_[0x371c - 0xe44];
#else
    char unknown_ec8_[0x3760 - 0xec8];
#endif
#if defined(jpn)
    char unknown_3760_[0x57f0 - 0x371c];
#else
    char unknown_3760_[0x5600 - 0x3760];
#endif
    Struct_02012fa4 unknown_5600_;
    Struct_02012fa4 unknown_5688_;
#if defined(jpn)
    char unknown_5900_[0x793c - 0x5900];
#else
    char unknown_5710_[0x774c - 0x5710];
#endif
    SafeAllocator unknown_774c_;
};

// USA: func_ov000_0216873c
extern "C" ARM void func_ov000_0216873c(struct BattleScene0216873c* scene) {
    GameState* gs = GameState::GetInstance();
    GameResources* res = gs->GetResources();
    if (scene->step == 0) {
        SetBrightness(res, -16, 15);
        scene->step++;
        return;
    }
    if (IsBrightnessTransitionActive(var1)) {
        return;
    }
    ClearCombatWorkFlags0x55f4_ov000_02160fbc(scene, 0x200);
    ResetBigStruct02013750(scene->bigStruct, 1);
    func_ov000_02172720(scene->field_0x3760);
    SetCombatWorkFlags0x55f4_ov000_02160fa8(scene, 0x800);
    ClearTwoRegions02079f9c((char*)GetData02108e10_020797dc());
    SprSprite_Unload(&scene->model0);
    SprSprite_Unload(&scene->model1);
    if (scene->entryManager != 0) {
        DestroyAllocatorAt0xa28((struct Obj020d6f0c*)scene->entryManager);
        ConstructEntryManager020d6d18(scene->entryManager);
        scene->entryManager = 0;
    }
    void* var2 = func_02057924();
    for (int* var3 = data_ov000_0218321c; *var3 >= 0; var3++) {
        func_02057f00(var2, *var3);
    }
    arg0->unknown_774c_.Destroy();
    for (int var4 = 0; var4 < Enum_ov000_0216873c_5; var4++) {
        arg0->unknown_8_[var4].Destroy();
    }
    if (func_ov000_02160fd4(arg0, 1)) {
        func_ov017_021a05a8(var1);
    }
    func_ov017_0219b624(var1);
#if !defined(jpn)
    func_ov017_0219ba0c(var1, 0);
#endif
    void* target = Scenario_GetInstance();
    unsigned short* key = Zone3D_GetInstance();
    Scenario_LoadZoneTriggers(target, FindEntryByHalfwordKey_02099950(GetPtrField0x468_02011584(gs), *key));
    if (scene->bgLayers != 0) {
        DISPCNT = (DISPCNT & ~0x1f00) | (scene->bgLayers << 8);
    }
    func_ov000_02160d80(arg0, 6);
}
