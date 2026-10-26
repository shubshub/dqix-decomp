#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct Vec3 { int x; int y; int z; };

struct Struct_01ff8b48_2;
struct Vector3i;
void Vector3fixDivideScalar(Vector3i const*, int, Vector3i*);

struct Struct_ov001_021592bc { int x; int y; int z; };
void Vector3fixMultiplyScalar(Vector3i const*, int, Vector3i*);

extern "C" int func_ov001_02164578(void* table, int index, void* arg2, int arg3, float arg4);
extern "C" int Zone3D_GetInstance(void);
extern "C" int Zone3D_GetGroundHeight(int seed, void* v);
extern void* data_ov001_02165884;

// USA: func_ov001_021592bc
extern "C" ARM int func_ov001_021592bc(char* req, char* state) {
    int flag = 0;
    GameState* battleStruct = GameState::GetInstance();
    int var2 = (int)(battleStruct->GetTickCount() << 12);

    if (*(int*)(state + 0x48) >= *(int*)(req + 0x10) * 2) {
        int mode = *(int*)(req + 0x14);
        if (mode == 0) {
            memcpy(state + 0x74, req + 0x4, 0xc);
        } else if (mode == 1) {
            *(int*)(state + 0x74) = *(int*)(req + 0x4);
            *(int*)(state + 0x7c) = *(int*)(req + 0xc);
        }
        void* var4 = req + 0x1c;
        if (var4) {
            func_ov001_02164578(data_ov001_02165884, *(int*)(state + 0x70), var4, flag, 0.0f);
        }
        *(int*)(state + 0x48) = 0;
        return 0;
    }

    if (*(int*)(state + 0x48) <= 0) {
        Vec3 delta;
        Vector3fix_Subtract((const Vector3fix*)((Vec3*)(req + 0x4)), (const Vector3fix*)((Vec3*)(state + 0x74)), (Vector3fix*)&delta);
        Vector3fixDivideScalar((Vector3i const*)&delta, (*(unsigned int*)(req + 0x10)) << 13, (Vector3i*)(state + 0x94));
    } else {
        Struct_ov001_021592bc tmp = *(Struct_ov001_021592bc*)(state + 0x94);
        Vector3fixMultiplyScalar((Vector3i const*)&tmp, var2, (Vector3i*)&tmp);
        int mode = *(int*)(req + 0x14);
        if (mode == 0) {
            Vector3fix_Add((const Vector3fix*)((Vec3*)(state + 0x74)), (const Vector3fix*)((Vec3*)&tmp), (Vector3fix*)((Vec3*)(state + 0x74)));
        } else if (mode == 1) {
            Vector3fix_Add((const Vector3fix*)((Vec3*)(state + 0x74)), (const Vector3fix*)((Vec3*)&tmp), (Vector3fix*)((Vec3*)(state + 0x74)));
            int seed = Zone3D_GetInstance();
            *(int*)(state + 0x78) = Zone3D_GetGroundHeight(seed, state + 0x74);
        }
    }

    *(int*)(state + 0x48) += (int)battleStruct->GetTickCount();
    return 1;
}
