#include <globaldefs.h>

#if defined(jpn)
#define func_ov023_021dcedc func_ov023_021dd7e0
#endif
#include "NitroSDK/Cache.h"
#include "NitroSDK/LoadToVRAM.h"

struct Struct_ov023_021dcedc {
#if defined(jpn)
    unsigned char unknown_0_[0x6f8];
#else
    unsigned char unknown1_0_[0x77c];
#endif
    signed char unknown_77c_;
    signed char unknown_77d_;
    unsigned char unknown_77e_[6];
    const char* unknown_784_[3];
    unsigned char unknown_790_[3];
    unsigned char unknown_793_[3];
    unsigned char unknown_796_[3];
    unsigned char unknown_799_;
};
#if defined(jpn)
struct Struct_ov023_021ff9e0_7 { int unknown_0_; int unknown_4_; int unknown_8_; int unknown_c_; int unknown_10_; int unknown1_4_; };
#define data_ov023_021fdb3b data_ov023_021fcdec
enum { Enum_ov023_021dcedc_5 = 5, Enum_ov023_021dcedc_192 = 0xb9, Enum_ov023_021dcedc_200 = 0xcb,
       Enum_ov023_021dcedc_70 = 0x46, Enum_ov023_021dcedc_170 = 0xaa, Enum_ov023_021dcedc_185 = 0xb9,
       Enum_ov023_021dcedc_1 = 1 };
#else
struct Struct_ov023_021ff9e0_7 { int unknown_0_; int unknown1_4_; int unknown_8_; int unknown_c_; };
enum { Enum_ov023_021dcedc_0_2 = 0, Enum_ov023_021dcedc_192 = 0xc0, Enum_ov023_021dcedc_200 = 0xc8,
       Enum_ov023_021dcedc_64 = 0x40, Enum_ov023_021dcedc_192_2 = 0xc0, Enum_ov023_021dcedc_200_2 = 0xc8,
       Enum_ov023_021dcedc_0 = 0 };
#endif
extern Struct_ov023_021ff9e0_7 data_ov023_021ff9e0;
extern char data_ov023_021fdb2d[];
extern char data_ov023_021fdb31[];
extern char data_ov023_021fdb35[];
extern char data_ov023_021fdb39[];
extern char data_ov023_021fdb3b[];
extern char data_ov023_021fdb3e[];
void* MessageSystem_GetInstance();
extern "C" int sprintf(char*, const char*, ...);
void CopyTextAndUppercaseIfFlagged0206819c(const char*, char*, int);
extern "C" void MessageSystem_FormatText(void*, int, const char*, char*, int, int, int);
#if defined(jpn)
extern "C" void func_02050678(void*, short, short, const char*, int, int, short*, short*);
#else
extern "C" void func_0204f41c(void*, short, short, const char*, int, int, short*, short*, int);
#endif
static inline void inline_ov023_021dcedc(void* arg0, short arg1, short arg2, const char* arg3, int arg4, int arg5) {
    short var0;
    short var1;
#if defined(jpn)
    func_02050678(arg0, arg1, arg2, arg3, arg4, arg5, &var1, &var0);
#else
    func_0204f41c(arg0, arg1, arg2, arg3, arg4, arg5, &var1, &var0, 0);
#endif
}

