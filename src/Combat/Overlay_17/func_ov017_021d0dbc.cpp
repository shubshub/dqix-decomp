#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_ov017_021d0e00(int val);

// USA: func_ov017_021d0dbc
extern "C" ARM void func_ov017_021d0dbc(void) {
    LinkMessageQueue_GetInstance();
    unsigned char* battle = (unsigned char*)GameState_GetParty(GameState::GetInstance());
    unsigned char count = battle[0xf7c];
    for (unsigned char i = 0; i < count; i++) {
        signed char v = *(signed char*)(battle + i + 0xf78);
        func_ov017_021d0e00(v);
    }
}
