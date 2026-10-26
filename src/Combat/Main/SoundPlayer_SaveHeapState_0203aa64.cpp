#include <globaldefs.h>

struct Obj020bdac0;
extern "C" int NNS_SndHeapSaveState(struct Obj020bdac0*);

// Main, originally GetFromField00203aa64 (USA 0x0203aa64, EUR 0x0203aa74, JPN 0x0203a4bc)
extern "C" ARM int SoundPlayer_SaveHeapState(void* player) {
    void* heap = *(void**)player;
    if (heap == NULL) return 0;
    return NNS_SndHeapSaveState((struct Obj020bdac0*)heap);
}
