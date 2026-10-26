#include <globaldefs.h>

extern "C" void func_ov000_02160c84(void*);

// USA: func_ov017_021b8438
extern "C" ARM void func_ov017_021b8438(void* obj) {
    void* p = *(void**)((char*)obj + 0x6ac);
    if (p) func_ov000_02160c84(p);
}
