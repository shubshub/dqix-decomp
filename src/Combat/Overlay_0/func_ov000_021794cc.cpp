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
int GetGlobalField0x1c020421a0();
extern "C" void func_ov000_0217979c(void* obj, void* entry, void* buf);
#if defined(jpn)
extern "C" void func_0205d304(void* arg0, void* arg1, int arg2, int arg3, int arg4, int arg5, int arg6);
#else
extern "C" void func_0205d304(void* arg0, void* arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7);
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

    int var4 = func_020421a0();
    void* var5 = *(void**)((char*)var4 + REGION_OFFSET_0);
    memset(var5, 0, REGION_OFFSET_1);
    func_ov000_0217979c(arg0, arg1, var5);
#if defined(jpn)
    func_0205d304(var2, var5, 0, 0, var3, 1, 0);
#else
    func_0205d304(var2, var5, 0, 0, var3, 1, 0, 0);
#endif

    struct Struct_0205d0e0* var6 = func_0205d81c((struct Struct_0205d81c*)var2, 0x24);
    if (var6 != NULL) var6->unknown_c2_ = 0;
    func_ov000_02176210(arg0 + 0x188, 0x11, 0x24);
}
