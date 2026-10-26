#include <globaldefs.h>

// USA: func_ov031_0222aa9c
extern "C" ARM int func_ov031_0222aa9c(void) {
    int v = *(unsigned short*)0x27fffa8 & 0x8000;
    return (v >> 15) ? 1 : 0;
}
