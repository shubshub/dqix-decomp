#include "std_library_functions.h"
#include <globaldefs.h>

extern "C" void func_ov002_02157030(void *arg0, int arg1, short *arg2, short *arg3, short *arg4, short *arg5);
extern "C" void func_ov002_0215be00(void *arg0, int arg1, int arg2, int arg3);
extern "C" void func_ov002_021610c4(void *arg0, void *arg1, int arg2);
#if defined(jpn)
extern "C" void Window_OpenPane(void *a, void *b, int p2, int p3, int p4, int p5, int p6);
#else
extern "C" void Window_OpenPane(void *a, void *b, int p2, int p3, int p4, int p5, int p6, int p7);
#endif

struct Struct_0205d81c;
struct Struct_0205d0e0 {
    char unknown_0_[0xa8];
    short unknown_a8_;
    short unknown_aa_;
    short unknown_ac_;
    short unknown_ae_;
};
extern "C" struct Struct_0205d0e0 *func_0205d81c(struct Struct_0205d81c *arg0, int arg1);
extern "C" void func_0205d904(unsigned char *arg0);

struct Struct_ov002_02160fb4 {
#if defined(jpn)
    char unknown_0_[0xa98];
#else
    char unknown1_0_[0xbd0];
#endif
    void *unknown_bd0_;
};
struct Struct_ov002_02160fb4_2 {
#if defined(jpn)
    char unknown1_0_[0xa80];
#else
    char unknown_0_[0xbb8];
#endif
    int unknown_bb8_;
};

static inline void inline_ov002_02160fb4(struct Struct_0205d0e0 *arg0, short arg1, short arg2) {
    arg0->unknown_ac_ = arg1;
    arg0->unknown_ae_ = arg2;
}
static inline void inline_ov002_02160fb4_2(struct Struct_0205d0e0 *arg0, short arg1, short arg2) {
    arg0->unknown_a8_ = arg1;
    arg0->unknown_aa_ = arg2;
}

// USA: func_ov002_02160fb4
#if defined(jpn)
extern "C" ARM void func_ov002_02160fb4(char *arg0) {
    short var0, var1, var2, var3;
    func_ov002_0215be00(arg0, ((struct Struct_ov002_02160fb4_2 *) (arg0 + 0x1000))->unknown_bb8_ & 0xff, 1, 1);

    memset(((struct Struct_ov002_02160fb4 *) (arg0 + 0x1000))->unknown_bd0_, 0, 0x800);
    func_ov002_021610c4(arg0, ((struct Struct_ov002_02160fb4 *) (arg0 + 0x1000))->unknown_bd0_, 0);

    Window_OpenPane(base + 0xe20, ((struct BufOv02160fb4 *) (base + 0x1000))->buf, 0, 1, 0, 1, 0);

    struct Struct_0205d0e0 *var4 = func_0205d81c(
        (struct Struct_0205d81c *) (arg0 + 0xe20), ((struct Struct_ov002_02160fb4_2 *) (arg0 + 0x1000))->unknown_bb8_ & 0xff);
    if (var4 == NULL) return;

    func_ov002_02157030(arg0, ((struct Struct_ov002_02160fb4_2 *) (arg0 + 0x1000))->unknown_bb8_ & 0xff, &var0, &var1, &var2, &var3);
    var0 = 0x20 - var2;
    var1 = 0xf - var3;
    inline_ov002_02160fb4(var4, var0, var1);
    inline_ov002_02160fb4_2(var4, var2, var3);
    func_0205d904((unsigned char *) (arg0 + 0xe20));
}
#else
extern "C" ARM void func_ov002_02160fb4(char *arg0) {
    short var5, var6, var7, var8;
    func_ov002_0215be00(arg0, ((struct Struct_ov002_02160fb4_2 *) (arg0 + 0x1000))->unknown_bb8_ & 0xff, 1, 1);

    memset(((struct Struct_ov002_02160fb4 *) (arg0 + 0x1000))->unknown_bd0_, 0, 0x960);
    func_ov002_021610c4(arg0, ((struct Struct_ov002_02160fb4 *) (arg0 + 0x1000))->unknown_bd0_, 0);

    Window_OpenPane(base + 0xec8, ((struct BufOv02160fb4 *) (base + 0x1000))->buf, 0, 1, 0, 1, 0, 0);

    struct Struct_0205d0e0 *var9 = func_0205d81c(
        (struct Struct_0205d81c *) (arg0 + 0xec8), ((struct Struct_ov002_02160fb4_2 *) (arg0 + 0x1000))->unknown_bb8_ & 0xff);
    if (var9 == NULL) return;

    func_ov002_02157030(arg0, ((struct Struct_ov002_02160fb4_2 *) (arg0 + 0x1000))->unknown_bb8_ & 0xff, &var5, &var6, &var7, &var8);
    var5 = 0x20 - var7;
    var6 = 0xf - var8;
    inline_ov002_02160fb4(var9, var5, var6);
    inline_ov002_02160fb4_2(var9, var7, var8);
    func_0205d904((unsigned char *) (arg0 + 0xec8));
}
#endif
