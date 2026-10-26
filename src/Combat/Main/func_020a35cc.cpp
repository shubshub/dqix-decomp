#include <globaldefs.h>

// USA: func_020a35cc
extern "C" ARM void func_020a35cc(unsigned char* obj, unsigned char index) {
    obj[0x34] |= 1 << index;
}
