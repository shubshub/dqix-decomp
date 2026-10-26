#include <globaldefs.h>

// USA: func_ov031_02236760
extern "C" ARM int func_ov031_02236760(unsigned int c) {
    if (c <= '9') return c - '0';
    if (c <= 'F') return c - '7';
    return c - 'W';
}
