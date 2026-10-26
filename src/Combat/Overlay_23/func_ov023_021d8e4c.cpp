#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_0205d67c;
extern "C" int func_0205d67c(struct Struct_0205d67c*);

// USA: func_ov023_021d8e4c
extern "C" ARM void func_ov023_021d8e4c(void* obj, void* p1, void* arg2, void* src2) {
    *(void**)((char*)obj + 0xec) = p1;
    memcpy((char*)obj + 0xf0, arg2, 0x14);
    memcpy((char*)obj + 0x104, src2, 0x14);
    int flag = func_0205d67c((struct Struct_0205d67c*)((char*)obj + 0x20));
    if (flag == 0) {
        *((unsigned char*)obj + 0x11c) = 0;
    } else {
        *((unsigned char*)obj + 0x11c) = 1;
    }
    *((unsigned char*)obj + 0x11a) = 2;
}
