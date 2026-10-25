#include <globaldefs.h>

extern char data_0210cf88;

// Main, originally WriteGlobalPair020bb92c (USA 0x020bb92c, EUR 0x020bb93c, JPN 0x020bd3f8)
ARM void NNS_GfdSetFrmPlttVramState(int* src) {
    *(int*)(&data_0210cf88 + 0x0) = src[0];
    *(int*)(&data_0210cf88 + 0x4) = src[1];
}
