#include <globaldefs.h>

// USA: func_02026418
extern "C" ARM void func_02026418(unsigned char* obj, unsigned char value) {
#if defined(jpn)
    obj[0x6b8] = value;
#else
    obj[0x764] = value;
#endif
}
