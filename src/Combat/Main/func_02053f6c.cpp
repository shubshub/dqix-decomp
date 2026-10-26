#include <globaldefs.h>

// USA: func_02053f6c
extern "C" ARM void func_02053f6c(void* obj, unsigned char value) {
#if defined(jpn)
    *(unsigned char*)((char*)obj + 0x1a4) = value;
#else
    *(unsigned char*)((char*)obj + 0x1b0) = value;
#endif
}
