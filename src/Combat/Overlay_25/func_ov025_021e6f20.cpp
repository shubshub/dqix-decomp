#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov025_021e6f20_12 = 0x4 };
#else
enum { Enum_ov025_021e6f20_12 = 0xc };
#endif

extern "C" int func_ov025_021ed110(void*, int);

struct Struct_ov025_021ef988_27 {
    char pad[Enum_ov025_021e6f20_12];
    char* base;
};
extern struct Struct_ov025_021ef988_27 data_ov025_021ef988;

struct Struct_ov025_021e6f20 {
    char pad8[8];
    short v;
};

// USA: func_ov025_021e6f20
extern "C" ARM int func_ov025_021e6f20(struct Struct_ov025_021e6f20* obj) {
    func_ov025_021ed110(data_ov025_021ef988.base + 0x22c, obj->v);
    return 1;
}
