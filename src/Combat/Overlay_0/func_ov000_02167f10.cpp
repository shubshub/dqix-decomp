#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov000_02167f10_672 = 0x21c, Enum_ov000_02167f10_22865 = 0x5b41 };
#else
enum { Enum_ov000_02167f10_672 = 0x2a0, Enum_ov000_02167f10_22865 = 0x5951 };
#endif
#include "GameState/GameState.h"

struct Struct_02049e88;
extern "C" void func_02049e88(struct Struct_02049e88* obj);
extern "C" void func_02049ae4(unsigned char* obj);
extern "C" int func_020a35e0(unsigned char* obj, unsigned char index);

// USA: func_ov000_02167f10
extern "C" ARM void func_ov000_02167f10(unsigned char* obj) {
    GameState* bs = GameState::GetInstance();
    GameObject* c;
    int i;
    for (i = 0; i < 4; i++) {
        if (func_020a35e0(*(unsigned char**)(obj + Enum_ov000_02167f10_672), i & 0xff)) {
            c = bs->GetCombatantByIndex(i);
            if (c) {
                func_02049e88((struct Struct_02049e88*)c);
                func_02049ae4((unsigned char*)c);
            }
        }
    }
    for (i = 0xc0; i < 0xc8; i++) {
        c = bs->GetCombatantByIndex(i);
        if (c) {
            func_02049e88((struct Struct_02049e88*)c);
            func_02049ae4((unsigned char*)c);
        }
    }
    obj[Enum_ov000_02167f10_22865] &= ~0x3;
}
