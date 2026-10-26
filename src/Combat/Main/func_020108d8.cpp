#include <globaldefs.h>

#if defined(jpn)
enum { Enum_020108d8_2404 = 0x8cc };
#else
enum { Enum_020108d8_2404 = 0x964 };
#endif

// USA: func_020108d8
extern "C" ARM void* func_020108d8(char* base, int index) {
    return base + 0x474 + index * Enum_020108d8_2404;
}
