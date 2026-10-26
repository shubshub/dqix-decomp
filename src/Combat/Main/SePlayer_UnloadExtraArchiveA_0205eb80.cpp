#include <globaldefs.h>

void SoundPlayer_RestoreHeapState(void* obj, int arg2);

// Main, originally ForwardField0xc0_0205eb80 (USA 0x0205eb80, EUR 0x0205eb90, JPN 0x0205fe6c)
ARM void SePlayer_UnloadExtraArchiveA(void* obj) {
    SoundPlayer_RestoreHeapState(obj, *(int*)((char*)obj + 0xc0));
}
