#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov023_021d94e4_4
{
    unsigned int unknown_0_0_ : 10;
    unsigned int unknown_1_2_ : 10;
    unsigned int unknown_2_4_ : 10;
};

struct Struct_ov023_021d94e4
{
    int unk_0;
    unsigned short level_ : 7;
    unsigned short unknown_4_7_ : 9;
    short unk_6;
    Struct_ov023_021d94e4_4 stats_[3];
};

struct Struct_ov023_021d94e4_2
{
#if defined(jpn)
    char pad0[0x7b8];
#else
    char pad0[0x850];
#endif

    Struct_ov023_021d94e4_4 unknown_850_[13][3];
};

struct Struct_ov023_021d94e4_3
{
    unsigned char id_;
    unsigned char vocation_;
    unsigned char level_;
    unsigned char unknown_3_;
    int experience_;
#if defined(jpn)
    char name_[0xc];
#else
    char name_[0x30];
#endif

    Struct_ov023_021d94e4_2 unknown_38_;
};

struct Container020e0310;

struct Struct_ov023_021d94e4_5
{
    struct Container020e0310* texts_;
    char pad4[0xec - 4];
    int member_;
    Struct_ov023_021d94e4 unknown_f0_;
    Struct_ov023_021d94e4 unknown_104_;
    unsigned char unknown_118_;
    unsigned char count_;
    unsigned char state_;
    unsigned char unknown_11b_;
    unsigned char step_;
    signed char unknown_11d_;
    unsigned char memberCount_;
    Struct_ov023_021d94e4_3* members_;
};

struct Obj02046574;
struct StoreStruct;

extern "C" void* MessageSystem_GetInstance();
extern "C" Struct_ov023_021d94e4_3* func_ov023_021d994c(void* self, int id);
extern "C" int func_02085fb4(unsigned char* data);
extern "C" int func_02086020(unsigned char* data);
extern "C" int func_0208608c(unsigned char* data);
extern "C" int func_020860f8(unsigned char* data);
extern "C" int func_02086164(unsigned char* data);
extern "C" int func_020861d0(unsigned char* data);
extern "C" int func_0208623c(unsigned char* data);
extern "C" int func_020862a8(unsigned char* data);
extern "C" int func_02086314(unsigned char* data);
extern "C" const char* KeyTable_Get(struct Container020e0310* c, int key);
extern "C" int Font_GetTextWidth(const char* text, int large);
extern "C" void func_02041a90(char* text, int x, int y);
extern "C" void func_02041fac(char* text, int line, int value);
extern "C" void __clear(void* buffer, unsigned long size);
extern "C" void func_02046380(void* messages);
extern "C" void MessageSystem_SetStringArgument(struct Obj02046574* obj, int index, char* str);
extern "C" void func_020465c0(struct StoreStruct* base, int index, int value);
extern "C" void func_020465d8(unsigned char* base, int index, unsigned char value);
extern "C" void func_020465f0(unsigned char* base, int index, unsigned char value);
extern "C" int sprintf(char* buffer, const char* format, ...);
extern "C" void MessageSystem_FormatText(void* messages, int, const char* input, char* output, int, int, int);
extern "C" void Text_Append(char* text, const char* append);

