#include "std_library_functions.h"
#include <globaldefs.h>

struct Struct_0205d81c;
struct Elem_0205d81c;
extern "C" struct Elem_0205d81c *func_0205d81c(struct Struct_0205d81c *base, int arg1);
struct Struct0205de24;
extern "C" void func_0205de24(struct Struct0205de24 *base, unsigned char arg1,
                                                                        unsigned char arg2);
extern "C" void Window_SetPanePalette(struct Struct_0205d81c *base, int arg1, int arg2);
extern "C" void func_ov002_0215ee04(char *base);

extern "C" void func_ov002_0215ef60(void *base);
extern "C" void func_ov002_02157030(void *base, int arg1, short *arg2, short *arg3, short *arg4, short *arg5);
extern "C" void func_ov002_0215be00(void *base, int arg1, int arg2, int arg3);
extern "C" void func_ov002_0215ec4c(void *base, void *arg1, int arg2);
#if defined(jpn)
#define RG(u, j) (j)
extern "C" void Window_OpenPane(void *base, void *arg1, int arg2, int arg3, int arg4, int arg5, int arg6);
#else
#define RG(u, j) (u)
extern "C" void Window_OpenPane(void *base, void *arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7);
#endif

struct BufOv0215eadc {
    char pad[RG(0xbd0, 0xa98)];
    void *buf;
};
struct Struct_ov002_0215eadc_2 {
    char pad[RG(0xbb8, 0xa80)];
    int field;
};
struct Struct_ov002_0215eadc_3 {
    char pad[0x58];
    int count;
};

// USA: func_ov002_0215eadc
extern "C" ARM void func_ov002_0215eadc(char *base, int arg1) {
    struct Struct_ov002_0215eadc_3 *l = (struct Struct_ov002_0215eadc_3 *) (base + RG(0x2c8 + 0xc00, 0xe20)) + 1;
    l--;
    int many = 0;
    if (l->count > 1) many = 1;
    if (arg1 == 0) {
        func_ov002_0215ee04(base);
        func_ov002_0215ef60(base);
    }
    func_0205de24((struct Struct0205de24 *) (base + RG(0xec8, 0xe20)), 0, 2);
    short var2 = 0, var3 = 0, var4 = 1, var5 = 1;
    func_ov002_02157030(base, RG(0x10, 0x11), &var2, &var3, &var4, &var5);
    var2    = var2 + var4;
    int id = ((struct Struct_ov002_0215eadc_2 *) (base + 0x1000))->field & 0xff;
    if (arg1 != 0) id = RG(0x11, 0x12);
    if (func_0205d81c((struct Struct_0205d81c *) (base + RG(0xec8, 0xe20)), id) == 0) {
        func_ov002_0215be00(base, id, var2, var3);
        memset(((struct BufOv0215eadc *) (base + 0x1000))->buf, 0, RG(0x960, 0x800));
        func_ov002_0215ec4c(base, ((struct BufOv0215eadc *) (base + 0x1000))->buf, 0);
#if defined(jpn)
        Window_OpenPane(base + 0xe20, ((struct BufOv0215eadc *) (base + 0x1000))->buf, 0, 0, many, 1, 0);
#else
        Window_OpenPane(base + 0xec8, ((struct BufOv0215eadc *) (base + 0x1000))->buf, 0, 0, many, 1, 0, 0);
#endif
    }
    if (arg1 == 0) {
        Window_SetPanePalette((struct Struct_0205d81c *) (base + RG(0xec8, 0xe20)), RG(0x12, 0x13), 0);
        Window_SetPanePalette((struct Struct_0205d81c *) (base + RG(0xec8, 0xe20)), RG(0x13, 0x14), 0);
    }
}
