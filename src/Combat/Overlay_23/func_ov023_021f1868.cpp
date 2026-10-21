#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include <std_library_functions.h>
#include <Filesystem/BackgroundLoader.h>
#include <Memory/SafeAllocator.h>

struct GameResources;
struct Struct_02048150;
struct Struct_02072a68_2 { char unknown_0_[4]; };
struct Struct_0200f3a4_8;
struct Struct_0209a470;
struct Struct_02013fb4;
struct Struct_020727d8;
struct Struct_02046574_2;
struct Struct_020465c0;
struct Struct_0209fee4;
struct Struct_0209ff64;
struct Struct_0209ff6c;
struct Struct_ov023_021f1868_10;
struct Struct_020a13c4;
struct Struct_020a15bc;
struct Struct_0201099c_14;
struct Struct_0201099c_3;
struct Struct_ov023_021f1868_11;
struct Struct_ov023_021eeaac_2;

struct Struct_ov023_021f1868_12 {
    unsigned char unknown_0_0_ : 1;
};

struct Struct_ov023_021f1868_13 {
    char unknown_0_[0x49c];
    Struct_ov023_021f1868_12 unknown_49c_;
};

struct Struct_ov023_021f1868_14 {
#if defined(jpn)
    char unknown_0_[0x144];
#else
    char unknown1_0_[0x150];
#endif
    Struct_ov023_021f1868_13* unknown_150_;
};

struct GameState {
    static GameState* GetInstance();
    GameResources* GetResources();
    GameObject_021f1868* GetProtagonist();
};

struct Struct_ov023_021f1868 {
    char unknown_0_[0x134];
    char* unknown_134_;
};

struct Struct_ov023_021f1868_2 {
    unsigned short unknown_0_0_ : 11;
    unsigned short unknown_1_3_ : 5;
    short unknown_2_;
    unsigned int unknown_4_0_ : 5;
    unsigned int unknown_4_5_ : 7;
    unsigned int unknown_5_4_ : 8;
    unsigned int unknown_6_4_ : 5;
    unsigned int unknown_7_1_ : 7;
};

struct Struct_ov023_021f1868_3 {
#if defined(jpn)
    char unknown_0_[0x868];
    int unknown_868_;
    char unknown_86c_[0x17e2 - 0x86c];
    unsigned char unknown_17e2_;
    char unknown_17e3_[0x17fb - 0x17e3];
    unsigned char unknown_17fb_;
#else
    char* unknown1_0_;
    char unknown_4_[4];
    void* unknown_8_;
    char unknown_c_[0x998 - 0xc];
    int unknown_998_;
    char unknown_99c_[0x19b2 - 0x99c];
    unsigned char unknown_19b2_;
    char unknown_19b3_[0x19ca - 0x19b3];
    unsigned char unknown_19ca_;
#endif
};

struct Struct_ov023_021f1868_4 {
    char unknown_0_[0x68];
    short unknown_68_;
    short unknown_6a_[1];
};

struct Struct_ov023_021f1868_5 {
#if defined(jpn)
    char unknown_0_[0x15c];
#else
    char unknown1_0_[0x244];
#endif
};

struct Struct_ov023_021f1868_6 {
    char unknown_0_[0x438];
    unsigned short unknown_438_;
};

struct Struct_ov023_021f1868_7 {
    char unknown_0_[0x18];
};

struct Struct_ov023_021f1868_8 {
    int unknown_0_;
    int unknown_4_;
    char unknown_8_[0x18 - 0x8];
    int unknown_18_;
    char unknown_1c_[0x74 - 0x1c];
#if defined(jpn)
    short unknown_74_[55];
#else
    unsigned short unknown1_74_[55];
#endif
    unsigned char unknown_e2_;
    unsigned char unknown_e3_;
};

