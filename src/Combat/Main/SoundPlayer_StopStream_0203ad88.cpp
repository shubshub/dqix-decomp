#include <globaldefs.h>

extern "C" void* NNS_SndArcSetCurrent(void*);
extern "C" int NNS_SndArcStrmGetCurrentPlayingPos(void* obj);
extern "C" void NNS_SndArcStrmStop(void* volatile* slot, int arg);

// The sound player g_sePlayer and g_bgmPlayer both start with (0xb0 bytes): a NitroSystem sound heap, the sound
// archive opened into it (SoundPlayer_OpenArchive), a sequence handle and a stream handle.
struct SoundPlayer {
    void* heap;
    char archive[0x98 - 0x4];
    int seqHandle;
    int streamHandle;
    int baseHeapLevel;          // the heap level saved once the archive was open (SoundPlayer_OpenArchive)
    short streamId;             // the stream func_0203ad14 started, -1 for none
    int streamResumeMs;         // where func_0203ae4c paused it
    short pendingArchive;       // the entry SoundPlayer_PlayArchiveEntry deferred, -1 for none
    short pendingEntry;
};

// Main, originally ScaleAndNotify0203ad88 (USA 0x0203ad88, EUR 0x0203ad98, JPN 0x0203a7e0)
extern "C" ARM int SoundPlayer_StopStream(void* playerRaw, void* streamHandle, int fadeFrames) {
    SoundPlayer* player = (SoundPlayer*)playerRaw;
    int positionMs;
    if (player->heap == NULL) return 0;
    NNS_SndArcSetCurrent(player->archive);
    if (streamHandle != NULL) {
        positionMs = NNS_SndArcStrmGetCurrentPlayingPos(streamHandle);
        NNS_SndArcStrmStop((void* volatile*)streamHandle, fadeFrames);
    } else {
        positionMs = NNS_SndArcStrmGetCurrentPlayingPos(&player->streamHandle);
        NNS_SndArcStrmStop((void* volatile*)&player->streamHandle, fadeFrames);
    }
    player->streamId = -1;
    return positionMs;
}
