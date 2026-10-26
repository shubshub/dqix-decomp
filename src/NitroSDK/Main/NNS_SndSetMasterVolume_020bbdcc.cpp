#include <globaldefs.h>

int EnqueueEvent0x17_020d20e4(int);

// Main, originally Forward020bbdcc (USA 0x020bbdcc, EUR 0x020bbddc, JPN 0x020bd898)
ARM int NNS_SndSetMasterVolume(int a) {
    return EnqueueEvent0x17_020d20e4(a);
}
