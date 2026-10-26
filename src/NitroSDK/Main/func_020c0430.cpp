#include <globaldefs.h>
#include <NitroSDK/Memory.h>

struct Struct_020c0430 {
    unsigned long a, b, c, d;
    unsigned long long length;
    union {
        unsigned long unknown_18_[16];
        unsigned char unknown1_18_[64];
    };
};

extern "C" void func_020c0368(Struct_020c0430* context, const void* input, unsigned long length);
extern "C" void func_020c04e8(Struct_020c0430* context);

extern unsigned char data_020f1f8c;

// USA: func_020c0430
extern "C" ARM void func_020c0430(unsigned char* digest, Struct_020c0430* context) {
    unsigned long long var0;
    unsigned long index;
    unsigned long var2;

    var0 = context->length << 3;
    func_020c0368(context, &data_020f1f8c, 1);
    index = (unsigned long)(context->length & (64 - 1));
    var2 = 64 - index;
    if (var2 < sizeof(var0)) {
        VectorizedMemset(&context->unknown1_18_[index], 0, var2);
        func_020c04e8(context);
        index = 0;
        var2 = 64;
    }
    if (var2 > sizeof(var0))
        VectorizedMemset(&context->unknown1_18_[index], 0, var2 - sizeof(var0));

    context->unknown_18_[14] = (unsigned long)var0;
    context->unknown_18_[15] = (unsigned long)(var0 >> 32);
    func_020c04e8(context);
    VectorizedInvertedMemcpy(context, digest, 16);
    VectorizedMemset(context, 0, sizeof(Struct_020c0430));
}
