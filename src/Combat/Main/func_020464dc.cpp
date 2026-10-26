#include <globaldefs.h>

// USA: func_020464dc
extern "C" ARM void func_020464dc(void* obj, signed char value) {
#if defined(jpn)
    *((unsigned char*)obj + 0x1750) = value;
#else
    *((unsigned char*)obj + 0x1880) = value;
#endif
}
