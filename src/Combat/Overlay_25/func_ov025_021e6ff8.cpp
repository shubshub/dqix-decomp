#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"
#include "Graphics/Vector.h"

struct Struct_ov000_0215440c;
struct Struct_ov000_021600f8 {
    char pad0[0xe];
    short unknown_e_;
};

struct Struct_ov025_021e6ff8 {
    char pad0[8];
    unsigned char flags;
    char unknown_9_[3];
    fix32_t angle;
    fix32_t height;
    fix32_t distance;
    int arg18;
    int unknown_1c_;
    int arg20;
    unsigned char mode;
};

extern "C" void* func_ov000_02160130(void);
extern "C" unsigned char func_ov025_021dcc64(void* obj);
extern "C" Struct_ov000_021600f8* func_ov000_021600f8(Struct_ov000_0215440c* list, int index);
extern "C" void func_0202edf8(char* obj, int a, int b, int c, int d);

// USA: func_ov025_021e6ff8
extern "C" ARM int func_ov025_021e6ff8(Struct_ov025_021e6ff8* task, Struct_ov000_0215440c* list) {
#if defined(jpn)
 enum { regionalOffset=0x71c5 };
#else
 enum { regionalOffset=0x6fd5 };
#endif
    GameState* gs = GameState::GetInstance();
    void* camera = gs->GetCamera();
    void* work = func_ov000_02160130();
    if (work != NULL) {
        *((unsigned char*)work + regionalOffset) = 1;
        if (func_ov025_021dcc64(work)) {
            return 1;
        }
    }
    Vector3fix v = *(Vector3fix*)((char*)camera + 0x70);
    if (task->flags & 1) {
        if (fix32SignedAngleDistance(v.x, task->angle) > 0) {
            fix32_t a = task->angle;
            while (a < v.x) {
                a += FIX_2PI;
            }
            v.x = a;
        } else {
            fix32_t a = task->angle;
            while (v.x < a) {
                a -= FIX_2PI;
            }
            v.x = a;
        }
    }
    if (task->flags & 2) {
        v.y = task->height;
    }
    if (task->flags & 4) {
        v.z = task->distance;
    }
    if (task->mode == 2) {
        int height = 1;
        Struct_ov000_021600f8* node = func_ov000_021600f8(list, 0);
        if (node != NULL) {
            GameObject* c = gs->GetCombatantByIndex(node->unknown_e_);
            if (c != NULL) {
                height = c->obj3D_.GetHeight();
            }
        }
        float scale = 1.0f;
        if (height >= 0x1800) {
            scale = 1.0f + 0.8f * ((float)height / 4096.0f - 1.5f) / 2.5f;
            if (scale >= 1.8f) {
                scale = 1.8f;
            }
        }
        float y = (float)v.y / 4096.0f;
        float z = (float)v.z / 4096.0f;
        y = y * scale;
        z = z * scale;
        v.y = (int)(4096.0f * y);
        v.z = (int)(4096.0f * z);
    }
    func_0202edf8((char*)camera, (int)&v, task->arg18, task->unknown_1c_, task->arg20);
    return 1;
}
