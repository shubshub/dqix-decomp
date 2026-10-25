#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct Struct_02072a68_2;

struct Struct_ov012_021894b4
{
    unsigned int unknown_0_0_ : 12;
    unsigned int unknown_1_4_ : 4;
    unsigned int unknown_2_0_ : 5;
    unsigned int unknown_2_5_ : 4;
    unsigned int unknown_3_1_ : 1;
    unsigned int unknown_3_2_ : 1;
    unsigned int unknown_3_3_ : 1;
    unsigned int unknown_3_4_ : 1;
    unsigned int unknown_3_5_ : 1;
    unsigned int unknown_3_6_ : 1;
    unsigned int unknown_3_7_ : 1;
    unsigned int unknown_4_0_ : 9;
    int unknown_5_1_ : 10;
    int unknown_6_3_ : 11;
    int unknown_7_6_ : 1;
    unsigned int unknown_7_7_ : 1;
    char unknown_8_[0x74];
};

struct Struct_01ff8b48_12
{
    char unknown_0_[0x569c];
    Struct_ov012_021894b4 unknown_569c_;
};

struct Struct_ov012_021894b4_2
{
    char unknown_0_[0x133c];
    char unknown_133c_[0x1370 - 0x133c];
    unsigned char unknown_1370_;
    unsigned char unknown_1371_;
    char unknown_1372_[0x1378 - 0x1372];
    const char* unknown_1378_;
    char unknown_137c_[0x13d0 - 0x137c];
    char* unknown_13d0_;
    unsigned int unknown_13d4_;
    char unknown_13d8_[0x1400 - 0x13d8];
    char unknown_1400_[0x40];
    char unknown_1440_[0x40];
};

void Text_AppendFrameTag(char* text, int a, int b, int c, int d, int e);
void Text_AppendCursorTag(char* text, int a);
const char* FindEntryByKey_02072a68(TableA68* texts, int id);
extern "C" int Font_GetTextWidth(const char* text, int large);
void AppendXTag_02041a28(char* text, int x);
void AppendFormatted02041fac(char* text, int line, int a);
void AppendHeightTag_02041b00(char* text, int a);
void Text_AppendNTag(char* text, int item, const char* itemText);
void Text_Append(char* text, const char* append);
void AppendWidthHeightTag_02041b34(char* text, int a, int b);
void AppendLineXTag02041cf4(char* text, int a, int b, int c, int d);
void AppendLineYTag02041d48(char* text, int a, int b, int c, int d);
void* MessageSystem_GetInstance();
extern "C" void __clear(void* buffer, unsigned long size);
void AppendXYTag_02041a90(char* text, int x, int y);
int STD_GetStringLength(const char* text);
void CopyTextAndUppercaseIfFlagged0206819c(const char* text, char* output, int a);
void Text_AppendPaletteTag(char* text, int color);

extern "C" const short data_ov012_0218af92[];
extern "C" const char data_ov012_0218b305[];

static inline Struct_ov012_021894b4* inline_ov012_021894b4(GameState* arg0)
{
    return &((Struct_01ff8b48_12*)arg0)->unknown_569c_;
}

// USA: func_ov012_021894b4
extern "C" ARM void func_ov012_021894b4(Struct_ov012_021894b4_2* arg0, char* arg1, int arg2)
{
    if (arg1 == 0)
        return;

    int selection = self->selection_;
    if (hidden)
        Text_AppendFrameTag(text, selection, 8, 5, 5, 5);
    Text_AppendCursorTag(text, selection);
    const char* title = FindEntryByKey_02072a68((TableA68*)self->strings_, 1);
    AppendXTag_02041a28(text, (0xe0 - Font_GetTextWidth(title, 0)) >> 1);
    AppendFormatted02041fac(text, (int)title, 0x10);
    AppendHeightTag_02041b00(text, 3);
    Text_AppendNTag(text, 0, FindEntryByKey_02072a68((TableA68*)self->strings_, 2));
    int item;
    const short* texts = data_ov012_0218af92;
    for (item = 1;; item++, texts++)
    {
        short var4 = *var3;
        if (var4 < 0)
            break;
        Text_Append(text, self->unk_1378);
        if (item == 5)
            AppendWidthHeightTag_02041b34(text, 3, 3);
        Text_AppendNTag(text, item, FindEntryByKey_02072a68((TableA68*)self->strings_, id));
    }
    func_02041cf4(arg1, 0x7fff, 2, 0xdd, 0x66);
    func_02041d48(arg1, 0x7fff, 0x58, 0x10, 0x66);

    GameState* gameState = GameState::GetInstance();
    Profile021894b4* profile = GetProfile021894b4(gameState);
    MessageSystem_GetInstance();
    char unused[0x20];
    __clear(unused, sizeof(unused));
    AppendXYTag_02041a90(text, ((0x88 - Font_GetTextWidth(self->titleText_, 0)) >> 1) + 0x58, 0x16);
    Text_Append(text, self->titleText_);

    char var8[0x100];
    __clear(var8, sizeof(var8));
    const char* var9 = func_02072a68((Struct_02072a68_2*)arg0->unknown_133c_, (short)(inline_ov012_021894b4(var5)->unknown_1_4_ + 0x13));
    int var10;
    if (inline_ov012_021894b4(var5)->unknown_3_7_)
    {
        sprintf(birthday, data_ov012_0218b305, profile->day_, month, GetProfile021894b4(gameState)->year_);
        width = Font_GetTextWidth(birthday, 0);
    }
    else
    {
        const char* hiddenBirthday = FindEntryByKey_02072a68((TableA68*)self->strings_, 0x78);
        int length = STD_GetStringLength(hiddenBirthday);
        char shown[0x40];
        __clear(shown, sizeof(shown));
        memcpy(shown, hiddenBirthday + 8, length - 0x11);
        width = Font_GetTextWidth(shown, 0);
        sprintf(birthday, hiddenBirthday);
    }
    AppendXYTag_02041a90(text, ((0x88 - width) >> 1) + 0x58, 0x26);
    Text_Append(text, birthday);

    char accolade[0x80];
    __clear(accolade, sizeof(accolade));
    CopyTextAndUppercaseIfFlagged0206819c(self->accoladeText_, accolade, 0);
    AppendXYTag_02041a90(text, ((0x88 - Font_GetTextWidth(accolade, 0)) >> 1) + 0x58, 0x36);
    Text_Append(text, accolade);

    short design = 0x6d;
    unsigned int chosen = profile->designChosen_;
    if (chosen)
        design = profile->unk_0_21 + 30000;
    const char* designText = FindEntryByKey_02072a68((TableA68*)self->strings_, design);
    AppendXYTag_02041a90(text, ((0x88 - Font_GetTextWidth(designText, 0)) >> 1) + 0x58, 0x46);
    Text_Append(text, designText);

    char* var18 = (char*)var6->unknown_8_;
    int var19 = 0;
    if (arg0->unknown_1371_ == 14 && arg0->unknown_1370_ >= 1 && arg0->unknown_1370_ <= 4)
        var18 = arg0->unknown_13d0_;
    const char* var20;
    if (*var18 == 0)
    {
        var20 = func_02072a68((Struct_02072a68_2*)arg0->unknown_133c_, 0x12);
        var19 = 1;
    }
    else
    {
        var20 = func_02072a68((Struct_02072a68_2*)arg0->unknown_133c_, 0x13);
    }
    AppendXYTag_02041a90(text, ((0x88 - Font_GetTextWidth(messageText, 0)) >> 1) + 0x58, 0x56);
    if (empty)
        Text_AppendPaletteTag(text, 3);
    Text_Append(text, messageText);
}
