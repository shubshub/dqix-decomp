#include <globaldefs.h>

extern "C" int func_020ce704(int a, int b);
extern "C" void func_020ce234(int value, int* ptr);
extern "C" void func_020ce188(void);
extern "C" void func_020ce148(void);
extern void (*data_020f2298)(void);

// USA: func_020ce758
extern "C" ARM int func_020ce758(void) {
    int local;
    int result = func_020ce704((int)func_020ce234, (int)&local);
    if (result != 0) {
        return result;
    }
    data_020f2298 = func_020ce188;
    data_020f2298();
    data_020f2298 = func_020ce148;
    return local;
}
