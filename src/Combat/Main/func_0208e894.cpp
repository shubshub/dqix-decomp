#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Script.h"

#if defined(jpn)
enum { Enum_0208e894_220 = 0x27c, Enum_0208e894_23552 = 0x5800 };
#else
enum { Enum_0208e894_220 = 0xdc, Enum_0208e894_23552 = 0x5c00 };
#endif

struct Variant02030b0c;
extern "C" int _s32_div_f(int a, int b);
extern "C" void* LootPointList_GetInstance(void);

extern int data_02108fe4;

struct Entry02108ff4 {
    unsigned short a;
    unsigned char b;
    unsigned char c;
};

struct Struct_0208e894 {
    unsigned int f0 : 9;
    unsigned int f1 : 4;
    unsigned int f2 : 4;
    unsigned int f3 : 8;
    unsigned int f4 : 4;
    unsigned int unknown_3_5_ : 2;
    unsigned int unknown_3_7_ : 1;
};

// USA: func_0208e894
extern "C" ARM int func_0208e894(char* v) {
    struct Struct_0208e894* w;
    struct Entry02108ff4* tbl;
    int idx = ((Script::Parameter*)((struct Variant02030b0c*)v))->ToInt();
    int p10 = ((Script::Parameter*)((struct Variant02030b0c*)(v + 0x10)))->ToInt();
    int k = ((Script::Parameter*)((struct Variant02030b0c*)(v + 0x20)))->ToInt();
    int var5 = ((Script::Parameter*)((struct Variant02030b0c*)(v + 0x28)))->ToInt();
    int p30 = ((Script::Parameter*)((struct Variant02030b0c*)(v + 0x30)))->ToInt();
    int var7 = ((Script::Parameter*)((struct Variant02030b0c*)(v + 0x38)))->ToInt();
    w = (struct Struct_0208e894*)((char*)GameState::GetInstance() + Enum_0208e894_220 + Enum_0208e894_23552);
    if (k == 8) {
        w[idx].f0 = 0;
        w[idx].f1 = var7;
        w[idx].f3 = 0;
        w[idx].f4 = _s32_div_f(var5, 30);
        w[idx].f2 = p30;
        w[idx].unknown_3_5_ = p10;
        w[idx].unknown_3_7_ = 1;
    } else {
        tbl = (struct Entry02108ff4*)((char*)LootPointList_GetInstance() + 0x10);
        w[idx].f0 = 0;
        w[idx].f1 = tbl[k].c;
        w[idx].f3 = 0;
        w[idx].f4 = _s32_div_f(tbl[k].a, 30);
        w[idx].f2 = tbl[k].b;
        w[idx].unknown_3_5_ = p10;
        w[idx].unknown_3_7_ = 1;
    }
    return 1;
}
