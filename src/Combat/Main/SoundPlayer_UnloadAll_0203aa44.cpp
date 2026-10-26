#include <globaldefs.h>

extern "C" void NNS_SndHeapLoadState(void* a, int b);

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

// Main, originally CallField0xa00203aa44 (USA 0x0203aa44, EUR 0x0203aa54, JPN 0x0203a49c)
ARM void SoundPlayer_UnloadAll(void* playerRaw) {
    SoundPlayer* player = (SoundPlayer*)playerRaw;
    void* heap = player->heap;
    if (heap == NULL) return;
    NNS_SndHeapLoadState(heap, player->baseHeapLevel);
}
