#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov025_021e6374_12 = 0x4 };
#else
enum { Enum_ov025_021e6374_12 = 0xc };
#endif

struct Struct_ov025_021e6374 {
    char pad[0x1c];
    unsigned short f1c;
};

struct Struct_ov025_021e6374_2 {
    char pad[0x540];
    struct Struct_ov025_021e6374 sub;

    struct Struct_ov025_021e6374* inline_ov025_021e6374() { return &sub; }
};

struct Struct_ov025_021ef988_21 {
    char pad[Enum_ov025_021e6374_12];
    struct Struct_ov025_021e6374_2* base;
};
extern struct Struct_ov025_021ef988_21 data_ov025_021ef988;

// USA: func_ov025_021e6374
extern "C" ARM int func_ov025_021e6374(void* obj) {
    data_ov025_021ef988.base->inline_ov025_021e6374()->f1c =*(unsigned short*)((char*)obj + 8);
    return 1;
}
