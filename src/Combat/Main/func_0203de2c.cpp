#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_0203f430(void* p);
struct Struct_0203de2c;

struct Struct_0203de2c_2 {
    char pad0[0x14];
    void* unknown_14_;
    void* field_18;
};
struct Struct_0203de2c_3 {
    char pad0[0xc];
    struct Struct_0203de2c_2* nodes[0x20];
};

// USA: func_0203de2c
extern "C" ARM void func_0203de2c(struct Struct_0203de2c_3* roster) {
    int i;
    GameState::GetInstance();
    for (i = 0; i < 0x20; i++) {
        struct Struct_0203de2c_2* n = roster->nodes[i];
        if (n == NULL) continue;
        if (n->unknown_14_ != NULL) {
            func_0203f430(n->unknown_14_);
        } else if (n->field_18 != NULL) {
            ((Object3D*)((struct Struct_0203de2c*)n->field_18))->StageTextureData();
        }
    }
}
