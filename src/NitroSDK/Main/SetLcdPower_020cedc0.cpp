#include <globaldefs.h>

extern "C" int func_020ceba8(int a, int b, int c, int d);

// Main, originally DispatchIfEquals1_020cedc0 (USA 0x020cedc0, EUR 0x020cedd0, JPN 0x020d088c)
extern "C" ARM int SetLcdPower(int a) {
    if (a != 1) a = 0;
    return func_020ceba8(a, 0, 0, 1);
}
