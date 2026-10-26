#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_02154f80_812 = 0x328 };
enum { Enum_ov003_02154f80_503 = 0x1f3 };
enum { kRegion280 = 0x27c };
#else
enum { Enum_ov003_02154f80_812 = 0x32c };
enum { Enum_ov003_02154f80_503 = 0x1f7 };
enum { kRegion280 = 0x280 };
#endif

#include "GameState/GameState.h"

struct Struct_02059cfc_2;
struct Struct_02059cfc_3;
extern "C" void func_02059f38(struct Struct_02059cfc_2* dst, struct Struct_02059cfc_3* src);

// USA: func_ov003_02154f80
extern "C" ARM void func_ov003_02154f80(char* obj) {
    if (*(int*)(obj + Enum_ov003_02154f80_812) == 0) return;
    GameState* battleStruct = GameState::GetInstance();
    GameObject* combatant = battleStruct->GetPartyMemberByIndex(*(signed char*)(obj + Enum_ov003_02154f80_503));
    if (combatant != 0) {
        func_02059f38((struct Struct_02059cfc_2*)(obj + kRegion280), (struct Struct_02059cfc_3*)((char*)combatant + 0x44));
    }
    ((Object3D*)(obj + kRegion280))->AdvanceEffects();
    ((Object3D*)(obj + kRegion280))->Draw(1);
}
