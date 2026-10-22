#include <globaldefs.h>
#include "Resource/Keyboard.h"

struct KeyboardKey {
    char pad0[4];
    int text;
    int shiftedText;
    char padC[3];
    unsigned char disabled;
};

struct Struct_0204254c {
    char unknown_0_[4];
    signed char unknown_4_;
};

struct Keyboard {
    struct KeyboardKey* key;
    char pad4[4];
    char* text;
    int widthLimit;
    char pad10[4];
    int maxLen;
    char pad18[0x1e - 0x18];
    unsigned char page;
    unsigned char font;
    unsigned char shift;
};

extern "C" void __clear(void* buf, int size);
int FindEntryIndexByKey020424e4(int key, int tableIdx);
extern "C" int func_020426bc(void* src, void* dst, int flag);
extern "C" void func_02042764(void* src, void* dst, int flag);
extern "C" int func_020420e8(void* str, int flag);
struct Entry0204254c* Font_FindCharacter(int key, int tableIdx);

extern unsigned char data_ov003_0217f3b0[];

// Overlay 3, originally func_ov003_0215ec90 (USA/EUR 0x0215ec90; no JPN match, its keyboard differs)
extern "C" ARM int Keyboard_TypeCharacter(struct Keyboard* input) {
    unsigned char buf[0x100];
    unsigned char work[0x100];
    unsigned char* p;
    int code;
    int ch;
    struct Entry0204254c* entry;
    int width;
    int i;
    int len;
    char* text;
    int widthLimit;
    int font;
    int maxLen;
    struct KeyboardKey* key = input->key;
    if (key != 0) {
        if (key->disabled != 0) {
            return KeyboardResult_KeyDisabled;
        }

        font = input->font;
        text = input->text;
        code = key->text;
        if (data_ov003_0217f3b0[input->shift] == input->page) {
            code = key->shiftedText;
        }
        var10 = arg0->unknown_c_;
        var12 = arg0->unknown_14_;

        __clear(var0, 0x100);
        var4 = func_020424e4(var3, var11);
        var8 = func_020426bc(var9, var0, var11);
        var2 = var0;
        for (var7 = 0; var7 < var12; var7++, var2++) {
            if (var7 == var12 - 1) {
                unsigned char var14 = *var2;
                *var2 = var4;
                if (var10 != 0) {
                    __clear(var1, 0x100);
                    func_02042764(var0, var1, var11);
                    if (var10 < func_020420e8(var1, 0)) {
                        *var2 = var14;
                        break;
                    }
                }
                func_02042764(buf, text, font);
                input->shift = 0;
                return (maxLen <= len + 1) ? KeyboardResult_TypedFull : KeyboardResult_Typed;
            }
            if (*p == 0) {
                if (widthLimit != 0) {
                    width = func_020420e8(text, 0);
                    entry = Font_FindCharacter(code, 0);
                    if (entry != 0) {
                        width += entry->width + 1;
                    }
                    if (var10 < var6) {
                        break;
                    }
                }
                *p = ch;
                func_02042764(buf, text, font);
                input->shift = 0;
                return (maxLen <= len + 1) ? KeyboardResult_TypedFull : KeyboardResult_Typed;
            }
        }
    }
    return KeyboardResult_None;
}
