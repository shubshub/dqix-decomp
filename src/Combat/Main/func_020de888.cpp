#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct Struct_020de714_3;
extern "C" int func_020de7a4(Struct_020de714_3* obj);

struct Struct_020de714;
struct Struct_020de7d0;
typedef void (*Type_020de714)(Struct_020de714*, Struct_020de7d0*);
extern "C" int func_020de7d0(Struct_020de714* c, Type_020de714 cb);

struct Struct_020de5b0;
extern "C" int func_020de5b0(Struct_020de5b0* c);

extern "C" ARM int func_020de574(void* table, void* cursor);

struct Struct_020de888 {
    unsigned int count : 31;
    unsigned int flag : 1;
};

struct Struct_020de888_2 {
    char pad0[8];
    union {
        unsigned int raw;
        struct Struct_020de888 bits;
    } f8;
    void* unknown_c_;
    void* unknown_10_;
};

// USA: func_020de888
extern "C" ARM int func_020de888(Struct_020de888_2* self, SafeAllocator* allocator, void* file, void* arg3) {
    int offset;
    unsigned int count;
    Type_020de714 cb;

    if (allocator == 0 || file == 0 || arg3 == 0) {
        return 0;
    }
    if (allocator != 0 && file != 0) {
        memcpy(self, file, 0xc);
        offset = func_020de7a4((Struct_020de714_3*)self);
        count = self->f8.bits.count;
        if (offset != 0)
            self->unknown_c_ = allocator->Allocate(offset);
        else
            self->unknown_c_ = 0;
        self->unknown_10_ = (count != 0) ? allocator->Allocate(count) : 0;
        if (self->unknown_c_ != 0) {
            memcpy(self->unknown_c_, (char*)file + 0xc, offset);
        }
        if (self->unknown_10_ != 0) {
            memcpy(self->unknown_10_, (char*)file + (func_020de7a4((Struct_020de714_3*)self) + 0xc), count);
        }
        cb = (Type_020de714)func_020de574;
        if (cb != 0) {
            func_020de7d0((Struct_020de714*)self, cb);
        }
        self->f8.raw = (self->f8.raw & ~0x80000000u) | 0x80000000u;
    }
    return func_020de5b0((Struct_020de5b0*)self);
}
