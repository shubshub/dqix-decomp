#include <globaldefs.h>

extern "C" int func_ov000_0215ec1c(int count, short* buf, int max, int start);

// USA: func_ov000_02181d04
extern "C" ARM void func_ov000_02181d04(int count, int unused, int* dest) {
    short buf[12];
    count = func_ov000_0215ec1c(count, buf, 12, 0);
    for (int i = 0; i < count; i++) {
        dest[i] = buf[i];
    }
}
