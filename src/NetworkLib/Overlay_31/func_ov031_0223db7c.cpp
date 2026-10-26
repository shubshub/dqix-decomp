#include <globaldefs.h>

#include "NitroSDK/Interrupts.h"

struct Struct_ov031_0223db7c {
    Struct_ov031_0223db7c* unknown_0_;
    Struct_ov031_0223db7c* unknown_4_;
};

struct Struct_ov031_0223db7c_2 {
    Struct_ov031_0223db7c unknown_0_;
    unsigned short unknown_8_;
    unsigned short unknown_a_;
};

struct Struct_ov031_0223db7c_3 {
    Struct_ov031_0223db7c_2 unknown_0_[32];
    Struct_ov031_0223db7c_2 unknown_180_;
    Struct_ov031_0223db7c_2 unknown_18c_;
    void* unknown_198_;
    void* unknown_19c_;
};

struct Struct_ov031_0223db7c_4 {
    Struct_ov031_0223db7c_3 unknown_0_[2];
};

extern Struct_ov031_0223db7c_4* data_ov031_02290d64;
extern "C" void* func_ov031_0223bfa0(void*);
extern "C" void func_ov031_0223d8d8(void*, void*);
extern "C" void HaltSystem();

static inline Struct_ov031_0223db7c_3* inline_ov031_0223db7c(int arg0) {
    Struct_ov031_0223db7c_3* var0 = data_ov031_02290d64->unknown_0_;
    var0 += arg0;
    return var0;
}

// USA: func_ov031_0223db7c
extern "C" ARM void* func_ov031_0223db7c(int arg0, int arg1, unsigned char arg2, int* arg3) {
    Struct_ov031_0223db7c_2* var0 = static_cast<Struct_ov031_0223db7c_2*>(func_ov031_0223bfa0(inline_ov031_0223db7c(arg0)->unknown_19c_));
    Struct_ov031_0223db7c_2* var1;
    Struct_ov031_0223db7c_2* var2;
    unsigned long var3;
    int var4;
    int var5 = ((arg1 + 3) & ~3) >> 2;
    var0->unknown_a_ = var5;
    var3 = DisableSpecificInterrupts(1);
    if (arg2) {
        var1 = &inline_ov031_0223db7c(arg0)->unknown_180_;
        if (var1 != &inline_ov031_0223db7c(arg0)->unknown_18c_) {
            do {
                var2 = (Struct_ov031_0223db7c_2*)var1->unknown_0_.unknown_4_;
                var4 = var1->unknown_8_ + var1->unknown_a_;
                if (var4 + var5 <= var2->unknown_8_) {
                    var0->unknown_8_ = var4;
                    func_ov031_0223d8d8(var2, var0);
                    break;
                }
                var1 = var2;
            } while (var1 != &data_ov031_02290d64->unknown_0_[arg0].unknown_18c_);
        }
        if (cursor == &data_ov031_02290d64->pools[poolIndex].last) {
            HaltSystem();
        }
    } else {
        var1 = &inline_ov031_0223db7c(arg0)->unknown_18c_;
        if (var1 != &inline_ov031_0223db7c(arg0)->unknown_180_) {
            do {
                var2 = (Struct_ov031_0223db7c_2*)var1->unknown_0_.unknown_0_;
                var4 = var1->unknown_8_ - var5;
                if (var4 >= var2->unknown_8_ + var2->unknown_a_) {
                    var0->unknown_8_ = var4;
                    func_ov031_0223d8d8(var1, var0);
                    break;
                }
                var1 = var2;
            } while (var1 != &data_ov031_02290d64->unknown_0_[arg0].unknown_180_);
        }
        if (cursor == &data_ov031_02290d64->pools[poolIndex].first) {
            HaltSystem();
        }
    }
    *arg3 = var0->unknown_8_;
    EnableSpecificInterrupts(var3);
    return var0;
}
