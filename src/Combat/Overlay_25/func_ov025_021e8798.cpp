#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov025_021e8798_12 = 0x4 };
#else
enum { Enum_ov025_021e8798_12 = 0xc };
#endif

struct Struct_ov025_021ef988_40 {
    char pad0[Enum_ov025_021e8798_12];
    unsigned char* inner;
};

extern struct Struct_ov025_021ef988_40 data_ov025_021ef988;

struct Struct_ov025_021e8798 { char pad[8]; short field_8; };

// USA: func_ov025_021e8798
extern "C" ARM int func_ov025_021e8798(struct Struct_ov025_021e8798* p) {
    short val = p->field_8;
    if (val > 0) {
        *(short*)(data_ov025_021ef988.inner + 0x220) = val;
    } else if (val == -2) {
        *(short*)(data_ov025_021ef988.inner + 0x220) = 0x1e;
    } else {
        *(short*)(data_ov025_021ef988.inner + 0x220) = -1;
    }
    return 1;
}
