#include <globaldefs.h>

extern "C" void SoundPlayer_PlayArchiveEntry(void* obj, int x, int y, int z);

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

// Main, originally ResetXYField0203aa08 (USA 0x0203aa08, EUR 0x0203aa18, JPN 0x0203a460)
ARM void SoundPlayer_PlayPending(void* playerRaw) {
    SoundPlayer* player = (SoundPlayer*)playerRaw;
    short archive;
    if (player->heap == NULL) return;
    archive = player->pendingArchive;
    if (archive < 0) return;
    SoundPlayer_PlayArchiveEntry(player, archive, player->pendingEntry, 0);
    player->pendingArchive = -1;
    player->pendingEntry = -1;
}
