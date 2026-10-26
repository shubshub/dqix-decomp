#include <globaldefs.h>
#include "Resource/Script.h"
#include "Combat/CombatScriptContext.h"
#include "Combat/MapDisplay.h"

// Main, originally StoreTwoDecodedIntsAt0x18_0201f4cc (USA 0x0201f4cc, EUR 0x0201f4dc, JPN 0x0201f258)
extern "C" ARM int BmmpScript_SetImageOrigin(Script::Parameter* paramsIn) {
    const Script::Parameter* params = paramsIn;
    int tileX = params[0].ToInt();
    int tileY = params[1].ToInt();
    MapDisplay* map = (MapDisplay*)data_020fdc4c.currentObject;
    map->forwardingX = tileX;
    map->forwardingY = tileY;
    return 1;
}
