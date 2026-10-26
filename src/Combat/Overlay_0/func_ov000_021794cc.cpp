#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x28
#define REGION_OFFSET_1 0x800
#else
#define REGION_OFFSET_0 0x5c
#define REGION_OFFSET_1 0x960
#endif

#include "std_library_functions.h"

struct Elem_0205d81c {
    char pad0[0xC2];
    short unknown_c2_;
};
struct Struct_0205d81c;

extern "C" void func_ov000_0217964c(void* obj, void* entry);
extern "C" void func_ov000_0217ab8c(void* entry, int a, int b);
extern "C" int GridCursor_GetCount(void* obj);
extern "C" int MessageSystem_GetInstance();
extern "C" void func_ov000_0217979c(void* obj, void* entry, void* buf);
#if defined(jpn)
extern "C" void Window_OpenPane(void* a, void* b, int c, int d, int e, int f, int g);
#else
extern "C" void Window_OpenPane(void* a, void* b, int c, int d, int e, int f, int g, int h);
#endif
extern "C" struct Elem_0205d81c* func_0205d81c(struct Struct_0205d81c* s, int key);
extern "C" void func_ov000_02176210(void* a, int b, int c);

// USA: func_ov000_021794cc
extern "C" ARM void func_ov000_021794cc(char* obj, void* entry, int a, int b) {
    func_ov000_0217964c(obj, entry);

    int var0 = *(int*)((char*)entry + 0x44);
    int var1 = *(int*)((char*)entry + 0x48);
    func_ov000_0217ab8c(entry, a, b);

    char* base = obj + 0x188;
#if defined(jpn)
    *(short*)(base + 0xa0) = 0x10;
#else
    *(short*)(base + 0xa0) = 0x12;
#endif
    *(short*)(base + 0xa2) = 9;
#if defined(jpn)
    *(short*)(base + 0xa4) = (var0 >> 3) + 9;
#else
    *(short*)(base + 0xa4) = (var0 >> 3) + 0xe;
#endif
    *(short*)(base + 0xa6) = (var1 >> 3);
    *(short*)(base + 0xa8) = 0xc;
    *(short*)(base + 0xaa) = 8;
    *(short*)(base + 0xac) = 0xa;
    *(short*)(base + 0xae) = 0xc;
    *(unsigned char*)(base + 0xb1) = 0x11;

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

    struct Elem_0205d81c* e = func_0205d81c((struct Struct_0205d81c*)base, 0x24);
    if (e != NULL) e->unknown_c2_ = 0;
    func_ov000_02176210(obj + 0x188, 0x11, 0x24);
}
