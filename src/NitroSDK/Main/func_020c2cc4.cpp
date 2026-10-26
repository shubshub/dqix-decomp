#include <globaldefs.h>

// USA: func_020c2cc4
extern "C" ARM int fix32_GetSqrtResult(void) {
    volatile unsigned short* cnt = (volatile unsigned short*)0x40002b0;
    volatile unsigned int* result = (volatile unsigned int*)0x40002b4;
    while (*cnt & 0x8000) ;
    return (*result + 0x200) >> 10;
}
