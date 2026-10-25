#include "std_library_functions.h"
#include <globaldefs.h>

struct Struct_ov002_02155960_2;
struct Struct_ov002_02155960_4;
extern "C" struct Struct_ov002_02155960_4 *func_0205d81c(struct Struct_ov002_02155960_2 *arg0, int arg1);
struct Struct_ov002_0215624c_11;
extern "C" void func_0205de24(struct Struct_ov002_0215624c_11 *arg0, unsigned char arg1,
                                                                        unsigned char arg2);
extern "C" void func_0205deb4(struct Struct_ov002_02155960_2 *arg0, int arg1, int arg2);
extern "C" void func_ov002_0215ee04(char *arg0);

struct Struct_0205d81c;
struct Elem_0205d81c;
struct Elem_0205d81c *FindElementByC40205d81c(struct Struct_0205d81c *s, int key);
struct Struct0205de24;
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
void Window_SetPanePalette(struct Struct_0205d81c *s, int key, int value);
void InitBattleTag0215ee04(char *base);

extern "C" void func_ov002_0215ef60(void *base);
extern "C" void func_ov002_02157030(void *base, int type, short *a, short *b, short *c, short *d);
extern "C" void func_ov002_0215be00(void *base, int a, int b, int c);
extern "C" void func_ov002_0215ec4c(void *base, void *dst, int flag);
#if defined(jpn)
#define RG(u, j) (j)
extern "C" void Window_OpenPane(void *a, void *b, int p2, int p3, int p4, int p5, int p6);
#else
#define RG(u, j) (u)
extern "C" void Window_OpenPane(void *a, void *b, int p2, int p3, int p4, int p5, int p6, int p7);
#endif

struct Struct_ov002_0215eadc {
    char unknown_0_[RG(0xbd0, 0xa98)];
    void *unknown_bd0_;
};
struct Struct_ov002_0215eadc_2 {
    char unknown_0_[RG(0xbb8, 0xa80)];
    int unknown_bb8_;
};
struct Struct_ov002_0215eadc_3 {
    char unknown_0_[0x58];
    int unknown_58_;
};

// USA: func_ov002_0215eadc
extern "C" ARM void func_ov002_0215eadc(char *arg0, int arg1) {
    struct Struct_ov002_0215eadc_3 *var0 = (struct Struct_ov002_0215eadc_3 *) (arg0 + RG(0x2c8 + 0xc00, 0xe20)) + 1;
    var0--;
    int var1 = 0;
    if (var0->unknown_58_ > 1) var1 = 1;
    if (arg1 == 0) {
        func_ov002_0215ee04(arg0);
        func_ov002_0215ef60(arg0);
    }
    func_0205de24((struct Struct_ov002_0215624c_11 *) (arg0 + RG(0xec8, 0xe20)), 0, 2);
    short var2 = 0, var3 = 0, var4 = 1, var5 = 1;
    func_ov002_02157030(arg0, RG(0x10, 0x11), &var2, &var3, &var4, &var5);
    var2    = var2 + var4;
    int var6 = ((struct Struct_ov002_0215eadc_2 *) (arg0 + 0x1000))->unknown_bb8_ & 0xff;
    if (arg1 != 0) var6 = RG(0x11, 0x12);
    if (func_0205d81c((struct Struct_ov002_02155960_2 *) (arg0 + RG(0xec8, 0xe20)), var6) == 0) {
        func_ov002_0215be00(arg0, var6, var2, var3);
        memset(((struct Struct_ov002_0215eadc *) (arg0 + 0x1000))->unknown_bd0_, 0, RG(0x960, 0x800));
        func_ov002_0215ec4c(arg0, ((struct Struct_ov002_0215eadc *) (arg0 + 0x1000))->unknown_bd0_, 0);
#if defined(jpn)
        Window_OpenPane(base + 0xe20, ((struct BufOv0215eadc *) (base + 0x1000))->buf, 0, 0, many, 1, 0);
#else
        Window_OpenPane(base + 0xec8, ((struct BufOv0215eadc *) (base + 0x1000))->buf, 0, 0, many, 1, 0, 0);
#endif
    }
    if (refresh == 0) {
        Window_SetPanePalette((struct Struct_0205d81c *) (base + RG(0xec8, 0xe20)), RG(0x12, 0x13), 0);
        Window_SetPanePalette((struct Struct_0205d81c *) (base + RG(0xec8, 0xe20)), RG(0x13, 0x14), 0);
    }
}
