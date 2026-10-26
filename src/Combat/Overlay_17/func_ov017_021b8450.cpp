#include <globaldefs.h>

extern "C" void func_ov000_02160ad0(void*);

// USA: func_ov017_021b8450
extern "C" ARM void func_ov017_021b8450(void* obj) {
    void* p = *(void**)((char*)obj + 0x6ac);
    if (p) func_ov000_02160ad0(p);
}
