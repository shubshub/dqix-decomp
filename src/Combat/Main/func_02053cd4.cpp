#include <globaldefs.h>

// USA: func_02053cd4
extern "C" ARM int func_02053cd4(unsigned char* obj) {
#if defined(jpn)
    enum { Enum_02053cd4_440 = 0x1ac };
#else
    enum { Enum_02053cd4_440 = 0x1b8 };
#endif
    return *(int*)(obj + Enum_02053cd4_440);
}
