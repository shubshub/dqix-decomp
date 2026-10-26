#include <globaldefs.h>
#include <std_library_functions.h>
#include "GameState/GameState.h"

struct MessageSystem;
struct TableA68;
struct StoreStruct;
struct SearchStruct0202c1a4;
struct Container020e0310;

struct Struct_ov023_021e868c {
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
};

struct Struct_ov023_021e868c_2 {
    char unk_0[0x3c];
    char name_[1];
};

struct Struct_ov023_021e868c_3 {
    char unk_0[0x5d8];
    char* text_;
    char unknown_5dc_[0x5f4 - 0x5dc];
    TableA68* strings_;
#if defined(jpn)
    Container020e0310* vocationStrings_;
#endif
};

struct Struct_01ff91ac_27 {
    char unk_0[0x5400];
    Struct_ov023_021e868c unknown_5400_;
};

struct Struct_01ff91ac_28 {
#if defined(jpn)
    char unk_0[0x3c];
#else
    char unk_0[0x29c];
#endif
    Struct_01ff91ac_27 unknown_29c_;
};

static inline Struct_ov023_021e868c* inline_ov003_02172e84(GameState* gameState)
{
    return &((Struct_01ff91ac_28*)gameState)->unknown_29c_.unknown_5400_;
}

extern "C" int MessageSystem_GetInstance();
extern "C" int LinkSession_IsActive(int* unknown);
extern "C" Struct_ov023_021e868c_2* func_02053c6c(unsigned char* member);
extern "C" int LinkSession_GetOwnSlot(SearchStruct0202c1a4* unknown);
extern "C" void func_02041a28(char* text, int x);
#if defined(jpn)
extern "C" int Font_GetTextWidth(char* text, int y);
#define func_02041a5c Font_GetTextWidth
#else
extern "C" int func_02041a5c(char* text, int y);
#endif
extern "C" void func_02041a90(char* text, int x, int y);
extern "C" void Text_AppendNTag(char* text, int item, const char* itemText);
#if defined(jpn)
extern "C" int func_02042638(char* text, int line, int size);
#define func_02041fac func_02042638
#else
extern "C" int func_02041fac(char* text, int line, int size);
#endif
extern "C" void Text_Append(char* text, const char* append);
extern "C" const char* func_02072a68(TableA68* texts, int id);
extern "C" void func_020465c0(StoreStruct* messages, int index, int value);
extern "C" void func_020465d8(unsigned char* messages, int index, unsigned char value);
extern "C" void func_020465f0(unsigned char* messages, int index, unsigned char digits);

extern "C" {
void* LinkSession_GetInstance();
#if defined(jpn)
void func_020474a8(MessageSystem* messages, unsigned char font, const char* format, char* output);
#else
int Font_GetTextWidth(const char* text, int large);
void MessageSystem_FormatText(MessageSystem* messages, int a, const char* format, char* output, int size, int b, int c);
#endif
}
#if defined(jpn)
extern "C" int KeyTable_Get(Container020e0310* strings, int key);
#endif

