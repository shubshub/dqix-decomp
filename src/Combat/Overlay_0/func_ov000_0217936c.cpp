#include <globaldefs.h>

struct Struct_0205c508;
struct Container020e0310;

struct Struct_ov000_0217936c_2 {
    char pad0[0x1e];
    short cursor;
};

struct Struct_ov000_0217936c {
    char pad0[0xb8];
    char texts[0x1dc - 0xb8];
    char scroll[4];
};

extern "C" void func_0205c508(struct Struct_0205c508* s, int* out1, int* out2);
extern "C" int func_ov000_0217542c(void* obj);
extern "C" int Text_AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5);
extern "C" int Text_AppendCursorTag(char* dst, int cursor);
extern "C" int* func_ov000_0217199c(void* obj, int index);
extern "C" int func_ov000_0217c4e8(void* obj, int index);
extern "C" int Text_AppendPaletteTag(char* dst, int palette);
extern "C" void __clear(void* buf, int size);
extern "C" void func_020e4864(int id, char* dst, int a, int b, int c, int d);
extern "C" void func_0206819c(const char* src, char* dst, int flag);
extern "C" int Text_AppendNTag(char* dst, int n, const char* name);
extern "C" int KeyTable_Get(struct Container020e0310* c, int key);
extern "C" int Text_Append(char* dst, const char* src);

// USA: func_ov000_0217936c
extern "C" ARM void func_ov000_0217936c(struct Struct_ov000_0217936c* window, struct Struct_ov000_0217936c_2* menu, char* dst) {
#if !defined(jpn)
    char name[0x80];
    char upper[0x80];
#endif
    int first;
    int last;
    if (menu == NULL || dst == NULL) {
        return;
    }
    func_0205c508((struct Struct_0205c508*)window->scroll, &first, &last);
    short top = first;
    short end = last;
    short cursor = menu->cursor;
    if (func_ov000_0217542c(window)) {
        Text_AppendFrameTag(dst, cursor - top, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursor - top);
    for (short i = top; i < end; i++) {
        int* entry = func_ov000_0217199c(menu, i);
        if (entry == NULL) {
            continue;
        }
#if defined(jpn)
        if (func_ov000_0217c4e8(menu, i)) {
            Text_AppendPaletteTag(dst, 0xf);
        } else {
            Text_AppendPaletteTag(dst, 3);
        }
        Text_AppendNTag(dst, i - top, (const char*)*entry);
#else
        int palette = 3;
        if (func_ov000_0217c4e8(menu, i)) {
            palette = 0xf;
        }
        Text_AppendPaletteTag(dst, palette);
        __clear(name, sizeof(name));
        __clear(upper, sizeof(upper));
        func_020e4864(*entry, name, 1, 0, 0, 0);
        func_0206819c(name, upper, 0);
        Text_AppendNTag(dst, i - top, name);
#endif
        if (i != end - 1) {
            Text_Append(dst, (const char*)KeyTable_Get((struct Container020e0310*)window->texts, 0));
        }
    }
}
