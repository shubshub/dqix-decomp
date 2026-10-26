#include <globaldefs.h>

extern char data_021015a0;
extern "C" unsigned short func_020d4aa8();
extern "C" void func_0202c848(int);
extern "C" int func_020d6b34(int, short, short, unsigned short, unsigned short);
extern "C" void func_0202d840();

// USA: func_0202d788
extern "C" ARM int func_0202d788(unsigned short slot) {
    int mask;
    unsigned short idx;

    mask = func_020d4aa8();
    if (mask == 0x8000) {
        func_0202c848(3);
        *(int*)(&data_021015a0 + 0x10) = 9;
        return 3;
    }
    if (mask == 0) {
        func_0202c848(0x16);
        *(int*)(&data_021015a0 + 0x10) = 9;
        return 0x18;
    }
    idx = slot;
    while (!(mask & (1 << (idx - 1)))) {
        idx = idx + 1;
        if (idx > 0x10) {
            return 0x18;
        }
    }
    return (unsigned short)func_020d6b34((int)&func_0202d840, 3, 0x11, idx, 0x1e);
}
