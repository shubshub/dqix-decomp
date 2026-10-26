#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov000_02160094 {
    char pad[0x30];
    struct Struct_ov000_02160094* next;
};

struct Struct_ov000_0215440c_2 {
    char pad0[8];
    unsigned char count;
    char pad1[7];
    struct Struct_ov000_02160094* head;
};
extern "C" struct Struct_ov000_02160094* func_ov000_02160094(struct Struct_ov000_0215440c_2* list, int index);

// USA: func_ov000_021819c8
extern "C" ARM int func_ov000_021819c8(struct Struct_ov000_0215440c_2* list, int index, int* out, int flag) {
    GameState* battleStruct = GameState::GetInstance();
    struct Struct_ov000_02160094* node = func_ov000_02160094(list, index);
    if (node != NULL) {
        int var2 = 0;
        if (flag == 0) {
            var2 = *(unsigned short*)((char*)node + 0x20) * 0xc + 0x1c;
        } else if (flag == 1) {
            var2 = *(unsigned short*)((char*)node + 0x20) * 0xc + 0x1d;
        }

        GameObject* combatant = battleStruct->GetGameObjectByIndex(var2);
        if (combatant != NULL) {
            if (combatant->obj3D_.unknown_2_ > -1) {
                *out = var2;
                return 1;
            }
        }
    }
    return 0;
}
