#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"

extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern "C" ARM void NNS_GfdSetFrmTexVramState(int* out);
extern "C" ARM void NNS_GfdSetFrmPlttVramState(int* src);
extern "C" void VramState_Reserve(void* p, int a, int b);

extern AllocatorUnion g_mainAllocator;

struct Struct_ov017_021d6830 { int v; int pad; };
extern struct Struct_ov017_021d6830 data_ov017_021d6830[];
extern struct Struct_ov017_021d6830 data_ov017_021d6834[];

struct Struct_ov017_021d66f8 { int v; int pad0; int pad1; };
extern struct Struct_ov017_021d66f8 data_ov017_021d66f8[];
extern struct Struct_ov017_021d66f8 data_ov017_021d66fc[];
extern struct Struct_ov017_021d66f8 data_ov017_021d6700[];

struct Struct_ov017_021d6740 { int v; int pad0; int pad1; };
extern struct Struct_ov017_021d6740 data_ov017_021d6740[];
extern struct Struct_ov017_021d6740 data_ov017_021d6744[];
extern struct Struct_ov017_021d6740 data_ov017_021d6748[];

#if defined(jpn)
enum { PairBufferOffset = 0x2868, GlobalPairOffset = 0x28c0, SecondPairBufferOffset = 0x2898, FirstArenaOffset = 0xe4c, SecondArenaOffset = 0xebc, EntryBaseOffset = 0x27c };
#else
enum { PairBufferOffset = 0x2a78, GlobalPairOffset = 0x2ad0, SecondPairBufferOffset = 0x2aa8, FirstArenaOffset = 0xe9c, SecondArenaOffset = 0xf0c, EntryBaseOffset = 0x2cc };
#endif

// USA: func_ov017_021a0c0c
extern "C" ARM void func_ov017_021a0c0c(char* self) {
    int i;

    int size;
    for (i = 0; (size = data_ov017_021d6834[i].v) != 0; i++) {
        void* p = AllocatorUnion_AllocateRounded(&g_mainAllocator, size);
        SafeAllocator* alloc = (SafeAllocator*)(self + 0x38 + data_ov017_021d6830[i].v * 0x14);
        alloc->CreateTypeA(p, size);
    }

    NNS_GfdSetFrmTexVramState((int*)(self + PairBufferOffset));
    NNS_GfdSetFrmPlttVramState((int*)(self + GlobalPairOffset));

    for (i = 0; data_ov017_021d66fc[i].v != 0; i++) {
        VramState_Reserve(self + EntryBaseOffset + data_ov017_021d66f8[i].v * 0x70, data_ov017_021d66fc[i].v, data_ov017_021d6700[i].v);
    }

    NNS_GfdSetFrmTexVramState((int*)(self + SecondPairBufferOffset));

    for (i = 0; data_ov017_021d6744[i].v != 0; i++) {
        VramState_Reserve(self + EntryBaseOffset + data_ov017_021d6740[i].v * 0x70, data_ov017_021d6744[i].v, data_ov017_021d6748[i].v);
    }

    VramState_Reserve(self + FirstArenaOffset, 0x8000, 0x400);
    VramState_Reserve(self + SecondArenaOffset, 0x4000, 0x400);
}
