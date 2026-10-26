#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov000_02160f14_24 = 0x394, Enum_ov000_02160f14_3072 = 0x800 };
#else
enum { Enum_ov000_02160f14_24 = 0x18, Enum_ov000_02160f14_3072 = 0xc00 };
#endif

// USA: func_ov000_02160f14
extern "C" ARM void* func_ov000_02160f14(void* obj) {
    char* p = (char*)obj + Enum_ov000_02160f14_24;
    return p + Enum_ov000_02160f14_3072;
}
