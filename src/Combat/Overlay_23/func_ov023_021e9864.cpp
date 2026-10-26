#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_ov017_021d60f4(void*);
extern "C" void func_ov017_021d6134(void*, int);
extern "C" void* func_ov023_021e8f28(int);

// USA: func_ov023_021e9864
extern "C" ARM int func_ov023_021e9864(void* obj) {
    GameState::GetInstance();
    void* p = func_ov023_021e8f28(func_ov017_021d60f4(obj));
    if (p == NULL) return 0;
    void* q = *(void**)((char*)p + 0x130);
    unsigned short w = *(unsigned short*)((char*)q + 0x4);
    func_ov017_021d6134((char*)obj + 0x8, w);
    return 1;
}
