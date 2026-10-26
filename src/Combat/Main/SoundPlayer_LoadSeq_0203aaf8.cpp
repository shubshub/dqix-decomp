#include <globaldefs.h>

struct Obj020bdac0;
extern "C" int NNS_SndHeapSaveState(struct Obj020bdac0* obj);
extern "C" void* NNS_SndArcSetCurrent(void*);
extern "C" int NNS_SndArcLoadSeqEx(void*, int, int);
extern "C" int NNS_SndArcLoadSeq(void*, int);

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

// NitroSystem's NNS_SND_ARC_LOAD_* bits: the sequence, its bank, the bank's wave archives.
enum { kSndArcLoad_SeqAndBank = 1 | 2, kSndArcLoad_Wave = 4 };

// Main, originally TryAllocateOrAppend0203aaf8 (USA 0x0203aaf8, EUR 0x0203ab08, JPN 0x0203a550)
extern "C" ARM int SoundPlayer_LoadSeq(void* playerRaw, void* seq, int* levelBeforeWaves) {
    SoundPlayer* player = (SoundPlayer*)playerRaw;
    if (player->heap == NULL) return 0;
    NNS_SndArcSetCurrent(player->archive);
    if (levelBeforeWaves != NULL) {
        NNS_SndArcLoadSeqEx(seq, kSndArcLoad_SeqAndBank, (int)player->heap);
        *levelBeforeWaves = NNS_SndHeapSaveState((struct Obj020bdac0*)player->heap);
        NNS_SndArcLoadSeqEx(seq, kSndArcLoad_Wave, (int)player->heap);
    } else {
        NNS_SndArcLoadSeq(seq, (int)player->heap);
    }
    return 1;
}
