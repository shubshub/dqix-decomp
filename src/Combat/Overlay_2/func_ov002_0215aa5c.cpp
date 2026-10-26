#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_02039730(void* unused, int index);

// USA: func_ov002_0215aa5c
extern "C" ARM void func_ov002_0215aa5c(char* base) {
#if defined(jpn)
    enum { Enum_ov002_0215aa5c_3196 = 0xb40 };
#else
    enum { Enum_ov002_0215aa5c_3196 = 0xc7c };
#endif
    GameObject* combatant = GameState::GetInstance()->GetProtagonist();
    if (!combatant) return;
    for (int i = 0; i < 7; i++) {
        signed char value = (signed char)func_02039730(combatant, i);
        *(signed char*)(base + i + 0x1000 + Enum_ov002_0215aa5c_3196) = value;
    }
}
