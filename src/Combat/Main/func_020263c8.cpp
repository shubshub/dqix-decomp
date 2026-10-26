#include <globaldefs.h>

// USA: func_020263c8
extern "C" ARM void func_020263c8(unsigned char* obj, int value) {
#if defined(jpn)
    obj[0x6cc] = value != 0;
#else
    obj[0x778] = value != 0;
#endif
}
