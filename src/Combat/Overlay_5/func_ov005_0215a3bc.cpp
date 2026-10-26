#include <globaldefs.h>
#include "Resource/GameResources.h"
#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif

#if defined(jpn)
#define func_ov005_0215a3bc func_ov005_0215b910
#endif

struct EquipmentMenu {
    char unknown_0[R(0x3d44, 0x3dcc)];
    unsigned int flags_;
};

struct Struct_ov005_02159850 {
    char unknown_0[R(0x34f8, 0x3708)];
    int* unknown_3708_;
};

extern "C" void* func_ov017_021a193c(int* p);
extern "C" void func_ov023_021e32cc(void* self, int x, int y);

// USA: func_ov005_0215a3bc
extern "C" ARM void func_ov005_0215a3bc(EquipmentMenu* self) {
    short x = R(0x81, 0x80);
    short y = R(0xb4, 0xb0);
    if (self->flags_ & 0x80000) {
        x++;
        y++;
        self->flags_ &= ~0x80000;
    }
    func_ov023_021e32cc(func_ov017_021a193c(((Struct_ov005_02159850*)GetGameResources())->unknown_3708_), x, y);
}
