#include <globaldefs.h>
#include "Resource/FontBankLoader.h"

#if defined(jpn)
#define func_ov008_021895a8 func_ov008_0218a2b0
#endif
#include <std_library_functions.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"
#include "Resource/Brightness.h"

#define REG_DISPCNT (*(volatile unsigned int*)0x04000000)
#define REG_BG0CNT (*(volatile unsigned short*)0x04000008)
#define REG_BG1CNT (*(volatile unsigned short*)0x0400000a)
#define REG_BG2CNT (*(volatile unsigned short*)0x0400000c)
#define REG_BG3CNT (*(volatile unsigned short*)0x0400000e)
#define REG_BLDCNT 0x04000050

struct Struct_02021b84
{
#if defined(jpn)
    char unknown_0_[0x28];
#else
    char unknown1_0_[0x5c];
#endif
    void* unknown_5c_;
};

struct Struct_02043368_2;
struct Struct_02020cb8_4;
struct Struct_02020aec;
struct Struct_0204b12c;
struct Struct_02020cb8_5;
struct Struct_02020cb8_2;
struct Struct_0204c7a8;
struct Struct_0205cf78;
struct Struct_0205cf78_2;
struct Struct_02043368;

struct Struct_ov003_021594c4
{
    char unknown_0_[0x1c];
    unsigned char unknown_1c_0_ : 4;
    unsigned char unknown_1c_4_ : 4;
    unsigned char unknown_1d_;
    char unknown_1e_[2];
};

struct Struct_ov006_02158478
{
    void* unknown_0_;
    Struct_ov003_021594c4* unknown_4_;
    char unknown_8_[0xe0 - 8];
};

struct Struct_02081870_2
{
    char unknown_0_[0x98];
    Struct_ov003_021594c4* unknown_98_;
    int unknown_9c_;
    char unknown_a0_[0xb2 - 0xa0];
    unsigned char unknown_b2_;
    char unknown_b3_[0xbc - 0xb3];
};

struct Struct_ov006_021580b8
{
    char unknown_0_[0x22];
    unsigned char unknown_22_;
    char unknown_23_[0x28 - 0x23];
};

struct Struct_ov008_02188d74
{
    char unknown_0_[0x3c];
    void* unknown_3c_;
    Struct_ov006_021580b8* unknown_40_;
    char unknown_44_[4];
    unsigned int unknown_48_;
    short unknown_4c_;
    unsigned short unknown_4e_;
    unsigned char unknown_50_;
    char unknown_51_[3];

    void inline_ov008_02188d74(Struct_ov006_021580b8* arg0, short arg1)
    {
        unknown_40_ = arg0;
        unknown_4c_ = arg1;
    }
};

struct Struct_ov005_0215840c_2
{
    char unknown_0_[0x49c];
    unsigned char unknown_49c_0_ : 1;
};

struct Struct_ov008_02187278
{
    char unknown_0_[0x16];
    unsigned char unknown_16_0_ : 1;
    unsigned char unknown_16_1_ : 4;
    unsigned char unknown_16_5_ : 3;
    unsigned char unknown_17_;
};

struct Struct_ov008_02188f5c_2
{
    char unknown_0_[0x38];
    Struct_ov008_02187278 unknown_38_;
};

struct Struct_ov008_021895a8
{
    unsigned char unknown_0_[2];
};

extern "C" void func_020728ac(void* arg0, SafeAllocator* arg1, void* arg2, unsigned int arg3, int, int, int);
extern "C" void func_020dfec0(void* arg0, SafeAllocator* arg1, void* arg2, unsigned int arg3);
extern "C" void func_0204b5b4(Struct_ov003_021594c4* arg0, int);
extern "C" void func_0204b174(Struct_ov003_021594c4* arg0, void* arg1, SafeAllocator* arg2, unsigned int arg3);
extern "C" void func_0204bc74(Struct_ov003_021594c4* arg0, int, int, int, int, int, int);
extern "C" void func_0205a528(Struct_ov008_02188d74* arg0, void* arg1, unsigned int arg2, SafeAllocator* arg3);
extern "C" void ColorEffect_ConfigureAlphaBlend(void* reg, int a, int b, int c, int d);
extern "C" void func_ov008_0218b240(void* arg0);
extern "C" void func_ov008_0218aa24(void* arg0);

