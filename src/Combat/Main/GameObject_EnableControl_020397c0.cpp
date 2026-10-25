#include <globaldefs.h>

// Main, originally SetByteField0x253_020397c0 (USA 0x020397c0, EUR 0x020397d0, JPN 0x02039218)
ARM void GameObject_EnableControl(void* obj) {
#if defined(jpn)
    *(unsigned char*)((char*)obj + 0x247) = 1;
#else
    *(unsigned char*)((char*)obj + 0x253) = 1;
#endif
}
