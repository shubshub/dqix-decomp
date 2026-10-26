#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov000_02161318(void* obj, int idx);

extern "C" int func_02053c6c(unsigned char* obj);
extern "C" int func_ov000_021719f8(int* obj);

// USA: func_ov000_021756b8
extern "C" ARM void func_ov000_021756b8(void* obj) {
    GameState* bs = GameState::GetInstance();
    unsigned char* p2a04 = (unsigned char*)GameState_GetParty(bs);
    unsigned char count = p2a04[0xf7c];
    unsigned char i;
    for (i = 0; i < count; i++) {
        signed char combatantId = *((signed char*)p2a04 + i + 0xf00 + 0x78);
        GameObject* c = bs->GetPartyMemberByIndex(combatantId);
        if (c == 0) {
            continue;
        }
        int var6 = func_02053c6c((unsigned char*)c);
#if defined(jpn)
        enum { Enum_ov000_021756b8_2380 = 0x8b4 };
#else
        enum { Enum_ov000_021756b8_2380 = 0x94c };
#endif
        int val = *(int*)(var6 + Enum_ov000_021756b8_2380);
        signed char var8 = (signed char)val;
        if (var8 == 5) {
            continue;
        }
        void* e = func_ov000_02161318(obj, combatantId);
        if (e == 0) {
            continue;
        }
        if (func_ov000_021719f8((int*)e) == 0) {
            signed char off = *((signed char*)e + 0x18);
            unsigned char* p = (unsigned char*)e + off;
            p[0x10] = 0xd;
        }
    }
}
