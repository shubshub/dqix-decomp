#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"

struct Struct_ov005_02153954 {
    char unknown_0_[0xdf8];
    Struct_0201099c_3 unknown_df8_;
    char unknown_e00_[LOW_REGION(0xf80, 0xf84) - 0xdf8 - sizeof(Struct_0201099c_3)];
    short unknown_f84_;
    short unknown_f86_;
    short unknown_f88_;
    short unknown_f8a_;
    char unknown_f8c_[LOW_REGION(0x3d33 - 0xf88, 0x3dbb - 0xf8c)];
    signed char unknown_3dbb_;
    char unknown_3dbc_[LOW_REGION(0x3d54, 0x3ddc) - LOW_REGION(0x3d34, 0x3dbc)];
    unsigned char unknown_3ddc_;
    unsigned char unknown_3ddd_;
    signed char unknown_3dde_;
    unsigned char unknown_3ddf_;
};

void AppendFrameTag02041c08(char* text, int a, int b, int c, int d, int e);
void AppendCursorTag_02041ea4(char* text, int a);
const char* KeyTable_Get(Container020e0310* texts, int id);
extern "C" int func_020420e8(const char* text, int large);
void AppendNameTag_02041b70(char* text, int item, const char* itemText);
void AppendString02042058(char* text, const char* append);

// USA: func_ov005_02159a30
extern "C" ARM void func_ov005_02159a30(Struct_ov005_02153954* arg0, char* arg1, int arg2) {
    if (arg1 == NULL)
        return;
    int var0 = arg0->unknown_3dde_;
    if (arg2)
        func_02041c08(arg1, var0, 8, 5, 5, 5);
    func_02041ea4(arg1, var0);
    int var1 = 4;
    int var2 = 0;
    if (arg0->unknown_3dbb_ >= 0 && arg0->unknown_3dbb_ < 8) {
        var1--;
        var2 = 1;
    }
#if defined(jpn)
    for (int i = 0; i < count; i++) {
        if (shifted) {
            if (i == 0)
                AppendNameTag_02041b70(text, i, KeyTable_Get(&self->messages, 4));
            else
                AppendNameTag_02041b70(text, i, KeyTable_Get(&self->messages, (short)(i + 1)));
        } else {
            AppendNameTag_02041b70(text, i, KeyTable_Get(&self->messages, (short)i));
        }
        if (i != count - 1)
            AppendString02042058(text, KeyTable_Get(&self->messages, 0x64));
    }
#else
    Container020e0310* strings = &self->messages;
    const char* separator = KeyTable_Get(strings, 0x64);
    int maxWidth = 0;
    for (int i = 0; i < count; i++) {
        short key = i;
        if (shifted) {
            key++;
            if (i == 0)
                key = 4;
        }
        const char* name = KeyTable_Get(strings, key);
        int width = func_020420e8(name, 0);
        if (maxWidth < width)
            maxWidth = width;
        AppendNameTag_02041b70(text, i, name);
        if (i != count - 1)
            AppendString02042058(text, separator);
    }
    int var11 = ((var6 + 0x1b) & ~7) >> 3;
    var11 += var11 & 1;
    arg0->unknown_f84_ = var11;
    arg0->unknown_f86_ = 7;
    arg0->unknown_f88_ = (0x20 - var11) >> 1;
    arg0->unknown_f8a_ = 9;
#endif
}
