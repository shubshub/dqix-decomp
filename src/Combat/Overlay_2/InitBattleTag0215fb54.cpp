#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_ov002_0215be00(void* base, int a, int b, int c);
void AppendFieldRow0215fbd4(char* obj, char* dst, int flag);
#if defined(jpn)
enum { FieldOffset = 0xa80, TextOffset = 0xa98, TextCapacity = 0x800, WindowOffset = 0xe20, RowArg = 0x12 };
#define FINAL_ARG_0215fb54
extern "C" void Window_OpenPane(void* a, void* b, int p2, int p3, int p4, int p5, int p6);
#else
enum { FieldOffset = 0xbb8, TextOffset = 0xbd0, TextCapacity = 0x960, WindowOffset = 0xec8, RowArg = 0x11 };
#define FINAL_ARG_0215fb54 , 0
extern "C" void Window_OpenPane(void* a, void* b, int p2, int p3, int p4, int p5, int p6, int p7);
#endif

struct BufOv0215fb54 { char pad[TextOffset]; void* buf; };
struct FieldOv0215fb54 { char pad[FieldOffset]; int field; };

// USA: func_ov002_0215fb54  (semantic: InitBattleTag0215fb54)
extern "C" ARM void func_ov002_0215fb54(char* base) {
    func_ov002_0215be00(base, ((struct FieldOv0215fb54*)(base + 0x1000))->field & 0xff, RowArg, 1);

    memset(((struct BufOv0215fb54*)(base + 0x1000))->buf, 0, TextCapacity);
    AppendFieldRow0215fbd4(base, (char*)((struct BufOv0215fb54*)(base + 0x1000))->buf, 0);

    Window_OpenPane(base + WindowOffset, ((struct BufOv0215fb54*)(base + 0x1000))->buf, 0, 1, 0, 1, 0 FINAL_ARG_0215fb54);
}
