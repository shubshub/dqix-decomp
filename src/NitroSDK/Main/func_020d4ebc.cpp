#include <globaldefs.h>

extern "C" int func_020d424c(int, int);
extern "C" int func_020d40bc(int, int);
extern "C" void func_020d404c(int index, int value);

// USA: func_020d4ebc
extern "C" ARM int func_020d4ebc(int value) {
    int result = func_020d424c(1, 1);
    if (result != 0) return result;
    func_020d404c(4, value);
    result = func_020d40bc(4, 0);
    if (result == 0) result = 2;
    return result;
}
