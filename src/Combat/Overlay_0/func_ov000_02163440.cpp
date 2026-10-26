#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov000_02163440_28228 = 0x7034 };
#else
enum { Enum_ov000_02163440_28228 = 0x6e44 };
#endif

// USA: func_ov000_02163440
extern "C" ARM void func_ov000_02163440(void* obj, short a, unsigned short b, unsigned short c) {
    *(unsigned short*)((char*)obj + Enum_ov000_02163440_28228) = a;
    *(unsigned short*)((char*)obj + Enum_ov000_02163440_28228 + 2) = b;
    *(unsigned short*)((char*)obj + Enum_ov000_02163440_28228 + 4) = c;
}
