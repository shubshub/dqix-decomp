#include <globaldefs.h>
#include "std_library_functions.h"

#if defined(jpn)
#define RG(u, j) (j)
#else
#define RG(u, j) (u)
#endif

extern "C" void func_ov002_02157030(void* base, int type, short* a, short* b, short* c, short* d);
extern "C" void func_ov002_0215be00(void* base, int a, int b, int c);
extern "C" void func_ov002_0216186c(void* base, void* dst, int flag);
#if defined(jpn)
extern "C" void Window_OpenPane(void* a, void* b, int p2, int p3, int p4, int p5, int p6);
#else
extern "C" void Window_OpenPane(void* a, void* b, int p2, int p3, int p4, int p5, int p6, int p7);
#endif

struct BufOv02161798 { char pad[RG(0xbd0, 0xa98)]; void* buf; };
struct Struct_ov002_02161798_2 { char pad[RG(0xbb8, 0xa80)]; int field; };

// USA: func_ov002_02161798
extern "C" ARM void func_ov002_02161798(char* base) {
    short var0 = 0, var1 = 0, var2 = 1, var3 = 1;
    func_ov002_02157030(base, RG(0x27, 0x2a), &var0, &var1, &var2, &var3);
    var0 = var0 + 2;
    var1 = var1 + 0xb;
    func_ov002_0215be00(base, ((struct Struct_ov002_02161798_2*)(base + 0x1000))->field & 0xff, var0, var1);

    memset(((struct BufOv02161798*)(base + 0x1000))->buf, 0, RG(0x960, 0x800));
    func_ov002_0216186c(base, ((struct BufOv02161798*)(base + 0x1000))->buf, 0);

#if defined(jpn)
    Window_OpenPane(base + 0xe20, ((struct BufOv02161798*)(base + 0x1000))->buf, 0, 1, 0, 1, 0);
#else
    Window_OpenPane(base + 0xec8, ((struct BufOv02161798*)(base + 0x1000))->buf, 0, 1, 0, 1, 0, 0);
#endif
}
