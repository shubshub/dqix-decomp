#include <globaldefs.h>

extern "C" int func_020d40bc(int, int, int, int, int, int);
extern "C" int func_020d4204(void);
extern "C" void func_020d404c(int index, int value);

// USA: func_020d6ad4
extern "C" ARM int func_020d6ad4(int arg, int a, int b, int c, unsigned short d) {
    int r = func_020d4204();
    if (r != 0) return r;
    func_020d404c(0x1d, arg);
    r = func_020d40bc(0x1d, 4, a, b, c, d);
    if (r == 0) r = 2;
    return r;
}
