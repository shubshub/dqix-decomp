#include <globaldefs.h>

struct Struct_020b0e6c;
extern "C" int func_020b0e6c(struct Struct_020b0e6c* obj, unsigned int key);

struct Struct_020b0eb4;
extern "C" void* func_020b0eb4(struct Struct_020b0eb4** slot, unsigned int key);

struct Struct_020b1d70_3 {
    unsigned char b0;
    unsigned char b1;
    unsigned short stride;
    unsigned char pad4[3];
    unsigned char mode;
};

struct Struct_020b1d70_2 {
    unsigned char pad0[2];
    unsigned short unknown_2_;
    unsigned char pad1[4];
    struct Struct_020b1d70_3* header;
};

struct Struct_020b1d70_4 {
    signed char unknown_0_;
    unsigned char unknown_1_;
    signed char unknown_2_;
};

struct Struct_020b1d70;

struct Struct_020b1d70_5 {
    void (*fn)(struct Struct_020b1d70* paramA, struct Struct_020b1d70_2** paramB, int a, int b, int e, void* loc);
};

struct Struct_020b1d70 {
    unsigned char pad[0x14];
    struct Struct_020b1d70_5* cb;
};

struct Struct_020b1d70_6 {
    struct Struct_020b1d70_4* unknown_0_;
    void* unknown_4_;
};

// USA: func_020b1d70
extern "C" ARM int func_020b1d70(struct Struct_020b1d70* arg0, struct Struct_020b1d70_2** arg1, int arg2, int arg3, int arg4, unsigned short arg5) {
    int key = func_020b0e6c((struct Struct_020b0e6c*)arg1, arg5);
    if (key == 0xffff) {
        key = (*arg1)->unknown_2_;
    }

    struct Struct_020b1d70_4* result = (struct Struct_020b1d70_4*)func_020b0eb4((struct Struct_020b0eb4**)arg1, key);

    struct Struct_020b1d70_6 local;
    local.unknown_0_ = result;
    local.unknown_4_ = (char*)(*arg1)->header + 8 + key * (*arg1)->header->stride;

    struct Struct_020b1d70_3* header = (*arg1)->header;
    switch (header->mode) {
    case 0:
    case 7:
        arg2 += result->unknown_0_;
        break;
    case 1:
    case 2:
        arg2 -= header->b0;
        arg3 += result->unknown_0_;
        break;
    case 3:
    case 4:
        arg2 -= result->unknown_0_ + result->unknown_1_;
        arg3 -= header->b1;
        break;
    case 5:
    case 6:
        arg3 -= result->unknown_0_ + header->b1;
        break;
    default:
        break;
    }

    arg0->cb->fn(arg0, arg1, arg2, arg3, arg4, &local);

    return local.unknown_0_->unknown_2_;
}
