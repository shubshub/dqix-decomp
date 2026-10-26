#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov025_021e6ef8_12 = 0x4 };
#else
enum { Enum_ov025_021e6ef8_12 = 0xc };
#endif

struct Struct_ov025_021e6ef8 {
    char pad[8];
    unsigned short h8;
    short ha;
};

struct Struct_ov025_021e6ef8_2 {
    char pad[0x3e];
    unsigned short unknown_3e_;
    short f40;
};

struct Struct_ov025_021e6ef8_3 {
    char pad[0x540];
    struct Struct_ov025_021e6ef8_2 sub;
};

struct Struct_ov025_021ef988_26 {
    char pad[Enum_ov025_021e6ef8_12];
    struct Struct_ov025_021e6ef8_3* base;
};
extern struct Struct_ov025_021ef988_26 data_ov025_021ef988;

// USA: func_ov025_021e6ef8
extern "C" ARM int func_ov025_021e6ef8(struct Struct_ov025_021e6ef8* src) {
    short var0 = src->ha;
    unsigned short v8 = src->h8;
    struct Struct_ov025_021e6ef8_3* base = data_ov025_021ef988.base;
    base->sub.unknown_3e_ = v8;
    base->sub.f40 = var0;
    return 1;
}
