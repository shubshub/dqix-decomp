#include "std_library_functions.h"
#include <globaldefs.h>

extern "C" void func_ov002_0215be00(void *base, int a, int b, int c);
extern "C" void func_ov002_0215f4e8(void *base, void *dst, int flag);
extern "C" void Window_OpenPane(void *a, void *b, int p2, int p3, int p4, int p5, int p6, int p7);
void AppendField0215f644(void *base, char *dst, int);

struct Struct_ov002_02155960_2;
struct Struct_ov002_02155960_4 {
    char unknown_0_[0xa8];
    short unknown_a8_;
    short unknown_aa_;
    short unknown_ac_;
    short unknown_ae_;
};
extern "C" struct Struct_ov002_02155960_4 *func_0205d81c(struct Struct_ov002_02155960_2 *arg0, int arg1);
struct Struct_ov002_0215624c_11;
extern "C" void func_0205de24(struct Struct_ov002_0215624c_11 *arg0, unsigned char arg1,
                                                                        unsigned char arg2);

struct Struct_ov002_0215f3a0 {
    char unknown_0_[0xbd0];
    char *unknown_bd0_;
};
struct Struct_ov002_0215f3a0_2 {
    char unknown_0_[0xbb8];
    int unknown_bb8_;
};

static inline void inline_ov002_0215f3a0(struct Struct_ov002_02155960_4 *arg0, short arg1, short arg2) {
    arg0->unknown_ac_ = arg1;
    arg0->unknown_ae_ = arg2;
}

// USA: func_ov002_0215f3a0
extern "C" ARM void func_ov002_0215f3a0(char *base) {
    func_ov002_0215be00(base, 0x16, 0x10, 0x14);
    memset(((struct BufOv0215f3a0 *) (base + 0x1000))->buf, 0, 0x960);
    AppendField0215f644(base, ((struct BufOv0215f3a0 *) (base + 0x1000))->buf, 0);
    Window_OpenPane(base + 0xec8, ((struct BufOv0215f3a0 *) (base + 0x1000))->buf, 0, 0, 0, 0, 0, 0);

    FindAndLinkMatchingEntry0205de24((struct Struct0205de24 *) (base + 0xec8), 0, 2);
    func_ov002_0215be00(base, ((struct FieldOv0215f3a0 *) (base + 0x1000))->field & 0xff, 1, 1);
    memset(((struct BufOv0215f3a0 *) (base + 0x1000))->buf, 0, 0x960);
    func_ov002_0215f4e8(base, ((struct BufOv0215f3a0 *) (base + 0x1000))->buf, 0);
    Window_OpenPane(base + 0xec8, ((struct BufOv0215f3a0 *) (base + 0x1000))->buf, 0, 0, 0, 1, 0, 0);

    func_0205de24((struct Struct_ov002_0215624c_11 *) (arg0 + 0xec8), 0, 2);
    func_ov002_0215be00(arg0, ((struct Struct_ov002_0215f3a0_2 *) (arg0 + 0x1000))->unknown_bb8_ & 0xff, 1, 1);
    memset(((struct Struct_ov002_0215f3a0 *) (arg0 + 0x1000))->unknown_bd0_, 0, 0x960);
    func_ov002_0215f4e8(arg0, ((struct Struct_ov002_0215f3a0 *) (arg0 + 0x1000))->unknown_bd0_, 0);
    func_0205d304(arg0 + 0xec8, ((struct Struct_ov002_0215f3a0 *) (arg0 + 0x1000))->unknown_bd0_, 0, 0, 0, 1, 0, 0);

    struct Struct_ov002_02155960_4 *var0 = func_0205d81c(
        (struct Struct_ov002_02155960_2 *) (arg0 + 0xec8), ((struct Struct_ov002_0215f3a0_2 *) (arg0 + 0x1000))->unknown_bb8_ & 0xff);
    if (var0 == NULL) return;
    short var1 = var0->unknown_ac_;
    short var2 = var0->unknown_ae_;
    short var3 = var0->unknown_a8_;
    var0    = func_0205d81c((struct Struct_ov002_02155960_2 *) (arg0 + 0xec8), 0x16);
    if (var0 != NULL) {
        inline_ov002_0215f3a0(var0, var1 + var3, var2);
    }
#endif
}
