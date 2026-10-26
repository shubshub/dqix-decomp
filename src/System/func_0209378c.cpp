#include <globaldefs.h>

#include "NitroSDK/Graphics.h"

// USA: func_0209378c
extern "C" ARM int func_0209378c(int engine) {
    unsigned int var0;
    if (engine == 0)
        var0 = DISPCNT & 0x00300010;
    else
        var0 = DISPCNTSUB & 0x00300010;

    int shift = 0;
    switch (var0) {
        case 0x00000010: shift = 5; break;
        case 0x00100010: shift = 6; break;
        case 0x00200010: shift = 7; break;
    }
    return shift;
}
