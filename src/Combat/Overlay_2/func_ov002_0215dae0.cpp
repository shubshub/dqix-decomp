#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_ov002_0215be00(void* obj, int val, int a2, int a3);
extern "C" void func_ov002_0215db8c(void* obj, void* ptr, int flag);
#if defined(jpn)
#define RG(u, j) (j)
extern "C" void func_ov002_02157030(void* base, int type, short* a, short* b, short* c, short* d);
extern "C" void Window_OpenPane(void* ptr, int val, int a2, int a3, int s0, int s1, int s2);
#else
#define RG(u, j) (u)
extern "C" void Window_OpenPane(void* ptr, int val, int a2, int a3, int s0, int s1, int s2, int s3);
#endif
extern "C" void func_ov002_0215ddbc(void* obj);

struct Struct_0205dee8 {
    char pad0[0xb0];
    unsigned char fieldB0;
};
extern "C" void func_0205dee8(struct Struct_0205dee8* obj, int val);

struct Struct_0205d81c;
extern "C" void Window_SetPanePalette(struct Struct_0205d81c* s, int key, int value);

// USA: func_ov002_0215dae0
extern "C" ARM void func_ov002_0215dae0(unsigned char* obj) {
#if defined(jpn)
    short var0 = 0, var1 = 0, var2 = 1, var3 = 1;
    func_ov002_02157030(obj, 4, &var0, &var1, &var2, &var3);
    var0 = var0 + var2;
    var1 -= 3;
    var0 -= 2;
    func_ov002_0215be00(obj, (*(int*)(obj + 0x1000 + 0xa80)) & 0xff, var0, var1);
#else
    func_ov002_0215be00(obj, (*(int*)(obj + 0x1000 + 0xbb8)) & 0xff, 5, 1);
#endif

    memset(*(void**)(obj + 0x1000 + RG(0xbd0, 0xa98)), 0, RG(0x960, 0x800));

    func_ov002_0215db8c(obj, *(void**)(obj + 0x1000 + RG(0xbd0, 0xa98)), 0);

#if defined(jpn)
    Window_OpenPane(obj + 0xe20, *(int*)(obj + 0x1000 + 0xa98), 0, 1, 0, 1, 0);
#else
    Window_OpenPane(obj + 0x2c8 + 0xc00, *(int*)(obj + 0x1000 + 0xbd0), 0, 1, 0, 1, 0, 0);
#endif

    func_ov002_0215ddbc(obj);

    func_0205dee8((struct Struct_0205dee8*)(obj + RG(0x2c8 + 0xc00, 0xe20)), RG(0xb, 0xc));

    Window_SetPanePalette((struct Struct_0205d81c*)(obj + RG(0x2c8 + 0xc00, 0xe20)), RG(0xb, 0xc), 0);
}
