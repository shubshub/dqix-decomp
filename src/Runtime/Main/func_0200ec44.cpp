#include <globaldefs.h>

struct Struct_0200ec44_2 {
    void* location;
    void* unknown_4_;
    void* dtor;
    void* unknown_c_;
    long unknown_10_;
    void* unknown_14_;
};

struct Struct_0200ec44 {
    unsigned char* unknown_0_;
    void* location;
    void* dtor;
    Struct_0200ec44_2* unknown_c_;
    char* unknown_10_;
    char* unknown_14_;
    char* fp;
};

// USA: func_0200ec44
extern "C" ARM void func_0200ec44(Struct_0200ec44* context, long arg1, long arg2) {
    Struct_0200ec44_2* var0 = (Struct_0200ec44_2*)(context->fp + arg1);

    var0->location = context->location;
    var0->unknown_4_ = context->unknown_0_;
    var0->dtor = context->dtor;

    if (*context->unknown_0_ == '*') {
        var0->unknown_c_ = &var0->unknown_10_;
        var0->unknown_10_ = *(long*)context->location + arg2;
    } else {
        var0->unknown_c_ = (char*)context->location + arg2;
    }
}
