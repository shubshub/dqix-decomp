#include <globaldefs.h>
#include "GameState/GameState.h"
#include "GameState/Field3b0.h"

struct Struct_ov025_021e5c68 {
    char unknown_0_[0x70];
    Vector3fix unknown_70_;
};

struct Struct_ov025_021e5c68_2 {
    char unknown_0_[8];
    Vector3fix unknown_8_;
    unsigned char unknown_14_;
};

struct Struct_ov025_021e5c68_3 {
    char unknown_0_[0xe];
    short unknown_e_;
};

extern "C" void func_0202e694(void* arg0, int* arg1);
struct Struct_ov000_0215440c;
extern "C" Struct_ov025_021e5c68_3* func_ov000_021600f8(Struct_ov000_0215440c*, int);
extern "C" char* func_ov000_02160130();

// USA: func_ov025_021e5c68
extern "C" ARM int func_ov025_021e5c68(Struct_ov025_021e5c68_2* arg0, void* arg1) {
#if defined(jpn)
 enum {Enum_ov025_021e5c68_28629=0x71c5};
#else
 enum {Enum_ov025_021e5c68_28629=0x6fd5};
#endif
    GameState* gs = GameState::GetInstance();
    Camera021e5c68* cam = (Camera021e5c68*)gs->GetCamera();
    if (step->mode == 0) {
        if (cam != 0) ApplyVec3Tail_0202e694(cam, (int*)&step->offset);
    } else if (step->mode == 2) {
        fix32_t height = 1;
        Node021e5c68* node = GetNodeAtIndex021600f8((List021600f8*)list, 0);
        if (node != 0) {
            GameObject* c = gs->GetCombatantByIndex(node->combatant);
            if (c != 0) height = c->obj3D_.GetHeight();
        }
        float var5 = 1.0f;
        if (var2 >= 0x24cc) {
            var5 = 1.0f + ((var2 / 4096.0f - 2.3f) * 0.6f) / 1.7f;
            if (var5 >= 1.6f) var5 = 1.6f;
        }
        arg0->unknown_8_.z = (int)(4096.0f * ((arg0->unknown_8_.z / 4096.0f) * var5));
        if (var1 != 0) func_0202e694(var1, (int*)&arg0->unknown_8_);
    } else {
        if (var1 != 0) {
            Vector3fix var6 = var1->unknown_70_;
            Vector3fix var7 = arg0->unknown_8_;
            var6.x = var6.x + var7.x;
            var6.y = var6.y + var7.y;
            var6.z = var6.z + var7.z;
            func_0202e694(var1, (int*)&var6);
        }
    }
    char* var8 = func_ov000_02160130();
    if (var8 != 0) var8[Enum_ov025_021e5c68_28629] = 1;
    return 1;
}
