#include <globaldefs.h>

#if defined(jpn)
#define func_020c51c0 func_020c6c8c
#endif

extern "C" void MI_Copy36B(int cmd);

// USA: func_020c51c0
extern "C" ARM void func_020c51c0(int arg0) {
    *(int*)0x4000400 = 0x1a;
    MI_Copy36B(cmd);
}
