#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { Enum_ov003_021600b8_796 = 0x204 };
#else
enum { Enum_ov003_021600b8_796 = 0x31c };
#endif

extern "C" int GameState_GetProtagonistIndex(GameState* battleStruct);
extern "C" GameObject* func_0200ff1c(GameState* battleStruct, int combatantId);
struct Vector3i;
extern "C" void GameObject_Draw(void* a, int b, int c);

struct Struct_ov003_021600b8 { char pad[Enum_ov003_021600b8_796]; int unknown_31c_; void* field320; };

// USA: func_ov003_021600b8
extern "C" ARM void func_ov003_021600b8(Struct_ov003_021600b8* obj) {
    GameState* battleStruct = GameState::GetInstance();
    if (obj->unknown_31c_ == 0 || obj->field320 == 0) return;
    int val = GameState_GetProtagonistIndex(battleStruct);
    GameObject* combatant = func_0200ff1c(battleStruct, val);
    if (combatant == 0) return;
    *(Vector3i*)((int*)((char*)obj->field320 + 0x44)) = *(Vector3i const*)(&combatant->obj3D_.position_.x);
    *(int*)0x4000444 = 0;
    GameObject_Draw(obj->field320, 0, 0);
    *(int*)0x4000448 = 1;
}