struct Struct_ov023_021f1868_9 {
    char unknown_0_[0x30];
    SafeAllocator unknown_30_;
#if defined(jpn)
    char unknown_44_[0xe28 - 0x44];
    int unknown_eac_;
    char unknown_e2c_[0x371c - 0xe2c];
    char unknown_371c_[0x1bf8];
    SafeAllocator unknown_5314_;
    char unknown_5328_[0x5770 - 0x5328];
    Struct_02072a68_2* unknown_5770_;
    char unknown_5774_[0x57b4 - 0x5774];
    Struct_ov023_021f1868_4* unknown_57b4_;
    void* unknown_57b8_;
    Struct_ov023_021f1868_6* unknown_55cc_;
    Struct_ov023_021f1868_5* unknown_55d0_;
    unsigned char unknown_55d4_;
    unsigned char unknown_55d5_;
    char unknown_57c6_[0x5af4 - 0x57c6];
    Struct_02072a68_2 unknown_5af4_;
    char unknown_5af8_[0x79c1 - 0x5af8];
    unsigned char unknown_77d1_;
#else
    char unknown1_44_[0xe98 - 0x44];
    char unknown_e98_[0xeac - 0xe98];
    int unknown_eac_;
    char unknown_eb0_[0x3760 - 0xeb0];
    char unknown_3760_[0x1af8];
    SafeAllocator unknown_5258_;
    char unknown_526c_[0x557c - 0x526c];
    Struct_02072a68_2* unknown_557c_;
    void* unknown_5580_;
    char unknown_5584_[0x55c4 - 0x5584];
    Struct_ov023_021f1868_4* unknown_55c4_;
    void* unknown_55c8_;
    Struct_ov023_021f1868_6* unknown_55cc_;
    Struct_ov023_021f1868_5* unknown_55d0_;
    unsigned char unknown_55d4_;
    unsigned char unknown_55d5_;
    char unknown_55d6_[0x5904 - 0x55d6];
    Struct_02072a68_2 unknown_5904_;
    char unknown_5908_[0x77d1 - 0x5908];
    unsigned char unknown_77d1_;
#endif
};

extern "C" Struct_ov023_021f1868_8* _ZZ21inline_ov023_021f4c04vE1s;
extern const char data_ov023_021fe200[];
extern const char data_ov023_021fe25e[];
extern const char data_ov023_021fe273[];
extern const char data_ov023_021fe284[];
extern const char data_ov023_021fe2a0[];
extern const char data_ov023_021fe2b7[];
extern unsigned char data_0211e33c[0x30000] __attribute__((aligned(4)));
#if defined(jpn)
extern const char data_ov023_021fd517[];
extern const char data_ov023_021fd533[];
extern "C" void func_02073864(Struct_02072a68_2* arg0, SafeAllocator* arg1, const char* arg2, int arg3, int arg4, int arg5);
extern "C" void func_020e1fc4(Struct_ov023_021f1868_7* arg0, SafeAllocator* arg1, const char* arg2, short* arg3, unsigned short arg4, int arg5, int arg6);
#endif

extern "C" Struct_ov023_021f1868_3* func_020421a0();
extern "C" Struct_02048150* func_02010828(GameState* arg0);
extern "C" int func_02086ef0(Struct_02048150* arg0, int arg1);
void* LoadFileIntoMemory(const char* path, void* buffer, unsigned int* outLength);
void ClearFirstTwoWords0209a338(Pair0209a338* p);
void SetupAndRunBufferedScript0209a470(Ctx0209a470* ctx, SafeAllocator* allocator, StreamHeader* file, int size);
char* FindEntryByKey_02072a68(TableA68* table, int key);
void ResetListHeader020727d8(List020727d8* list);
void Zero4Bytes_020e526c(void* p);
void Reset0209fe9c(char* titles);
void InitManagerAndAllocateBuffers0209fee4(Obj0209fee4* titles, SafeAllocator* allocator, int file, int size);
void SetIntAt0x60(IntField0x60_0209ff64* titles, int value);
void PollOv017Task0209ff6c(TaskState0209ff6c* titles);
int AreFields60And64AllOnes_021f21f4(Fields60_021f21f4* titles);
Member_021f1868* GetCombatantWithFlag0x100_0200ff1c(GameState* gameState, int id);
int AppendString02042058(char* dst, const char* src);
void SetIndexedName02046574(Obj02046574* obj, int index, char* str);
void InitObjFromCombatantId020e4bf4(void* obj, int id);
void** CallFunc020e52a0_020e5294(void* p, int key);
void StoreInArray0x8b0_020465c0(StoreStruct* base, int index, int value);
void ReinitController02043204(char* messages);
void ClearStruct020a13c4(S020a13c4* table);
void SetupGlobalAndRunScript020a13e4(void* table, void* allocator, int ids, unsigned short count, unsigned char mode);
void* ResetAndReturnSelf020dfc2c(void* texts);
void ResetStruct020dfc40(Struct020dfc40* texts);
void* FindElementByField020a15bc(Array020a15bc* table, int id);
const char* GetFieldByKey020e0434(Container020e0310* texts, int id);
void InitObj_021f222c(Obj_021f222c* page);
void FormatLabelIntoBufC_021f2304(void* page, char* title);
void SetOrClearBit10At400_38_021f2348(void* guide, int value);
void SetMainBrightness(GameResources* resources, int brightness, int duration);
int IsBrightnessTransitionActive(GameResources* resources);
extern "C" void func_ov023_021eefac(Struct_ov023_021eeaac_2* arg0);

