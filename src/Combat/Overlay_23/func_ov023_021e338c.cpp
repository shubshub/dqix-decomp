#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov023_021e338c_1252 = 0x4e0, kFlagsOffset = 0x56c };
#else
enum { Enum_ov023_021e338c_1252 = 0x4e4, kFlagsOffset = 0x634 };
#endif

struct Struct_ov023_021e3030 {
    unsigned char unknown[Enum_ov023_021e338c_1252];
    unsigned char unknown_4e4_;
    unsigned char unknown_4e5_;
    signed char state;
    signed char unknown_4e7_;
    unsigned char unknown_4e8_[kFlagsOffset - Enum_ov023_021e338c_1252 - 4];
    unsigned short flags;
    unsigned char counter;
};

// USA: func_ov023_021e338c
extern "C" ARM void func_ov023_021e338c(char* arg0) {
    Struct_ov023_021e3030* transition = (Struct_ov023_021e3030*)arg0;
    transition->flags |= 0x1000;
}
