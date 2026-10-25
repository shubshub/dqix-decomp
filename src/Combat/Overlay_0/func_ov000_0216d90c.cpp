#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

extern "C" void func_ov000_0216d370(void* obj, int a, int b, int c);
void Camera_SetTarget(struct Camera* obj, int x, int y, int z);
void ApplyVec3Tail_0202e694(void* obj, int* vec);
void SetFlagOrState0216d530(void* obj, int val);

extern int data_ov000_021832a4[8];

// USA: func_ov000_0216d90c
extern "C" ARM void func_ov000_0216d90c(unsigned char* arg0, int arg1) {
    GameState* var0 = GameState::GetInstance();
    GameObject* var1 = var0->GetGameObjectByIndex(arg1);
    if (var1 == NULL) {
        return;
    }
    GameObject* var2 = var0->GetGameObjectByIndex(arg0[0x263]);
    if (var2 == NULL) {
        return;
    }
    fix32_t var3 = var1->obj3D_.GetHeight();
    fix32_t var4 = var2->obj3D_.GetHeight();
    int var5;
    if (var4 < var3 && 2.0f <= var3) {
        var5 = 1;
    } else {
        var5 = 0;
    }
    func_ov000_0216d370(obj, 1, 1, 1);
    Camera_SetTarget((struct Camera*)obj, 0, 0x1000, 0x1000);
    int r = NextRandomMax(*(struct Random**)(obj + 0x21c), 8);
    if (tall) {
        if (r == 2) {
            r = 7;
        } else if (r == 3) {
            r = 6;
        } else if (r == 4) {
            r = 1;
        } else if (r == 5) {
            r = 0;
        }
    }
    int var7[3];
    var7[0] = data_ov000_021832a4[var6];
    var7[1] = 0x3000;
    var7[2] = 0x8000;
    func_0202e694(arg0, var7);
    func_ov000_0216d530(arg0, arg1);
    *(int*)(arg0 + 0x23c) = -20;
}
