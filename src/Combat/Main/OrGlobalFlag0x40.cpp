#include <globaldefs.h>

unsigned int* GlobalFlags_GetInstance(void);
void FlagWord_SetBits(unsigned int* p, unsigned int mask);

// USA: func_020dc2bc
ARM void OrGlobalFlag0x40_020dc2bc(void) {
    FlagWord_SetBits(GlobalFlags_GetInstance(), 0x40);
}
