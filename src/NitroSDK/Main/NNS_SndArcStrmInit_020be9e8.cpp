#include <globaldefs.h>
#include "NitroSDK/Memory/SignedAllocator.h"
#include "NitroSDK/Filesystem/LowNitroHandle.h"
#include "NitroSDK/Mutex.h"

struct Struct_01ffd34c_3 {
    void (*callback)(void*);
    void* arg;
    Struct_01ffd34c_3* next;
};

struct Struct_020bc8d0 {
    void* prev;
    void* next;
    Struct_01ffd34c_3 unknown_8_;
    Struct_01ffd34c_3 unknown_14_;
    int format;
    unsigned int active : 1;
    unsigned int started : 1;
    unsigned int unknown_28_;
    int unknown_2c_;
    void (*callback)(int, int, void**, unsigned int, int, void*);
    void* unknown_34_;
    int unknown_38_;
    int volume;
    int unknown_40_;
    unsigned int unknown_44_;
    int channelCount;
    unsigned char unknown_4c_[16];
};

struct Struct_01ffd34c_5 {
    unsigned char unknown_0_[16];
    unsigned int unknown_10_;
    unsigned int unknown_14_;
    unsigned char format;
    unsigned char unknown_19_;
    unsigned char unknown_1a_;
    unsigned char reserved;
    unsigned short unknown_1c_;
    unsigned short timer;
    unsigned int unknown_20_;
    unsigned int unknown_24_;
    unsigned int unknown_28_;
    unsigned int unknown_2c_;
    unsigned int unknown_30_;
    unsigned int unknown_34_;
    unsigned int unknown_38_;
    unsigned int unknown_3c_;
};

struct Struct_02110a4c {
    Struct_020bc8d0 stream;
    NitroVM file;
    unsigned int unknown_a4_;
    Struct_01ffd34c_5 info;
    int unknown_e8_[4];
    struct Struct_01ffd34c_2 { short sample; unsigned char index; unsigned char reserved; } unknown_f8_[6];
    unsigned int active : 1;
    unsigned int unknown_110_1_ : 1;
    unsigned int start : 1;
    unsigned int unknown_110_3_ : 1;
    unsigned int dirty : 1;
    unsigned int unknown_110_5_ : 1;
    unsigned int unknown_110_6_ : 1;
    int unknown_114_;
    int unknown_118_;
    int unknown_11c_;
    int unknown_120_;
    unsigned char unknown_124_;
    unsigned char reserved;
    unsigned char unknown_126_[6];
    void* buffer;
    unsigned int unknown_130_;
    void* unknown_134_;
    void* unknown_138_;
    void* unknown_13c_;
    void* unknown_140_;
    int unknown_144_;
    int unknown_148_;
    void* handle;
    int priority;
    int unknown_154_;
    int unknown_158_;
    int volume;
    unsigned int unknown_160_;
    void* unknown_164_;
    void* unknown_168_;
    void* unknown_16c_;
    void* unknown_170_;
};

struct Struct_01ffd34c_4 {
    void* previous;
    void* next;
};

struct Struct_021103e0 {
    Struct_01ffd34c_4 link;
    Struct_02110a4c* player;
    int status;
    int channelCount;
    void* buffer[6];
    unsigned int unknown_2c_;
};

struct Struct_021103b0 {
    int initialized;
    void* unknown_4_;
    unsigned char* unknown_8_;
};

extern Struct_021103b0 data_021103b0;
extern SignedAllocatorList data_021103bc;
extern Mutex data_021103c8;
extern Struct_021103e0 data_021103e0[8];
extern unsigned char data_02110560[];
extern Struct_02110a4c data_02110a4c[4];
extern unsigned char data_02111020[512] __attribute__((aligned(32)));
extern "C" void func_020bc8d0(Struct_020bc8d0*);
extern "C" int func_020beaec(void*);
extern "C" void func_020bf2f8(void*, unsigned int);

// Main, originally InitAllocatorsAndVmPoolOnce_020be9e8 (USA 0x020be9e8, EUR 0x020be9f8, JPN 0x020c04b4)
extern "C" ARM void NNS_SndArcStrmInit(void* priority, void* heap)
{
    int var0;
    Struct_02110a4c* player;
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
    data_021103b0.unknown_8_ = data_02111020;
    for (var0 = 0; var0 < 4; ++var0) {
        player = &data_02110a4c[var0];
        player->active = 0;
        NitroVM_Initialize(&player->file);
        func_020bc8d0(&player->stream);
        player->unknown_148_ = var0;
        player->unknown_124_ = 0;
        player->buffer = NULL;
        player->unknown_130_ = 0;
        player->unknown_120_ = 0;
    }
    func_020beaec(heap);
    func_020bf2f8(data_02110560, (unsigned int)priority);
}
