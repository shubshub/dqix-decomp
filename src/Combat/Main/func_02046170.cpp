#include <globaldefs.h>
#include "Resource/MessageGlyphSlot.h"

extern "C" bool func_02044494(void* obj, void* src);
extern "C" int Font_GetKerning(int a, int b, int fontIndex);

extern int data_020e7a94[];

struct Struct_02046170 {
    char pad0[0x9b8];
    Struct_0204166c glyphs[0x80];
};

#if defined(jpn)
enum Enum_02046f80 { Enum_02046f80_65281 = 0xff01 };

enum Enum_02046f80_B {
    Enum_02046f80_B_33 = 0x21, Enum_02046f80_B_34, Enum_02046f80_B_35, Enum_02046f80_B_36, Enum_02046f80_B_37, Enum_02046f80_B_38
};
// USA: func_02046170
extern "C" ARM int func_02046f80(void* obj, int arg1, unsigned short* commands, int arg3) {
    if (commands == 0) return 0;
    if (arg3 < 0) return 0;
    int advance;
    switch (arg1) {
    case 10: advance = 10; break;
    case 12: advance = 12; break;
    default: return 0;
    }
    Enum_02046f80 end = Enum_02046f80_65281;
    int currentExtent = 0;
    int var3 = 0;
    for (int i = 0; i < arg3; i++) {
        unsigned short command = commands[i];
        if (command == end) break;
        if (command == end + 0x17 || command == end + 9 || command == end + 0x1b ||
            command == end + 0x1e || command == end + 0x1f || command == end + 0x20 ||
            command == end + 3 || command == end + 4 || command == end + 5 || command == end + 6) {
        } else if (command == end + 0x1a) {
            currentExtent += advance >> 1;
        } else if (command == end + Enum_02046f80_B_33) {
            ++i;
            if (var3 < commands[i]) var3 = commands[i];

            int previous = currentExtent;
            currentExtent = var3;
            var3 = previous;
        } else if (command == end + Enum_02046f80_B_34) {
            ++i;
        } else if (command == end + Enum_02046f80_B_35) {
            unsigned short value = commands[i + 1];
            i += 2;
            if (var3 < value) var3 = value;
            int previous = currentExtent;
            currentExtent = var3;
            var3 = previous;
        } else if (command == end + Enum_02046f80_B_36) {
            unsigned short value = commands[i + 1];

            i += 2;
            currentExtent += value;
        } else if (command == end + Enum_02046f80_B_37) {
            ++i;
        } else if (command == end + Enum_02046f80_B_38) {
            unsigned short value = commands[i + 1];
            i += 2;
            currentExtent += value;
        } else {
            currentExtent += advance;
        }
    }
    if (currentExtent < var3) currentExtent = var3;
    return currentExtent;
}
#else
// USA: func_02046170
extern "C" ARM int func_02046170(struct Struct_02046170* window, unsigned short* commands, int arg2,
                                 int fontIndex) {
    if (commands == 0) return 0;
    if (arg2 < 0) return 0;

    int var0 = data_020e7a94[fontIndex] & 0xff;
    int currentExtent = 0;
    int var2 = 0;
    int previousCharacter = 0xff;

    for (int i = 0; i < arg2; i++) {
        unsigned short command = commands[i];
        if (command == 0xff01) break;
        if (command == 0xff18) {
            if (var2 < currentExtent) var2 = currentExtent;
            currentExtent = 0;
            previousCharacter = 0xff;
        } else if (command == 0xff19) {
            previousCharacter = 0xff;
            currentExtent += var0 + 1;
        } else if (func_02044494(window, &command)) {
            previousCharacter = 0xff;
        } else {
            Struct_0204166c* slot = &window->glyphs[command];
            int characterIndex = slot->characterIndex;
            currentExtent += Font_GetKerning(previousCharacter, characterIndex, fontIndex);
            previousCharacter = characterIndex;
            int glyphWidth = var0;
            if (slot->character != 0) glyphWidth = slot->character->width_;
            currentExtent += glyphWidth + 1;
        }
    }

    if (currentExtent < var2) currentExtent = var2;
    return currentExtent;
}
#endif
