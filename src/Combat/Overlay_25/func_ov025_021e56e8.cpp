#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov025_021e56e8 {
    char unknown_0_[8];
    unsigned char unknown_8_;
    unsigned char unknown_9_;
    char unknown_a_[2];
    int unknown_c_;
};

int DispatchByIndex021820bc(void* obj, int unused, int index, int arg);
void SetThreeWords_021e4448(int* obj, int a, int b, int c);
void* GetActiveCombatWork_ov000_02160130(void);
extern "C" void* func_ov000_02160f14(void* work);
int Camera_GetOrbitDistance(void* obj);

extern Vector3fix data_ov025_021eef24;

// USA: func_ov025_021e56e8
extern "C" ARM int func_ov025_021e56e8(struct Param021e56e8* p, int b, int unused, void* c) {
    GameState* gs = GameState::GetInstance();
    int ids[8];
    int count = DispatchByIndex021820bc(c, b, p->index, (int)ids);
    Vector3fix scale = data_ov025_021eef24;
    if (p->mode == 0) {
        SetThreeWords_021e4448((int*)&scale, 0x10a, 0x10a, 0x10a);
    } else if (p->mode == 2) {
        void* field = func_ov000_02160f14(GetActiveCombatWork_ov000_02160130());
        float y0 = 0.065f;
        float y1 = 0.08f;
        float x0 = 6.5f;
        float x1 = 7.0f;
        float zoom = Camera_GetOrbitDistance(field) / 4096.0f;
        float s = zoom * ((y1 - y0) / (x1 - x0)) + (x1 * y0 - x0 * y1) / (x1 - x0);
        if (s < 0.065f) {
            s = 0.065f;
        }
        int var11 = 4096.0f * var10;
        func_ov025_021e4448((int*)&var3, var11, var11, var11);
    } else if (arg0->unknown_9_ == 3) {
        func_ov025_021e4448((int*)&var3, arg0->unknown_c_, arg0->unknown_c_, arg0->unknown_c_);
    }
    for (int var12 = 0; var12 < var2; var12++) {
        GameObject* var13 = var0->GetGameObjectByIndex(var1[0]);
        if (var13 != NULL) {
            var13->obj3D_.SetScale(&var3);
        }
    }
    return 1;
}
