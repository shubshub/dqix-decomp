#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov025_021e6208_12 = 0x4 };
#else
enum { Enum_ov025_021e6208_12 = 0xc };
#endif

extern int data_ov025_021ef988;
extern "C" void func_ov025_021e3084(void* p);

// USA: func_ov025_021e6208
extern "C" ARM int func_ov025_021e6208(void* unused, int value) {
    char* p = *(char**)((char*)&data_ov025_021ef988 + Enum_ov025_021e6208_12);
    func_ov025_021e3084(p + 0x540);
    *(int*)(p + 0x540) = value;
    return 1;
}
