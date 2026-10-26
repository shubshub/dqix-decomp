#include <globaldefs.h>
#include "Resource/GameResources.h"

extern "C" int func_ov017_021d60f4(void* obj);
struct FlagWord020466f4;
extern "C" void FlagWord_ClearBits(struct FlagWord020466f4* word, unsigned int mask);
extern "C" void FlagWord_SetBits(unsigned int* p, unsigned int mask);
extern "C" void func_020dc2d0(int mode);
extern "C" void* GlobalFlags_GetInstance(void);

// USA: func_ov001_0215aef0
extern "C" ARM int func_ov001_0215aef0(void* obj) {
    int cond = func_ov017_021d60f4(obj);
    void* p = GlobalFlags_GetInstance();
    (int)GetGameResources();
    if (cond != 0) {
        FlagWord_ClearBits((struct FlagWord020466f4*)p, 1);
        func_020dc2d0(0);
    } else {
        FlagWord_SetBits((unsigned int*)p, 1);
    }
    return 1;
}
