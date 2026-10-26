#include <globaldefs.h>
#include "Sound/SePlayer.h"

void SoundPlayer_RestoreHeapState(void* obj, int arg2);
int SoundPlayer_LoadGroup(void*, int);

// Main, originally SetForwardAndStore0205eb54 (USA 0x0205eb54, EUR 0x0205eb64, JPN 0x0205fe40)
ARM void SePlayer_LoadExtraArchiveA(void* obj, int arg1, int arg2) {
    SoundPlayer_RestoreHeapState(obj, *(int*)((char*)obj + 0xc0));
    SoundPlayer_LoadGroup(obj, arg1);
    ((SePlayer*)obj)->extraArchive = (short)arg2;
}
