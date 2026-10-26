#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* GameState_GetParty(GameState* battleStruct);
extern "C" void* func_02053c6c(unsigned char* obj);
extern "C" void* func_ov000_02161318(void* obj, int id);

// USA: func_ov000_02175628
extern "C" ARM void func_ov000_02175628(void* obj) {
    GameState* battleStruct = GameState::GetInstance();
    unsigned char* field2a04 = (unsigned char*)GameState_GetParty(battleStruct);
    unsigned char count = field2a04[0xf7c];
    unsigned char i;
    for (i = 0; i < count; i++) {
        signed char var4 = *(signed char*)(field2a04 + i + 0xf00 + 0x78);
        GameObject* combatant = battleStruct->GetPartyMemberByIndex(var4);
        if (combatant == 0) {
            continue;
        }
        void* p = func_02053c6c((unsigned char*)combatant);
#if defined(jpn)
        enum { Enum_ov000_02175628_2380 = 0x8b4 };
#else
        enum { Enum_ov000_02175628_2380 = 0x94c };
#endif
        signed char var7 = (signed char)*(int*)((char*)p + Enum_ov000_02175628_2380);
        if (var7 == 5) {
            continue;
        }
        char* entry = (char*)func_ov000_02161318(obj, var4);
        if (entry) {
            signed char off = *(signed char*)(entry + 0x18);
            *(entry + off + 0x10) = 0x64;
        }
    }
}
