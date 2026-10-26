#include "GameState/GameState.h"
#include "std_library_functions.h"
#include <globaldefs.h>

extern "C" void func_ov002_02157480(void *arg0, int *arg1);
extern "C" void func_ov002_0215be00(void *arg0, int arg1, int arg2, int arg3);
extern "C" void func_ov002_021605d4(void *arg0, void *arg1, int arg2);
extern "C" void func_ov002_0216049c(void *arg0, void *arg1, int arg2);
extern "C" void func_ov002_0215b9a4(void *arg0, int arg1, int arg2);
#if defined(jpn)
extern "C" void Window_OpenPane(void *arg0, void *arg1, int arg2, int arg3, int arg4, int arg5, int arg6);
#else
extern "C" void Window_OpenPane(void *arg0, void *arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7);
#endif
extern "C" unsigned char data_ov002_0216c9f9[];

struct Struct_0205d81c;
struct Struct_0205def8;
struct Elem_0205d81c {
    char unknown_0_[0xa8];
    short unknown_a8_;
    short unknown_aa_;
    short unknown_ac_;
    short unknown_ae_;
};
extern "C" struct Elem_0205d81c *func_0205d81c(struct Struct_0205d81c *arg0, int arg1);
struct Struct0205de24;
extern "C" void func_0205de24(struct Struct0205de24 *arg0, unsigned char arg1,
                                                                        unsigned char arg2);
extern "C" void Window_SetPanePalette(struct Struct_0205d81c *arg0, int arg1, int arg2);
extern "C" void func_0205def8(struct Struct_0205def8 *arg0, int arg1, int arg2);

struct Struct_ov002_02160274 {
    char unknown_0_[0xbd0];
    char *unknown_bd0_;
};
struct Struct_ov002_02160274_2 {
    char unknown_0_[0xbb8];
    int unknown_bb8_;
};

static inline int inline_ov002_02160274(int arg0) {
    return (arg0 >= 0 && arg0 <= 3) ? 1 : 0;
}
static inline void inline_ov002_02160274_2(struct Elem_0205d81c *arg0, short arg1, short arg2) {
    arg0->unknown_ac_ = arg1;
    arg0->unknown_ae_ = arg2;
}

// USA: func_ov002_02160274
extern "C" ARM void func_ov002_02160274(char *arg0) {
    int var0[4];
    GameState *var1 = GameState::GetInstance();
    func_ov002_02157480(arg0, var0);
    int var2 = 0;
    for (int var3 = 0; var3 < 4; var3++) {
        if (inline_ov002_02160274(var0[var3]) && func_0200ff1c(var1, var0[var3]) != NULL) {
            var2++;
        }
    }
    int var4 = var2 * 2;
    if (var2 == 1) var4++;
#if defined(jpn)
    func_ov002_0215be00(arg0, 0x21, 0x10, (short) (var4 + 10));
    memset(*(char **) (arg0 + 0x1000 + 0xa98), 0, 0x800);
    func_ov002_021605d4(arg0, *(char **) (arg0 + 0x1000 + 0xa98), 0);
    Window_OpenPane(arg0 + 0xe20, *(char **) (arg0 + 0x1000 + 0xa98), 0, 0, 0, 1, 0);

    func_0205de24((struct Struct0205de24 *) (arg0 + 0xe20), 0, 2);
    func_ov002_0215be00(arg0, *(int *) (arg0 + 0x1000 + 0xa80) & 0xff, 0x10, 8);
    memset(*(char **) (arg0 + 0x1000 + 0xa98), 0, 0x800);
    func_ov002_0216049c(arg0, *(char **) (arg0 + 0x1000 + 0xa98), 0);
    Window_OpenPane(arg0 + 0xe20, *(char **) (arg0 + 0x1000 + 0xa98), 0, 1, 0, 1, 0);

    Window_SetPanePalette((struct Struct_0205d81c *) (arg0 + 0xe20), 0x21, 0);
    func_0205def8((struct Struct_0205def8 *) (arg0 + 0xe20), 0, 0x2c);
#else
    func_ov002_0215be00(arg0, 0x20, 0x10, (short) (var4 + 10));
    memset(((struct Struct_ov002_02160274 *) (arg0 + 0x1000))->unknown_bd0_, 0, 0x960);
    func_ov002_021605d4(arg0, ((struct Struct_ov002_02160274 *) (arg0 + 0x1000))->unknown_bd0_, 0);
    Window_OpenPane(arg0 + 0xec8, ((struct Struct_ov002_02160274 *) (arg0 + 0x1000))->unknown_bd0_, 0, 0, 0, 1, 0, 0);

    func_0205de24((struct Struct0205de24 *) (arg0 + 0xec8), 0, 2);
    func_ov002_0215be00(arg0, ((struct Struct_ov002_02160274_2 *) (arg0 + 0x1000))->unknown_bb8_ & 0xff, 0x10, 8);
    memset(((struct Struct_ov002_02160274 *) (arg0 + 0x1000))->unknown_bd0_, 0, 0x960);
    func_ov002_0216049c(arg0, ((struct Struct_ov002_02160274 *) (arg0 + 0x1000))->unknown_bd0_, 0);
    Window_OpenPane(arg0 + 0xec8, ((struct Struct_ov002_02160274 *) (arg0 + 0x1000))->unknown_bd0_, 0, 1, 0, 1, 0, 0);

    Window_SetPanePalette((struct Struct_0205d81c *) (arg0 + 0xec8), 0x20, 0);
    func_0205def8((struct Struct_0205def8 *) (arg0 + 0xec8), 0, 0x29);
    struct Elem_0205d81c *var5 =
        func_0205d81c((struct Struct_0205d81c *) (arg0 + 0xec8), 0x15);
    if (var5 != NULL) {
        int var6 = var5->unknown_ac_ + var5->unknown_a8_;
        for (int var7 = 0; var7 < 2; var7++) {
            struct Elem_0205d81c *var8 = func_0205d81c(
                (struct Struct_0205d81c *) (arg0 + 0x2c8 + 0xc00), data_ov002_0216c9f9[var7]);
            if (var8 != NULL) {
                inline_ov002_02160274_2(var8, var6, var8->unknown_ae_);
            }
        }
    }
    func_ov002_0215b9a4(arg0, ((struct Struct_ov002_02160274_2 *) (arg0 + 0x1000))->unknown_bb8_ & 0xff, 0);
#endif
}
