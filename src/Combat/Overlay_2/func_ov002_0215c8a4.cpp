#include "std_library_functions.h"
#include <globaldefs.h>

extern "C" void func_ov002_02157030(void *base, int type, short *a, short *b, short *c, short *d);
extern "C" void func_ov002_0215be00(void *base, int a, int b, int c);
extern "C" void func_ov002_0215c988(void *base, void *dst, int flag);
#if defined(jpn)
#define RG(u, j) (j)
extern "C" void Window_OpenPane(void *a, void *b, int p2, int p3, int p4, int p5, int p6);
#else
#define RG(u, j) (u)
extern "C" void Window_OpenPane(void *a, void *b, int p2, int p3, int p4, int p5, int p6, int p7);
#endif

struct BufOv0215c8a4 {
    char pad[RG(0xbd0, 0xa98)];
    void *buf;
};
struct Struct_ov002_0215c8a4_2 {
    char pad[0x58];
    int count;
};

// USA: func_ov002_0215c8a4
extern "C" ARM void func_ov002_0215c8a4(char *base) {
    struct Struct_ov002_0215c8a4_2 *l = (struct Struct_ov002_0215c8a4_2 *) (base + RG(0x2c8 + 0xc00, 0xe20)) + 1;
    l--;
    int flag = 0;
    if (l->count > 1) {
        flag = 1;
    }
    short var2 = 0, var3 = 0, var4 = 1, var5 = 1;
    func_ov002_02157030(base, 4, &var2, &var3, &var4, &var5);
    var2 = var2 + var4;
    func_ov002_0215be00(base, 5, var2, 1);

    memset(((struct BufOv0215c8a4 *) (base + 0x1000))->buf, 0, RG(0x960, 0x800));
    func_ov002_0215c988(base, ((struct BufOv0215c8a4 *) (base + 0x1000))->buf, 0);

#if defined(jpn)
    Window_OpenPane(base + 0xe20, ((struct BufOv0215c8a4 *) (base + 0x1000))->buf, 0, 0, flag, 1, 0);
#else
    Window_OpenPane(base + 0xec8, ((struct BufOv0215c8a4 *) (base + 0x1000))->buf, 0, 0, flag, 1, 0, 0);
#endif
}
