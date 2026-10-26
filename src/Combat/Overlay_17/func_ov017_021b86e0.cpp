#include <globaldefs.h>

extern "C" void func_ov000_02166e3c(void* work);

// USA: func_ov017_021b86e0
extern "C" ARM void func_ov017_021b86e0(void* obj) {
    void* p = *(void**)((char*)obj + 0x6ac);
    if (p) func_ov000_02166e3c(p);
}
