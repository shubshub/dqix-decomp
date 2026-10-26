#include <globaldefs.h>
#include <std_library_functions.h>

struct Struct_0206b37c {
    char unknown_0_[0x19dc];
    unsigned char unknown_19dc_;
};

struct Struct_0204254c {
    int unknown_0_;
    signed char unknown_4_;
    signed char unknown_5_0_ : 6;
    signed char unknown_5_6_ : 2;
    char unknown_6_[2];
};

int Font_GetFallbackWidth(int);
bool IsHighByteFF02044494(void*, void*);
int Dispatch02044420(void*, void*);
int Font_GetKerning(int, int, int);
Entry0204254c* Font_FindCharacter(int, int);
int Font_FindCharacterIndex(int, int);
int IsHalfwordInRange02067ad8(int, void*);

// USA: func_0206b37c
extern "C" ARM int func_0206b37c(TextContext* context, char* text) {
    if (!text) return 0;
    unsigned char defaultWidth = Font_GetFallbackWidth(context->fontTable);
    int current = 0xff;
    unsigned char previous = current;
    int payloadWords;
    int step;
    int width = 0;
    unsigned short command;
    short argument;
    while (!IsHalfwordInRange02067ad8((int)context, text)) {
        memcpy(&command, text, 2);
        if (IsHighByteFF02044494(context, &command)) {
            payloadWords = Dispatch02044420(context, &command);
            switch (command) {
            case 0xff19:
                previous = 0xff;
                width += Font_GetKerning(previous, current, context->fontTable);
                break;
            case 0xff20:
                var2 = 0xff;
                memcpy(&var7, arg1 + 2, 2);
                if (var5 < var7) var5 = var7;
                break;
            case 0xff23:
                var2 = 0xff;
                memcpy(&var7, arg1 + 2, 2);
                var5 += var7;
                break;
            }
            arg1 = arg1 + 2 + var3 * 2;
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
            var5 += var8 + 1;
            arg1 += var4;
        }
    }
    return var5;
}
