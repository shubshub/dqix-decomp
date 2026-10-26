#include <globaldefs.h>
#include "Resource/GameResources.h"
#include "Input/Input.h"

#if defined(jpn)
enum { Enum_ov005_0215bed4_1276 = 0x4f8 };
#else
enum { Enum_ov005_0215bed4_1276 = 0x4fc };
#endif

struct MemberScreen
{
    char unk_0[Enum_ov005_0215bed4_1276];
    int member_;
};

struct EquipmentMenu;

extern "C" void func_ov005_021562b8(EquipmentMenu* self);
extern "C" void func_ov005_0215730c(EquipmentMenu* self);
extern "C" MemberScreen* func_ov017_021a193c(int* obj);
extern "C" void func_ov005_021551fc(char*, int, int);

// USA: func_ov005_0215bed4
extern "C" ARM void func_ov005_0215bed4(EquipmentMenu* self)
{
    int var0 = 0;
    if (g_touchInput.pressed_ || (g_touchInput.isRepeatValid_ != 0 && g_touchInput.currentReading_.isHeld != 0) ||
        g_touchInput.released_ != 0)
    {
        func_ov005_021562b8(self);
        var0 = 1;
    }
    if (!var0)
        func_ov005_0215730c(self);
    func_ov005_021551fc((char*)self, func_ov017_021a193c((int*)GetGameResources()->unknown_ptr_array_3700[2])->member_, 0);
}
