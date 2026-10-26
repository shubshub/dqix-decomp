#include <globaldefs.h>

#if defined(jpn)
#define func_020ca7e0 func_020cc2ac
#endif

// USA: func_020ca7e0
extern "C" ARM int func_020ca7e0(int value, int* addr) {
    asm {
        swp value, value, [addr]
    }
    return value;
}
