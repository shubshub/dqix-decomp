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

struct Struct_0205d5d0;
struct Struct_ov012_02185cf8
{
    char unknown_0_[LOW_REGION(0x90, 0xac)];
    char unknown_ac_[LOW_REGION(0x1340, 0x1370) - LOW_REGION(0x90, 0xac)];
    unsigned char unknown_1370_;
    unsigned char unknown_1371_;
    char unknown_1372_[2];
    char* unknown_1374_;
    char unknown_1378_[LOW_REGION(0x1360, 0x1398) - LOW_REGION(0x1348, 0x1378)];
    int unknown_1398_;
};

struct Struct_ov012_02185cf8_2
{
    char unknown_0_[0x30];
    int unknown_30_;
};

typedef void (Struct_ov012_02185cf8::*Type_ov012_02185cf8)(char* text, int hidden);

struct Struct_ov012_0218b108
{
    Type_ov012_02185cf8 unknown_0_[16];
};

extern "C" const TextTable02185cf8 data_ov012_0218b108;
extern "C" TextFn02185cf8 __ptmf_null;

static inline Struct_ov012_02185cf8_2* inline_ov012_02185cf8(char* arg0)
{
    return (Struct_ov012_02185cf8_2*)(arg0 + 4);
}

static inline char* inline_ov012_02185cf8_2(Struct_ov012_02185cf8* arg0)
{
    return (char*)arg0 + LOW_REGION(0x90, 0xac);
}

// USA: func_ov012_02185cf8
extern "C" ARM void func_ov012_02185cf8(Struct_ov012_02185cf8* arg0)
{
    if (arg0->unknown_1398_ == 0)
        return;

    int var0 = 0;
    if (arg0->unknown_1398_ == 2)
    {
        if (g_touchInput.isRepeatValid_ != 0 && g_touchInput.currentReading_.isHeld != 0 &&
            inline_ov012_02185cf8(inline_ov012_02185cf8_2(arg0))->unknown_30_ < 0)
            return;
        var0 = 1;
    }
    memset(self->text_, 0, LOW_REGION(0x800, 0x960));
    TextTable02185cf8 functions = data_ov012_0218b108;
    TextFn02185cf8 none = __ptmf_null;
    functions.functions[0] = none;
    functions.functions[15] = none;
    if (functions.functions[self->state_] != 0)
        (self->*functions.functions[self->state_])(self->text_, hidden);
#if defined(jpn)
    func_0205d5d0((Struct_0205d5d0*)arg0->unknown_ac_, arg0->unknown_1371_, (int)arg0->unknown_1374_, 0);
#else
    func_0205d5d0((Struct_0205d5d0*)arg0->unknown_ac_, arg0->unknown_1371_, (int)arg0->unknown_1374_, 0, 0);
#endif
}
