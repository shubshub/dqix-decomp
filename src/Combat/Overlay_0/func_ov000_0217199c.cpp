#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov000_0217199c_420 = 0x1e4 };
#else
enum { Enum_ov000_0217199c_420 = 0x1a4 };
#endif

// USA: func_ov000_0217199c
extern "C" ARM int func_ov000_0217199c(void* obj, int index) {
    if (index < 0 || index >= 0x93) return 0;
    return *(int*)((char*)obj + Enum_ov000_0217199c_420 + (index << 2));
}
