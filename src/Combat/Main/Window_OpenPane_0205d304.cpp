#include <globaldefs.h>

struct Struct_0205d304_3 {
    short x;
    short y;
    inline void inline_0205d304(short newX, short newY) { x = newX; y = newY; }
};

struct Struct_0205d81c;
struct GridCursor;
struct Struct_0205d304_2;
struct Struct_0204aa28;

extern "C" void* func_0205d81c(struct Struct_0205d81c*, int);
extern "C" void func_0204c770(char*, void*);
extern "C" void func_0205d594(struct Struct_0205d304_2*, unsigned char*, unsigned char*);
#if defined(jpn)
extern "C" void func_0204d790(void* self, const char* text, unsigned int destination, int mode, unsigned char border, unsigned char fullWidth);
#else
extern "C" void func_0204c980(void* self, const char* text, unsigned int destination, int mode, unsigned char border, unsigned char fullWidth, unsigned char font);
#endif
extern "C" unsigned int func_0204aa28(struct Struct_0204aa28*);
extern "C" void GridCursor_ResetKeyRepeat(struct GridCursor*);
extern "C" void func_0205d904(unsigned char*);

struct Struct_0205d304_4 {
    char pad0[0x4];
    void* style;
    char pad8[0x98];
    unsigned int destination;
    int unknown_a4_;
    struct Struct_0205d304_3 layout[4];
    char unknown_b8_[0xa];
    short c2;
    unsigned char id;
    unsigned char flags;
    char unknown_c6_;
    unsigned char fontHeight;
    char unknown_c8_[0x18];
};

struct Ctx0205d304 {
    char pad0[0x54];
    char resetState[0x44];
    void* styles;
    struct Struct_0205d304_4* windows;
    struct Struct_0205d304_3 layout[4];
    unsigned char unknown_b0_;
    unsigned char unknown_b1_;
    char unknown_b2_;
    unsigned char unknown_b3_;
    unsigned char unknown_b4_;
    unsigned char unknown_b5_;
    unsigned char noHorizontalInset;
    unsigned char fontHeight;
};

// Main, originally func_0205d304 (USA 0x0205d304, EUR 0x0205d314, JPN 0x0205e634)
extern "C" ARM void Window_OpenPane(struct Ctx0205d304* renderer, const char* text, int mode, unsigned char border,
#if defined(jpn)
                                       unsigned char flagBit3, unsigned char fullWidth, void* extraStyle) {
#else
                                       unsigned char flagBit3, unsigned char fullWidth, void* extraStyle, unsigned char font) {
#endif
    struct Struct_0205d304_4* elem;
    struct Struct_0205d304_4* e;
    unsigned char var2, var3, var4, var5;
    int matched;
    int j;
    unsigned char i;
    unsigned int value;

    if (text == 0 || renderer->styles == NULL || renderer->windows == NULL) return;
    if (renderer->unknown_b3_ <= renderer->unknown_b4_) return;
    if (func_0205d81c((struct Struct_0205d81c*)renderer, renderer->unknown_b1_) != 0) return;

    elem = &renderer->windows[renderer->unknown_b4_];
    elem->layout[0].inline_0205d304(renderer->layout[0].x, renderer->layout[0].y);
    elem->layout[1].inline_0205d304(renderer->layout[1].x, renderer->layout[1].y);
    elem->layout[2].inline_0205d304(renderer->layout[2].x, renderer->layout[2].y);
    elem->layout[3].inline_0205d304(renderer->layout[3].x, renderer->layout[3].y);
    if (flagBit3) {
        elem->flags |= 8;
    } else {
        elem->flags &= ~8;
    }
    elem->id = renderer->unknown_b1_;
    if (renderer->unknown_b5_) {
        elem->flags |= 4;
    } else {
        elem->flags &= ~4;
    }
    if (renderer->noHorizontalInset) {
        elem->flags |= 0x10;
    } else {
        elem->flags &= ~0x10;
    }
    elem->fontHeight = renderer->fontHeight;
    func_0204c770((char*)elem, extraStyle);

    if (renderer->unknown_b4_ != 0) {
        matched = 0;
        func_0205d594((struct Struct_0205d304_2*)elem->style, &var2, &var3);
        for (j = renderer->unknown_b4_ - 1; j >= 0; j--) {
            e = &renderer->windows[j];
            func_0205d594((struct Struct_0205d304_2*)e->style, &var4, &var5);
            if (var2 == var4 && var3 == var5) {
                e = &renderer->windows[j];
                value = e->destination + e->unknown_a4_;
#if defined(jpn)
                func_0204d790(elem, text, value, mode, border, fullWidth);
#else
                func_0204c980(elem, text, value, mode, border, fullWidth, font);
#endif
                matched = 1;
                break;
            }
        }
        if (!matched) {
            value = func_0204aa28((struct Struct_0204aa28*)elem->style);
#if defined(jpn)
            func_0204d790(elem, text, value, mode, border, fullWidth);
#else
            func_0204c980(elem, text, value, mode, border, fullWidth, font);
#endif
        }
        elem->flags &= ~0x20;
        for (i = 0; i < renderer->unknown_b4_; i++) {
            e = &renderer->windows[i];
            e->c2 = 1;
        }
    } else {
        value = func_0204aa28((struct Struct_0204aa28*)elem->style);
#if defined(jpn)
        func_0204d790(elem, text, value, mode, border, fullWidth);
#else
        func_0204c980(elem, text, value, mode, border, fullWidth, font);
#endif
        elem->flags &= ~0x20;
    }

    renderer->unknown_b4_++;
    GridCursor_ResetKeyRepeat((struct GridCursor*)renderer->resetState);
    renderer->unknown_b0_ = renderer->unknown_b1_;
    func_0205d904((unsigned char*)renderer);
}
