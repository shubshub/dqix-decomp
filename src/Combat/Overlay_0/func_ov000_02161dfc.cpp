#include <globaldefs.h>

// USA: func_ov000_02161dfc
extern "C" ARM void func_ov000_02161dfc(unsigned char* dst, unsigned char* src) {
    int n = 0x16;
    unsigned char* d = dst + 0x3e;
    unsigned char* s = src;
    do {
        *d = *s;
        s++;
        n--;
        d++;
    } while (n != 0);
    dst[0x54] = src[0x16];
    dst[0x55] = src[0x17];
}
