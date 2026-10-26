#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov025_021e6230_12 = 0x4 };
#else
enum { Enum_ov025_021e6230_12 = 0xc };
#endif

extern "C" int func_ov025_021e2f54(void*, int, int);

struct Struct_ov025_021ef988_19 {
    char pad[Enum_ov025_021e6230_12];
    char* base;
};
extern struct Struct_ov025_021ef988_19 data_ov025_021ef988;

// USA: func_ov025_021e6230
extern "C" ARM int func_ov025_021e6230(void* obj, int b, int c, int d) {
    (void)obj;
    (void)c;
    func_ov025_021e2f54(data_ov025_021ef988.base + 0x540, b, d);
    return 1;
}
