#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

#if defined(jpn)
enum { Enum_ov003_021726f8_448 = 0x1cc };
enum { kRegionValue128_134 = 0x134 };
enum { Enum_ov003_021726f8_520 = 0x1e0 };
enum { Enum_ov003_021726f8_300 = 0x138 };
enum { Enum_ov003_021726f8_13 = 0xc };
enum { Enum_ov003_021726f8_428 = 0x1b8 };
enum { Enum_ov003_021726f8_10240 = 0x1c00 };
enum { Enum_ov003_021726f8_388 = 0x190 };
enum { Enum_ov003_021726f8_408 = 0x1a4 };
#else
enum { Enum_ov003_021726f8_448 = 0x1c0 };
enum { kRegionValue128_134 = 0x128 };
enum { Enum_ov003_021726f8_520 = 0x208 };
enum { Enum_ov003_021726f8_300 = 0x12c };
enum { Enum_ov003_021726f8_13 = 0xd };
enum { Enum_ov003_021726f8_428 = 0x1ac };
enum { Enum_ov003_021726f8_10240 = 0x2800 };
enum { Enum_ov003_021726f8_388 = 0x184 };
enum { Enum_ov003_021726f8_408 = 0x198 };
#endif


struct Struct0205a198;
extern "C" void Sprite_Init(struct Struct0205a198* p);

struct ClearTarget0205a234;
extern "C" void func_0205a234(struct ClearTarget0205a234* target);

// USA: func_ov003_021726f8
extern "C" ARM void func_ov003_021726f8(char* obj, SafeAllocator* allocator) {
    int i;

    if (allocator == 0) return;

    *(SafeAllocator**)(obj + Enum_ov003_021726f8_448) = allocator;
    *(void**)(obj + kRegionValue128_134) = allocator->Allocate(Enum_ov003_021726f8_520);
    *(void**)(obj + Enum_ov003_021726f8_300) = (*(SafeAllocator**)(obj + Enum_ov003_021726f8_448))->Allocate(8);

    for (i = 0; i < Enum_ov003_021726f8_13; i++) {
        Sprite_Init((struct Struct0205a198*)(*(char**)(obj + kRegionValue128_134) + i * 0x28));
    }

    func_0205a234((struct ClearTarget0205a234*)*(void**)(obj + Enum_ov003_021726f8_300));

    void* p1 = (*(SafeAllocator**)(obj + Enum_ov003_021726f8_448))->Allocate(0x1000);
    ((SafeAllocator*)(obj + Enum_ov003_021726f8_428))->CreateTypeA(p1, 0x1000);
    ((SafeAllocator*)(obj + Enum_ov003_021726f8_428))->Reset();

    void* p2 = (*(SafeAllocator**)(obj + Enum_ov003_021726f8_448))->Allocate(Enum_ov003_021726f8_10240);
    ((SafeAllocator*)(obj + Enum_ov003_021726f8_388))->CreateTypeA(p2, Enum_ov003_021726f8_10240);
    ((SafeAllocator*)(obj + Enum_ov003_021726f8_388))->Reset();

    void* p3 = (*(SafeAllocator**)(obj + Enum_ov003_021726f8_448))->Allocate(0x400);
    ((SafeAllocator*)(obj + Enum_ov003_021726f8_408))->CreateTypeA(p3, 0x400);
    ((SafeAllocator*)(obj + Enum_ov003_021726f8_408))->Reset();
}
