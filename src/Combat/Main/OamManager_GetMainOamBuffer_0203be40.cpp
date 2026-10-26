#include <globaldefs.h>

extern int data_021052b4;

// Main, originally func_0203be40 (USA 0x0203be40, EUR 0x0203be50, JPN 0x0203b898)
extern "C" ARM void* OamManager_GetMainOamBuffer(void) {
    return &data_021052b4;
}
