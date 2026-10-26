#include <globaldefs.h>

struct Struct_0200ea08_2 {
    void* location;
    void* unknown_4_;
    void* dtor;
    void* unknown_c_;
    long unknown_10_;
    void* unknown_14_;
};

struct Struct_0200ea08 {
    unsigned char* unknown_0_;
    void* location;
    void* dtor;
    Struct_0200ea08_2* unknown_c_;
    char* unknown_10_;
    char* unknown_14_;
    char* fp;
};

struct Struct_0200ea08_3 {
    char* unknown_0_;
    char* unknown_4_;
    char* unknown_8_;
    void* unknown_c_;
    void* unknown_10_;
    int target;
};

struct Struct_0200ea08_4 {
    unsigned long unknown_0_;
    unsigned long unknown_4_;
    long unknown_8_;
    char* unknown_c_;
};

extern "C" void func_0200df80(Struct_0200ea08* context, Struct_0200ea08_3* info, char* arg2);
extern "C" void func_0200f2ec(Struct_0200ea08* context, Struct_0200ea08_3* info, char* address);

// USA: func_0200ea08
extern "C" ARM void func_0200ea08(Struct_0200ea08* context, Struct_0200ea08_3* info,
                                  Struct_0200ea08_4* arg2, char* arg3) {
    Struct_0200ea08_2* var0;

#pragma exception_terminate

    func_0200df80(context, info, arg3);

    var0 = (Struct_0200ea08_2*)(context->fp + arg2->unknown_8_);
    var0->location = context->location;
    var0->unknown_4_ = context->unknown_0_;
    var0->dtor = context->dtor;
    var0->unknown_14_ = arg3;

    func_0200f2ec(context, info, info->unknown_0_ + arg2->unknown_4_);
}
