#include <globaldefs.h>

// USA: func_ov031_0223e3d4
extern "C" ARM int func_ov031_0223e3d4(unsigned int c) {
    if (c >= 0x41 && c <= 0x5a) return c - 0x41;
    if (c >= 0x61 && c <= 0x7a) return c - 0x47;
    if (c >= 0x30 && c <= 0x39) return c + 4;
    if (c == 0x2e) return 0x3e;
    if (c == 0x2d) return 0x3f;
    return -1;
}
