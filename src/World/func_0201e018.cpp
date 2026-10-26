#include <globaldefs.h>
#include "World/ZoneWarpScript.h"
#include "Graphics/Vector.h"

#if defined(usa) || defined(jpn)

// USA: func_0201e018
extern "C" ARM int func_0201e018(Script::Parameter* params, int numParams)
{
    ZoneFeatures::Opcode7bEntry entry;
    params = params->ToVec3fix(&entry.unknown_0_.vec);
    params = params->ToVec3fix(&entry.vector_c.vec);
    entry.unknown_18_ = 4096.0f * (params++)->ToFloat();

    fix32_t var1 = -entry.vector_c.vec.x / 2;
    fix32_t var2 = -entry.vector_c.vec.z / 2;
    fix32_t var3 = entry.vector_c.vec.x / 2;
    fix32_t var4 = entry.vector_c.vec.z / 2;

    Vector3fix vertices[4] = { 0 };

    vertices[0].x = var1;
    vertices[0].z = var2;
    vertices[1].x = var1;
    vertices[1].z = var4;
    vertices[2].x = var3;
    vertices[2].z = var2;
    vertices[3].x = var3;
    vertices[3].z = var4;

    Matrix4x3 matrix;
    matrix = RotationMatrixY(entry.unknown_18_);

    for (int i = 0; i < 4; i++)
        Mat4x3_ApplyToVector(&vertices[i], &matrix, &vertices[i]);

    entry.minX = vertices[0].x;
    entry.minZ = vertices[0].z;
    entry.maxX = vertices[0].x;
    entry.maxZ = vertices[0].z;

    for (int i = 1; i < 4; i++)
    {
        if (entry.minX > vertices[i].x)
            entry.minX = vertices[i].x;
        if (entry.minZ > vertices[i].z)
            entry.minZ = vertices[i].z;
        if (entry.maxX < vertices[i].x)
            entry.maxX = vertices[i].x;
        if (entry.maxZ < vertices[i].z)
            entry.maxZ = vertices[i].z;
    }

    entry.minX += entry.unknown_0_.vec.x;
    entry.minZ += entry.unknown_0_.vec.z;
    entry.maxX += entry.unknown_0_.vec.x;
    entry.maxZ += entry.unknown_0_.vec.z;
    data_020fdc20.warp->func_0201e88c(entry);
    return 1;
}
#endif