extern "C" {
void __clear(void* arg0, unsigned long arg1);
void* ExtractFileFromGP2(const char* arg0, const char* arg1, unsigned int* arg2);
void func_020728ac(void* arg0, void* arg1, void* arg2, int arg3, int arg4, int arg5, int arg6);
void func_020e5604(void* arg0, SafeAllocator* arg1, void* arg2, int arg3);
Struct_ov023_021f1868_2* func_0209a594(void* arg0, int arg1);
void func_02046380(Struct_ov023_021f1868_3* arg0);
void func_020e4864(void* arg0, char* arg1, int arg2, int arg3, int arg4, int arg5);
#if defined(jpn)
void func_0204500c(Struct_ov023_021f1868_3* arg0, char* arg1, int arg2);
#else
void func_0204500c(Struct_ov023_021f1868_3* arg0, char* arg1, int arg2, int arg3);
#endif
int func_ov023_021f4fc8();
int func_ov023_021ed724(void* arg0, short* arg1, int arg2);
void func_020e0028(Struct_ov023_021f1868_7* arg0, SafeAllocator* arg1, void* arg2, unsigned int arg3, short* arg4, unsigned short arg5);
void func_ov023_021f229c(Struct_ov023_021f1868_5* arg0, void* arg1);
void func_ov023_021eb138(Struct_ov023_021f1868_6* arg0, int arg1);
void func_ov023_021eb080(Struct_ov023_021f1868_6* arg0, SafeAllocator* arg1);
void func_ov023_021eb564(Struct_ov023_021f1868_6* arg0, Struct_ov023_021f1868_5* arg1, int arg2);
void func_ov023_021eb26c(Struct_ov023_021f1868_6* arg0);
}

static inline int inline_ov023_021f1868(Struct_ov023_021f1868_6* arg0) { return (arg0->unknown_438_ & 4) ? 1 : 0; }

