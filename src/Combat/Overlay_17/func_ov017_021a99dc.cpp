#if defined(jpn)
enum {regionalOffset0=0xe94, regionalOffset1=0x200, regionalOffset2=0xdec, regionalOffset3=0x218};
#else
enum {regionalOffset0=0xe98, regionalOffset1=0x204, regionalOffset2=0xdf0, regionalOffset3=0x21c};
#endif
#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_ov017_021a99dc {
    unsigned char pad0[regionalOffset0];
    unsigned char flags;
};

struct Struct_ov017_021a99dc_2 {
    unsigned char pad0[0x20];
    Struct_ov017_021a99dc* target;
    unsigned char pad1[0x1];
    unsigned char unknown_25_;
    unsigned char unknown_26_;
};

// USA: func_ov017_021a99dc
extern "C" ARM void func_ov017_021a99dc(Struct_ov017_021a99dc_2* self, void* src, int mode, int amount, unsigned char flag) {
    Struct_ov017_021a99dc* target = self->target;
    if (target == NULL) {
        return;
    }
    if (mode == 0) {
        unsigned char b = self->unknown_25_;
        memcpy((char*)target + regionalOffset1 + 0xc00 + b, src, amount);
        self->unknown_25_ = self->unknown_25_ + amount;
    } else if (mode == 2) {
        memcpy((char*)target + regionalOffset2, src, amount);
        target = self->target;
        target->flags = target->flags | 0x4;
    } else {
        target->flags = target->flags | 0x1;
        unsigned char b = self->unknown_26_;
        memcpy((char*)self->target + regionalOffset3 + 0xc00 + b, src, amount);
        self->unknown_26_ = self->unknown_26_ + amount;
    }
    if (flag != 0) {
        target = self->target;
        target->flags = target->flags | 0x2;
    }
}
