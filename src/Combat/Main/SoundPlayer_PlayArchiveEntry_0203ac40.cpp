#include <globaldefs.h>

extern "C" int func_020d84ec(void);
extern "C" void* NNS_SndArcSetCurrent(void* value);
extern "C" int NNS_SndArcPlayerStartSeqArc(void* obj, int id, int index);

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

// Main, originally func_0203ac40 (USA 0x0203ac40, EUR 0x0203ac50, JPN 0x0203a698)
extern "C" ARM int SoundPlayer_PlayArchiveEntry(void* playerRaw, int archive, int entry, void* handle) {
    SoundPlayer* player = (SoundPlayer*)playerRaw;
    if (func_020d84ec()) {
        player->pendingArchive = archive;
        player->pendingEntry = entry;
        return 1;
    }
    int result = 0;
    if ((int)player->heap != 0) {
        NNS_SndArcSetCurrent(player->archive);
        if (handle != 0) {
            if (NNS_SndArcPlayerStartSeqArc(handle, archive, entry) != 0) result = 1;
        } else {
            if (NNS_SndArcPlayerStartSeqArc(&player->seqHandle, archive, entry) != 0) result = 1;
        }
    }
    return result;
}
