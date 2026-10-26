#include <globaldefs.h>
#include "Resource/GameResources.h"


#if defined(jpn)
enum { Enum_020ae4ec_17496 = 0x41a8 };
#else
enum { Enum_020ae4ec_17496 = 0x4458 };
#endif

extern "C" void* Scenario_GetInstance(void);
extern "C" void Scenario_SetFlag(void*, unsigned char*, int, int);
extern "C" void func_ov017_021cdb00(int, int, int, int);

// USA: func_020ae4ec
extern "C" ARM void func_020ae4ec(int param0, int param1) {
    void* x = Scenario_GetInstance();
    Scenario_SetFlag(x, (unsigned char*)x + 0x8c, param0 + 0x33e, param1);
    void* y = GetGameResources();
    if (*(int*)((char*)y + Enum_020ae4ec_17496) == 0) return;
    func_ov017_021cdb00(7, param0, param1, -1);
}
