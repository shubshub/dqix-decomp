#include <globaldefs.h>
#include "Resource/Script.h"
#include "Combat/CombatScriptContext.h"


// One pair of opcode 0x70's parameters: a zone id and its name code (M01.bmmp: 1100 "M01", 1101 "M01M01", ...)
struct ZoneNamePair0201f8d0 { Script::Parameter zoneId; Script::Parameter name; };
struct Obj02026b0c;
struct Obj02026b3c;
#if defined(jpn)
extern "C" void MapDisplay_SetRedChestZone(struct Obj02026b3c* obj, unsigned int index, unsigned short id, const char* name);
#endif

void MapDisplay_ClearRedChests(char* obj);
void MapDisplay_AllocateRedChestZones(struct Obj02026b0c* p, int n);
#if !defined(jpn)
extern "C" void _Z26MapDisplay_SetRedChestZoneP11Obj02026b3cjsPKc(Obj02026b3c*, unsigned int, unsigned short, const char*);
#define MapDisplay_SetRedChestZone _Z26MapDisplay_SetRedChestZoneP11Obj02026b3cjsPKc
#endif

// Main, originally func_0201f8d0 (USA 0x0201f8d0, EUR 0x0201f8e0, JPN 0x0201f65c)
extern "C" ARM int BmmpScript_SetRedChestZones(struct ZoneNamePair0201f8d0* pairs, int paramCount) {
    int pairCount = paramCount / 2;
    void* map = data_020fdc4c.currentObject;
    MapDisplay_ClearRedChests((char*)map);
    map = data_020fdc4c.currentObject;
    MapDisplay_AllocateRedChestZones((struct Obj02026b0c*)map, pairCount & 0xff);
    struct ZoneNamePair0201f8d0* pair = pairs;
    for (int i = 0; i < pairCount; i++) {
        int zoneId = pair->zoneId.ToInt();
        const Script::Parameter* nameParam = &pair->name;
        pair++;
        const char* name = nameParam->ToString();
        map = data_020fdc4c.currentObject;
        MapDisplay_SetRedChestZone((struct Obj02026b3c*)map, (unsigned char)i, zoneId, name);
    }
    return 1;
}
