#include <globaldefs.h>

int GetPositionVectorMtxStackLevel_020c5650(int* out);
int GetProjectionMtxStackLevel_020c5680(int* out);

// Main, originally func_020c5414 (USA 0x020c5414, EUR 0x020c5424, JPN 0x020c6ee0)
extern "C" ARM void G3X_ResetMtxStack(void) {
    int posLevel;
    int projLevel;
    *(volatile unsigned int*)0x4000600 |= 0x8000;
    while (GetPositionVectorMtxStackLevel_020c5650(&posLevel) != 0) {}
    while (GetProjectionMtxStackLevel_020c5680(&projLevel) != 0) {}
    *(volatile unsigned int*)0x4000440 = 3;
    *(volatile unsigned int*)0x4000454 = 0;
    *(volatile unsigned int*)0x4000440 = 0;
    if (projLevel != 0) *(volatile unsigned int*)0x4000448 = projLevel;
    *(volatile unsigned int*)0x4000440 = 2;
    *(volatile unsigned int*)0x4000448 = posLevel;
    *(volatile unsigned int*)0x4000454 = 0;
}
