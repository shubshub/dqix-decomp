#include "std_library_functions.h"
#include <globaldefs.h>

extern "C" void func_ov002_02157030(void *arg0, int arg1, short *arg2, short *arg3, short *arg4, short *arg5);
extern "C" void func_ov002_0215be00(void *arg0, int arg1, int arg2, int arg3);
extern "C" void func_ov002_0215d950(void *arg0, void *arg1, int arg2);
#if defined(jpn)
#define RG(u, j) (j)
extern "C" int Window_OpenPane(void *a, void *b, int p2, int p3, int p4, int p5, int p6);
#else
#define RG(u, j) (u)
extern "C" int Window_OpenPane(void *a, void *b, int p2, int p3, int p4, int p5, int p6, int p7);
#endif

struct Struct_ov002_0215d864 {
    char unknown_0_[RG(0xbd0, 0xa98)];
    void *unknown_bd0_;
};
struct Struct_ov002_0215d864_2 {
    char unknown_0_[RG(0xbb8, 0xa80)];
    int unknown_bb8_;
};
struct Struct_ov002_0215d864_3 {
    char unknown_0_[0x58];
    int unknown_58_;
};

// USA: func_ov002_0215d864
extern "C" ARM int func_ov002_0215d864(char *arg0) {
    struct Struct_ov002_0215d864_3 *var0 = (struct Struct_ov002_0215d864_3 *) (arg0 + RG(0x2c8 + 0xc00, 0xe20)) + 1;
    var0--;
    int var1 = 0;
    if (var0->unknown_58_ > 1) {
        var1 = 1;
    }
    short var2 = 0, var3 = 0, var4 = 1, var5 = 1;
    func_ov002_02157030(arg0, 3, &var2, &var3, &var4, &var5);
    var2 = var2 + var4;
    func_ov002_0215be00(arg0, ((struct Struct_ov002_0215d864_2 *) (arg0 + 0x1000))->unknown_bb8_ & 0xff, var2, 1);

    memset(((struct Struct_ov002_0215d864 *) (arg0 + 0x1000))->unknown_bd0_, 0, RG(0x960, 0x800));
    func_ov002_0215d950(arg0, ((struct Struct_ov002_0215d864 *) (arg0 + 0x1000))->unknown_bd0_, 0);

#if defined(jpn)
    return Window_OpenPane(base + 0xe20, ((struct BufOv0215d864 *) (base + 0x1000))->buf, 0, 0, many, 1, 0);
#else
    return Window_OpenPane(base + 0xec8, ((struct BufOv0215d864 *) (base + 0x1000))->buf, 0, 0, many, 1, 0, 0);
#endif
}
