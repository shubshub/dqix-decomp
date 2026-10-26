#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

struct Vec3 { int x; int y; int z; };
struct Struct_ov001_021592bc { int x; int y; int z; };
struct Struct_ov001_02157e18 { int v[3]; };

struct Vector3i;
ARM void Vector3fixMultiplyScalar(Vector3i const*, int, Vector3i*);

// USA: func_ov001_02157e18
extern "C" ARM int func_ov001_02157e18(void* a, void* b) {
    char* pA = (char*)a;
    char* pB = (char*)b;
    GameState* battleStruct = GameState::GetInstance();
    int scale = battleStruct->GetTickCount() << 0xc;
    int var4 = *(int*)(pA + 0x1c);
    if (var4 == 0) {
        memcpy(pB + 0x58, pA + 0x10, 0xc);
        *(int*)(pB + 0x38) = 0;
        return 0;
    }
    if (*(int*)(pB + 0x38) <= 0) {
        struct Vec3 diff;
        int var6 = var4 << 0xd;
        Vector3fix_Subtract((const Vector3fix*)((struct Vec3*)(pA + 0x10)), (const Vector3fix*)((struct Vec3*)(pB + 0x58)), (Vector3fix*)&diff);
        *(int*)(pB + 0xc0) = fix32_Divide((fix32_t)diff.x, (fix32_t)var6);
        *(int*)(pB + 0xc4) = fix32_Divide((fix32_t)diff.y, (fix32_t)var6);
        *(int*)(pB + 0xc8) = fix32_Divide((fix32_t)diff.z, (fix32_t)var6);
    }
    struct Struct_ov001_02157e18 var7 = *(struct Struct_ov001_02157e18*)(pB + 0xc0);
    Vector3fixMultiplyScalar((Vector3i const*)&var7, scale, (Vector3i*)&var7);
    Vector3fix_Add((const Vector3fix*)((struct Vec3*)(pB + 0x58)), (const Vector3fix*)((struct Vec3*)&var7), (Vector3fix*)((struct Vec3*)(pB + 0x58)));
    int counter = *(int*)(pB + 0x38) + battleStruct->GetTickCount();
    *(int*)(pB + 0x38) = counter;
    int limit = *(int*)(pA + 0x1c) << 1;
    if (counter >= limit) {
        *(int*)(pB + 0x38) = 0;
        return 0;
    }
    return 1;
}
