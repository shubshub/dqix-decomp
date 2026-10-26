#include <globaldefs.h>

#if defined(jpn)
enum { Enum_020dd154_2384 = 0x8b8 };
#else
enum { Enum_020dd154_2384 = 0x950 };
#endif
extern "C" int func_020dd19c(unsigned int, int);
#include "GameState/GameState.h"

extern "C" void* func_02053c6c(unsigned char*);

// USA: func_020dd154
extern "C" ARM int func_020dd154(int combatantId, int b) {
    GameObject* combatant = func_0200ff1c(GameState::GetInstance(), combatantId);
    if (combatant == NULL) {
        return 0;
    }
    void* p = func_02053c6c((unsigned char*)combatant);
    if (p == NULL) {
        return 0;
    }
    int val = *(int*)((char*)p + Enum_020dd154_2384);
    return func_020dd19c((unsigned int)(val & 0xff), (int)(b));
}
