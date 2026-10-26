#include "World/ZoneWarpScript.h"
#include <globaldefs.h>

// USA: func_0201d044
extern "C" ARM int func_0201d044(Script::Parameter* params, int numParams)
{
    ZoneFeatures::Opcode6aEntry entry;
    entry.func_0201d424();
    int var1 = (params++)->ToInt();
    entry.maybeType = var1;
    bool var2 = false;
    if (entry.maybeType >= 10)
    {
        entry.maybeType -= 10;
        var2 = true;
    }

    Vector3fix var3;
    params = params->ToVec3fix(&var3);
    entry.unk_8.vec = var3;
    params = params->ToVec3fix(&var3);
    entry.unk_14.vec = var3;

    if (var2)
    {
        fix32_t angle = 4096.0f * (params++)->ToFloat();
        entry.unk_22 = fix32ReduceAngle0To2Pi(angle);
    }
    entry.angle = 4096.0f * (params++)->ToFloat();

    fix32_t var5 = entry.unk_14.vec.x / 2;
    fix32_t var6 = entry.unk_14.vec.z / 2;
    fix32_t var7 = FIX32_MULTIPLY(var5, var5);
    fix32_t var8 = FIX32_MULTIPLY(var6, var6);
    entry.unk_24 = var8;
    entry.unk_24 = var7 + var8;

    if (entry.maybeType == 2)
    {
        entry.unk_2c.type2.nodeId = (params++)->ToInt();
        entry.unk_2c.type2.elementId = (params++)->ToInt();
        entry.unk_2c.type2.flags = (params++)->ToInt();
    }
    else if (entry.maybeType == 3)
    {
        entry.unk_2c.type3.unk_0 = (params++)->ToInt();
    }
    else if (entry.maybeType == 4)
    {
        int arg = (params++)->ToInt();
        entry.unk_2c.type4.unk_1 = -1;
        entry.unk_2c.type4.unk_0 = arg;
        entry.unk_2c.type4.unk_0_high = 0;
        switch (entry.unk_2c.type4.unk_0)
        {
        case 0:
            entry.unk_2c.type4.vector_4.vec3.vec.y = 4096.0f * (params++)->ToFloat();
            entry.unk_2c.type4.vector_4.vec3.vec.z = 4096.0f * (params++)->ToFloat();
            break;
        case 1:
            params = params->ToVec3fix(&var3);
            entry.unk_2c.type4.vector_4.vec3.vec = var3;
            break;
        case 2:
        case 3:
            params = params->ToVec3fix(&var3);
            entry.unk_2c.type4.vector_4.vec3.vec = var3;
            break;
        case 4:
        case 5:
        {
            Vector3fix vecB;
            Vector3fix vecA;
            params = params->ToVec3fix(&vecB);
            params = params->ToVec3fix(&vecA);
            MaybeVector4fix difference;
            Vector3fix_Subtract(&vecA, &vecB, &difference.vec3.vec);
            fix32_t distance = Vector3fix_Length(&difference.vec3.vec);
            Vector3fix_Normalize(&difference.vec3.vec, &difference.vec3.vec);
            difference.w = Vector3fix_InnerProduct(&difference.vec3.vec, &vecB);
            Vector3fix var14  = { 0, 0, 0 };
            if (entry.unk_2c.type4.unk_0 == 4)
            {
                var14.x = 4096.0f * (params++)->ToFloat();
            }
            var14.y = 4096.0f * (params++)->ToFloat();
            var14.z = 4096.0f * (params++)->ToFloat();
            Vector3fix var15;
            params = params->ToVec3fix(&var15);
            entry.unk_2c.type4.vector_4.CopyFrom(difference);
            entry.unk_2c.type4.distance_14 = distance;
            entry.unk_2c.type4.vector_18 = var14;
            entry.unk_2c.type4.vector_24 = var15;
            break;
        }
        }
        entry.unk_2c.type4.vector_30.x = 0;
        entry.unk_2c.type4.vector_30.y = 0;
        entry.unk_2c.type4.vector_30.z = 0;
        if (numParams > 12)
        {
            params = params->ToVec3fix(&var3);
            entry.unk_2c.type4.vector_30 = var3;
        }
    }
    else if (entry.maybeType == 5)
    {
        entry.unk_2c.type5.unk_0 = (params++)->ToInt();
        entry.unk_2c.type5.unk_2 = (params++)->ToInt();
        entry.unk_2c.type5.cupboardContainerId = 0;
    }

    ZoneFeatures* instance = data_020fdc20.warp;
    entry.pNext = NULL;
    instance->CreateOpcode6aEntry(entry);
    return 1;
}
