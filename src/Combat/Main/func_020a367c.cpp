#include <globaldefs.h>

// USA: func_020a367c
extern "C" ARM void func_020a367c(unsigned char* obj, int index) {
    obj[0x34] &= ~(1 << index);
}
