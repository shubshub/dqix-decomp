#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov023_021e4e3c_1252 = 0x4e0, kFlagsOffset = 0x56c };
#else
enum { Enum_ov023_021e4e3c_1252 = 0x4e4, kFlagsOffset = 0x634 };
#endif

struct Struct_ov023_021e3030 {
    unsigned char unknown[Enum_ov023_021e4e3c_1252];
    unsigned char unknown_4e4_;
    unsigned char unknown_4e5_;
    signed char state;
    signed char unknown_4e7_;
    unsigned char unknown_4e8_[kFlagsOffset - Enum_ov023_021e4e3c_1252 - 4];
    unsigned short flags;
    unsigned char counter;
};

// USA: func_ov023_021e4e3c
extern "C" ARM Struct_ov023_021e3030* func_ov023_021e4e3c(Struct_ov023_021e3030* self) {
    if (!(self->flags & 0x1000)) {
        return self;
    }
    if (self->flags & 0x2000) {
        return self;
    }
    if (self->counter != 0) {
        return self;
    }
    self->unknown_4e7_ = self->state;
    self->state = 1;
    self->unknown_4e4_ = 0;
    ++self->counter;
    return self;
}