int IsField0Null_02046b08(void** field);
unsigned int* GetDataPtr02114e04_020d6c00();
void OrBitsIntoField0_020466e4(unsigned int* field, unsigned int bits);
MessageSystem* GetGlobalField0x1c020421a0();
PartyMemberData* GetFieldAt0x150_02053c6c(unsigned char* member);
void SetWord0x18ClearByte0x1f_0204b11c(unsigned char* background, int);
void AllocateAndClearBuffer0204b12c(AllocTarget0204b12c* background, SafeAllocator* allocator);
void DispatchViaTable0204b5e8(Obj0204b5e8* background, int, int);
void FlushAndDispatchList0204b0e8(List0204b0e8* background, void*);
void AllocateBuffer0204c7a8(Obj0204c7a8* canvas, SafeAllocator* allocator, int pixels, unsigned int size);
void LinkArrayPrevPointers0205cf78(Struct_0205cf78* window, Elem_0205cf78* canvases, unsigned char count);
void Init0205a198(Struct0205a198* sprite);
void ClearField0And40205a234(ClearTarget0205a234* list);
void InitStruct0205a444(char* renderer);
int CountActiveEntries(ActiveEntry02046900* archive);
void* FindRecordByIndex(Rec020467f0* archive, int index, void** name, int* size);

extern char data_ov008_0218b4c8[];
extern char data_ov008_0218b4df[];
extern char data_ov008_0218b4f2[];
extern char data_ov008_0218b508[];
extern char data_ov008_0218b51a[];
extern char data_ov008_0218b52d[];
extern char data_ov008_0218b544[];
extern char data_ov008_0218b559[];
extern char data_ov008_0218b56a[];
extern char data_ov008_0218b57f[];
extern const unsigned char data_ov008_0218b3b8[4];

struct Struct_ov008_02188f5c_3
{
    char unknown_0_[0x10];
    unsigned char unknown_10_;
    unsigned char unknown_11_;
    unsigned int unknown_14_;
    Struct_02081870_2 unknown_18_;
    Struct_ov003_021594c4 unknown_d4_[2];
    Struct_ov006_02158478 unknown_114_;
    Struct_ov008_02188d74* unknown_1f4_;
    Struct_ov006_021580b8* unknown_1f8_;
    void* unknown_1fc_;
    SafeAllocator unknown_200_;
    SafeAllocator unknown_214_;
    SafeAllocator unknown_228_;
    SafeAllocator unknown_23c_;
    SafeAllocator unknown_250_;
    SafeAllocator unknown_264_;
    char unknown_278_[8];
    char unknown_280_[8];
    char unknown_288_[0x18];
    char* unknown_2a0_;
    void* unknown_2a4_;
#if defined(jpn)
    char unknown_2a8_[0xb44];
#else
    char unknown1_2a8_[0xb48];
#endif
    char unknown_df0_[0x2c];
    char unknown_e1c_[0x7c];
    unsigned char unknown_e98_;
    signed char unknown_e99_;
    signed char unknown_e9a_;
    signed char unknown_e9b_;
    signed char unknown_e9c_;
    int unknown_ea0_;
    int unknown_ea4_;
    int unknown_ea8_;
    int unknown_eac_;
#if !defined(jpn)
    int unknown_eb0_;
#endif
    int unknown_eb4_;
    unsigned char unknown_eb8_;
    signed char unknown_eb9_;
    unsigned char unknown_eba_;
    unsigned char unknown_ebb_;
    Struct_ov008_02188f5c_2* unknown_ebc_;
    unsigned char unknown_ec0_0_ : 1;
    unsigned char unknown_ec0_1_ : 1;
    unsigned char unknown_ec0_2_ : 1;
    unsigned char unknown_ec0_3_ : 1;
    unsigned char unknown_ec0_4_ : 4;
    void* unknown_ec4_;
    unsigned int unknown_ec8_;
};

// USA: func_ov008_021895a8
extern "C" ARM void func_ov008_021895a8(Struct_ov008_02188f5c_3* arg0)
{
    GameState* gameState = GameState::GetInstance();
    char* resources = (char*)gameState->GetResources();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    GetGlobal02109400_02094a00();
    signed char step = self->step_;
    if (step == 0)
    {
        if (!func_02046b08(*(void***)(var1
#if defined(jpn)
            + 0x34f0)))
#else
            + 0x3700)))
