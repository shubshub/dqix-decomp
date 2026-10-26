#include <globaldefs.h>
#include "std_library_functions.h"

#if defined(jpn)
#define func_ov004_0215de9c func_ov002_0215ef64
#endif

extern "C" void func_ov002_02157030(void* obj, unsigned char flag, short* arg2, short* arg3, short* arg4, short* arg5);
struct Struct0205de24;
extern "C" void func_0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);
extern "C" void func_ov002_0215be00(void* obj, int a1, int a2, int a3);
extern "C" void func_ov004_0215de9c(void* obj, void* buf, int zero);
#if defined(jpn)
#define RG(u, j) (j)
extern "C" void Window_OpenPane(void* a, void* b, int c, int d, int e, int f, int g);
#else
#define RG(u, j) (u)
extern "C" void Window_OpenPane(void* a, void* b, int c, int d, int e, int f, int g, int h);
#endif

// USA: func_ov002_0215ddbc
extern "C" ARM void func_ov002_0215ddbc(unsigned char* obj) {
    short var0 = 0, var1 = 0, var2 = 1, var3 = 1;
    unsigned char var4 = (unsigned char)*(int*)(obj + 0x1000 + RG(0xbb8, 0xa80));
    func_ov002_02157030(obj, var4, &var0, &var1, &var2, &var3);
    var0 = var0 + var2;
    func_0205de24((struct Struct0205de24*)(obj + RG(0x2c8 + 0xc00, 0xe20)), 0, 3);
    func_ov002_0215be00(obj, RG(0xd, 0xe), var0, var1);
    memset(*(void**)(obj + 0x1000 + RG(0xbd0, 0xa98)), 0, RG(0x960, 0x800));
    func_ov004_0215de9c(obj, *(void**)(obj + 0x1000 + RG(0xbd0, 0xa98)), 0);
#if defined(jpn)
    Window_OpenPane(obj + 0xe20, *(void**)(obj + 0x1000 + 0xa98), 0, 0, 0, 1, 0);
#else
    Window_OpenPane(obj + 0x2c8 + 0xc00, *(void**)(obj + 0x1000 + RG(0xbd0, 0xa98)), 0, 0, 0, 1, 0, 0);
#endif
}
