#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x244
#define REGION_OFFSET_1 0x2ac
#define REGION_OFFSET_2 0x3400
#define REGION_OFFSET_3 0x21c
#define REGION_OFFSET_4 0x288
#else
#define REGION_OFFSET_0 0x2c8
#define REGION_OFFSET_1 0x6f0
#define REGION_OFFSET_2 0x3000
#define REGION_OFFSET_3 0x2a0
#define REGION_OFFSET_4 0x2ec
#endif

#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "NitroSDK/Timing.h"
#include "World/Zone3D.h"
#include "Resource/GameResources.h"

extern "C" void LinkSession_GetInstance(void);
void Zone3D_Init(char* obj, int a, int b);
extern "C" void Zone3D_GetInstance(void);
int IsField0xcNonNegative_020a3694(int* obj);
void* GameState_GetZoneTable(void* obj);
struct SearchEntry;
struct SearchTable;
struct SearchEntry* ZoneTable_FindEntry(struct SearchTable* table, int key);
extern "C" void Main_HandleLid(void);
struct Obj0202fa00;
extern "C" void Zone3D_Update(void* p);
void BlankFunction020d84f4(void);
void SetCombatWorkFlags0x55f4_ov000_02160fa8(void* work, int mask);

// USA: func_ov000_02166880
ARM void InitAndProcessCombat02166880(unsigned char* obj) {
    ((int)GetGameResources());
    GameState* battle = GameState::GetInstance();
    struct Obj0202fa00* fieldObj = (struct Obj0202fa00*)(int)BackgroundLoader::GetInstance();
    battle->GetProtagonist();
    LinkSession_GetInstance();
    Zone3D_Init((char*)(obj + REGION_OFFSET_0 + 0xc00), (int)(obj + 8), (int)(obj + REGION_OFFSET_1 + REGION_OFFSET_2));
    Zone3D_GetInstance();

    if (IsField0xcNonNegative_020a3694(*(int**)(obj + REGION_OFFSET_3))) {
        unsigned short v = *(unsigned short*)((char*)*(int**)(obj + REGION_OFFSET_3) + 0x20);
        if (v != 0) *(unsigned short*)((char*)*(int**)(obj + REGION_OFFSET_3) + 2) = v;
    }

    void* table = GameState_GetZoneTable(battle);
    struct SearchEntry* entry = ZoneTable_FindEntry((struct SearchTable*)table,
        *(unsigned short*)((char*)*(int**)(obj + REGION_OFFSET_3) + 2));
    if (entry == NULL || *(unsigned short*)((char*)*(int**)(obj + REGION_OFFSET_3) + 2) == 30000) {
        *(unsigned short*)((char*)*(int**)(obj + REGION_OFFSET_3) + 2) = 0x75a4;
    }
    ((Zone3D*)(obj + REGION_OFFSET_0 + 0xc00))->SwitchZone(*(unsigned short*)((char*)*(int**)(obj + REGION_OFFSET_3) + 2), 0);

    GetCurrentTimestamp();
    for (;;) {
        Main_HandleLid();
        ((BackgroundLoader*)(fieldObj))->RemoveAllLocks();
        Zone3D_Update(obj + REGION_OFFSET_0 + 0xc00);
        if (*(int*)(obj + 0x1000 + REGION_OFFSET_4) == 0) break;
        BlankFunction020d84f4();
    }
    SetCombatWorkFlags0x55f4_ov000_02160fa8(obj, 0x10);
}
