// USA: func_ov003_0216fb6c
#include <globaldefs.h>

extern "C" ARM void func_ov003_0216fb6c(char* obj) {
    int i;
    for (i = 0; i < 3; i++) {
        *(int*)(obj + i * 4 + 0x1000 + 0xb68) = -1;
    }
    *(int*)(obj + 0x1000 + 0xb74) = 0;
}
