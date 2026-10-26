#include <globaldefs.h>
#if defined(jpn)
enum { objectOffset = 0xb94, Enum_ov000_0216118c_668 = 0x218, Enum_ov000_0216118c_3208 = 0xc04 };
#else
enum { objectOffset = 0xc18, Enum_ov000_0216118c_668 = 0x29c, Enum_ov000_0216118c_3208 = 0xc88 };
#endif
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" void func_ov000_021626a0(void* self, int a, int b);
extern "C" void func_ov000_0216d600(void* obj, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
extern "C" void Camera_SetOrbitVector(void* obj, int* vec);
extern "C" void func_ov000_0216f1e4(void* obj, int* arg1, int a, int b);

struct Struct_ov000_0216118c { int v[3]; };

// USA: func_ov000_0216118c
extern "C" ARM void func_ov000_0216118c(void* self, int flag) {
    GameState::GetInstance();
    ((int)GetGameResources());
    func_ov000_021626a0(self, 0x26, 0);
    func_ov000_0216d600((char*)self + objectOffset, 1, 1, 0, 0, 0, 0, 1);
    if (flag == 0) {
        return;
    }
    int* var0 = *(int**)((char*)self + Enum_ov000_0216118c_668);
    if (*(int*)((char*)var0 + 0x8000 + 0xe20) != 0) {
        return;
    }
    struct Struct_ov000_0216118c var1 = *(struct Struct_ov000_0216118c*)((char*)self + Enum_ov000_0216118c_3208);
    struct Struct_ov000_0216118c temp2 = var1;
    temp2.v[1] += 0x800;
    temp2.v[2] += 0x3000;
    Camera_SetOrbitVector((char*)self + objectOffset, temp2.v);
    func_ov000_0216f1e4((char*)self + objectOffset, var1.v, 0xf33, 0);
}
