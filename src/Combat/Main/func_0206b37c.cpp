#include <globaldefs.h>
#include <std_library_functions.h>

struct Struct_0206b37c {
    char unknown_0_[0x19dc];
    unsigned char fontTable;
};

struct Entry0204254c {
    int key;
    signed char width;
    signed char size : 6;
    signed char flags : 2;
    char unknown_6_[2];
};

extern "C" int Font_GetFallbackWidth(int);
extern "C" bool func_02044494(void*, void*);
extern "C" int func_02044420(void*, void*);
extern "C" int Font_GetKerning(int, int, int);
extern "C" Entry0204254c* Font_FindCharacter(int, int);
extern "C" int Font_FindCharacterIndex(int, int);
extern "C" int func_02067ad8(int, void*);

// USA: func_0206b37c
extern "C" ARM int func_0206b37c(Struct_0206b37c* context, char* text) {
    if (!text) return 0;
    unsigned char defaultWidth = Font_GetFallbackWidth(context->fontTable);
    int current = 0xff;
    unsigned char previous = current;
    int var3;
    int step;
    int width = 0;
    unsigned short command;
    short argument;
    while (!func_02067ad8((int)context, text)) {
        memcpy(&command, text, 2);
        if (func_02044494(context, &command)) {
            var3 = func_02044420(context, &command);
            switch (command) {
            case 0xff19:
                previous = 0xff;
                width += Font_GetKerning(previous, current, context->fontTable);
                break;
            case 0xff20:
                previous = 0xff;
                memcpy(&argument, text + 2, 2);
                if (width < argument) width = argument;
                break;
            case 0xff23:
                previous = 0xff;
                memcpy(&argument, text + 2, 2);
                width += argument;
                break;
            }
            text = text + 2 + var3 * 2;
        } else {
            step = 1;
            int glyphWidth = defaultWidth;
            Entry0204254c* entry = Font_FindCharacter((int)text, context->fontTable);
            if (entry) {
                current = (unsigned char)Font_FindCharacterIndex((int)text, context->fontTable);
                width += Font_GetKerning(previous, current, context->fontTable);
                previous = current;
                current = 0xff;
                step = entry->size;
                glyphWidth = entry->width;
            }
            width += glyphWidth + 1;
            text += step;
        }
    }
    return width;
}
