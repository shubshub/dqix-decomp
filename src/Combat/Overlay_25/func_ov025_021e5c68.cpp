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

void Camera_SetOrbitVector(void* obj, int* vec);
struct List021600f8;
Node021e5c68* GetNodeAtIndex021600f8(List021600f8*, int);
char* GetActiveCombatWork_ov000_02160130();

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
        if (cam != 0) Camera_SetOrbitVector(cam, (int*)&step->offset);
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
        step->offset.z = (int)(4096.0f * ((step->offset.z / 4096.0f) * scale));
        if (cam != 0) Camera_SetOrbitVector(cam, (int*)&step->offset);
    } else {
        if (cam != 0) {
            Vector3fix pos = cam->position;
            Vector3fix off = step->offset;
            pos.x = pos.x + off.x;
            pos.y = pos.y + off.y;
            pos.z = pos.z + off.z;
            Camera_SetOrbitVector(cam, (int*)&pos);
        }
    }
    char* var8 = func_ov000_02160130();
    if (var8 != 0) var8[Enum_ov025_021e5c68_28629] = 1;
    return 1;
}
