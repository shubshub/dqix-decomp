#include <globaldefs.h>

extern int data_021056b4;

// Main, originally func_0203be4c (USA 0x0203be4c, EUR 0x0203be5c, JPN 0x0203b8a4)
extern "C" ARM void* OamManager_GetSubOamBuffer(void) {
    return &data_021056b4;
}
