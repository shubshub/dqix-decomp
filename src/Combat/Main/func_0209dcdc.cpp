#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_0209dcdc_4 {
    signed int unknown_0_0_:3;
    signed int unknown_0_3_:3;
    signed int unknown_0_6_:3;
    signed int unknown_1_1_:3;
    signed int unknown_1_4_:3;
    signed int unknown_1_7_:3;
    signed int unknown_2_2_:3;
    signed int unknown_2_5_:3;
    signed int unknown_3_0_:3;
    signed int unknown_3_3_:3;
    unsigned int padding:2;
};
struct Struct_0209dcdc {
    unsigned short style:2;
    unsigned short padding:14;
};
struct Struct_0209dcdc_2 {
    unsigned char padding:4;
    unsigned char category:4;
};
struct Struct_0209dcdc_3 {
    unsigned long long unknown_0_[2];
    unsigned char unknown_10_[8];
    Struct_0209dcdc styles[2];
    Struct_0209dcdc_2 unknown_1c_[2];
    unsigned char unknown_1e_[0xa];
    Struct_0209dcdc_4 unknown_28_[2];
};

// USA: func_0209dcdc
extern "C" ARM int func_0209dcdc(void* manager, Struct_0209dcdc_3* record, int alternate, unsigned int arg3) {
    unsigned int category;
    unsigned int var1;
    unsigned int var2;
    unsigned int style;
    Struct_0209dcdc_4 var4;
    if (alternate == 0) {
        style = record->styles[0].style;
        category = record->unknown_1c_[0].category;
        unsigned long long flags = record->unknown_0_[0];
        var1 = flags;
        var2 = flags >> 32;
        memcpy(&var4, &record->unknown_28_[0], sizeof(var4));
    } else {
        style = record->styles[1].style;
        category = record->unknown_1c_[1].category;
        unsigned long long flags = record->unknown_0_[1];
        var1 = flags;
        var2 = flags >> 32;
        memcpy(&var4, &record->unknown_28_[1], sizeof(var4));
    }
    if ((arg3 & 0x1) && (var1 & 2) && style == 1) return 1;
    if ((arg3 & 0x2) && (var1 & 2) && style == 2) return 1;
    if ((arg3 & 0x4) && (var1 & 0x400) && var4.unknown_0_0_ == 2) return 1;
    if ((arg3 & 0x8) && (var1 & 0x400) && var4.unknown_0_0_ == 1) return 1;
    if ((arg3 & 0x10) && (var1 & 0x400) && var4.unknown_0_0_ == -1) return 1;
    if ((arg3 & 0x20) && (var1 & 0x400) && var4.unknown_0_0_ == -2) return 1;
    if ((arg3 & 0x40) && (var1 & 0x800) && var4.unknown_0_3_ == 2) return 1;
    if ((arg3 & 0x80) && (var1 & 0x800) && var4.unknown_0_3_ == 1) return 1;
    if ((arg3 & 0x100) && (var1 & 0x800) && var4.unknown_0_3_ == -1) return 1;
    if ((arg3 & 0x200) && (var1 & 0x800) && var4.unknown_0_3_ == -2) return 1;
    if ((arg3 & 0x400) && (var1 & 0x1000) && var4.unknown_0_6_ == 2) return 1;
    if ((arg3 & 0x800) && (var1 & 0x1000) && var4.unknown_0_6_ == 1) return 1;
    if ((arg3 & 0x1000) && (var1 & 0x1000) && var4.unknown_0_6_ == -1) return 1;
    if ((arg3 & 0x2000) && (var1 & 0x1000) && var4.unknown_0_6_ == -2) return 1;
    if ((arg3 & 0x4000) && (var1 & 0x2000) && var4.unknown_1_1_ == 1) return 1;
    if ((arg3 & 0x8000) && (var1 & 0x4000) && var4.unknown_1_4_ == 2) return 1;
    if ((arg3 & 0x10000) && (var1 & 0x4000) && var4.unknown_1_4_ == 1) return 1;
    if ((arg3 & 0x20000) && (var1 & 0x8000) && var4.unknown_1_7_ == 2) return 1;
    if ((arg3 & 0x40000) && (var1 & 0x8000) && var4.unknown_1_7_ == 1) return 1;
    if ((arg3 & 0x80000) && (var1 & 0x10000) && var4.unknown_2_2_ == 2) return 1;
    if ((arg3 & 0x100000) && (var1 & 0x10000) && var4.unknown_2_2_ == 1) return 1;
    if ((arg3 & 0x200000) && (var1 & 0x10000) && var4.unknown_2_2_ == -1) return 1;
    if ((arg3 & 0x400000) && (var1 & 0x10000) && var4.unknown_2_2_ == -2) return 1;
    if ((arg3 & 0x800000) && (var1 & 0x20000) && var4.unknown_2_5_ == 2) return 1;
    if ((arg3 & 0x1000000) && (var1 & 0x20000) && var4.unknown_2_5_ == 1) return 1;
    if ((arg3 & 0x2000000) && (var2 & 1) && var4.unknown_3_0_ == 2) return 1;
    if ((arg3 & 0x4000000) && (var1 & 0x2000000) && var4.unknown_3_3_ == 2) return 1;
    if ((arg3 & 0x8000000) && (var1 & 0x800000) && category == 1) return 1;
    if ((arg3 & 0x10000000) && (var1 & 0x800000) && category == 2) return 1;
    if ((arg3 & 0x20000000) && (var1 & 0x800000) && category == 3) return 1;
    return 0;
}
