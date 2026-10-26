#include <globaldefs.h>

extern "C" void func_02098364(void* entry);

struct Struct_020982b4_2 {
    unsigned char pad[0xe8];
};

struct Struct_020982b4 {
    unsigned char pad0[0xb34];
    int unknown_b34_;
    int unknown_b38_;
    int unknown_b3c_;
    unsigned char unknown_b40_;
    unsigned char unknown_b41_;
    unsigned char unknown_b42_;
    unsigned char unknown_b43_;
    int unknown_b44_;
    int unknown_b48_;
    int unknown_b4c_;
    int unknown_b50_;
    int unknown_b54_;
    int unknown_b58_;
    int unknown_b5c_;
    unsigned char unknown_b60_;
    unsigned char unknown_b61_;
    unsigned char unknown_b62_;
};

// USA: func_020982b4
extern "C" ARM void func_020982b4(Struct_020982b4_2* arr) {
    Struct_020982b4* ctx = (Struct_020982b4*)((char*)arr + 0x1000);
    int zero = 0;
    ctx->unknown_b34_ = zero;
    ctx->unknown_b38_ = zero;
    ctx->unknown_b3c_ = 1;
    ctx->unknown_b40_ = 1;
    ctx->unknown_b41_ = 1;
    ctx->unknown_b42_ = zero;
    ctx->unknown_b44_ = zero;
    ctx->unknown_b48_ = zero;
    ctx->unknown_b4c_ = zero;
    ctx->unknown_b50_ = zero;
    ctx->unknown_b54_ = zero;
    ctx->unknown_b60_ = 1;
    ctx->unknown_b61_ = zero;
    ctx->unknown_b62_ = zero;
    *(unsigned short*)((char*)arr + 0x1b64) = zero;
    ctx->unknown_b58_ = zero;
    Struct_020982b4_2* p = arr;
    ctx->unknown_b5c_ = zero;
    for (int i = 0; i < 30; i++, p++) {
        func_02098364(p);
    }
    for (int i = 0; i < 3; i++) {
        *(int*)((char*)arr + i * 4 + 0x1b68) = -1;
    }
    *(int*)((char*)arr + 0x1b74) = 0;
}
