#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"
#include <std_library_functions.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "NitroSDK/Graphics.h"

struct Struct_ov003_021594c4 {
    char unknown_0_[0x1c];
    unsigned char unknown_1c_0_ : 4;
    unsigned char unknown_1c_4_ : 4;
    unsigned char unknown_1d_;
    char unknown_1e_[2];
};

struct Struct_ov009_02184e58 {
    char unknown_0_[0xc];
    void* unknown_c_;
};

struct Struct_02020cb8;
struct Struct_02020cb8_5;
struct Struct_0204b12c;
struct Struct_0204af38;
struct Struct_02020aec;
struct Struct_02020cb8_4;
struct Struct_0204b8d0;
struct Struct_02020cb8_2;
struct Struct_02020cb8_6;
struct Struct_0204af14;
struct Struct_02000c9c_8;

void ResetList0204af64(List0204af64* background);
void SetWord0x18ClearByte0x1f_0204b11c(unsigned char* background, int value);
extern "C" void func_0204b5b4(BackgroundGraphics* background, int screen);
void DispatchViaTable0204b5e8(Obj0204b5e8* background, int a, int b);
void AllocateAndClearBuffer0204b12c(AllocTarget0204b12c* background, SafeAllocator* allocator);
void AllocateArray0204af38(Foo0204af38* background, int count, SafeAllocator* allocator);
int CountActiveEntries(ActiveEntry02046900* archive);
void* FindRecordByIndex(Rec020467f0* archive, int index, void** name, int* size);
extern "C" void func_0204b174(BackgroundGraphics* background, void* file, SafeAllocator* allocator, unsigned int size);
void DispatchEntry0204b8d0(Obj0204b8d0* background, unsigned int a, int b, int c, short d, short e, short f, short g,
                           unsigned short h);
void FlushAndDispatchList0204b0e8(List0204b0e8* background, void* a);
extern "C" void func_0204bc74(BackgroundGraphics* background, int a, int b, int c, int d, int e, int f);
extern "C" int func_02001aec(const void* a, const void* b, unsigned int length);
void DispatchByTag0204b2e0(void* background, char* file);
void DispatchByTagLookup0204b3a0(SelfTag0204b3a0* background, char* file);
void* GetEntryByIndexStride0x10(EntryList0204af14* background, unsigned int index);
extern "C" void func_0204b620(BackgroundGraphics* graphics, void* a, void* b, int c, int d, int e, int f, int g, int h,
                              int i);
int NormalizeField5_0200fb08(Struct0200fb08* state);
extern "C" void func_ov023_021da274(void* self);
void RefreshFieldIfFlag4000_021d9d34(char* self);
void CharacterCreationUI_RefreshNameText(char* self);

extern const unsigned char data_ov009_0218a95d[];
extern const unsigned char data_ov009_0218a95f[];
extern const signed char data_ov009_0218a961[];
extern const unsigned char data_ov009_0218a963[];
extern const signed char data_ov009_0218a966[];
extern const signed char data_ov009_0218a969[];
extern const signed char data_ov009_0218aa54[];
extern char data_ov009_0218aca6[];
extern char data_ov009_0218acab[];

struct Struct_ov009_021842a0_2 {
    SafeAllocator unknown_0_[9];
    char unknown_b4_[0x138 - 0xb4];
    Struct_ov003_021594c4 unknown_138_[6];
    char unknown_1f8_[0xc58 - 0x1f8];
    signed char unknown_c58_;
    unsigned char unknown_c59_;
    char unknown_c5a_[0xd90 - 0xc5a];
    int unknown_d90_;
    unsigned char unknown_d94_;
    unsigned char unknown_d95_;
    char unknown_d96_[0xd9c - 0xd96];
    unsigned int unknown_d9c_;
    char unknown_da0_[0xdb6 - 0xda0];
    unsigned char unknown_db6_;
};

#if defined(jpn)
extern const unsigned char data_ov009_0218b93b[];
extern const signed char data_ov009_0218b939[];
extern const unsigned char data_ov009_0218b93d[];
extern const signed char data_ov009_0218b943[];
extern const signed char data_ov009_0218b946[];
extern const signed char data_ov009_0218ba30[];
extern char data_ov009_0218bc20[];

