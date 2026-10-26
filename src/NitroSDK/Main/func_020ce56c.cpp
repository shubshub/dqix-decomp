#include <globaldefs.h>

extern "C" void func_020ce234();
extern "C" int func_020ce4e8(int a, int b, int c, void* callback, int* out);
extern void (*data_020f2298)();

// USA: func_020ce56c
extern "C" ARM int func_020ce56c(int a, int b, int c) {
    int local;
    int result = func_020ce4e8(a, b, c, (void*)func_020ce234, &local);
    if (result != 0) {
        return result;
    }
    data_020f2298();
    return local;
}
