#include <globaldefs.h>

unsigned int DisableIRQInterrupts(void);
extern "C" int func_020d41e8(void);
unsigned int SetIRQInterruptState(int mask);
extern "C" void* func_020d41d8(void);

// USA: func_020d472c
extern "C" ARM int func_020d472c(void* param) {
    unsigned int mask = DisableIRQInterrupts();
    int state = func_020d41e8();
    if (state != 0) {
        SetIRQInterruptState(mask);
        return state;
    }
    void* ctx = func_020d41d8();
    *(void**)((char*)ctx + 0xc8) = param;
    SetIRQInterruptState(mask);
    return 0;
}
