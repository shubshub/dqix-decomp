#include "Combat/TryApplyElemFields.h"
#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>

#if defined(jpn)
#define func_ov012_02185cf8 func_ov012_0218634c
#endif
#include "std_library_functions.h"
#include "Input/Input.h"

struct StructA0205d5d0;
struct Struct_ov012_02185cf8
{
    char unk_0[LOW_REGION(0x90, 0xac)];
    char window_[LOW_REGION(0x1340, 0x1370) - LOW_REGION(0x90, 0xac)];
    unsigned char step_;
    unsigned char state_;
    char unknown_1372_[2];
    char* text_;
    char unk_1378[LOW_REGION(0x1360, 0x1398) - LOW_REGION(0x1348, 0x1378)];
    int unk_1398;
};

struct Struct_ov012_02185cf8_2
{
    char unk_0[0x30];
    int unknown_30_;
};

typedef void (Struct_ov012_02185cf8::*Type_ov012_02185cf8)(char* text, int hidden);

struct Struct_ov012_0218b108
{
    Type_ov012_02185cf8 unknown_0_[16];
};

extern "C" const Struct_ov012_0218b108 data_ov012_0218b108;
extern "C" Type_ov012_02185cf8 __ptmf_null;

static inline Struct_ov012_02185cf8_2* inline_ov012_02185cf8(char* window)
{
    return (Struct_ov012_02185cf8_2*)(window + 4);
}

static inline char* inline_ov012_02185cf8_2(Struct_ov012_02185cf8* editor)
{
    return (char*)editor + LOW_REGION(0x90, 0xac);
}

// USA: func_ov012_02185cf8
extern "C" ARM void func_ov012_02185cf8(Struct_ov012_02185cf8* self)
{
    if (self->unk_1398 == 0)
        return;

    int hidden = 0;
    if (self->unk_1398 == 2)
    {
        if (g_touchInput.isRepeatValid_ != 0 && g_touchInput.currentReading_.isHeld != 0 &&
            inline_ov012_02185cf8(inline_ov012_02185cf8_2(self))->unknown_30_ < 0)
            return;
        hidden = 1;
    }
    memset(self->text_, 0, LOW_REGION(0x800, 0x960));
    Struct_ov012_0218b108 var1 = data_ov012_0218b108;
    Type_ov012_02185cf8 none = __ptmf_null;
    var1.unknown_0_[0] = none;
    var1.unknown_0_[15] = none;
    if (var1.unknown_0_[self->state_] != 0)
        (self->*var1.unknown_0_[self->state_])(self->text_, hidden);
#if defined(jpn)
    Window_SetPaneText((StructA0205d5d0*)self->window_, self->state_, (int)self->text_, 0);
#else
    Window_SetPaneText((StructA0205d5d0*)self->window_, self->state_, (int)self->text_, 0, 0);
#endif
}
