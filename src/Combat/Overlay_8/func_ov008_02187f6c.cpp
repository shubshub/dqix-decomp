#include <globaldefs.h>

#if defined(jpn)
#define func_ov008_02187f6c func_ov008_02188ccc
#define LOW_REGION(j,u) (j)
#else
#define LOW_REGION(j,u) (u)
#endif
#include <std_library_functions.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"

#if defined(jpn)
#define func_0205ec34 func_0205ff20
#endif

struct Struct_0201099c_3;
struct Struct_02021b84;

extern "C" void __clear(void* arg0, unsigned long arg1);
extern "C" void* ExtractFileFromGP2(const char* arg0, const char* arg1, unsigned int* arg2);
extern "C" const char* func_020e046c(char* arg0, void* arg1, unsigned int arg2, short arg3);
extern "C" int func_020420e8(const char* arg0, int arg1);
extern "C" char* func_0205ec34();

struct Struct_02081870_2;
#if defined(jpn)
extern "C" void func_0205d304(Struct_02081870_2* arg0, char* arg1, int, int, int, int, int);
extern "C" void func_020e2168(char*, const char*, unsigned int, unsigned char, int);
extern "C" void func_02041f50(char*, char*);
extern "C" int func_020d2ff0(const char*);
extern char data_ov008_0218c0d5[];
#else
extern "C" void func_0205d304(Struct_02081870_2* arg0, char* arg1, int, int, int, int, int, int);
#endif

MessageSystem* GetGlobalField0x1c020421a0();
void AppendXYTag_02041a90(char* text, int x, int y);
void AppendString02042058(char* text, const char* append);
int TestBitInByteArray_0206dfb0(int, unsigned char*, int);
const char* KeyTable_Get(Container020e0310* texts, int id);

extern char data_ov008_0218b465[];
extern char data_ov008_0218b47c[];

struct Struct_02081870_2
{
    char unknown_0_[0xa0];
    short unknown_a0_;
    short unknown_a2_;
    short unknown_a4_;
    short unknown_a6_;
    short unknown_a8_;
    short unknown_aa_;
    short unknown_ac_;
    short unknown_ae_;
    unsigned char unknown_b0_;
    unsigned char unknown_b1_;
    unsigned char unknown_b2_;
    unsigned char unknown_b3_;
    unsigned char unknown_b4_;
    unsigned char unknown_b5_;
    unsigned char unknown_b6_;
    unsigned char unknown_b7_;
    unsigned char unknown_b8_;
    unsigned char unknown_b9_;
    unsigned char unknown_ba_;
    unsigned char unknown_bb_;
};

struct Struct_ov008_021843f8_2
{
    char unknown_0_[0x10];
    unsigned int unknown_10_0_ : 9;
    unsigned int unknown_11_1_ : 14;
    unsigned int unknown_12_7_ : 9;
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
    char unknown_0_[LOW_REGION(0x144,0x150)];
    Struct_ov008_02187f6c_2* unknown_150_;
};

struct Struct_ov008_021842a0_2
{
    char unknown_0_[0xa0];
    char unknown_a0_[0x18];
    char* unknown_b8_;
    char unknown_bc_[0x130 - 0xbc];
    Struct_02081870_2 unknown_130_;
};

extern "C" void func_ov008_02188408(Struct_ov008_021842a0_2* arg0, char* arg1, int arg2, Struct_ov008_021843f8_2* arg3);

