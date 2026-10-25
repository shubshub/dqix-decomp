#include <globaldefs.h>
#include "Resource/GameResources.h"
#include "Input/Input.h"

#if defined(jpn)
enum { Enum_ov005_0215bed4_1276 = 0x4f8 };
#else
enum { Enum_ov005_0215bed4_1276 = 0x4fc };
#endif

struct Struct_ov005_02153ba4_2
{
    char unknown_0_[Enum_ov005_0215bed4_1276];
    int unknown_4fc_;
};

struct Struct_ov005_02153954;

extern "C" void func_ov005_021562b8(Struct_ov005_02153954* arg0);
extern "C" void func_ov005_0215730c(Struct_ov005_02153954* arg0);
extern "C" Struct_ov005_02153ba4_2* func_ov017_021a193c(int* arg0);
extern "C" void func_ov005_021551fc(char*, int, int);

// USA: func_ov005_0215bed4
extern "C" ARM void func_ov005_0215bed4(Struct_ov005_02153954* arg0)
{
    int var0 = 0;
    if (g_touchInput.pressed_ || (g_touchInput.isRepeatValid_ != 0 && g_touchInput.currentReading_.isHeld != 0) ||
        g_touchInput.released_ != 0)
    {
        func_ov005_021562b8(arg0);
        var0 = 1;
    }
    if (!touchHandled)
        func_ov005_0215730c(self);
    DispatchByIdxAndCond021551fc((char*)self, GetField1c_021a193c((int*)GetGameResources()->unknown_ptr_array_3700[2])->member_, 0);
}
