#include <globaldefs.h>
#include "Resource/FontBankLoader.h"

struct Struct_02092f00 {
    char pad0[0x36];
    unsigned char unknown_36_;
    unsigned char unknown_37_;
};

// USA: func_02092f00
extern "C" ARM void func_02092f00(struct Struct_02092f00* self) {
    unsigned char flags = self->unknown_37_;
    if (flags & 8) return;
    if (!(flags & 4)) return;
    FontBankLoader* globalVal = FontBankLoader_GetInstance();
    if (self->unknown_36_ == 0) {
        func_02094b3c(globalVal, 0xa);
        func_02094b30(globalVal, 0x1f8, 0);
        self->unknown_36_ = self->unknown_36_ + 1;
        return;
    }
    if (self->unknown_36_ != 1) return;
    if (func_02094b4c(globalVal)) {
        self->unknown_37_ = self->unknown_37_ & ~4;
        self->unknown_36_ = 0;
    }
}
