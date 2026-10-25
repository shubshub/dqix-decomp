#include <globaldefs.h>
#include "Graphics/GlyphMetrics.h"
#include "std_library_functions.h"

struct Struct_0202a6c4 {
    int unknown_0_;
    char unknown_4_[0x30];
    Struct_0202a6c4* unknown_34_;
    char unknown_38_[8];
    int unknown_40_;
    char unknown_44_[8];
    unsigned short unknown_4c_;
};

struct Struct_0202a6c4_2 {
    int unknown_0_;
    char unknown_4_[0x40];
    Struct_0202a6c4* unknown_44_;
    char unknown_48_[8];
    short unknown_50_;
    short unknown_52_;
    short unknown_54_;
    short unknown_56_;
    short unknown_58_;
    unsigned short unknown_5a_;
    short unknown_5c_;
    short unknown_5e_;
    short unknown_60_;
    unsigned short unknown_62_;
    short unknown_64_;
    short unknown_66_;
};

extern char data_020ef772[];
extern char data_020ef775[];
extern "C" int Font_GetTextWidth(const char*, int);
#if defined(jpn)
extern "C" void func_02028ce4(const char*, int*, int*);
#endif

static inline int inline_0202a6c4(int arg0, int arg1, unsigned int arg2, unsigned int arg3) {
    return arg3 - (arg2 - (arg0 - arg1));
}

// USA: func_0202a6c4
extern "C" ARM void func_0202a6c4(Struct_0202a6c4_2* arg0) {
    char var0[16];
    int var1 = strlen(arg0->unknown_4_);
    if (data_020ef74c.unknown_c_ >= 3 && data_020ef74c.unknown_c_ <= 6) {
        int var2;
        #if defined(jpn)
        int var3;
        func_02028ce4(arg0->unknown_4_, &var2, &var3);
#else
        if (menu->text != NULL) measured = Font_GetTextWidth(menu->text, 1);
#endif
        var2 /= data_020ef74c.unknown_8_;
        var1 = var2;
    }
    Struct_0202a6c4* var4 = arg0->unknown_44_;
    int var5 = 0;
    while (var4 != NULL) {
        int var6;
        if (data_020ef74c.unknown_c_ >= 3 && data_020ef74c.unknown_c_ <= 6) {
            int var7;
            #if defined(jpn)
            int var8;
            func_02028ce4(var4->unknown_4_, &var7, &var8);
#else
            if (entry->text != NULL) measured = Font_GetTextWidth(entry->text, 1);
#endif
            var7 /= data_020ef74c.unknown_8_;
            var6 = var7;
            if (arg0->unknown_5c_ >= 0 && arg0->unknown_5c_ <= arg0->unknown_5e_ &&
                arg0->unknown_5c_ <= var5 && var5 <= arg0->unknown_5e_)
                var6 += 2;
            if (var4->unknown_0_ == 2) var6 += 6;
            if (var4->unknown_0_ == 3) {
                var6 += 4;
                if (var4->unknown_4c_ & 0x80)
                    sprintf(var0, data_020ef772, var4->unknown_40_ + 0x40);
                else
                    sprintf(var0, data_020ef775, var4->unknown_40_);
                var6 += strlen(var0) * 2;
            }
        } else {
            var6 = strlen(var4->unknown_4_);
            if (arg0->unknown_5c_ >= 0 && arg0->unknown_5c_ <= arg0->unknown_5e_ &&
                arg0->unknown_5c_ <= var5 && var5 <= arg0->unknown_5e_)
                var6++;
            if (var4->unknown_0_ == 2) var6 += 3;
        }
        if (var1 < var6) var1 = var6;
        var4 = var4->unknown_34_;
        ++var5;
    }
    arg0->unknown_54_ = (var1 + 3) * data_020ef74c.unknown_8_;
    arg0->unknown_56_ = (arg0->unknown_5a_ + 3) * data_020ef74c.unknown_4_;
    if (arg0->unknown_50_ + arg0->unknown_56_ > 192)
        arg0->unknown_56_ = 192 - arg0->unknown_50_ - data_020ef74c.unknown_4_;
    arg0->unknown_62_ = arg0->unknown_56_ / data_020ef74c.unknown_4_ - 2;
    short var9 = arg0->unknown_5c_;
    int var10 = inline_0202a6c4(arg0->unknown_5e_, var9, arg0->unknown_5a_, arg0->unknown_62_);
    arg0->unknown_64_ = var9;
    arg0->unknown_66_ = var9 + var10;
}
