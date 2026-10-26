#include <globaldefs.h>

extern char data_021015a0;
extern "C" int func_020d5204(int a);
extern "C" void func_0202c848(int arg);
extern "C" void func_0202c9ac(void);

// USA: func_0202c958
extern "C" ARM int func_0202c958(void) {
    int state = *(int*)(&data_021015a0 + 0x10);
    if ((unsigned int)(state - 4) <= 2) {
        return 1;
    }
    int result = func_020d5204((int)func_0202c9ac);
    if (result != 2) {
        func_0202c848(result);
        return 0;
    }
    *(short*)(&data_021015a0 + 0x0) = 0;
    *(short*)(&data_021015a0 + 0xa) = 1;
    return 1;
}
