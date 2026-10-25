#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_ov002_0215be00(void* obj, int val, int a2, int a3);
void BuildStatusString_0215c178(void* a0, char* dst, int flag);
#if defined(jpn)
enum { FieldOffset = 0xa80, TextOffset = 0xa98, TextCapacity = 0x800, WindowOffset = 0xe20 };
#define FINAL_ARG_0215c0f8
extern "C" void Window_OpenPane(void* ptr, int val, int a2, int a3, int s0, int s1, int s2);
#else
enum { FieldOffset = 0xbb8, TextOffset = 0xbd0, TextCapacity = 0x960, WindowOffset = 0x2c8 + 0xc00 };
#define FINAL_ARG_0215c0f8 , 0
extern "C" void Window_OpenPane(void* ptr, int val, int a2, int a3, int s0, int s1, int s2, int s3);
#endif

// USA: func_ov002_0215c0f8  (semantic: InitBattleTag0215c0f8)
extern "C" ARM void func_ov002_0215c0f8(unsigned char* obj) {
    func_ov002_0215be00(obj, (*(int*)(obj + 0x1000 + FieldOffset)) & 0xff, 1, 1);

    memset(*(void**)(obj + 0x1000 + TextOffset), 0, TextCapacity);

    BuildStatusString_0215c178(obj, (char*)*(void**)(obj + 0x1000 + TextOffset), 0);

    Window_OpenPane(obj + WindowOffset, *(int*)(obj + 0x1000 + TextOffset), 0, 1, 0, 1, 0 FINAL_ARG_0215c0f8);
}