// USA: func_ov023_021e868c
// JPN: func_ov023_021e85e0
extern "C" ARM void func_ov023_021e868c(Struct_ov023_021e868c_3* self)
{
    GameState* gameState = GameState::GetInstance();
    MessageSystem* messages = (MessageSystem*)MessageSystem_GetInstance();
    void* unknown = LinkSession_GetInstance();
    Struct_ov023_021e868c_2* data = NULL;
    if (LinkSession_IsActive((int*)unknown) == 0)
    {
        void* member = func_0200ff1c(gameState, 0);
        if (member != NULL)
            data = func_02053c6c((unsigned char*)member);
    }
    else
    {
        void* member = func_0200ff1c(gameState, LinkSession_GetOwnSlot((SearchStruct0202c1a4*)unknown));
        if (member != NULL)
            data = func_02053c6c((unsigned char*)member);
    }
    if (data == NULL)
        return;
    Struct_ov023_021e868c* profile = inline_ov003_02172e84(gameState);
    char* text = self->text_;
    char buffer[0x20] = {};
#if defined(jpn)
    func_02041a28(text, (0xd0 - (strlen(data->name_) * 10 / 2)) / 2);
#else
    func_02041a28(text, (0xd0 - Font_GetTextWidth(data->name_, 0)) >> 1);
#endif
    func_02041fac(text, (int)data->name_, 0x10);
    const char* title = func_02072a68(self->strings_, (short)(profile->unknown_5_1_ + 10000));
    Text_AppendNTag(text, 0, func_02072a68(self->strings_, 2));
    Text_Append(text, func_02072a68(self->strings_, 0x6c));
#if defined(jpn)
    int titleX = (0x6e - strlen(title) * 10 / 2) / 2 + 0x56;
    func_02041a28(text, titleX);
#else
    func_02041a28(text, ((0x6e - Font_GetTextWidth(title, 0)) >> 1) + 0x56);
#endif
    Text_Append(text, title);
    Text_Append(text, func_02072a68(self->strings_, 0));
    Text_AppendNTag(text, 1, func_02072a68(self->strings_, 3));
    func_02041a28(text, 0x4c);
    Text_Append(text, func_02072a68(self->strings_, 0x6c));
    if (profile->unknown_3_7_)
    {
        func_02041a28(text, 0x5a);
    }
    else
    {
        func_02041a90(text, 0x6e, 0x34);
#if defined(jpn)
        func_020474a8(messages, 10, func_02072a68(self->strings_, 0x78), buffer);
#else
        MessageSystem_FormatText(messages, 10, func_02072a68(self->strings_, 0x78), buffer, 0x100, 0, 0);
#endif
        Text_Append(text, buffer);
        func_02041a90(text, 0x5a, 0x28);
    }
    if (profile->unknown_3_4_)
    {
        func_020465c0((StoreStruct*)messages, 0, profile->unknown_0_0_);
        func_020465d8((unsigned char*)messages, 0, 1);
        func_020465f0((unsigned char*)messages, 0, 4);
#if defined(jpn)
        const char* var11 = func_02072a68(self->strings_, 0x64);
        func_020474a8(messages, 10, var11, buffer);
#else
        MessageSystem_FormatText(messages, 10, func_02072a68(self->strings_, 0x64), buffer, 0x100, 0, 0);
#endif
        Text_Append(text, buffer);
        memset(buffer, 0, sizeof(buffer));
        func_020465c0((StoreStruct*)messages, 0, profile->unknown_1_4_);
        func_020465d8((unsigned char*)messages, 0, 1);
        func_020465f0((unsigned char*)messages, 0, 2);
#if defined(jpn)
        const char* var12 = func_02072a68(self->strings_, 0x65);
        func_020474a8(messages, 10, var12, buffer);
#else
        MessageSystem_FormatText(messages, 10, func_02072a68(self->strings_, 0x65), buffer, 0x100, 0, 0);
#endif
        Text_Append(text, buffer);
        memset(buffer, 0, sizeof(buffer));
        func_020465c0((StoreStruct*)messages, 0, profile->unknown_2_0_);
        func_020465d8((unsigned char*)messages, 0, 1);
        func_020465f0((unsigned char*)messages, 0, 2);
#if defined(jpn)
        const char* var13 = func_02072a68(self->strings_, 0x66);
        func_020474a8(messages, 10, var13, buffer);
#else
        MessageSystem_FormatText(messages, 10, func_02072a68(self->strings_, 0x66), buffer, 0x100, 0, 0);
#endif
        Text_Append(text, buffer);
        Text_Append(text, func_02072a68(self->strings_, 0));
    }
    else
    {
#if defined(jpn)
        func_020474a8(messages, 10, func_02072a68(self->strings_, 0x6e), buffer);
#else
        MessageSystem_FormatText(messages, 10, func_02072a68(self->strings_, 0x6e), buffer, 0x100, 0, 0);
#endif
        Text_Append(text, buffer);
        memset(buffer, 0, sizeof(buffer));
#if defined(jpn)
        func_020474a8(messages, 10, func_02072a68(self->strings_, 0x6f), buffer);
#else
        MessageSystem_FormatText(messages, 10, func_02072a68(self->strings_, 0x6f), buffer, 0x100, 0, 0);
#endif
        Text_Append(text, buffer);
        memset(buffer, 0, sizeof(buffer));
#if defined(jpn)
        func_020474a8(messages, 10, func_02072a68(self->strings_, 0x70), buffer);
#else
        MessageSystem_FormatText(messages, 10, func_02072a68(self->strings_, 0x70), buffer, 0x100, 0, 0);
#endif
        Text_Append(text, buffer);
        Text_Append(text, func_02072a68(self->strings_, 0));
    }
    int accolade = profile->accolade_;
#if defined(jpn)
    const char* accoladeText;
    if (accolade < 700)
        accoladeText = (const char*)KeyTable_Get(self->vocationStrings_, (short)accolade);
    else
        accoladeText = func_02072a68(self->strings_, (short)(accolade + 20000));
#else
    short var15 = accolade + 20000;
    if (accolade < 700)
        var15 = accolade;
    const char* accoladeText = func_02072a68(self->strings_, var15);
#endif
    func_02041a5c(text, 0x42);
    Text_AppendNTag(text, 2, func_02072a68(self->strings_, 4));
    func_02041a28(text, 0x4c);
    Text_Append(text, func_02072a68(self->strings_, 0x6c));
#if defined(jpn)
    int var17 = (0x6e - strlen(accoladeText) * 10 / 2) / 2 + 0x56;
    func_02041a28(text, var17);
#else
    func_02041a28(text, ((0x6e - Font_GetTextWidth(accoladeText, 0)) >> 1) + 0x56);
#endif
    Text_Append(text, accoladeText);
    Text_Append(text, func_02072a68(self->strings_, 0));
#if defined(jpn)
    const char* vocation;
    if (profile->unknown_3_3_)
        vocation = func_02072a68(self->strings_, (short)(profile->unknown_2_5_ + 30000));
    else
        vocation = func_02072a68(self->strings_, 0x6d);
#else
    short id = 0x6d;
    if (profile->unknown_3_3_)
        id = profile->unknown_2_5_ + 30000;
    const char* vocation = func_02072a68(self->strings_, id);
#endif
    Text_AppendNTag(text, 3, func_02072a68(self->strings_, 5));
    func_02041a28(text, 0x4c);
    Text_Append(text, func_02072a68(self->strings_, 0x6c));
#if defined(jpn)
    int var20 = (0x6e - strlen(vocation) * 10 / 2) / 2 + 0x56;
    func_02041a28(text, var20);
#else
    func_02041a28(text, ((0x6e - Font_GetTextWidth(vocation, 0)) >> 1) + 0x56);
#endif
    Text_Append(text, vocation);
}

#if defined(jpn)
#undef func_02041a5c
#undef func_02041fac
#endif
