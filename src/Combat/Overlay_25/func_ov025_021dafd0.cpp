#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov025_021dafd0_1096 = 0x488 };
#else
enum { Enum_ov025_021dafd0_1096 = 0x448 };
#endif

// USA: func_ov025_021dafd0
extern "C" ARM void* func_ov025_021dafd0(char* obj, int id) {
    int flag;
    if (id < 0) goto zero;
    if (id <= 3) { flag = 1; goto check; }
zero:
    flag = 0;
check:
    if (flag == 0) goto fail;
    for (int i = 0; i < 4; i++) {
        int val = *(int*)(obj + i * Enum_ov025_021dafd0_1096 + 0x9a4);
        if (id == val) {
            return obj + 0x958 + i * Enum_ov025_021dafd0_1096;
        }
    }
fail:
    return NULL;
}
