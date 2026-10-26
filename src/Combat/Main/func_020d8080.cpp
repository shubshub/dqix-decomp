#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c {
    signed char byte0;
    signed char unknown_1_;
    signed char unknown_2_;
    signed char unknown_3_;
};
struct Struct_020727d8 {
    void* entries;
    short capacity;
    short count;
};
extern "C" void func_0204693c(struct ByteHeader0204693c* p);
extern "C" void func_020727d8(struct Struct_020727d8* list);

struct Obj020d8080 {
    struct ByteHeader0204693c header;   // 0x0
    int field4;                          // 0x4
    int field8;                          // 0x8
    struct Struct_020727d8 list;            // 0xc
    SafeAllocator allocator;             // 0x14
};

// USA: func_020d8080
extern "C" ARM void func_020d8080(struct Obj020d8080* self) {
    func_0204693c(&self->header);
    self->header.byte0 = 0x43;
    self->field8 = 0;
    func_020727d8(&self->list);
    self->allocator.ResetAllocatorPointer();
}
