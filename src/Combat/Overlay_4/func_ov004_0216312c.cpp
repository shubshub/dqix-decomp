#include <globaldefs.h>

struct FlagWord020466f4 {
    unsigned int flags;
};
extern "C" void* GlobalFlags_GetInstance(void);
extern "C" void FlagWord_ClearBits(struct FlagWord020466f4* word, unsigned int mask);

// USA: func_ov004_0216312c
extern "C" ARM int func_ov004_0216312c(void) {
    FlagWord_ClearBits((struct FlagWord020466f4*)GlobalFlags_GetInstance(), 1);
    return 0;
}
