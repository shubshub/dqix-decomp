#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov025_021e4ec8_12 = 0x4 };
#else
enum { Enum_ov025_021e4ec8_12 = 0xc };
#endif

struct Struct_ov025_021e3c3c;
struct Struct_ov025_021ef988_7 {
    char unknown0[Enum_ov025_021e4ec8_12];
    Struct_ov025_021e3c3c* context;
};
extern Struct_ov025_021ef988_7 data_ov025_021ef988;

extern "C" void func_ov025_021e8af8(void* param);

// USA: func_ov025_021e4ec8
extern "C" ARM int func_ov025_021e4ec8(void) {
    func_ov025_021e8af8(data_ov025_021ef988.context);
    return 1;
}
