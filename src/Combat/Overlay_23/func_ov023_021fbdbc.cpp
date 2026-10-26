#include <globaldefs.h>

extern "C" int func_ov023_021dc354(void *obj, int a1, int a2, int a3);

// USA: func_ov023_021fbdbc
extern "C" ARM int func_ov023_021fbdbc(void *obj, int a1, int a2, int a3) {
    return func_ov023_021dc354((char*)obj + 0x20, a1, a2, a3);
}
