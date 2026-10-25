#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x28
#define REGION_OFFSET_1 0x800
#else
#define REGION_OFFSET_0 0x5c
#define REGION_OFFSET_1 0x960
#endif

#include "std_library_functions.h"

struct Struct_0205d0e0 {
    char unknown_0_[0xC2];
    short unknown_c2_;
};
struct Struct_0205d81c;

extern "C" void func_ov000_0217964c(void* obj, void* entry);
extern "C" void func_ov000_0217ab8c(void* entry, int a, int b);
int GridCursor_GetCount(void* obj);
int MessageSystem_GetInstance();
extern "C" void func_ov000_0217979c(void* obj, void* entry, void* buf);
#if defined(jpn)
extern "C" void Window_OpenPane(void* a, void* b, int c, int d, int e, int f, int g);
#else
extern "C" void Window_OpenPane(void* a, void* b, int c, int d, int e, int f, int g, int h);
#endif
extern "C" struct Struct_0205d0e0* func_0205d81c(struct Struct_0205d81c* arg0, int arg1);
extern "C" void func_ov000_02176210(void* arg0, int arg1, int arg2);

// USA: func_ov000_021794cc
extern "C" ARM void func_ov000_021794cc(char* arg0, void* arg1, int arg2, int arg3) {
    func_ov000_0217964c(arg0, arg1);

    int var0 = *(int*)((char*)arg1 + 0x44);
    int var1 = *(int*)((char*)arg1 + 0x48);
    func_ov000_0217ab8c(arg1, arg2, arg3);

    char* var2 = arg0 + 0x188;
#if defined(jpn)
    *(short*)(var2 + 0xa0) = 0x10;
#else
    *(short*)(var2 + 0xa0) = 0x12;
#endif
    *(short*)(var2 + 0xa2) = 9;
#if defined(jpn)
    *(short*)(var2 + 0xa4) = (var0 >> 3) + 9;
#else
    *(short*)(var2 + 0xa4) = (var0 >> 3) + 0xe;
#endif
    *(short*)(var2 + 0xa6) = (var1 >> 3);
    *(short*)(var2 + 0xa8) = 0xc;
    *(short*)(var2 + 0xaa) = 8;
    *(short*)(var2 + 0xac) = 0xa;
    *(short*)(var2 + 0xae) = 0xc;
    *(unsigned char*)(var2 + 0xb1) = 0x11;

    int many = 0;
    if (GridCursor_GetCount(base + 0x54) > 4) many = 1;

    int g = MessageSystem_GetInstance();
    void* buf = *(void**)((char*)g + REGION_OFFSET_0);
    memset(buf, 0, REGION_OFFSET_1);
    func_ov000_0217979c(obj, entry, buf);
#if defined(jpn)
    Window_OpenPane(base, buf, 0, 0, many, 1, 0);
#else
    Window_OpenPane(base, buf, 0, 0, many, 1, 0, 0);
#endif

    struct Struct_0205d0e0* var6 = func_0205d81c((struct Struct_0205d81c*)var2, 0x24);
    if (var6 != NULL) var6->unknown_c2_ = 0;
    func_ov000_02176210(arg0 + 0x188, 0x11, 0x24);
}
