#include <globaldefs.h>

#if defined(jpn)
#define func_ov005_0215cb4c func_ov005_0215df2c
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif

struct Struct0209c830;

struct EquipmentMenu
{
    char unk_0[LOW_REGION(0x3d44, 0x3dcc)];
    unsigned int flags_;
    char unknown_3dd0_[0x3df3 - 0x3dd0];
    unsigned char unknown_3df3_;
};

extern "C" void func_0209c830(Struct0209c830* p, int value);
extern "C" int func_0209ca2c(void* obj);

extern "C" Struct0209c830 g_bgmPlayer;

// USA: func_ov005_0215cb4c
extern "C" ARM int func_ov005_0215cb4c(EquipmentMenu* self)
{
    if (!(self->flags_ & 0x10000))
        return 0;
    unsigned char step = self->unknown_3df3_;
    if (step == 0)
    {
        func_0209c830(&g_bgmPlayer, 0x3d);
        self->unknown_3df3_++;
    }
    if (step == 1)
    {
        if (func_0209ca2c(&g_bgmPlayer))
            return 1;
        self->flags_ &= ~0x10000;
        self->unknown_3df3_ = 0;
        return 0;
    }
    return 1;
}
