#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_02074b64;
extern "C" void func_02074b64(struct Struct_02074b64* obj);

struct InitTarget0205cfd4;
extern "C" void Window_Init(struct InitTarget0205cfd4* s);

// USA: func_ov023_021d8a40
extern "C" ARM void func_ov023_021d8a40(void* obj) {
    *(unsigned char*)((char*)obj + 0x18) = 0;
    *(unsigned char*)((char*)obj + 0x19) = 0;
    func_02074b64((struct Struct_02074b64*)((char*)obj + 8));
    unsigned int* reg = (unsigned int*)0x4001000;
    *(int*)((char*)obj + 0x1c) = (*reg & 0x1f00) >> 8;
    *(int*)obj = 0;
    *(int*)((char*)obj + 4) = 0;
    Window_Init((struct InitTarget0205cfd4*)((char*)obj + 0x20));
    for (int i = 0; i < 4; i++) {
        *(int*)((char*)obj + 0xdc + i * 4) = 0;
    }
    *(int*)((char*)obj + 0xec) = -1;
    memset((char*)obj + 0xf0, 0, 0x14);
    memset((char*)obj + 0x104, 0, 0x14);
    *(unsigned char*)((char*)obj + 0x118) = 0;
    *(unsigned char*)((char*)obj + 0x119) = 0;
    *(unsigned char*)((char*)obj + 0x11a) = 0;
    *(unsigned char*)((char*)obj + 0x11b) = 0;
    *(unsigned char*)((char*)obj + 0x11c) = 0;
    *(unsigned char*)((char*)obj + 0x11d) = 0;
    *(int*)((char*)obj + 0x120) = 0;
    *(unsigned char*)((char*)obj + 0x11e) = 0;
}
