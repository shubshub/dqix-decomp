#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov025_021e56e8 {
    char pad0[8];
    unsigned char index;
    unsigned char mode;
    char padA[2];
    int scale;
};

extern "C" int func_ov000_021820bc(void* obj, int unused, int index, int arg);
extern "C" void func_ov025_021e4448(int* obj, int a, int b, int c);
extern "C" void* func_ov000_02160130(void);
extern "C" void* func_ov000_02160f14(void* work);
extern "C" int Camera_GetOrbitDistance(void* obj);

extern Vector3fix data_ov025_021eef24;

// USA: func_ov025_021e56e8
extern "C" ARM int func_ov025_021e56e8(struct Struct_ov025_021e56e8* p, int b, int unused, void* c) {
    GameState* gs = GameState::GetInstance();
    int ids[8];
    int count = func_ov000_021820bc(c, b, p->index, (int)ids);
    Vector3fix scale = data_ov025_021eef24;
    if (p->mode == 0) {
        func_ov025_021e4448((int*)&scale, 0x10a, 0x10a, 0x10a);
    } else if (p->mode == 2) {
        void* field = func_ov000_02160f14(func_ov000_02160130());
        float var5 = 0.065f;
        float var6 = 0.08f;
        float var7 = 6.5f;
        float x1 = 7.0f;
        float zoom = Camera_GetOrbitDistance(field) / 4096.0f;
        float s = zoom * ((var6 - var5) / (x1 - var7)) + (x1 * var5 - var7 * var6) / (x1 - var7);
        if (s < 0.065f) {
            s = 0.065f;
        }
        int v = 4096.0f * s;
        func_ov025_021e4448((int*)&scale, v, v, v);
    } else if (p->mode == 3) {
        func_ov025_021e4448((int*)&scale, p->scale, p->scale, p->scale);
    }
    for (int i = 0; i < count; i++) {
        GameObject* obj = gs->GetGameObjectByIndex(ids[0]);
        if (obj != NULL) {
            obj->obj3D_.SetScale(&scale);
        }
    }
    return 1;
}
