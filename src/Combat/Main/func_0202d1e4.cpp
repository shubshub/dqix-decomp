#include <globaldefs.h>

extern char data_021015a0;
extern "C" int func_0202d224(void);
extern "C" void func_0202c848(int arg);

// USA: func_0202d1e4
extern "C" ARM void func_0202d1e4(unsigned short* a) {
    unsigned short v = a[1];
    if (v != 0) {
        func_0202c848(v);
        *(int*)(&data_021015a0 + 0x10) = 9;
        return;
    }
    if (func_0202d224() == 0) {
        *(int*)(&data_021015a0 + 0x10) = 9;
    }
}
