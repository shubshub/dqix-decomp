#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_ov002_0215be00(void* obj, int val, int a2, int a3);
extern "C" void func_ov002_0215e9c4(void* obj, void* buf, int flag);
#if defined(jpn)
#define RG(u, j) (j)
extern "C" void Window_OpenPane(void* ptr, int val, int a2, int a3, int s0, int s1, int s2);
#else
#define RG(u, j) (u)
extern "C" void Window_OpenPane(void* ptr, int val, int a2, int a3, int s0, int s1, int s2, int s3);
#endif
extern "C" void func_ov002_0215eadc(void* obj, int val);

struct Struct_0205d81c;
extern "C" void Window_SetPanePalette(struct Struct_0205d81c* s, int key, int value);

struct Struct_0205dee8 {
    char pad0[0xb0];
    unsigned char fieldB0;
};
extern "C" void func_0205dee8(struct Struct_0205dee8* obj, int val);

// USA: func_ov002_0215e900
extern "C" ARM void func_ov002_0215e900(unsigned char* obj) {
    func_ov002_0215be00(obj, (*(int*)(obj + 0x1000 + RG(0xbb8, 0xa80))) & 0xff, 1, 1);

    memset(*(void**)(obj + 0x1000 + RG(0xbd0, 0xa98)), 0, RG(0x960, 0x800));

    func_ov002_0215e9c4(obj, *(void**)(obj + 0x1000 + RG(0xbd0, 0xa98)), 0);

#if defined(jpn)
    Window_OpenPane(obj + 0xe20, *(int*)(obj + 0x1000 + 0xa98), 0, 1, 0, 1, 0);
#else
    Window_OpenPane(obj + 0x2c8 + 0xc00, *(int*)(obj + 0x1000 + RG(0xbd0, 0xa98)), 0, 1, 0, 1, 0, 0);
#endif

    func_ov002_0215eadc(obj, 1);

    Window_SetPanePalette((struct Struct_0205d81c*)(obj + RG(0x2c8 + 0xc00, 0xe20)), RG(0x11, 0x12), 1);

    func_0205dee8((struct Struct_0205dee8*)(obj + RG(0x2c8 + 0xc00, 0xe20)), RG(0x10, 0x11));

    Window_SetPanePalette((struct Struct_0205d81c*)(obj + RG(0x2c8 + 0xc00, 0xe20)), RG(0x10, 0x11), 0);
}
