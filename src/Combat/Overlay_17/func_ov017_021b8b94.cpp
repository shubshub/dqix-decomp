#include <globaldefs.h>

extern "C" int func_ov000_0216265c(void* objRaw);

// USA: func_ov017_021b8b94
extern "C" ARM int func_ov017_021b8b94(void* obj) {
    void* p = *(void**)((char*)obj + 0x6ac);
    if (p == NULL) {
        return 0;
    }
    return func_ov000_0216265c(p);
}