#if defined(jpn)
extern "C" void func_020474a8(void*,int,const char*,char*);
#endif
// USA: func_ov023_021d94e4
extern "C" ARM void func_ov023_021d94e4(Struct_ov023_021d94e4_5* self, char* text, unsigned char arg2)
{
    if (text == NULL || self->member_ == -1)
        return;
    GameState::GetInstance();
    void* messages = MessageSystem_GetInstance();
    if (self->members_ == NULL)
        return;
    Struct_ov023_021d94e4_3* member = func_ov023_021d994c(self, self->member_);
    if (member == NULL)
        return;
    Struct_ov023_021d94e4_4* var2 = member->unknown_38_.unknown_850_[member->vocation_];
    unsigned char* data = (unsigned char*)&member->unknown_38_;
    short stats[9][2];
    stats[0][0] = func_02085fb4(data) + self->unknown_f0_.stats_[0].unknown_0_0_ + var2[0].unknown_0_0_;
    stats[1][0] = func_02086020(data) + self->unknown_f0_.stats_[0].unknown_1_2_ + var2[0].unknown_1_2_;
    stats[2][0] = func_0208608c(data) + self->unknown_f0_.stats_[0].unknown_2_4_ + var2[0].unknown_2_4_;
    stats[3][0] = func_020860f8(data) + self->unknown_f0_.stats_[1].unknown_0_0_ + var2[1].unknown_0_0_;
    stats[4][0] = func_02086164(data) + self->unknown_f0_.stats_[1].unknown_1_2_ + var2[1].unknown_1_2_;
    stats[5][0] = func_020861d0(data) + self->unknown_f0_.stats_[1].unknown_2_4_ + var2[1].unknown_2_4_;
    stats[6][0] = func_0208623c(data) + self->unknown_f0_.stats_[2].unknown_0_0_ + var2[2].unknown_0_0_;
    stats[7][0] = func_020862a8(data) + self->unknown_f0_.stats_[2].unknown_1_2_ + var2[2].unknown_1_2_;
    stats[8][0] = func_02086314(data) + self->unknown_f0_.stats_[2].unknown_2_4_ + var2[2].unknown_2_4_;
    stats[0][1] = stats[0][0] + self->unknown_104_.stats_[0].unknown_0_0_;
    stats[1][1] = stats[1][0] + self->unknown_104_.stats_[0].unknown_1_2_;
    stats[2][1] = stats[2][0] + self->unknown_104_.stats_[0].unknown_2_4_;
    stats[3][1] = stats[3][0] + self->unknown_104_.stats_[1].unknown_0_0_;
    stats[4][1] = stats[4][0] + self->unknown_104_.stats_[1].unknown_1_2_;
    stats[5][1] = stats[5][0] + self->unknown_104_.stats_[1].unknown_2_4_;
    stats[6][1] = stats[6][0] + self->unknown_104_.stats_[2].unknown_0_0_;
    stats[7][1] = stats[7][0] + self->unknown_104_.stats_[2].unknown_1_2_;
    stats[8][1] = stats[8][0] + self->unknown_104_.stats_[2].unknown_2_4_;
    for (int i = 0; i < 9; i++)
    {
        if (i == 7)
        {
            if (stats[i][0] <= 0)
                stats[i][0] = 1;
            if (stats[i][1] <= 0)
                stats[i][1] = 1;
        }
        else
        {
            if (stats[i][0] < 0)
                stats[i][0] = 0;
            if (stats[i][1] < 0)
                stats[i][1] = 0;
        }
        if (stats[i][0] > 999)
            stats[i][0] = 999;
        if (stats[i][1] > 999)
            stats[i][1] = 999;
    }
#if defined(jpn)
    const char* title = KeyTable_Get(self->texts_, 0x7602);
    Text_Append(text, title);
    for (int line = 0; line < 9; line++) {
        if (arg2 != 0) {
            func_02041a90(text, 10, line * 15 + 0x15);
            char input[0x100] = {0};
    func_02046380(messages);
    MessageSystem_SetStringArgument((Obj02046574*)messages, 0, (char*)KeyTable_Get(self->texts_, (short)(line + 0x760c)));
    short before = stats[line][0];
    func_020465c0((StoreStruct*)messages, 0, before);
    func_020465d8((unsigned char*)messages, 0, 1);
    func_020465f0((unsigned char*)messages, 0, 3);
    short after = stats[line][1];
    func_020465c0((StoreStruct*)messages, 1, after);
    func_020465d8((unsigned char*)messages, 1, 1);
    func_020465f0((unsigned char*)messages, 1, 3);
    int color = 15;
    if (after > before)
        color = 5;
            func_020465c0((StoreStruct*)messages, 2, color);
            func_020465d8((unsigned char*)messages, 2, 1);
            func_020465f0((unsigned char*)messages, 2, 0);
            func_020474a8(messages,12,KeyTable_Get(self->texts_,0x7603),input);
            Text_Append(text, input);
            arg2--;
        }
    }

#else
    const char* title = KeyTable_Get(self->texts_, 0x7602);
    func_02041a90(text, (0xd0 - Font_GetTextWidth(title, 0)) >> 1, 1);
    func_02041fac(text, (int)title, 0x10);
    int line;
    const char* format = KeyTable_Get(self->texts_, 0x7603);
    line = arg2 - 1;
    if (line < 0)
        return;
    func_02041a90(text, 10, line * 15 + 0x15);
    char output[0x100] = {0};
    char input[0x100] = {0};
    func_02046380(messages);
    MessageSystem_SetStringArgument((Obj02046574*)messages, 0, (char*)KeyTable_Get(self->texts_, (short)(line + 0x760c)));
    short before = stats[line][0];
    func_020465c0((StoreStruct*)messages, 0, before);
    func_020465d8((unsigned char*)messages, 0, 1);
    func_020465f0((unsigned char*)messages, 0, 3);
    short after = stats[line][1];
    func_020465c0((StoreStruct*)messages, 1, after);
    func_020465d8((unsigned char*)messages, 1, 1);
    func_020465f0((unsigned char*)messages, 1, 3);
    int color = 15;
    if (after > before)
        color = 5;
    sprintf(input, format, color);
    MessageSystem_FormatText(messages, 12, input, output, 0xe3, 0, 1);
    Text_Append(text, output);

#endif
}
