#include <globaldefs.h>
#include "NitroSDK/Memory/SignedAllocator.h"
#include "NitroSDK/Filesystem/LowNitroHandle.h"
#include "NitroSDK/Mutex.h"

struct SleepCallback020be9e8 {
    void (*callback)(void*);
    void* arg;
    SleepCallback020be9e8* next;
};

struct SelfObj020bc8d0 {
    void* prev;
    void* next;
    SleepCallback020be9e8 preSleep;
    SleepCallback020be9e8 postSleep;
    int format;
    unsigned int active : 1;
    unsigned int started : 1;
    unsigned int channelBufferLength;
    int interval;
    void (*callback)(int, int, void**, unsigned int, int, void*);
    void* callbackArg;
    int currentBuffer;
    int volume;
    int alarmNo;
    unsigned int channelMask;
    int channelCount;
    unsigned char channels[16];
};

struct StreamInfo020be9e8 {
    unsigned char fileHeader[16];
    unsigned int blockKind;
    unsigned int blockSize;
    unsigned char format;
    unsigned char loopFlag;
    unsigned char numChannels;
    unsigned char reserved;
    unsigned short sampleRate;
    unsigned short timer;
    unsigned int loopStart;
    unsigned int loopEnd;
    unsigned int dataOffset;
    unsigned int numBlocks;
    unsigned int blockLength;
    unsigned int blockSamples;
    unsigned int lastBlockSize;
    unsigned int lastBlockSamples;
};

struct StreamPlayer020be9e8 {
    SelfObj020bc8d0 stream;
    NitroVM file;
    unsigned int fileOffset;
    StreamInfo020be9e8 info;
    int fader[4];
    struct AdpcmState { short sample; unsigned char index; unsigned char reserved; } adpcm[6];
    unsigned int active : 1;
    unsigned int play : 1;
    unsigned int start : 1;
    unsigned int fadeOut : 1;
    unsigned int dirty : 1;
    unsigned int finish : 1;
    unsigned int mono : 1;
    int finishCounter;
    int prepareFlag;
    int commandCount;
    int allocChannelCount;
    unsigned char numChannels;
    unsigned char reserved;
    unsigned char channels[6];
    void* buffer;
    unsigned int bufSize;
    void* streamCallback;
    void* streamCallbackArg;
    void* archiveCallback;
    void* archiveCallbackArg;
    int streamNo;
    int playerNo;
    void* handle;
    int priority;
    int initialVolume;
    int externalVolume;
    int volume;
    unsigned int currentSample;
    void* openStream;
    void* closeStream;
    void* readStream;
    void* cancelStream;
};

struct StreamCommandLink020be9e8 {
    void* previous;
    void* next;
};

struct LoadCommand020be9e8 {
    StreamCommandLink020be9e8 link;
    StreamPlayer020be9e8* player;
    int status;
    int channelCount;
    void* buffer[6];
    unsigned int bufferLength;
};

struct StreamState020be9e8 {
    int initialized;
    void* prepareThread;
    unsigned char* decodeBuffer;
};

extern StreamState020be9e8 data_021103b0;
extern SignedAllocatorList data_021103bc;
extern Mutex data_021103c8;
extern LoadCommand020be9e8 data_021103e0[8];
extern unsigned char data_02110560[];
extern StreamPlayer020be9e8 data_02110a4c[4];
extern unsigned char data_02111020[512] __attribute__((aligned(32)));
void InitAllocatorObj020bc8d0(SelfObj020bc8d0*);
extern "C" int func_020beaec(void*);
extern "C" void func_020bf2f8(void*, unsigned int);

// Main, originally InitAllocatorsAndVmPoolOnce_020be9e8 (USA 0x020be9e8, EUR 0x020be9f8, JPN 0x020c04b4)
ARM void NNS_SndArcStrmInit(void* priority, void* heap)
{
    int playerNo;
    StreamPlayer020be9e8* player;
    int i;
    if (data_021103b0.initialized) {
        func_020beaec(heap);
        return;
    }
    data_021103b0.initialized = 1;
    data_021103bc.Initialize(0);
    for (i = 0; i < 8; i++)
        data_021103bc.InsertAtEnd((SignedAllocatorHeader*)&data_021103e0[i].link);
    ZeroInitializeMutex(&data_021103c8);
    data_021103b0.decodeBuffer = data_02111020;
    for (playerNo = 0; playerNo < 4; ++playerNo) {
        player = &data_02110a4c[playerNo];
        player->active = 0;
        NitroVM_Initialize(&player->file);
        InitAllocatorObj020bc8d0(&player->stream);
        player->playerNo = playerNo;
        player->numChannels = 0;
        player->buffer = NULL;
        player->bufSize = 0;
        player->allocChannelCount = 0;
    }
    func_020beaec(heap);
    func_020bf2f8(data_02110560, (unsigned int)priority);
}
