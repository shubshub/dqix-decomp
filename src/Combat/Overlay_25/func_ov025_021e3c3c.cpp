#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov025_021e3c3c_12 = 0x4 };
#else
enum { Enum_ov025_021e3c3c_12 = 0xc };
#endif

extern "C" int func_ov025_021eb050(void* obj);
extern "C" void func_ov025_021eb044(void* obj, int val);
struct Struct_ov025_021e3c3c;
struct Struct_ov025_021ef988_7 {
    char unknown0[Enum_ov025_021e3c3c_12];
    Struct_ov025_021e3c3c* context;
};
extern Struct_ov025_021ef988_7 data_ov025_021ef988;

struct Struct_ov025_021e3c3c_2 {
    char pad[0x8];
    unsigned short field8;
};

// USA: func_ov025_021e3c3c
extern "C" ARM int func_ov025_021e3c3c(struct Struct_ov025_021e3c3c_2* obj) {
    Struct_ov025_021e3c3c* base = data_ov025_021ef988.context;
    int val = func_ov025_021eb050(base);
    if (obj->field8 == val) {
        base = data_ov025_021ef988.context;
        func_ov025_021eb044(base, 0);
    }
    return 1;
}
