#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_ov002_0215be00(void* base, int a, int b, int c);
extern "C" void func_ov002_02160ce8(void* base, void* dst, int flag);
#if defined(jpn)
extern "C" void Window_OpenPane(void* a, void* b, int p2, int p3, int p4, int p5, int p6);
#else
extern "C" void Window_OpenPane(void* a, void* b, int p2, int p3, int p4, int p5, int p6, int p7);
#endif

#if defined(jpn)
struct BufOv02160c68 { char pad[0xa98]; void* buf; };
struct Struct_ov002_02160c68_2 { char pad[0xa80]; int field; };
#else
struct BufOv02160c68 { char pad[0xbd0]; void* buf; };
struct Struct_ov002_02160c68_2 { char pad[0xbb8]; int field; };
#endif

// USA: func_ov002_02160c68
#if defined(jpn)
extern "C" void func_ov002_02161c0c(void* base, void* dst, int flag);
#define func_ov002_02160ce8 func_ov002_02161c0c
extern "C" ARM void func_ov002_02160c68(char* base) {
    func_ov002_0215be00(base, ((struct Struct_ov002_02160c68_2*)(base + 0x1000))->field & 0xff, 1, 0xe);

    memset(((struct BufOv02160c68*)(base + 0x1000))->buf, 0, 0x800);
    func_ov002_02160ce8(base, ((struct BufOv02160c68*)(base + 0x1000))->buf, 0);

    Window_OpenPane(base + 0xe20, ((struct BufOv02160c68*)(base + 0x1000))->buf, 0, 0, 0, 1, 0);
}
#else
extern "C" ARM void func_ov002_02160c68(char* base) {
    func_ov002_0215be00(base, ((struct Struct_ov002_02160c68_2*)(base + 0x1000))->field & 0xff, 1, 0xe);

    memset(((struct BufOv02160c68*)(base + 0x1000))->buf, 0, 0x960);
    func_ov002_02160ce8(base, ((struct BufOv02160c68*)(base + 0x1000))->buf, 0);

    Window_OpenPane(base + 0xec8, ((struct BufOv02160c68*)(base + 0x1000))->buf, 0, 0, 0, 0, 0, 0);
}
#endif
