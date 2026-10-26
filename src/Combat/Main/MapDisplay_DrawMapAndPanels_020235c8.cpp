#include <globaldefs.h>

#if defined(jpn)
enum { kModeOffset = 0x915, kFlagsOffset = 0x9cb, kBattleFlagsOffset = 0xa6c };
#else
enum { kModeOffset = 0x9c1, kFlagsOffset = 0xa97, kBattleFlagsOffset = 0xccc };
#endif

#include "GameState/GameState.h"

void* GlobalFlags_GetInstance(void);

struct FlagWord02046708;
int FlagWord_TestBits(struct FlagWord02046708* word, unsigned int mask);

void ApplyBitfieldsForTableEntries02026ebc(void* obj);
void MapDisplay_DrawMemberPanels(unsigned char* obj);

extern "C" {
    void MapDisplay_DrawTreasureMap(void* obj);
    void MapDisplay_DrawWorldMap(void* obj);
    void MapDisplay_DrawGrottoIcons(void* obj);
    void MapDisplay_DrawMapNameFrame(void* obj);
    void MapDisplay_DrawFreeScrollMap(void* obj);
    void func_02024e78(void* obj);
    void func_020251bc(void* obj);
    void func_0202555c(void* obj);
    void func_02025b0c(void* obj);
    void MapDisplay_UpdateHpColors(void* obj);
    void func_020dc7e8(int a, int b);
}

struct BattleFlags5ccc020235c8 {
    char pad[kBattleFlagsOffset];
    unsigned int flagsBit0 : 1;
    signed int flagsBit1 : 1;
    unsigned int flagsRest : 30;
};

// The MapDisplay fields this reads (header: displayMode, field9c1, flags at 0xa97)
struct Obj020235c8 {
    char pad0[0x14];
    int displayMode; // the map layout, from the zone's map type (MapDisplay_LoadLocalMap)
    char pad1[kModeOffset - 0x18];
    unsigned char mode; // what MapDisplay_SetMode set: 1 treasure map, 4 world map
    char pad2[kFlagsOffset - (kModeOffset + 1)];
    unsigned char panelFlags; // bit 0 (SetFlagsAt0xa97, ClearFlags0xa97_02027bbc): leave out the member panels
};

// Main, originally ProcessCombatantState020235c8 (USA 0x020235c8, EUR 0x020235d8, JPN 0x02022f90)
ARM void MapDisplay_DrawMapAndPanels(struct Obj020235c8* obj) {
    GameState* game = GameState::GetInstance();

    if (FlagWord_TestBits((struct FlagWord02046708*)GlobalFlags_GetInstance(), 0x41)) {
        return;
    }

    unsigned char mode = obj->mode;
    switch (mode) {
    case 1:
        MapDisplay_DrawTreasureMap(obj);
        break;
    case 4:
        MapDisplay_DrawWorldMap(obj);
        break;
    default:
        MapDisplay_DrawGrottoIcons(obj);
        MapDisplay_DrawMapNameFrame(obj);
        ApplyBitfieldsForTableEntries02026ebc(obj);
        switch (obj->displayMode) {
        case 0:
            MapDisplay_DrawFreeScrollMap(obj);
            break;
        case 1:
            func_02024e78(obj);
            break;
        case 2:
            func_020251bc(obj);
            break;
        case 3:
            func_0202555c(obj);
            break;
        case 4:
            func_02025b0c(obj);
            break;
        }
        break;
    }

    MapDisplay_UpdateHpColors(obj);
    if (!(obj->panelFlags & 1)) {
        MapDisplay_DrawMemberPanels((unsigned char*)obj);
    }

    if (((struct BattleFlags5ccc020235c8*)((char*)game + 0x5000))->flagsBit1) {
        func_020dc7e8(6, 6 - 7);
        func_020dc7e8(7, 7 - 8);
    }
}
