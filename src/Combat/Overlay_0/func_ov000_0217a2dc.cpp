#include <globaldefs.h>
#include "Resource/ActionDataTables.h"

struct Container020e0310;

extern "C" int KeyTable_Get(struct Container020e0310* c, int key);
extern "C" int Text_Append(char* dst, const char* src);
extern "C" int func_ov000_0217542c(void* obj);
extern "C" int Text_AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5);

extern "C" int Text_AppendPaletteTag(char* dst, int palette);
extern "C" const char** func_02079e2c(char* table, int key);
extern "C" int Text_AppendCursorTag(char* dst, int cursor);
extern "C" int Text_AppendNTag(char* dst, int n, const char* name);
extern "C" int Font_GetTextWidth(const char* text, int large);
extern "C" int func_02041a90(char* dst, int x, int y);
extern "C" int func_02041cc0(char* dst, int a1);
#if defined(jpn)
extern "C" void* MessageSystem_GetInstance();
extern "C" void func_02046380(void*);
extern "C" void MessageSystem_SetStringArgument(void*, int, const char*);
extern "C" void __clear(void*, int);
extern "C" void func_02041f50(const char*, char*);
extern char data_ov000_021851af[];
#endif

struct Struct_ov000_0217a2dc {
    char pad0[0x10];
    unsigned short itemIds[5];
    signed char itemCount;
#if defined(jpn)
    char unknown_1b_[0x1fa5 - 0x1b];
#else
    char unknown1_1b_[0x1d6d - 0x1b];
#endif
    signed char cursor;
    char unknown_1d6e_[0x1d81 - 0x1d6e];
    unsigned char unknown_1d81_;
};

// USA: func_ov000_0217a2dc
extern "C" ARM void func_ov000_0217a2dc(struct Struct_ov000_0217a2dc* menu, int unused, char* dst) {
    struct Container020e0310* strings = (struct Container020e0310*)((char*)menu + 0xb8);
    const char* emptyName = (const char*)KeyTable_Get(strings, 0x1f);
    const char* separator = (const char*)KeyTable_Get(strings, 0);
    signed char cursor = menu->cursor;
    Text_Append(dst, separator);

    if (menu->unknown_1d81_) {
        if (func_ov000_0217542c(menu)) {
            Text_AppendFrameTag(dst, cursor, 8, 5, 5, 5);
        }
        ActionDataTables* table = func_020797dc();
        if (table == NULL) {
            return;
        }
        for (int i = 0; i < menu->itemCount; i++) {
#if defined(jpn)
            if (i == cursor) {
                Text_AppendPaletteTag(dst, 5);
            } else {
                Text_AppendPaletteTag(dst, 3);
            }
#else
            int palette = 3;
            if (i == cursor) {
                palette = 5;
            }
            Text_AppendPaletteTag(dst, palette);
#endif
            if (menu->itemIds[i] == 0) {
                Text_Append(dst, emptyName);
            } else {
                const char** entry = func_02079e2c((char*)table, (short)menu->itemIds[i]);
                if (entry == NULL) {
                    continue;
                }
#if defined(jpn)
                char name[0x40];
                __clear(name, sizeof(name));
                func_02041f50(*entry, name);
                Text_Append(dst, name);
#else
                Text_Append(dst, *entry);
#endif
            }
            if (i == menu->itemCount - 1) {
                continue;
            }
            Text_Append(dst, separator);
        }
    } else {
        if (func_ov000_0217542c(menu)) {
            Text_AppendFrameTag(dst, cursor, 8, 5, 5, 5);
        }
        Text_AppendCursorTag(dst, cursor);
        ActionDataTables* table = func_020797dc();
        if (table == NULL) {
            return;
        }
        for (int i = 0; i < menu->itemCount; i++) {
            if (menu->itemIds[i] == 0) {
                Text_AppendNTag(dst, i, emptyName);
            } else {
                const char** entry = func_02079e2c((char*)table, (short)menu->itemIds[i]);
                if (entry == NULL) {
                    continue;
                }
#if defined(jpn)
                char name[0x40];
                __clear(name, sizeof(name));
                func_02041f50(*entry, name);
                Text_AppendNTag(dst, i, name);
#else
                Text_AppendNTag(dst, i, *entry);
#endif
            }
            if (i == menu->itemCount - 1) {
                continue;
            }
            Text_Append(dst, separator);
        }
    }

    Text_AppendPaletteTag(dst, 0xf);
#if defined(jpn)
    void* formatter = MessageSystem_GetInstance();
    func_02046380(formatter);
    MessageSystem_SetStringArgument(formatter, 0,
        (const char*)KeyTable_Get(strings, 0x21));
    Text_Append(dst, data_ov000_021851af);
#else
    const char* title = (const char*)KeyTable_Get(strings, 0x21);
    func_02041a90(dst, (0xb0 - Font_GetTextWidth(title, 0)) >> 1, 5);
    Text_Append(dst, title);
    func_02041cc0(dst, 0x11);
#endif
}
