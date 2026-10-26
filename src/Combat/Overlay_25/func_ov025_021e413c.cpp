#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov025_021e413c_12 = 0x4 };
#else
enum { Enum_ov025_021e413c_12 = 0xc };
#endif

#include "Filesystem/BackgroundLoader.h"

extern "C" int func_ov025_021eb0f4(void* context);
struct Struct_ov025_021e3c3c;
struct Struct_ov025_021ef988_7 {
    char unknown0[Enum_ov025_021e413c_12];
    Struct_ov025_021e3c3c* context;
};
extern Struct_ov025_021ef988_7 data_ov025_021ef988;

// USA: func_ov025_021e413c
extern "C" ARM int func_ov025_021e413c(void) {
    if (BackgroundLoader::GetInstance()->IsIdle() == 0) {
        return 0;
    }
    return func_ov025_021eb0f4(data_ov025_021ef988.context);
}
