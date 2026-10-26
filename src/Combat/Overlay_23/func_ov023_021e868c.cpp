#include <globaldefs.h>
#include <std_library_functions.h>
#include "GameState/GameState.h"

struct Struct_02021b84;
struct Struct_02072a68_2;
struct Struct_020465c0;
struct Struct_0202c1a4;
struct Struct_0201099c_3;

struct Struct_ov023_021e868c {
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
};

struct Struct_ov023_021e868c_2 {
    char unknown_0_[0x3c];
    char unknown_3c_[1];
};

struct Struct_ov023_021e868c_3 {
    char unknown_0_[0x5d8];
    char* unknown_5d8_;
    char unknown_5dc_[0x5f4 - 0x5dc];
    Struct_02072a68_2* unknown_5f4_;
#if defined(jpn)
    Struct_0201099c_3* unknown_5f8_;
#endif
};

struct Struct_01ff91ac_27 {
    char unknown_0_[0x5400];
    Struct_ov023_021e868c unknown_5400_;
};

struct Struct_01ff91ac_28 {
#if defined(jpn)
    char unknown_0_[0x3c];
#else
    char unknown1_0_[0x29c];
#endif
    Struct_01ff91ac_27 unknown_29c_;
};

static inline Struct_ov023_021e868c* inline_ov003_02172e84(GameState* arg0)
{
    return &((Struct_01ff91ac_28*)arg0)->unknown_29c_.unknown_5400_;
}

int MessageSystem_GetInstance();
int LinkSession_IsActive(int* unknown);
PartyMemberData_021e868c* GetFieldAt0x150_02053c6c(unsigned char* member);
int LinkSession_GetOwnSlot(SearchStruct0202c1a4* unknown);
void AppendXTag_02041a28(char* text, int x);
#if defined(jpn)
extern "C" int Font_GetTextWidth(char* text, int y);
#define AppendYTag_02041a5c Font_GetTextWidth
#else
extern "C" int func_02041a5c(char* arg0, int arg1);
#endif
void AppendXYTag_02041a90(char* text, int x, int y);
void Text_AppendNTag(char* text, int item, const char* itemText);
#if defined(jpn)
extern "C" int func_02042638(char* arg0, int arg1, int arg2);
#define func_02041fac func_02042638
#else
extern "C" int func_02041fac(char* arg0, int arg1, int arg2);
#endif
void Text_Append(char* text, const char* append);
const char* FindEntryByKey_02072a68(TableA68* texts, int id);
void StoreInArray0x8b0_020465c0(StoreStruct* messages, int index, int value);
void SetByteAtIndex_020465d8(unsigned char* messages, int index, unsigned char value);
void SetByteInRange_020465f0(unsigned char* messages, int index, unsigned char digits);

extern "C" {
void* LinkSession_GetInstance();
#if defined(jpn)
void func_020474a8(Struct_02021b84* arg0, unsigned char arg1, const char* arg2, char* arg3);
#else
int Font_GetTextWidth(const char* text, int large);
void MessageSystem_FormatText(MessageSystem* messages, int a, const char* format, char* output, int size, int b, int c);
#endif
}
#if defined(jpn)
int KeyTable_Get(Container020e0310* strings, int key);
#endif

