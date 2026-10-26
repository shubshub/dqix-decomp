#include <globaldefs.h>

// USA: func_020546a0
extern "C" ARM void func_020546a0(void* obj, int value) {
#if defined(jpn)
    *(unsigned char*)((char*)obj + 0x2c4) = value;
#else
    *(unsigned char*)((char*)obj + 0x2d0) = value;
#endif
}
