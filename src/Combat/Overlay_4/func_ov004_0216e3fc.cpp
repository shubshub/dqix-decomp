#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" void* GlobalFlags_GetInstance(void);
extern "C" void FlagWord_SetBits(unsigned int* p, unsigned int mask);

// USA: func_ov004_0216e3fc
extern "C" ARM int func_ov004_0216e3fc(void) {
    FlagWord_SetBits((unsigned int*)GlobalFlags_GetInstance(), 0x80);
    return 0;
}
