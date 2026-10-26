#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_0216664c_1116 = 0x284 };
enum { Enum_ov003_0216664c_1184 = 0x2c8 };
#else
enum { Enum_ov003_0216664c_1116 = 0x45c };
enum { Enum_ov003_0216664c_1184 = 0x4a0 };
#endif


extern "C" void func_ov003_021666c4(void* self);

// USA: func_ov003_0216664c
extern "C" ARM void func_ov003_0216664c(void* self) {
    int flags = *(int*)((char*)self + Enum_ov003_0216664c_1116);
    int changed = 0;
    if (flags & 0x10) {
        signed char v = *((signed char*)self + Enum_ov003_0216664c_1184);
        changed = 1;
        *((signed char*)self + Enum_ov003_0216664c_1184) = v + 1;
    } else if (flags & 0x20) {
        signed char v = *((signed char*)self + Enum_ov003_0216664c_1184);
        changed = 1;
        *((signed char*)self + Enum_ov003_0216664c_1184) = v - 1;
    }
    signed char v = *((signed char*)self + Enum_ov003_0216664c_1184);
    if (v >= 2) {
        *((signed char*)self + Enum_ov003_0216664c_1184) = 0;
    } else if (v < 0) {
        *((signed char*)self + Enum_ov003_0216664c_1184) = 1;
    }
    if (changed) {
        func_ov003_021666c4(self);
    }
}
