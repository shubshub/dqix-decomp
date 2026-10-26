#include <globaldefs.h>
#include "Input/Input.h"
#if defined(jpn)
enum { flagOffset = 0x484, Enum_ov000_0217bfbc_2 = 0, Enum_ov000_0217bfbc_1 = 2, Enum_ov000_0217bfbc_0 = 1 };
#else
enum { flagOffset = 0x444, Enum_ov000_0217bfbc_2 = 2, Enum_ov000_0217bfbc_1 = 1, Enum_ov000_0217bfbc_0 = 0 };
#endif

extern "C" int func_0205d97c(int);
extern "C" void func_ov000_0217629c(void* obj);
extern "C" void func_ov000_0217ab8c(void* obj, int a, int b);
extern "C" void func_ov000_02176e3c(int a, void* obj, int c, int d, int e, int f);

extern int data_ov000_02184294[3];

// USA: func_ov000_0217bfbc
extern "C" ARM int func_ov000_0217bfbc(void* objRaw, int arg1, int arg2) {
    char* obj = (char*)objRaw;
    int flags = g_keyManager.TestKeysPressed(0x601);
    flags |= g_keyManager.TestKeysPressed(0x802);
    int c = (func_0205d97c(*(int*)(obj + 0x38)) == 2) ? 1 : 0;
    if ((flags | c) != 0) {
        *(unsigned char*)(obj + flagOffset) = 0;
        func_ov000_0217629c(obj);
        signed char idx = *(signed char*)(obj + 0x18);
        *(unsigned char*)(obj + idx + 0x10) = 0;
        idx = *(signed char*)(obj + 0x18);
        *(unsigned char*)(obj + 0x18) = idx - 1;
        func_ov000_0217ab8c(obj, arg1, arg2);
        signed char idx2 = *(signed char*)(obj + 0x18);
        signed char p2 = *(signed char*)(obj + idx2 + 0x10);
        func_ov000_02176e3c(data_ov000_02184294[Enum_ov000_0217bfbc_2], obj, p2, data_ov000_02184294[Enum_ov000_0217bfbc_1], data_ov000_02184294[Enum_ov000_0217bfbc_0], 0);
    }
    return -1;
}
