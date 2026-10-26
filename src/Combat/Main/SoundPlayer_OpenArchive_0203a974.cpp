#include <globaldefs.h>

struct Obj020bd984;
void NNS_SndHeapDestroy(struct Obj020bd984*);
void SoundPlayer_Init(void*);
extern void* NNS_SndHeapCreate(void* start, unsigned int size);
struct Holder020bd110;
int NNS_SndArcInit(struct Holder020bd110* obj, const char* path, int arg2, int arg3);
extern "C" int NNS_SndArcPlayerSetup(void* obj);
void NNS_SndArcStrmInit(void* arg0, void* arg1);
struct Obj020bdac0;
int NNS_SndHeapSaveState(struct Obj020bdac0*);

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

// Main, originally func_0203a974 (USA 0x0203a974, EUR 0x0203a984, JPN 0x0203a3cc)
extern "C" ARM void SoundPlayer_OpenArchive(SoundPlayer* player, const char* path, void* heapStart, unsigned int heapSize, void* withStreams) {
    void* oldHeap;
    if (heapSize <= 1) {
        return;
    }
    oldHeap = player->heap;
    if (oldHeap == 0) {
        goto skip_both;
    }
    if (oldHeap == 0) {
        goto skip_destroy;
    }
    NNS_SndHeapDestroy((struct Obj020bd984*)oldHeap);
skip_destroy:
    SoundPlayer_Init(player);
skip_both:
    player->heap = NNS_SndHeapCreate(heapStart, heapSize);
    NNS_SndArcInit((struct Holder020bd110*)player->archive, path, (int)player->heap, 0);
    if (NNS_SndArcPlayerSetup(player->heap) == 0) {
        return;
    }
    if (withStreams != 0) {
        NNS_SndArcStrmInit(0, player->heap);
    }
    player->baseHeapLevel = NNS_SndHeapSaveState((struct Obj020bdac0*)player->heap);
}
