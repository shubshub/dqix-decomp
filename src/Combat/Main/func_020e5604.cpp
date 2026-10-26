#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct Struct_020e53bc_3;
extern "C" unsigned int func_020e544c(Struct_020e53bc_3* header);

struct Struct_020e53bc;
struct Struct_020e545c;
typedef void (*Type_020e53bc)(Struct_020e53bc*, Struct_020e545c*);
extern "C" int func_020e545c(Struct_020e53bc* list, Type_020e53bc callback);

struct Struct_020e5204;
extern "C" void func_020e5204(void* a, Struct_020e5204* b);

struct Struct_020e5604 {
    unsigned int field0;
    void* field4;
    void* field8;
};

// USA: func_020e5604
extern "C" ARM int func_020e5604(struct Struct_020e5604* self, SafeAllocator* alloc, unsigned char* src, int flag) {
    unsigned int var0;
    unsigned int var1;
    if (!(alloc != 0 && src != 0 && flag != 0)) {
        return 0;
    }
    if (!(alloc != 0 && src != 0)) {
        return 0;
    }
    memcpy(self, src, 4);
    var0 = func_020e544c((Struct_020e53bc_3*)self);
    var1 = (self->field0 << 1) >> 13;
    if (var0)
        self->field4 = alloc->Allocate(var0);
    else
        self->field4 = (void*)0;
    self->field8 = var1 ? alloc->Allocate(var1) : (void*)0;
    if (self->field4) {
        memcpy(self->field4, src + 4, var0);
    }
    if (self->field8) {
        memcpy(self->field8, src + (func_020e544c((Struct_020e53bc_3*)self) + 4), var1);
    }
    if ((void*)func_020e5204 != 0) {
        func_020e545c((Struct_020e53bc*)self,
            (Type_020e53bc)func_020e5204);
    }
    self->field0 = (self->field0 & ~0x80000000) | 0x80000000;
    return 1;
}
