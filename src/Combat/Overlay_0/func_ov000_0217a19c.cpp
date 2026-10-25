#include "Combat/TryApplyElemFields.h"
#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_0201099c_3;
struct Struct_0205d81c;

struct Struct_0205d5d0 {
    char unknown_0_[0xa0];
    short unknown_a0_;
    short unknown_a2_;
    short unknown_a4_;
    short unknown_a6_;
    short unknown_a8_;
    short unknown_aa_;
    short unknown_ac_;
    short unknown_ae_;
    char unknown_b0_;
    unsigned char unknown_b1_;
};

struct Struct_ov000_02170cf8 {
    char unknown_0_[4];
    unsigned int unknown_4_0_ : 12;
    unsigned int unknown_5_4_ : 20;
};

int MessageSystem_GetInstance();
extern "C" struct Entry02170cf8* func_ov000_02170cf8(char* obj, int val);
void NotifyLocalizedResourceLoad020dd040(int len, char* buf);
int KeyTable_Get(struct Container020e0310* c, int key);
extern "C" void MessageSystem_FormatText(int g, int b, char* src, char* dst, int size, int f, int h);
void* FindElementByC40205d81c(struct Struct_0205d81c* s, int key);
#if defined(jpn)
extern "C" void Window_OpenPane(void*, void*, int, int, int, int, int);
#define APPLY_TEXT(s,k,t) Window_SetPaneText(s,k,(int)t,1)
#define DRAW_TEXT(s,t) Window_OpenPane(s,t,0,1,0,1,0)
enum { textOffset=0x28, textSize=0x800, cursorOffset=0x1fa5, style=6, y=0 };
#else
extern "C" void Window_OpenPane(void* a, void* b, int c, int d, int e, int f, int g, int h);
#define APPLY_TEXT(s,k,t) Window_SetPaneText(s,k,(int)t,1,0)
#define DRAW_TEXT(s,t) Window_OpenPane(s,t,0,0,0,1,0,0)
enum { textOffset=0x5c, textSize=0x960, cursorOffset=0x1d6d, style=7, y=0x18 };
#endif

// USA: func_ov000_0217a19c
extern "C" ARM void func_ov000_0217a19c(char* arg0, char* arg1) {
    struct Struct_0205d5d0* var0;
#if !defined(jpn)
    char var1[0x800];
#endif
    char* str = *(char**)(MessageSystem_GetInstance() + textOffset);
    memset(str, 0, textSize);
    signed char cursor = *(signed char*)(obj + cursorOffset);
    struct Entry02170cf8* entry = func_ov000_02170cf8(table, *(unsigned short*)(obj + 0x10 + cursor * 2));
    if (entry != 0) {
        NotifyLocalizedResourceLoad020dd040(entry->textId, str);
    } else {
        str = (char*)KeyTable_Get((struct Container020e0310*)(obj + 0xb8), 0x20);
    }
#if !defined(jpn)
    MessageSystem_FormatText(MessageSystem_GetInstance(), 0xa, str, text, 0x98, 0, 0);
#endif
    var0 = (struct Struct_0205d5d0*)(arg0 + 0x188);
#if !defined(jpn)
    var2 = var1;
#endif
    if (func_0205d81c((struct Struct_0205d81c*)var0, 0x18) != 0) {
        APPLY_TEXT(var0, 0x18, var2);
        return;
    }
    var0->unknown_a0_ = 0x16;
    var0->unknown_a2_ = Enum_ov000_0217a19c_7;
    var0->unknown_a4_ = 5;
    var0->unknown_a6_ = Enum_ov000_0217a19c_24;
    var0->unknown_a8_ = 0xc;
    var0->unknown_aa_ = 8;
    var0->unknown_ac_ = 0xa;
    var0->unknown_ae_ = 0xe;
    var0->unknown_b1_ = 0x18;
    DRAW_TEXT(var0, var2);
}
