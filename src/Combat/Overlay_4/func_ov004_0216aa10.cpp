#include <globaldefs.h>
#include "NitroSDK/Graphics.h"

#if defined(jpn)
enum { Enum_ov004_0216aa10_2456 = 0x868 };
#else
enum { Enum_ov004_0216aa10_2456 = 0x998 };
#endif

extern "C" void func_ov004_02169144(void);
extern "C" void func_020dc2d0(int mode);
extern "C" int MessageSystem_GetInstance(void);
extern "C" void MessageSystem_Reset(char* obj);

// USA: func_ov004_0216aa10
extern "C" ARM int func_ov004_0216aa10(void) {
    func_ov004_02169144();
    BG0CNTSUB = (BG0CNTSUB & ~3) | 1;
    BG1CNTSUB = (BG1CNTSUB & ~3) | 2;
    BG2CNTSUB = (BG2CNTSUB & ~3);
    func_020dc2d0(0);
    int g = MessageSystem_GetInstance();
    if (*(int*)((char*)g + Enum_ov004_0216aa10_2456) != 0) {
        MessageSystem_Reset((char*)g);
    }
    return 0;
}
