#include <globaldefs.h>

void* NNS_SndArcSetCurrent(void* value);
int NNS_SndArcLoadGroup(void* obj, int arg);

// The sound player g_sePlayer and g_bgmPlayer both start with (0xb0 bytes): a NitroSystem sound heap, the sound
// archive opened into it (SoundPlayer_OpenArchive), a sequence handle and a stream handle.
struct SoundPlayer {
    void* heap;
    char archive[0x98 - 0x4];
    int seqHandle;
    int streamHandle;
    int baseHeapLevel;          // the heap level saved once the archive was open (SoundPlayer_OpenArchive)
    short streamId;             // the stream SetKeyAndApplyRecord0203ad14 started, -1 for none
    int streamResumeMs;         // where UpdateScaleOrApplyRecord0203ae4c paused it
    short pendingArchive;       // the entry SoundPlayer_PlayArchiveEntry deferred, -1 for none
    short pendingEntry;
};

// Main, originally DispatchIndexedCommand0203aa98 (USA 0x0203aa98, EUR 0x0203aaa8, JPN 0x0203a4f0)
ARM int SoundPlayer_LoadGroup(void* playerRaw, int group) {
    SoundPlayer* player = (SoundPlayer*)playerRaw;
    if ((int)player->heap == 0) return 0;
    if (group >= 0xffff || group < 0) return 0;
    NNS_SndArcSetCurrent(player->archive);
    return NNS_SndArcLoadGroup((void*)group, (int)player->heap) != 0 ? 1 : 0;
}
