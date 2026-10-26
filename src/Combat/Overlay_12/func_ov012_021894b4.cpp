#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct TableA68;

struct Struct_ov012_021894b4
{
    unsigned int unknown_0_0_ : 12;
    unsigned int unknown_1_4_ : 4;
    unsigned int unknown_2_0_ : 5;
    unsigned int unknown_2_5_ : 4;
    unsigned int female_ : 1;
    unsigned int unknown_3_2_ : 1;
    unsigned int unknown_3_3_ : 1;
    unsigned int unknown_3_4_ : 1;
    unsigned int unknown_3_5_ : 1;
    unsigned int unknown_3_6_ : 1;
    unsigned int unknown_3_7_ : 1;
    unsigned int unknown_4_0_ : 9;
    int unknown_5_1_ : 10;
    int accolade_ : 11;
    int unknown_7_6_ : 1;
    unsigned int unknown_7_7_ : 1;
    char unk_8[0x74];
};

struct Struct_01ff8b48_12
{
    char unk_0[0x569c];
    Struct_ov012_021894b4 unknown_569c_;
};

struct Struct_ov012_021894b4_2
{
    char unk_0[0x133c];
    char strings_[0x1370 - 0x133c];
    unsigned char step_;
    unsigned char state_;
    char unknown_1372_[0x1378 - 0x1372];
    const char* unk_1378;
    char unknown_137c_[0x13d0 - 0x137c];
    char* message_;
    unsigned int selection_;
    char unknown_13d8_[0x1400 - 0x13d8];
    char unknown_1400_[0x40];
    char titleText_[0x40];
};

extern "C" void Text_AppendFrameTag(char* text, int a, int b, int c, int d, int e);
extern "C" void Text_AppendCursorTag(char* text, int a);
extern "C" const char* func_02072a68(TableA68* texts, int id);
extern "C" int Font_GetTextWidth(const char* text, int large);
extern "C" void func_02041a28(char* text, int x);
extern "C" void func_02041fac(char* text, int line, int a);
extern "C" void func_02041b00(char* text, int a);
extern "C" void Text_AppendNTag(char* text, int item, const char* itemText);
extern "C" void Text_Append(char* text, const char* append);
extern "C" void func_02041b34(char* text, int a, int b);
extern "C" void func_02041cf4(char* text, int a, int b, int c, int d);
extern "C" void func_02041d48(char* text, int a, int b, int c, int d);
extern "C" void* MessageSystem_GetInstance();
extern "C" void __clear(void* buffer, unsigned long size);
extern "C" void func_02041a90(char* text, int x, int y);
extern "C" int STD_GetStringLength(const char* text);
extern "C" void func_0206819c(const char* text, char* output, int a);
extern "C" void Text_AppendPaletteTag(char* text, int color);

extern "C" const short data_ov012_0218af92[];
extern "C" const char data_ov012_0218b305[];

static inline Struct_ov012_021894b4* inline_ov012_021894b4(GameState* gameState)
{
    return &((Struct_01ff8b48_12*)gameState)->unknown_569c_;
}

// USA: func_ov012_021894b4
extern "C" ARM void func_ov012_021894b4(Struct_ov012_021894b4_2* self, char* text, int hidden)
{
    if (text == 0)
        return;

    int selection = self->selection_;
    if (hidden)
        Text_AppendFrameTag(text, selection, 8, 5, 5, 5);
    Text_AppendCursorTag(text, selection);
    const char* title = func_02072a68((TableA68*)self->strings_, 1);
    func_02041a28(text, (0xe0 - Font_GetTextWidth(title, 0)) >> 1);
    func_02041fac(text, (int)title, 0x10);
    func_02041b00(text, 3);
    Text_AppendNTag(text, 0, func_02072a68((TableA68*)self->strings_, 2));
    int item;
    const short* texts = data_ov012_0218af92;
    for (item = 1;; item++, texts++)
    {
        short id = *texts;
        if (id < 0)
            break;
        Text_Append(text, self->unk_1378);
        if (item == 5)
            func_02041b34(text, 3, 3);
        Text_AppendNTag(text, item, func_02072a68((TableA68*)self->strings_, id));
    }
    func_02041cf4(text, 0x7fff, 2, 0xdd, 0x66);
    func_02041d48(text, 0x7fff, 0x58, 0x10, 0x66);

    GameState* gameState = GameState::GetInstance();
    Struct_ov012_021894b4* profile = inline_ov012_021894b4(gameState);
    MessageSystem_GetInstance();
    char unused[0x20];
    __clear(unused, sizeof(unused));
    func_02041a90(text, ((0x88 - Font_GetTextWidth(self->titleText_, 0)) >> 1) + 0x58, 0x16);
    Text_Append(text, self->titleText_);

    char birthday[0x100];
    __clear(birthday, sizeof(birthday));
    const char* month = func_02072a68((TableA68*)self->strings_, (short)(inline_ov012_021894b4(gameState)->unknown_1_4_ + 0x13));
    int width;
    if (inline_ov012_021894b4(gameState)->unknown_3_7_)
    {
        sprintf(birthday, data_ov012_0218b305, profile->unknown_2_0_, month, inline_ov012_021894b4(gameState)->unknown_0_0_);
        width = Font_GetTextWidth(birthday, 0);
    }
    else
    {
        const char* hiddenBirthday = func_02072a68((TableA68*)self->strings_, 0x78);
        int length = STD_GetStringLength(hiddenBirthday);
        char shown[0x40];
        __clear(shown, sizeof(shown));
        memcpy(shown, hiddenBirthday + 8, length - 0x11);
        width = Font_GetTextWidth(shown, 0);
        sprintf(birthday, hiddenBirthday);
    }
    func_02041a90(text, ((0x88 - width) >> 1) + 0x58, 0x26);
    Text_Append(text, birthday);

    char accolade[0x80];
    __clear(accolade, sizeof(accolade));
    func_0206819c(self->unknown_1400_, accolade, 0);
    func_02041a90(text, ((0x88 - Font_GetTextWidth(accolade, 0)) >> 1) + 0x58, 0x36);
    Text_Append(text, accolade);

    short var15 = 0x6d;
    unsigned int var16 = profile->unknown_3_3_;
    if (var16)
        var15 = profile->unknown_2_5_ + 30000;
    const char* designText = func_02072a68((TableA68*)self->strings_, var15);
    func_02041a90(text, ((0x88 - Font_GetTextWidth(designText, 0)) >> 1) + 0x58, 0x46);
    Text_Append(text, designText);

    char* message = (char*)profile->unk_8;
    int empty = 0;
    if (self->state_ == 14 && self->step_ >= 1 && self->step_ <= 4)
        message = self->message_;
    const char* messageText;
    if (*message == 0)
    {
        messageText = func_02072a68((TableA68*)self->strings_, 0x12);
        empty = 1;
    }
    else
    {
        messageText = func_02072a68((TableA68*)self->strings_, 0x13);
    }
    func_02041a90(text, ((0x88 - Font_GetTextWidth(messageText, 0)) >> 1) + 0x58, 0x56);
    if (empty)
        Text_AppendPaletteTag(text, 3);
    Text_Append(text, messageText);
}
