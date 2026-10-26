#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void __clear(void* buf, int n);
extern "C" unsigned char GameState_GetOwnPartyOrder(char* obj, void* dst);
extern "C" void func_ov017_021d6134(void*, int);

struct Struct_ov023_021ea3ec { char pad[0x130]; unsigned short* unknown_130_; };

// USA: func_ov023_021ea3ec
extern "C" ARM int func_ov023_021ea3ec(void* obj) {
    GameState* bs = GameState::GetInstance();
    unsigned char buf[4];
    __clear(buf, 4);
    unsigned char len = GameState_GetOwnPartyOrder((char*)bs, buf);
    int count = 0;
    for (int i = 1; i < len; i++) {
        unsigned char id = buf[i];
        struct Struct_ov023_021ea3ec* c = (struct Struct_ov023_021ea3ec*)func_0200ff1c(bs, id);
        if (c) {
            int val = *(unsigned short*)((char*)c->unknown_130_ + 4);
            if (val <= 0) count++;
        }
    }
    func_ov017_021d6134(obj, count);
    return 1;
}
