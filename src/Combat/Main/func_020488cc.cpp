#include <globaldefs.h>

// USA: func_020488cc
extern "C" ARM void func_020488cc(unsigned char* obj, int value) {
    obj[0x180] = value != 0;
    if (value) {
        obj[0x17f] = 0;
    }
}
