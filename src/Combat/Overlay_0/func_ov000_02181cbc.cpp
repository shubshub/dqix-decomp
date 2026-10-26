#include <globaldefs.h>

extern "C" int func_ov000_0215e9fc(int count, short* buf, int max, int start);

// USA: func_ov000_02181cbc
extern "C" ARM void func_ov000_02181cbc(int count, int unused, int* dest) {
    short buf[4];
    count = func_ov000_0215e9fc(count, buf, 4, 0);
    for (int i = 0; i < count; i++) {
        dest[i] = buf[i];
    }
}
