#include <globaldefs.h>

extern char data_0210cf88;

// Main, originally ReadGlobalPair020bb910 (USA 0x020bb910, EUR 0x020bb920, JPN 0x020bd3dc)
extern "C" ARM void NNS_GfdGetFrmPlttVramState(int* dst) {
    dst[0] = *(int*)(&data_0210cf88 + 0x0);
    dst[1] = *(int*)(&data_0210cf88 + 0x4);
}
