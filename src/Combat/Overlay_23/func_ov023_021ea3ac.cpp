#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void __clear(void* buf, int n);
extern "C" unsigned char GameState_GetOwnPartyOrder(char* obj, void* dst);
extern "C" void func_ov017_021d6134(void* obj, int v);

// USA: func_ov023_021ea3ac
extern "C" ARM int func_ov023_021ea3ac(void* obj) {
    GameState* bs = GameState::GetInstance();
    char buf[4];
    __clear(buf, 4);
    int v = GameState_GetOwnPartyOrder((char*)bs, buf);
    func_ov017_021d6134(obj, v - 1);
    return 1;
}
