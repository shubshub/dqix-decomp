#include <globaldefs.h>

// USA: func_ov003_02167240
extern "C" ARM void func_ov003_02167240(void* obj) {
#if defined(jpn)
    enum { fieldOffset = 0x2d8 };
#else
    enum { fieldOffset = 0x4b0 };
#endif
    *(int*)((char*)obj + fieldOffset) = 1;
}
