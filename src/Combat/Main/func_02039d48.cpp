#include <globaldefs.h>

// USA: func_02039d48
extern "C" ARM void func_02039d48(unsigned char* obj) {
#if defined(jpn)
    obj[0x1c2] |= 4;
#else
    obj[0x1ce] |= 4;
#endif
}
