#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct_0208ba54;
extern "C" void func_0208ba54(struct Struct_0208ba54* self);

struct Struct_ov004_021678bc {
    unsigned char pad[0x20];
    SafeAllocator allocator;
    unsigned char pad2[0x34 - 0x20 - sizeof(SafeAllocator)];
    struct Struct_0208ba54* group;
};

// USA: func_ov004_021678bc
extern "C" ARM void func_ov004_021678bc(struct Struct_ov004_021678bc* self) {
    func_0208ba54((struct Struct_0208ba54*)((char*)self + 0x34));
    self->allocator.Destroy();
}
