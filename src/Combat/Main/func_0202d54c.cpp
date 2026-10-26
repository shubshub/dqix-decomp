#include <globaldefs.h>
extern "C" int func_020d5aec(int);

extern char data_021015a0;
extern "C" void func_0202d584(void);
extern "C" void func_0202c848(int);

// USA: func_0202d54c
extern "C" ARM int func_0202d54c(void) {
    int r;
    *(int*)(&data_021015a0 + 0x10) = 3;
    r = func_020d5aec((int)((void*)func_0202d584));
    if (r == 2) return 1;
    func_0202c848(r);
    return 0;
}
