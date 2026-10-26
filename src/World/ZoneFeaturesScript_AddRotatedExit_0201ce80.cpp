#include "World/ZoneWarpScript.h"

// Main, originally WarpScript_Opcode_72_0201ce80 (USA 0x0201ce80, EUR 0x0201ce90, JPN 0x0201cc0c)
extern "C" ARM int ZoneFeaturesScript_AddRotatedExit(Script::Parameter *params, int numParams) {
    Script::Parameter *paramsStart = params;
    ZoneFeatures::Opcode68Entry entry;
    entry.func_0201ce10();
    fix32_t centreX     = (int) (4096.0f * (params++)->ToFloat());
    fix32_t centreY     = (int) (4096.0f * (params++)->ToFloat());
    fix32_t centreZ     = (int) (4096.0f * (params++)->ToFloat());
    fix32_t var5 = (int) (4096.0f * (params++)->ToFloat()) / 2;
    fix32_t var6 = (int) (4096.0f * (params++)->ToFloat()) / 2;
    fix32_t var7 = (int) (4096.0f * (params++)->ToFloat()) / 2;

    entry.unk_4[0] = centreX + var5;
    entry.unk_4[1] = centreY + var6;
    entry.unk_4[2] = centreZ + var7;
    entry.unk_4[3] = centreX - var5;
    entry.unk_4[4] = centreY - var6;
    entry.unk_4[5] = centreZ - var7;

    entry.unk_58[0] = centreX;
    entry.unk_58[1] = centreY;
    entry.unk_58[2] = centreZ;

    entry.unk_52 = 4096.0f * (params++)->ToFloat();

    fix32_t var8 = FIX32_MULTIPLY(var5, var5);
    fix32_t var9 = FIX32_MULTIPLY(var7, var7);
    entry.unk_54               = var9;
    entry.unk_54               = var8 + var9;

    if (!ZoneFeaturesScript_ParseExitDestination(params, numParams - (params - paramsStart), entry)) return 0;
    data_020fdc20.warp->CreateExit(entry);
    return 1;
}
