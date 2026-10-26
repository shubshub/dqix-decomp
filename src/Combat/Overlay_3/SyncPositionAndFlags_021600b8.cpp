#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { kRegionValue31C_204 = 0x204 };
#else
enum { kRegionValue31C_204 = 0x31c };
#endif

int GameState_GetProtagonistIndex(GameState* battleStruct);
GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState* battleStruct, int combatantId);
struct Vector3i;
extern "C" void GameObject_Draw(void* a, int b, int c);

struct Struct31c_021600b8 { char pad[kRegionValue31C_204]; int field31c; void* field320; };

// USA: func_ov003_021600b8  (semantic: SyncPositionAndFlags_021600b8)
extern "C" ARM void func_ov003_021600b8(Struct31c_021600b8* obj) {
    GameState* battleStruct = GameState::GetInstance();
    if (obj->field31c == 0 || obj->field320 == 0) return;
    int val = GameState_GetProtagonistIndex(battleStruct);
    GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(battleStruct, val);
    if (combatant == 0) return;
    *(Vector3i*)((int*)((char*)obj->field320 + 0x44)) = *(Vector3i const*)(&combatant->obj3D_.position_.x);
    *(int*)0x4000444 = 0;
    GameObject_Draw(obj->field320, 0, 0);
    *(int*)0x4000448 = 1;
}
