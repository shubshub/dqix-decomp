#include <globaldefs.h>

#if defined(jpn)
#define func_ov023_021dcedc func_ov023_021dd7e0
#endif
#include "NitroSDK/Cache.h"
#include "NitroSDK/LoadToVRAM.h"

struct Struct_ov023_021dcedc {
#if defined(jpn)
    unsigned char padding0[0x6f8];
#else
    unsigned char padding0[0x77c];
#endif
    signed char unknown_77c_;
    signed char unknown_77d_;
    unsigned char unknown_77e_[6];
    const char* names[3];
    unsigned char unknown_790_[3];
    unsigned char unknown_793_[3];
    unsigned char unknown_796_[3];
    unsigned char unknown_799_;
};
#if defined(jpn)
struct Struct_ov023_021ff9e0_7 { int field0; int field4; int field8; int palette; int field10; int enabled; };
#define data_ov023_021fdb3b data_ov023_021fcdec
enum { Enum_ov023_021dcedc_5 = 5, Enum_ov023_021dcedc_192 = 0xb9, Enum_ov023_021dcedc_200 = 0xcb,
       Enum_ov023_021dcedc_70 = 0x46, Enum_ov023_021dcedc_170 = 0xaa, Enum_ov023_021dcedc_185 = 0xb9,
       Enum_ov023_021dcedc_1 = 1 };
#else
struct Struct_ov023_021ff9e0_7 { int field0; int enabled; int field8; int palette; };
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
extern "C" void* MessageSystem_GetInstance();
extern "C" int sprintf(char*, const char*, ...);
extern "C" void func_0206819c(const char*, char*, int);
extern "C" void MessageSystem_FormatText(void*, int, const char*, char*, int, int, int);
#if defined(jpn)
extern "C" void func_02050678(void*, short, short, const char*, int, int, short*, short*);
#else
extern "C" void func_0204f41c(void*, short, short, const char*, int, int, short*, short*, int);
#endif
static inline void inline_ov023_021dcedc(void* canvas, short x, short y, const char* text, int font, int color) {
    short height;
    short width;
#if defined(jpn)
    func_02050678(canvas, x, y, text, font, color, &width, &height);
#else
    func_0204f41c(canvas, x, y, text, font, color, &width, &height, 0);
#endif
}

// USA: func_ov023_021dcedc
extern "C" ARM void func_ov023_021dcedc(Struct_ov023_021dcedc* state, void* canvas) {
    if (!data_ov023_021ff9e0.enabled) return;
    if (state->unknown_77c_ == 0) {
        unsigned short color = 0x110f;
        unsigned int offset = data_ov023_021ff9e0.palette * 32;
        CleanInvalidateCacheRange(&color, 2);
        LoadToMainBGStandardPalette(&color, offset + 0x12, 2);
    }
    char text[64] = {};
#if !defined(jpn)
    void* formatter = MessageSystem_GetInstance();
#endif
    for (int i = 0; i < 3; i++) {
        const char* name = state->names[i];
        if (!name) continue;
        unsigned char var6 = state->unknown_799_ * state->unknown_790_[i];
        unsigned char limit = state->unknown_793_[i];
        unsigned char var8 = state->unknown_796_[i];
        int color = 15;
        if (var6 > limit) color = 9;
        if (!var6) continue;
        if (state->unknown_77d_ == 1) {
            short y = i * 14 + 7;
#if defined(jpn)
            short var11 = y + Enum_ov023_021dcedc_1;
            inline_ov023_021dcedc(canvas, Enum_ov023_021dcedc_5, y, name, 10, color);
#else
            char source[256] = {};
            char converted[256] = {};
            func_0206819c(name, source, 0);
            MessageSystem_FormatText(formatter, 10, source, converted, 0x400, 0, 0);
            inline_ov023_021dcedc(canvas, Enum_ov023_021dcedc_0_2, y, converted, 10, color);
#endif
            sprintf(text, data_ov023_021fdb2d);
#if defined(jpn)
            inline_ov023_021dcedc(canvas, 0x72, var11, text, 8, color);
#else
            inline_ov023_021dcedc(canvas, 0x72, y, text, 8, color);
#endif
            sprintf(text, data_ov023_021fdb31, var6);
#if defined(jpn)
            inline_ov023_021dcedc(canvas, 0x7d, var11, text, 8, color);
#else
            inline_ov023_021dcedc(canvas, 0x7d, y, text, 8, color);
#endif
            sprintf(text, data_ov023_021fdb35, limit);
#if defined(jpn)
            inline_ov023_021dcedc(canvas, 0xa1, var11, text, 8, color);
#else
            inline_ov023_021dcedc(canvas, 0xa1, y, text, 8, color);
#endif
            sprintf(text, data_ov023_021fdb39);
            inline_ov023_021dcedc(canvas, Enum_ov023_021dcedc_192, y, text, 10, color);
            sprintf(text, data_ov023_021fdb3b, var8);
#if defined(jpn)
            inline_ov023_021dcedc(canvas, 0xc3, var11, text, 8, color);
#else
            inline_ov023_021dcedc(canvas, 0xc3, y, text, 8, color);
#endif
            sprintf(text, data_ov023_021fdb3e);
            inline_ov023_021dcedc(canvas, Enum_ov023_021dcedc_200, y, text, 10, color);
        } else {
            short y = i * 14;
#if defined(jpn)
            short var15 = y + Enum_ov023_021dcedc_1;
            inline_ov023_021dcedc(canvas, Enum_ov023_021dcedc_70, y, name, 10, color);
#else
            char source[256] = {};
            char converted[256] = {};
            func_0206819c(name, source, 0);
            MessageSystem_FormatText(formatter, 10, source, converted, 0x400, 0, 0);
            inline_ov023_021dcedc(canvas, Enum_ov023_021dcedc_64, y, converted, 10, color);
#endif
            sprintf(text, data_ov023_021fdb2d);
#if defined(jpn)
            inline_ov023_021dcedc(canvas, Enum_ov023_021dcedc_170, var15, text, 8, color);
#else
            inline_ov023_021dcedc(canvas, Enum_ov023_021dcedc_192_2, y, text, 8, color);
#endif
            sprintf(text, data_ov023_021fdb31, var6);
#if defined(jpn)
            inline_ov023_021dcedc(canvas, Enum_ov023_021dcedc_185, var15, text, 8, color);
#else
            inline_ov023_021dcedc(canvas, Enum_ov023_021dcedc_200_2, y, text, 8, color);
#endif
        }
    }
}
