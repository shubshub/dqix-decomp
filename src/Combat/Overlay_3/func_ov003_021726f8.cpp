#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

#if defined(jpn)
enum { Enum_ov003_021726f8_448 = 0x1cc };
enum { Enum_ov003_021726f8_296 = 0x134 };
enum { Enum_ov003_021726f8_520 = 0x1e0 };
enum { Enum_ov003_021726f8_300 = 0x138 };
enum { Enum_ov003_021726f8_13 = 0xc };
enum { Enum_ov003_021726f8_428 = 0x1b8 };
enum { Enum_ov003_021726f8_10240 = 0x1c00 };
enum { Enum_ov003_021726f8_388 = 0x190 };
enum { Enum_ov003_021726f8_408 = 0x1a4 };
#else
enum { Enum_ov003_021726f8_448 = 0x1c0 };
enum { Enum_ov003_021726f8_296 = 0x128 };
enum { Enum_ov003_021726f8_520 = 0x208 };
enum { Enum_ov003_021726f8_300 = 0x12c };
enum { Enum_ov003_021726f8_13 = 0xd };
enum { Enum_ov003_021726f8_428 = 0x1ac };
enum { Enum_ov003_021726f8_10240 = 0x2800 };
enum { Enum_ov003_021726f8_388 = 0x184 };
enum { Enum_ov003_021726f8_408 = 0x198 };
#endif


struct Struct0205a198;
void Sprite_Init(struct Struct0205a198* p);

struct Struct_02043368;
extern "C" void func_0205a234(struct Struct_02043368* arg0);

// USA: func_ov003_021726f8
extern "C" ARM void func_ov003_021726f8(char* arg0, SafeAllocator* arg1) {
    int var0;

    if (arg1 == 0) return;

    *(SafeAllocator**)(arg0 + Enum_ov003_021726f8_448) = arg1;
    *(void**)(arg0 + Enum_ov003_021726f8_296) = arg1->Allocate(Enum_ov003_021726f8_520);
    *(void**)(arg0 + Enum_ov003_021726f8_300) = (*(SafeAllocator**)(arg0 + Enum_ov003_021726f8_448))->Allocate(8);

    for (i = 0; i < kRegionValueD_C; i++) {
        Sprite_Init((struct Struct0205a198*)(*(char**)(obj + kRegionValue128_134) + i * 0x28));
    }

    func_0205a234((struct Struct_02043368*)*(void**)(arg0 + Enum_ov003_021726f8_300));

    void* var1 = (*(SafeAllocator**)(arg0 + Enum_ov003_021726f8_448))->Allocate(0x1000);
    ((SafeAllocator*)(arg0 + Enum_ov003_021726f8_428))->CreateTypeA(var1, 0x1000);
    ((SafeAllocator*)(arg0 + Enum_ov003_021726f8_428))->Reset();

    void* var2 = (*(SafeAllocator**)(arg0 + Enum_ov003_021726f8_448))->Allocate(Enum_ov003_021726f8_10240);
    ((SafeAllocator*)(arg0 + Enum_ov003_021726f8_388))->CreateTypeA(var2, Enum_ov003_021726f8_10240);
    ((SafeAllocator*)(arg0 + Enum_ov003_021726f8_388))->Reset();

    void* var3 = (*(SafeAllocator**)(arg0 + Enum_ov003_021726f8_448))->Allocate(0x400);
    ((SafeAllocator*)(arg0 + Enum_ov003_021726f8_408))->CreateTypeA(var3, 0x400);
    ((SafeAllocator*)(arg0 + Enum_ov003_021726f8_408))->Reset();
}
