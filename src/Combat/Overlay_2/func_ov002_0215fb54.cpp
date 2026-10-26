#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_ov002_0215be00(void* base, int a, int b, int c);
extern "C" void func_ov002_0215fbd4(char* obj, char* dst, int flag);
#if defined(jpn)
enum { Enum_ov002_0215fb54_3000 = 0xa80, TextOffset = 0xa98, Enum_ov002_0215fb54_2400 = 0x800, WindowOffset = 0xe20, Enum_ov002_0215fb54_17 = 0x12 };
#define FINAL_ARG_0215fb54
extern "C" void Window_OpenPane(void* a, void* b, int p2, int p3, int p4, int p5, int p6);
#else
enum { Enum_ov002_0215fb54_3000 = 0xbb8, TextOffset = 0xbd0, Enum_ov002_0215fb54_2400 = 0x960, WindowOffset = 0xec8, Enum_ov002_0215fb54_17 = 0x11 };
#define FINAL_ARG_0215fb54 , 0
extern "C" void Window_OpenPane(void* a, void* b, int p2, int p3, int p4, int p5, int p6, int p7);
#endif

struct BufOv0215fb54 { char pad[TextOffset]; void* buf; };
struct Struct_ov002_0215fb54_2 { char pad[Enum_ov002_0215fb54_3000]; int field; };

// USA: func_ov002_0215fb54
extern "C" ARM void func_ov002_0215fb54(char* base) {
    func_ov002_0215be00(base, ((struct Struct_ov002_0215fb54_2*)(base + 0x1000))->field & 0xff, Enum_ov002_0215fb54_17, 1);

    memset(((struct BufOv0215fb54*)(base + 0x1000))->buf, 0, Enum_ov002_0215fb54_2400);
    func_ov002_0215fbd4(base, (char*)((struct BufOv0215fb54*)(base + 0x1000))->buf, 0);

    Window_OpenPane(base + WindowOffset, ((struct BufOv0215fb54*)(base + 0x1000))->buf, 0, 1, 0, 1, 0 FINAL_ARG_0215fb54);
}
