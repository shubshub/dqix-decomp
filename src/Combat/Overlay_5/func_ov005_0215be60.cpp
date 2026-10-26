#if defined(jpn)
#define R(j,u) (j)
extern const char data_ov012_0218bfd7[];
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "Input/Input.h"

struct EquipmentMenu
{
    char unk_0[R(0x1240, 0x1244)];
    char unknown_1244_[4];
};

extern "C" void func_ov023_021dcae0(void* window, int item);
extern "C" void func_ov005_021562b8(EquipmentMenu* self);
extern "C" void func_ov005_0215730c(EquipmentMenu* self);

// USA: func_ov005_0215be60
extern "C" ARM void func_ov005_0215be60(EquipmentMenu* self)
{
    func_ov023_021dcae0(self->unknown_1244_, -1);
    int touched = 0;
    if (g_touchInput.pressed_ || (g_touchInput.isRepeatValid_ != 0 && g_touchInput.currentReading_.isHeld != 0) ||
        g_touchInput.released_ != 0)
    {
        func_ov005_021562b8(self);
        touched = 1;
    }
    if (touched)
        return;
    func_ov005_0215730c(self);
}
