#include <globaldefs.h>
#if defined(jpn)
enum { Enum_02072d58_14076 = 0x34ec, Enum_02072d58_336 = 0x144 };
#else
enum { Enum_02072d58_14076 = 0x36fc, Enum_02072d58_336 = 0x150 };
#endif
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" void func_02072c9c(int combatantId, char* buf);

struct HeadNode02046b24;
extern "C" int FieldTaskQueue_GetCurrentKind(struct HeadNode02046b24** obj);

extern char data_020f0cff[];

// USA: func_02072d58
extern "C" ARM void func_02072d58(int combatantId, char* arg1, char* outBuf) {
    func_02072c9c(combatantId, arg1);

    int base = ((int)GetGameResources());
    struct HeadNode02046b24** headTable = *(struct HeadNode02046b24***)((char*)base + Enum_02072d58_14076);
    int flag = 0;

    if (FieldTaskQueue_GetCurrentKind(headTable) == 0xa) {
        GameObject* c = GameState::GetInstance()->GetCombatantByIndex(combatantId);
        if (c != NULL) {
            flag = *(unsigned char*)(*(int*)((char*)c + 0x138) + 0x26);
        }
    }

    if (flag != 0) {
        sprintf(outBuf, data_020f0cff, arg1, 0x62);
        sprintf(arg1, data_020f0cff, arg1, 0x66);
    } else {
        sprintf(arg1, data_020f0cff, arg1, 0x6e);
        sprintf(outBuf, data_020f0cff, arg1, 0x65);
    }

    GameObject* c2 = func_0200ff1c(GameState::GetInstance(), combatantId);
    if (c2 == NULL) {
        return;
    }

    int val = *(int*)((char*)c2 + Enum_02072d58_336);
    struct Struct_02072d58 {
        unsigned char bit0 : 1;
        unsigned char rest : 7;
    };
    struct Struct_02072d58* var6 = (struct Struct_02072d58*)(val + 0x49c);

    if (var6->bit0 == 1) {
        arg1[0] = 0x77;
    }
}
