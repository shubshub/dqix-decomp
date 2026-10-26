#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov000_0215440c_2;
struct Struct_ov000_02160094;
struct Struct_ov000_0215440c;
struct Struct_ov000_021600f8;

extern "C" struct Struct_ov000_02160094* func_ov000_02160094(struct Struct_ov000_0215440c_2* list, int index);
extern "C" struct Struct_ov000_021600f8* func_ov000_021600f8(struct Struct_ov000_0215440c* list, int index);
extern "C" void GameObject_FaceGameObject(void* combatant, int arg1, int arg2);

// USA: func_ov025_021e45c4
extern "C" ARM int func_ov025_021e45c4(void* unused, void* list) {
    struct Struct_ov000_02160094* a = func_ov000_02160094((struct Struct_ov000_0215440c_2*)list, 0);
    struct Struct_ov000_021600f8* b = func_ov000_021600f8((struct Struct_ov000_0215440c*)list, 0);
    if (a == 0 || b == 0) return 1;
    GameState* bs = GameState::GetInstance();
    GameObject* c = bs->GetCombatantByIndex(*(unsigned short*)((char*)a + 0x20));
    if (c != 0) {
        GameObject_FaceGameObject(c, *(short*)((char*)b + 0xe), 0);
    }
    return 1;
}
