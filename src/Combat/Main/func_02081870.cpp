#include <globaldefs.h>
#include <std_library_functions.h>

#if defined(jpn)
#define func_0204f41c func_02050678
#endif

struct Struct_02072a68_2;
struct Struct_02046574_2;
struct Struct_02081870 {
    Struct_02072a68_2* unknown_0_;
    char unknown_4_[0x14];
    char* unknown_18_;
};
struct Struct_02081870_2 {
    char unknown_0_[0xa8];
    short unknown_a8_;
    char unknown_aa_[0xa];
    short unknown_b4_;
    short unknown_b6_;
};
struct Struct_02081870_3 {
    char* unknown_0_;
    short unknown_4_;
    short unknown_6_;
    short unknown_8_;
    short unknown_a_;
    short unknown_c_;
    short unknown_e_;
    short unknown_10_;
    unsigned char unknown_12_;
    unsigned char unknown_13_0_ : 4;
    unsigned char unknown_13_4_ : 4;
    unsigned char unknown_14_0_ : 2;
    unsigned char unknown_14_2_ : 6;
    char unknown_15_[0x13];
    short unknown_28_;
    unsigned char unknown_2a_;
};
int IsValueEqual12_02042190(int);
void* FindEntryByKey_02072a68(TableA68*, int);
extern "C" int Font_GetTextWidth(char*, int);
int MessageSystem_GetInstance();
extern "C" void func_02046380(Obj02046574*);
void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
#if defined(jpn)
int STD_GetStringLength(const char*);
extern "C" void func_020474a8(Obj02046574*, int, void*, char*);
extern "C" void func_0204f41c(TextWindow*, short, int, char*, int, int, short*, short*);
#else
extern "C" void MessageSystem_FormatText(Obj02046574*, int, void*, char*, int, int, int);
extern "C" void func_0204f41c(TextWindow*, short, int, char*, int, int, short*, short*, int);
#endif

// USA: func_02081870
#if defined(jpn)
extern "C" ARM void func_02081870(TextRenderer* renderer, TextWindow* window, TextItem* item) {
    int color = item->color;
    if (item->flags & 4) color = 5;
    if (item->flags & 8) {
        char* text = (char*)FindEntryByKey_02072a68(renderer->strings, item->stringId);
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
    void* text = FindEntryByKey_02072a68(renderer->strings, item->stringId);
    func_020474a8(formatter, item->font, text, renderer->buffer);
    int firstFont = item->font;
    window->firstFont = firstFont;
    window->lastFont = firstFont + 1;
    if (item->flags & 0x10) {
        int selectedFont = item->font;
        if (selectedFont == 12) {
            window->firstFont = selectedFont;
            window->lastFont = 20;
        }
    }
    func_0204f41c(arg1, (short)(arg2->unknown_6_ + arg2->unknown_28_), arg2->unknown_8_,
        arg0->unknown_18_, arg2->unknown_13_0_, var0, &arg2->unknown_a_, &arg2->unknown_c_);
}
#else
extern "C" ARM void func_02081870(TextRenderer* renderer, TextWindow* window, TextItem* item) {
    int color = item->color;
    if (item->flags & 4) color = 5;
    int font = IsValueEqual12_02042190(item->font);
    if (item->flags & 8) {
        char* text = (char*)FindEntryByKey_02072a68(renderer->strings, item->stringId);
        if (text) {
            short width = window->width * 8;
            item->x = (short)(width - Font_GetTextWidth(text, font)) >> 1;
        }
    }
    Obj02046574* formatter = (Obj02046574*)MessageSystem_GetInstance();
    memset(renderer->buffer, 0, 0x960);
    func_02046380(formatter);
    MessageSystem_SetStringArgument(formatter, item->nameIndex, item->name);
    void* text = FindEntryByKey_02072a68(renderer->strings, item->stringId);
    MessageSystem_FormatText(formatter, item->font, text, renderer->buffer, 0x100, 0, 0);
    int firstFont = item->font;
    window->firstFont = firstFont;
    window->lastFont = firstFont + 1;
    if (item->flags & 0x10) {
        int selectedFont = item->font;
        if (selectedFont == 12) {
            window->firstFont = selectedFont;
            window->lastFont = 20;
        }
    }
    int offset = 0;
    if (item->alignment) offset = Font_GetTextWidth(renderer->buffer, 0);
    func_0204f41c(window, (short)(item->x + item->xOffset - offset), item->y,
        renderer->buffer, item->font, color, &item->width, &item->height, 0);
}
#endif
