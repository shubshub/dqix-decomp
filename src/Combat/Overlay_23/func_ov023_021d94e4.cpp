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
    int unknown_0_;
    unsigned short unknown_4_0_ : 7;
    unsigned short unknown_4_7_ : 9;
    short unknown_6_;
    Struct_ov023_021d94e4_4 unknown_8_[3];
};

struct Struct_ov023_021d94e4_2
{
#if defined(jpn)
    char unknown_0_[0x7b8];
#else
    char unknown1_0_[0x850];
#endif

    Struct_ov023_021d94e4_4 unknown_850_[13][3];
};

struct Struct_ov023_021d94e4_3
{
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    int unknown_4_;
#if defined(jpn)
    char unknown_8_[0xc];
#else
    char unknown1_8_[0x30];
#endif

    Struct_ov023_021d94e4_2 unknown_38_;
};

struct Struct_0201099c_3;

struct Struct_ov023_021d94e4_5
{
    struct Struct_0201099c_3* unknown_0_;
    char unknown_4_[0xec - 4];
    int unknown_ec_;
    Struct_ov023_021d94e4 unknown_f0_;
    Struct_ov023_021d94e4 unknown_104_;
    unsigned char unknown_118_;
    unsigned char unknown_119_;
    unsigned char unknown_11a_;
    unsigned char unknown_11b_;
    unsigned char unknown_11c_;
    signed char unknown_11d_;
    unsigned char unknown_11e_;
    Struct_ov023_021d94e4_3* unknown_120_;
};

struct Struct_02046574_2;
struct Struct_020465c0;

void* MessageSystem_GetInstance();
BattleResultMember_021d94e4* Find_021d994c(void* self, int id);
int AccumulateFlaggedSlotBits02085fb4(unsigned char* data);
int AccumulateFlaggedSlotBits02086020(unsigned char* data);
int AccumulateFlaggedSlotBits0208608c(unsigned char* data);
int AccumulateFlaggedSlotBits020860f8(unsigned char* data);
int AccumulateFlaggedSlotBits02086164(unsigned char* data);
int AccumulateFlaggedSlotBits020861d0(unsigned char* data);
int AccumulateFlaggedSlotBits0208623c(unsigned char* data);
int AccumulateSlotBitsFromTable020862a8(unsigned char* data);
int AccumulateSlotBitsFromTable02086314(unsigned char* data);
const char* KeyTable_Get(struct Container020e0310* c, int key);
extern "C" int Font_GetTextWidth(const char* text, int large);
void AppendXYTag_02041a90(char* text, int x, int y);
void AppendFormatted02041fac(char* text, int line, int value);
extern "C" void __clear(void* buffer, unsigned long size);
extern "C" void func_02046380(void* messages);
void MessageSystem_SetStringArgument(struct Obj02046574* obj, int index, char* str);
void StoreInArray0x8b0_020465c0(struct StoreStruct* base, int index, int value);
void SetByteAtIndex_020465d8(unsigned char* base, int index, unsigned char value);
void SetByteInRange_020465f0(unsigned char* base, int index, unsigned char value);
extern "C" int sprintf(char* buffer, const char* format, ...);
extern "C" void MessageSystem_FormatText(void* messages, int, const char* input, char* output, int, int, int);
void Text_Append(char* text, const char* append);

