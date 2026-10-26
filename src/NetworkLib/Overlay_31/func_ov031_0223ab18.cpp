#include <globaldefs.h>

extern unsigned char* data_ov031_02290d20;

// USA: func_ov031_0223ab18
extern "C" ARM void func_ov031_0223ab18(unsigned char* out0, unsigned char* out1) {
    *out0 = data_ov031_02290d20[0xa90];
    if (data_ov031_02290d20[0xa90] != data_ov031_02290d20[0xa91]) {
        *out1 = 1;
    } else {
        *out1 = 0;
    }
    data_ov031_02290d20[0xa91] = data_ov031_02290d20[0xa90];
}
