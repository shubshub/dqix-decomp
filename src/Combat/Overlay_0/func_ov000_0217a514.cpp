#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x28
#define REGION_OFFSET_1 0x800
#else
#define REGION_OFFSET_0 0x5c
#define REGION_OFFSET_1 0x960
#endif

#include "std_library_functions.h"

struct Struct_0205ba68;
struct Struct_0205bacc;

extern "C" int func_ov000_0217538c(void* obj);
extern "C" int func_ov000_021753d8(void* obj, int targetIndex);
extern "C" void func_ov000_0217c638(void* obj, int a, int b);
void GridCursor_SetDimensions(struct Struct_0205ba68* s, int a, int b, int mode);
void GridCursor_SetCount(struct Node0205bacc* s, int val);
extern "C" void GridCursor_SetSelectedIndex(void* s, int n);
int GetGlobalField0x1c020421a0();
extern "C" void func_ov000_0217a688(void* obj, void* entry, int b, void* buf);
#if defined(jpn)
extern "C" void func_0205d304(void* arg0, void* arg1, int arg2, int arg3, int arg4, int arg5, int arg6);
#else
extern "C" void func_0205d304(void* arg0, void* arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7);
#endif

// USA: func_ov000_0217a514
extern "C" ARM void func_ov000_0217a514(char* arg0, char* arg1, int arg2, int arg3) {
    if (arg1 == NULL) return;

    int var0 = func_ov000_0217538c(arg0);
    int var1 = func_ov000_021753d8(arg0, *(signed char*)(arg1 + 0x1d));
    func_ov000_0217c638(arg0, arg2, arg3);

    char* var2 = arg0 + 0x188;
#if defined(jpn)
    *(short*)(var2 + 0xa0) = 1;
#else
    *(short*)(var2 + 0xa0) = 0x10;
#endif
    *(short*)(var2 + 0xa2) = 1;
    *(short*)(var2 + 0xa4) = 0xd;
    *(short*)(var2 + 0xa6) = 9;
    *(short*)(var2 + 0xa8) = 0xc;
    *(short*)(var2 + 0xaa) = 6;
    *(short*)(var2 + 0xac) = 0xa;
    *(short*)(var2 + 0xae) = 0x10;
    *(unsigned char*)(var2 + 0xb1) = 0x19;

    GridCursor_SetDimensions((struct Struct_0205ba68*)(obj + 0x244), 1, groups, 0);
    *(int*)(obj + 0x248) = 1;
    GridCursor_SetCount((struct Node0205bacc*)(obj + 0x244), groups);
    GridCursor_SetSelectedIndex(obj + 0x244, group);

    int var3 = func_020421a0();
    void* var4 = *(void**)((char*)var3 + REGION_OFFSET_0);
    memset(var4, 0, REGION_OFFSET_1);
    func_ov000_0217a688(arg0, arg1, arg3, var4);
#if defined(jpn)
    func_0205d304(var2, var4, 0, 1, 0, 1, 0);
#else
    func_0205d304(var2, var4, 0, 1, 0, 1, 0, 0);
#endif
}
