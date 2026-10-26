#include <globaldefs.h>

#if defined(jpn)
enum { Enum_02053f74_432 = 0x1a4 };
#else
enum { Enum_02053f74_432 = 0x1b0 };
#endif

// USA: func_02053f74
extern "C" ARM unsigned char func_02053f74(void* obj) {
    return *(unsigned char*)((char*)obj + Enum_02053f74_432);
}
