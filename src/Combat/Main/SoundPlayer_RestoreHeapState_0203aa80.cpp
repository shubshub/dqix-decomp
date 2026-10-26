#include <globaldefs.h>

extern "C" void NNS_SndHeapLoadState(void* heap, int level);

// Main, originally Forward0203aa80 (USA 0x0203aa80, EUR 0x0203aa90, JPN 0x0203a4d8)
ARM void SoundPlayer_RestoreHeapState(void* player, int level) {
    void* heap = *(void**)player;
    if (heap == NULL) return;
    NNS_SndHeapLoadState(heap, level);
}
