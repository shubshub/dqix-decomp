#include <globaldefs.h>
#include "std_library_functions.h"

extern const char data_ov017_021d82d4[];

struct Struct_ov017_021d4c04 {
    int field0;
    char pad4[0xc - 0x4];
    int unknown_c_;
    int unknown_10_;
    char unknown_14_[0x18 - 0x14];
    int unknown_18_;
    int unknown_1c_;
    int unknown_20_;
    int unknown_24_;
    char pad28[0x2c - 0x28];
    int unknown_2c_;
    char unknown_30_[0x44 - 0x30];
    void* field0x44;
    void* unknown_48_;
};

// USA: func_ov017_021d4c04
extern "C" ARM void func_ov017_021d4c04(struct Struct_ov017_021d4c04* self, void* node, int arg2, int arg3, int arg4, int arg5) {
    self->unknown_10_ = arg2;
    self->unknown_c_ = arg3;
    self->unknown_24_ = arg4;
    self->unknown_20_ = arg5;
    self->unknown_18_ = self->unknown_10_ + (arg3 << 3);
    self->unknown_2c_ = arg5 * 0xc + self->unknown_24_;
    self->field0x44 = node;
    self->unknown_48_ = (char*)node + *(int*)((char*)node + 8);
    if (strncmp((char*)self->field0x44, data_ov017_021d82d4, 3) != 0) return;
    self->field0 = 2;
    self->unknown_1c_ = self->unknown_10_;
    self->unknown_10_ = self->unknown_10_ + *(int*)((char*)self->field0x44 + 0x18) * 8;
    self->unknown_c_ = self->unknown_c_ - *(int*)((char*)self->field0x44 + 0x18);
    memset((void*)self->unknown_1c_, 0, *(int*)((char*)self->field0x44 + 0x18) * 8);
}
