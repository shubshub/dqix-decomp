#include <globaldefs.h>
extern unsigned char data_0211e33c[0x30000] __attribute__((aligned(4)));
#include "std_library_functions.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "Filesystem/GPC.h"
#include "GameState/GameState.h"
#include "Resource/ActionDataTables.h"
#include "Resource/GameResources.h"

struct Struct_02013fb4;
struct Struct_0203d028;
struct Struct_0205faf4_11;
struct Struct_0203d028_11;
struct Struct_02015ef4_5;

extern "C" void* func_0202ae18(void);
extern "C" void func_02012de8(void);

void RunOverlayScript0216d1c4(int, StreamHeader*, int, int*);
int CheckField0NonZero_0202b7d8(int* obj);
void BlankFunction020d84f4(void);
void* ResetObjectState02079a3c(void* obj);
int TestBitAt0x34_020a35e0(unsigned char* obj, unsigned char index);
int CheckField0x56bLowNibble(Obj02061bd8* obj);
void CopyInternalFields0207df50(Foo0207df50* p);
void VramState_Restore(char* obj);
void VramState_Save(char* obj);
void FormatEffectStats02072c9c(int combatantId, char* buf);
void ClearEightWords_0203dafc(Struct_203dafc* obj);
extern "C" void func_02049c88(void* obj, void* state);
void SetPtrFieldIfNonNull0x13c_ov000_02165480(void*, int);
struct CombatantData02164fac;
CombatantData02164fac* GetFieldAt0x150_02053c6c(unsigned char* obj);
extern "C" void func_ov000_02166a94(void* work);
#if defined(jpn)
extern "C" void func_0207ab68(Struct_02108e10* arg0, SafeAllocator* arg1);
#endif
extern "C" int func_ov017_0219e008(void* arg0);
extern "C" void func_0207dfc8(Struct_02015ef4_5* arg0, Struct_02015ef4_5* arg1);

extern const char data_ov000_02183960[];
extern const char data_ov000_02183976[];
extern const char data_ov000_02183983[];
extern const char data_ov000_0218399e[];
extern const char data_ov000_021839b8[];
extern const char data_ov000_021839c0[];
extern const char data_ov000_021839da[];
extern const char data_ov000_021839e2[];
extern const char data_ov000_021839e8[];

struct Struct_01ff91ac_11 { char unknown_0_[0x70]; };
struct Struct_ov000_02164fac_2 { char unknown_0_[0x70]; };
static inline SafeAllocator* inline_ov000_02164fac(GameResources* arg0, int arg1) { return &arg0->allocator_array_38[arg1]; }

struct Struct_ov000_02164fac_3 {
    char unknown_0_[4];
    int unknown_4_;
    char unknown_8_[0x44 - 0x8];
    SafeAllocator unknown_44_;
    SafeAllocator unknown_58_;
#if defined(jpn)
    char unknown_6c_[0x1a8 - 0x6c];
    char unknown_1bc_[0x21c - 0x1a8];
    unsigned char* unknown_2a0_;
    char unknown_220_[0x5914 - 0x220];
    int unknown_5724_;
    char unknown_5918_[0x5e2c - 0x5918];
#else
    char unknown1_6c_[0x1bc - 0x6c];
    char unknown_1bc_[0x2a0 - 0x1bc];
    unsigned char* unknown_2a0_;
    char unknown_2a4_[0x5724 - 0x2a4];
    int unknown_5724_;
    char unknown_5728_[0x5c3c - 0x5728];
#endif
    Struct_01ff91ac_11 unknown_5c3c_[4];
};

struct Struct_ov000_02164fac_4 {
    unsigned char unknown_0_0_ : 1;
    unsigned char unknown_0_1_ : 7;
};

struct Struct_ov000_02164fac {
    char unknown_0_[0x49c];
    Struct_ov000_02164fac_4 unknown_49c_;
#if defined(jpn)
    char unknown_49d_[0x8b4 - 0x49d];
#else
    char unknown1_49d_[0x94c - 0x49d];
#endif
    int unknown_94c_;
};

