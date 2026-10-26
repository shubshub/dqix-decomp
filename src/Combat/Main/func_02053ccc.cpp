#include <globaldefs.h>

// USA: func_02053ccc
extern "C" ARM int func_02053ccc(unsigned char* obj) {
#if defined(jpn)
    return *(int*)(obj + 0x17c);
#else
    return *(int*)(obj + 0x188);
#endif
}
