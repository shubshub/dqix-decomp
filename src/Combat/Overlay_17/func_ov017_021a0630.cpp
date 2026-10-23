#if defined(jpn)
enum { Enum_ov017_021a0630_632 = 0x68, Enum_ov017_021a0630_2768 = 0x8c0, Enum_ov017_021a0630_716 = 0x27c, Enum_ov017_021a0630_680 = 0x98, Enum_ov017_021a0630_668 = 0x24c, Enum_ov017_021a0630_780 = 0x2bc };
#else
enum { Enum_ov017_021a0630_632 = 0x278, Enum_ov017_021a0630_2768 = 0xad0, Enum_ov017_021a0630_716 = 0x2cc, Enum_ov017_021a0630_680 = 0x2a8, Enum_ov017_021a0630_668 = 0x29c, Enum_ov017_021a0630_780 = 0x30c };
#endif

#include <globaldefs.h>
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "Memory/SafeAllocator.h"

void* AllocateAligned4_02012d88(AllocatorUnion* alloc, unsigned int size);
void RestorePairTableFromBuffer_020bb740(int* out);
void WriteGlobalPair020bb92c(int* src);
extern "C" void VramState_Reserve(void* p, int a, int b);

extern AllocatorUnion data_02114e20;

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
extern "C" ARM void func_ov017_021a0630(char* arg0) {
    int var0;
    int var1;
    for (var0 = 0; (var1 = data_ov017_021d66cc[var0].unknown_0_) != 0; var0++) {
        void* var2 = func_02012d88(&data_02114e20, var1);
        int var3 = data_ov017_021d66c8[var0].unknown_0_;
        SafeAllocator* var4 = (SafeAllocator*)(arg0 + 0x38 + var3 * 0x14);
        var4->CreateTypeA(var2, var1);
    }

    func_020bb740((int*)(arg0 + Enum_ov017_021a0630_632 + 0x2800));
    func_020bb92c((int*)(arg0 + Enum_ov017_021a0630_2768 + 0x2000));

    int cond;
    for (i = 0; (cond = data_ov017_021d681c[i].v) != 0; i++) {
        int a = data_ov017_021d6818[i].v;
        int b = data_ov017_021d6820[i].v;
        VramState_Reserve((self + RegionOffset2cc) + a * 0x70, cond, b);
    }

    func_020bb740((int*)(arg0 + Enum_ov017_021a0630_680 + 0x2800));

    for (i = 0; (cond = data_ov017_021d6804[i].v) != 0; i++) {
        int a = data_ov017_021d6800[i].v;
        int b = data_ov017_021d6808[i].v;
        VramState_Reserve((self + RegionOffset2cc) + a * 0x70, cond, b);
    }

    VramState_Reserve(self + RegionOffset29c + 0xc00, 0x8000, 0x400);
    VramState_Reserve(self + RegionOffset30c + 0xc00, 0x4000, 0x400);
}
