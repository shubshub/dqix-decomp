#include <globaldefs.h>
extern unsigned char g_fileLoadBuffer[0x30000] __attribute__((aligned(4)));
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "Combat/Main/BattleList.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/GPC.h"
#include "Filesystem/FileIO.h"
#include "NitroSDK/Filesystem/FileAccessor.h"
#include "NitroSDK/Filesystem/LowNitroHandle.h"
#include "NitroSDK/Filesystem/NitroVM.h"
#include "std_library_functions.h"
#include "World/Object3D.h"
#include "GameState/GameState.h"

#if defined(jpn)
#define func_020daf90 func_020dc998
#define func_0203e8f8 func_0203edf4
#define data_020efdc4 data_020efcdc
#define data_020efdda data_020efcf2
#define data_020efde9 data_020efd01
#define data_020efdf0 data_020efd08
#define data_020efe08 data_020efd20
#define data_020efe0e data_020efd26
#define data_020efe20 data_020efd38
#define data_020efe27 data_020efd3f
#define data_020efe30 data_020efd48
#define data_020efe38 data_020efd50
#endif
struct Struct_0203d028_5 {
    char unknown_0_[6];
    unsigned char unknown_6_;
};
struct Struct_0203d028_2 {
    int unknown_0_;
    int unknown_4_;
    struct Struct_0203d028_3* unknown_8_[0xe9];
#if defined(jpn)
    char unknown_3ac_[0x7c38 - 0x3ac];
#else
    char unknown1_3ac_[0x7e78 - 0x3ac];
#endif
    struct Struct_0203d028_5 unknown_7e78_;
    struct Struct_0203d028_5* inline_0203d028() { return &unknown_7e78_; }
};

struct Struct_020652b4 { int unknown_0_; };
extern "C" int func_020652b4(struct Struct_020652b4* arg0);
extern "C" int func_0206dda4(int* arg0);

struct Struct_0203d028_6 {
    unsigned int unknown_0_;
    unsigned char unknown_4_;
    unsigned char unknown_5_;
    unsigned char unknown_6_[2];
    void* unknown_8_;
};
extern "C" void func_020401fc(struct Struct_0203d028_6* arg0, unsigned int arg1, SafeAllocator* arg2);

extern "C" int func_020652c8(int* arg0);

struct Struct_0203d028_7 {
    char unknown_0_[0xb5c];
    unsigned char* unknown_b5c_;
};
struct Struct_0203d028_8 {
    unsigned short unknown_0_;
    char unknown_2_[0x1840 - 2];
    struct Struct_0203d028_7 unknown_1840_;
    struct Struct_0203d028_7* inline_0203d028_2() { return &unknown_1840_; }
};
extern "C" struct Global02012fe4* Zone3D_GetInstance(void);
unsigned int* GlobalFlags_GetInstance(void);

extern "C" int func_020981e4(int arg0, int arg1);
extern "C" int func_02098210(int arg0, int arg1);

extern "C" void func_020404c0(int* arg0);

struct Struct_0203d028_9 {
    char unknown_0_[0xa];
    unsigned char unknown_a_0_ : 7;
    unsigned char unknown_a_7_ : 1;
    unsigned char unknown_b_;
    int unknown_c_;
    int unknown_10_;
    int unknown_14_;
    int unknown_18_;
    short unknown_1c_;
    unsigned char unknown_1e_;
    unsigned char unknown_1f_;
    char unknown_20_[0x38 - 0x20];
    int unknown_38_;
    int unknown_3c_;
    char unknown_40_[0x54 - 0x40];
    int unknown_54_;
    int unknown_58_;
};
extern "C" struct Struct_0203d028_9* func_0206db20(void* arg0, int arg1);

extern "C" void func_02040520(int* arg0, int arg1);
extern "C" void func_02040530(int* arg0, int arg1);

struct Struct_0203d028_10 {
    char unknown_0_[0xac];
    unsigned short unknown_ac_;
    char unknown_ae_[2];
    int unknown_b0_;
    char unknown_b4_[0xc];
    int unknown_c0_;
    unsigned char unknown_c4_;
    char unknown_c5_[3];
    int unknown_c8_;
    int unknown_cc_;
    int unknown_d0_;
    unsigned char unknown_d4_;
};
extern "C" void func_02041244(struct Struct_0203d028_10* arg0);

