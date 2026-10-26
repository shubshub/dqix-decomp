#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct SafeAllocator;
struct Foo0207df50;

struct Struct_ov025_021e8b6c {
    char pad[0x10];
    SafeAllocator* allocators[4];
    Foo0207df50* fields[4];
    unsigned char index;
};

extern "C" void VramState_Rewind(Foo0207df50*);
extern "C" void func_ov025_021e8bc4(Struct_ov025_021e8b6c*, unsigned int);

// USA: func_ov025_021e8b6c
extern "C" ARM void func_ov025_021e8b6c(Struct_ov025_021e8b6c* self) {
    self->allocators[self->index]->Reset();
    VramState_Rewind(self->fields[self->index]);
    func_ov025_021e8bc4(self, self->index);
}
