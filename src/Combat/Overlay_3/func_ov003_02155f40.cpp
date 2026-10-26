#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_02155f40_336 = 0x144 };
enum { Enum_ov003_02155f40_2384 = 0x8b8 };
#else
enum { Enum_ov003_02155f40_336 = 0x150 };
enum { Enum_ov003_02155f40_2384 = 0x950 };
#endif
#include "GameState/GameState.h"

extern "C" void* func_ov003_02156034(void* obj);

// USA: func_ov003_02155f40
extern "C" ARM int func_ov003_02155f40(void* obj, int combatantId) {
    GameState* bs = GameState::GetInstance();
    GameObject* combatant = bs->GetPartyMemberByIndex(combatantId);
    int result;
    if (combatant != NULL) {
        void* inner = *(void**)((char*)combatant + Enum_ov003_02155f40_336);
        int val = *(int*)((char*)inner + Enum_ov003_02155f40_2384);
        result = (val == (int)func_ov003_02156034(obj)) ? 1 : 0;
    } else {
        result = 0;
    }
    return result;
}
