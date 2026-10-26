#include <globaldefs.h>
// USA: func_0207c6a8
extern "C" ARM void func_0207c6a8(unsigned char* base, unsigned int index, unsigned char value) {
    if (index <= 7) {
        *(base + index + 0xc28) = value;
    }
}
