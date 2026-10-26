#include <globaldefs.h>

struct Struct_ov000_02175808 {
    char unknown0[8];
    unsigned short argument;
};
struct Struct_ov025_021e3c3c {
    char unknown0[0x74a];
    unsigned short unknown_74a_;
};
struct Struct_ov025_021ef988_7 {
#if defined(jpn)
    char unknown0[4];
#else
    char unknown0[0xc];
#endif
    Struct_ov025_021e3c3c* context;
};
extern Struct_ov025_021ef988_7 data_ov025_021ef988;

// USA: func_ov025_021e85a8
extern "C" ARM int func_ov025_021e85a8(Struct_ov000_02175808* command) {
    data_ov025_021ef988.context->unknown_74a_ = command->argument;
    return 1;
}