struct Struct_ov009_02184e58_2 {
    SafeAllocator unknown_0_[2];
    char unknown_28_[0xfc - 0x28];
    Struct_ov003_021594c4 unknown_fc_[5];
    char unknown_19c_[0xc1c - 0x19c];
    signed char unknown_c1c_;
    unsigned char unknown_c1d_;
    char unknown_c1e_[0xd54 - 0xc1e];
    int unknown_d54_;
    unsigned char unknown_d58_;
    unsigned char unknown_d59_;
    char unknown_d5a_[0xd60 - 0xd5a];
    unsigned int unknown_d60_;
    char unknown_d64_[0xd8f - 0xd64];
    unsigned char unknown_d8f_;
};

// USA: func_ov009_02184e58
extern "C" ARM void func_ov009_02184e58(Struct_ov009_02184e58_2* arg0)
{
    int var0;
    int var1;
    BackgroundLoader* var2 = BackgroundLoader::GetInstance();
    if (arg0->unknown_d58_ != 2)
        return;

    if (arg0->unknown_c1c_ == 10)
    {
        arg0->unknown_0_[0].Reset();
        Struct_ov003_021594c4* var3[] = {&arg0->unknown_fc_[0], &arg0->unknown_fc_[1], &arg0->unknown_fc_[2]};
        for (int var4 = 0; var4 < 3; var4++)
        {
            Struct_ov003_021594c4* var5 = var3[var4];
            func_0204af64((Struct_02020cb8*)var5);
            func_0204b11c((unsigned char*)var5, 0);
            var5->unknown_1c_0_ = 0;
            var5->unknown_1c_4_ = data_ov009_0218b93d[var4];
            func_0204b5b4(var5, data_ov009_0218b946[var4]);
            func_0204b5e8((Struct_02020cb8_5*)var5, 0, 0);
            func_0204b12c((Struct_0204b12c*)var5, &arg0->unknown_0_[0]);
            if (data_ov009_0218b943[var4] > 0)
                func_0204af38((Struct_0204af38*)var5, (unsigned char)data_ov009_0218b943[var4], &arg0->unknown_0_[0]);
        }
        char name[4];
        void* archive;
        unsigned int archiveSize;
        loader->GetLoadedFileByID(self->task_, &archive, &archiveSize);
        int count = CountActiveEntries((ActiveEntry02046900*)archive);
        if (self->mode_ == CreationMode_PartyMemberCreation)
            count--;
        for (int i = 0; i < count; i++)
        {
            unsigned int var11;
            void* var12 = func_020467f0((Struct_02020aec*)var7, var10, (void**)var6, (int*)&var11);
            if (var12 != NULL)
            {
                if (var10 == 2)
                {
                    func_0204b174(&arg0->unknown_fc_[1], var12, &arg0->unknown_0_[0], var11);
                    func_0204b174(&arg0->unknown_fc_[2], var12, &arg0->unknown_0_[0], var11);
                }
                else
                {
                    func_0204b174(&arg0->unknown_fc_[0], var12, &arg0->unknown_0_[0], var11);
                }
            }
        }
        var2->RemoveTask(arg0->unknown_d54_);
        arg0->unknown_d54_ = -1;
        func_0204b8d0((Struct_0204b8d0*)&arg0->unknown_fc_[0], 0, 0, 0, 0, 0, 0x20, 0x18, 0xffff);
        func_0204b0e8((Struct_02020cb8_2*)&arg0->unknown_fc_[0], 0);
        func_0204bc74(&arg0->unknown_fc_[1], 0, 0, 0, 0x20, 0x19, 0);
        func_0204b0e8((Struct_02020cb8_2*)&arg0->unknown_fc_[1], 0);
        func_0204bc74(&arg0->unknown_fc_[2], 0, 0, 0, 0x20, 0x19, 0);
        func_0204b0e8((Struct_02020cb8_2*)&arg0->unknown_fc_[2], 0);
        arg0->unknown_d60_ &= ~0x80;
        arg0->unknown_d58_ = 0;
        return;
    }

    DISPCNTSUB = (DISPCNTSUB & ~0x1f00) | 0x1500;
    arg0->unknown_0_[1].Reset();
    var0 = 0;
    Struct_ov003_021594c4* var13[] = {&arg0->unknown_fc_[3], &arg0->unknown_fc_[4]};
    for (int var14 = 0; var14 < 2; var14++)
    {
        Struct_ov003_021594c4* var15 = var13[var14];
        func_0204af64((Struct_02020cb8*)var15);
        func_0204b11c((unsigned char*)var15, 0);
        var15->unknown_1c_0_ = 1;
        var15->unknown_1c_4_ = data_ov009_0218b93b[var14];
        func_0204b5b4(var15, data_ov009_0218b939[var14]);
        func_0204b5e8((Struct_02020cb8_5*)var15, 0, 0);
        func_0204b12c((Struct_0204b12c*)var15, &arg0->unknown_0_[1]);
        unsigned char var16 = 0;
        for (int var17 = 0; data_ov009_0218ba30[var17] >= 0; var17 += 3)
        {
            if (arg0->unknown_c1c_ == data_ov009_0218ba30[var17])
            {
                var16 = data_ov009_0218ba30[var17 + var14 + 1];
                if (var14 == 0)
                    var0 = var16;
                break;
            }
        }
        if (var16 != 0)
            func_0204af38((Struct_0204af38*)var15, var16, &arg0->unknown_0_[1]);
    }

    char var18[4];
    void* var19;
    unsigned int var20;
    unsigned int var21;
    var2->GetLoadedFileByID(arg0->unknown_d54_, &var19, &var20);
    void* var22;
    int var23 = func_02046900((Struct_02020cb8_4*)var19);
    if (arg0->unknown_c1c_ == 8)
    {
        if (arg0->unknown_d8f_ != 0)
            arg0->unknown_d8f_ = 0;
        else
            arg0->unknown_d8f_ = 1;
    }
    if (self->mode_ == CreationMode_PartyMemberCreation)
        count--;
    int pairEnd = first * 2 + 1;
    firstEnd = first + 1;
    for (int i = 0; i < count; i++)
    {
        var22 = func_020467f0((Struct_02020aec*)var19, var25, (void**)var18, (int*)&var21);
        if (var22 == NULL)
            continue;
        if (arg0->unknown_c1c_ == 8)
        {
            Struct_ov003_021594c4* var26 = &arg0->unknown_fc_[4];
            if (var25 < var24)
            {
                if (self->mode_ == CreationMode_PartyMemberCreation)
                {
                    if (var25 >= var1)
                        continue;
                }
                else if (var25 < var1 && var25 != 0)
                {
                    continue;
                }
                var26 = &arg0->unknown_fc_[3];
            }
            if (arg0->unknown_d8f_ != 0)
            {
                func_0204b2e0(var26, (char*)var22);
            }
            else
            {
                char var27[5] = {};
                memcpy(var27, var22, 4);
                func_0204b3a0((Struct_02020cb8_6*)var26, (char*)var22);
                if (func_02001aec(var27, data_ov009_0218bc20, 4) == 0)
                    func_0204b174(var26, var22, &arg0->unknown_0_[1], var21);
            }
        }
        else if (var25 < var1)
        {
            func_0204b174(&arg0->unknown_fc_[3], var22, &arg0->unknown_0_[1], var21);
        }
        else
        {
            func_0204b174(&arg0->unknown_fc_[4], var22, &arg0->unknown_0_[1], var21);
        }
    }

    if (arg0->unknown_d8f_ != 0)
        return;
    loader->RemoveTask(self->task_);
    self->task_ = -1;
    int unk = 0;
    if (self->mode_ == CreationMode_NewGame && self->state_ == 1)
        unk = 1;
    DispatchEntry0204b8d0((Obj0204b8d0*)&self->backgrounds_[3], unk, 0, 0, 0, 0, 0x20, 0x18, 0xffff);
    func_0204bc74(&self->backgrounds_[4], 0, 0, 0, 0x20, 0x19, 0);
    self->flags_ |= 0x2000;
    if (self->backgrounds_[4].unk_1d != 0)
        func_ov023_021da274(self);
    self->flags_ &= ~0x2000;
    FlushAndDispatchList0204b0e8((List0204b0e8*)&self->backgrounds_[3], 0);
    FlushAndDispatchList0204b0e8((List0204b0e8*)&self->backgrounds_[4], 0);
    self->flags_ |= 0x4000;
    RefreshFieldIfFlag4000_021d9d34((char*)self);
    self->flags_ &= ~0x4000;
    self->flags_ |= 0x8000;
    CharacterCreationUI_RefreshNameText((char*)self);
    self->flags_ &= ~0x8000;
    self->flags_ &= ~0x80;
    self->loadStep_ = 0;
    DISPCNTSUB = (DISPCNTSUB & ~0x1f00) | 0x1700;
}
#else
// USA: func_ov009_02184e58
extern "C" ARM void func_ov009_02184e58(Struct_ov009_021842a0_2* arg0)
{
    int var29;
    BackgroundLoader* var30 = BackgroundLoader::GetInstance();
    int var31;
    int var32;
    signed char var33 = arg0->unknown_c58_;
    if (arg0->unknown_d94_ != 2)
        return;

    if (var33 == 10)
    {
        arg0->unknown_0_[0].Reset();
        Struct_ov003_021594c4* var34[] = {&arg0->unknown_138_[0], &arg0->unknown_138_[1], &arg0->unknown_138_[2]};
        for (int var35 = 0; var35 < 3; var35++)
        {
            Struct_ov003_021594c4* var36 = var34[var35];
            func_0204af64((Struct_02020cb8*)var36);
            func_0204b11c((unsigned char*)var36, 0);
            var36->unknown_1c_0_ = 0;
            var36->unknown_1c_4_ = data_ov009_0218a963[var35];
            func_0204b5b4(var36, data_ov009_0218a969[var35]);
            func_0204b5e8((Struct_02020cb8_5*)var36, 0, 0);
            func_0204b12c((Struct_0204b12c*)var36, &arg0->unknown_0_[0]);
            if (data_ov009_0218a966[var35] > 0)
                func_0204af38((Struct_0204af38*)var36, (unsigned char)data_ov009_0218a966[var35], &arg0->unknown_0_[0]);
        }
        char name[4];
        void* archive;
        unsigned int archiveSize;
        loader->GetLoadedFileByID(self->task_, &archive, &archiveSize);
        int count = CountActiveEntries((ActiveEntry02046900*)archive);
        if (self->mode_ == CreationMode_PartyMemberCreation)
            count--;
        for (int i = 0; i < count; i++)
        {
            unsigned int var42;
            void* var43 = func_020467f0((Struct_02020aec*)var38, var41, (void**)var37, (int*)&var42);
            if (var43 != NULL)
            {
                if (var41 == 2)
                {
                    func_0204b174(&arg0->unknown_138_[1], var43, &arg0->unknown_0_[0], var42);
                    func_0204b174(&arg0->unknown_138_[2], var43, &arg0->unknown_0_[0], var42);
                }
                else
                {
                    func_0204b174(&arg0->unknown_138_[0], var43, &arg0->unknown_0_[0], var42);
                }
            }
        }
        var30->RemoveTask(arg0->unknown_d90_);
        arg0->unknown_d90_ = -1;
        func_0204b8d0((Struct_0204b8d0*)&arg0->unknown_138_[0], 0, 0, 0, 0, 0, 0x20, 0x18, 0xffff);
        func_0204b0e8((Struct_02020cb8_2*)&arg0->unknown_138_[0], 0);
        func_0204bc74(&arg0->unknown_138_[1], 0, 0, 0, 0x20, 0x19, 0);
        func_0204b0e8((Struct_02020cb8_2*)&arg0->unknown_138_[1], 0);
        func_0204bc74(&arg0->unknown_138_[2], 0, 0, 0, 0x20, 0x19, 0);
        func_0204b0e8((Struct_02020cb8_2*)&arg0->unknown_138_[2], 0);
        arg0->unknown_d9c_ &= ~0x80;
        arg0->unknown_d94_ = 0;
        return;
    }

    DISPCNTSUB = (DISPCNTSUB & ~0x1f00) | 0x1500;
    arg0->unknown_0_[1].Reset();
    var31 = 0;
    Struct_ov003_021594c4* var44[] = {&arg0->unknown_138_[3], &arg0->unknown_138_[4]};
    for (int var45 = 0; var45 < 2; var45++)
    {
        Struct_ov003_021594c4* var46 = var44[var45];
        func_0204af64((Struct_02020cb8*)var46);
        func_0204b11c((unsigned char*)var46, 0);
        var46->unknown_1c_0_ = 1;
        var46->unknown_1c_4_ = data_ov009_0218a95f[var45];
        func_0204b5b4(var46, data_ov009_0218a961[var45]);
        func_0204b5e8((Struct_02020cb8_5*)var46, 0, 0);
        func_0204b12c((Struct_0204b12c*)var46, &arg0->unknown_0_[1]);
        unsigned char var47 = 0;
        for (int var48 = 0; data_ov009_0218aa54[var48] >= 0; var48 += 3)
        {
            if (var33 == data_ov009_0218aa54[var48])
            {
                var47 = data_ov009_0218aa54[var48 + var45 + 1];
                if (var45 == 0)
                    var31 = var47;
                break;
            }
        }
        if (var47 != 0)
            func_0204af38((Struct_0204af38*)var46, var47, &arg0->unknown_0_[1]);
    }

    char var49[4];
    void* var50;
    unsigned int var51;
    unsigned int var52;
    var30->GetLoadedFileByID(arg0->unknown_d90_, &var50, &var51);
    int var53 = func_02046900((Struct_02020cb8_4*)var50);
    if (var33 == 8)
        arg0->unknown_db6_ = arg0->unknown_db6_ == 0 ? 1 : 0;
    unsigned char var54 = 0;
    var32 = var53 - 1;
    var29 = var31 + 1;
    void* var55;
    for (int var56 = 0; var56 < var53; var56++)
    {
        var55 = func_020467f0((Struct_02020aec*)var50, var56, (void**)var49, (int*)&var52);
        if (var55 == NULL)
            continue;
        char var57[5] = {};
        memcpy(var57, var55, 4);
        if (func_02001aec(var57, data_ov009_0218aca6, 4) == 0 && data_ov009_0218a95d[var54++] == arg0->unknown_d95_)
            continue;
        if (var33 == 8)
        {
            Struct_ov003_021594c4* var58 = &arg0->unknown_138_[4];
            if (var56 < var31)
                var58 = &arg0->unknown_138_[3];
            if (var56 == var32)
                var58 = &arg0->unknown_138_[3];
            if (arg0->unknown_db6_ != 0)
            {
                if (var56 != var32)
                    func_0204b2e0(var58, (char*)var55);
            }
            else
            {
                if (var56 != var32)
                    func_0204b3a0((Struct_02020cb8_6*)var58, (char*)var55);
                if (func_02001aec(var57, data_ov009_0218acab, 4) == 0)
                    func_0204b174(var58, var55, &arg0->unknown_0_[1], var52);
            }
        }
        else if (var56 < var29)
        {
            func_0204b174(&arg0->unknown_138_[3], var55, &arg0->unknown_0_[1], var52);
        }
        else
        {
            func_0204b174(&arg0->unknown_138_[4], var55, &arg0->unknown_0_[1], var52);
        }
    }

    if (arg0->unknown_db6_ != 0)
        return;
    loader->RemoveTask(self->task_);
    self->task_ = -1;
    int unk = 0;
    if (self->mode_ == CreationMode_NewGame && state == 1)
        unk = 1;
    if (state == 8 && self->mode_ == CreationMode_PartyMemberCreation)
    {
        void* var60 = func_0204af14((Struct_0204af14*)&arg0->unknown_138_[3], 4);
        for (int var61 = 0; var61 < 4; var61++)
        {
            Struct_ov009_02184e58* var62 = (Struct_ov009_02184e58*)func_0204af14((Struct_0204af14*)&arg0->unknown_138_[3], (unsigned char)var61);
            Struct_ov003_021594c4 var63;
            func_0204af64((Struct_02020cb8*)&var63);
            func_0204b620(&var63, var62->unknown_c_, var60, 0, 0, 0x13, 0x11, 4, 2, 1);
        }
    }
    func_0204b8d0((Struct_0204b8d0*)&arg0->unknown_138_[3], var59, 0, 0, 0, 0, 0x20, 0x18, 0xffff);
    if (arg0->unknown_138_[3].unknown_1d_ == 5)
    {
        int var64 = func_0200fb08((Struct_02000c9c_8*)GameState::GetInstance());
        int var65 = 0;
        switch (var64)
        {
        case 2:
            var65 = 1;
            break;
        case 4:
            var65 = 2;
            break;
        case 3:
            var65 = 3;
            break;
        case 5:
            var65 = 4;
            break;
        }
        if (var65 != 0)
            func_0204b8d0((Struct_0204b8d0*)&arg0->unknown_138_[3], var65, 0, 0, 1, 1, 0xd, 3, 0xffff);
    }
    func_0204bc74(&self->backgrounds_[4], 0, 0, 0, 0x20, 0x19, 0);
    self->flags_ |= 0x2000;
    if (self->backgrounds_[4].unk_1d != 0)
        func_ov023_021da274(self);
    self->flags_ &= ~0x2000;
    FlushAndDispatchList0204b0e8((List0204b0e8*)&self->backgrounds_[3], 0);
    FlushAndDispatchList0204b0e8((List0204b0e8*)&self->backgrounds_[4], 0);
    self->flags_ |= 0x4000;
    RefreshFieldIfFlag4000_021d9d34((char*)self);
    self->flags_ &= ~0x4000;
    self->flags_ |= 0x8000;
    CharacterCreationUI_RefreshNameText((char*)self);
    self->flags_ &= ~0x8000;
    self->flags_ &= ~0x80;
    self->loadStep_ = 0;
    DISPCNTSUB = (DISPCNTSUB & ~0x1f00) | 0x1700;
}
#endif
