#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov023_021e3030_1252 = 0x4e0, kFlagsOffset = 0x56c };
#else
enum { Enum_ov023_021e3030_1252 = 0x4e4, kFlagsOffset = 0x634 };
#endif

struct Struct_ov023_021e3030 {
    unsigned char unknown[Enum_ov023_021e3030_1252];
    unsigned char unknown_4e4_;
    unsigned char unknown_4e5_;
    signed char state;
    signed char unknown_4e7_;
    unsigned char unknown_4e8_[kFlagsOffset - Enum_ov023_021e3030_1252 - 4];
    unsigned short flags;
    unsigned char counter;
};

extern "C" Struct_ov023_021e3030* func_ov023_021e4e3c(Struct_ov023_021e3030* obj);
extern "C" void func_ov023_021e33b4(void* obj);
extern "C" void func_ov023_021e3db0(void* obj);
extern "C" void func_ov023_021e3f34(void* obj);

// USA: func_ov023_021e3030
extern "C" ARM void func_ov023_021e3030(Struct_ov023_021e3030* obj) {
    func_ov023_021e4e3c(obj);
    switch (obj->state) {
    case 0:
        func_ov023_021e33b4(obj);
        break;
    case 3:
        func_ov023_021e3db0(obj);
        break;
    case 1:
        func_ov023_021e3f34(obj);
        break;
    }
}
