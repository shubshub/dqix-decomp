#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov025_021e7fb4_12 = 0x4 };
#else
enum { Enum_ov025_021e7fb4_12 = 0xc };
#endif

struct Struct_ov025_021e3c3c;
struct Struct_ov025_021ef988_7 {
    char unknown0[Enum_ov025_021e7fb4_12];
    Struct_ov025_021e3c3c* context;
};
extern Struct_ov025_021ef988_7 data_ov025_021ef988;
extern "C" void func_ov025_021e9d14(void* p);
extern "C" void func_ov025_021e9edc(void* p);

// USA: func_ov025_021e7fb4
extern "C" ARM int func_ov025_021e7fb4() {
    Struct_ov025_021e3c3c* p = data_ov025_021ef988.context;
    func_ov025_021e9d14(p);
    p = data_ov025_021ef988.context;
    func_ov025_021e9edc(p);
    return 1;
}
