#include <globaldefs.h>

extern "C" void func_ov008_02184968(void* p);

// USA: func_ov017_021c1220
extern "C" ARM void func_ov017_021c1220(void* obj) {
    void* p = *(void**)((char*)obj + 0x1c);
    if (p) func_ov008_02184968(p);
}
