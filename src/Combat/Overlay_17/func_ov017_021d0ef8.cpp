#include <globaldefs.h>
#include "std_library_functions.h"

void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021d0ef8 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned char unknown_2_0_ : 7;
    unsigned char unknown_2_7_ : 1;
    unsigned char unknown_3_[12];
};

struct Struct_ov017_021d0ef8_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[3];
    Struct_ov017_021d0ef8 unknown_4_;
};

// USA: func_ov017_021d0ef8
extern "C" ARM void func_ov017_021d0ef8(int a1, unsigned char* a2, int a3, int a4, int* outLen) {
    void* data = LinkMessageQueue_GetInstance();

    Struct_ov017_021d0ef8_2 var1;
    Struct_ov017_021d0ef8* var2 = &var1.unknown_4_;
    var2->unknown_0_ = (unsigned char)arg0;
    var1.unknown_0_ = 0xab;
    int var3 = arg2 - arg3;

    *arg4 = var3;
    if (var3 > 12) {
        *arg4 = 12;
    } else {
        var2->unknown_2_7_ = 1;
    }
    var2->unknown_2_0_ = (unsigned char)*arg4;
    var2->unknown_1_ = (unsigned char)arg3;
    memcpy(var2->unknown_3_, arg1 + arg3, *arg4);

    func_0205e330(var0, &var1, 0);
}
