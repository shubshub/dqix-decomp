#include <globaldefs.h>

struct Struct_020bb964 {
    int unk_0;
    unsigned int unknown_4_;
};

// USA: func_020bb964
extern "C" ARM unsigned short func_020bb964(Struct_020bb964* ctx, unsigned int value) {
    return (unsigned short)((value + 1) % ctx->unknown_4_);
}
