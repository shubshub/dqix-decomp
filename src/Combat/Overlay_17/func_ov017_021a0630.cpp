#if defined(jpn)
enum { RegionOffset278 = 0x68, RegionOffsetad0 = 0x8c0, RegionOffset2cc = 0x27c, RegionOffset2a8 = 0x98, RegionOffset29c = 0x24c, RegionOffset30c = 0x2bc };
#else
enum { RegionOffset278 = 0x278, RegionOffsetad0 = 0xad0, RegionOffset2cc = 0x2cc, RegionOffset2a8 = 0x2a8, RegionOffset29c = 0x29c, RegionOffset30c = 0x30c };
#endif

#include <globaldefs.h>
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "Memory/SafeAllocator.h"

extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern "C" void NNS_GfdSetFrmTexVramState(int* out);
extern "C" void NNS_GfdSetFrmPlttVramState(int* src);
extern "C" void VramState_Reserve(void* p, int a, int b);

extern AllocatorUnion g_mainAllocator;

struct Struct_ov017_021d66c8 { int index; int pad4; };
struct Struct_ov017_021d66cc { int size; int pad4; };
extern Struct_ov017_021d66c8 data_ov017_021d66c8[];
extern Struct_ov017_021d66cc data_ov017_021d66cc[];

struct Struct_ov017_021d6800 { int v; int pad4; int pad8; };
extern Struct_ov017_021d6800 data_ov017_021d6818[];
extern Struct_ov017_021d6800 data_ov017_021d6820[];
extern Struct_ov017_021d6800 data_ov017_021d681c[];
extern Struct_ov017_021d6800 data_ov017_021d6800[];
extern Struct_ov017_021d6800 data_ov017_021d6808[];
extern Struct_ov017_021d6800 data_ov017_021d6804[];

// USA: func_ov017_021a0630
extern "C" ARM void func_ov017_021a0630(char* self) {
    int i;
    int size;
    for (i = 0; (size = data_ov017_021d66cc[i].size) != 0; i++) {
        void* p = AllocatorUnion_AllocateRounded(&g_mainAllocator, size);
        int idx = data_ov017_021d66c8[i].index;
        SafeAllocator* alloc = (SafeAllocator*)(self + 0x38 + idx * 0x14);
        alloc->CreateTypeA(p, size);
    }

    NNS_GfdSetFrmTexVramState((int*)(self + RegionOffset278 + 0x2800));
    NNS_GfdSetFrmPlttVramState((int*)(self + RegionOffsetad0 + 0x2000));

    int cond;
    for (i = 0; (cond = data_ov017_021d681c[i].v) != 0; i++) {
        int a = data_ov017_021d6818[i].v;
        int b = data_ov017_021d6820[i].v;
        VramState_Reserve((self + RegionOffset2cc) + a * 0x70, cond, b);
    }

    NNS_GfdSetFrmTexVramState((int*)(self + RegionOffset2a8 + 0x2800));

    for (i = 0; (cond = data_ov017_021d6804[i].v) != 0; i++) {
        int a = data_ov017_021d6800[i].v;
        int b = data_ov017_021d6808[i].v;
        VramState_Reserve((self + RegionOffset2cc) + a * 0x70, cond, b);
    }

    VramState_Reserve(self + RegionOffset29c + 0xc00, 0x8000, 0x400);
    VramState_Reserve(self + RegionOffset30c + 0xc00, 0x4000, 0x400);
}
