#include <globaldefs.h>
#include "Sound/SePlayer.h"

void Forward0203aa80(void* obj, int arg2);
int DispatchIndexedCommand0203aa98(void*, int);

// Main, originally SetForwardAndStore0205ebc0 (USA 0x0205ebc0, EUR 0x0205ebd0, JPN 0x0205feac)
ARM void SePlayer_LoadExtraArchiveB(void* obj, int arg1, int arg2) {
    Forward0203aa80(obj, *(int*)((char*)obj + 0xc0));
    DispatchIndexedCommand0203aa98(obj, arg1);
    ((SePlayer*)obj)->extraArchive = (short)arg2;
}
