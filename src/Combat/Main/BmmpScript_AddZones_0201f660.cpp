#include <globaldefs.h>

#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"
#include "Combat/CombatScriptContext.h"
#include "Combat/MapDisplay.h"

// One of MapDisplay's zone lists (field754): the zone ids a .bmmp map covers. Opcode 0x6b adds one of type 0 (no
// position); opcode 0x6c (func_0201f728) one of type 1 with a map position. id numbers them from 1, newest first
struct Node02021f88 {
    unsigned char type;
    unsigned char id;
    unsigned char zoneCount;
    unsigned char pad3;
    short* zoneIds;
    int x;
    int y;
    struct Node02021f88* next;
};

// Main, originally func_0201f660 (USA 0x0201f660, EUR 0x0201f670, JPN 0x0201f3ec)
extern "C" ARM int BmmpScript_AddZones(Script::Parameter* params, int count) {
    struct Node02021f88* list = (struct Node02021f88*)data_020fdc4c.allocator->Allocate(sizeof(struct Node02021f88));
    if (list == 0) return 0;
    list->type = 0;
    list->zoneCount = count;
    list->zoneIds = (short*)data_020fdc4c.allocator->Allocate(list->zoneCount * sizeof(short));
    if (list->zoneIds == 0) return 0;
    for (int i = 0; i < list->zoneCount; i++) {
        list->zoneIds[i] = (short)params->ToInt();
        params++;
    }
    struct Node02021f88* head = ((MapDisplay*)data_020fdc4c.currentObject)->field754;
    list->id = head ? head->id + 1 : 1;
    list->next = ((MapDisplay*)data_020fdc4c.currentObject)->field754;
    ((MapDisplay*)data_020fdc4c.currentObject)->field754 = list;
    return 1;
}
