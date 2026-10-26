#include <globaldefs.h>

// USA: func_02026420
extern "C" ARM void func_02026420(unsigned char* obj, unsigned char value) {
#if defined(jpn)
    obj[0x6b9] = value;
#else
    obj[0x765] = value;
#endif
}
