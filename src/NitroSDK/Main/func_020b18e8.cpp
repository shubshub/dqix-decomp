#include <globaldefs.h>

struct Struct_020b18e8 {
    void *dest;
    int width;
    int height;
    unsigned char depth;
};

extern "C" void MIi_CpuClearFast(unsigned int value, void *dest, int count);

// USA: func_020b18e8
extern "C" ARM void func_020b18e8(struct Struct_020b18e8 *ctx, unsigned int val) {
    int depth = ctx->depth;
    if (depth == 4) {
        val = val | (val << 4);
        val = val | (val << 8);
        val = val | (val << 16);
    } else {
        val = val | (val << 8);
        val = val | (val << 16);
    }
    {
        int wh = ctx->width * ctx->height;
        int d8 = (depth << 6) / 8;
        MIi_CpuClearFast(val, ctx->dest, wh * d8);
    }
}
