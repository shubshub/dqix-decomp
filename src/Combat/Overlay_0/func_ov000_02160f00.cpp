#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov000_02160f00_2864 = 0xaac };
#else
enum { Enum_ov000_02160f00_2864 = 0xb30 };
#endif

// USA: func_ov000_02160f00
extern "C" ARM void* func_ov000_02160f00(void* obj) {
    return (char*)obj + Enum_ov000_02160f00_2864;
}
