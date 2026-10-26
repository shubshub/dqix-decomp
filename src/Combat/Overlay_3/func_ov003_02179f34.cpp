#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { Enum_ov003_02179f34_4096 = 0xf7c };
enum { Enum_ov003_02179f34_2204 = 0x818 };
#else
enum { Enum_ov003_02179f34_4096 = 0x1000 };
enum { Enum_ov003_02179f34_2204 = 0x89c };
#endif

extern "C" void* GameState_GetParty(GameState* battleStruct);
extern "C" short func_02080468(void* obj, int id);
extern "C" unsigned char func_0207ca94(int index);
extern "C" short func_0207c638(void* base, unsigned int index);
extern "C" int func_02053c6c(unsigned char* obj);
struct Struct_0207d300;
extern "C" int func_02083960(struct Struct_0207d300* s);
struct Struct_020a0b8c;
extern "C" int func_020a0b8c(struct Struct_020a0b8c* p);

// USA: func_ov003_02179f34
extern "C" ARM int func_ov003_02179f34(char* obj) {
    int result = 0;
    GameState* battle = GameState::GetInstance();
    void* ptr = GameState_GetParty(battle);
    short val = *(short*)(obj + Enum_ov003_02179f34_4096 + 0xc);
    void* var4 = *(void**)(obj + Enum_ov003_02179f34_2204);

    if (val == 0x77) {
        short id = func_02080468(var4, 0x1d);
        short idx = (short)(*(short*)(obj + Enum_ov003_02179f34_4096 + 0x12) - id);
        unsigned char var7 = func_0207ca94(idx);
        result = func_0207c638((char*)ptr + 0x1d4, var7);
    } else {
        signed char var8 = *(signed char*)(obj + Enum_ov003_02179f34_4096 + 0x43);
        int flag = result;
        if (var8 >= 0) {
            flag = (var8 <= 3) ? 1 : 0;
        }
        if (flag) {
            GameObject* combatant = battle->GetPartyMemberByIndex(var8);
            if (combatant != 0) {
                int f150 = func_02053c6c((unsigned char*)combatant);
                result = (short)func_02083960((struct Struct_0207d300*)f150);
            }
        } else {
            result = func_020a0b8c((struct Struct_020a0b8c*)ptr);
        }
    }
    return result;
}
