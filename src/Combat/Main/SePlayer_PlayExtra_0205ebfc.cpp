#include <globaldefs.h>
#include "Sound/SePlayer.h"


extern "C" void SePlayer_PlayArchiveEntry(void*, int, int, int);

// Main, originally DispatchIfField0xc4NonNeg_0205ebfc (USA 0x0205ebfc, EUR 0x0205ec0c, JPN 0x0205fee8)
ARM void SePlayer_PlayExtra(void* obj, int a, int b) {
    short s = ((SePlayer*)obj)->extraArchive;
    if (s >= 0) {
        SePlayer_PlayArchiveEntry(obj, s, a, b);
    }
}
