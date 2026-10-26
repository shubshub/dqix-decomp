#include <globaldefs.h>
#include "Resource/Script.h"

struct StreamHeader;

// The zone being looked up; maplist9.bin's opcode table (0x66-0x69)
extern int data_020ef2bc;
extern Script::OpcodeLookupEntry data_020ef2c0[];

struct MapListScriptState0201c724 {
    int unknown0;
    void* output;
    int unknown8;
};
extern struct MapListScriptState0201c724 data_020fdc14;

// Main, originally func_0201c724 (USA 0x0201c724, EUR 0x0201c734, JPN 0x0201c4b0)
extern "C" ARM void MapListScript_LookUpZone(int zoneId, void* output, struct StreamHeader* mapList, int mapListLength) {
    Script script;
    data_020fdc14.output = output;
    data_020ef2bc = zoneId;
    script.Initialize();
    script.SetOpcodeLookup(data_020ef2c0);
    script.Load(mapList, mapListLength);
    script.Execute();
    data_020fdc14.output = 0;
    data_020ef2bc = -1;
}
