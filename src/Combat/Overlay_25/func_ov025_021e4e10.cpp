#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"

extern "C" int func_ov000_02160f14(void* work);
extern "C" void func_ov000_0216d370(int a, int b, int c, int d);
extern "C" void* func_ov000_02160130(void);
extern "C" void GameState_SetCamera(GameState* battleStruct, int value);
struct Vector3i;
extern "C" void Camera_SetOrbitVector(void* obj, int* vec);

struct Struct_ov025_021e4e10 {
    unsigned int v[3];
};

struct WorkStruct021e4e10 {
    char pad1[0x10];
    struct Struct_ov025_021e4e10 vecA;
    char pad2[0x70 - 0x1c];
    struct Struct_ov025_021e4e10 vecB;
};

// USA: func_ov025_021e4e10
extern "C" ARM int func_ov025_021e4e10(void) {
    GameState* bs = GameState::GetInstance();
    void* work = func_ov000_02160130();
    struct WorkStruct021e4e10* p = (struct WorkStruct021e4e10*)bs->GetCamera();
    struct Struct_ov025_021e4e10 vecA = p->vecA;
    struct Struct_ov025_021e4e10 vecB = p->vecB;
    int val = func_ov000_02160f14(work);
    GameState_SetCamera(bs, val);
    func_ov000_0216d370(val, 1, 1, 1);
    struct WorkStruct021e4e10* p2 = (struct WorkStruct021e4e10*)bs->GetCamera();
    *(Vector3i*)((int*)&p2->vecA) = *(Vector3i const*)((int*)&vecA);
    Camera_SetOrbitVector(p2, (int*)&vecB);
    return 1;
}
