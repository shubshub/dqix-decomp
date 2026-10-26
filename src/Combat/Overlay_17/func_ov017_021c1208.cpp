#include <globaldefs.h>

extern "C" void func_ov008_02184918(void* p);

// USA: func_ov017_021c1208
extern "C" ARM void func_ov017_021c1208(void* obj) {
    void* p = *(void**)((char*)obj + 0x1c);
    if (p) func_ov008_02184918(p);
}