struct Struct_0203d028_11 {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
    int unknown_c_;
    int unknown_10_;
    int unknown_14_;
    int unknown_18_;
    int unknown_1c_;
};
extern "C" void func_0203dafc(struct Struct_0203d028_11* arg0);

void VramState_Restore(char* obj);
void VramState_Save(char* obj);

struct Struct_0203d028_12;
extern "C" struct Struct_0203d028_12* func_0209854c(struct Struct_0203d028_12* arg0, int arg1);

extern "C" void* func_020daf90(void);
extern "C" int func_020db2d4(void* arg0);
extern "C" void func_020daf9c(int arg0, int arg1, int arg2, int arg3);

void SetMainBrightness(GameResources*, int, int);
void FlagWord_SetBits(unsigned int* p, unsigned int mask);
int IsPowcntBit0Set_020cede0(void);
int DispatchIfEquals1_020cedc0(int a);

extern "C" void func_ov017_0218f064(void* arg0, int arg1, int arg2, int arg3, int arg4);

struct Struct_0203d028_3;

struct Struct_0203d028_13 { char unknown_0_[6]; unsigned short unknown_6_; };
extern "C" void _ZN8Object3D10SetField06Et(struct Struct_0203d028_13* arg0, int arg1);

extern "C" int* func_ov017_021a4658(void* arg0, int arg1);

struct FieldTaskQueue;
void FieldTaskQueue_Update(struct FieldTaskQueue* ctx);

struct Struct_02015438 { signed char unknown_0_; };
extern "C" int func_02046b24(struct Struct_02015438** arg0);

extern "C" void func_0203c794(void* arg0);
extern "C" void func_0203db24(unsigned char* arg0, int arg1);

struct Struct_0203d028_14;
extern "C" void func_0203f02c(struct Struct_0203d028_14* arg0, int arg1, int arg2, char* arg3, int arg4, int arg5);

extern "C" void func_0203f138(void* arg0, int arg1);

extern "C" void func_0203e8f8(void* arg0, void* arg1, void* arg2);

struct Foo0207df50;
void VramState_Rewind(struct Foo0207df50* p);

struct GameState;
extern "C" void func_0200fd48(GameState*, int);

struct FlagWord020466f4 { unsigned int flags; };
void FlagWord_ClearBits(struct FlagWord020466f4* word, unsigned int mask);

struct Struct_02040774 { char unknown_0_[4]; int unknown_4_; int unknown_8_; int unknown_c_; };
struct Struct_0203d028_15 {
    char unknown_0_[0x14];
    struct Struct_02040774* unknown_14_;
    void* unknown_18_;
    void* unknown_1c_;
};
extern "C" void func_02040774(struct Struct_0203d028_15* arg0, int arg1, int arg2, int arg3);

struct Struct_0203cda8;
struct Struct_0203d028_16 {
    char unknown_0_[0x14];
    struct Struct_0203cda8* unknown_14_;
    unsigned char* unknown_18_;
    unsigned char* unknown_1c_;
};
extern "C" void func_0204085c(struct Struct_0203d028_16* arg0, int arg1, int arg2, int arg3);

struct Struct_0203cec4;
struct Struct_02037d88_8;
struct Struct_02040540 { char unknown_0_[0xc]; unsigned int unknown_c_; };
struct Struct_0203d028_17 {
    unsigned int unknown_0_;
    unsigned int unknown_4_;
    unsigned int unknown_8_;
    struct Struct_02040540* unknown_c_;
    unsigned int unknown_10_;
    struct Struct_0203cec4* unknown_14_;
    struct Struct_02037d88_8* unknown_18_;
};
extern "C" void func_02040540(struct Struct_0203d028_17* arg0);

struct ObjectArchiveLoadInfo;

struct Struct_0203d028_18 { char unknown_0_[0x5c]; short unknown_5c_; short unknown_5e_; short unknown_60_; };

struct Struct_020408c8 { char unknown_0_[0x1c]; int unknown_1c_; int unknown_20_; int unknown_24_; };
struct Struct_0203d028_19 {
    char unknown_0_[0x14];
    struct Struct_020408c8* unknown_14_;
    void* unknown_18_;
    void* unknown_1c_;
};
extern "C" void func_020408c8(struct Struct_0203d028_19* arg0, short arg1, short arg2, short arg3);

