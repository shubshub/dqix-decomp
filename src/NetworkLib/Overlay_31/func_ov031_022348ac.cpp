#include <globaldefs.h>

// USA: func_ov031_022348ac
extern "C" ARM int func_ov031_022348ac(void) {
    int v = *(unsigned short*)0x27fffa8 & 0x8000;
    return (v >> 15) ? 1 : 0;
}
