#include <globaldefs.h>
#include "NitroSDK/Memory.h"
#include "std_library_functions.h"

struct Struct_ov031_0222faac {
    unsigned char padding0[0x40];
    unsigned char name[0x80];
    unsigned char unknown_c0_[4];
    unsigned char unknown_c4_[4];
    unsigned char unknown_c8_[4];
    unsigned char unknown_cc_[4];
    unsigned char unknown_d0_[0x16];
    unsigned char nameLength : 2;
    unsigned char unknown_e6_2_ : 6;
    unsigned char unknown_e7_[9];
    unsigned char unknown_f0_[4];
    unsigned char unknown_f4_;
    unsigned char unknown_f5_;
    unsigned char unknown_f6_;
};

extern "C" Struct_ov031_0222faac* func_ov031_02235c70();
extern "C" void func_ov031_0222ff34(unsigned char*, int);
extern "C" void func_ov031_02230088(unsigned char*, int);

// USA: func_ov031_0222faac
extern "C" ARM void func_ov031_0222faac(int index, int row) {
    Struct_ov031_0222faac* info = func_ov031_02235c70();
    switch (index) {
    case 0:
        func_ov031_0222ff34(info->name, row);
        return;
    case 1: {
        int length;
        unsigned char var2[0x21];
        switch (info->nameLength) {
        case 0: return;
        case 1: length = 10; break;
        case 2: length = 26; break;
        case 3: length = 32; break;
        }
        if (info->unknown_e6_2_ == 1) length /= 2;
        VectorizedMemset(var2, 0, sizeof(var2));
        memset(var2, '*', length);
        func_ov031_0222ff34(var2, row);
        return;
    }
    case 3:
        if (info->unknown_f5_ != 0) return;
        func_ov031_02230088(info->unknown_c0_, row);
        return;
    case 4:
        if (info->unknown_f5_ != 0) return;
        func_ov031_02230088(info->unknown_f0_, row);
        return;
    case 5:
        if (info->unknown_f5_ != 0) return;
        func_ov031_02230088(info->unknown_c4_, row);
        return;
    case 7:
        if (info->unknown_f6_ != 0) return;
        func_ov031_02230088(info->unknown_c8_, row);
        return;
    case 8:
        if (info->unknown_f6_ != 0) return;
        func_ov031_02230088(info->unknown_cc_, row);
        return;
    }
}
