#include <globaldefs.h>

extern int data_02108fe4;

// Main, originally func_0208e0a8 (USA 0x0208e0a8, EUR 0x0208e0b8, JPN 0x0208e9b8)
extern "C" ARM void* LootPointList_GetInstance(void) {
    return &data_02108fe4;
}
