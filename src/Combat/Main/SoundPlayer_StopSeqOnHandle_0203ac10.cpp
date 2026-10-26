#include <globaldefs.h>

void* NNS_SndArcSetCurrent(void*);
void* NNS_SndPlayerStopSeq(void* obj, int arg2);

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

// Main, originally SetContextAndDispatch0203ac10 (USA 0x0203ac10, EUR 0x0203ac20, JPN 0x0203a668)
ARM void SoundPlayer_StopSeqOnHandle(void* playerRaw, void* handle, int fadeFrames) {
    SoundPlayer* player = (SoundPlayer*)playerRaw;
    if (player->heap == NULL) return;
    NNS_SndArcSetCurrent(player->archive);
    NNS_SndPlayerStopSeq(handle, fadeFrames);
}
