#include <globaldefs.h>

#if defined(jpn)
#define func_020ca3b8 func_020cbe84
#endif

extern "C" int func_020ca3b8(int, int, int);

// Main, originally CallWithAddr4000330_020c555c (USA 0x020c555c, EUR 0x020c556c, JPN 0x020c7028)
extern "C" ARM int G3X_SetEdgeColorTable(int a) {
    return func_020ca3b8(a, 0x4000330, 0x10);
}
