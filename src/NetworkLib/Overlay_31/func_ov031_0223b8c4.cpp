#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"


struct Struct_ov031_0223b8c4 {
    Struct_ov031_0223b8c4* unknown_0_;
    Struct_ov031_0223b8c4* unknown_4_;
    unsigned char* unknown_8_;
    unsigned char unknown_c_;
    char unknown_d_[3];
};

struct Struct_ov031_0223b8c4_2 {
    char unknown_0_[0x200];
    Struct_ov031_0223b8c4 unknown_200_;
    Struct_ov031_0223b8c4 unknown_210_;
    int unknown_220_;
    void* unknown_224_;
};

extern AllocationRegion0223b8c4* data_ov031_02290d28;
extern "C" AllocationNode0223b8c4* func_ov031_0223bfa0(void*);
extern "C" void func_ov031_0223d8d8(AllocationNode0223b8c4*, AllocationNode0223b8c4*);
extern "C" void HaltSystem();

static inline Struct_ov031_0223b8c4_2* inline_ov031_0223b8c4(int arg0) {
    Struct_ov031_0223b8c4_2* var0 = data_ov031_02290d28;
    var0 += arg0;
    return var0;
}

// USA: func_ov031_0223b8c4
extern "C" ARM Struct_ov031_0223b8c4* func_ov031_0223b8c4(int arg0, int arg1, int arg2) {
    Struct_ov031_0223b8c4* var0 = func_ov031_0223bfa0(inline_ov031_0223b8c4(arg0)->unknown_224_);
    Struct_ov031_0223b8c4* var1;
    unsigned int var2 = DisableSpecificInterrupts(1);
    if (arg2) {
        var1 = &inline_ov031_0223b8c4(arg0)->unknown_200_;
        if (var1 != &inline_ov031_0223b8c4(arg0)->unknown_210_) {
            do {
                Struct_ov031_0223b8c4* var3 = var1->unknown_4_;
                unsigned char* var4 = var1->unknown_8_ + var1->unknown_c_ * 8;
                if (var4 + arg1 * 8 <= var3->unknown_8_) {
                    var0->unknown_8_ = var4;
                    func_ov031_0223d8d8(var3, var0);
                    break;
                }
                var1 = var3;
            } while (var1 != &data_ov031_02290d28[arg0].unknown_210_);
        }
        if (node == &data_ov031_02290d28[region].back) HaltSystem();
    } else {
        var1 = &inline_ov031_0223b8c4(arg0)->unknown_210_;
        if (var1 != &inline_ov031_0223b8c4(arg0)->unknown_200_) {
            do {
                Struct_ov031_0223b8c4* var5 = var1->unknown_0_;
                unsigned char* var6 = var1->unknown_8_ - arg1 * 8;
                if (var6 >= var5->unknown_8_ + var5->unknown_c_ * 8) {
                    var0->unknown_8_ = var6;
                    func_ov031_0223d8d8(var1, var0);
                    break;
                }
                var1 = var5;
            } while (var1 != &data_ov031_02290d28[arg0].unknown_200_);
        }
        if (node == &data_ov031_02290d28[region].front) HaltSystem();
    }
    EnableSpecificInterrupts(var2);
    var0->unknown_c_ = arg1;
    return var0;
}
