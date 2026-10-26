#include <globaldefs.h>

// USA: func_02053ec0
extern "C" ARM void func_02053ec0(unsigned char* obj, int value) {
#if defined(jpn)
    obj[0x19b] = value;
#else
    obj[0x1a7] = value;
#endif
}
