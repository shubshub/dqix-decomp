#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov025_021e7450_12 = 0x4 };
#else
enum { Enum_ov025_021e7450_12 = 0xc };
#endif

struct Struct_ov025_021e7450 {
    char pad[0x26];
    unsigned short unknown_26_;
};

struct Struct_ov025_021e7450_2 {
    char pad[0x540];
    struct Struct_ov025_021e7450 sub;

    struct Struct_ov025_021e7450* inline_ov025_021e7450() { return &sub; }
};

struct Struct_ov025_021ef988_28 {
    char pad[Enum_ov025_021e7450_12];
    struct Struct_ov025_021e7450_2* base;
};
extern struct Struct_ov025_021ef988_28 data_ov025_021ef988;

// USA: func_ov025_021e7450
extern "C" ARM int func_ov025_021e7450(void* obj) {
    data_ov025_021ef988.base->inline_ov025_021e7450()->unknown_26_ = *(unsigned short*)((char*)obj + 8);
    return 1;
}
