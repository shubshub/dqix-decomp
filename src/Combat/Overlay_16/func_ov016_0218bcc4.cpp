#include <globaldefs.h>

struct Struct_ov016_0219d0c0_3 {
#if defined(jpn)
    unsigned char unknown0[0x3c];
#else
    unsigned char unknown0[0x48];
#endif
    unsigned long long unknown_48_;
};
extern struct Struct_ov016_0219d0c0_3 data_ov016_0219d0c0;

// USA: func_ov016_0218bcc4
extern "C" ARM void func_ov016_0218bcc4(void) {
    data_ov016_0219d0c0.unknown_48_++;
}
