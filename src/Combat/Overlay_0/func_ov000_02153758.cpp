#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" GameObject* func_0200ff94(GameState*, int);
struct Struct_0206f01c_2;
extern "C" void* func_0206f4f0(struct Struct_0206f01c_2* base, int key);

// USA: func_ov000_02153758
extern "C" ARM void* func_ov000_02153758(void* obj, int idx) {
    int flag = (idx >= 0 && idx <= 3);
    if (flag) return 0;
    GameState* battleStruct = GameState::GetInstance();
    GameObject* combatant = func_0200ff94(battleStruct, idx);
    if (combatant == 0) return 0;
    int base = *(int*)((char*)obj + 0x8000 + 0xe18);
    short key = combatant->obj3D_.unknown_2_;
    return func_0206f4f0((struct Struct_0206f01c_2*)((char*)base + 0x678), key);
}
