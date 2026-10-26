#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov000_02167dd8_672 = 0x21c, Enum_ov000_02167dd8_2385 = 0xb41 };
#else
enum { Enum_ov000_02167dd8_672 = 0x2a0, Enum_ov000_02167dd8_2385 = 0x951 };
#endif
#include "GameState/GameState.h"

extern "C" int func_020a35e0(unsigned char* obj, unsigned char index);
extern "C" void func_02049e00(void);

// USA: func_ov000_02167dd8
extern "C" ARM void func_ov000_02167dd8(unsigned char* obj) {
    GameState* battle = GameState::GetInstance();
    for (int i = 0; i < 4; i++) {
        if (func_020a35e0(*(unsigned char**)(obj + Enum_ov000_02167dd8_672), i)) {
            if (battle->GetCombatantByIndex(i)) func_02049e00();
        }
    }
    for (int i = 0xc0; i < 0xc8; i++) {
        if (battle->GetCombatantByIndex(i)) func_02049e00();
    }
    unsigned char b = *(unsigned char*)(obj + 0x5000 + Enum_ov000_02167dd8_2385);
    b = (b & ~3) | 2;
    *(unsigned char*)(obj + 0x5000 + Enum_ov000_02167dd8_2385) = b;
}
