#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov025_021e85c8_12 = 0x4 };
#else
enum { Enum_ov025_021e85c8_12 = 0xc };
#endif

extern "C" int func_ov025_021eb6fc(void* p, int flag);

struct Struct_ov025_021ef988_39 {
    char unknown_0_[Enum_ov025_021e85c8_12];
    void* unknown_c_;
};
extern Struct_ov025_021ef988_39 data_ov025_021ef988;

// USA: func_ov025_021e85c8
extern "C" ARM int func_ov025_021e85c8(void) {
    func_ov025_021eb6fc(data_ov025_021ef988.unknown_c_, 1);
    return 1;
}
