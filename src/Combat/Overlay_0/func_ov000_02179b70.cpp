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
    char unknown_0_[0xc2];
    unsigned short unknown_c2_;
    char unknown_c4_[0xe0 - 0xc4];
};

struct Struct_0205d81c;

extern "C" void func_ov000_02179cdc(void* obj, void* ptr);
extern "C" void func_ov000_0217ab8c(void* obj, int a, int b);
int MessageSystem_GetInstance(void);
extern "C" void func_ov000_02179ed8(void* obj, void* entry, void* buf);
#if defined(jpn)
extern "C" void Window_OpenPane(void* a, void* b, int c, int d, int e, int f, int g);
#else
extern "C" void Window_OpenPane(void* a, void* b, int c, int d, int e, int f, int g, int h);
#endif
extern "C" struct Struct_0205d0e0* func_0205d81c(struct Struct_0205d81c* arg0, int arg1);
extern "C" void func_ov000_02176210(void* arg0, int arg1, int arg2);

// USA: func_ov000_02179b70
extern "C" ARM void func_ov000_02179b70(char* arg0, void* arg1, int arg2, int arg3) {
    func_ov000_02179cdc(arg0, arg1);
    int var0 = *(int*)((char*)arg1 + 0x44);
    int var1 = *(int*)((char*)arg1 + 0x48);
    func_ov000_0217ab8c(arg1, arg2, arg3);

    char* var2 = arg0 + 0x188;
#if defined(jpn)
    *(short*)(var2 + 0xa0) = 0xd;
#else
    *(short*)(var2 + 0xa0) = 0x10;
#endif
    *(short*)(var2 + 0xa2) = 1;
    *(short*)(var2 + 0xa4) = (var0 >> 3) + 0x10;
    *(short*)(var2 + 0xa6) = (var1 >> 3);
    *(short*)(var2 + 0xa8) = 0xc;
    *(short*)(var2 + 0xaa) = 0xa;
    *(short*)(var2 + 0xac) = 0xa;
    *(short*)(var2 + 0xae) = 0xe;
    *(unsigned char*)(var2 + 0xb1) = 0x15;

    void* buf = *(void**)(MessageSystem_GetInstance() + REGION_OFFSET_0);
    memset(buf, 0, REGION_OFFSET_1);
    func_ov000_02179ed8(obj, ptr, buf);
#if defined(jpn)
    Window_OpenPane(base, buf, 0, 1, 0, 1, 0);
#else
    Window_OpenPane(base, buf, 0, 1, 0, 1, 0, 0);
#endif

    struct Struct_0205d0e0* var4 = func_0205d81c((struct Struct_0205d81c*)var2, 0x16);
    if (var4 != NULL) {
        var4->unknown_c2_ = 0;
    }
    func_ov000_02176210(arg0 + 0x188, 0x15, 0x16);
}
