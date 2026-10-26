#include "World/ZoneWarpScript.h"
#include <globaldefs.h>

// Main, originally WarpScript_Opcode_67_0201c96c (USA 0x0201c96c, EUR 0x0201c97c, JPN 0x0201c6f8)
extern "C" ARM int ZoneFeaturesScript_AddOpcode66Entry(Script::Parameter *params, int numParams) {
    float centreX = params[0].ToFloat();
    float centreY = params[1].ToFloat();
    float centreZ = params[2].ToFloat();
    float var3 = params[3].ToFloat();
    float var4 = params[4].ToFloat();
    float var5 = params[5].ToFloat();
    float var6;
    int value0 = params[6].ToInt();
    int var8 = params[7].ToInt();
    var6 = 0;
    if (numParams >= 9) var6 = params[8].ToFloat();

    ZoneFeatures::Opcode66Entry entry;
    entry.unk_0[0] = 4096.0f * (centreX + (var3 / 2.0f));
    entry.unk_0[1] = 4096.0f * (centreY + (var4 / 2.0f));
    entry.unk_0[2] = 4096.0f * (centreZ + (var5 / 2.0f));

    entry.unk_0[3] = 4096.0f * (centreX - (var3 / 2.0f));
    entry.unk_0[4] = 4096.0f * (centreY - (var4 / 2.0f));
    entry.unk_0[5] = 4096.0f * (centreZ - (var5 / 2.0f));

    entry.unknown_18_[0] = value0;
    entry.unknown_18_[1] = var8;
    entry.unk_20    = 4096.0f * var6;

    data_020fdc20.warp->CreateOpcode66Entry(entry);
    return 1;
}
