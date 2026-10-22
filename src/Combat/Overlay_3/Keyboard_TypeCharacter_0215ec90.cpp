#include <globaldefs.h>

struct Struct_ov003_0215ec90_2 {
    char unknown_0_[4];
    int unknown_4_;
    int unknown_8_;
    char unknown_c_[3];
    unsigned char unknown_f_;
};

struct Struct_0204254c {
    char unknown_0_[4];
    signed char unknown_4_;
};

struct Struct_ov003_0215ec90 {
    struct Struct_ov003_0215ec90_2* unknown_0_;
    char unknown_4_[4];
    char* unknown_8_;
    int unknown_c_;
    char unknown_10_[4];
    int unknown_14_;
    char unknown_18_[0x1e - 0x18];
    unsigned char unknown_1e_;
    unsigned char unknown_1f_;
    unsigned char unknown_20_;
};

extern "C" void __clear(void* arg0, int arg1);
extern "C" int func_020424e4(int arg0, int arg1);
extern "C" int func_020426bc(void* arg0, void* arg1, int arg2);
extern "C" void func_02042764(void* arg0, void* arg1, int arg2);
extern "C" int func_020420e8(void* arg0, int arg1);
extern "C" struct Struct_0204254c* func_0204254c(int arg0, int arg1);

extern unsigned char data_ov003_0217f3b0[];

// USA: func_ov003_0215ec90
extern "C" ARM int func_ov003_0215ec90(struct Struct_ov003_0215ec90* arg0) {
    unsigned char var0[0x100];
    unsigned char var1[0x100];
    unsigned char* var2;
    int var3;
    int var4;
    struct Struct_0204254c* var5;
    int var6;
    int var7;
    int var8;
    char* var9;
    int var10;
    int var11;
    int var12;
    struct Struct_ov003_0215ec90_2* var13 = arg0->unknown_0_;
    if (var13 != 0) {
        if (var13->unknown_f_ != 0) {
            return 0xd;
        }

        var11 = arg0->unknown_1f_;
        var9 = arg0->unknown_8_;
        var3 = var13->unknown_4_;
        if (data_ov003_0217f3b0[arg0->unknown_20_] == arg0->unknown_1e_) {
            var3 = var13->unknown_8_;
        }
        var10 = arg0->unknown_c_;
        var12 = arg0->unknown_14_;

        __clear(var0, 0x100);
        var4 = func_020424e4(var3, var11);
        var8 = func_020426bc(var9, var0, var11);
        var2 = var0;
        for (var7 = 0; var7 < var12; var7++, var2++) {
            if (var7 == var12 - 1) {
                unsigned char var14 = *var2;
                *var2 = var4;
                if (var10 != 0) {
                    __clear(var1, 0x100);
                    func_02042764(var0, var1, var11);
                    if (var10 < func_020420e8(var1, 0)) {
                        *var2 = var14;
                        break;
                    }
                }
                func_02042764(var0, var9, var11);
                arg0->unknown_20_ = 0;
                return (var12 <= var8 + 1) ? 3 : 2;
            }
            if (*var2 == 0) {
                if (var10 != 0) {
                    var6 = func_020420e8(var9, 0);
                    var5 = func_0204254c(var3, 0);
                    if (var5 != 0) {
                        var6 += var5->unknown_4_ + 1;
                    }
                    if (var10 < var6) {
                        break;
                    }
                }
                *var2 = var4;
                func_02042764(var0, var9, var11);
                arg0->unknown_20_ = 0;
                return (var12 <= var8 + 1) ? 3 : 2;
            }
        }
    }
    return 0;
}
