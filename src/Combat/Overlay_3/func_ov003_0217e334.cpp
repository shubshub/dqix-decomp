#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c {
    signed char byte0;
    signed char unknown_1_;
    signed char unknown_2_;
    signed char unknown_3_;
};
extern "C" void func_0204693c(struct ByteHeader0204693c* p);

struct Struct_ov003_0217e300 {
    struct ByteHeader0204693c hdr;
    char pad4[4];
    int field8;
    class SafeAllocator alloc;
    int field20;
    unsigned char field24;
};

// USA: func_ov003_0217e334
extern "C" ARM void func_ov003_0217e334(struct Struct_ov003_0217e300* self) {
    func_0204693c(&self->hdr);
    self->hdr.byte0 = 0x11;
    self->field8 = 0;
    self->alloc.ResetAllocatorPointer();
    self->field20 = 0;
    self->field24 = 0xff;
}
