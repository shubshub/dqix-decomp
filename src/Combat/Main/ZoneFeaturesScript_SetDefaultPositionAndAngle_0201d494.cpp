#include "World/ZoneWarpScript.h"
#include <globaldefs.h>

// Main, originally WarpScript_Opcode_6e_0201d494 (USA 0x0201d494, EUR 0x0201d4a4, JPN 0x0201d220)
ARM int ZoneFeaturesScript_SetDefaultPositionAndAngle(Script::Parameter* params, int numParams) {
    Vector3fix position;
    params = params->ToVec3fix(&position);
    fix32_t angle = fix32ReduceAngle0To2Pi((int)(4096.0f * params->ToFloat()));
    ZoneFeatures* features = data_020fdc20.warp;
    features->vector_70_ = position;
    features->angle_7c_ = angle;
    return 1;
}
