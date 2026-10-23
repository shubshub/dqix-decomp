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

int GetGlobalField0x1c020421a0();
extern "C" struct Entry02170cf8* func_ov000_02170cf8(char* obj, int val);
void NotifyLocalizedResourceLoad020dd040(int len, char* buf);
int KeyTable_Get(struct Container020e0310* c, int key);
extern "C" void func_02046608(int g, int b, char* src, char* dst, int size, int f, int h);
void* FindElementByC40205d81c(struct Struct_0205d81c* s, int key);
#if defined(jpn)
extern "C" void func_0205d304(void*, void*, int, int, int, int, int);
#define APPLY_TEXT(s,k,t) func_0205d5d0(s,k,(int)t,1)
#define DRAW_TEXT(s,t) func_0205d304(s,t,0,1,0,1,0)
enum { Enum_ov000_0217a19c_92=0x28, Enum_ov000_0217a19c_2400=0x800, Enum_ov000_0217a19c_7533=0x1fa5, Enum_ov000_0217a19c_7=6, Enum_ov000_0217a19c_24=0 };
#else
extern "C" void func_0205d304(void* arg0, void* arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7);
#define APPLY_TEXT(s,k,t) func_0205d5d0(s,k,(int)t,1,0)
#define DRAW_TEXT(s,t) func_0205d304(s,t,0,0,0,1,0,0)
enum { Enum_ov000_0217a19c_92=0x5c, Enum_ov000_0217a19c_2400=0x960, Enum_ov000_0217a19c_7533=0x1d6d, Enum_ov000_0217a19c_7=7, Enum_ov000_0217a19c_24=0x18 };
#endif

// USA: func_ov000_0217a19c
extern "C" ARM void func_ov000_0217a19c(char* arg0, char* arg1) {
    struct Struct_0205d5d0* var0;
#if !defined(jpn)
    char var1[0x800];
#endif
    char* var2 = *(char**)(func_020421a0() + Enum_ov000_0217a19c_92);
    memset(var2, 0, Enum_ov000_0217a19c_2400);
    signed char var3 = *(signed char*)(arg0 + Enum_ov000_0217a19c_7533);
    struct Struct_ov000_02170cf8* var4 = func_ov000_02170cf8(arg1, *(unsigned short*)(arg0 + 0x10 + var3 * 2));
    if (var4 != 0) {
        func_020dd040(var4->unknown_4_0_, var2);
    } else {
        str = (char*)KeyTable_Get((struct Container020e0310*)(obj + 0xb8), 0x20);
    }
#if !defined(jpn)
    func_02046608(func_020421a0(), 0xa, var2, var1, 0x98, 0, 0);
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
