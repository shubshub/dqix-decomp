#include "std_library_functions.h"
#include <globaldefs.h>

extern "C" void func_ov002_02157030(void *base, int type, short *a, short *b, short *c, short *d);
extern "C" void func_ov002_0215be00(void *base, int a, int b, int c);
extern "C" void func_ov002_0215d950(void *base, void *dst, int flag);
#if defined(jpn)
#define RG(u, j) (j)
extern "C" int Window_OpenPane(void *a, void *b, int p2, int p3, int p4, int p5, int p6);
#else
#define RG(u, j) (u)
extern "C" int Window_OpenPane(void *a, void *b, int p2, int p3, int p4, int p5, int p6, int p7);
#endif

struct BufOv0215d864 {
    char pad[RG(0xbd0, 0xa98)];
    void *buf;
};
struct Struct_ov002_0215d864_2 {
    char pad[RG(0xbb8, 0xa80)];
    int field;
};
struct Struct_ov002_0215d864_3 {
    char pad[0x58];
    int n;
};

// USA: func_ov002_0215d864
extern "C" ARM int func_ov002_0215d864(char *base) {
    struct Struct_ov002_0215d864_3 *l = (struct Struct_ov002_0215d864_3 *) (base + RG(0x2c8 + 0xc00, 0xe20)) + 1;
    l--;
    int many = 0;
    if (l->n > 1) {
        many = 1;
    }
    short var2 = 0, var3 = 0, var4 = 1, var5 = 1;
    func_ov002_02157030(base, 3, &var2, &var3, &var4, &var5);
    var2 = var2 + var4;
    func_ov002_0215be00(base, ((struct Struct_ov002_0215d864_2 *) (base + 0x1000))->field & 0xff, var2, 1);

    memset(((struct BufOv0215d864 *) (base + 0x1000))->buf, 0, RG(0x960, 0x800));
    func_ov002_0215d950(base, ((struct BufOv0215d864 *) (base + 0x1000))->buf, 0);

#if defined(jpn)
    return Window_OpenPane(base + 0xe20, ((struct BufOv0215d864 *) (base + 0x1000))->buf, 0, 0, many, 1, 0);
#else
    return Window_OpenPane(base + 0xec8, ((struct BufOv0215d864 *) (base + 0x1000))->buf, 0, 0, many, 1, 0, 0);
#endif
}
