#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov000_02160f08_1888 = 0x31c, Enum_ov000_02160f08_12288 = 0x3400 };
#else
enum { Enum_ov000_02160f08_1888 = 0x760, Enum_ov000_02160f08_12288 = 0x3000 };
#endif

// USA: func_ov000_02160f08
extern "C" ARM void* func_ov000_02160f08(void* obj) {
    return (char*)obj + Enum_ov000_02160f08_1888 + Enum_ov000_02160f08_12288;
}
