#include <globaldefs.h>

// USA: func_ov031_0222ae94
extern "C" ARM int func_ov031_0222ae94(void) {
    int v = *(unsigned short*)0x27fffa8 & 0x8000;
    return (v >> 15) ? 1 : 0;
}
