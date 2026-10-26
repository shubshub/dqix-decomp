#include <globaldefs.h>

extern "C" int func_020d40bc(int, int);
extern "C" int func_020d4204(void);
extern "C" void func_020d404c(int index, int value);

// USA: func_020d5004
extern "C" ARM int func_020d5004(int arg) {
    int r = func_020d4204();
    if (r != 0) return r;
    func_020d404c(1, arg);
    r = func_020d40bc(1, 0);
    if (r == 0) r = 2;
    return r;
}
