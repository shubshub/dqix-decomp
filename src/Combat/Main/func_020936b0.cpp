#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" ARM int FontBankLoader_GetInstance(void);
extern "C" ARM void FontBankLoader_CancelLoads(void* obj);
extern "C" ARM int MessageSystem_GetInstance();
extern "C" ARM void MessageSystem_Reset(char* obj);
extern "C" ARM void func_0200fb40(void* obj);

// USA: func_020936b0
extern "C" ARM void func_020936b0(void* obj) {
    unsigned char* self = (unsigned char*)obj;
    FontBankLoader_CancelLoads((void*)FontBankLoader_GetInstance());
    self[0x37] &= ~4;
    MessageSystem_Reset((char*)MessageSystem_GetInstance());
    *(short*)(self + 0x30) = -1;
    self[0x34] = 4;
    self[0x35] = 0;
    func_0200fb40(GameState::GetInstance());
}
