#include <globaldefs.h>

// USA: func_0200f374
extern "C" ARM void* __clear(void* dst, int count) {
    unsigned char* p = (unsigned char*)dst;
    if (dst != 0 && count != 0) {
        do {
            *p++ = 0;
        } while (--count);
    }
    return dst;
}
