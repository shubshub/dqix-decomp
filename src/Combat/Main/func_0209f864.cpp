#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_0209f864
extern "C" ARM void func_0209f864(char* obj, int mode) {
    int var0 = 0x40;
    if (mode == 0) {
        int count;
        int i;
        *(int*)(obj + 0x98) = 0;
        count = *(unsigned char*)(*(char**)(obj + 4) + 0x8e07);
        for (i = 0; i < count; i++) {
            char* elem = *(char**)(obj + 4) + 0x5c60 + i * var0;
            if (elem != 0 && (*(unsigned char*)(elem + 0x25) != 0 || *(unsigned char*)(elem + 0x26) != 0)) {
                int idx = *(int*)(obj + 0x98);
                *(int*)(obj + 0x98) += 1;
                memcpy(obj + 0x9c + idx * var0, elem, var0);
            }
        }
        return;
    }
    *(int*)(obj + 0x49c) = 0;
    memset(obj + 0x4a0, 0, 0x400);
    {
        char* var5 = obj + 0x9c;
        int i;
        for (i = 0; i < *(int*)(obj + 0x98); i++) {
            char* elem = var5 + i * var0;
            if (*(unsigned char*)(elem + 0x25) != 0 || *(unsigned char*)(elem + 0x26) != 0) {
                int idx = *(int*)(obj + 0x49c);
                int cur = *(int*)(var5 + 0x400);
                *(int*)(var5 + 0x400) = cur + 1;
                memcpy(obj + 0x4a0 + idx * var0, elem, var0);
            }
        }
    }
    *(int*)(obj + 0x98) = *(int*)(obj + 0x49c);
    memcpy(obj + 0x9c, obj + 0x4a0, 0x400);
}
