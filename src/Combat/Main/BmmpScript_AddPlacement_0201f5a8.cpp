#include <globaldefs.h>
#include "Resource/Script.h"
#include "Combat/CombatScriptContext.h"

// A Script::Parameter (Resource/Script.h)
struct Variant02030b0c {
    int type;
    union { int i; float f; } value;
};
extern "C" void MapDisplay_AddPlacement(void*, int, int, int, int);

// Opcode 0x68's parameters: a value that is 0 in every .bmmp file, the id of the map graphic (opcode 0x66) to
// place, and the tile position to place it at
struct Vec4Variant0201f5a8 {
    struct Variant02030b0c reserved;
    struct Variant02030b0c graphicId;
    struct Variant02030b0c tileX;
    struct Variant02030b0c tileY;
};

// Main, originally SetDecodedIntEntry0201f5a8 (USA 0x0201f5a8, EUR 0x0201f5b8, JPN 0x0201f334)
extern "C" ARM int BmmpScript_AddPlacement(struct Vec4Variant0201f5a8* params) {
    int reserved = ((Script::Parameter*)&params->reserved)->ToInt();
    int graphicId = ((Script::Parameter*)&params->graphicId)->ToInt();
    int tileX = ((Script::Parameter*)&params->tileX)->ToInt();
    int tileY = ((Script::Parameter*)&params->tileY)->ToInt();
    MapDisplay_AddPlacement((void*)data_020fdc4c.currentObject, reserved, graphicId, tileX, tileY);
    return 1;
}
