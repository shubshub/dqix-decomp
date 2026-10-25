#include <globaldefs.h>
#include "GameState/GameState.h"

ARM int FontBankLoader_GetInstance(void);
extern "C" ARM void FontBankLoader_CancelLoads(void* obj);
ARM int MessageSystem_GetInstance();
ARM void MessageSystem_Reset(char* obj);
ARM void ClearSubstructBytes_0200fb40(void* obj);

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_020936b0
ARM void ResetBattlePhaseController020936b0(void* obj) {
    unsigned char* self = (unsigned char*)obj;
    FontBankLoader_CancelLoads((void*)FontBankLoader_GetInstance());
    self[0x37] &= ~4;
    MessageSystem_Reset((char*)MessageSystem_GetInstance());
    *(short*)(self + 0x30) = -1;
    self[0x34] = 4;
    self[0x35] = 0;
    ClearSubstructBytes_0200fb40(GameState::GetInstance());
}
