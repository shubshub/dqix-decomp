#include <globaldefs.h>
#include "World/Bounds3D.h"
#include "Graphics/Vector.h"

struct Vec3 { int x; int y; int z; };

extern "C" ARM void func_0201ce78(int* obj, int a, int b, int c);

// A ZoneFeatures::Opcode7bEntry (World/ZoneFeatures.h): a box turned about y, with the x/z bounds of the turned box
struct BoxEntry0201e8fc {
    Vector3fix center;
    Vector3fix size;
    short angle;
    int minX, minZ, maxX, maxZ;
};

// A ZoneFeatures (World/ZoneFeatures.h), with its field names
struct Container0201e8fc {
    unsigned char pad[0x80];
    unsigned short arraySize7b_;
    unsigned short arrayCapacity7b_;
    struct BoxEntry0201e8fc* entries7b_;
};

// Main, originally FindBoxContainingPoint0201e8fc (USA 0x0201e8fc, EUR 0x0201e90c, JPN 0x0201e688)
extern "C" ARM void* ZoneFeatures_FindHeadingLockArea(struct Container0201e8fc* features, struct Vec3* point) {
    int i;
    for (i = 0; i < features->arraySize7b_; i++) {
        struct BoxEntry0201e8fc* box = &features->entries7b_[i];
        Vector3fix boxPoint;
        Matrix4x3 rotation;
        Bounds3D bounds;
        int angle;

        if (point->x < box->minX || point->z < box->minZ) continue;
        if (point->x > box->maxX || point->z > box->maxZ) continue;

        Vector3fix_Subtract((const Vector3fix*)point, &box->center, &boxPoint);
        angle = fix32ReduceAngle0To2Pi(-(short)box->angle);
        rotation = RotationMatrixY(angle);
        Mat4x3_ApplyToVector(&boxPoint, &rotation, &boxPoint);
        Vector3fix_Add(&boxPoint, &box->center, &boxPoint);

        func_0201ce78(&bounds.minimum.x, box->center.x - box->size.x / 2, box->center.y - box->size.y / 2, box->center.z - box->size.z / 2);
        func_0201ce78(&bounds.maximum.x, box->center.x + box->size.x / 2, box->center.y + box->size.y / 2, box->center.z + box->size.z / 2);

        if (Bounds3D_ContainsPoint(&boxPoint, &bounds) != 0)
            return box;
    }
    return 0;
}
