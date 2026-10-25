#include <globaldefs.h>
#include "Sound/SePlayer.h"

void Forward0203aa80(void* obj, int arg2);
int DispatchIndexedCommand0203aa98(void*, int);

// Main, originally SetForwardAndStore0205eb54 (USA 0x0205eb54, EUR 0x0205eb64, JPN 0x0205fe40)
ARM void SePlayer_LoadExtraArchiveA(void* obj, int arg1, int arg2) {
    Forward0203aa80(obj, *(int*)((char*)obj + 0xc0));
    DispatchIndexedCommand0203aa98(obj, arg1);
    ((SePlayer*)obj)->extraArchive = (short)arg2;
}
