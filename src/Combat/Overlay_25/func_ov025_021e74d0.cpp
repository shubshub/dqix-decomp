#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov025_021e74d0_12 = 0x4 };
#else
enum { Enum_ov025_021e74d0_12 = 0xc };
#endif

extern "C" int func_ov025_021ed11c(void*, int);

struct Struct_ov025_021ef988_29 {
    char pad[Enum_ov025_021e74d0_12];
    char* base;
};
extern struct Struct_ov025_021ef988_29 data_ov025_021ef988;

struct Struct_ov025_021e74d0 {
    char pad8[8];
    int v;
};

// USA: func_ov025_021e74d0
extern "C" ARM int func_ov025_021e74d0(struct Struct_ov025_021e74d0* obj) {
    func_ov025_021ed11c(data_ov025_021ef988.base + 0x22c, obj->v);
    return 1;
}
