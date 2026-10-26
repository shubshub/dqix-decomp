#include "Combat/TryApplyElemFields.h"
#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_020dcfc8(int id, char* buf);
extern "C" int MessageSystem_GetInstance();
extern "C" void MessageSystem_FormatText(int a, int b, void* fmt, void* dst, int p4, int p5, int p6);
struct Struct_0205d81c;
struct Elem_0205d81c;
extern "C" struct Elem_0205d81c* func_0205d81c(struct Struct_0205d81c* s, int key);
struct StructA0205d5d0;
#if defined(jpn)
extern "C" void Window_OpenPane(void*, void*, int, int, int, int, int);
#define APPLY_TEXT(s,k,t) Window_SetPaneText(s,k,(int)t,1)
#define DRAW_TEXT(s,t) Window_OpenPane(s,t,0,0,0,1,0)
enum { textOffset=0x28, textSize=0x800, Enum_ov000_021781f8_7535=0x1fa7, width=12, height=7, xOffset=0x16, lineHeight=8 };
#else
extern "C" void Window_OpenPane(void* s, void* buf, int a, int b, int c, int d, int e, int f);
#define APPLY_TEXT(s,k,t) Window_SetPaneText(s,k,(int)t,1,0)
#define DRAW_TEXT(s,t) Window_OpenPane(s,t,0,0,0,1,0,0)
enum { textOffset=0x5c, textSize=0x960, Enum_ov000_021781f8_7535=0x1d6f, width=16, height=8, xOffset=0x10, lineHeight=5 };
#endif

struct Struct_ov000_021781f8 {
    char pad[0x44];
    int x;
    int y;
};

// USA: func_ov000_021781f8
extern "C" ARM void func_ov000_021781f8(char* obj, struct Struct_ov000_021781f8* in) {
    char* msg;
    char* s;
#if !defined(jpn)
    char text[0x800];
#endif
    char* buf = *(char**)(MessageSystem_GetInstance() + textOffset);
    memset(buf, 0, textSize);
    func_020dcfc8(*(short*)(obj + 0x26 + *(signed char*)(obj + Enum_ov000_021781f8_7535) * 2), buf);
#if !defined(jpn)
    MessageSystem_FormatText(MessageSystem_GetInstance(), 0xa, buf, text, 0x72, 0, 0);
#endif
    s = obj + 0x188;
#if defined(jpn)
    msg = buf;
#else
    msg = text;
#endif
    if (func_0205d81c((struct Struct_0205d81c*)s, 0x21)) {
        APPLY_TEXT((struct StructA0205d5d0*)s, 0x21, msg);
        return;
    }
    int x = in->x;
    int y = in->y;
    *(short*)(s + 0xa0) = width;
    *(short*)(s + 0xa2) = height;
    *(short*)(s + 0xa4) = (x >> 3) + xOffset;
    *(short*)(s + 0xa6) = y >> 3;
    *(short*)(s + 0xa8) = 7;
    *(short*)(s + 0xaa) = lineHeight;
    *(short*)(s + 0xac) = 0xa;
    *(short*)(s + 0xae) = 0xe;
    *(unsigned char*)(s + 0xb1) = 0x21;
    DRAW_TEXT(s, msg);
}
