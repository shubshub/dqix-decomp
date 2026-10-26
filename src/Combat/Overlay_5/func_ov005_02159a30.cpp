#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"

struct EquipmentMenu {
    char unk_0[0xdf8];
    Container020e0310 messages;
    char unknown_e00_[LOW_REGION(0xf80, 0xf84) - 0xdf8 - sizeof(Container020e0310)];
    short unknown_f84_;
    short unknown_f86_;
    short unknown_f88_;
    short unknown_f8a_;
    char unknown_f8c_[LOW_REGION(0x3d33 - 0xf88, 0x3dbb - 0xf8c)];
    signed char slot_;
    char unknown_3dbc_[LOW_REGION(0x3d54, 0x3ddc) - LOW_REGION(0x3d34, 0x3dbc)];
    unsigned char unknown_3ddc_;
    unsigned char menuResult_;
    signed char menuChoice_;
    unsigned char unknown_3ddf_;
};

extern "C" void Text_AppendFrameTag(char* text, int a, int b, int c, int d, int e);
extern "C" void Text_AppendCursorTag(char* text, int a);
extern "C" const char* KeyTable_Get(Container020e0310* texts, int id);
extern "C" int Font_GetTextWidth(const char* text, int large);
extern "C" void Text_AppendNTag(char* text, int item, const char* itemText);
extern "C" void Text_Append(char* text, const char* append);

// USA: func_ov005_02159a30
extern "C" ARM void func_ov005_02159a30(EquipmentMenu* self, char* text, int arg2) {
    if (text == NULL)
        return;
    int choice = self->menuChoice_;
    if (arg2)
        Text_AppendFrameTag(text, choice, 8, 5, 5, 5);
    Text_AppendCursorTag(text, choice);
    int count = 4;
    int var2 = 0;
    if (self->slot_ >= 0 && self->slot_ < 8) {
        count--;
        var2 = 1;
    }
#if defined(jpn)
    for (int i = 0; i < count; i++) {
        if (var2) {
            if (i == 0)
                Text_AppendNTag(text, i, KeyTable_Get(&self->messages, 4));
            else
                Text_AppendNTag(text, i, KeyTable_Get(&self->messages, (short)(i + 1)));
        } else {
            Text_AppendNTag(text, i, KeyTable_Get(&self->messages, (short)i));
        }
        if (i != count - 1)
            Text_Append(text, KeyTable_Get(&self->messages, 0x64));
    }
#else
    Container020e0310* strings = &self->messages;
    const char* separator = KeyTable_Get(strings, 0x64);
    int var6 = 0;
    for (int i = 0; i < count; i++) {
        short key = i;
        if (var2) {
            key++;
            if (i == 0)
                key = 4;
        }
        const char* name = KeyTable_Get(strings, key);
        int width = Font_GetTextWidth(name, 0);
        if (var6 < width)
            var6 = width;
        Text_AppendNTag(text, i, name);
        if (i != count - 1)
            Text_Append(text, separator);
    }
    int tiles = ((var6 + 0x1b) & ~7) >> 3;
    tiles += tiles & 1;
    self->unknown_f84_ = tiles;
    self->unknown_f86_ = 7;
    self->unknown_f88_ = (0x20 - tiles) >> 1;
    self->unknown_f8a_ = 9;
#endif
}
