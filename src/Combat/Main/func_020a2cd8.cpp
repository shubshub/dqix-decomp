#include <globaldefs.h>

// USA: func_020a2cd8
extern "C" ARM void func_020a2cd8(unsigned char* obj, int flag) {
    if (flag != 0) {
        obj[0x245] |= 2;
    } else {
        obj[0x245] &= ~2;
    }
}
