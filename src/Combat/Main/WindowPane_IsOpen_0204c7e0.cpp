#include <globaldefs.h>

// Main, originally CheckField0x9cSetWhenField0xd4Present_0204c7e0 (USA 0x0204c7e0, EUR 0x0204c7f0, JPN 0x0204d5fc)
extern "C" ARM int WindowPane_IsOpen(unsigned char* obj) {
    if (*(int*)(obj + 0xd4) == 0) return 0;
    return *(int*)(obj + 0x9c) != 0;
}
