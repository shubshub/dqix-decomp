#include <globaldefs.h>

extern void* data_02110370;

// Main, originally SetGlobalContext02110370_020bd42c (USA 0x020bd42c, EUR 0x020bd43c, JPN 0x020beef8)
ARM void* NNS_SndArcSetCurrent(void* value) {
    void* previous = data_02110370;
    data_02110370 = value;
    return previous;
}
