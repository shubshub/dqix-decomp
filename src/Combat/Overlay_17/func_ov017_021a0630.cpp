#if defined(jpn)
enum { Enum_ov017_021a0630_632 = 0x68, Enum_ov017_021a0630_2768 = 0x8c0, Enum_ov017_021a0630_716 = 0x27c, Enum_ov017_021a0630_680 = 0x98, Enum_ov017_021a0630_668 = 0x24c, Enum_ov017_021a0630_780 = 0x2bc };
#else
enum { Enum_ov017_021a0630_632 = 0x278, Enum_ov017_021a0630_2768 = 0xad0, Enum_ov017_021a0630_716 = 0x2cc, Enum_ov017_021a0630_680 = 0x2a8, Enum_ov017_021a0630_668 = 0x29c, Enum_ov017_021a0630_780 = 0x30c };
#endif

#include <globaldefs.h>
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "Memory/SafeAllocator.h"

void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
void NNS_GfdSetFrmTexVramState(int* out);
void NNS_GfdSetFrmPlttVramState(int* src);
extern "C" void VramState_Reserve(void* p, int a, int b);

extern AllocatorUnion g_mainAllocator;

struct Struct_ov017_021d66c8 { int unknown_0_; int unknown_4_; };
struct Struct_ov017_021d66cc { int unknown_0_; int unknown_4_; };
extern Struct_ov017_021d66c8 data_ov017_021d66c8[];
extern Struct_ov017_021d66cc data_ov017_021d66cc[];

struct Struct_ov017_021d6800 { int unknown_0_; int unknown_4_; int unknown_8_; };
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
