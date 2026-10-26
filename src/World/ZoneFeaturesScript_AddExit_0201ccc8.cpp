#include "Combat/Main/ElementLookup.h"
#include "GameState/GameState.h"
#include "Resource/Script.h"
#include "World/ZoneWarpScript.h"
#include <globaldefs.h>

// Main, originally ProcessExtraOpcode69Params_0201cb60 (USA 0x0201cb60, EUR 0x0201cb70, JPN 0x0201c8ec)
extern "C" ARM bool ZoneFeaturesScript_ParseExitDestination(Script::Parameter *param, int numParams, ZoneFeatures::Opcode68Entry &entry) {
    Script::Parameter *var0 = param;
    List0209998c *zoneTable       = static_cast<List0209998c *>(GameState_GetZoneTable(GameState::GetInstance()));

    entry.unk_0 = (param++)->ToInt();
    if (var0[1].type == 0) {
        Elem0209998c *destinationZone = ZoneTable_FindEntryByMapCode(zoneTable, (param++)->ToString());
        if (destinationZone == NULL) return false;
        entry.unk_1c = destinationZone->f0;
    } else {
        entry.unk_1c = (param++)->ToInt();
    }
    entry.unk_64[0] = (param++)->ToInt();
    entry.unk_64[1] = (param++)->ToInt();

    Vector3fix var3;
    param           = param->ToVec3fix(&var3);
    entry.unk_20[0] = var3;
    entry.unk_50    = 4096.0f * (param++)->ToFloat();

    if (numParams - (param - var0) > 0) {
        entry.unk_6c = (param++)->ToInt();
    }
    if (numParams - (param - var0) > 0) {
        param           = param->ToVec3fix(&var3);
        entry.unk_20[1] = var3;
        param           = param->ToVec3fix(&var3);
        entry.unk_20[2] = var3;
        param           = param->ToVec3fix(&var3);
        entry.unk_20[3] = var3;
    }
    return true;
}

// Main, originally WarpScript_Opcode_69_0201ccc8 (USA 0x0201ccc8, EUR 0x0201ccd8, JPN 0x0201ca54)
extern "C" ARM int ZoneFeaturesScript_AddExit(Script::Parameter *params, int numParams) {
    ZoneFeatures::Opcode68Entry entry;
    entry.func_0201ce10();
    Script::Parameter *param = params;
    fix32_t centreX      = (int) (4096.0f * (param++)->ToFloat());
    fix32_t centreY      = (int) (4096.0f * (param++)->ToFloat());
    fix32_t centreZ      = (int) (4096.0f * (param++)->ToFloat());
    fix32_t halfExtentX      = (int) (4096.0f * (param++)->ToFloat()) / 2;
    fix32_t halfExtentY      = (int) (4096.0f * (param++)->ToFloat()) / 2;
    fix32_t halfExtentZ      = (int) (4096.0f * (param++)->ToFloat()) / 2;

    fix32_t xMax = centreX + halfExtentX;
    fix32_t xMin = centreX - halfExtentX;
    fix32_t var10 = centreY + halfExtentY;
    fix32_t var11 = centreY - halfExtentY;
    fix32_t zMax = centreZ + halfExtentZ;
    fix32_t zMin = centreZ - halfExtentZ;

    entry.unk_58[1] = centreY;
    entry.unk_4[0]  = xMax;
    entry.unk_58[0] = centreX;
    entry.unk_58[2] = centreZ;
    entry.unk_4[1]  = var10;
    entry.unk_4[2]  = zMax;
    entry.unk_4[3]  = xMin;
    entry.unk_4[4]  = var11;
    entry.unk_4[5]  = zMin;

    if (!ZoneFeaturesScript_ParseExitDestination(param, numParams - (param - params), entry)) return 0;
    data_020fdc20.warp->CreateExit(entry);
    return 1;
}
