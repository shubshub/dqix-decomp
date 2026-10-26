#include <globaldefs.h>

// USA: func_020340f4
extern "C" ARM void func_020340f4(unsigned char* object) {
    object[0xc1] &= ~4;  // set by func_020340e4; no reader found
}
