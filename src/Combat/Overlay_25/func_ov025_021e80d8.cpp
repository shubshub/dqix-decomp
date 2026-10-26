#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov025_021e80d8_12 = 0x4 };
#else
enum { Enum_ov025_021e80d8_12 = 0xc };
#endif

struct Struct_ov025_021ef988_32 {
    char pad0[Enum_ov025_021e80d8_12];
    unsigned char* inner;
};

extern struct Struct_ov025_021ef988_32 data_ov025_021ef988;
extern "C" void func_ov025_021ed344(unsigned char* obj, int val);

// USA: func_ov025_021e80d8
extern "C" ARM int func_ov025_021e80d8(unsigned short* in) {
    func_ov025_021ed344(data_ov025_021ef988.inner + 0x5e8, in[4]);
    return 1;
}
