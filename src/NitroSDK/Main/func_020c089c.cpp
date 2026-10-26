#include <globaldefs.h>

struct Struct_020c089c {
    unsigned int h0, h1, h2, h3, h4;
    unsigned int f14, f18, f1c;
};

// USA: func_020c089c
extern "C" ARM void func_020c089c(Struct_020c089c* ctx) {
    ctx->h0 = 0x67452301;
    ctx->h1 = 0xefcdab89;
    ctx->h2 = 0x98badcfe;
    ctx->h3 = 0x10325476;
    ctx->h4 = 0xc3d2e1f0;
    ctx->f14 = 0;
    ctx->f18 = 0;
    ctx->f1c = 0;
}