#if defined(jpn)
#define INFO_NAME_ID 0xc
#else
#define INFO_NAME_ID 0x11
#endif

struct Struct_ov000_02164fac_5 {
    Object3D unknown_0_;
    char unknown_ac_[0xc2 - 0xac];
    unsigned char unknown_c2_;
#if defined(jpn)
    char unknown_c3_[0x144 - 0xc3];
    Struct_ov000_02164fac* unknown_150_;
    unsigned char* unknown_154_;
    char unknown_14c_[0x1b8 - 0x14c];
#else
    char unknown1_c3_[0x150 - 0xc3];
    Struct_ov000_02164fac* unknown_150_;
    unsigned char* unknown_154_;
    char unknown_158_[0x1c4 - 0x158];
#endif
    unsigned char* unknown_1c4_;
};

// USA: func_ov000_02164fac
extern "C" ARM void func_ov000_02164fac(Struct_ov000_02164fac_3* arg0) {
    GPCReadPair var0;
    char var1[0x50];
    ObjectArchiveLoadInfo var2;
    ObjectArchiveLoadInfo var3;
    unsigned int var4;
    const void* var5;
    unsigned int var6;
    char var7[8];
    const void* var8;
    unsigned int var9;
    int var10;
    Struct_ov000_02164fac_2* var11;

    GameState* var12 = GameState::GetInstance();
    GameResources* var13 = GetGameResources();
    int* var14 = (int*)func_0202ae18();
    SafeAllocator* var15 = inline_ov000_02164fac(var13, 7);
    var11 = (Struct_ov000_02164fac_2*)var13->unknown_2cc_;
    var15->Reset();
    func_0207df50((Struct_0203d028*)&var11[7]);
    BackgroundLoader::AddLockGlobal();
    func_02012de8();
    Struct_02108e10* var16 = func_020797dc();
#if defined(jpn)
    func_0207ab68(var16, var15);
#else
    arg0->unknown_58_.Reset();
    func_02079cf8(var16, var15, &arg0->unknown_58_);
#endif
    func_02012de8();

    if (LoadFileIntoMemory(data_ov000_02183960, data_0211e33c, &var4)) {
        GetFileInNarc(data_0211e33c, data_ov000_02183976, &var5, &var6, 0);
        if (var5 != NULL) {
            func_02012de8();
            func_ov000_0216d1c4(arg0->unknown_4_, (Struct_02013fb4*)var5, var6, &arg0->unknown_5724_);
        }
    }
    if (func_0202b7d8(var14)) {
        func_020d84f4();
    }

    unsigned char* var17 = data_0211e33c;
    int var18 = 0x30000;
    func_02079a3c(&var0);
    const char* var19 = data_ov000_02183983;
    if (LoadAndDecompressGPCHeaderAndInnerFileInfo(&var0.pGPCFile, var0.machine,
            var19, var17, var4, var18, false, 0)) {
        var17 += var4;
        var18 -= var4;

        for (int var20 = 0; var20 < 4; var20++) {
            if (!func_020a35e0(arg0->unknown_2a0_, var20)) {
                continue;
            }
            Struct_ov000_02164fac_5* var21 = (Struct_ov000_02164fac_5*)func_0200ff1c(var12, var20);
            unsigned char* var22;
            if (var21 == NULL || (var22 = var21->unknown_154_) == NULL) {
                continue;
            }

            SafeAllocator* var23;
            func_02012de8();
            if (func_02061bd8((Struct_0205faf4_11*)var21)) {
                var21->unknown_0_.Destroy();
                if (var21->unknown_1c4_ != NULL) {
                    sprintf(var1, data_ov000_0218399e, var21->unknown_1c4_[INFO_NAME_ID]);
                }
                alloc = (SafeAllocator*)(model + 4);
                alloc->Reset();
                CopyInternalFields0207df50((Foo0207df50*)(model + 0xcc));
                VramState_Restore((char*)(model + 0xcc));
                LoadFileIntoMemory(name, data_0211e33c, &size);
                buf = data_0211e33c;
            } else {
                func_02072c9c(var20, var7);
                if (var21->unknown_150_->unknown_49c_.unknown_0_0_ == 1) {
                    var7[0] = 'w';
                }
                sprintf(var1, data_ov000_021839b8, var7);
                var23 = (SafeAllocator*)(var22 + 0x52c);
                DecompressFileFromGPCByName(var0.pGPCFile, var0.machine, var17, var4, var18, var1);
            }

            if (var4 != 0) {
                var21->unknown_0_.RemoveAllAnimationPackages();
                ((SafeAllocator*)(var22 + 0x52c))->Reset();
                func_0203dafc((Struct_0203d028_11*)&var2);
                var2.allocator = var23;
                var2.unk_10 = 1;
                var2.packageID = 0;
                var2.unk_8 = var4;
                var2.fileData = var17;
                var21->unknown_0_.LoadFromCCHROrCMOTArchive(&var2, NULL);
            }

            func_02049c88(var21, &arg0->unknown_5c3c_[var20]);
            func_02012de8();
            if (CheckField0x56bLowNibble((Obj02061bd8*)c)) {
                VramState_Save((char*)(model + 0xcc));
                if (c->info != NULL) {
                    sprintf(name, data_ov000_021839c0, c->info[INFO_NAME_ID]);
                }
                LoadFileIntoMemory(var1, data_0211e33c, &var4);
                var17 = data_0211e33c;
            } else {
                var7[0] = 'm';
                sprintf(var1, data_ov000_021839da, var7);
                DecompressFileFromGPCByName(var0.pGPCFile, var0.machine, var17, var4, var18, var1);
            }

            if (var4 != 0) {
                var21->unknown_0_.RemoveAnimationPackageByID(1);
                ((SafeAllocator*)(var22 + 0x540))->Reset();
                func_0203dafc((Struct_0203d028_11*)&var3);
                var3.unk_10 = 1;
                var3.packageID = 1;
                var3.allocator = (SafeAllocator*)(var22 + 0x540);
                var3.unk_8 = var4;
                var3.fileData = var17;
                var21->unknown_0_.LoadFromCCHROrCMOTArchive(&var3, NULL);
                if (FindFilesInNarcBySubstring(var17, data_ov000_021839e2, &var8, &var9, 1)) {
                    func_ov000_0216d1c4((int)(var22 + 0x540), (Struct_02013fb4*)var8, var9, &var10);
                    func_ov000_02165480(var21, var10);
                }
            }

            var21->unknown_c2_ |= 0x20;
            var21->unknown_0_.MaybeSetRegularAnimation(data_ov000_021839e8, 0);
            if (func_02061bd8((Struct_0205faf4_11*)var21)) {
                Struct_ov000_02164fac* var24 = func_02053c6c((unsigned char*)var21);
                if (var24 != NULL) {
                    var24->unknown_94c_ = 0;
                }
            }
            if (func_0202b7d8(var14)) {
                func_020d84f4();
            }
        }
    }

    BackgroundLoader::RemoveLockGlobal();
    func_02012de8();
    func_ov000_02166a94(arg0);
#if defined(jpn)
    unsigned int var25 = var15->GetMaxPossibleAllocation();
#else
    unsigned int var25 = 0x26a80;
#endif
    void* var26 = var15->Allocate(var25);
    if (var26 != NULL) {
        arg0->unknown_44_.CreateTypeA(var26, var25);
    }
    if (func_ov017_0219e008(var13) == 0) {
        func_0207dfc8((Struct_02015ef4_5*)var13->unknown_2cc_, (Struct_02015ef4_5*)arg0->unknown_1bc_);
    } else {
        func_0207dfc8((Struct_02015ef4_5*)&var11[7], (Struct_02015ef4_5*)arg0->unknown_1bc_);
    }
    var0.Reset();
    ZeroDestroyGPCPointer(&var0.pGPCFile);
}
