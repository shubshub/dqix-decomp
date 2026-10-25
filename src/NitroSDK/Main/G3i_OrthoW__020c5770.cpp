#include <globaldefs.h>

extern "C" void Mat4x4_WriteProjectionUnknown(int a0, int a1, int a2, int a3, int b0, int b1, int b2, void* outBuf);
void GxLoadMatrix4x4_020c516c(const void* mtx);

// Main, originally ComputeAndLoadMatrix020c5770 (USA 0x020c5770, EUR 0x020c5780, JPN 0x020c723c)
ARM void G3i_OrthoW_(int a0, int a1, int a2, int a3, int b0, int b1, int b2, int gate, void* outBuf) {
    int localBuf[16];
    void* buf = outBuf ? outBuf : localBuf;
    Mat4x4_WriteProjectionUnknown(a0, a1, a2, a3, b0, b1, b2, buf);
    if (gate == 0) return;
    *(volatile unsigned int*)0x4000440 = 0;
    GxLoadMatrix4x4_020c516c(buf);
}
