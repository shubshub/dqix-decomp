#include <globaldefs.h>

#if defined(jpn)
enum { Enum_02039850_596 = 0x248 };
#else
enum { Enum_02039850_596 = 0x254 };
#endif

// USA: func_02039850
extern "C" ARM unsigned char func_02039850(void* obj) {
    return *((unsigned char*)obj + Enum_02039850_596);
}
