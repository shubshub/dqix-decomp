#include "GameState/BattleRecordSnapshot.h"
#include <globaldefs.h>
#include <std_library_functions.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"

struct Struct_0201099c_3;
struct Struct_02021b84;
struct Struct_020465c0;

extern "C" void __clear(void* buffer, unsigned long size);
extern "C" void* ExtractFileFromGP2(const char* gp2, const char* inner, unsigned int* size);
extern "C" const char* func_020e046c(char* output, void* file, unsigned int size, short id);
extern "C" int Font_GetTextWidth(const char* text, int large);
extern "C" char* Scenario_GetInstance();
extern "C" void func_02046380(MessageSystem* messages);

MessageSystem* MessageSystem_GetInstance();
void AppendXYTag_02041a90(char* text, int x, int y);
void AppendYTag_02041a5c(char* text, int y);
void Text_Append(char* text, const char* append);
void AppendFormatted0204201c(char* text, int append, int);
int Scenario_TestFlag(int, unsigned char*, int);
const char* KeyTable_Get(Container020e0310* texts, int id);
int GetFieldPercentOver307_020a0870(BattleRecordSnapshot* records);
int GetFieldPercentOver944_020a08d8(BattleRecordSnapshot* records);
int GetFieldPercentOver232_020a08a4(BattleRecordSnapshot* records);
int GetFieldPercentOver448_020a090c(BattleRecordSnapshot* records);
void StoreInArray0x8b0_020465c0(StoreStruct* messages, int index, int value);

#if defined(jpn)
extern char data_ov008_0218c0d5[];
extern "C" int func_020e2168(char*, const char*, int, int, bool);
extern "C" void func_02041f50(char*, char*);
int STD_GetStringLength(const char*);
void SetByteInRange_020465f0(unsigned char*, int, unsigned char);
void SetByteAtIndex_020465d8(unsigned char*, int, unsigned char);
#endif
extern char data_ov008_0218b465[];
extern char data_ov008_0218b47c[];

struct Struct_ov008_021843f8_2
{
    char unknown_0_[0x10];
    unsigned int unknown_10_0_ : 9;
    unsigned int unknown_11_1_ : 14;
    unsigned int unknown_12_7_ : 9;
};

struct Struct_ov008_02187278
{
    unsigned int unknown_0_0_ : 14;
    unsigned int unknown_1_6_ : 17;
    unsigned int unknown_3_7_ : 1;
    unsigned int unknown_4_0_ : 14;
    unsigned int unknown_5_6_ : 17;
    unsigned int unknown_7_7_ : 1;
    unsigned int unknown_8_0_ : 7;
    unsigned int unknown_8_7_ : 7;
    unsigned int unknown_9_6_ : 7;
    unsigned int unknown_a_5_ : 7;
    unsigned int unknown_b_4_ : 4;
    unsigned int unknown_c_0_ : 10;
    unsigned int unknown_d_2_ : 14;
    unsigned int unknown_f_0_ : 7;
    unsigned int unknown_f_7_ : 1;
    unsigned int unknown_10_0_ : 9;
    unsigned int unknown_11_1_ : 14;
    unsigned int unknown_12_7_ : 7;
    unsigned int unknown_13_6_ : 2;
};

struct Struct_ov008_02187f6c
{
    unsigned char unknown_0_0_ : 1;
};

struct Struct_ov008_02187f6c_2
{
    char unknown_0_[0x49c];
    Struct_ov008_02187f6c unknown_49c_;
};

struct Struct_ov008_02187f6c_3
{
#if defined(jpn)
    char unknown_0_[0x144];
#else
    char unknown1_0_[0x150];
#endif
    Struct_ov008_02187f6c_2* unknown_150_;
};

struct Struct_ov008_021842a0_2
{
    char unknown_0_[0xa0];
    char unknown_a0_[0x18];
    char* unknown_b8_;
#if defined(jpn)
    char unknown_bc_[0xb30 - 0xbc];
#else
    char unknown1_bc_[0xb34 - 0xbc];
#endif
    Struct_ov008_02187278* unknown_b34_;
};

