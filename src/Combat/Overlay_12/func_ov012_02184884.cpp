#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

struct Struct0215efb8;
extern "C" ARM void Keyboard_Init(Struct0215efb8* s);

struct KeyboardLayout;
extern "C" ARM void KeyboardLayout_Init(KeyboardLayout* s);

extern "C" ARM int func_020ac460(void* dst);

#if defined(jpn)
enum { Enum_ov012_02184884_0 = -8, Enum_ov012_02184884_0_2 = -0x28, Enum_ov012_02184884_0_3 = 0x58, Enum_ov012_02184884_84992 = 0x15000, Enum_ov012_02184884_9216 = 0x1c00, Enum_ov012_02184884_6144 = 0x1400, Enum_ov012_02184884_760 = 0x2a8 };
#else
enum { Enum_ov012_02184884_0 = 0, Enum_ov012_02184884_0_2 = 0, Enum_ov012_02184884_0_3 = 0, Enum_ov012_02184884_84992 = 0x14c00, Enum_ov012_02184884_9216 = 0x2400, Enum_ov012_02184884_6144 = 0x1800, Enum_ov012_02184884_760 = 0x2f8 };
#endif

// USA: func_ov012_02184884
extern "C" ARM void func_ov012_02184884(char* self, SafeAllocator* alloc) {
    if (alloc == 0) return;

#if !defined(jpn)
    void* p0 = alloc->Allocate(0x28);
    *(void**)(self + 0x0) = p0;
    if (p0 != 0) Keyboard_Init((Struct0215efb8*)p0);

    void* p4 = alloc->Allocate(0x10);
    *(void**)(self + 0x4) = p4;
    if (p4 != 0) KeyboardLayout_Init((KeyboardLayout*)p4);

#endif

    ((SafeAllocator*)(self + 0x20 + Enum_ov012_02184884_0))->CreateTypeA(alloc->Allocate(Enum_ov012_02184884_84992), Enum_ov012_02184884_84992);
    ((SafeAllocator*)(self + 0x34 + Enum_ov012_02184884_0))->CreateTypeA(alloc->Allocate(Enum_ov012_02184884_9216), Enum_ov012_02184884_9216);
    ((SafeAllocator*)(self + 0x48 + Enum_ov012_02184884_0))->CreateTypeA(alloc->Allocate(0x9400), 0x9400);
    ((SafeAllocator*)(self + 0x5c + Enum_ov012_02184884_0))->CreateTypeA(alloc->Allocate(0x800), 0x800);
    ((SafeAllocator*)(self + 0x70 + Enum_ov012_02184884_0))->CreateTypeA(alloc->Allocate(Enum_ov012_02184884_6144), Enum_ov012_02184884_6144);
    ((SafeAllocator*)(self + 0x84 + Enum_ov012_02184884_0))->CreateTypeA(alloc->Allocate(0x5400), 0x5400);
#if !defined(jpn)
    ((SafeAllocator*)(self + 0x98 + Enum_ov012_02184884_0))->CreateTypeA(alloc->Allocate(0x400), 0x400);
#endif

    *(void**)(self + 0x1000 + 0x364 + Enum_ov012_02184884_0_2) = alloc->Allocate(Enum_ov012_02184884_760);
    *(void**)(self + 0x1000 + 0x35c + Enum_ov012_02184884_0_2) = alloc->Allocate(0x54);
    *(void**)(self + 0x1000 + 0x360 + Enum_ov012_02184884_0_2) = alloc->Allocate(0x8);
#if !defined(jpn)
    *(void**)(self + 0x1000 + 0x36c) = alloc->Allocate(0x78);
#endif
#if !defined(jpn)
    *(void**)(self + 0x1000 + 0x368) = alloc->Allocate(0x54);
#endif
    *(void**)(self + 0x1000 + 0x3ac + Enum_ov012_02184884_0_3) = alloc->Allocate(0x72);
    *(void**)(self + 0x1000 + 0x3b4 + Enum_ov012_02184884_0_3) = alloc->Allocate(0x3c00);

    *(void**)(self + 0x1000 + 0x3bc + Enum_ov012_02184884_0_3) = alloc->Allocate(0xf2);
    memset(*(void**)(self + 0x1000 + 0x3bc + Enum_ov012_02184884_0_3), 0, 0xf2);

    *(void**)(self + 0x1000 + 0x3c0 + Enum_ov012_02184884_0_3) = alloc->Allocate(0x12);
    memset(*(void**)(self + 0x1000 + 0x3c0 + Enum_ov012_02184884_0_3), 0, 0x12);

    void* var2 = alloc->Allocate(0x38c);
    *(void**)(self + 0x1000 + 0x3c8 + Enum_ov012_02184884_0_3) = var2;
    memset(var2, 0, 0x38c);

    void* var3 = alloc->Allocate(0x3c);
    *(void**)(self + 0x1000 + 0x3cc + Enum_ov012_02184884_0_3) = var3;
    memset(var3, 0, 0x3c);

    func_020ac460(*(void**)(self + 0x1000 + 0x3cc + Enum_ov012_02184884_0_3));

    void* var4 = alloc->Allocate(0x400);
    *(void**)(self + 0x1000 + 0x3d0 + Enum_ov012_02184884_0_3) = var4;
    memset(var4, 0, 0x400);
}