// USA: func_ov023_021f1868
extern "C" ARM int func_ov023_021f1868(Struct_ov023_021f1868_9* arg0)
{
#if defined(jpn)
    GameState* var19 = GameState::GetInstance();
    Struct_ov023_021f1868_8* var20 = _ZZ21inline_ov023_021f4c04vE1s;
    Struct_ov023_021f1868_3* var0 = func_020421a0();
    BackgroundLoader* var1 = BackgroundLoader::GetInstance();
    int var2 = var20->unknown_18_;
    int var3 = func_02086ef0(func_02010828(var19), var2);
    if (var20->unknown_0_ == 0)
    {
        arg0->unknown_77d1_ = 1;
        arg0->unknown_30_.Reset();
        arg0->unknown_5770_ = (Struct_02072a68_2*)arg0->unknown_30_.Allocate(8);
        func_020727d8((Struct_020727d8*)arg0->unknown_5770_);
        func_02073864(arg0->unknown_5770_, &arg0->unknown_30_, func_02072a68(&arg0->unknown_5af4_, 0x21), 0, 0, 0);
        arg0->unknown_57b4_ = NULL;
        var20->unknown_4_ = var1->QueueLoadFile(data_ov023_021fd517, NULL);
        var20->unknown_0_++;
    }
    if (var20->unknown_0_ == 1)
    {
        if (var1->GetTaskStatus(var20->unknown_4_))
        {
            unsigned int var4;
            void* var5;
            var1->GetLoadedFileByID(var20->unknown_4_, &var5, &var4);
            arg0->unknown_57b4_ = (Struct_ov023_021f1868_4*)arg0->unknown_30_.Allocate(0xd0);
            func_0209fe9c((char*)arg0->unknown_57b4_);
            func_0209fee4((Struct_0209fee4*)arg0->unknown_57b4_, &arg0->unknown_30_, (int)var5, var4);
            func_0209ff64((Struct_0209ff64*)arg0->unknown_57b4_, 100);
            do
            {
                func_0209ff6c((Struct_0209ff6c*)arg0->unknown_57b4_);
            } while (!func_ov023_021f21f4((Struct_ov023_021f1868_10*)arg0->unknown_57b4_));
            var1->RemoveTask(var20->unknown_4_);
            var20->unknown_4_ = -1;
            var20->unknown_0_++;
        }
    }
    else if (var20->unknown_0_ == 2)
    {
        while (var20->unknown_e3_ < var20->unknown_e2_)
        {
            char* var6 = func_02072a68(arg0->unknown_5770_, var20->unknown_74_[var20->unknown_e3_]);
            if (var6 != NULL)
            {
                Struct_ov023_021f1868* var7 = func_0200ff1c(var19, var2);
                if (var7 != NULL)
                {
                    char var8[0x80];
                    __clear(var8, sizeof(var8));
                    func_02042058(var8, var6);
                    func_02042058(var8, func_02072a68(&arg0->unknown_5af4_, 0x22));
                    func_02046380(var0);
                    func_02046574((Struct_02046574_2*)var0, 0, var7->unknown_134_);
                    if (var3)
                    {
                        func_0204500c(var0, var8, 1);
                        var0->unknown_17e2_ = 0;
                        var0->unknown_868_ = 1;
                    }
                    var20->unknown_e3_++;
                    var20->unknown_0_++;
                    return arg0->unknown_eac_;
                }
            }
            var20->unknown_e3_++;
        }
        var20->unknown_0_ = 4;
    }
    else if (var20->unknown_0_ == 3)
    {
        if (var20->unknown_e2_ <= var20->unknown_e3_)
        {
            if (arg0->unknown_57b4_->unknown_68_ > 0)
                var0->unknown_17fb_ = 0;
        }
        if (func_ov023_021f4fc8())
        {
            if (var20->unknown_e2_ <= var20->unknown_e3_)
                var20->unknown_0_++;
            else
                var20->unknown_0_ = 2;
        }
    }
    else if (var20->unknown_0_ == 4)
    {
        short* var9;
        int var10;
        int var11 = arg0->unknown_57b4_->unknown_68_;
        if (var11 > 0)
        {
            func_02043204((char*)var0);
            SafeAllocator* var12 = &arg0->unknown_5314_;
            var12->Reset();
            var11 = arg0->unknown_57b4_->unknown_68_;
            var9 = (short*)var12->Allocate(var11 * 2);
            for (int var13 = 0; var13 < var11; var13++)
                var9[var13] = arg0->unknown_57b4_->unknown_6a_[var13];
            arg0->unknown_30_.Reset();
            arg0->unknown_5770_ = NULL;
            arg0->unknown_57b4_ = NULL;
            arg0->unknown_57b8_ = arg0->unknown_30_.Allocate(0x14);
            func_020a13c4((Struct_020a13c4*)arg0->unknown_57b8_);
            func_020a13e4(arg0->unknown_57b8_, &arg0->unknown_30_, (int)var9, (unsigned short)var11, 4);
            arg0->unknown_55d5_ = func_ov023_021ed724(arg0->unknown_57b8_, var9, var11) & 1 ? 1 : 0;
            Struct_ov023_021f1868_14* var14 = var19->GetProtagonist();
            Struct_ov023_021f1868_7 var15;
            func_020dfc2c(&var15);
            func_020dfc40((Struct_0201099c_14*)&var15);
            func_020e1fc4(&var15, &arg0->unknown_30_, data_ov023_021fd533, var9, (unsigned short)var11, var14->unknown_150_->unknown_49c_.unknown_0_0_, 1);
            arg0->unknown_55d0_ = (Struct_ov023_021f1868_5*)arg0->unknown_30_.Allocate(var11 * sizeof(Struct_ov023_021f1868_5));
            for (var10 = 0; var10 < var11; var10++)
            {
                void* var16 = func_020a15bc((Struct_020a15bc*)arg0->unknown_57b8_, var9[var10]);
                if (var16 == NULL)
                    continue;
                const char* var17 = func_020e0434((Struct_0201099c_3*)&var15, var9[var10]);
                if (var17 == NULL)
                    continue;
                func_ov023_021f222c((Struct_ov023_021f1868_11*)&arg0->unknown_55d0_[var10]);
                func_ov023_021f229c(&arg0->unknown_55d0_[var10], var16);
                func_ov023_021f2304(&arg0->unknown_55d0_[var10], (char*)var17);
            }
            arg0->unknown_57b8_ = NULL;
            arg0->unknown_55d4_ = var11;
            var12->Reset();
            var20->unknown_0_++;
        }
        else if (var11 == 0)
        {
            arg0->unknown_30_.Reset();
            arg0->unknown_5770_ = NULL;
            arg0->unknown_57b4_ = NULL;
            arg0->unknown_77d1_ = 0;
            Struct_0208cb08* var18 = func_02094a00();
            func_02094b40(var18);
            func_02094b34(var18, 0x65, 500, 0, 0);
            var20->unknown_0_ = 8;
        }
    }
#else
    GameState* var19 = GameState::GetInstance();
    Struct_ov023_021f1868_8* var20 = _ZZ21inline_ov023_021f4c04vE1s;
    Struct_ov023_021f1868_3* var21 = func_020421a0();
    BackgroundLoader* var22 = BackgroundLoader::GetInstance();
    int var23 = var20->unknown_18_;
    int var24 = func_02086ef0(func_02010828(var19), var23);
    if (var20->unknown_0_ == 0)
    {
        arg0->unknown_77d1_ = 1;
        BackgroundLoader::AddLockGlobal();
        BackgroundLoader::FreeAllocationsGlobal();
        arg0->unknown_30_.Reset();
        unsigned int var25;
        void* var26 = LoadFileIntoMemory(data_ov023_021fe200, data_0211e33c, &var25);
        func_0209a338((Struct_0200f3a4_8*)arg0->unknown_e98_);
        if (var26 != NULL)
            func_0209a470((Struct_0209a470*)arg0->unknown_e98_, &arg0->unknown_30_, (Struct_02013fb4*)var26, var25);
        var26 = ExtractFileFromGP2(func_02072a68(&arg0->unknown_5904_, 0x2b), func_02072a68(&arg0->unknown_5904_, 0x21), &var25);
        arg0->unknown_557c_ = (Struct_02072a68_2*)arg0->unknown_30_.Allocate(8);
        func_020727d8((Struct_020727d8*)arg0->unknown_557c_);
        if (var26 != NULL)
            func_020728ac(arg0->unknown_557c_, &arg0->unknown_30_, var26, var25, 0, 0, 0);
        var26 = ExtractFileFromGP2(data_ov023_021fe25e, data_ov023_021fe273, &var25);
        arg0->unknown_5580_ = arg0->unknown_30_.Allocate(0xc);
        func_020e526c(arg0->unknown_5580_);
        if (var26 != NULL)
            func_020e5604(arg0->unknown_5580_, &arg0->unknown_30_, var26, var25);
        BackgroundLoader::RemoveLockGlobal();
        arg0->unknown_55c4_ = NULL;
        var20->unknown_4_ = var22->QueueLoadFile(data_ov023_021fe284, NULL);
        var20->unknown_0_++;
    }
    if (var20->unknown_0_ == 1)
    {
        if (var22->GetTaskStatus(var20->unknown_4_))
        {
            unsigned int var27;
            void* var28;
            var22->GetLoadedFileByID(var20->unknown_4_, &var28, &var27);
            arg0->unknown_55c4_ = (Struct_ov023_021f1868_4*)arg0->unknown_30_.Allocate(0xd0);
            func_0209fe9c((char*)arg0->unknown_55c4_);
            func_0209fee4((Struct_0209fee4*)arg0->unknown_55c4_, &arg0->unknown_30_, (int)var28, var27);
            func_0209ff64((Struct_0209ff64*)arg0->unknown_55c4_, 100);
            do
            {
                func_0209ff6c((Struct_0209ff6c*)arg0->unknown_55c4_);
            } while (!func_ov023_021f21f4((Struct_ov023_021f1868_10*)arg0->unknown_55c4_));
            var22->RemoveTask(var20->unknown_4_);
            var20->unknown_4_ = -1;
            var20->unknown_0_++;
        }
    }
    else if (var20->unknown_0_ == 2)
    {
        while (var20->unknown_e3_ < var20->unknown_e2_)
        {
            Struct_ov023_021f1868_2* var29 = func_0209a594(arg0->unknown_e98_, var20->unknown1_74_[var20->unknown_e3_]);
            char* var30 = NULL;
            if (var29 != NULL)
                var30 = func_02072a68(arg0->unknown_557c_, var29->unknown_6_4_);
            if (var30 != NULL)
            {
                Struct_ov023_021f1868* var31 = func_0200ff1c(GameState::GetInstance(), var23);
                if (var31 != NULL)
                {
                    char var32[0x200];
                    char var33[12];
                    char var34[0x80];
                    __clear(var32, sizeof(var32));
                    func_02042058(var32, var30);
                    func_02042058(var32, func_02072a68(&arg0->unknown_5904_, 0x22));
                    func_02046380(var21);
                    func_02046574((Struct_02046574_2*)var21, 0, var31->unknown_134_);
                    func_020e4bf4(var33, var23);
                    var21->unknown1_0_ = var33;
                    if (var29->unknown_6_4_ == 1)
                    {
                        void** var35 = func_020e5294(arg0->unknown_5580_, var29->unknown_2_);
                        var21->unknown_8_ = var35;
                        __clear(var34, sizeof(var34));
                        func_020e4864(*var35, var34, 1, 0, 0, 0);
                        func_02046574((Struct_02046574_2*)var21, 1, var34);
                    }
                    else
                    {
                        func_02046574((Struct_02046574_2*)var21, 1, func_02072a68(arg0->unknown_557c_, (short)(var29->unknown_4_0_ + 100)));
                    }
                    int var36 = 2;
                    if (var29->unknown_6_4_ == 4 || var29->unknown_6_4_ == 0x10)
                        var36 = 1;
                    func_02046574((Struct_02046574_2*)var21, var36, func_02072a68(arg0->unknown_557c_, (short)(var29->unknown_1_3_ + 200)));
                    func_020465c0((Struct_020465c0*)var21, 0, var29->unknown_5_4_);
                    if (var24)
                    {
                        func_0204500c(var21, var32, 1, 0xe3);
                        var21->unknown_19b2_ = 0;
                        var21->unknown_998_ = 1;
                    }
                    var20->unknown_e3_++;
                    var20->unknown_0_++;
                    return arg0->unknown_eac_;
                }
            }
            var20->unknown_e3_++;
        }
        var20->unknown_0_ = 4;
    }
    else if (var20->unknown_0_ == 3)
    {
        if (var20->unknown_e2_ <= var20->unknown_e3_)
        {
            if (arg0->unknown_55c4_->unknown_68_ > 0)
                var21->unknown_19ca_ = 0;
        }
        if (func_ov023_021f4fc8())
        {
            if (var20->unknown_e2_ <= var20->unknown_e3_)
                var20->unknown_0_++;
            else
                var20->unknown_0_ = 2;
        }
    }
    else if (var20->unknown_0_ == 4)
    {
        int var37 = arg0->unknown_55c4_->unknown_68_;
        if (var37 > 0)
        {
            func_02043204((char*)var21);
            char* var38 = arg0->unknown_3760_; SafeAllocator* var39 = (SafeAllocator*)(var38 + 0x1af8);
            var39->Reset();
            var37 = arg0->unknown_55c4_->unknown_68_;
            short* var40 = (short*)var39->Allocate(var37 * 2);
            for (int var41 = 0; var41 < var37; var41++)
                var40[var41] = arg0->unknown_55c4_->unknown_6a_[var41];
            arg0->unknown_30_.Reset();
            arg0->unknown_557c_ = NULL;
            arg0->unknown_5580_ = NULL;
            arg0->unknown_55c4_ = NULL;
            arg0->unknown_55c8_ = arg0->unknown_30_.Allocate(0x14);
            func_020a13c4((Struct_020a13c4*)arg0->unknown_55c8_);
            func_020a13e4(arg0->unknown_55c8_, &arg0->unknown_30_, (int)var40, (unsigned short)var37, 4);
            arg0->unknown_55d5_ = func_ov023_021ed724(arg0->unknown_55c8_, var40, var37) & 1 ? 1 : 0;
            Struct_ov023_021f1868_14* var42 = var19->GetProtagonist();
            Struct_ov023_021f1868_7 var43;
            func_020dfc2c(&var43);
            func_020dfc40((Struct_0201099c_14*)&var43);
            BackgroundLoader::AddLockGlobal();
            unsigned int var44 = 0;
            char var45[0x40];
            __clear(var45, sizeof(var45));
            char var46[0x20];
            __clear(var46, sizeof(var46));
            Struct_ov023_021f1868_13* var47 = var42->unknown_150_;
            sprintf(var45, data_ov023_021fe2a0, var47->unknown_49c_.unknown_0_0_);
            sprintf(var46, data_ov023_021fe2b7, var42->unknown_150_->unknown_49c_.unknown_0_0_);
            void* var48 = ExtractFileFromGP2(var45, var46, &var44);
            if (var48 != NULL)
                func_020e0028(&var43, &arg0->unknown_30_, var48, var44, var40, (unsigned short)var37);
            BackgroundLoader::RemoveLockGlobal();
            arg0->unknown_55d0_ = (Struct_ov023_021f1868_5*)arg0->unknown_30_.Allocate(var37 * sizeof(Struct_ov023_021f1868_5));
            for (int var49 = 0; var49 < var37; var49++)
            {
                void* var50 = func_020a15bc((Struct_020a15bc*)arg0->unknown_55c8_, var40[var49]);
                if (var50 == NULL)
                    continue;
                const char* var51 = func_020e0434((Struct_0201099c_3*)&var43, var40[var49]);
                if (var51 == NULL)
                    continue;
                func_ov023_021f222c((Struct_ov023_021f1868_11*)&arg0->unknown_55d0_[var49]);
                func_ov023_021f229c(&arg0->unknown_55d0_[var49], var50);
                func_ov023_021f2304(&arg0->unknown_55d0_[var49], (char*)var51);
            }
            arg0->unknown_55c8_ = NULL;
            arg0->unknown_55d4_ = var37;
            var39->Reset();
            var20->unknown_0_++;
        }
        else if (var37 == 0)
        {
            arg0->unknown_30_.Reset();
            arg0->unknown_557c_ = NULL;
            arg0->unknown_5580_ = NULL;
            arg0->unknown_55c4_ = NULL;
            arg0->unknown_77d1_ = 0;
            Struct_0208cb08* var52 = func_02094a00();
            func_02094b40(var52);
            func_02094b34(var52, 0x65, 500, 0, 0);
            var20->unknown_0_ = 8;
        }
    }
#endif
    else if (var20->unknown_0_ == 5)
    {
        arg0->unknown_55cc_ = (Struct_ov023_021f1868_6*)arg0->unknown_30_.Allocate(0x44c);
        func_ov023_021eb138(arg0->unknown_55cc_, 7);
        arg0->unknown_55cc_->unknown_438_ |= 8;
        func_ov023_021eb080(arg0->unknown_55cc_, &arg0->unknown_30_);
        func_ov023_021eb564(arg0->unknown_55cc_, arg0->unknown_55d0_, arg0->unknown_55d4_);
        func_ov023_021f2348(arg0->unknown_55cc_, arg0->unknown_55d5_);
        var20->unknown_0_++;
    }
    else if (var20->unknown_0_ == 6)
    {
#if defined(jpn)
        if (arg0->unknown_55cc_->unknown_438_ & 4)
            var20->unknown_0_++;
#else
        if (inline_ov023_021f1868(arg0->unknown_55cc_))
            var20->unknown_0_++;
#endif
    }
    else if (var20->unknown_0_ == 7)
    {
        func_ov023_021eb26c(self->guide_);
        self->allocator_.Reset();
        self->guide_ = NULL;
        self->pages_ = NULL;
        self->pageCount_ = 0;
        self->firstGuide_ = 0;
        self->busy_ = 0;
        SetMainBrightness(gameState->GetResources(), 0, 0xf);
        FontBankLoader* music = GetGlobal02109400_02094a00();
        BlankFunction02094b40(music);
        BlankFunction02094b34(music, 0x65, 500, 0, 0);
        end->step_++;
    }
    else if (var20->unknown_0_ == 8)
    {
        if (func_02094b4c(func_02094a00()))
            var20->unknown_0_++;
    }
    else if (var20->unknown_0_ == 9)
    {
        if (!IsBrightnessTransitionActive(gameState->GetResources()))
        {
            func_ov023_021eefac((Struct_ov023_021eeaac_2*)var20);
            return 7;
        }
    }
    return arg0->unknown_eac_;
}
