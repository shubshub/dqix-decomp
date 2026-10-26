#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

#if defined(jpn)
enum { Enum_ov003_021680d4_1236 = 0x4d0 };
enum { Enum_ov003_021680d4_28672 = 0x8000 };
enum { Enum_ov003_021680d4_4096 = 0x400 };
enum { Enum_ov003_021680d4_640 = 0x140 };
enum { kRegionValue5C_28 = 0x28 };
#else
enum { Enum_ov003_021680d4_1236 = 0x4d4 };
enum { Enum_ov003_021680d4_28672 = 0x7000 };
enum { Enum_ov003_021680d4_4096 = 0x1000 };
enum { Enum_ov003_021680d4_640 = 0x280 };
enum { kRegionValue5C_28 = 0x5c };
#endif

struct Struct0205a198;
extern "C" void Sprite_Init(Struct0205a198*);
struct ClearTarget0205a234;
extern "C" void func_0205a234(ClearTarget0205a234*);
extern "C" int MessageSystem_GetInstance();

struct Struct_ov003_021680d4 {
    SafeAllocator unknown_0_;
    SafeAllocator unknown_14_;
    SafeAllocator alloc28;
    SafeAllocator alloc3c;
    SafeAllocator unknown_50_;
    char unknown_64_[0x7c - 0x64];
    int field7c;
    char unknown_80_[Enum_ov003_021680d4_1236 - 0x80];
    void* field4d4;
    void* unknown_4d8_;
};

// USA: func_ov003_021680d4
extern "C" ARM void func_ov003_021680d4(struct Struct_ov003_021680d4* obj, SafeAllocator* alloc) {
    if (alloc == 0) return;
    void* p1 = alloc->Allocate(0x4000);
    obj->unknown_0_.CreateTypeA(p1, 0x4000);
    void* p2 = alloc->Allocate(0x8000);
    obj->unknown_14_.CreateTypeA(p2, 0x8000);
    void* p3 = alloc->Allocate(Enum_ov003_021680d4_28672);
    obj->alloc28.CreateTypeA(p3, Enum_ov003_021680d4_28672);
    void* p4 = alloc->Allocate(Enum_ov003_021680d4_4096);
    obj->alloc3c.CreateTypeA(p4, Enum_ov003_021680d4_4096);
    void* p5 = alloc->Allocate(0x400);
    obj->unknown_50_.CreateTypeA(p5, 0x400);
    void* p6 = alloc->Allocate(Enum_ov003_021680d4_640);
    obj->field4d4 = p6;

    int i;
#if defined(jpn)
    for (i = 0; i < 8; i++) {
#else
    for (i = 0; i < 0x10; i++) {
#endif
        Sprite_Init((Struct0205a198*)((char*)obj->field4d4 + i * 0x28));
    }

    void* p7 = alloc->Allocate(8);
    obj->unknown_4d8_ = p7;
    func_0205a234((ClearTarget0205a234*)p7);

    obj->field7c = *(int*)(MessageSystem_GetInstance() + kRegionValue5C_28);
}
