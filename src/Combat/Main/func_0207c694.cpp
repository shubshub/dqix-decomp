#include <globaldefs.h>
// USA: func_0207c694
extern "C" ARM unsigned char func_0207c694(unsigned char *base, unsigned int index) {
    if (index > 7) return -1;
    return *(base + index + 0xc28);
}
