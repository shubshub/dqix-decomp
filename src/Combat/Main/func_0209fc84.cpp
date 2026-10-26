#include <globaldefs.h>

struct Struct_0209d38c {
    char pad0[4];
    char* data;
    char pad2[0x90];
    int field98;
};

// USA: func_0209fc84
extern "C" ARM int func_0209fc84(struct Struct_0209d38c* ctx, int selector) {
    return (selector == 0) ? *(unsigned char*)(ctx->data + 0x8e07) : ctx->field98;
}
