#include <globaldefs.h>

#if defined(jpn)
enum { Enum_020546b4_721 = 0x2c5 };
#else
enum { Enum_020546b4_721 = 0x2d1 };
#endif

// USA: func_020546b4
extern "C" ARM void func_020546b4(void* obj, int value) {
    *(unsigned char*)((char*)obj + Enum_020546b4_721) = value;
}
