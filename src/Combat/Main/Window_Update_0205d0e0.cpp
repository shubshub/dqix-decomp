#include <globaldefs.h>

struct Struct_0205d0e0 {
    char unknown_0_[0xc4];
    unsigned char unknown_c4_;
    char unknown_c5_[0xd8 - 0xc5];
    unsigned char unknown_d8_0_ : 1;
    unsigned char unknown_d8_1_ : 7;
    unsigned char unknown_d9_;
    unsigned char unknown_da_;
    char unknown_db_[0xe0 - 0xdb];
};

struct Struct_0205d81c {
    char unknown_0_[0x98];
    int unknown_98_;
    struct Struct_0205d0e0* unknown_9c_;
    char unknown_a0_[0xb0 - 0xa0];
    unsigned char unknown_b0_;
    char unknown_b1_[0xb3 - 0xb1];
    unsigned char unknown_b3_;
    char unknown_b4_[0xb8 - 0xb4];
    unsigned char unknown_b8_;
};

struct Struct_0205d0e0_2;
extern "C" void* func_0205d888(struct Struct_0205d0e0_2* arg0);

extern "C" int func_0205c5b0(void* arg0, int arg1);
extern "C" unsigned int func_0205c710(unsigned char* arg0);
extern "C" void func_0205042c(unsigned char* arg0, unsigned char arg1);
extern "C" unsigned int func_0205c6e4(unsigned char* arg0);
extern "C" void func_02050440(unsigned char* arg0, int arg1);
extern "C" void func_0204c87c(void* arg0, int arg1);
extern "C" struct Struct_0205d0e0* func_0205d81c(struct Struct_0205d81c* arg0, int arg1);
struct Struct_0204ffc0_2;
extern "C" void func_0204ffc0(struct Struct_0204ffc0_2* arg0, int arg1);

// Main, originally func_0205d0e0 (USA 0x0205d0e0, EUR 0x0205d0f0, JPN 0x0205e410)
extern "C" ARM int Window_Update(void* objPtr, int val) {
    struct Struct_0205d81c* obj = (struct Struct_0205d81c*)objPtr;
    int ret;
    struct Elem_0205d81c* entry;
    unsigned char i;

    if (var0->unknown_98_ == 0) return 0;
    if (var0->unknown_9c_ == 0) return 0;

    var1 = 0;
    var2 = (struct Struct_0205d0e0*)func_0205d888((struct Struct_0205d0e0_2*)arg0);
    if (var2 != 0) {
        var1 = func_0205c5b0(arg0, arg1);
        if (var0->unknown_b0_ == var2->unknown_c4_) {
            if (var2->unknown_d8_0_) {
                func_0205042c((unsigned char*)var2, func_0205c710((unsigned char*)arg0));
                func_02050440((unsigned char*)var2, (unsigned char)func_0205c6e4((unsigned char*)arg0));
            }
        }
    }

    for (var3 = 0; var3 < var0->unknown_b3_; var3++) {
        func_0204c87c((void*)&var0->unknown_9c_[var3], arg1);
    }

    if (var0->unknown_b8_ != 0xff) {
        var2 = func_0205d81c(var0, var0->unknown_b8_);
        if (var2 != 0) {
            func_0204ffc0((struct Struct_0204ffc0_2*)var2, -1);
        }
        var0->unknown_b8_ = 0xff;
    }

    return var1;
}
