#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Script.h"

#if defined(jpn)
enum { Enum_0208e894_220 = 0x27c, Enum_0208e894_23552 = 0x5800 };
#else
enum { Enum_0208e894_220 = 0xdc, Enum_0208e894_23552 = 0x5c00 };
#endif

struct Struct_0201c1c8;
extern "C" int _s32_div_f(int a, int b);
extern "C" void* LootPointList_GetInstance(void);

extern int data_02108fe4;

struct Struct_02108ff4 {
    unsigned short unknown_0_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
};

struct Struct_0208e894 {
    unsigned int unknown_0_0_ : 9;
    unsigned int unknown_1_1_ : 4;
    unsigned int unknown_1_5_ : 4;
    unsigned int unknown_2_1_ : 8;
    unsigned int unknown_3_1_ : 4;
    unsigned int unknown_3_5_ : 2;
    unsigned int unknown_3_7_ : 1;
};

// USA: func_0208e894
extern "C" ARM int func_0208e894(char* arg0) {
    struct Struct_0208e894* var0;
    struct Struct_02108ff4* var1;
    int var2 = ((Script::Parameter*)((struct Struct_0201c1c8*)arg0))->ToInt();
    int var3 = ((Script::Parameter*)((struct Struct_0201c1c8*)(arg0 + 0x10)))->ToInt();
    int var4 = ((Script::Parameter*)((struct Struct_0201c1c8*)(arg0 + 0x20)))->ToInt();
    int var5 = ((Script::Parameter*)((struct Struct_0201c1c8*)(arg0 + 0x28)))->ToInt();
    int var6 = ((Script::Parameter*)((struct Struct_0201c1c8*)(arg0 + 0x30)))->ToInt();
    int var7 = ((Script::Parameter*)((struct Struct_0201c1c8*)(arg0 + 0x38)))->ToInt();
    var0 = (struct Struct_0208e894*)((char*)GameState::GetInstance() + Enum_0208e894_220 + Enum_0208e894_23552);
    if (var4 == 8) {
        var0[var2].unknown_0_0_ = 0;
        var0[var2].unknown_1_1_ = var7;
        var0[var2].unknown_2_1_ = 0;
        var0[var2].unknown_3_1_ = _s32_div_f(var5, 30);
        var0[var2].unknown_1_5_ = var6;
        var0[var2].unknown_3_5_ = var3;
        var0[var2].unknown_3_7_ = 1;
    } else {
        tbl = (struct Entry02108ff4*)((char*)LootPointList_GetInstance() + 0x10);
        w[idx].f0 = 0;
        w[idx].f1 = tbl[k].c;
        w[idx].f3 = 0;
        w[idx].f4 = _s32_div_f(tbl[k].a, 30);
        w[idx].f2 = tbl[k].b;
        w[idx].f5 = p10;
        w[idx].f6 = 1;
    }
    return 1;
}
