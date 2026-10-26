#include <globaldefs.h>

void* NNS_SndArcSetCurrent(void* value);
int NNS_SndArcStrmGetCurrentPlayingPos(void* obj);

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

// Main, originally IsScaledFieldPositive0203adfc (USA 0x0203adfc, EUR 0x0203ae0c, JPN 0x0203a854)
ARM int SoundPlayer_IsStreamPlaying(void* playerRaw, void* streamHandle) {
    SoundPlayer* player = (SoundPlayer*)playerRaw;
    int positionMs;
    if ((int)player->heap == 0) return 0;
    NNS_SndArcSetCurrent(player->archive);
    if (streamHandle != NULL) {
        positionMs = NNS_SndArcStrmGetCurrentPlayingPos(streamHandle);
    } else {
        positionMs = NNS_SndArcStrmGetCurrentPlayingPos(&player->streamHandle);
    }
    return positionMs > 0 ? 1 : 0;
}
