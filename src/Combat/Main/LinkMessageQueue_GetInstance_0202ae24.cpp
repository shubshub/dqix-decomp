#include <globaldefs.h>

extern int data_02100044;

// Main, originally GetData02100044_0202ae24 (USA 0x0202ae24, EUR 0x0202ae34, JPN 0x0202a9dc)
extern "C" ARM void* LinkMessageQueue_GetInstance(void) {
    return &data_02100044;
}
