#include <globaldefs.h>

extern "C" unsigned int* GlobalFlags_GetInstance(void);
extern "C" void FlagWord_SetBits(unsigned int* p, unsigned int mask);

// USA: func_020dc2bc
extern "C" ARM void func_020dc2bc(void) {
    FlagWord_SetBits(GlobalFlags_GetInstance(), 0x40);
}
