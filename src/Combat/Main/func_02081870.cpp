#include <globaldefs.h>
#include <std_library_functions.h>

#if defined(jpn)
#define func_0204f41c func_02050678
#endif

struct TableA68;
struct Obj02046574;
struct TextRenderer {
    TableA68* strings;
    char unknown_4_[0x14];
    char* buffer;
};
struct TextWindow {
    char unknown_0_[0xa8];
    short width;
    char unknown_aa_[0xa];
    short unknown_b4_;
    short unknown_b6_;
};
struct Struct_02081870_3 {
    char* name;
    short id;
    short x;
    short y;
    short width;
    short height;
    short unknown_e_;
    short nameIndex;
    unsigned char unknown_12_;
    unsigned char font : 4;
    unsigned char color : 4;
    unsigned char alignment : 2;
    unsigned char unknown_14_2_ : 6;
    char unknown_15_[0x13];
    short xOffset;
    unsigned char flags;
};
extern "C" int func_02042190(int);
extern "C" void* func_02072a68(TableA68*, int);
extern "C" int Font_GetTextWidth(char*, int);
extern "C" int MessageSystem_GetInstance();
extern "C" void func_02046380(Obj02046574*);
extern "C" void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
#if defined(jpn)
extern "C" int STD_GetStringLength(const char*);
extern "C" void func_020474a8(Obj02046574*, int, void*, char*);
extern "C" void func_0204f41c(TextWindow*, short, int, char*, int, int, short*, short*);
#else
extern "C" void MessageSystem_FormatText(Obj02046574*, int, void*, char*, int, int, int);
extern "C" void func_0204f41c(TextWindow*, short, int, char*, int, int, short*, short*, int);
#endif

// USA: func_02081870
#if defined(jpn)
extern "C" ARM void func_02081870(TextRenderer* renderer, TextWindow* window, Struct_02081870_3* item) {
    int color = item->color;
    if (item->flags & 4) color = 5;
    if (item->flags & 8) {
        char* text = (char*)func_02072a68(renderer->strings, item->unknown_e_);
        if (text) {
            short width = window->width * 8;
            int half = STD_GetStringLength(text) >> 1;
            item->x = (short)(width - half * item->font) >> 1;
        }
    }
    Obj02046574* formatter = (Obj02046574*)MessageSystem_GetInstance();
    memset(renderer->buffer, 0, 0x800);
    func_02046380(formatter);
    MessageSystem_SetStringArgument(formatter, item->nameIndex, item->name);
    void* text = func_02072a68(renderer->strings, item->unknown_e_);
    func_020474a8(formatter, item->font, text, renderer->buffer);
    int var6 = item->font;
    window->unknown_b4_ = var6;
    window->unknown_b6_ = var6 + 1;
    if (item->flags & 0x10) {
        int var7 = item->font;
        if (var7 == 12) {
            window->unknown_b4_ = var7;
            window->unknown_b6_ = 20;
        }
    }
    func_0204f41c(window, (short)(item->x + item->xOffset), item->y,
        renderer->buffer, item->font, color, &item->width, &item->height);
}
#else
extern "C" ARM void func_02081870(TextRenderer* renderer, TextWindow* window, Struct_02081870_3* item) {
    int color = item->color;
    if (item->flags & 4) color = 5;
    int font = func_02042190(item->font);
    if (item->flags & 8) {
        char* text = (char*)func_02072a68(renderer->strings, item->unknown_e_);
        if (text) {
            short width = window->width * 8;
            item->x = (short)(width - Font_GetTextWidth(text, font)) >> 1;
        }
    }
    Obj02046574* formatter = (Obj02046574*)MessageSystem_GetInstance();
    memset(renderer->buffer, 0, 0x960);
    func_02046380(formatter);
    MessageSystem_SetStringArgument(formatter, item->nameIndex, item->name);
    void* text = func_02072a68(renderer->strings, item->unknown_e_);
    MessageSystem_FormatText(formatter, item->font, text, renderer->buffer, 0x100, 0, 0);
    int var14 = item->font;
    window->unknown_b4_ = var14;
    window->unknown_b6_ = var14 + 1;
    if (item->flags & 0x10) {
        int var15 = item->font;
        if (var15 == 12) {
            window->unknown_b4_ = var15;
            window->unknown_b6_ = 20;
        }
    }
    int offset = 0;
    if (item->alignment) offset = Font_GetTextWidth(renderer->buffer, 0);
    func_0204f41c(window, (short)(item->x + item->xOffset - offset), item->y,
        renderer->buffer, item->font, color, &item->width, &item->height, 0);
}
#endif