// USA: func_ov023_021dcedc
extern "C" ARM void func_ov023_021dcedc(Struct_ov023_021dcedc* arg0, void* arg1) {
    if (!data_ov023_021ff9e0.unknown1_4_) return;
    if (arg0->unknown_77c_ == 0) {
        unsigned short var0 = 0x110f;
        unsigned int var1 = data_ov023_021ff9e0.unknown_c_ * 32;
        CleanInvalidateCacheRange(&var0, 2);
        LoadToMainBGStandardPalette(&var0, var1 + 0x12, 2);
    }
    char var2[64] = {};
#if !defined(jpn)
    void* formatter = MessageSystem_GetInstance();
#endif
    for (int var4 = 0; var4 < 3; var4++) {
        const char* var5 = arg0->unknown_784_[var4];
        if (!var5) continue;
        unsigned char var6 = arg0->unknown_799_ * arg0->unknown_790_[var4];
        unsigned char var7 = arg0->unknown_793_[var4];
        unsigned char var8 = arg0->unknown_796_[var4];
        int var9 = 15;
        if (var6 > var7) var9 = 9;
        if (!var6) continue;
        if (arg0->unknown_77d_ == 1) {
            short var10 = var4 * 14 + 7;
#if defined(jpn)
            short var11 = var10 + Enum_ov023_021dcedc_1;
            inline_ov023_021dcedc(arg1, Enum_ov023_021dcedc_5, var10, var5, 10, var9);
#else
            char source[256] = {};
            char converted[256] = {};
            CopyTextAndUppercaseIfFlagged0206819c(name, source, 0);
            MessageSystem_FormatText(formatter, 10, source, converted, 0x400, 0, 0);
            DrawStatusText(canvas, ExpandedNameX, y, converted, 10, color);
#endif
            sprintf(var2, data_ov023_021fdb2d);
#if defined(jpn)
            inline_ov023_021dcedc(arg1, 0x72, var11, var2, 8, var9);
#else
            inline_ov023_021dcedc(arg1, 0x72, var10, var2, 8, var9);
#endif
            sprintf(var2, data_ov023_021fdb31, var6);
#if defined(jpn)
            inline_ov023_021dcedc(arg1, 0x7d, var11, var2, 8, var9);
#else
            inline_ov023_021dcedc(arg1, 0x7d, var10, var2, 8, var9);
#endif
            sprintf(var2, data_ov023_021fdb35, var7);
#if defined(jpn)
            inline_ov023_021dcedc(arg1, 0xa1, var11, var2, 8, var9);
#else
            inline_ov023_021dcedc(arg1, 0xa1, var10, var2, 8, var9);
#endif
            sprintf(var2, data_ov023_021fdb39);
            inline_ov023_021dcedc(arg1, Enum_ov023_021dcedc_192, var10, var2, 10, var9);
            sprintf(var2, data_ov023_021fdb3b, var8);
#if defined(jpn)
            inline_ov023_021dcedc(arg1, 0xc3, var11, var2, 8, var9);
#else
            inline_ov023_021dcedc(arg1, 0xc3, var10, var2, 8, var9);
#endif
            sprintf(var2, data_ov023_021fdb3e);
            inline_ov023_021dcedc(arg1, Enum_ov023_021dcedc_200, var10, var2, 10, var9);
        } else {
            short var14 = var4 * 14;
#if defined(jpn)
            short var15 = var14 + Enum_ov023_021dcedc_1;
            inline_ov023_021dcedc(arg1, Enum_ov023_021dcedc_70, var14, var5, 10, var9);
#else
            char source[256] = {};
            char converted[256] = {};
            CopyTextAndUppercaseIfFlagged0206819c(name, source, 0);
            MessageSystem_FormatText(formatter, 10, source, converted, 0x400, 0, 0);
            DrawStatusText(canvas, CollapsedNameX, y, converted, 10, color);
#endif
            sprintf(var2, data_ov023_021fdb2d);
#if defined(jpn)
            inline_ov023_021dcedc(arg1, Enum_ov023_021dcedc_170, var15, var2, 8, var9);
#else
            inline_ov023_021dcedc(arg1, Enum_ov023_021dcedc_192_2, var14, var2, 8, var9);
#endif
            sprintf(var2, data_ov023_021fdb31, var6);
#if defined(jpn)
            inline_ov023_021dcedc(arg1, Enum_ov023_021dcedc_185, var15, var2, 8, var9);
#else
            inline_ov023_021dcedc(arg1, Enum_ov023_021dcedc_200_2, var14, var2, 8, var9);
#endif
        }
    }
}
