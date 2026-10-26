#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"

// A ZoneRecord (ZoneRecords_GetInstance's array of 4)
struct BigRecord020289c4 {
    unsigned short zoneId;
    unsigned short slotIndex : 2;
    unsigned short inUse : 1;
    unsigned short otherFlags : 13;
    char reserved4[0xc];
    SafeAllocator* allocator;
#if !defined(jpn)
    SafeAllocator* secondAllocator;
#endif
    char reserved18[0x300];
};

struct ZoneMonsterObject {
    GameObject object;
    char reserved13c[0x5c];
};

enum { kZoneRecordCount = 4, kFirstZoneMonsterSlot = 0x70, kMonstersPerZone = 12 };

void ZoneRecord_Reset(BigRecord020289c4*);
void ClearCombatantSlot_0200fd48(GameState*, int);
void RegisterCombatantSlot_0200fd38(GameState*, int, GameObject*);
extern "C" void LinkSession_GetInstance();
extern "C" void Zone3D_GetInstance();
extern "C" void FieldMonsterState_Init(GameObject*);

// Main, originally func_02028a54 (USA 0x02028a54, EUR 0x02028a64, JPN 0x020282ac)
extern "C" ARM int ZoneRecords_Add(BigRecord020289c4* records, int zoneId)
{
    GameState* gameState = GameState::GetInstance();
    LinkSession_GetInstance();
    GetGameResources();
    Zone3D_GetInstance();
    gameState->GetGrottoStruct();
    for (int i = 0; i < kZoneRecordCount; ++i) {
        if (zoneId == records[i].zoneId) return 0;
    }
    int freeIndex = -1;
    for (int i = 0; i < kZoneRecordCount; ++i) {
        if (!records[i].inUse) {
            freeIndex = i;
            break;
        }
    }
    if (freeIndex < 0) return 0;
    BigRecord020289c4* record = &records[freeIndex];
    ZoneRecord_Reset(record);
    record->inUse = 1;
    record->zoneId = zoneId;
    record->allocator->Reset();
#if !defined(jpn)
    record->secondAllocator->Reset();
#endif
    ZoneMonsterObject* monsters = (ZoneMonsterObject*)record->allocator->Allocate(kMonstersPerZone * sizeof(ZoneMonsterObject));
    int i = 0;
    if (!monsters) {
        int firstSlot = freeIndex * kMonstersPerZone + kFirstZoneMonsterSlot;
        for (; i < kMonstersPerZone; ++i) ClearCombatantSlot_0200fd48(gameState, i + firstSlot);
        return 0;
    }
    int firstSlot = freeIndex * kMonstersPerZone;
    firstSlot += kFirstZoneMonsterSlot;
    for (; i < kMonstersPerZone; ++i) {
        FieldMonsterState_Init(&monsters[i].object);
        monsters[i].object.obj3D_.MakeHidden();
        RegisterCombatantSlot_0200fd38(gameState, i + firstSlot, &monsters[i].object);
    }
    return 1;
}
