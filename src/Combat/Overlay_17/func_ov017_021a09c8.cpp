#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"

#if defined(jpn)
enum { Field2a78 = 0x2868, Field2ad0 = 0x28c0, Field2aa8 = 0x2898, Field2cc = 0x27c, Enum_ov017_021a09c8_3852 = 0xebc, Enum_ov017_021a09c8_3068 = 0xbac, Enum_ov017_021a09c8_3892 = 0xee4, Enum_ov017_021a09c8_3108 = 0xbd4, Enum_ov017_021a09c8_3932 = 0xf0c, Enum_ov017_021a09c8_3148 = 0xbfc, Enum_ov017_021a09c8_3936 = 0xf10, Enum_ov017_021a09c8_3152 = 0xc00, Enum_ov017_021a09c8_3940 = 0xf14, Enum_ov017_021a09c8_3156 = 0xc04, Enum_ov017_021a09c8_3948 = 0xf1c, Enum_ov017_021a09c8_3164 = 0xc0c, Enum_ov017_021a09c8_3956 = 0xf24, Enum_ov017_021a09c8_3172 = 0xc14, Enum_ov017_021a09c8_3960 = 0xf28, Enum_ov017_021a09c8_3176 = 0xc18 };
#else
enum { Field2a78 = 0x2a78, Field2ad0 = 0x2ad0, Field2aa8 = 0x2aa8, Field2cc = 0x2cc, Enum_ov017_021a09c8_3852 = 0xf0c, Enum_ov017_021a09c8_3068 = 0xbfc, Enum_ov017_021a09c8_3892 = 0xf34, Enum_ov017_021a09c8_3108 = 0xc24, Enum_ov017_021a09c8_3932 = 0xf5c, Enum_ov017_021a09c8_3148 = 0xc4c, Enum_ov017_021a09c8_3936 = 0xf60, Enum_ov017_021a09c8_3152 = 0xc50, Enum_ov017_021a09c8_3940 = 0xf64, Enum_ov017_021a09c8_3156 = 0xc54, Enum_ov017_021a09c8_3948 = 0xf6c, Enum_ov017_021a09c8_3164 = 0xc5c, Enum_ov017_021a09c8_3956 = 0xf74, Enum_ov017_021a09c8_3172 = 0xc64, Enum_ov017_021a09c8_3960 = 0xf78, Enum_ov017_021a09c8_3176 = 0xc68 };
#endif

extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern "C" void VramState_Reserve(void* p, int a, int b);
extern "C" void NNS_GfdSetFrmTexVramState(int* out);
extern "C" void NNS_GfdSetFrmPlttVramState(int* src);
extern "C" int NNS_GfdAllocFrmTexVram(unsigned int size, int a, int b);

extern AllocatorUnion g_mainAllocator;

struct Struct_ov017_021d689c { int a; int pad4; };
struct Struct_ov017_021d6758 { int a; int pad4; int pad8; };
extern Struct_ov017_021d689c data_ov017_021d689c[];
extern Struct_ov017_021d689c data_ov017_021d68a0[];
extern Struct_ov017_021d6758 data_ov017_021d6758[];
extern Struct_ov017_021d6758 data_ov017_021d6760[];
extern Struct_ov017_021d6758 data_ov017_021d675c[];
extern Struct_ov017_021d6758 data_ov017_021d6850[];
extern Struct_ov017_021d6758 data_ov017_021d6858[];
extern Struct_ov017_021d6758 data_ov017_021d6854[];

struct Struct_ov017_021a09c8 { unsigned int w[10]; };
struct Struct_ov017_021a09c8_2 { unsigned int w[2]; };

// USA: func_ov017_021a09c8
extern "C" ARM void func_ov017_021a09c8(char* self) {
    int size;
    for (int i = 0; (size = data_ov017_021d68a0[i].a) != 0; i++) {
        void* buf = AllocatorUnion_AllocateRounded(&g_mainAllocator, size);
        int idx = data_ov017_021d689c[i].a;
        ((SafeAllocator*)((self + 0x38) + idx * 0x14))->CreateTypeA(buf, size);
    }

    NNS_GfdSetFrmTexVramState((int*)(self + Field2a78));
    NNS_GfdSetFrmPlttVramState((int*)(self + Field2ad0));
    NNS_GfdAllocFrmTexVram(0x20000, 0, 0);

    {
        int n;
        for (int i = 0; (n = data_ov017_021d675c[i].a) != 0; i++) {
            VramState_Reserve((self + Field2cc) + data_ov017_021d6758[i].a * 0x70, n, data_ov017_021d6760[i].a);
        }
    }

    NNS_GfdSetFrmTexVramState((int*)(self + Field2aa8));

    {
        int n;
        for (int i = 0; (n = data_ov017_021d6854[i].a) != 0; i++) {
            VramState_Reserve((self + Field2cc) + data_ov017_021d6850[i].a * 0x70, n, data_ov017_021d6858[i].a);
        }
    }

    *(Struct_ov017_021a09c8*)(self + Enum_ov017_021a09c8_3852) = *(Struct_ov017_021a09c8*)(self + Enum_ov017_021a09c8_3068);
    *(Struct_ov017_021a09c8*)(self + Enum_ov017_021a09c8_3892) = *(Struct_ov017_021a09c8*)(self + Enum_ov017_021a09c8_3108);

    *(int*)(self + Enum_ov017_021a09c8_3932) = *(int*)(self + Enum_ov017_021a09c8_3148);
    *(int*)(self + Enum_ov017_021a09c8_3936) = *(int*)(self + Enum_ov017_021a09c8_3152);
    *(Struct_ov017_021a09c8_2*)(self + Enum_ov017_021a09c8_3940) = *(Struct_ov017_021a09c8_2*)(self + Enum_ov017_021a09c8_3156);
    *(Struct_ov017_021a09c8_2*)(self + Enum_ov017_021a09c8_3948) = *(Struct_ov017_021a09c8_2*)(self + Enum_ov017_021a09c8_3164);
    *(int*)(self + Enum_ov017_021a09c8_3956) = *(int*)(self + Enum_ov017_021a09c8_3172);
    *(int*)(self + Enum_ov017_021a09c8_3960) = *(int*)(self + Enum_ov017_021a09c8_3176);
}
