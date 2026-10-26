#include <globaldefs.h>

// Main, originally IsField0x9cEqual3_0204c7cc (USA 0x0204c7cc, EUR 0x0204c7dc, JPN 0x0204d5e8)
extern "C" ARM int WindowPane_IsReady(unsigned char* obj) {
    return *(int*)(obj + 0x9c) == 3;
}
