#include <globaldefs.h>

extern "C" int MessageSystem_GetInstance(void);

// USA: func_ov004_0216e894
extern "C" ARM int func_ov004_0216e894(void) {
#if defined(jpn)
    enum { Enum_ov004_0216e894_2506 = 0x7fb, Enum_ov004_0216e894_2479 = 0x7df };
#else
    enum { Enum_ov004_0216e894_2506 = 0x9ca, Enum_ov004_0216e894_2479 = 0x9af };
#endif
    int g = MessageSystem_GetInstance();
    g += 0x1000;
    *(unsigned char*)(g + Enum_ov004_0216e894_2506) = 1;
    *(unsigned char*)(g + Enum_ov004_0216e894_2479) = 1;
    return 0;
}
