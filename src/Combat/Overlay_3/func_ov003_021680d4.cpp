#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

#if defined(jpn)
enum { Enum_ov003_021680d4_1236 = 0x4d0 };
enum { Enum_ov003_021680d4_28672 = 0x8000 };
enum { Enum_ov003_021680d4_4096 = 0x400 };
enum { Enum_ov003_021680d4_640 = 0x140 };
enum { Enum_ov003_021680d4_92 = 0x28 };
#else
enum { Enum_ov003_021680d4_1236 = 0x4d4 };
enum { Enum_ov003_021680d4_28672 = 0x7000 };
enum { Enum_ov003_021680d4_4096 = 0x1000 };
enum { Enum_ov003_021680d4_640 = 0x280 };
enum { Enum_ov003_021680d4_92 = 0x5c };
#endif

struct Struct0205a198;
void Sprite_Init(Struct0205a198*);
struct ClearTarget0205a234;
void ClearField0And40205a234(ClearTarget0205a234*);
int GetGlobalField0x1c020421a0();

struct Struct_ov003_021680d4 {
    SafeAllocator unknown_0_;
    SafeAllocator unknown_14_;
    SafeAllocator unknown_28_;
    SafeAllocator unknown_3c_;
    SafeAllocator unknown_50_;
    char unknown_64_[0x7c - 0x64];
    int unknown_7c_;
    char unknown_80_[Enum_ov003_021680d4_1236 - 0x80];
    void* unknown_4d4_;
    void* unknown_4d8_;
};

// USA: func_ov003_021680d4
extern "C" ARM void func_ov003_021680d4(struct Struct_ov003_021680d4* arg0, SafeAllocator* arg1) {
    if (arg1 == 0) return;
    void* var0 = arg1->Allocate(0x4000);
    arg0->unknown_0_.CreateTypeA(var0, 0x4000);
    void* var1 = arg1->Allocate(0x8000);
    arg0->unknown_14_.CreateTypeA(var1, 0x8000);
    void* var2 = arg1->Allocate(Enum_ov003_021680d4_28672);
    arg0->unknown_28_.CreateTypeA(var2, Enum_ov003_021680d4_28672);
    void* var3 = arg1->Allocate(Enum_ov003_021680d4_4096);
    arg0->unknown_3c_.CreateTypeA(var3, Enum_ov003_021680d4_4096);
    void* var4 = arg1->Allocate(0x400);
    arg0->unknown_50_.CreateTypeA(var4, 0x400);
    void* var5 = arg1->Allocate(Enum_ov003_021680d4_640);
    arg0->unknown_4d4_ = var5;

    int var6;
#if defined(jpn)
    for (var6 = 0; var6 < 8; var6++) {
#else
    for (var6 = 0; var6 < 0x10; var6++) {
#endif
        Sprite_Init((Struct0205a198*)((char*)obj->field4d4 + i * 0x28));
    }

    void* var7 = arg1->Allocate(8);
    arg0->unknown_4d8_ = var7;
    func_0205a234((Struct_02043368*)var7);

    arg0->unknown_7c_ = *(int*)(func_020421a0() + Enum_ov003_021680d4_92);
}
