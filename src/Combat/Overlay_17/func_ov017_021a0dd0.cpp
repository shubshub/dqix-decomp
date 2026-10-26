#include <globaldefs.h>
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "Memory/SafeAllocator.h"

extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern "C" void NNS_GfdSetFrmTexVramState(int* out);
extern "C" void NNS_GfdSetFrmPlttVramState(int* src);
extern "C" int NNS_GfdAllocFrmTexVram(unsigned int size, int a, int b);
extern "C" void VramState_Reserve(void* p, int a, int b);

extern AllocatorUnion g_mainAllocator;

struct Struct_ov017_021d6788 { int index; int pad4; };
struct Struct_ov017_021d678c { int size; int pad4; };
extern Struct_ov017_021d6788 data_ov017_021d6788[];
extern Struct_ov017_021d678c data_ov017_021d678c[];

struct Struct_ov017_021d66b0 { int v; int pad4; int pad8; };
extern Struct_ov017_021d66b0 data_ov017_021d66b0[];
extern Struct_ov017_021d66b0 data_ov017_021d66b8[];
extern Struct_ov017_021d66b0 data_ov017_021d66b4[];
extern Struct_ov017_021d66b0 data_ov017_021d6728[];
extern Struct_ov017_021d66b0 data_ov017_021d6730[];
extern Struct_ov017_021d66b0 data_ov017_021d672c[];

#if defined(jpn)
enum { PairBufferOffset = 0x2868, GlobalPairOffset = 0x28c0, SecondPairBufferOffset = 0x2898, FirstArenaOffset = 0xe4c, SecondArenaOffset = 0xebc, EntryBaseOffset = 0x27c };
#else
enum { PairBufferOffset = 0x2a78, GlobalPairOffset = 0x2ad0, SecondPairBufferOffset = 0x2aa8, FirstArenaOffset = 0xe9c, SecondArenaOffset = 0xf0c, EntryBaseOffset = 0x2cc };
#endif

// USA: func_ov017_021a0dd0
extern "C" ARM void func_ov017_021a0dd0(char* self) {
    int i;
    int size;
    for (i = 0; (size = data_ov017_021d678c[i].size) != 0; i++) {
        void* p = AllocatorUnion_AllocateRounded(&g_mainAllocator, size);
        int idx = data_ov017_021d6788[i].index;
        SafeAllocator* alloc = (SafeAllocator*)(self + 0x38 + idx * 0x14);
        alloc->CreateTypeA(p, size);
    }

    NNS_GfdSetFrmTexVramState((int*)(self + PairBufferOffset));
    NNS_GfdSetFrmPlttVramState((int*)(self + GlobalPairOffset));
    NNS_GfdAllocFrmTexVram(0x20000, 0, 0);

    int cond;
    for (i = 0; (cond = data_ov017_021d66b4[i].v) != 0; i++) {
        int a = data_ov017_021d66b0[i].v;
        int b = data_ov017_021d66b8[i].v;
        VramState_Reserve((self + EntryBaseOffset) + a * 0x70, cond, b);
    }

    NNS_GfdSetFrmTexVramState((int*)(self + SecondPairBufferOffset));

    for (i = 0; (cond = data_ov017_021d672c[i].v) != 0; i++) {
        int a = data_ov017_021d6728[i].v;
        int b = data_ov017_021d6730[i].v;
        VramState_Reserve((self + EntryBaseOffset) + a * 0x70, cond, b);
    }

    VramState_Reserve(self + FirstArenaOffset, 0x8000, 0x400);
    VramState_Reserve(self + SecondArenaOffset, 0x4000, 0x400);
}
