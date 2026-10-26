#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_ov000_0215eb1c(void* p0, short* arr, int count, int flag);
extern "C" GameObject* func_0200fea4(GameState* battleStruct, int combatantId);
extern short data_ov000_02182c44[8];

struct Struct_ov000_0215fc8c { short v[8]; };

struct Struct_ov000_0215fc8c_2 { char pad[0x10]; unsigned short val; };

// USA: func_ov000_0215fc8c
extern "C" ARM int func_ov000_0215fc8c(void* p0, int arg1) {
    short var0[8];
    *(struct Struct_ov000_0215fc8c*)var0 = *(struct Struct_ov000_0215fc8c*)data_ov000_02182c44;
    int count = (short)func_ov000_0215eb1c(p0, var0, 8, 0);
    int i = 0;
    while (i < count) {
        short id = var0[i];
        GameState* bs = GameState::GetInstance();
        GameObject* c = func_0200fea4(bs, id);
        if (c != NULL) {
            struct Struct_ov000_0215fc8c_2* inner = *(struct Struct_ov000_0215fc8c_2**)((char*)c + 0x144);
            if (inner != NULL) {
                if (inner->val == arg1) {
                    return 1;
                }
            }
        }
        i++;
    }
    return 0;
}
