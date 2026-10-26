#include <globaldefs.h>

extern "C" void func_ov003_0215ca1c(void*);

// USA: func_ov017_021bae80
extern "C" ARM void func_ov017_021bae80(void* obj) {
    void* p = *(void**)((char*)obj + 0x20);
    if (p) func_ov003_0215ca1c(p);
}
