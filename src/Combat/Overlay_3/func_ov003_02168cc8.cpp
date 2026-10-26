#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov003_02168cc8_2464 = 0x870 };
enum { Enum_ov003_02168cc8_2478 = 0x7de };
enum { Enum_ov003_02168cc8_1260 = 0x4e8 };
#else
enum { Enum_ov003_02168cc8_2464 = 0x9a0 };
enum { Enum_ov003_02168cc8_2478 = 0x9ae };
enum { Enum_ov003_02168cc8_1260 = 0x4ec };
#endif


extern "C" int MessageSystem_GetInstance();
extern "C" int func_ov003_02169b30(void* obj);

// USA: func_ov003_02168cc8
extern "C" ARM void func_ov003_02168cc8(void* obj) {
    int g = MessageSystem_GetInstance();
    if (*(int*)(g + Enum_ov003_02168cc8_2464) == 3) {
        *(unsigned char*)(g + 0x1000 + Enum_ov003_02168cc8_2478) = 0;
    }
    int ret = func_ov003_02169b30(obj);
    switch (ret) {
        case -1:
            return;
        case 0:
            *((unsigned char*)obj + Enum_ov003_02168cc8_1260) = 3;
            break;
        case 1:
            *((unsigned char*)obj + Enum_ov003_02168cc8_1260) = 4;
            break;
        case -2:
        case 2:
            *((unsigned char*)obj + Enum_ov003_02168cc8_1260) = 5;
            break;
    }
}
