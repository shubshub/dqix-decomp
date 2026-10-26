#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov000_02160f9c_1496 = 0x7c8 };
#else
enum { Enum_ov000_02160f9c_1496 = 0x5d8 };
#endif

// USA: func_ov000_02160f9c
extern "C" ARM int func_ov000_02160f9c(void* obj) {
    return *(int*)((char*)obj + 0x5000 + Enum_ov000_02160f9c_1496);
}
