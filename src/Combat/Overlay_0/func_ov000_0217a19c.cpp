#include "Combat/TryApplyElemFields.h"
#include <globaldefs.h>
#include "std_library_functions.h"

struct Container020e0310;
struct Struct_0205d81c;

struct StructA0205d5d0 {
    char unk_0[0xa0];
    short kind;
    short style;
    short x;
    short y;
    short width;
    short height;
    short unk_ac;
    short unknown_ae_;
    char unk_b0;
    unsigned char slot;
};

struct Struct_ov000_02170cf8 {
    char unk_0[4];
    unsigned int textId : 12;
    unsigned int unknown_5_4_ : 20;
};

extern "C" int MessageSystem_GetInstance();
extern "C" struct Struct_ov000_02170cf8* func_ov000_02170cf8(char* obj, int val);
extern "C" void func_020dd040(int len, char* buf);
extern "C" int KeyTable_Get(struct Container020e0310* c, int key);
extern "C" void MessageSystem_FormatText(int g, int b, char* src, char* dst, int size, int f, int h);
extern "C" void* func_0205d81c(struct Struct_0205d81c* s, int key);
#if defined(jpn)
extern "C" void Window_OpenPane(void*, void*, int, int, int, int, int);
#define APPLY_TEXT(s,k,t) Window_SetPaneText(s,k,(int)t,1)
#define DRAW_TEXT(s,t) Window_OpenPane(s,t,0,1,0,1,0)
enum { textOffset=0x28, textSize=0x800, Enum_ov000_0217a19c_7533=0x1fa5, style=6, y=0 };
#else
extern "C" void Window_OpenPane(void* a, void* b, int c, int d, int e, int f, int g, int h);
#define APPLY_TEXT(s,k,t) Window_SetPaneText(s,k,(int)t,1,0)
#define DRAW_TEXT(s,t) Window_OpenPane(s,t,0,0,0,1,0,0)
enum { textOffset=0x5c, textSize=0x960, Enum_ov000_0217a19c_7533=0x1d6d, style=7, y=0x18 };
#endif

// USA: func_ov000_0217a19c
extern "C" ARM void func_ov000_0217a19c(char* obj, char* table) {
    struct StructA0205d5d0* window;
#if !defined(jpn)
    char text[0x800];
#endif
    char* str = *(char**)(MessageSystem_GetInstance() + textOffset);
    memset(str, 0, textSize);
    signed char cursor = *(signed char*)(obj + Enum_ov000_0217a19c_7533);
    struct Struct_ov000_02170cf8* entry = func_ov000_02170cf8(table, *(unsigned short*)(obj + 0x10 + cursor * 2));
    if (entry != 0) {
        func_020dd040(entry->textId, str);
    } else {
        str = (char*)KeyTable_Get((struct Container020e0310*)(obj + 0xb8), 0x20);
    }
#if !defined(jpn)
    MessageSystem_FormatText(MessageSystem_GetInstance(), 0xa, str, text, 0x98, 0, 0);
#endif
    window = (struct StructA0205d5d0*)(obj + 0x188);
#if !defined(jpn)
    str = text;
#endif
    if (func_0205d81c((struct Struct_0205d81c*)window, 0x18) != 0) {
        APPLY_TEXT(window, 0x18, str);
        return;
    }
    window->kind = 0x16;
    window->style = style;
    window->x = 5;
    window->y = y;
    window->width = 0xc;
    window->height = 8;
    window->unk_ac = 0xa;
    window->unknown_ae_ = 0xe;
    window->slot = 0x18;
    DRAW_TEXT(window, str);
}
