#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_ov002_02157030(void* base, int type, short* a, short* b, short* c, short* d);
extern "C" void func_ov002_0215be00(void* base, int a, int b, int c);
extern "C" void func_ov002_02160aa0(void* base, void* dst, int flag);
#if defined(jpn)
extern "C" void Window_OpenPane(void* a, void* b, int p2, int p3, int p4, int p5, int p6);
#else
extern "C" void Window_OpenPane(void* a, void* b, int p2, int p3, int p4, int p5, int p6, int p7);
#endif

#if defined(jpn)
struct BufOv021609d4 { char pad[0xa98]; void* buf; };
struct Struct_ov002_021609d4_2 { char pad[0xa80]; int field; };
#else
struct BufOv021609d4 { char pad[0xbd0]; void* buf; };
struct Struct_ov002_021609d4_2 { char pad[0xbb8]; int field; };
#endif

// USA: func_ov002_021609d4
#if defined(jpn)
struct Struct_0205d81c;
extern "C" void Window_SetPanePalette(struct Struct_0205d81c*, int, int);
extern "C" void func_ov002_02161938(void* base, void* dst, int flag);
#define func_ov002_02160aa0 func_ov002_02161938
extern "C" ARM void func_ov002_021609d4(char* base) {
    short var0 = 0, var1 = 0, var2 = 1, var3 = 1;
    func_ov002_02157030(base, 0x24, &var0, &var1, &var2, &var3);
    var0 = var0 + 0xc;
    func_ov002_0215be00(base, ((struct Struct_ov002_021609d4_2*)(base + 0x1000))->field & 0xff, 4, var1);

    memset(((struct BufOv021609d4*)(base + 0x1000))->buf, 0, 0x800);
    func_ov002_02160aa0(base, ((struct BufOv021609d4*)(base + 0x1000))->buf, 0);

    Window_OpenPane(base + 0xe20, ((struct BufOv021609d4*)(base + 0x1000))->buf, 0, 0, 0, 1, 0);
    Window_SetPanePalette((struct Struct_0205d81c*)(base + 0xe20), 0x22, 0);
    Window_SetPanePalette((struct Struct_0205d81c*)(base + 0xe20), 0x23, 0);
}
#else
extern "C" ARM void func_ov002_021609d4(char* base) {
    short var4 = 0, var5 = 0, var6 = 1, var7 = 1;
    func_ov002_02157030(base, 0x21, &var4, &var5, &var6, &var7);
    var4 = var4 + 0xc;
    func_ov002_0215be00(base, ((struct Struct_ov002_021609d4_2*)(base + 0x1000))->field & 0xff, 4, var5);

    memset(((struct BufOv021609d4*)(base + 0x1000))->buf, 0, 0x960);
    func_ov002_02160aa0(base, ((struct BufOv021609d4*)(base + 0x1000))->buf, 0);

    Window_OpenPane(base + 0xec8, ((struct BufOv021609d4*)(base + 0x1000))->buf, 0, 0, 1, 1, 0, 0);
}
#endif
