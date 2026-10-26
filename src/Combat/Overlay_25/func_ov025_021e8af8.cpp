#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct SafeAllocator;
struct Foo0207df50;

struct Struct_ov025_021e8af8 {
    char pad[0x10];
    SafeAllocator* allocators[4];
    Foo0207df50* fields[4];
    unsigned char index;
};

extern "C" void VramState_Rewind(Foo0207df50*);
extern "C" void _ZN13SafeAllocator7DestroyEv(SafeAllocator*, unsigned int);
extern "C" void func_ov025_021e8bc4(Struct_ov025_021e8af8*, unsigned int);

// USA: func_ov025_021e8af8
extern "C" ARM void func_ov025_021e8af8(Struct_ov025_021e8af8* self) {
    if (self->index == 0) {
        return;
    }
    func_ov025_021e8bc4(self, self->index);
    void* var0 = self->allocators[self->index]->GetSignedAllocator();
    _ZN13SafeAllocator7DestroyEv(self->allocators[self->index], self->index);
    self->allocators[self->index - 1]->Free(var0);
    VramState_Rewind(self->fields[self->index]);
    self->index--;
}
