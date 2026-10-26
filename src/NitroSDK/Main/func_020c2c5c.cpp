#include <globaldefs.h>

// USA: func_020c2c5c
extern "C" ARM int fix32_GetDivisionResult(void) {
    volatile unsigned short* cnt = (volatile unsigned short*)0x4000280;
    long long v;
    while (*cnt & 0x8000) ;
    v = *(long long*)0x40002a0;
    return (int)((v + 0x80000) >> 20);
}