// JPN: func_ov008_02188408 (021890ec)
// USA: func_ov008_02188408
extern "C" ARM void func_ov008_02188408(Struct_ov008_021842a0_2* arg0, char* arg1, int arg2, Struct_ov008_021843f8_2* arg3)
{
    if (arg1 == NULL)
        return;
    MessageSystem* messages = MessageSystem_GetInstance();
    if (records != NULL)
    {
        Struct_ov008_02187f6c_3* var1 = (Struct_ov008_02187f6c_3*)GameState::GetInstance()->GetProtagonist();
#if defined(jpn)
        char* name = self->text_ + 0x780;
        func_020e2168(name, data_ov008_0218c0d5, records->title_, hero->partyData_->appearance_.female_, 1);
        char plainName[0x80];
        __clear(plainName, sizeof(plainName));
        func_02041f50(name, plainName);
        int length = STD_GetStringLength(plainName);
        int x = (0x80 - (length / 2) * 12) / 2;
        int y = 6;
        if (length != STD_GetStringLength(name)) y = 8;
        AppendXYTag_02041a90(text, x, y);
        Text_Append(text, name);
#else
        char* var7 = arg0->unknown_b8_ + 0x8e0;
        BackgroundLoader::AddLockGlobal();
        unsigned int var8 = 0;
        char var9[0x40];
        char var10[0x20];
        __clear(var9, sizeof(var9));
        __clear(var10, sizeof(var10));
        sprintf(var9, data_ov008_0218b465, var1->unknown_150_->unknown_49c_.unknown_0_0_);
        sprintf(var10, data_ov008_0218b47c, var1->unknown_150_->unknown_49c_.unknown_0_0_);
        void* var11 = ExtractFileFromGP2(var9, var10, &var8);
        if (var11 != NULL)
            func_020e046c(var7, var11, var8, (short)arg3->unknown_12_7_);
        BackgroundLoader::RemoveLockGlobal();
        int x = (0xa0 - Font_GetTextWidth(name, 1)) / 2;
        if (x < 0)
            x = 0;
        AppendXYTag_02041a90(text, x, 6);
        if (name != NULL)
            Text_Append(text, name);
#endif
        return;
    }
    int count = 3;
    char* store = Scenario_GetInstance();
    if (Scenario_TestFlag((int)store, (unsigned char*)store + 0x8c, 0x1198))
        count = 4;
    if (kind == 0)
    {
        for (int var15 = 0; var15 < var13; var15++)
        {
            AppendXYTag_02041a90(text, 4, i * 15 + 4);
            Text_Append(text, KeyTable_Get((Container020e0310*)&self->texts_, (short)(i + 0x82)));
        }
    }
    else if (arg2 == 1)
    {
        unsigned int var16;
        unsigned int var17;
        unsigned int var18;
        unsigned int var19;
        Struct_ov008_02187278* var20 = arg0->unknown_b34_;
        if (var20 != NULL)
        {
            var16 = var20->unknown_9_6_;
            var17 = var20->unknown_f_0_;
            var18 = var20->unknown_a_5_;
            var19 = var20->unknown_12_7_;
        }
        else
        {
            Struct_02061c04 var21;
            func_020ac4c0(&var21);
            int var22 = var21.unknown_14_0_;
            int var23 = var21.unknown_16_2_;
            int var24 = var21.unknown_15_1_;
            int var25 = var21.unknown_12_7_;
            var16 = func_020a0870(&var21);
            var17 = func_020a08d8(&var21);
            var18 = func_020a08a4(&var21);
            var19 = func_020a090c(&var21);
            if (var16 == 0 && var22 > 0)
                var16 = 1;
            if (var17 == 0 && var23 > 0)
                var17 = 1;
            if (var18 == 0 && var24 > 0)
                var18 = 1;
            if (var19 == 0 && var25 > 0)
                var19 = 1;
        }
        func_02046380(var0);
        func_020465c0((Struct_020465c0*)var0, 0, var16);
#if defined(jpn)
        func_020465f0((unsigned char*)var0, 0, 3);
        func_020465d8((unsigned char*)var0, 0, 1);
#endif
        func_020465c0((Struct_020465c0*)var0, 1, var17);
#if defined(jpn)
        func_020465f0((unsigned char*)var0, 1, 3);
        func_020465d8((unsigned char*)var0, 1, 1);
#endif
        func_020465c0((Struct_020465c0*)var0, 2, var18);
#if defined(jpn)
        func_020465f0((unsigned char*)var0, 2, 3);
        func_020465d8((unsigned char*)var0, 2, 1);
#endif
        func_020465c0((Struct_020465c0*)var0, 3, var19);
#if defined(jpn)
        func_020465f0((unsigned char*)var0, 3, 3);
        func_020465d8((unsigned char*)var0, 3, 1);
#endif
        for (int var26 = 0; var26 < var13; var26++)
        {
#if defined(jpn)
            Text_Append(text, KeyTable_Get((Container020e0310*)&self->texts_, (short)(i + 0x8c)));
#else
            AppendYTag_02041a5c(text, i * 15 + 4);
            AppendFormatted0204201c(text, (int)KeyTable_Get((Container020e0310*)&self->texts_, (short)(i + 0x8c)), 0x18);
#endif
        }
    }
}
