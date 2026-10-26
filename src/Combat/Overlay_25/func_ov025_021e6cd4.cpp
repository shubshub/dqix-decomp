#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov025_021e6cd4_12 = 0x4 };
#else
enum { Enum_ov025_021e6cd4_12 = 0xc };
#endif

struct Struct_ov025_021e6cd4 {
    char pad[0x24];
    unsigned short f24;
};

struct Struct_ov025_021e6cd4_2 {
    char pad[0x540];
    struct Struct_ov025_021e6cd4 sub;

    struct Struct_ov025_021e6cd4* inline_ov025_021e6cd4() { return &sub; }
};

struct Struct_ov025_021ef988_25 {
    char pad[Enum_ov025_021e6cd4_12];
    struct Struct_ov025_021e6cd4_2* base;
};
extern struct Struct_ov025_021ef988_25 data_ov025_021ef988;

// USA: func_ov025_021e6cd4
extern "C" ARM int func_ov025_021e6cd4(void* obj) {
    data_ov025_021ef988.base->inline_ov025_021e6cd4()->f24 = (unsigned short)*(unsigned int*)((char*)obj + 8);
    return 1;
}
