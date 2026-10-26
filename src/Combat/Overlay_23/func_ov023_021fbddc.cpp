#include <globaldefs.h>

extern "C" int func_ov023_021dca88(void *obj, int a1, int a2, int a3);

// USA: func_ov023_021fbddc
extern "C" ARM int func_ov023_021fbddc(void *obj, int a1, int a2, int a3) {
    return func_ov023_021dca88((char*)obj + 0x20, a1, a2, a3);
}
