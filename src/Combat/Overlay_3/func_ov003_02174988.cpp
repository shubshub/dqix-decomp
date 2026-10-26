#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_02174988_4096 = 0xf00 };
enum { Enum_ov003_02174988_70 = 0xc2 };
#else
enum { Enum_ov003_02174988_4096 = 0x1000 };
enum { Enum_ov003_02174988_70 = 0x46 };
#endif

extern "C" int func_ov023_021dc488(void* obj);

// USA: func_ov003_02174988
extern "C" ARM void func_ov003_02174988(char* self) {
    if ((*(unsigned short*)(self + Enum_ov003_02174988_4096 + Enum_ov003_02174988_70) & 0x80) == 0) {
        return;
    }
    if (func_ov023_021dc488(self + 0x3c) != 0) {
        *(unsigned short*)(self + Enum_ov003_02174988_4096 + Enum_ov003_02174988_70) &= ~0x80;
    }
}
