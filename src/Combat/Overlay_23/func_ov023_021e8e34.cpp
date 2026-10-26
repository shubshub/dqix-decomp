#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsActive(int* obj);

struct SearchStruct0202c1a4;
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);

extern "C" int func_02053c6c(unsigned char* obj);

extern "C" int func_02041a28(char* dst, int x);
extern "C" int Text_Append(char* dst, const char* src);

// USA: func_ov023_021e8e34
extern "C" ARM void func_ov023_021e8e34(void* obj) {
    if (*(int*)((char*)obj + 0x5f4) == 0) return;
    char* dst = *(char**)((char*)obj + 0x5d8);
    GameState* battleStruct = GameState::GetInstance();
    void* search = LinkSession_GetInstance();
    int fieldPtr = 0;
    if (!LinkSession_IsActive((int*)search)) {
        GameObject* combatant = func_0200ff1c(battleStruct, 0);
        if (combatant) fieldPtr = func_02053c6c((unsigned char*)combatant);
    } else {
        int id = LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)search);
        GameObject* combatant = func_0200ff1c(battleStruct, id);
        if (combatant) fieldPtr = func_02053c6c((unsigned char*)combatant);
    }
    if (fieldPtr == 0) return;
    char* str = (char*)fieldPtr + 0x3c;
    int len = strlen(str);
    int total = len * 5 + 6;
    int pad = (total / 8 + 1) * 8 - len * 5;
    pad = pad / 2;
    func_02041a28(dst, pad);
    Text_Append(dst, str);
}
