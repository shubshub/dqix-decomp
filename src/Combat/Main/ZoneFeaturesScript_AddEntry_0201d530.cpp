#include <globaldefs.h>
#include "Resource/Script.h"
#include "World/ZoneWarpScript.h"

static inline int FixedMultiplyRounded(int a, int b) {
    return (int)(((long long)a * b + 0x800) >> 12);
}

// Main, originally WarpScript_Opcode_73_0201d530 (USA 0x0201d530, EUR 0x0201d540, JPN 0x0201d2bc)
extern "C" ARM int ZoneFeaturesScript_AddEntry(Script::Parameter* params, int) {
    ZoneFeatures::Opcode6aEntry entry;
    Vector3fix vector;

    entry.func_0201d424();
    entry.maybeType = params->ToInt();

    Script::Parameter* param = params[1].ToVec3fix(&vector);
    entry.unk_8.vec = vector;

    param = param->ToVec3fix(&vector);
    entry.unk_14.vec = vector;

    entry.unk_22 = (short)fix32ReduceAngle0To2Pi((int)(4096.0f * param->ToFloat()));
    entry.angle = (short)(int)(4096.0f * param[1].ToFloat());

    int halfX = entry.unk_14.vec.x / 2;
    int halfZ = entry.unk_14.vec.z / 2;
    int halfZSquared = FixedMultiplyRounded(halfZ, halfZ);
    int halfXSquared = FixedMultiplyRounded(halfX, halfX);
    entry.unk_24 = halfXSquared + halfZSquared;

    data_020fdc20.currentEntry = data_020fdc20.warp->CreateOpcode6aEntry(entry);
    return 1;
}
