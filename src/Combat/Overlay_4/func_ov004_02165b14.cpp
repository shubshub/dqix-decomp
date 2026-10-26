#include <globaldefs.h>

extern "C" int MessageSystem_GetInstance(void);

// USA: func_ov004_02165b14
extern "C" ARM int func_ov004_02165b14(void) {
#if defined(jpn)
    enum { byteOffset = 0x7e2, Enum_ov004_02165b14_2460 = 0x86c };
#else
    enum { byteOffset = 0x9b2, Enum_ov004_02165b14_2460 = 0x99c };
#endif
    int g = MessageSystem_GetInstance();
    *(unsigned char*)(g + 0x1000 + byteOffset) = 1;
    *(int*)(g + Enum_ov004_02165b14_2460) = 2;
    return 0;
}
