#include <globaldefs.h>

// USA: func_ov031_0221563c
extern "C" ARM unsigned int func_ov031_0221563c(int n) {
    unsigned int w = 0xffffffff;
    int i = 0;
    int shift = 0x20 - n;
    if (shift > 0) {
        do {
            i++;
            w = w << 1;
        } while (i < shift);
    }
    return ((w >> 24) & 0xff) | ((w >> 8) & 0xff00) | ((w << 8) & 0xff0000) | ((w << 24) & 0xff000000);
}
