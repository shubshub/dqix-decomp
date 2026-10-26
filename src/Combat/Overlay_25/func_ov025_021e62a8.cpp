#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov025_021e62a8_12 = 0x4 };
#else
enum { Enum_ov025_021e62a8_12 = 0xc };
#endif

struct Struct_ov025_021e62a8 {
    char pad[0x14];
    unsigned short f14;
};

struct Struct_ov025_021e62a8_2 {
    char pad[0x540];
    struct Struct_ov025_021e62a8 sub;

    struct Struct_ov025_021e62a8* inline_ov025_021e62a8() { return &sub; }
};

struct Struct_ov025_021ef988_20 {
    char pad[Enum_ov025_021e62a8_12];
    struct Struct_ov025_021e62a8_2* base;
};
extern struct Struct_ov025_021ef988_20 data_ov025_021ef988;

// USA: func_ov025_021e62a8
extern "C" ARM int func_ov025_021e62a8(void* obj) {
    data_ov025_021ef988.base->inline_ov025_021e62a8()->f14 = *(unsigned short*)((char*)obj + 8);
    return 1;
}