#if defined(jpn)
extern "C" void func_020474a8(void*,int,const char*,char*);
#endif
// USA: func_ov023_021d94e4
extern "C" ARM void func_ov023_021d94e4(Struct_ov023_021d94e4_5* arg0, char* arg1, unsigned char arg2)
{
    if (arg1 == NULL || arg0->unknown_ec_ == -1)
        return;
    GameState::GetInstance();
    void* messages = MessageSystem_GetInstance();
    if (self->members_ == NULL)
        return;
    Struct_ov023_021d94e4_3* var1 = func_ov023_021d994c(arg0, arg0->unknown_ec_);
    if (var1 == NULL)
        return;
    Struct_ov023_021d94e4_4* var2 = var1->unknown_38_.unknown_850_[var1->unknown_1_];
    unsigned char* var3 = (unsigned char*)&var1->unknown_38_;
    short var4[9][2];
    var4[0][0] = func_02085fb4(var3) + arg0->unknown_f0_.unknown_8_[0].unknown_0_0_ + var2[0].unknown_0_0_;
    var4[1][0] = func_02086020(var3) + arg0->unknown_f0_.unknown_8_[0].unknown_1_2_ + var2[0].unknown_1_2_;
    var4[2][0] = func_0208608c(var3) + arg0->unknown_f0_.unknown_8_[0].unknown_2_4_ + var2[0].unknown_2_4_;
    var4[3][0] = func_020860f8(var3) + arg0->unknown_f0_.unknown_8_[1].unknown_0_0_ + var2[1].unknown_0_0_;
    var4[4][0] = func_02086164(var3) + arg0->unknown_f0_.unknown_8_[1].unknown_1_2_ + var2[1].unknown_1_2_;
    var4[5][0] = func_020861d0(var3) + arg0->unknown_f0_.unknown_8_[1].unknown_2_4_ + var2[1].unknown_2_4_;
    var4[6][0] = func_0208623c(var3) + arg0->unknown_f0_.unknown_8_[2].unknown_0_0_ + var2[2].unknown_0_0_;
    var4[7][0] = func_020862a8(var3) + arg0->unknown_f0_.unknown_8_[2].unknown_1_2_ + var2[2].unknown_1_2_;
    var4[8][0] = func_02086314(var3) + arg0->unknown_f0_.unknown_8_[2].unknown_2_4_ + var2[2].unknown_2_4_;
    var4[0][1] = var4[0][0] + arg0->unknown_104_.unknown_8_[0].unknown_0_0_;
    var4[1][1] = var4[1][0] + arg0->unknown_104_.unknown_8_[0].unknown_1_2_;
    var4[2][1] = var4[2][0] + arg0->unknown_104_.unknown_8_[0].unknown_2_4_;
    var4[3][1] = var4[3][0] + arg0->unknown_104_.unknown_8_[1].unknown_0_0_;
    var4[4][1] = var4[4][0] + arg0->unknown_104_.unknown_8_[1].unknown_1_2_;
    var4[5][1] = var4[5][0] + arg0->unknown_104_.unknown_8_[1].unknown_2_4_;
    var4[6][1] = var4[6][0] + arg0->unknown_104_.unknown_8_[2].unknown_0_0_;
    var4[7][1] = var4[7][0] + arg0->unknown_104_.unknown_8_[2].unknown_1_2_;
    var4[8][1] = var4[8][0] + arg0->unknown_104_.unknown_8_[2].unknown_2_4_;
    for (int var5 = 0; var5 < 9; var5++)
    {
        if (var5 == 7)
        {
            if (var4[var5][0] <= 0)
                var4[var5][0] = 1;
            if (var4[var5][1] <= 0)
                var4[var5][1] = 1;
        }
        else
        {
            if (var4[var5][0] < 0)
                var4[var5][0] = 0;
            if (var4[var5][1] < 0)
                var4[var5][1] = 0;
        }
        if (var4[var5][0] > 999)
            var4[var5][0] = 999;
        if (var4[var5][1] > 999)
            var4[var5][1] = 999;
    }
#if defined(jpn)
    const char* title = KeyTable_Get(self->texts_, 0x7602);
    Text_Append(text, title);
    for (int line = 0; line < 9; line++) {
        if (lines != 0) {
            AppendXYTag_02041a90(text, 10, line * 15 + 0x15);
            char input[0x100] = {0};
    func_02046380(messages);
    MessageSystem_SetStringArgument((Obj02046574*)messages, 0, (char*)KeyTable_Get(self->texts_, (short)(line + 0x760c)));
    short before = stats[line][0];
    StoreInArray0x8b0_020465c0((StoreStruct*)messages, 0, before);
    SetByteAtIndex_020465d8((unsigned char*)messages, 0, 1);
    SetByteInRange_020465f0((unsigned char*)messages, 0, 3);
    short after = stats[line][1];
    StoreInArray0x8b0_020465c0((StoreStruct*)messages, 1, after);
    SetByteAtIndex_020465d8((unsigned char*)messages, 1, 1);
    SetByteInRange_020465f0((unsigned char*)messages, 1, 3);
    int color = 15;
    if (after > before)
        color = 5;
            StoreInArray0x8b0_020465c0((StoreStruct*)messages, 2, color);
            SetByteAtIndex_020465d8((unsigned char*)messages, 2, 1);
            SetByteInRange_020465f0((unsigned char*)messages, 2, 0);
            func_020474a8(messages,12,KeyTable_Get(self->texts_,0x7603),input);
            Text_Append(text, input);
            lines--;
        }
    }

#else
    const char* title = KeyTable_Get(self->texts_, 0x7602);
    AppendXYTag_02041a90(text, (0xd0 - Font_GetTextWidth(title, 0)) >> 1, 1);
    AppendFormatted02041fac(text, (int)title, 0x10);
    int line;
    const char* format = KeyTable_Get(self->texts_, 0x7603);
    line = lines - 1;
    if (line < 0)
        return;
    AppendXYTag_02041a90(text, 10, line * 15 + 0x15);
    char output[0x100] = {0};
    char input[0x100] = {0};
    func_02046380(messages);
    MessageSystem_SetStringArgument((Obj02046574*)messages, 0, (char*)KeyTable_Get(self->texts_, (short)(line + 0x760c)));
    short before = stats[line][0];
    StoreInArray0x8b0_020465c0((StoreStruct*)messages, 0, before);
    SetByteAtIndex_020465d8((unsigned char*)messages, 0, 1);
    SetByteInRange_020465f0((unsigned char*)messages, 0, 3);
    short after = stats[line][1];
    StoreInArray0x8b0_020465c0((StoreStruct*)messages, 1, after);
    SetByteAtIndex_020465d8((unsigned char*)messages, 1, 1);
    SetByteInRange_020465f0((unsigned char*)messages, 1, 3);
    int color = 15;
    if (after > before)
        color = 5;
    sprintf(input, format, color);
    MessageSystem_FormatText(messages, 12, input, output, 0xe3, 0, 1);
    Text_Append(text, output);

#endif
}