struct Struct_0203d028_20 {
    char unknown_0_[0xc4];
    char unknown_c4_;
    char unknown_c5_[0xb];
    int unknown_d0_;
};
extern "C" int func_02041598(struct Struct_0203d028_20* arg0, int arg1, int arg2);

extern "C" void func_0203db34(unsigned char* arg0, int arg1, int arg2, int arg3);

struct Struct_0203d028_21 {
    char unknown_0_[0xcc];
    int unknown_cc_;
    int unknown_d0_;
};
extern "C" int func_020415b0(Struct_0203d028_21*, int, int);

extern "C" void func_0203db44(void* arg0, void* arg1, void* arg2);

extern "C" void func_02041628(void* arg0, int arg1, int arg2);
extern "C" void func_02041640(void* arg0, int arg1, int arg2);
struct Vector3i;

extern "C" int Zone3D_GetGroundHeight(void* globalStruct, int* vec3);

struct Struct_02040bfc { char unknown_0_[0x8c]; int unknown_8c_; };
struct Struct_02040bfc_2 { char unknown_0_[0xc8]; int unknown_c8_; };
struct Struct_02040bfc_3 { char unknown_0_[0x2ec]; int unknown_2ec_; };
struct Struct_0203d028_22 {
    char unknown_0_[0x14];
    struct Struct_02040bfc* unknown_14_;
    struct Struct_02040bfc_2* unknown_18_;
    struct Struct_02040bfc_3* unknown_1c_;
};
extern "C" void func_02040bfc(struct Struct_0203d028_22* arg0, int arg1);

struct Struct_0203d028_23 {
    unsigned short unknown_0_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
#if defined(jpn)
    char unknown_4_[0xc];
#endif
    char unknown1_4_[12];
    struct Struct_0203d028_23* unknown_10_;
};

struct Struct_0203d028_24 {
    unsigned int unknown_0_;
    int unknown_4_;
    struct Struct_0203d028_23* unknown_8_;
    struct Struct_0203d028_9* unknown_c_;
    void* unknown_10_;
    void* unknown_14_;
    struct Struct_0203d028_10* unknown_18_;
    struct Struct_0203d028_3* unknown_1c_;
};

struct Struct_0203d028_25 {
    struct Struct_0203d028_6 unknown_0_;
    struct Struct_0203d028_24* unknown_c_[0x20];
    int unknown_8c_;
    int unknown_90_;
    void* unknown_94_;
    char unknown_98_[4];
    unsigned char unknown_9c_;
};

extern char data_020efdc4;
extern char data_020efdda;
extern char data_020efde9;
extern char data_020efdf0;
extern char data_020efe08;
extern char data_020efe0e;
extern char data_020efe20;
extern char data_020efe27;
extern char data_020efe30;
extern char data_020efe38;

struct Struct_0203d028_26 { unsigned int unknown_0_0_ : 1; };

static inline void inline_0203d028_3(void* arg0, short arg1) { *(short*)((char*)arg0 + 0x2e) = arg1; }
static inline void inline_0203d028_4(void* arg0, unsigned char arg1) { *((unsigned char*)arg0 + 0x95) = arg1; }

static inline SafeAllocator& inline_02021578(GameResources* arg0, int arg1) {
    return arg0->allocator_array_1a0[arg1];
}

static inline char& GetResourceBuffer(GameResources* resources, int offset) {
    return resources->vramStates_[offset];
}

static inline void inline_0203d028_6(void* arg0, int arg1)
{
    if (arg0 != 0) {
        *(int*)((char*)arg0 + 0x90) = arg1;
    }
}

