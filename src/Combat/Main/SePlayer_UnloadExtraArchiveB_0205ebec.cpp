#include <globaldefs.h>

extern "C" void SoundPlayer_RestoreHeapState(void* obj, int arg1);

// Main, originally ForwardField0xc0_0205ebec (USA 0x0205ebec, EUR 0x0205ebfc, JPN 0x0205fed8)
extern "C" ARM void SePlayer_UnloadExtraArchiveB(void* obj) {
    SoundPlayer_RestoreHeapState(obj, *(int*)((char*)obj + 0xc0));
}
