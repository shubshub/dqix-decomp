#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Foo0207df50;
extern "C" ARM void VramState_Rewind(struct Foo0207df50* p);
extern "C" ARM void VramState_Restore(char* obj);
extern "C" ARM void VramState_Save(char* obj);
extern "C" void VramState_Reserve(void* p, int a, int b);

struct Struct_020e7d30 { int a; int b; };
extern unsigned int data_020e7c18[];
extern struct Struct_020e7d30 data_020e7d30[];
extern struct Struct_020e7d30 data_020e7d34[];

// USA: func_02054464
extern "C" ARM int func_02054464(char* obj, SafeAllocator* alloc, char* p) {
    int i;
    unsigned int size;
    void* buf;

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
            ((SafeAllocator*)(obj + 4 + i * 0x14))->ResetAllocatorPointer();
        }
    }

    VramState_Reserve(obj + 0x168 + 0x400, 0x240, 0x20);
    VramState_Save(p);

    buf = alloc->Allocate(0x2000);
    ((SafeAllocator*)(obj + 0x12c + 0x400))->CreateTypeA(buf, 0x2000);

    buf = alloc->Allocate(0x5400);
    ((SafeAllocator*)(obj + 0x540))->CreateTypeA(buf, 0x5400);

    buf = alloc->Allocate(0x1000);
    ((SafeAllocator*)(obj + 0x154 + 0x400))->CreateTypeA(buf, 0x1000);

    buf = alloc->Allocate(0xc00);
    ((SafeAllocator*)(obj + 0x1d8 + 0x400))->CreateTypeA(buf, 0xc00);
}
