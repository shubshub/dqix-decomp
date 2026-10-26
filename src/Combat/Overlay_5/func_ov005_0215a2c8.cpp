#if defined(jpn)
#define func_ov005_0215a2c8 func_ov005_0215b81c
#endif

#include <globaldefs.h>
#include "Resource/GameResources.h"

#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif

struct EquipmentMenu {
    char unk_0[LOW_REGION(0x3d34, 0x3dbc)];
    unsigned char kind_;
    char unknown_3dbd_[0x3dcc - 0x3dbd];
    unsigned int flags_;
    char unknown_3dd0_[0x3df4 - 0x3dd0];
    unsigned char unknown_3df4_[8];
};

struct Struct_ov005_02159850 {
    char unk_0[LOW_REGION(0x34f8, 0x3708)];
    int* unknown_3708_;
};

extern "C" void* func_ov017_021a193c(int* p);
extern "C" void func_ov023_021e31e4(void* self, int arg1, int arg2, int arg3, short arg4);

// USA: func_ov005_0215a2c8
extern "C" ARM void func_ov005_0215a2c8(EquipmentMenu* self) {
    if (self->unknown_3df4_[self->kind_] == 1)
        return;
    short var0 = 0x8e;
    short var1 = 0xa0;
    if (self->flags_ & 0x20000) {
        var0--;
        var1++;
        self->flags_ &= ~0x20000;
    }
    short var2 = 0xeb;
    short var3 = 0xa0;
    if (self->flags_ & 0x40000) {
        var2++;
        var3++;
        self->flags_ &= ~0x40000;
    }
    func_ov023_021e31e4(func_ov017_021a193c(((Struct_ov005_02159850*)GetGameResources())->unknown_3708_), var0, var1, var2, var3);
}
