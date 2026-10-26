#include <globaldefs.h>

extern int data_02105ab4;

// Main, originally func_0203bd08 (USA 0x0203bd08, EUR 0x0203bd18, JPN 0x0203b760)
extern "C" ARM void* OamManager_GetInstance(void) {
    return &data_02105ab4;
}