// USA: func_ov008_02187f6c
extern "C" ARM void func_ov008_02187f6c(Struct_ov008_021842a0_2* arg0, Struct_ov008_021843f8_2* arg1)
{
    if (arg1 != NULL)
    {
        arg0->unknown_130_.unknown_a0_ = LOW_REGION(0x10,0x14);
        arg0->unknown_130_.unknown_a2_ = 3;
        arg0->unknown_130_.unknown_a4_ = LOW_REGION(8,6);
        arg0->unknown_130_.unknown_a6_ = 0x11;
        arg0->unknown_130_.unknown_a8_ = 0;
        arg0->unknown_130_.unknown_aa_ = LOW_REGION(5,6);
        arg0->unknown_130_.unknown_ac_ = 0xc;
        arg0->unknown_130_.unknown_ae_ = 0xe;
        arg0->unknown_130_.unknown_b7_ = 0xc;
        arg0->unknown_130_.unknown_b1_ = 4;
        arg0->unknown_130_.unknown_b5_ = 1;
        arg0->unknown_130_.unknown_b6_ = 1;
        memset(arg0->unknown_b8_, 0, LOW_REGION(0x800,0x960));
        char* var0 = arg0->unknown_b8_;
        if (var0 != NULL)
        {
            func_020421a0();
            if (arg1 != NULL)
            {
    #if defined(jpn)
            Struct_ov008_02187f6c_3* var1 = (Struct_ov008_02187f6c_3*)GameState::GetInstance()->GetProtagonist();
            char* var2 = arg0->unknown_b8_ + 0x780;
            func_020e2168(var2, data_ov008_0218c0d5, arg1->unknown_12_7_, var1->unknown_150_->unknown_49c_.unknown_0_0_, 1);
            char var3[0x80];
            __clear(var3, sizeof(var3));
            func_02041f50(var2, var3);
            int var4 = func_020d2ff0(var3);
            int var5;
            int var6 = (0x80 - (var4 / 2) * 12) / 2;
            var5 = 6;
            if (var4 != func_020d2ff0(var2)) var5 = 8;
            func_02041a90(var0, var6, var5);
            func_02042058(var0, var2);
#else
            Struct_ov008_02187f6c_3* var7 = (Struct_ov008_02187f6c_3*)GameState::GetInstance()->GetProtagonist();
                char* var8 = arg0->unknown_b8_ + 0x8e0;
                BackgroundLoader::AddLockGlobal();
                unsigned int var9 = 0;
                char var10[0x20];
                char var11[0x40];
                __clear(var11, sizeof(var11));
                __clear(var10, sizeof(var10));
                sprintf(var11, data_ov008_0218b465, var7->unknown_150_->unknown_49c_.unknown_0_0_);
                sprintf(var10, data_ov008_0218b47c, var7->unknown_150_->unknown_49c_.unknown_0_0_);
                void* var12 = ExtractFileFromGP2(var11, var10, &var9);
                if (var12 != NULL)
                    func_020e046c(var8, var12, var9, (short)arg1->unknown_12_7_);
                BackgroundLoader::RemoveLockGlobal();
                int var13 = (0xa0 - func_020420e8(var8, 1)) / 2;
                if (var13 < 0)
                    var13 = 0;
                func_02041a90(var0, var13, 6);
                if (var8 != NULL)
                    func_02042058(var0, var8);
#endif
            }
            else
            {
                int var14;
                int var15 = 3;
                char* var16 = func_0205ec34();
                if (func_0206dfb0((int)var16, (unsigned char*)var16 + 0x8c, 0x1198))
                    var15 = 4;
                for (var14 = 0; var14 < var15; var14++)
                {
                    AppendXYTag_02041a90(text, 4, i * 15 + 4);
                    AppendString02042058(text, KeyTable_Get((Container020e0310*)&self->texts_, (short)(i + 0x82)));
                }
            }
        }
        #if defined(jpn)
    func_0205d304(&arg0->unknown_130_, arg0->unknown_b8_, 0, 0, 0, 0, 0);
#else
    func_0205d304(&arg0->unknown_130_, arg0->unknown_b8_, 0, 0, 0, 0, 0, 1);
#endif
        return;
    }
    arg0->unknown_130_.unknown_a0_ = LOW_REGION(0x12,0x16);
    arg0->unknown_130_.unknown_a2_ = 8;
    arg0->unknown_130_.unknown_a4_ = 1;
    arg0->unknown_130_.unknown_a6_ = 0xf;
    arg0->unknown_130_.unknown_a8_ = 4;
    arg0->unknown_130_.unknown_aa_ = 5;
    arg0->unknown_130_.unknown_ac_ = 0xa;
    arg0->unknown_130_.unknown_ae_ = 0xe;
    arg0->unknown_130_.unknown_b7_ = 0xa;
    arg0->unknown_130_.unknown_b1_ = 4;
    arg0->unknown_130_.unknown_b5_ = 1;
    arg0->unknown_130_.unknown_b6_ = 1;
    memset(arg0->unknown_b8_, 0, LOW_REGION(0x800,0x960));
    char* var17 = arg0->unknown_b8_;
    if (var17 != NULL)
    {
        func_020421a0();
        if (arg1 != NULL)
        {
#if defined(jpn)
            Struct_ov008_02187f6c_3* var18 = (Struct_ov008_02187f6c_3*)GameState::GetInstance()->GetProtagonist();
            char* var19 = arg0->unknown_b8_ + 0x780;
            func_020e2168(var19, data_ov008_0218c0d5, arg1->unknown_12_7_, var18->unknown_150_->unknown_49c_.unknown_0_0_, 1);
            char var20[0x80];
            __clear(var20, sizeof(var20));
            func_02041f50(var19, var20);
            int var21 = func_020d2ff0(var20);
            int var22;
            int var23 = (0x80 - (var21 / 2) * 12) / 2;
            var22 = 6;
            if (var21 != func_020d2ff0(var19)) var22 = 8;
            func_02041a90(var17, var23, var22);
            func_02042058(var17, var19);
#else
            Struct_ov008_02187f6c_3* var24 = (Struct_ov008_02187f6c_3*)GameState::GetInstance()->GetProtagonist();
            char* var25 = arg0->unknown_b8_ + 0x8e0;
            BackgroundLoader::AddLockGlobal();
            unsigned int var26 = 0;
            char var27[0x20];
            char var28[0x40];
            __clear(var28, sizeof(var28));
            __clear(var27, sizeof(var27));
            sprintf(var28, data_ov008_0218b465, var24->unknown_150_->unknown_49c_.unknown_0_0_);
            sprintf(var27, data_ov008_0218b47c, var24->unknown_150_->unknown_49c_.unknown_0_0_);
            void* var29 = ExtractFileFromGP2(var28, var27, &var26);
            if (var29 != NULL)
                func_020e046c(var25, var29, var26, (short)arg1->unknown_12_7_);
            BackgroundLoader::RemoveLockGlobal();
            int var30 = (0xa0 - func_020420e8(var25, 1)) / 2;
            if (var30 < 0)
                var30 = 0;
            func_02041a90(var17, var30, 6);
            if (var25 != NULL)
                func_02042058(var17, var25);
#endif
        }
        else
        {
            int var31;
            int var32 = 3;
            char* var33 = func_0205ec34();
            if (func_0206dfb0((int)var33, (unsigned char*)var33 + 0x8c, 0x1198))
                var32 = 4;
            for (var31 = 0; var31 < var32; var31++)
            {
                AppendXYTag_02041a90(labels, 4, i * 15 + 4);
                AppendString02042058(labels, KeyTable_Get((Container020e0310*)&self->texts_, (short)(i + 0x82)));
            }
        }
    }
    #if defined(jpn)
    func_0205d304(&arg0->unknown_130_, arg0->unknown_b8_, 0, 0, 0, 0, 0);
#else
    func_0205d304(&arg0->unknown_130_, arg0->unknown_b8_, 0, 0, 0, 0, 0, 0);
#endif
    arg0->unknown_130_.unknown_a0_ = LOW_REGION(5,3);
    arg0->unknown_130_.unknown_a2_ = 8;
    arg0->unknown_130_.unknown_a4_ = LOW_REGION(0x1a,0x1b);
    arg0->unknown_130_.unknown_a6_ = 0xf;
    arg0->unknown_130_.unknown_a8_ = 4;
    arg0->unknown_130_.unknown_aa_ = 5;
    arg0->unknown_130_.unknown_ac_ = 0xa;
    arg0->unknown_130_.unknown_ae_ = 0xe;
    arg0->unknown_130_.unknown_b7_ = 0xa;
    arg0->unknown_130_.unknown_b1_ = 5;
    arg0->unknown_130_.unknown_b5_ = 1;
    arg0->unknown_130_.unknown_b6_ = 1;
    memset(arg0->unknown_b8_, 0, LOW_REGION(0x800,0x960));
    func_ov008_02188408(arg0, arg0->unknown_b8_, 1, arg1);
    #if defined(jpn)
    func_0205d304(&arg0->unknown_130_, arg0->unknown_b8_, 0, 0, 0, 0, 0);
#else
    func_0205d304(&arg0->unknown_130_, arg0->unknown_b8_, 0, 0, 0, 0, 0, 0);
#endif
}