#endif
            return;
        SetFlags00(GetGameResources(), 0x10);
        func_020466e4(func_020d6c00(), 0xd);
        unsigned int var4;
        arg0->unknown_2a0_ = (char*)func_020421a0()->unknown_5c_;
        var4 = 0;
        Struct_ov008_02188f5c_2* var5 = arg0->unknown_ebc_;
        if (var5 == NULL)
        {
            GameObject* var6 = var0->GetPartyMemberByIndex(arg0->unknown_eb9_);
            if (var6 == NULL)
            {
                func_ov008_0218b240(arg0);
                return;
            }
            Struct_ov005_0215840c_2* var7 = func_02053c6c((unsigned char*)var6);
            if (var7 != NULL)
                var4 = var7->unknown_49c_0_;
        }
        else
        {
            var4 = var5->unknown_38_.unknown_16_0_;
        }
#if defined(jpn)
        char var8[0x40];
        sprintf(var8, data_ov008_0218b4c8, var4);
        arg0->unknown_ea0_ = var2->QueueLoadFile(data_ov008_0218b4f2, NULL);
        arg0->unknown_eb4_ = var2->QueueLoadFile(var8, NULL);
#else
        char var9[0x40];
        char var10[0x20];
        sprintf(var9, data_ov008_0218b4c8, var4);
        sprintf(var10, data_ov008_0218b4df, var4);
        arg0->unknown_ea0_ = var2->QueueLoadFileInGP2(data_ov008_0218b4f2, data_ov008_0218b508, NULL);
        arg0->unknown_eb4_ = var2->QueueLoadFileInGP2(var9, var10, NULL);
