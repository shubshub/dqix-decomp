#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* GameState_GetParty(GameState* battleStruct);

struct Struct_020a0b8c;
extern "C" int func_020a0b8c(struct Struct_020a0b8c* p);
extern "C" int func_02053c6c(unsigned char* obj);
struct Struct_0207d300;
extern "C" int func_02083960(struct Struct_0207d300* s);

// USA: func_ov002_02157108
extern "C" ARM int func_ov002_02157108(void* unused, int id) {
    GameState* bs = GameState::GetInstance();
    int result = 0;
    if (id == 5) {
        void* p = (char*)GameState_GetParty(bs) + 0xe04;
        result = func_020a0b8c((struct Struct_020a0b8c*)p);
    } else if (id == 4) {
        void* p = GameState_GetParty(bs);
        result = func_020a0b8c((struct Struct_020a0b8c*)p);
    } else {
        GameObject* c = func_0200ff1c(bs, id);
        if (c != NULL) {
            int var5 = func_02053c6c((unsigned char*)c);
            result = func_02083960((struct Struct_0207d300*)var5);
        }
    }
    return result;
}
