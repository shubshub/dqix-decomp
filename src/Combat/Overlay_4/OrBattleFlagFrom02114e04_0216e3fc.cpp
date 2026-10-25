#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

void* GlobalFlags_GetInstance(void);
void FlagWord_SetBits(unsigned int* p, unsigned int mask);

// USA: func_ov004_0216e3fc  (semantic: OrBattleFlagFrom02114e04_0216e3fc)
extern "C" ARM int func_ov004_0216e3fc(void) {
    FlagWord_SetBits((unsigned int*)GlobalFlags_GetInstance(), 0x80);
    return 0;
}
