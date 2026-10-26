#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov025_021e4a90_28 = 0xc };
#else
enum { Enum_ov025_021e4a90_28 = 0x1c };
#endif

struct Struct_ov025_021ef988_12 {
    char pad0[Enum_ov025_021e4a90_28];
    unsigned int flags;
};

extern struct Struct_ov025_021ef988_12 data_ov025_021ef988;

// USA: func_ov025_021e4a90
extern "C" ARM int func_ov025_021e4a90(void) {
    data_ov025_021ef988.flags |= 0x100;
    return 1;
}
