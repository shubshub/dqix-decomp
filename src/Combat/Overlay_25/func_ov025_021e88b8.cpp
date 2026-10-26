#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov025_021e88b8_28665 = 0x71e9 };
#else
enum { Enum_ov025_021e88b8_28665 = 0x6ff9 };
#endif

extern "C" void* func_ov000_02160130(void);

// USA: func_ov025_021e88b8
extern "C" ARM int func_ov025_021e88b8(void) {
    void* obj = func_ov000_02160130();
    if (obj) {
        *((char*)obj + Enum_ov025_021e88b8_28665) = 1;
    }
    return 1;
}
