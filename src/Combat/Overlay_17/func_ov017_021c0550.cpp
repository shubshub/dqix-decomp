#include <globaldefs.h>

extern "C" void func_ov014_02186dc8(void*);

// USA: func_ov017_021c0550
extern "C" ARM void func_ov017_021c0550(void* obj) {
    void* p = *(void**)((char*)obj + 0x20);
    if (p) func_ov014_02186dc8(p);
}
