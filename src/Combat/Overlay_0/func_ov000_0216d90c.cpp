#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

extern "C" void func_ov000_0216d370(void* obj, int a, int b, int c);
extern "C" void Camera_SetTarget(struct Camera* obj, int x, int y, int z);
extern "C" void Camera_SetOrbitVector(void* obj, int* vec);
extern "C" void func_ov000_0216d530(void* obj, int val);

extern int data_ov000_021832a4[8];

// USA: func_ov000_0216d90c
extern "C" ARM void func_ov000_0216d90c(unsigned char* obj, int index) {
    GameState* state = GameState::GetInstance();
    GameObject* self = state->GetGameObjectByIndex(index);
    if (self == NULL) {
        return;
    }
    GameObject* other = state->GetGameObjectByIndex(obj[0x263]);
    if (other == NULL) {
        return;
    }
    fix32_t var3 = self->obj3D_.GetHeight();
    fix32_t var4 = other->obj3D_.GetHeight();
    int var5;
    if (var4 < var3 && 2.0f <= var3) {
        var5 = 1;
    } else {
        var5 = 0;
    }
    func_ov000_0216d370(obj, 1, 1, 1);
    Camera_SetTarget((struct Camera*)obj, 0, 0x1000, 0x1000);
    int r = NextRandomMax(*(struct Random**)(obj + 0x21c), 8);
    if (var5) {
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
    int vec[3];
    vec[0] = data_ov000_021832a4[r];
    vec[1] = 0x3000;
    vec[2] = 0x8000;
    Camera_SetOrbitVector(obj, vec);
    func_ov000_0216d530(obj, index);
    *(int*)(obj + 0x23c) = -20;
}
