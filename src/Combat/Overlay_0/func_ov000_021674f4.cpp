#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_020a35e0(unsigned char* obj, unsigned char index);
struct ArrayContainsByteStruct;
extern "C" int func_02086ef0(struct ArrayContainsByteStruct* s, int val);
extern "C" int func_02053c6c(unsigned char* obj);
extern "C" void func_02083c48(void* p, int flag, int mode);

// USA: func_ov000_021674f4
extern "C" ARM void func_ov000_021674f4(unsigned char* obj, int arg1) {
    GameState* battle = GameState::GetInstance();
    struct ArrayContainsByteStruct* base = (struct ArrayContainsByteStruct*)GameState_GetParty(battle);
#if defined(jpn)
    enum { Enum_ov000_021674f4_668 = 0x218 };
#else
    enum { Enum_ov000_021674f4_668 = 0x29c };
#endif
    unsigned char* bits = *(unsigned char**)((char*)*(void**)(obj + Enum_ov000_021674f4_668) + 0x8000 + 0xe18);
    for (int i = 0; i < 4; i++) {
        if (!func_020a35e0(bits, i)) continue;
        if (arg1 == 0) {
            if (!func_02086ef0(base, i)) continue;
        }
        GameObject* c = battle->GetPartyMemberByIndex(i);
        if (!c) continue;
        int var5 = func_02053c6c((unsigned char*)c);
        int contains = func_02086ef0(base, i);
        func_02083c48((void*)var5, contains, 1);
    }
}
