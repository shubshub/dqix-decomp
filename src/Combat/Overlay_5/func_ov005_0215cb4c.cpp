#include <globaldefs.h>

#if defined(jpn)
#define func_ov005_0215cb4c func_ov005_0215df2c
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif

struct Struct_02109bf4_2;

struct Struct_ov005_02153954
{
    char unknown_0_[LOW_REGION(0x3d44, 0x3dcc)];
    unsigned int unknown_3dcc_;
    char unknown_3dd0_[0x3df3 - 0x3dd0];
    unsigned char unknown_3df3_;
};

extern "C" void func_0209c830(Struct_02109bf4_2* arg0, int arg1);
extern "C" int func_0209ca2c(void* arg0);

extern "C" Struct0209c830 g_bgmPlayer;

// USA: func_ov005_0215cb4c
extern "C" ARM int func_ov005_0215cb4c(Struct_ov005_02153954* arg0)
{
    if (!(arg0->unknown_3dcc_ & 0x10000))
        return 0;
    unsigned char var0 = arg0->unknown_3df3_;
    if (var0 == 0)
    {
        SetValueAndActivate0209c830(&g_bgmPlayer, 0x3d);
        self->fadeStep_++;
    }
    if (var0 == 1)
    {
        if (IsAnimationActive0209ca2c(&g_bgmPlayer))
            return 1;
        arg0->unknown_3dcc_ &= ~0x10000;
        arg0->unknown_3df3_ = 0;
        return 0;
    }
    return 1;
}
