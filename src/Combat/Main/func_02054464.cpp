#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Foo0207df50;
ARM void VramState_Rewind(struct Foo0207df50* p);
ARM void VramState_Restore(char* obj);
ARM void VramState_Save(char* obj);
extern "C" void VramState_Reserve(void* p, int a, int b);

struct Struct_020e7d30 { int unknown_0_; int unknown_4_; };
extern unsigned int data_020e7c18[];
extern struct Struct_020e7d30 data_020e7d30[];
extern struct Struct_020e7d30 data_020e7d34[];

// USA: func_02054464
extern "C" ARM int func_02054464(char* arg0, SafeAllocator* arg1, char* arg2) {
    int var0;
    unsigned int var1;
    void* var2;

    alloc->Reset();
    VramState_Rewind((struct Foo0207df50*)p);
    VramState_Restore(p);

    for (i = 0; i < 10; i++) {
        size = data_020e7c18[i];
        if (size != 0) {
            buf = alloc->Allocate(size);
            ((SafeAllocator*)(obj + 4 + i * 0x14))->CreateTypeA(buf, size);
            VramState_Reserve(obj + 0xcc + i * 0x70, data_020e7d30[i].a, data_020e7d34[i].a);
        } else {
            ((SafeAllocator*)(arg0 + 4 + var0 * 0x14))->ResetAllocatorPointer();
        }
    }

    VramState_Reserve(obj + 0x168 + 0x400, 0x240, 0x20);
    VramState_Save(p);

    var2 = arg1->Allocate(0x2000);
    ((SafeAllocator*)(arg0 + 0x12c + 0x400))->CreateTypeA(var2, 0x2000);

    var2 = arg1->Allocate(0x5400);
    ((SafeAllocator*)(arg0 + 0x540))->CreateTypeA(var2, 0x5400);

    var2 = arg1->Allocate(0x1000);
    ((SafeAllocator*)(arg0 + 0x154 + 0x400))->CreateTypeA(var2, 0x1000);

    var2 = arg1->Allocate(0xc00);
    ((SafeAllocator*)(arg0 + 0x1d8 + 0x400))->CreateTypeA(var2, 0xc00);
}
