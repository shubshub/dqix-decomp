#include <globaldefs.h>

struct Struct_020813ec_3 {
    char pad0[0xa];
    short unknown_a_;
    short unknown_c_;
    short unknown_e_;
    short unknown_10_;
    unsigned char unknown_12_0_ : 4;
    unsigned char unknown_12_4_ : 4;
    char pad1[2];
    unsigned char unknown_15_;
};

extern "C" void func_0204f174(void* target, short a, short b, short c, int d, int e, int f, int g, int h);
extern "C" void func_0204fae8(void* target);

struct Struct_02081498 {
    char pad[4];
    short* entries;
    char pad2[0x14 - 8];
    unsigned char count;
};
extern "C" void func_02081530(void* unused, void* ctx, struct Struct_02081498* list);

// USA: func_02081498
extern "C" ARM void func_02081498(void* obj, void* ctx, struct Struct_020813ec_3* p) {
    int var0 = (p->unknown_15_ & 2) != 0;
    func_0204f174(ctx, p->unknown_a_, p->unknown_c_, p->unknown_e_, p->unknown_10_, p->unknown_12_0_, p->unknown_12_4_, var0, 0);
    if (p->unknown_15_ & 1) {
        func_0204fae8(ctx);
    }
    func_02081530(obj, ctx, (struct Struct_02081498*)p);
}
