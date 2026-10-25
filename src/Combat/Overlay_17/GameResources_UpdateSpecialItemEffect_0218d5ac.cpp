#include <globaldefs.h>

extern "C" void func_020dbdc0(void* p);

// Overlay 17, originally CallIfField498_0218d5ac (USA/EUR 0x0218d5ac, JPN 0x0218e18c)
ARM void GameResources_UpdateSpecialItemEffect(void* obj) {
    void* p = *(void**)((char*)obj
#if defined(jpn)
 + 0x41e8
#else
 + 0x4498
#endif
);
    if (p) func_020dbdc0(p);
}
