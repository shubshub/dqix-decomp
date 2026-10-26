#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

// A ZoneRecord (ZoneRecords_GetInstance's array of 4)
struct BigRecord020289c4 {
    unsigned short zoneId;
    unsigned short slotIndex : 2;
    unsigned short inUse : 1;
    unsigned short unknown_2_3_ : 13;
    char unknown_4_[0xc];
    SafeAllocator* allocator;
    SafeAllocator* secondAllocator;
#if defined(jpn)
    char unknown_18_[0x2fc];
#else
    char unknown1_18_[0x300];
#endif
};

struct ZoneObject020288e0 {
#if defined(jpn)
    char unknown_0_[0x150];
#else
    char unknown1_0_[0x15c];
#endif
    int field15c;
};

enum { kZoneRecordCount = 4, kFirstZoneMonsterSlot = 0x70, kMonstersPerZone = 12 };

extern "C" GameObject* func_0200fee0(GameState* gameState, int index);
extern "C" int func_02053ed0(void* object);
extern "C" void func_0200fd48(GameState* gameState, int slot);
extern "C" void ZoneRecord_Reset(BigRecord020289c4*);

// Main, originally func_020288e0 (USA 0x020288e0, EUR 0x020288f0, JPN 0x02028138)
extern "C" ARM void ZoneRecords_ReleaseUnoccupied(BigRecord020289c4* records)
{
    GameState* gameState = GameState::GetInstance();
    for (int i = 0; i < kZoneRecordCount; ++i) {
        BigRecord020289c4* record = &records[i];
        int zoneId = records[i].zoneId;
        if (!record->inUse) continue;
        bool occupied = false;
        for (int objectIndex = 0; objectIndex < 4; ++objectIndex) {
            GameObject* object = func_0200fee0(gameState, objectIndex);
            if (object == NULL) continue;
            if (!func_02053ed0(object)) {
                if (((Object3D*)object)->GetField06() != zoneId) continue;
            } else {
                if (zoneId != ((ZoneObject020288e0*)object)->field15c) continue;
            }
            occupied = true;
            break;
        }
        if (occupied) continue;
        for (int monster = 0; monster < kMonstersPerZone; ++monster) {
            func_0200fd48(gameState, monster + (i * kMonstersPerZone + kFirstZoneMonsterSlot));
        }
        ZoneRecord_Reset(record);
    }
}
