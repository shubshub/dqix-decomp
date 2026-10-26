#include <globaldefs.h>

// USA: func_020488ac
extern "C" ARM void func_020488ac(unsigned char* obj, int value) {
    obj[0x17f] = value != 0;
    if (value) {
        obj[0x180] = 0;
    }
}
