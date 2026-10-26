#include <globaldefs.h>
#include "GameState/GameState.h"

void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021c9d2c {
    unsigned char unknown_0_0_ : 3;
    unsigned char unknown_0_3_ : 1;
    unsigned char unknown_0_4_ : 1;
    unsigned char unknown_1_;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    unsigned short unknown_8_;
    unsigned int unknown_c_;
};

struct Struct_ov017_021c9d2c_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[3];
    Struct_ov017_021c9d2c unknown_4_;
};

static inline int inline_ov017_021c9d2c(int arg0) {
    return arg0 >= 0 && arg0 <= 3;
}

// USA: func_ov017_021c9d2c
extern "C" ARM void func_ov017_021c9d2c(int slot, unsigned short a1, unsigned short a2, unsigned short a3, int a4, unsigned int a5, unsigned char a6, int flagA, int flagB) {
    void* p = LinkMessageQueue_GetInstance();
    GameState::GetInstance();
    if (inline_ov017_021c9d2c(arg0)) {
        Struct_ov017_021c9d2c_2 var1;
        var1.unknown_0_ = 4;
        Struct_ov017_021c9d2c* var2 = &var1.unknown_4_;
        var2->unknown_0_0_ = arg0;
        var2->unknown_2_ = arg1;
        var2->unknown_6_ = arg3;
        var2->unknown_4_ = arg2;
        var2->unknown_8_ = arg4;
        var2->unknown_1_ = arg6;
        var2->unknown_c_ = arg5;
        var2->unknown_0_3_ = arg7;
        var2->unknown_0_4_ = arg8;
        func_0205e330(var0, &var1, 0);
    }
}
