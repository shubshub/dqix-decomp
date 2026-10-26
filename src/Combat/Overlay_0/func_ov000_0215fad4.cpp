#include <globaldefs.h>

// USA: func_ov000_0215fad4
extern "C" ARM int func_ov000_0215fad4(unsigned char* p) {
    if (p[0x8e47] == 0) {
        return -1;
    }
    unsigned char idx = --p[0x8e47];
    unsigned char* q = p + idx;
    return q[0x8e44];
}
