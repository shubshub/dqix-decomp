#include <globaldefs.h>

extern "C" void func_02001b2c(void* dst, int value, unsigned int n);

// KEEP-NAME: the ROM symbol is the C library name, not a func_ tag.
// USA: func_02001aac
extern "C" ARM void* memset(void* dst, int value, unsigned int n) {
    func_02001b2c(dst, value, n);
    return dst;
}
