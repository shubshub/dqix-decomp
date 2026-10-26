#include <globaldefs.h>
extern unsigned char g_fileLoadBuffer[0x30000] __attribute__((aligned(4)));
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

extern "C" void* LinkSession_GetInstance(void);
extern "C" void Main_HandleLid(void);

void RunOverlayScript0216d1c4(int, StreamHeader*, int, int*);
int LinkSession_IsActive(int* obj);
void BlankFunction020d84f4(void);
void* ResetObjectState02079a3c(void* obj);
int TestBitAt0x34_020a35e0(unsigned char* obj, unsigned char index);
int CheckField0x56bLowNibble(Obj02061bd8* obj);
void VramState_Rewind(Foo0207df50* p);
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
int GetFieldB08_0219e008(void* ov);
void VramState_CopyCurrentTo(State0207dfc8* src, State0207dfc8* dst);

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

    GameState* game = GameState::GetInstance();
    GameResources* res = GetGameResources();
    int* search = (int*)LinkSession_GetInstance();
    SafeAllocator* allocator = GetAllocator38(res, 7);
    blocks = (Slot70*)res->vramStates_;
    allocator->Reset();
    VramState_Rewind((Foo0207df50*)&blocks[7]);
    BackgroundLoader::AddLockGlobal();
    Main_HandleLid();
    ActionDataTables* table = GetData02108e10_020797dc();
#if defined(jpn)
    func_0207ab68(var16, var15);
#else
    arg0->unknown_58_.Reset();
    func_02079cf8(var16, var15, &arg0->unknown_58_);
#endif
    Main_HandleLid();

    if (LoadFileIntoMemory(data_ov000_02183960, g_fileLoadBuffer, &size)) {
        GetFileInNarc(g_fileLoadBuffer, data_ov000_02183976, &script, &scriptSize, 0);
        if (script != NULL) {
            Main_HandleLid();
            RunOverlayScript0216d1c4(work->scriptOwner, (StreamHeader*)script, scriptSize, &work->scriptState);
        }
    }
    if (LinkSession_IsActive(search)) {
        BlankFunction020d84f4();
    }

    unsigned char* buf = g_fileLoadBuffer;
    int capacity = 0x30000;
    ResetObjectState02079a3c(&pair);
    const char* path = data_ov000_02183983;
    if (LoadAndDecompressGPCHeaderAndInnerFileInfo(&pair.pGPCFile, pair.machine,
            path, buf, size, capacity, false, 0)) {
        buf += size;
        capacity -= size;

        for (int var20 = 0; var20 < 4; var20++) {
            if (!func_020a35e0(arg0->unknown_2a0_, var20)) {
                continue;
            }
            Struct_ov000_02164fac_5* var21 = (Struct_ov000_02164fac_5*)func_0200ff1c(var12, var20);
            unsigned char* var22;
            if (var21 == NULL || (var22 = var21->unknown_154_) == NULL) {
                continue;
            }

            SafeAllocator* alloc;
            Main_HandleLid();
            if (CheckField0x56bLowNibble((Obj02061bd8*)c)) {
                c->object.Destroy();
                if (c->info != NULL) {
                    sprintf(name, data_ov000_0218399e, c->info[INFO_NAME_ID]);
                }
                alloc = (SafeAllocator*)(model + 4);
                alloc->Reset();
                VramState_Rewind((Foo0207df50*)(model + 0xcc));
                VramState_Restore((char*)(model + 0xcc));
                LoadFileIntoMemory(name, g_fileLoadBuffer, &size);
                buf = g_fileLoadBuffer;
            } else {
                func_02072c9c(var20, var7);
                if (var21->unknown_150_->unknown_49c_.unknown_0_0_ == 1) {
                    var7[0] = 'w';
                }
                sprintf(var1, data_ov000_021839b8, var7);
                var23 = (SafeAllocator*)(var22 + 0x52c);
                DecompressFileFromGPCByName(var0.pGPCFile, var0.machine, var17, var4, var18, var1);
            }

            if (size != 0) {
                c->object.RemoveAllAnimationPackages();
                ((SafeAllocator*)(model + 0x52c))->Reset();
                ClearEightWords_0203dafc((Struct_203dafc*)&info);
                info.allocator = alloc;
                info.unk_10 = 1;
                info.packageID = 0;
                info.fileSize = size;
                info.fileData = buf;
                c->object.LoadFromCCHROrCMOTArchive(&info, NULL);
            }

            func_02049c88(c, &work->models[i]);
            Main_HandleLid();
            if (CheckField0x56bLowNibble((Obj02061bd8*)c)) {
                VramState_Save((char*)(model + 0xcc));
                if (c->info != NULL) {
                    sprintf(name, data_ov000_021839c0, c->info[INFO_NAME_ID]);
                }
                LoadFileIntoMemory(name, g_fileLoadBuffer, &size);
                buf = g_fileLoadBuffer;
            } else {
                var7[0] = 'm';
                sprintf(var1, data_ov000_021839da, var7);
                DecompressFileFromGPCByName(var0.pGPCFile, var0.machine, var17, var4, var18, var1);
            }

            if (size != 0) {
                c->object.RemoveAnimationPackageByID(1);
                ((SafeAllocator*)(model + 0x540))->Reset();
                ClearEightWords_0203dafc((Struct_203dafc*)&info2);
                info2.unk_10 = 1;
                info2.packageID = 1;
                info2.allocator = (SafeAllocator*)(model + 0x540);
                info2.fileSize = size;
                info2.fileData = buf;
                c->object.LoadFromCCHROrCMOTArchive(&info2, NULL);
                if (FindFilesInNarcBySubstring(buf, data_ov000_021839e2, &script2, &scriptSize2, 1)) {
                    RunOverlayScript0216d1c4((int)(model + 0x540), (StreamHeader*)script2, scriptSize2, &scriptState);
                    SetPtrFieldIfNonNull0x13c_ov000_02165480(c, scriptState);
                }
            }

            c->flags |= 0x20;
            c->object.SetAnimationByName(data_ov000_021839e8, 0);
            if (CheckField0x56bLowNibble((Obj02061bd8*)c)) {
                CombatantData02164fac* data = GetFieldAt0x150_02053c6c((unsigned char*)c);
                if (data != NULL) {
                    data->phase = 0;
                }
            }
            if (LinkSession_IsActive(search)) {
                BlankFunction020d84f4();
            }
        }
    }

    BackgroundLoader::RemoveLockGlobal();
    Main_HandleLid();
    func_ov000_02166a94(work);
#if defined(jpn)
    unsigned int var25 = var15->GetMaxPossibleAllocation();
#else
    unsigned int var25 = 0x26a80;
#endif
    void* var26 = var15->Allocate(var25);
    if (var26 != NULL) {
        arg0->unknown_44_.CreateTypeA(var26, var25);
    }
    if (GetFieldB08_0219e008(res) == 0) {
        VramState_CopyCurrentTo((State0207dfc8*)res->vramStates_, (State0207dfc8*)work->state);
    } else {
        VramState_CopyCurrentTo((State0207dfc8*)&blocks[7], (State0207dfc8*)work->state);
    }
    var0.Reset();
    ZeroDestroyGPCPointer(&var0.pGPCFile);
}
