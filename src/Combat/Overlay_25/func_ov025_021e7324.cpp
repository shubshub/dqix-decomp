#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_ov000_021820bc(void* obj, int unused, int index, int arg);
struct Struct_ov001_0215cdf8;
struct Struct_ov001_0215cd50;
struct Object3D;

struct Struct_ov025_021e7324 {
    char pad[8];
    unsigned char idx1;
    unsigned char idx2;
    char pad2[2];
    char* label;
};

struct Struct_ov025_021e7324_2 {
    int id;
    char pad[0x2c];
};

// USA: func_ov025_021e7324
extern "C" ARM int func_ov025_021e7324(struct Struct_ov025_021e7324* a, int b, int unused, void* obj) {
    struct Struct_ov025_021e7324_2 out1;
    struct Struct_ov025_021e7324_2 out2;
    int var2 = func_ov000_021820bc(obj, b, a->idx1, (int)&out1.id);
    int found2 = func_ov000_021820bc(obj, b, a->idx2, (int)&out2.id);
    if (!var2 || !found2) {
        return 1;
    }
    GameState* bs = GameState::GetInstance();
    GameObject* c1 = bs->GetGameObjectByIndex(out1.id);
    GameObject* c2 = bs->GetGameObjectByIndex(out2.id);
    if (!c1 || !c2) {
        return 1;
    }
    ((Object3D*)((struct Struct_ov001_0215cdf8*)c1))->Detach();
    ((Object3D*)((struct Struct_ov001_0215cd50*)c1))->Attach(&c2->obj3D_, a->label);
    return 1;
}
