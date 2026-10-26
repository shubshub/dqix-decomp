#include <globaldefs.h>

void* NNS_SndArcSetCurrent(void* value);
int NNS_SndArcPlayerStartSeq(void* a, void* key);

// The sound player g_sePlayer and g_bgmPlayer both start with (0xb0 bytes): a NitroSystem sound heap, the sound
// archive opened into it (SoundPlayer_OpenArchive), a sequence handle and a stream handle.
struct Obj0203aba8 {
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

// Main, originally TryDispatchOrFallback0203aba8 (USA 0x0203aba8, EUR 0x0203abb8, JPN 0x0203a600)
ARM int SoundPlayer_StartSeq(struct Obj0203aba8* player, void* seq, void* handle) {
    int started;
    if (player->heap == 0) {
        return 0;
    }
    NNS_SndArcSetCurrent(player->archive);
    started = 1;
    if (handle != 0) {
        if (NNS_SndArcPlayerStartSeq(handle, seq) == 0) {
            started = 0;
        }
    } else {
        if (NNS_SndArcPlayerStartSeq(&player->seqHandle, seq) == 0) {
            started = 0;
        }
    }
    return started != 0;
}
