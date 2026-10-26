#include <globaldefs.h>
#include "std_library_functions.h"
#include "NitroSDK/Cache.h"

struct Struct_0204c980_2 {
    char padding[0x1c];
    unsigned char unknown_1c_0_ : 4;
    unsigned char unknown_1c_4_ : 4;
};

struct Struct_0204c980 {
    int field_0;
    Struct_0204c980_2* style;
    void* pixels;
    short unknown_c_[4][18];
    int dirty;
    unsigned int destination;
    unsigned int unknown_a4_;
    short width;
    short height;
    short field_ac;
    short unknown_ae_;
    short textX;
    char unknown_b2_[0xe];
    short cursorX;
    short cursorY;
    unsigned char field_c4;
    unsigned char flags;
    unsigned char unknown_c6_;
    unsigned char fontHeight;
    short mapWidth;
    short mapHeight;
    int field_cc;
    int unknown_d0_;
    void* unknown_d4_;
};

extern "C" void func_0204f0ec(char*);
extern "C" void* MessageSystem_GetInstance();
extern "C" int func_0204a5e4(int, int);
#if defined(jpn)
extern "C" void func_020474a8(void*, unsigned char, const char*, char*);
extern "C" short func_0204f6a0(Struct_0204c980*, char*, int, unsigned char, unsigned char);
extern "C" void func_0204daf8(Struct_0204c980*, char*, short);
#else
extern "C" void MessageSystem_FormatText(void*, unsigned char, const char*, char*, int, int, unsigned char);
extern "C" short func_0204e3e0(Struct_0204c980*, char*, int, unsigned char, unsigned char, unsigned char);
extern "C" void func_0204cd60(Struct_0204c980*, char*, short, short);
#endif
typedef void (*Type_0204c980)(const void*, unsigned int, unsigned int);

inline int inline_0204c980(int bank, int index) { return func_0204a5e4(index, bank); }

inline int inline_0204c980_2(Struct_0204c980_2* style) { return style->unknown_1c_4_; }

// USA: func_0204c980
#if defined(jpn)
extern "C" ARM void func_0204d790(Struct_0204c980* window, const char* text, unsigned int destination, int mode, unsigned char border, unsigned char fullWidth) {
#else
extern "C" ARM void func_0204c980(Struct_0204c980* window, const char* text, unsigned int destination, int mode, unsigned char border, unsigned char fullWidth, unsigned char font) {
#endif
    if (window->style && window->pixels && text) {
        func_0204f0ec((char*)window);
#if defined(jpn)
        char buffer[0x800] = {};
        func_020474a8(MessageSystem_GetInstance(), window->fontHeight, text, buffer);
        short padding = func_0204f6a0(window, buffer, mode, border, fullWidth);
        func_0204daf8(window, buffer, padding);
#else
        int width = window->width * 8;
        if (!(window->flags & 0x10)) width -= 4;
        if (fullWidth) width = 256;
        char buffer[0x800] = {};
        MessageSystem_FormatText(MessageSystem_GetInstance(), window->fontHeight, text, buffer, width, window->textX, font);
        short padding = func_0204e3e0(window, buffer, mode, border, fullWidth, font);
        func_0204cd60(window, buffer, padding, font);
#endif
        window->destination = destination;
        Type_0204c980 var5 = (Type_0204c980)inline_0204c980(inline_0204c980_2(window->style), window->style->unknown_1c_0_);
        CleanInvalidateCacheRange(window->pixels, window->unknown_a4_);
        var5(window->pixels, window->destination, window->unknown_a4_);
        if (window->flags & 1) {
            window->cursorX = 0;
            short height = window->height;
            short width = window->width;
            int length = width * height * 2;
            window->mapWidth = width;
            window->mapHeight = height;
            window->unknown_d0_ = length;
            window->cursorY = 0;
            window->dirty = 1;
        } else {
            window->flags |= 1;
            window->cursorX = 0;
            int length = window->width * window->height * 2;
            memset(window->unknown_d4_, 0, length);
            short height = window->height;
            short width = window->width;
            window->mapWidth = width;
            window->mapHeight = height;
            window->unknown_d0_ = length;
            window->cursorY = 0;
            window->dirty = 1;
        }
    }
}
