#include <globaldefs.h>

extern "C" int func_020cf1e0(void*, void*, void(*)(int), int);
extern "C" void func_020cf864(void);
extern "C" void func_020cf854(int val);

extern char data_02111818;

// USA: func_020cf25c
extern "C" ARM int func_020cf25c(void* a, void* b) {
    int result = func_020cf1e0(a, b, func_020cf854, 0);
    *(int*)(&data_02111818 + 0x2c) = result;
    if (result == 0) {
        func_020cf864();
    }
    return *(int*)(&data_02111818 + 0x2c);
}
