#include <globaldefs.h>
#include "World/Object3D.h"

extern "C" int func_ov017_021d60f4(int arg0);

struct Struct_0203cec4;
extern "C" void func_0203cec4(struct Struct_0203cec4* arg0, int arg1);
struct Struct_0203fc5c;
extern "C" int func_0203fc5c(struct Struct_0203fc5c* arg0, float arg1);

struct Struct_ov001_0216013c {
    int unknown_0_;
    char unknown_4_[0x8];
    void* unknown_c_;
};
struct Struct_ov001_02165880_40 {
    void* unknown_0_;
    struct Struct_ov001_0216013c* unknown_4_;
};
extern struct Struct_ov001_02165880_40 data_ov001_02165880;
extern int data_ov001_02165769;

struct Struct_ov001_0216013c_2 {
    char unknown_0_[0x14];
    void* unknown_14_;
};

// USA: func_ov001_0216013c
extern "C" ARM int func_ov001_0216013c(int arg0) {
    arg0 = func_ov017_021d60f4(arg0);
    int var0 = data_ov001_02165880.unknown_4_[arg0].unknown_0_;

    if (var0 == 2 || var0 == 6) {
        void* var1 = 0;
        if (data_ov001_02165880.unknown_4_ != 0) {
            var1 = data_ov001_02165880.unknown_4_[arg0].unknown_c_;
        }
        if (var1 == 0) {
            return 0;
        }
        if (((struct Struct_ov001_0216013c_2*)var1)->unknown_14_ != 0) {
            func_0203cec4((struct Struct_0203cec4*)((struct Struct_ov001_0216013c_2*)var1)->unknown_14_, 0);
        }
        if (((struct Struct_ov001_0216013c_2*)var1)->unknown_14_ != 0) {
            func_0203fc5c((struct Struct_0203fc5c*)((struct Struct_ov001_0216013c_2*)var1)->unknown_14_, 1.0f);
        }
    } else if (var0 == 1 || var0 == 0 || (unsigned int)(var0 - 4) <= 1) {
        void* var2 = 0;
        if (data_ov001_02165880.unknown_4_ != 0) {
            var2 = data_ov001_02165880.unknown_4_[arg0].unknown_c_;
        }
        if (var2 == 0) {
            return 0;
        }
        ((Object3D*)obj2)->SetAnimationByName((char const*)&data_ov001_02165769, 0);
    }

    return 1;
}
