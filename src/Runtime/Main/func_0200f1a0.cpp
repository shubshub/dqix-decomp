#include <globaldefs.h>

struct Struct_0200f1a0_2 {
    unsigned long unknown_0_[16];
    char* unknown_40_;
    unsigned long unknown_44_;
    unsigned long unknown_48_;
    unsigned short unknown_4c_;
    bool unknown_4e_;
    bool unknown_4f_;
    bool unknown_50_;
};

struct Struct_0200f1a0 {
    unsigned char* unknown_0_;
    void* location;
    void* dtor;
    void* unknown_c_;
    char* unknown_10_;
    char* unknown_14_;
    char* fp;
    Struct_0200f1a0_2 target;
};

struct Struct_0200f1a0_3;

// USA: func_0200f1a0
extern "C" ARM char* func_0200f1a0(Struct_0200f1a0* context, Struct_0200f1a0_3* info) {
    unsigned long var0, var1, *var2;
    int i;

    var0 = context->target.unknown_44_;
    var1 = context->target.unknown_4e_ ? 16 : 0;

    var2 = (unsigned long*)(context->fp + var0 - var1);
    for (i = 15; i >= 0; i--) {
        if (context->target.unknown_4c_ & (1 << i))
            context->target.unknown_0_[i] = *--var2;
    }

    context->unknown_14_ = context->fp + var0;

    return (char*)context->target.unknown_0_[14];
}
