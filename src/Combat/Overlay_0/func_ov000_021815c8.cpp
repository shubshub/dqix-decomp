#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov000_021815c8_7531 = 0x1fa3 };
#else
enum { Enum_ov000_021815c8_7531 = 0x1d6b };
#endif

// USA: func_ov000_021815c8
extern "C" ARM int func_ov000_021815c8(void* obj) {
    signed char val = *((signed char*)obj + Enum_ov000_021815c8_7531);
    if (val < 0) return -1;
    return *((signed char*)obj + val + 0x70);
}