// USA: func_0203d028
extern "C" ARM void func_0203d028(struct Struct_0203d028_25* arg0, void* arg1, SafeAllocator* arg2, char* arg3)
{
    if (func_020652b4((struct Struct_020652b4*)&arg0->unknown_90_) ||
        func_0206dda4((int*)&arg0->unknown_94_))
    {
        func_020401fc(&arg0->unknown_0_, 0xc, arg2);
        return;
    }

    struct BattleStruct* battleStruct = (BattleStruct*)GameState::GetInstance();
    GameResources* mgr = GetGameResources();
    struct RegNode0203d028* entry = (struct RegNode0203d028*)GetFieldAt0x0020652c8(&self->listHead);
    struct Global02012fe4* globalStruct = Zone3D_GetInstance();
#if defined(jpn)
    char* var4 = (char*)var3 + 0x860;
#define GLOBAL_SUB var4
#else
#define GLOBAL_SUB ((char*)var3 + 0x840)
#endif
    unsigned int* dataFlags = GlobalFlags_GetInstance();
    unsigned int idVal = *(unsigned short*)globalStruct;
    void* childModelPtr = 0;
    unsigned int loopIndex = 0;
    int assignedFlag = 0;
    InitPool020401fc(&self->pool, 0xc, sb);

    if (func_020981e4((int)GLOBAL_SUB, var6) &&
        func_02098210((int)GLOBAL_SUB, var6) == 0) {
        arg0->unknown_0_.unknown_5_ = 1;
    } else {
        arg0->unknown_0_.unknown_5_ = 0;
    }
    arg0->unknown_8c_ = 0;
    arg0->unknown_9c_ = 0;
    BackgroundLoader::AddLockGlobal();

    while (var2 != 0) {
        struct Struct_0203d028_24* var10 = (struct Struct_0203d028_24*)arg2->Allocate(0x20);
        if (var10 == 0) goto abort_unlock;
        func_020404c0((int*)var10);
        struct Struct_0203d028_9* var11 = func_0206db20(&arg0->unknown_94_, var2->unknown_0_);
        func_02040520((int*)var10, (int)var2);
        func_02040530((int*)var10, (int)var11);

        if (var0->inline_0203d028()->unknown_6_ != 0xff && var11 != 0 && var11->unknown_1f_ != 0) {
            var10->unknown_0_ |= 0x40000;
        }

        int var12 = 0;
        unsigned int var13;
        unsigned int var14;
        unsigned int var15;
        unsigned int var16;
        const void* var17;
        unsigned int var18;
        unsigned int var19;
        unsigned int var20;
        void* var21;
        void* var22;
        void* var23;

        if (entry->type == 2) {
            node->state = (struct State02041244*)sb->Allocate(0xd8);
            if (node->state == 0) goto abort_unlock;
            ResetState02041244(node->state);
            char pathBuf[40];
            sprintf(pathBuf, &data_020efdc4, entry->name);
            void* loadedPtr = LoadFileIntoNewAllocation(pathBuf, *sb, &outLen);
            if (loadedPtr == 0) goto abort_unlock;
            struct Struct_203dafc params;
            ClearEightWords_0203dafc(&params);
            VramState_Restore(fp);
            params.fieldc = (int)sb;
            params.field4 = (int)loadedPtr;
            params.field8 = (int)outLen;
            ((Object3D*)node->state)->LoadFromCCHROrCMOTArchive((ObjectArchiveLoadInfo*)&params, 0);
            VramState_Save(fp);
        }
        else if (var2->unknown_2_ == 4) {
#if defined(jpn)
            unsigned char* var27 = ((struct Struct_0203d028_7*)(var4 + 0x1000))->unknown_b5c_;
#else
            unsigned char* var27 = var3->inline_0203d028_2()->unknown_b5c_;
#endif
            int var28 = 5;
            struct Struct_0203d028_12* var29 = func_0209854c((struct Struct_0203d028_12*)GLOBAL_SUB, var2->unknown_0_);
            if (var29 != 0) {
                {
                    if (func_020db2d4(func_020daf90()) == 0) {
                        func_020daf9c(1, 0, 1, 0);
                        SetMainBrightness(var1, ~0xf, 0);
                    }
                    FlagWord_SetBits(dataFlags, 0x400000);
                    if (!IsPowcntBit0Set_020cede0()) {
                        while (DispatchIfEquals1_020cedc0(1) == 0) {
                        }
                        SleepCurrentContext(1);
                    }
                    *(short*)(var27 + 0x568) = var28;
                    ((unsigned char*)var27)[0x56a] = ((unsigned char*)var29)[0x4f];
                    memcpy(var27 + 0x488, (unsigned char*)var29 + 0x1a, 0x1c);

                    func_ov017_0218f064(var1, 5, 0x4000, 1, 0);

                    var10->unknown_1c_ = (Struct_0203d028_3*)((GameState*)var0)->GetGameObjectByIndex(5);
                    _ZN8Object3D10SetField06Et((struct Struct_0203d028_13*)var10->unknown_1c_, var6);

                    int* var30 = func_ov017_021a4658(var1, 5);
                    var30[3] = 1;

                    char* var31 = (char*)var1 + 0x3000;
#if defined(jpn)
                    void* var32 = *(void**)(var31 + 0x4f0);
                    void* var33 = *(void**)(var31 + 0x4f4);
#else
                    void* var32 = *(void**)(var31 + 0x700);
                    void* var33 = *(void**)(var31 + 0x704);
#endif
                    BackgroundLoader* var34 = BackgroundLoader::GetInstance();

                    while (GetHeadNodeIdOrMinusOne((struct HeadNode02046b24**)ctxA) == 0x13) {
                        instance->RemoveAllLocks();
                        FieldTaskQueue_Update((struct FieldTaskQueue*)ctxA);
                        if (GetHeadNodeIdOrMinusOne((struct HeadNode02046b24**)ctxB) == 0x14) {
                            FieldTaskQueue_Update((struct FieldTaskQueue*)ctxB);
                        }
                    }

                    var10->unknown_14_ = arg2->Allocate(0x9c);
                    if (var10->unknown_14_ == 0) goto abort_unlock;
                    func_0203c794(var10->unknown_14_);
                    func_0203db24((unsigned char*)var10, (int)arg0);

                    const char* var35 = &data_020efdda;
                    if (var10->unknown_14_ != 0) {
                        func_0203f02c(*(struct Struct_0203d028_14**)((char*)var10 + 0x14), (int)var35, (int)arg2, arg3, 0, 0);
                    }
                    if (var10->unknown_14_ != 0) {
                        func_0203f138(var10->unknown_14_, 1);
                    }
                    inline_0203d028_3(var10->unknown_14_, 0x3d);
                    inline_0203d028_4(var10->unknown_14_, 1);
                    func_0203db24((unsigned char*)var10, (int)arg0);

                    SafeAllocator* var36 = &inline_02021578(var1, 8);
                    var36->Reset();
                    func_0203e8f8(arg0, var10, var36);

                    node->combatant = 0;
                    SafeAllocator* alloc3 = &GetResourceAllocator(mgr, 3);
                    char* buf930 = &GetResourceBuffer(mgr, 0x930);
                    entry->type = 0;
                    alloc3->Reset();
                    VramState_Rewind((struct Foo0207df50*)buf930);
                    ClearCombatantSlot_0200fd48((GameState*)battleStruct, 5);
                    FlagWord_ClearBits((struct FlagWord020466f4*)dataFlags, 0x400000);
                }
            }
        }
        else if (var2->unknown_2_ == 5) {
            var10->unknown_18_ = (struct Struct_0203d028_10*)arg2->Allocate(0xd8);
            if (var10->unknown_18_ == 0) goto abort_unlock;
            func_02041244(var10->unknown_18_);
            BackgroundLoader::FreeAllocationsGlobal();

            GPCReadPair var39;
#if defined(jpn)
            GPCReadPair* var40 = &var39;
#define PAIR (*var40)
#else
#define PAIR var39
#endif
            ZeroInitGPCPointer(&PAIR.pGPCFile);
            PAIR.ZeroInitializeMachine();

            char var41[16];
            sprintf(var41, &data_020efde9, var2->unknown1_4_);

            if (!LoadAndDecompressGPCHeaderAndInnerFileInfo(&PAIR.pGPCFile, pair.machine,
                    &data_020efdf0, g_fileLoadBuffer, length2, 0x30000, false, NULL))
            {
                PAIR.Reset();
                ZeroDestroyGPCPointer(&PAIR.pGPCFile);
                goto abort_unlock;
            }

            unsigned char* dst = g_fileLoadBuffer + length2;
            if (!DecompressFileFromGPCByName(pair.pGPCFile, pair.machine,
                    dst, gpcLen, 0x30000 - length2, innerName))
            {
                var39.Reset();
                var39.Reset();
                ZeroDestroyGPCPointer(&var39.pGPCFile);
                goto abort_unlock;
            }

            if (!FindFilesInNarcBySubstring(var42, &data_020efe08, &var17, &var16, 1)) {
                var39.Reset();
                var39.Reset();
                ZeroDestroyGPCPointer(&var39.pGPCFile);
                goto abort_unlock;
            }

            var23 = DecompressLZ77FileIntoAllocatedSpace(*arg2, var17, var18);

            struct Struct_203dafc params;
            ClearEightWords_0203dafc(&params);
            VramState_Restore(fp);
            params.fieldc = (int)sb;
            params.field4 = (int)decompressed;
            params.field8 = (int)decompSize;
            ((Object3D*)node->state)->LoadFromCCHROrCMOTArchive((ObjectArchiveLoadInfo*)&params, 0);
            VramState_Save(fp);

            var10->unknown_18_->unknown_d4_ |= 2;
            var39.Reset();
            var39.Reset();
            ZeroDestroyGPCPointer(&var39.pGPCFile);
        }
        else {
            var10->unknown_14_ = arg2->Allocate(0x9c);
            if (var10->unknown_14_ == 0) goto abort_unlock;
            func_0203c794(var10->unknown_14_);
            func_0203db24((unsigned char*)var10, (int)arg0);

            if (var2->unknown1_4_[0] != 0 && var2->unknown_2_ == 0) {
                int var44 = 0;
                char var45[40];
                if (var11 != 0 && (var11->unknown_c_ & 0x800)) {
                    var44 = 1;
                    sprintf(var45, &data_020efe0e, var2->unknown1_4_);
                    NitroVM var46;
                    NitroVM_Initialize(&var46);
                    if (!NitroVM_PrepareReadFileByPath(&var46, var45)) {
                        var44 = 0;
                    }
                }
                if (var44 == 0) {
                    sprintf(var45, &data_020efe20, var2->unknown1_4_);
                } else {
                    sprintf(var45, &data_020efe27, var2->unknown1_4_);
                }
                if (var10->unknown_14_ != 0) {
                    func_0203f02c(*(struct Struct_0203d028_14**)((char*)var10 + 0x14), (int)var45, (int)arg2, arg3, 0, 0);
                }
                if (var10->unknown_14_ != 0) {
                    func_0203f138(var10->unknown_14_, 1);
                }
                inline_0203d028_3(var10->unknown_14_, 0x3d);
                var12 = 1;
            }
        }

        if (var8 < 0x20) {
            arg0->unknown_c_[var8] = var10;
        }

        if (var11 != 0) {
            func_02040774((struct Struct_0203d028_15*)var10, var11->unknown_10_, var11->unknown_14_, var11->unknown_18_);
            func_0204085c((struct Struct_0203d028_16*)var10, 0, var11->unknown_1c_, 0);
            func_02040540((struct Struct_0203d028_17*)var10);

            if (var12 == 0 && var11->unknown_54_ != 0) {
                char var47[60];
                sprintf(var47, &data_020efe30, var11->unknown_54_);
                void* var48 = LoadFileIntoNewAllocation(var47, *arg2, &var19);
                if (var48 != 0) {
                    int var49 = 0;
                    struct Struct_0203d028_26* var50 = 0;
                    if (var10->unknown_18_ != 0) var50 = *(struct Struct_0203d028_26**)((char*)var10->unknown_18_ + 0xc);
                    else if (var10->unknown_1c_ != 0) var50 = *(struct Struct_0203d028_26**)((char*)var10->unknown_1c_ + 0xc);
                    if (var50 != 0) var49 = var50->unknown_0_0_;

                    struct Struct_0203d028_11 var51;
                    var51.unknown_4_ = (int)var48;
                    var51.unknown_c_ = (int)arg2;
                    var51.unknown_8_ = (int)var19;
                    var51.unknown_1c_ = 1;

                    if (var49 == 0) {
                        ((Object3D*)((int)var10->unknown_18_))->LoadFromCHRArchive((ObjectArchiveLoadInfo*)((int)&var51));
                    } else if (var49 == 1) {
                        ((Object3D*)var10->unknown_18_)->LoadFromCCHROrCMOTArchive((ObjectArchiveLoadInfo*)&var51, 0);
                    }
                }
            }

            if (info->fieldC & 0x2000) {
                if (childModelPtr == 0) {
                    childModelPtr = sb->Allocate(0xac);
                    if (childModelPtr == 0) goto abort_unlock;
                    ((Object3D*)childModelPtr)->Initialize();
                    mdlPtr = LoadFileIntoNewAllocation(&data_020efe38, *sb, &mdlOutLen);
                    if (mdlPtr != 0) {
                        struct Struct_203dafc mdlParams;
                        ClearEightWords_0203dafc(&mdlParams);
                        VramState_Restore(fp);
                        mdlParams.field4 = (int)mdlPtr;
                        mdlParams.field8 = (int)mdlOutLen;
                        mdlParams.fieldc = (int)sb;
                        ((Object3D*)((int)childModelPtr))->LoadFromCHRArchive((ObjectArchiveLoadInfo*)((int)&mdlParams));
                        VramState_Save(fp);
                    }
                    ((Object3D*)((struct Struct_0203d028_18*)var7))->SetScale(0x10a, 0x10a, 0x10a);
                    ((Object3D*)((unsigned char*)var7))->SetFlag16();
                }
                if (var9 == 0) {
                    var10->unknown_10_ = var7;
                    var9 = 1;
                } else {
                    var21 = arg2->Allocate(0xac);
                    if (var21 == 0) goto abort_unlock;
                    ((Object3D*)var21)->Initialize();
                    ((Object3D*)var7)->ShallowCloneTo((Object3D*)var21);
                    ((Object3D*)((unsigned char*)var21))->SetFlag16();
                    var10->unknown_10_ = var21;
                }
            }

            if (var10->unknown_14_ != 0) {
                func_020408c8((struct Struct_0203d028_19*)var10, 0x8f, 0x8f, 0x8f);
            }
            else if (var10->unknown_18_ != 0) {
                ((Object3D*)((struct Struct_0203d028_18*)var10->unknown_18_))->SetScale(0x10a, 0x10a, 0x10a);
                func_02041598((struct Struct_0203d028_20*)var10->unknown_18_, var11->unknown_1e_, 0);
                if (var10->unknown_0_ & 0x800) {
                    ((Object3D*)((unsigned char*)var10->unknown_18_))->SetFlag16();
                    ((Object3D*)((unsigned char*)var10->unknown_18_))->EnableFlag(0x2000000);
                    func_0203db34((unsigned char*)var10->unknown_18_, 0x4b5c, var11->unknown_1c_, 0);
                }
                if (var11->unknown_58_ != 0) {
                    func_020415b0((struct Struct_0203d028_21*)var10->unknown_18_, var11->unknown_58_, 0);
                }
                if (var11->unknown_a_7_) {
                    func_0203db44(arg0, var10, arg2);
                }
            }
            else if (var10->unknown_1c_ != 0) {
                ((Object3D*)((struct Struct_0203d028_18*)var10->unknown_1c_))->SetScale(0x10a, 0x10a, 0x10a);
                func_02041628(var10->unknown_1c_, var11->unknown_1e_, 0);
                if (var10->unknown_0_ & 0x800) {
                    ((Object3D*)((unsigned char*)var10->unknown_1c_))->SetFlag16();
                    func_0203db34((unsigned char*)var10->unknown_1c_, 0x4b5c, var11->unknown_1c_, 0);
                }
                if (var11->unknown_58_ != 0) {
                    func_02041640(var10->unknown_1c_, var11->unknown_58_, 0);
                }
                int localVec3[3];
                *(Vector3i*)localVec3 = *(Vector3i const*)((int*)((char*)node->combatant + 0x44));
                localVec3[1] = Zone3D_GetGroundHeight(globalStruct, localVec3);
                *(Vector3i*)((int*)((char*)node->combatant + 0x44)) = *(Vector3i const*)localVec3;
            }
            func_02040bfc((struct Struct_0203d028_22*)var10, var11->unknown_38_);

            inline_0203d028_6(var10->unknown_14_, var11->unknown_3c_);
        }

        var8++;
        arg0->unknown_8c_++;
        var2 = var2->unknown_10_;
    }

abort_unlock:
    BackgroundLoader::RemoveLockGlobal();
}
