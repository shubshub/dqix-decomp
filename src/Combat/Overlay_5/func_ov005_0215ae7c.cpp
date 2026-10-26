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

struct MemberScreen
{
    char unk_0[LOW_REGION(0x4f8,0x4fc)];
    int member_;
};

struct Element020de650
{
    int unk_0;
    const char* unk_4;
};

struct EquipmentMenu
{
    char unk_0[0xdf4];
    ItemTable* items_;
    char texts_[LOW_REGION(0x3d7c,0x3e04) - 0xdf8];
    signed char unknown_3e04_;
    char unknown_3e05_[0x3e84 - 0x3e05];
    unsigned short names_[8][LOW_REGION(0xa,0x40)];
    unsigned char unknown_4284_[8];
};

extern "C" MessageSystem* MessageSystem_GetInstance();
extern "C" MemberScreen* func_ov017_021a193c(int* obj);
extern "C" short* func_02052e14(Field150Holder02052e14* member);
extern "C" void func_020462d0(MessageSystem* messages, unsigned short* codes, int count);
extern "C" Element020de650* ItemTable_Find(ItemTable* c, int key);
extern "C" void __clear(void* buffer, unsigned long size);
extern "C" void func_0206819c(const char* name, char* output, int flag);
extern "C" void MessageSystem_FormatText(MessageSystem* messages, int, const char* format, char* output, int size, int, int);
extern "C" const char* KeyTable_Get(Container020e0310* texts, int id);
extern "C" int func_020d2f88(char* text, char* search);
extern "C" void func_02045d14(MessageSystem* messages, const char* text, unsigned short* codes, int);
extern "C" void func_020439b0(MessageSystem* messages, int);
#if defined(jpn)
extern "C" void func_020471d0(MessageSystem* messages, int, unsigned short* codes, int);
extern "C" void func_020469b0(MessageSystem* messages, const char* text, unsigned short* codes, int);
#endif

extern "C" const unsigned char data_ov005_0215cc04[8];
extern "C" char data_ov005_0215ce08[];

// USA: func_ov005_0215ae7c
extern "C" ARM void func_ov005_0215ae7c(EquipmentMenu* self)
{
    MessageSystem* messages = MessageSystem_GetInstance();
    GameState* gameState = GameState::GetInstance();
    Field150Holder02052e14* member =
        (Field150Holder02052e14*)func_0200ff1c(gameState, func_ov017_021a193c((int*)GetGameResources()->unknown_ptr_array_3700[2])->member_);
    if (member == NULL)
        return;
    short* equipment = func_02052e14(member);
    for (int i = 0; i < 8; i++)
    {
#if defined(jpn)
        func_020471d0(messages, 0xa, self->names_[i], 0xa);
#else
        func_020462d0(messages, self->names_[i], 0x40);
#endif
        for (int j = 0; j < LOW_REGION(0xa,0x40); j++)
            self->names_[i][j] = 0xffff;
#if !defined(jpn)
        self->unknown_4284_[i] = 0;
#endif
    }
    for (int i = 0; i < 8; i++)
    {
        short item = equipment[data_ov005_0215cc04[i]];
        Element020de650* entry = ItemTable_Find(self->items_, item);
#if defined(jpn)
        if (entry != NULL)
        {
            func_020469b0(messages, entry->unk_4, self->names_[i], 0xa);
        }
        else if (item <= 0)
        {
            func_020469b0(messages, KeyTable_Get((Container020e0310*)self->texts_, 0x2ee0), self->names_[i], 0xa);
        }
        else
        {
            func_020469b0(messages, KeyTable_Get((Container020e0310*)self->texts_, 0x32c7), self->names_[i], 0xa);
        }
#else
        char text[0x80];
        __clear(text, sizeof(text));
        if (entry != NULL)
        {
            char name[0x80];
            __clear(name, sizeof(name));
            func_0206819c(entry->unk_4, name, 0);
            MessageSystem_FormatText(messages, 0, name, text, 0x58, 0, 0);
        }
        else if (item <= 0)
        {
            MessageSystem_FormatText(messages, 0, KeyTable_Get((Container020e0310*)self->texts_, 0x2ee0), text, 0x58, 0, 0);
        }
        else
        {
            MessageSystem_FormatText(messages, 0, KeyTable_Get((Container020e0310*)self->texts_, 0x32c7), text, 0x58, 0, 0);
        }
        if (func_020d2f88(text, data_ov005_0215ce08))
            self->unknown_4284_[i] = 1;
        func_02045d14(messages, text, self->names_[i], 0);
#endif
        func_020439b0(messages, 0);
        self->unknown_3e04_ = 2;
    }
}
