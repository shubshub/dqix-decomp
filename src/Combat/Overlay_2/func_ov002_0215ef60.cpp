#include "std_library_functions.h"
#include <globaldefs.h>

extern "C" void func_ov002_0215be00(void *base, int a, int b, int c);
extern "C" void func_ov002_0215f084(void *base, void *dst, int flag);
extern "C" void Window_OpenPane(void *a, void *b, int p2, int p3, int p4, int p5, int p6, int p7);

struct Struct_ov002_02155960_2;
struct Struct_ov002_02155960_4 {
    char unknown_0_[0xa8];
    short unknown_a8_;
    short unknown_aa_;
    short unknown_ac_;
    short unknown_ae_;
};
struct Elem_0205d81c *FindElementByC40205d81c(struct Struct_0205d81c *s, int key);
struct Struct0205de24;
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
struct StructA0205d5d0;
void Window_SetPaneText(struct StructA0205d5d0 *s, int key, int buf, int a3,
                                                                     unsigned char a4);

struct Struct_ov002_0215ef60 {
    char unknown_0_[0xbd0];
    void *unknown_bd0_;
};

static inline void inline_ov002_0215ef60(struct Struct_ov002_02155960_4 *arg0, short arg1, short arg2) {
    arg0->unknown_ac_ = arg1;
    arg0->unknown_ae_ = arg2;
}

// USA: func_ov002_0215ef60
extern "C" ARM void func_ov002_0215ef60(char *arg0) {
#if defined(jpn)
    func_0205de24((struct Struct_ov002_0215624c_11 *) (arg0 + 0xe20), 0, 2);
    func_ov002_0215be00(arg0, 0x14, 0x15, 8);

    memset(*(void **) (arg0 + 0x1000 + 0xa98), 0, 0x800);
    func_ov002_0215f084(arg0, *(void **) (arg0 + 0x1000 + 0xa98), 0);

    func_0205d304(arg0 + 0xe20, *(void **) (arg0 + 0x1000 + 0xa98), 0, 0, 0, 1, 0);
#else
    short var0 = 0x17;
    short var1 = 9;
    short var2 = 0;
    struct Struct_ov002_02155960_4 *var3 =
        func_0205d81c((struct Struct_ov002_02155960_2 *) (arg0 + 0xec8), 0x10);
    if (var3 != NULL) {
        var0 = var3->unknown_ac_;
        var2 = var3->unknown_a8_;
        var1 = var3->unknown_ae_ + var3->unknown_aa_;
    }
    func_0205de24((struct Struct_ov002_0215624c_11 *) (arg0 + 0xec8), 0, 2);
    func_ov002_0215be00(arg0, 0x13, var0, var1);

    memset(((struct Struct_ov002_0215ef60 *) (arg0 + 0x1000))->unknown_bd0_, 0, 0x960);
    func_ov002_0215f084(arg0, ((struct Struct_ov002_0215ef60 *) (arg0 + 0x1000))->unknown_bd0_, 0);

    Window_OpenPane(base + 0xec8, ((struct BufOv0215ef60 *) (base + 0x1000))->buf, 0, 0, 0, 1, 0, 0);

    elem = FindElementByC40205d81c((struct Struct_0205d81c *) (base + 0xec8), 0x13);
    if (elem == NULL) return;
    SetPos0215ef60(elem, x + w - elem->fa8, elem->fae);
    Window_SetPaneText((struct StructA0205d5d0 *) (base + 0xec8), 0x13,
                                                         (int) ((struct BufOv0215ef60 *) (base + 0x1000))->buf, 1, 0);
}