#endif
        arg0->unknown_ea4_ = var2->QueueLoadFile(data_ov008_0218b51a, NULL);
        arg0->unknown_ea8_ = var2->QueueLoadFile(data_ov008_0218b52d, NULL);
        arg0->unknown_e9a_++;
    }
    else if (var3 == 1)
    {
        if (var2->GetTaskStatus(arg0->unknown_ea0_))
        {
            void* var11;
            unsigned int var12;
            var2->GetLoadedFileByID(arg0->unknown_ea0_, &var11, &var12);
            arg0->unknown_214_.Reset();
            func_020728ac(&arg0->unknown_278_, &arg0->unknown_214_, var11, var12, 0, 0, 0);
            var2->RemoveTask(arg0->unknown_ea0_);
            arg0->unknown_ea0_ = -1;
            arg0->unknown_e9a_++;
        }
    }
    else if (var3 == 2)
    {
        if (var2->GetTaskStatus(arg0->unknown_eb4_))
        {
            void* var13;
            unsigned int var14;
            var2->GetLoadedFileByID(arg0->unknown_eb4_, &var13, &var14);
            arg0->unknown_264_.Reset();
            func_020dfec0(&arg0->unknown_288_, &arg0->unknown_264_, var13, var14);
            arg0->unknown_ec0_2_ = 1;
            var2->RemoveTask(arg0->unknown_eb4_);
            arg0->unknown_eb4_ = -1;
            arg0->unknown_200_.Reset();
            unsigned char var15[2];
            unsigned char var16[2];
            *(Struct_ov008_021895a8*)var15 = *(Struct_ov008_021895a8*)&data_ov008_0218b3b8[2];
            *(Struct_ov008_021895a8*)var16 = *(Struct_ov008_021895a8*)&data_ov008_0218b3b8[0];
            Struct_ov003_021594c4* var17;
            for (int var18 = 0; var18 < 2; var18++)
            {
                var17 = &arg0->unknown_d4_[var18];
                func_0204b11c((unsigned char*)var17, 0);
                var17->unknown_1c_0_ = 0;
                var17->unknown_1c_4_ = var15[var18];
                func_0204b5b4(var17, var16[var18]);
                func_0204b12c((Struct_0204b12c*)var17, &arg0->unknown_200_);
                func_0204b5e8((Struct_02020cb8_5*)var17, 0, 0);
            }
            REG_BG1CNT = (REG_BG1CNT & 0x43) | 0x1d00;
            REG_BG2CNT = (REG_BG2CNT & 0x43) | 0x1e00;
            ColorEffect_ConfigureAlphaBlend((void*)REG_BLDCNT, 2, 1, 10, 6);
            arg0->unknown_e9a_++;
        }
    }
    else if (var3 == 3)
    {
        if (var2->GetTaskStatus(arg0->unknown_ea4_))
        {
            char var19[4];
            void* var20;
            unsigned int var21;
            var2->GetLoadedFileByID(arg0->unknown_ea4_, &var20, &var21);
            int var22 = func_02046900((Struct_02020cb8_4*)var20);
            for (int var23 = 0; var23 < var22; var23++)
            {
                unsigned int var24;
                void* var25 = func_020467f0((Struct_02020aec*)var20, var23, (void**)var19, (int*)&var24);
                if (var25 != NULL)
                    func_0204b174(&arg0->unknown_d4_[1], var25, &arg0->unknown_200_, var24);
            }
            var2->RemoveTask(arg0->unknown_ea4_);
            arg0->unknown_ea4_ = -1;
            Struct_ov003_021594c4* var26;
            for (int var27 = 0; var27 < 2; var27++)
            {
                var26 = &arg0->unknown_d4_[var27];
                func_0204bc74(var26, 0, 0, 0, 0x20, 0x19, 0);
                func_0204b0e8((Struct_02020cb8_2*)var26, 0);
            }
            arg0->unknown_2a4_ = arg0->unknown_200_.Allocate(0x800);
            func_0204c7a8((Struct_0204c7a8*)&arg0->unknown_114_, &arg0->unknown_200_, (int)arg0->unknown_2a4_, 0x100);
            arg0->unknown_114_.unknown_4_ = &arg0->unknown_d4_[1];
            arg0->unknown_18_.unknown_98_ = &arg0->unknown_d4_[0];
            arg0->unknown_18_.unknown_b2_ = 2;
            func_0205cf78((Struct_0205cf78*)&arg0->unknown_18_, (Struct_0205cf78_2*)&arg0->unknown_114_, 1);
            for (unsigned char var28 = 0; var28 < 8; var28++)
            {
                int var29 = var28 * sizeof(Struct_ov006_021580b8);
                func_0205a198((Struct_02043368_2*)((char*)arg0->unknown_1f8_ + var29));
                ((Struct_ov006_021580b8*)((char*)arg0->unknown_1f8_ + var29))->unknown_22_ = var28 + 4;
            }
            func_0205a234((Struct_02043368*)arg0->unknown_1fc_);
            func_0205a444((char*)arg0->unknown_1f4_);
            arg0->unknown_1f4_->unknown_50_ = 0;
            Struct_ov008_02188d74* var30 = arg0->unknown_1f4_;
            var30->inline_ov008_02188d74(arg0->unknown_1f8_, 8);
            arg0->unknown_1f4_->unknown_3c_ = arg0->unknown_1fc_;
            arg0->unknown_e9a_++;
        }
    }
    else if (var3 == 4)
    {
        if (var2->GetTaskStatus(arg0->unknown_ea8_))
        {
            char var31[4];
            void* var32;
            unsigned int var33;
            var2->GetLoadedFileByID(arg0->unknown_ea8_, &var32, &var33);
            int var34 = func_02046900((Struct_02020cb8_4*)var32);
            arg0->unknown_23c_.Reset();
            for (int var35 = 0; var35 < var34; var35++)
            {
                unsigned int var36;
                func_0205a528(arg0->unknown_1f4_, func_020467f0((Struct_02020aec*)var32, var35, (void**)var31, (int*)&var36), var36, &arg0->unknown_23c_);
            }
            var2->RemoveTask(arg0->unknown_ea8_);
            arg0->unknown_ea8_ = -1;
            REG_BG0CNT = (REG_BG0CNT & ~3) | 2;
            REG_BG1CNT = (REG_BG1CNT & ~3) | 1;
            REG_BG2CNT = REG_BG2CNT & ~3;
            REG_BG3CNT = (REG_BG3CNT & ~3) | 3;
            REG_DISPCNT = (REG_DISPCNT & ~0x1f00) | 0x1700;
            func_02094b34(func_02094a00(), 0x6b, 0x206, 0, 0);
            arg0->unknown_e9a_++;
        }
    }
    else if (var3 == 5)
    {
        if (func_02094b4c(func_02094a00()))
        {
            func_ov008_0218aa24(arg0);
#if defined(jpn)
            arg0->unknown_eac_ = var2->QueueLoadFile(data_ov008_0218b544, NULL);
#else
            arg0->unknown_eac_ = var2->QueueLoadFileInGP2(data_ov008_0218b544, data_ov008_0218b559, NULL);
            arg0->unknown_eb0_ = var2->QueueLoadFileInGP2(data_ov008_0218b56a, data_ov008_0218b57f, NULL);
#endif
            arg0->unknown_e99_ = 1;
            arg0->unknown_e9a_ = 0;
        }
    }
}
