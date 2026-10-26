#include <globaldefs.h>

extern "C" void* func_020d41d8(void);
extern "C" int func_020d424c(int a, int b, int c, int d);
extern "C" void func_020d404c(int index, int value);
extern "C" int func_020d4168(void* a, unsigned int b);

struct Struct_020d5254 {
    int field0;
    unsigned short type;
    unsigned short field6;
    unsigned char b8, unknown_9_, unknown_a_, unknown_b_, unknown_c_, unknown_d_;
};

struct Struct_020d5254_2 {
    unsigned short tag;
    unsigned short type;
    int field0;
    unsigned short field6;
    unsigned char b8, unknown_b_, unknown_c_, unknown_d_, unknown_e_, unknown_f_;
};


// USA: func_020d5254
extern "C" ARM int func_020d5254(int a0, struct Struct_020d5254* ctx) {
    int r = func_020d424c(3, 2, 3, 5);
    if (r != 0) {
        return r;
    }
    if (ctx == NULL) {
        return 6;
    }
    if (ctx->field0 == 0) {
        return 6;
    }
    if (ctx->type < 1 || ctx->type > 0xe) {
        return 6;
    }
    func_020d404c(0xa, a0);
    struct Struct_020d5254_2 buf;
    buf.tag = 0xa;
    buf.type = ctx->type;
    buf.field0 = ctx->field0;
    buf.field6 = ctx->field6;
    buf.b8 = ctx->b8;
    buf.unknown_b_ = ctx->unknown_9_;
    buf.unknown_c_ = ctx->unknown_a_;
    buf.unknown_d_ = ctx->unknown_b_;
    buf.unknown_e_ = ctx->unknown_c_;
    buf.unknown_f_ = ctx->unknown_d_;
    r = func_020d4168(&buf, 0x10);
    return (r == 0) ? 2 : r;
}
