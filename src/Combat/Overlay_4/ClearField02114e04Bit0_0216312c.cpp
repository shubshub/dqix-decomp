#include <globaldefs.h>

struct FlagWord020466f4 {
    unsigned int flags;
};
void* GlobalFlags_GetInstance(void);
void FlagWord_ClearBits(struct FlagWord020466f4* word, unsigned int mask);

// USA: func_ov004_0216312c
ARM int ClearField02114e04Bit0_0216312c(void) {
    FlagWord_ClearBits((struct FlagWord020466f4*)GlobalFlags_GetInstance(), 1);
    return 0;
}
