#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov025_021e8044_12 = 0x4 };
#else
enum { Enum_ov025_021e8044_12 = 0xc };
#endif

struct Struct_ov025_021e8044 {
    char pad[0x16];
    unsigned short unknown_16_;
};

struct Struct_ov025_021e8044_2 {
    char pad[0x540];
    struct Struct_ov025_021e8044 sub;

    struct Struct_ov025_021e8044* inline_ov025_021e8044() { return &sub; }
};

struct Struct_ov025_021ef988_30 {
    char pad[Enum_ov025_021e8044_12];
    struct Struct_ov025_021e8044_2* base;
};
extern struct Struct_ov025_021ef988_30 data_ov025_021ef988;

// USA: func_ov025_021e8044
extern "C" ARM int func_ov025_021e8044(void* obj) {
    data_ov025_021ef988.base->inline_ov025_021e8044()->unknown_16_ = *(unsigned short*)((char*)obj + 8);
    return 1;
}
