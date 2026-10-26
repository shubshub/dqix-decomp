#include <globaldefs.h>

// USA: func_0204f160
extern "C" ARM void func_0204f160(unsigned char* obj, int value, int b) {
    if ((obj[0xc5] & 1) == 0) {
        *(int*)(obj + 0xa0) = value;
        obj[0xc4] = b;
    }
}
