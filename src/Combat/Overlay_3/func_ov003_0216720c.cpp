// USA: func_ov003_0216720c
#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_0216720c_1124 = 0x28c };
enum { kRegion328 = 0x210 };
#else
enum { Enum_ov003_0216720c_1124 = 0x464 };
enum { kRegion328 = 0x328 };
#endif

extern "C" void Background_TransferMap(void*, int);

extern "C" ARM void func_ov003_0216720c(char* obj) {
    if (*(int*)(obj + Enum_ov003_0216720c_1124) & 0x40000) {
        Background_TransferMap(*(char**)(obj + kRegion328) + 0x40, 0);
        *(int*)(obj + Enum_ov003_0216720c_1124) &= ~0x40000;
    }
}
