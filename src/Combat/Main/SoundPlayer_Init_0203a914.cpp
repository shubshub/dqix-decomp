#include <globaldefs.h>
void NNS_SndStrmHandleInit(int*);
void NNS_SndHandleInit(int*);

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

// Main, originally InitObjectFields0203a914 (USA 0x0203a914, EUR 0x0203a924, JPN 0x0203a36c)
ARM void SoundPlayer_Init(void* playerRaw) {
    SoundPlayer* player = (SoundPlayer*)playerRaw;
    player->heap = 0;
    NNS_SndHandleInit(&player->seqHandle);
    NNS_SndStrmHandleInit(&player->streamHandle);
    player->streamId = -1;
    player->streamResumeMs = 0;
    player->pendingArchive = -1;
    player->pendingEntry = -1;
}
