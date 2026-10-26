#include <globaldefs.h>

// USA: func_020e29ec
extern "C" ARM void func_020e29ec(int x1, int arg1, int x2, int y2) {
    *(volatile unsigned short*)0x4001040 = ((x1 << 8) & 0xff00) | (x2 & 0xff);
    *(volatile unsigned short*)0x4001044 = ((arg1 << 8) & 0xff00) | (y2 & 0xff);
}
