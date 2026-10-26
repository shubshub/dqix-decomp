#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov025_021e5ff0_12 = 0x4 };
#else
enum { Enum_ov025_021e5ff0_12 = 0xc };
#endif

struct Struct_ov025_021ef988_17 {
    char pad0[Enum_ov025_021e5ff0_12];
    unsigned char* inner;
};

extern struct Struct_ov025_021ef988_17 data_ov025_021ef988;

struct Struct_ov025_021e5ff0 { char pad[8]; unsigned short field_8; };

// USA: func_ov025_021e5ff0
extern "C" ARM int func_ov025_021e5ff0(struct Struct_ov025_021e5ff0* p) {
    *(unsigned short*)(data_ov025_021ef988.inner + 0x21c) = p->field_8;
    return 1;
}
