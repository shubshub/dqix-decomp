#include <globaldefs.h>

// USA: func_ov001_02159eb0
extern "C" ARM void* func_ov001_02159eb0(void* obj) {
    char* p = *(char**)obj;
    int i;
    for (i = 0; i < *(int*)((char*)obj + 4); i++, p += 0x40) {
        if (*(int*)p == 0) {
            *(int*)(p + 0x3c) = 0;
            return p;
        }
    }
    return NULL;
}
