#include "std_library_functions.h"
#include <globaldefs.h>

extern "C" void func_ov002_0215be00(void *arg0, int arg1, int arg2, int arg3);
extern "C" void func_ov002_0215f4e8(void *arg0, void *arg1, int arg2);
#if defined(jpn)
extern "C" void Window_OpenPane(void *arg0, void *arg1, int arg2, int arg3, int arg4, int arg5, int arg6);
#else
extern "C" void Window_OpenPane(void *arg0, void *arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7);
#endif
extern "C" void func_ov002_0215f644(void *arg0, char *arg1, int);

struct Struct_0205d81c;
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

struct Struct_ov002_0215f3a0 {
    char unknown_0_[0xbd0];
    char *unknown_bd0_;
};
struct Struct_ov002_0215f3a0_2 {
    char unknown_0_[0xbb8];
    int unknown_bb8_;
};

static inline void inline_ov002_0215f3a0(struct Elem_0205d81c *arg0, short arg1, short arg2) {
    arg0->unknown_ac_ = arg1;
    arg0->unknown_ae_ = arg2;
}

// USA: func_ov002_0215f3a0
extern "C" ARM void func_ov002_0215f3a0(char *arg0) {
#if defined(jpn)
    func_ov002_0215be00(arg0, 0x17, 0x10, 1);
    memset(*(char **) (arg0 + 0x1000 + 0xa98), 0, 0x800);
    func_ov002_0215f644(arg0, *(char **) (arg0 + 0x1000 + 0xa98), 0);
    Window_OpenPane(arg0 + 0xe20, *(char **) (arg0 + 0x1000 + 0xa98), 0, 1, 0, 1, 0);

    func_0205de24((struct Struct0205de24 *) (arg0 + 0xe20), 0, 2);
    func_ov002_0215be00(arg0, *(int *) (arg0 + 0x1000 + 0xa80) & 0xff, 1, 1);
    memset(*(char **) (arg0 + 0x1000 + 0xa98), 0, 0x800);
    func_ov002_0215f4e8(arg0, *(char **) (arg0 + 0x1000 + 0xa98), 0);
    Window_OpenPane(arg0 + 0xe20, *(char **) (arg0 + 0x1000 + 0xa98), 0, 0, 0, 1, 0);
#else
    func_ov002_0215be00(arg0, 0x16, 0x10, 0x14);
    memset(((struct Struct_ov002_0215f3a0 *) (arg0 + 0x1000))->unknown_bd0_, 0, 0x960);
    func_ov002_0215f644(arg0, ((struct Struct_ov002_0215f3a0 *) (arg0 + 0x1000))->unknown_bd0_, 0);
    Window_OpenPane(arg0 + 0xec8, ((struct Struct_ov002_0215f3a0 *) (arg0 + 0x1000))->unknown_bd0_, 0, 0, 0, 0, 0, 0);

    func_0205de24((struct Struct0205de24 *) (arg0 + 0xec8), 0, 2);
    func_ov002_0215be00(arg0, ((struct Struct_ov002_0215f3a0_2 *) (arg0 + 0x1000))->unknown_bb8_ & 0xff, 1, 1);
    memset(((struct Struct_ov002_0215f3a0 *) (arg0 + 0x1000))->unknown_bd0_, 0, 0x960);
    func_ov002_0215f4e8(arg0, ((struct Struct_ov002_0215f3a0 *) (arg0 + 0x1000))->unknown_bd0_, 0);
    Window_OpenPane(arg0 + 0xec8, ((struct Struct_ov002_0215f3a0 *) (arg0 + 0x1000))->unknown_bd0_, 0, 0, 0, 1, 0, 0);

    struct Elem_0205d81c *var0 = func_0205d81c(
        (struct Struct_0205d81c *) (arg0 + 0xec8), ((struct Struct_ov002_0215f3a0_2 *) (arg0 + 0x1000))->unknown_bb8_ & 0xff);
    if (var0 == NULL) return;
    short var1 = var0->unknown_ac_;
    short var2 = var0->unknown_ae_;
    short var3 = var0->unknown_a8_;
    var0    = func_0205d81c((struct Struct_0205d81c *) (arg0 + 0xec8), 0x16);
    if (var0 != NULL) {
        inline_ov002_0215f3a0(var0, var1 + var3, var2);
    }
#endif
}
