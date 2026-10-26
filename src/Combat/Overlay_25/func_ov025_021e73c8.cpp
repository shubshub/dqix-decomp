#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov000_0215440c_2;
struct Struct_ov000_02160094;
struct Struct_ov001_0215cdf8;

extern "C" int func_ov000_021820bc(void* obj, int unused, int index, int arg);
extern "C" struct Struct_ov000_02160094* func_ov000_02160094(struct Struct_ov000_0215440c_2* list, int index);
extern "C" int func_ov017_021917f0(int a, int b);

struct Struct_ov025_021e73c8 {
    char pad[8];
    unsigned char field8;
};

// USA: func_ov025_021e73c8
extern "C" ARM int func_ov025_021e73c8(struct Struct_ov025_021e73c8* obj, int v1, int arg2, void* a3) {
    int local[12];
    GameState* bs;
    GameObject* c;

    if (func_ov000_021820bc(a3, v1, obj->field8, (int)&local[0]) == 0) {
        return 1;
    }
    bs = GameState::GetInstance();
    c = bs->GetGameObjectByIndex(local[0]);
    if (c == NULL) {
        return 1;
    }
    ((Object3D*)((struct Struct_ov001_0215cdf8*)c))->Detach();
    if (obj->field8 >= 0x22 && obj->field8 <= 0x25) {
        struct Struct_ov000_02160094* node = func_ov000_02160094((struct Struct_ov000_0215440c_2*)v1, obj->field8 - 0x22);
        if (node != NULL) {
            func_ov017_021917f0(*(unsigned short*)((char*)node + 0x20), 1);
        }
    }
    return 1;
}