// USA: func_ov023_021e868c
// JPN: func_ov023_021e85e0
extern "C" ARM void func_ov023_021e868c(Struct_ov023_021e868c_3* arg0)
{
    GameState* gameState = GameState::GetInstance();
    MessageSystem* messages = (MessageSystem*)MessageSystem_GetInstance();
    void* unknown = LinkSession_GetInstance();
    PartyMemberData_021e868c* data = NULL;
    if (LinkSession_IsActive((int*)unknown) == 0)
    {
        void* var4 = func_0200ff1c(var0, 0);
        if (var4 != NULL)
            var3 = func_02053c6c((unsigned char*)var4);
    }
    else
    {
        void* member = GetCombatantWithFlag0x100_0200ff1c(gameState, LinkSession_GetOwnSlot((SearchStruct0202c1a4*)unknown));
        if (member != NULL)
            data = GetFieldAt0x150_02053c6c((unsigned char*)member);
    }
    if (var3 == NULL)
        return;
    Struct_ov023_021e868c* var6 = inline_ov003_02172e84(var0);
    char* var7 = arg0->unknown_5d8_;
    char var8[0x20] = {};
#if defined(jpn)
    func_02041a28(var7, (0xd0 - (strlen(var3->unknown_3c_) * 10 / 2)) / 2);
#else
    AppendXTag_02041a28(text, (0xd0 - Font_GetTextWidth(data->name_, 0)) >> 1);
#endif
    AppendFormatted02041fac(text, (int)data->name_, 0x10);
    const char* title = FindEntryByKey_02072a68(self->strings_, (short)(profile->title_ + 10000));
    Text_AppendNTag(text, 0, FindEntryByKey_02072a68(self->strings_, 2));
    Text_Append(text, FindEntryByKey_02072a68(self->strings_, 0x6c));
#if defined(jpn)
    int var10 = (0x6e - strlen(var9) * 10 / 2) / 2 + 0x56;
    func_02041a28(var7, var10);
#else
    AppendXTag_02041a28(text, ((0x6e - Font_GetTextWidth(title, 0)) >> 1) + 0x56);
#endif
    Text_Append(text, title);
    Text_Append(text, FindEntryByKey_02072a68(self->strings_, 0));
    Text_AppendNTag(text, 1, FindEntryByKey_02072a68(self->strings_, 3));
    AppendXTag_02041a28(text, 0x4c);
    Text_Append(text, FindEntryByKey_02072a68(self->strings_, 0x6c));
    if (profile->showBirthday_)
    {
        func_02041a28(var7, 0x5a);
    }
    else
    {
        func_02041a90(var7, 0x6e, 0x34);
#if defined(jpn)
        func_020474a8(var1, 10, func_02072a68(arg0->unknown_5f4_, 0x78), var8);
#else
        MessageSystem_FormatText(messages, 10, FindEntryByKey_02072a68(self->strings_, 0x78), buffer, 0x100, 0, 0);
#endif
        Text_Append(text, buffer);
        AppendXYTag_02041a90(text, 0x5a, 0x28);
    }
    if (var6->unknown_3_4_)
    {
        func_020465c0((Struct_020465c0*)var1, 0, var6->unknown_0_0_);
        func_020465d8((unsigned char*)var1, 0, 1);
        func_020465f0((unsigned char*)var1, 0, 4);
#if defined(jpn)
        const char* var11 = func_02072a68(arg0->unknown_5f4_, 0x64);
        func_020474a8(var1, 10, var11, var8);
#else
        MessageSystem_FormatText(messages, 10, FindEntryByKey_02072a68(self->strings_, 0x64), buffer, 0x100, 0, 0);
#endif
        Text_Append(text, buffer);
        memset(buffer, 0, sizeof(buffer));
        StoreInArray0x8b0_020465c0((StoreStruct*)messages, 0, profile->month_);
        SetByteAtIndex_020465d8((unsigned char*)messages, 0, 1);
        SetByteInRange_020465f0((unsigned char*)messages, 0, 2);
#if defined(jpn)
        const char* var12 = func_02072a68(arg0->unknown_5f4_, 0x65);
        func_020474a8(var1, 10, var12, var8);
#else
        MessageSystem_FormatText(messages, 10, FindEntryByKey_02072a68(self->strings_, 0x65), buffer, 0x100, 0, 0);
#endif
        Text_Append(text, buffer);
        memset(buffer, 0, sizeof(buffer));
        StoreInArray0x8b0_020465c0((StoreStruct*)messages, 0, profile->day_);
        SetByteAtIndex_020465d8((unsigned char*)messages, 0, 1);
        SetByteInRange_020465f0((unsigned char*)messages, 0, 2);
#if defined(jpn)
        const char* var13 = func_02072a68(arg0->unknown_5f4_, 0x66);
        func_020474a8(var1, 10, var13, var8);
#else
        MessageSystem_FormatText(messages, 10, FindEntryByKey_02072a68(self->strings_, 0x66), buffer, 0x100, 0, 0);
#endif
        Text_Append(text, buffer);
        Text_Append(text, FindEntryByKey_02072a68(self->strings_, 0));
    }
    else
    {
#if defined(jpn)
        func_020474a8(var1, 10, func_02072a68(arg0->unknown_5f4_, 0x6e), var8);
#else
        MessageSystem_FormatText(messages, 10, FindEntryByKey_02072a68(self->strings_, 0x6e), buffer, 0x100, 0, 0);
#endif
        Text_Append(text, buffer);
        memset(buffer, 0, sizeof(buffer));
#if defined(jpn)
        func_020474a8(var1, 10, func_02072a68(arg0->unknown_5f4_, 0x6f), var8);
#else
        MessageSystem_FormatText(messages, 10, FindEntryByKey_02072a68(self->strings_, 0x6f), buffer, 0x100, 0, 0);
#endif
        Text_Append(text, buffer);
        memset(buffer, 0, sizeof(buffer));
#if defined(jpn)
        func_020474a8(var1, 10, func_02072a68(arg0->unknown_5f4_, 0x70), var8);
#else
        MessageSystem_FormatText(messages, 10, FindEntryByKey_02072a68(self->strings_, 0x70), buffer, 0x100, 0, 0);
#endif
        Text_Append(text, buffer);
        Text_Append(text, FindEntryByKey_02072a68(self->strings_, 0));
    }
    int var14 = var6->unknown_6_3_;
#if defined(jpn)
    const char* accoladeText;
    if (accolade < 700)
        accoladeText = (const char*)KeyTable_Get(self->vocationStrings_, (short)accolade);
    else
        var16 = func_02072a68(arg0->unknown_5f4_, (short)(var14 + 20000));
#else
    short var15 = var14 + 20000;
    if (var14 < 700)
        var15 = var14;
    const char* var16 = func_02072a68(arg0->unknown_5f4_, var15);
#endif
    AppendYTag_02041a5c(text, 0x42);
    Text_AppendNTag(text, 2, FindEntryByKey_02072a68(self->strings_, 4));
    AppendXTag_02041a28(text, 0x4c);
    Text_Append(text, FindEntryByKey_02072a68(self->strings_, 0x6c));
#if defined(jpn)
    int var17 = (0x6e - strlen(var16) * 10 / 2) / 2 + 0x56;
    func_02041a28(var7, var17);
#else
    AppendXTag_02041a28(text, ((0x6e - Font_GetTextWidth(accoladeText, 0)) >> 1) + 0x56);
#endif
    Text_Append(text, accoladeText);
    Text_Append(text, FindEntryByKey_02072a68(self->strings_, 0));
#if defined(jpn)
    const char* var19;
    if (var6->unknown_3_3_)
        var19 = func_02072a68(arg0->unknown_5f4_, (short)(var6->unknown_2_5_ + 30000));
    else
        var19 = func_02072a68(arg0->unknown_5f4_, 0x6d);
#else
    short var18 = 0x6d;
    if (var6->unknown_3_3_)
        var18 = var6->unknown_2_5_ + 30000;
    const char* var19 = func_02072a68(arg0->unknown_5f4_, var18);
#endif
    Text_AppendNTag(text, 3, FindEntryByKey_02072a68(self->strings_, 5));
    AppendXTag_02041a28(text, 0x4c);
    Text_Append(text, FindEntryByKey_02072a68(self->strings_, 0x6c));
#if defined(jpn)
    int var20 = (0x6e - strlen(var19) * 10 / 2) / 2 + 0x56;
    func_02041a28(var7, var20);
#else
    AppendXTag_02041a28(text, ((0x6e - Font_GetTextWidth(vocation, 0)) >> 1) + 0x56);
#endif
    Text_Append(text, vocation);
}

#if defined(jpn)
#undef func_02041a5c
#undef func_02041fac
#endif
