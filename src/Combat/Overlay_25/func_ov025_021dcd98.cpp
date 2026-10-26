#include <globaldefs.h>
#include "std_library_functions.h"

#if defined(jpn)
enum { Enum_ov025_021dcd98_0 = 0x1f0 };
#else
enum { Enum_ov025_021dcd98_0 = 0 };
#endif

// USA: func_ov025_021dcd98
extern "C" ARM void func_ov025_021dcd98(char* obj) {
    obj[0x6f00 + Enum_ov025_021dcd98_0] = 0;
    obj[0x6eff + Enum_ov025_021dcd98_0] = 0;
    memset(obj + 0x6fba + Enum_ov025_021dcd98_0, -1, 8);
    *(short*)(obj + 0x6fc2 + Enum_ov025_021dcd98_0) = 0;
    *(int*)(obj + 0x6fc4 + Enum_ov025_021dcd98_0) = 0;
    *(int*)(obj + 0x6fc8 + Enum_ov025_021dcd98_0) = 0;
    *(int*)(obj + 0x6fcc + Enum_ov025_021dcd98_0) = 0;
    *(int*)(obj + 0x6fd0 + Enum_ov025_021dcd98_0) = 0;
}
