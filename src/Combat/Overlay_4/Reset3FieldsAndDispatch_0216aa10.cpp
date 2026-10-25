#include <globaldefs.h>
#include "NitroSDK/Graphics.h"

#if defined(jpn)
enum { kControllerField = 0x868 };
#else
enum { kControllerField = 0x998 };
#endif

extern "C" void func_ov004_02169144(void);
void SetCombatModeFromCase020dc2d0(int mode);
int MessageSystem_GetInstance(void);
void MessageSystem_Reset(char* obj);

// USA: func_ov004_0216aa10
ARM int Reset3FieldsAndDispatch_0216aa10(void) {
    func_ov004_02169144();
    BG0CNTSUB = (BG0CNTSUB & ~3) | 1;
    BG1CNTSUB = (BG1CNTSUB & ~3) | 2;
    BG2CNTSUB = (BG2CNTSUB & ~3);
    SetCombatModeFromCase020dc2d0(0);
    int g = MessageSystem_GetInstance();
    if (*(int*)((char*)g + kControllerField) != 0) {
        MessageSystem_Reset((char*)g);
    }
    return 0;
}
