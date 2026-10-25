#include "Combat/TryApplyElemFields.h"
#include <globaldefs.h>
#include "std_library_functions.h"

void NotifyLocalizedResourceLoad020dcfc8(int id, char* buf);
int MessageSystem_GetInstance();
extern "C" void MessageSystem_FormatText(int a, int b, void* fmt, void* dst, int p4, int p5, int p6);
struct Struct_0205d81c;
struct Struct_0205d0e0;
extern "C" struct Struct_0205d0e0* func_0205d81c(struct Struct_0205d81c* arg0, int arg1);
struct Struct_0205d5d0;
#if defined(jpn)
extern "C" void Window_OpenPane(void*, void*, int, int, int, int, int);
#define APPLY_TEXT(s,k,t) Window_SetPaneText(s,k,(int)t,1)
#define DRAW_TEXT(s,t) Window_OpenPane(s,t,0,0,0,1,0)
enum { textOffset=0x28, textSize=0x800, cursorOffset=0x1fa7, width=12, height=7, xOffset=0x16, lineHeight=8 };
#else
extern "C" void Window_OpenPane(void* s, void* buf, int a, int b, int c, int d, int e, int f);
#define APPLY_TEXT(s,k,t) Window_SetPaneText(s,k,(int)t,1,0)
#define DRAW_TEXT(s,t) Window_OpenPane(s,t,0,0,0,1,0,0)
enum { textOffset=0x5c, textSize=0x960, cursorOffset=0x1d6f, width=16, height=8, xOffset=0x10, lineHeight=5 };
#endif

struct Struct_ov000_021781f8 {
    char unknown_0_[0x44];
    int unknown_44_;
    int unknown_48_;
};

// USA: func_ov000_021781f8
extern "C" ARM void func_ov000_021781f8(char* arg0, struct Struct_ov000_021781f8* arg1) {
    char* var0;
    char* var1;
#if !defined(jpn)
    char var2[0x800];
#endif
    char* buf = *(char**)(MessageSystem_GetInstance() + textOffset);
    memset(buf, 0, textSize);
    NotifyLocalizedResourceLoad020dcfc8(*(short*)(obj + 0x26 + *(signed char*)(obj + cursorOffset) * 2), buf);
#if !defined(jpn)
    MessageSystem_FormatText(MessageSystem_GetInstance(), 0xa, buf, text, 0x72, 0, 0);
#endif
    var1 = arg0 + 0x188;
#if defined(jpn)
    var0 = var3;
#else
    var0 = var2;
#endif
    if (func_0205d81c((struct Struct_0205d81c*)var1, 0x21)) {
        APPLY_TEXT((struct Struct_0205d5d0*)var1, 0x21, var0);
        return;
    }
    int var4 = arg1->unknown_44_;
    int var5 = arg1->unknown_48_;
    *(short*)(var1 + 0xa0) = Enum_ov000_021781f8_16;
    *(short*)(var1 + 0xa2) = Enum_ov000_021781f8_8;
    *(short*)(var1 + 0xa4) = (var4 >> 3) + Enum_ov000_021781f8_16_2;
    *(short*)(var1 + 0xa6) = var5 >> 3;
    *(short*)(var1 + 0xa8) = 7;
    *(short*)(var1 + 0xaa) = Enum_ov000_021781f8_5;
    *(short*)(var1 + 0xac) = 0xa;
    *(short*)(var1 + 0xae) = 0xe;
    *(unsigned char*)(var1 + 0xb1) = 0x21;
    DRAW_TEXT(var1, var0);
}
