#include <globaldefs.h>

void Forward0203aa80(void* obj, int arg2);

// Main, originally ForwardField0xc0_0205ebec (USA 0x0205ebec, EUR 0x0205ebfc, JPN 0x0205fed8)
ARM void SePlayer_UnloadExtraArchiveB(void* obj) {
    Forward0203aa80(obj, *(int*)((char*)obj + 0xc0));
}
