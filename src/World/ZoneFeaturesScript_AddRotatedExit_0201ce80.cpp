#include "World/ZoneWarpScript.h"

// Main, originally WarpScript_Opcode_72_0201ce80 (USA 0x0201ce80, EUR 0x0201ce90, JPN 0x0201cc0c)
ARM int ZoneFeaturesScript_AddRotatedExit(Script::Parameter *params, int numParams) {
    Script::Parameter *paramsStart = params;
    ZoneFeatures::Opcode68Entry entry;
    entry.Reset_0201ce10();
    fix32_t centreX     = (int) (4096.0f * (params++)->ToFloat());
    fix32_t centreY     = (int) (4096.0f * (params++)->ToFloat());
    fix32_t centreZ     = (int) (4096.0f * (params++)->ToFloat());
    fix32_t halfLengthX = (int) (4096.0f * (params++)->ToFloat()) / 2;
    fix32_t halfLengthY = (int) (4096.0f * (params++)->ToFloat()) / 2;
    fix32_t halfLengthZ = (int) (4096.0f * (params++)->ToFloat()) / 2;

    entry.unk_4[0] = centreX + halfLengthX;
    entry.unk_4[1] = centreY + halfLengthY;
    entry.unk_4[2] = centreZ + halfLengthZ;
    entry.unk_4[3] = centreX - halfLengthX;
    entry.unk_4[4] = centreY - halfLengthY;
    entry.unk_4[5] = centreZ - halfLengthZ;

    entry.unk_58[0] = centreX;
    entry.unk_58[1] = centreY;
    entry.unk_58[2] = centreZ;

    entry.unk_52 = 4096.0f * (params++)->ToFloat();

    fix32_t halfLengthXSquared = FIX32_MULTIPLY(halfLengthX, halfLengthX);
    fix32_t halfLengthZSquared = FIX32_MULTIPLY(halfLengthZ, halfLengthZ);
    entry.unk_54               = halfLengthZSquared;
    entry.unk_54               = halfLengthXSquared + halfLengthZSquared;

    if (!ZoneFeaturesScript_ParseExitDestination(params, numParams - (params - paramsStart), entry)) return 0;
    data_020fdc20.warp->CreateExit(entry);
    return 1;
}
