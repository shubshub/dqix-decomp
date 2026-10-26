#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsActive(int* obj);
extern "C" int LinkSession_IsGuest(void* p);
extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

// USA: func_ov017_021cfabc
extern "C" ARM void func_ov017_021cfabc(void) {
    void* x = LinkSession_GetInstance();
    if (LinkSession_IsActive((int*)x) != 0 && LinkSession_IsGuest(x) == 0) {
        GameState::GetInstance();
        void* p = LinkMessageQueue_GetInstance();
        unsigned char buf[0x14];
        buf[0] = 0xa1;
        func_0205e330(p, buf, 0);
    }
}
