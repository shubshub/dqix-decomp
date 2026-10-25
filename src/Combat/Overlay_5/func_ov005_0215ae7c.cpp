#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

#if defined(jpn)
#define func_ov005_0215ae7c func_ov005_0215c33c
#define LOW_REGION(j,u) (j)
#else
#define LOW_REGION(j,u) (u)
#endif

struct MessageSystem;
struct Field150Holder02052e14;
struct ItemTable;
struct Container020e0310;

struct Struct_ov005_02153ba4_2
{
    char unknown_0_[LOW_REGION(0x4f8,0x4fc)];
    int unknown_4fc_;
};

struct Struct_0201099c_9
{
    int unknown_0_;
    const char* unknown_4_;
};

struct Struct_ov005_02153954
{
    char unk_0[0xdf4];
    ItemTable* items_;
    char texts_[LOW_REGION(0x3d7c,0x3e04) - 0xdf8];
    signed char unk_3e04;
    char unk_3e05[0x3e84 - 0x3e05];
    unsigned short names_[8][LOW_REGION(0xa,0x40)];
    unsigned char longNames_[8];
};

MessageSystem* MessageSystem_GetInstance();
MemberScreen* GetField1c_021a193c(int* obj);
short* GetField150Ptr0x488(Field150Holder02052e14* member);
extern "C" void func_020462d0(MessageSystem* messages, unsigned short* codes, int count);
Element020de650* ItemTable_Find(ItemTable* c, int key);
extern "C" void __clear(void* buffer, unsigned long size);
void CopyTextAndUppercaseIfFlagged0206819c(const char* name, char* output, int flag);
extern "C" void MessageSystem_FormatText(MessageSystem* messages, int, const char* format, char* output, int size, int, int);
const char* KeyTable_Get(Container020e0310* texts, int id);
int FindSubstring_020d2f88(char* text, char* search);
extern "C" void func_02045d14(MessageSystem* messages, const char* text, unsigned short* codes, int);
extern "C" void func_020439b0(MessageSystem* messages, int);
#if defined(jpn)
extern "C" void func_020471d0(Struct_02021b84* arg0, int, unsigned short* arg2, int);
extern "C" void func_020469b0(Struct_02021b84* arg0, const char* arg1, unsigned short* arg2, int);
#endif

extern "C" const unsigned char data_ov005_0215cc04[8];
extern "C" char data_ov005_0215ce08[];

// USA: func_ov005_0215ae7c
extern "C" ARM void func_ov005_0215ae7c(Struct_ov005_02153954* arg0)
{
    MessageSystem* messages = MessageSystem_GetInstance();
    GameState* gameState = GameState::GetInstance();
    Field150Holder02052e14* member =
        (Field150Holder02052e14*)GetCombatantWithFlag0x100_0200ff1c(gameState, GetField1c_021a193c((int*)GetGameResources()->unknown_ptr_array_3700[2])->member_);
    if (member == NULL)
        return;
    short* var3 = func_02052e14(var2);
    for (int var4 = 0; var4 < 8; var4++)
    {
#if defined(jpn)
        func_020471d0(var0, 0xa, arg0->unknown_3e84_[var4], 0xa);
#else
        func_020462d0(var0, arg0->unknown_3e84_[var4], 0x40);
#endif
        for (int var5 = 0; var5 < LOW_REGION(0xa,0x40); var5++)
            arg0->unknown_3e84_[var4][var5] = 0xffff;
#if !defined(jpn)
        arg0->unknown_4284_[var4] = 0;
#endif
    }
    for (int var6 = 0; var6 < 8; var6++)
    {
        short item = equipment[data_ov005_0215cc04[i]];
        Element020de650* entry = ItemTable_Find(self->items_, item);
#if defined(jpn)
        if (var8 != NULL)
        {
            func_020469b0(var0, var8->unknown_4_, arg0->unknown_3e84_[var6], 0xa);
        }
        else if (var7 <= 0)
        {
            func_020469b0(messages, KeyTable_Get((Container020e0310*)self->texts_, 0x2ee0), self->names_[i], 0xa);
        }
        else
        {
            func_020469b0(messages, KeyTable_Get((Container020e0310*)self->texts_, 0x32c7), self->names_[i], 0xa);
        }
#else
        char var9[0x80];
        __clear(var9, sizeof(var9));
        if (var8 != NULL)
        {
            char name[0x80];
            __clear(name, sizeof(name));
            CopyTextAndUppercaseIfFlagged0206819c(entry->unk_4, name, 0);
            MessageSystem_FormatText(messages, 0, name, text, 0x58, 0, 0);
        }
        else if (var7 <= 0)
        {
            MessageSystem_FormatText(messages, 0, KeyTable_Get((Container020e0310*)self->texts_, 0x2ee0), text, 0x58, 0, 0);
        }
        else
        {
            MessageSystem_FormatText(messages, 0, KeyTable_Get((Container020e0310*)self->texts_, 0x32c7), text, 0x58, 0, 0);
        }
        if (func_020d2f88(var9, data_ov005_0215ce08))
            arg0->unknown_4284_[var6] = 1;
        func_02045d14(var0, var9, arg0->unknown_3e84_[var6], 0);
#endif
        func_020439b0(var0, 0);
        arg0->unknown_3e04_ = 2;
    }
}
