#include <globaldefs.h>
#include "Resource/GameResources.h"


#if defined(jpn)
enum { Enum_020ae53c_17496 = 0x41a8 };
#else
enum { Enum_020ae53c_17496 = 0x4458 };
#endif

extern "C" void* Scenario_GetInstance(void);
extern "C" unsigned short* Zone3D_GetInstance(void);
extern "C" void func_020aee04(int mode, int value);

extern "C" int Scenario_TestFlag(int unused, unsigned char* arr, int index);
extern "C" void func_020ae6e8(int enable);
extern "C" void func_020ae730(int a);
extern "C" void func_020ae7d4(int mode);
extern "C" void func_020ae880(int mode);
extern "C" void func_020ae990(int a);
extern "C" void func_020ae9f0(void);
extern "C" void func_020ae694(int, int, unsigned short);
extern "C" void func_020ae4ec(int param0, int param1);

// USA: func_020ae53c
extern "C" ARM void func_020ae53c(int arg) {
    char* res = (char*)GetGameResources();
    unsigned char* f = (unsigned char*)Scenario_GetInstance();
    int key;
    Zone3D_GetInstance();
    *(int*)((unsigned char*)res + Enum_020ae53c_17496) = arg;

    func_020ae6e8(!Scenario_TestFlag((int)f, f + 0x8c, 0x33e));
    func_020ae730((unsigned char)Scenario_TestFlag((int)f, f + 0x8c, 0x344));
    func_020ae7d4((unsigned char)Scenario_TestFlag((int)f, f + 0x8c, 0x347));
    func_020ae880((unsigned char)Scenario_TestFlag((int)f, f + 0x8c, 0x34a));
    func_020ae990((unsigned char)Scenario_TestFlag((int)f, f + 0x8c, 0x36c));
    func_020ae9f0();

    arg = Scenario_TestFlag((int)f, f + 0x8c, 0x385);
    if (*Zone3D_GetInstance() == 0x1cea) {
        for (key = 0x4e; key <= 0x58; key++) {
            func_020ae694((unsigned char)arg, 0, key);
        }
        func_020ae4ec(0x47, arg != 0);
    }
    func_020aee04(0, Scenario_TestFlag((int)f, f + 0x8c, 0x386));
    *(int*)(res + Enum_020ae53c_17496) = 1;
}
