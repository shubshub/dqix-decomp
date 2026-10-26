#include <globaldefs.h>

extern "C" int func_020d40bc(int, int, int);
extern "C" int func_020d4204(void);
extern "C" void func_020d404c(int index, int value);

// USA: func_020d6a84
extern "C" ARM int func_020d6a84(int arg, int mode) {
    int r = func_020d4204();
    if (r != 0) return r;
    if (mode != 0 && mode != 1) return 6;
    func_020d404c(0x19, arg);
    r = func_020d40bc(0x19, 1, mode);
    if (r == 0) r = 2;
    return r;
}
