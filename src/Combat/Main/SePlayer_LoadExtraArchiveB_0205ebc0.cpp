#include <globaldefs.h>
#include "Sound/SePlayer.h"

void SoundPlayer_RestoreHeapState(void* obj, int arg2);
int SoundPlayer_LoadGroup(void*, int);

// Main, originally SetForwardAndStore0205ebc0 (USA 0x0205ebc0, EUR 0x0205ebd0, JPN 0x0205feac)
ARM void SePlayer_LoadExtraArchiveB(void* obj, int arg1, int arg2) {
    SoundPlayer_RestoreHeapState(obj, *(int*)((char*)obj + 0xc0));
    SoundPlayer_LoadGroup(obj, arg1);
    ((SePlayer*)obj)->extraArchive = (short)arg2;
}
