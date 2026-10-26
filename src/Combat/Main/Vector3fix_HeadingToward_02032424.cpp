#include <globaldefs.h>

struct Vector3fix
{
    int x;
    int y;
    int z;
};

extern "C" void Vector3fix_Subtract(const Vector3fix* a, const Vector3fix* b, Vector3fix* out);
extern "C" void Vector3fix_Normalize(const Vector3fix* in, Vector3fix* out);
extern "C" int fix32_Atan2(int y, int x);
int fix32ReduceAngle0To2Pi(int);

// Main, originally func_02032424 (USA 0x02032424, EUR 0x02032434, JPN 0x02031f5c)
extern "C" ARM int Vector3fix_HeadingToward(const Vector3fix* target, const Vector3fix* origin) {
    Vector3fix awayFromTarget;
    Vector3fix_Subtract(origin, target, &awayFromTarget);
    Vector3fix_Normalize(&awayFromTarget, &awayFromTarget);
    return fix32ReduceAngle0To2Pi(fix32_Atan2(-awayFromTarget.x, -awayFromTarget.z));
}
