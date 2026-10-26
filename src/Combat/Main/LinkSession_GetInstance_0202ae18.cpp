#include <globaldefs.h>

extern int data_020fefec;

// Main, originally func_0202ae18 (USA 0x0202ae18, EUR 0x0202ae28, JPN 0x0202a9d0)
extern "C" ARM void* LinkSession_GetInstance(void) {
    return &data_020fefec;
}
