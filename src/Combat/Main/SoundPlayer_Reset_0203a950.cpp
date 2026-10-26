#include <globaldefs.h>

struct Obj020bd984;
extern "C" void NNS_SndHeapDestroy(struct Obj020bd984*);
extern "C" void SoundPlayer_Init(void*);

// Main, originally FreeAndReinit0203a950 (USA 0x0203a950, EUR 0x0203a960, JPN 0x0203a3a8)
extern "C" ARM void SoundPlayer_Reset(void* player) {
    void* heap = *(void**)player;
    if (heap != NULL) {
        NNS_SndHeapDestroy((struct Obj020bd984*)heap);
    }
    SoundPlayer_Init(player);
}
