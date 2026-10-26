#include "GameState/BattleRecordSnapshot.h"
#include <globaldefs.h>
#include <std_library_functions.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"

struct Container020e0310;
struct MessageSystem;
struct StoreStruct;

extern "C" void __clear(void* buffer, unsigned long size);
extern "C" void* ExtractFileFromGP2(const char* gp2, const char* inner, unsigned int* size);
extern "C" const char* func_020e046c(char* output, void* file, unsigned int size, short id);
extern "C" int Font_GetTextWidth(const char* text, int large);
extern "C" char* Scenario_GetInstance();
extern "C" void func_02046380(MessageSystem* messages);

extern "C" MessageSystem* MessageSystem_GetInstance();
extern "C" void func_02041a90(char* text, int x, int y);
extern "C" void func_02041a5c(char* text, int y);
extern "C" void Text_Append(char* text, const char* append);
extern "C" void func_0204201c(char* text, int append, int);
extern "C" int Scenario_TestFlag(int, unsigned char*, int);
extern "C" const char* KeyTable_Get(Container020e0310* texts, int id);
extern "C" int func_020a0870(Struct_02061c04* records);
extern "C" int func_020a08d8(Struct_02061c04* records);
extern "C" int func_020a08a4(Struct_02061c04* records);
extern "C" int func_020a090c(Struct_02061c04* records);
extern "C" void func_020465c0(StoreStruct* messages, int index, int value);

#if defined(jpn)
extern char data_ov008_0218c0d5[];
extern "C" int func_020e2168(char*, const char*, int, int, bool);
extern "C" void func_02041f50(char*, char*);
extern "C" int STD_GetStringLength(const char*);
extern "C" void func_020465f0(unsigned char*, int, unsigned char);
extern "C" void func_020465d8(unsigned char*, int, unsigned char);
#endif
extern char data_ov008_0218b465[];
extern char data_ov008_0218b47c[];

struct Struct_ov008_021843f8_2
{
    char unk_0[0x10];
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
    unsigned char female_ : 1;
};

struct Struct_ov008_02187f6c_2
{
    char unk_0[0x49c];
    Struct_ov008_02187f6c appearance_;
};

struct Struct_ov008_02187f6c_3
{
#if defined(jpn)
    char unk_0[0x144];
#else
    char unk_0[0x150];
#endif
    Struct_ov008_02187f6c_2* unknown_150_;
};

struct Struct_ov008_021842a0_2
{
    char unk_0[0xa0];
    char texts_[0x18];
    char* text_;
#if defined(jpn)
    char unk_bc[0xb30 - 0xbc];
#else
    char unk_bc[0xb34 - 0xbc];
#endif
    Struct_ov008_02187278* unknown_b34_;
};

// JPN: func_ov008_02188408 (021890ec)
// USA: func_ov008_02188408
extern "C" ARM void func_ov008_02188408(Struct_ov008_021842a0_2* self, char* text, int kind, Struct_ov008_021843f8_2* records)
{
    if (text == NULL)
        return;
    MessageSystem* messages = MessageSystem_GetInstance();
    if (records != NULL)
    {
        Struct_ov008_02187f6c_3* hero = (Struct_ov008_02187f6c_3*)GameState::GetInstance()->GetProtagonist();
#if defined(jpn)
        char* name = self->text_ + 0x780;
        func_020e2168(name, data_ov008_0218c0d5, records->unknown_12_7_, hero->unknown_150_->appearance_.female_, 1);
        char plainName[0x80];
        __clear(plainName, sizeof(plainName));
        func_02041f50(name, plainName);
        int length = STD_GetStringLength(plainName);
        int x = (0x80 - (length / 2) * 12) / 2;
        int y = 6;
        if (length != STD_GetStringLength(name)) y = 8;
        func_02041a90(text, x, y);
        Text_Append(text, name);
#else
        char* name = self->text_ + 0x8e0;
        BackgroundLoader::AddLockGlobal();
        unsigned int size = 0;
        char gp2[0x40];
        char inner[0x20];
        __clear(gp2, sizeof(gp2));
        __clear(inner, sizeof(inner));
        sprintf(gp2, data_ov008_0218b465, hero->unknown_150_->appearance_.female_);
        sprintf(inner, data_ov008_0218b47c, hero->unknown_150_->appearance_.female_);
        void* file = ExtractFileFromGP2(gp2, inner, &size);
        if (file != NULL)
            func_020e046c(name, file, size, (short)records->unknown_12_7_);
        BackgroundLoader::RemoveLockGlobal();
        int x = (0xa0 - Font_GetTextWidth(name, 1)) / 2;
        if (x < 0)
            x = 0;
        func_02041a90(text, x, 6);
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
        for (int i = 0; i < count; i++)
        {
            func_02041a90(text, 4, i * 15 + 4);
            Text_Append(text, KeyTable_Get((Container020e0310*)&self->texts_, (short)(i + 0x82)));
        }
    }
    else if (kind == 1)
    {
        unsigned int count1;
        unsigned int count2;
        unsigned int var18;
        unsigned int var19;
        Struct_ov008_02187278* var20 = self->unknown_b34_;
        if (var20 != NULL)
        {
            count1 = var20->unknown_9_6_;
            count2 = var20->unknown_f_0_;
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
            count1 = func_020a0870(&var21);
            count2 = func_020a08d8(&var21);
            var18 = func_020a08a4(&var21);
            var19 = func_020a090c(&var21);
            if (count1 == 0 && var22 > 0)
                count1 = 1;
            if (count2 == 0 && var23 > 0)
                count2 = 1;
            if (var18 == 0 && var24 > 0)
                var18 = 1;
            if (var19 == 0 && var25 > 0)
                var19 = 1;
        }
        func_02046380(messages);
        func_020465c0((StoreStruct*)messages, 0, count1);
#if defined(jpn)
        func_020465f0((unsigned char*)messages, 0, 3);
        func_020465d8((unsigned char*)messages, 0, 1);
#endif
        func_020465c0((StoreStruct*)messages, 1, count2);
#if defined(jpn)
        func_020465f0((unsigned char*)messages, 1, 3);
        func_020465d8((unsigned char*)messages, 1, 1);
#endif
        func_020465c0((StoreStruct*)messages, 2, var18);
#if defined(jpn)
        func_020465f0((unsigned char*)messages, 2, 3);
        func_020465d8((unsigned char*)messages, 2, 1);
#endif
        func_020465c0((StoreStruct*)messages, 3, var19);
#if defined(jpn)
        func_020465f0((unsigned char*)messages, 3, 3);
        func_020465d8((unsigned char*)messages, 3, 1);
#endif
        for (int i = 0; i < count; i++)
        {
#if defined(jpn)
            Text_Append(text, KeyTable_Get((Container020e0310*)&self->texts_, (short)(i + 0x8c)));
#else
            func_02041a5c(text, i * 15 + 4);
            func_0204201c(text, (int)KeyTable_Get((Container020e0310*)&self->texts_, (short)(i + 0x8c)), 0x18);
#endif
        }
    }
}
