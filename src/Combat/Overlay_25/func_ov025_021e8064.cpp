#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov025_021e8064_12 = 0x4 };
#else
enum { Enum_ov025_021e8064_12 = 0xc };
#endif

struct Struct_ov025_021e8064 {
    char pad[0x1e];
    unsigned short unknown_1e_;
};

struct Struct_ov025_021e8064_2 {
    char pad[0x540];
    struct Struct_ov025_021e8064 sub;

    struct Struct_ov025_021e8064* inline_ov025_021e8064() { return &sub; }
};

struct Struct_ov025_021ef988_31 {
    char pad[Enum_ov025_021e8064_12];
    struct Struct_ov025_021e8064_2* base;
};
extern struct Struct_ov025_021ef988_31 data_ov025_021ef988;

// USA: func_ov025_021e8064
extern "C" ARM int func_ov025_021e8064(void* obj) {
    data_ov025_021ef988.base->inline_ov025_021e8064()->unknown_1e_ =*(unsigned short*)((char*)obj + 8);
    return 1;
}
