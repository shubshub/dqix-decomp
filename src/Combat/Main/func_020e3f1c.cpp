#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Grotto/Main/ActiveGrottoClass.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "Memory/SafeAllocator.h"
#include "Resource/Brightness.h"
#include "Resource/GameResources.h"

struct Struct_ov009_0218aa28 {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
};

struct Struct_020e3f1c_5 {
#if defined(jpn)
    char unknown_0_[0x240c];
#else
    char unknown1_0_[0x23ec];
#endif
    ActiveGrottoClass unknown_23ec_;
};

struct Struct_020e3f1c_6 {
    unsigned char unknown_0_0_ : 2;
    unsigned char unknown_0_2_ : 6;
};

struct Struct_020e3f1c_7 {
#if defined(jpn)
    const char* unknown_0_;
    char unknown_4_[0x10 - 0x4];
#else
    char unknown1_0_[0x10];
#endif
    unsigned short unknown_10_;
};

struct Struct_020e3f1c_8 {
    char unknown_0_[0x44];
    struct Struct_ov009_0218aa28 unknown_44_;
    char unknown_50_[0xb2 - 0x50];
    short unknown_b2_;
    char unknown_b4_[0xc1 - 0xb4];
    struct Struct_020e3f1c_6 unknown_c1_;
    char unknown_c2_[0x134 - 0xc2];
    char* unknown_134_;
    char unknown_138_[0x17d - 0x138];
    unsigned char unknown_17d_;
    char unknown_17e_[0x180 - 0x17e];
    struct Struct_020e3f1c_7* unknown_180_;
};

struct Struct_020e3f1c {
    char unknown_0_[0xf78];
    unsigned char unknown_f78_[4];
    unsigned char unknown_f7c_;
};

struct Struct_020e3f1c_2 {
    char unknown_0_[0x10];
    struct Struct_ov009_0218aa28 unknown_10_;
};

struct Struct_020e3f1c_3 {
#if defined(jpn)
    char unknown_0_[0x868];
    int unknown_998_;
    int unknown_99c_;
    char unknown_870_[0x17e2 - 0x870];
#else
    char unknown1_0_[0x998];
    int unknown_998_;
    int unknown_99c_;
    char unknown_9a0_[0x19b2 - 0x9a0];
#endif
    unsigned char unknown_19b2_;
};

struct Struct_020e3f1c_4 {
    char unknown_0_[0x8];
    unsigned short unknown_8_;
    unsigned char unknown_a_;
    char unknown_b_;
    short unknown_c_;
    unsigned char unknown_e_;
};

struct Struct_0201099c_14 {
    unsigned char unknown_0_[0x14];
    int unknown_14_;
};

struct Struct_02076a8c_2;
struct Struct_02010604;
struct Struct_02018300_3;
struct Struct_020338d4;
struct Struct_0202e6a8;
struct Struct_0202e5c0;
struct Struct_0202ea4c;
struct Struct_020d7aa0_2;
struct Struct_02046574_2;
struct Struct_0201099c_3;

extern "C" struct Struct_020e3f1c_3* func_020421a0();
extern "C" struct Struct_020e3f1c_5* func_02012fe4();
extern "C" int func_020100f8(char* arg0);
extern "C" int func_ov017_021959b4();
void StartBattleTimerSequence020e4524(char* obj);
extern "C" void func_ov004_0216fa48(void* obj);
void TickActorAndDispatchPhase02076b58(struct Obj02076b58* actor);
void* GetDataPtr02114e04_020d6c00();
void OrBitsIntoField0_020466e4(unsigned int* word, unsigned int mask);
void SetByte0xbeShiftPrev(struct Bytes02033b88* obj, int value);
extern "C" void func_02037d88(GameObject* obj);
void CancelPendingAction020397cc(struct Obj020397cc* obj, int arg);
extern "C" void func_020531f0(GameObject* obj);
void ClearIntAt0x23c_020a27b8(unsigned char* obj);
int GetSignedByte0x1c9_02039874(void* obj);
void AimAndSetVecY020338d4(struct Struct020338d4* self, struct Vec3* target);
void ClearBytesAndZeroBlock02039d24(unsigned char* obj);
void ComputeAndDispatch020338b0(unsigned char* obj, int target);
void ApplyField0x70Tail(struct GlobalObj0202e6a8* obj, int value);
int GetField0x78_0202e800(void* obj);
void Camera_SetPosition(struct Vec3Target0202e5c0* obj, int x, int y, int z);
void ComputeAngleHeightDistance0202ea4c(struct Obj0202ea4c* obj);
extern "C" void func_0202e0a4(struct Camera020e3f1c* camera);
struct Obj020d7aa0* GetGlobalResetObj020d7a50();
void TeardownAndResetState020d7aa0(struct Obj020d7aa0* obj);
extern "C" void func_ov017_021c3e18(int arg);
extern "C" int sprintf(char* buf, const char* fmt, ...);
void* AllocateAligned4_02012d88(AllocatorUnion* alloc, unsigned int size);
void* ResetAndReturnSelf020dfc2c(void* p);
void KeyTable_Reset(struct Struct020dfc40* p);
extern "C" void KeyTable_Load(void* dest, void* allocator, void* fileData, unsigned int size);
int KeyTable_Get(struct Container020e0310* c, int key);
void TailForward02012da4(AllocatorUnion* alloc, void* ptr);
void SetIndexedName02046574(struct Obj02046574* obj, int index, char* name);
#if defined(jpn)
extern "C" void func_0204500c(void* arg0, void* arg1, int arg2);
#else
extern "C" void func_0204500c(void* arg0, void* arg1, int arg2, int arg3);
#endif
extern "C" void func_02043124(void* arg0);

extern AllocatorUnion data_02114e20;
#if defined(jpn)
struct Struct_020727d8 {
    void* unknown_0_;
    void* unknown_4_;
};
struct Struct_02072a68_2;
#include "Filesystem/FileIO.h"
extern "C" int func_020d3018(const char* arg0, const char* arg1);
extern "C" void func_020727d8(struct Struct_020727d8* arg0);
extern "C" void func_020728ac(void* arg0, void* arg1, void* arg2, int arg3, int arg4, int arg5, int arg6);
extern "C" void* func_02072a68(struct Struct_02072a68_2* arg0, int arg1);
extern const char data_020f2e30[];
extern const char data_020f2e3b[];
extern const char data_020f2e4d[];
#else
extern const char data_020f2cd4[];
extern const char data_020f2ce4[];
#endif

static inline int inline_02061c04_5(int arg0, int arg1) {
    return (int)(((long long)arg0 * arg1 + 0x800) >> 12);
}

// USA: func_020e3f1c
extern "C" ARM void func_020e3f1c(struct Struct_020e3f1c_4* arg0) {
    BackgroundLoader* var0 = BackgroundLoader::GetInstance();
    GameState* var1 = GameState::GetInstance();
    struct Struct_020e3f1c_3* var2 = func_020421a0();
    Struct_0208cb08* var3 = func_02094a00();
    ActiveGrottoClass* var4 = &func_02012fe4()->unknown_23ec_;
    struct Struct_020e3f1c_2* var5 = (struct Struct_020e3f1c_2*)func_020100f8((char*)var1);
    struct Struct_020e3f1c_8* var6 = (struct Struct_020e3f1c_8*)var1->GetUnknownGameObject();
    GameResources* var7 = GetGameResources();

    if (func_ov017_021959b4()) {
        func_020e4524((char*)arg0);
        return;
    }

    short var8 = -1;
    if (var4 != NULL) {
        DetailedTreasureMapData* var9 = var4->GetDetailedData();
        if (var9 != NULL) {
            if (var9->mapType_ == 1) {
                var8 = var9->regular_.bossMonsterID_;
            } else if (var9->mapType_ == 2) {
                var8 = var9->legacy_.bossMonsterID_;
            }
        }
    }

    struct Struct_020e3f1c_8* var10 = (struct Struct_020e3f1c_8*)var1->GetMaybeFieldMonsterByIndex(arg0->unknown_8_);
    if (var10 == NULL) {
        func_ov004_0216fa48(arg0);
        return;
    }
    func_02076b58((struct Struct_02076a8c_2*)var10);
    func_020466e4((unsigned int*)func_020d6c00(), 2);

    int var11;
    for (var11 = 0; var11 < 4; var11++) {
        GameObject* var12 = var1->GetPartyMemberByIndex(var11);
        if (var12 != NULL) {
            var12->obj3D_.EnableFlag(0x1000000);
            var12->obj3D_.DisableFlag(0x1020);
            ((struct Struct_020e3f1c_8*)var12)->unknown_c1_.unknown_0_0_ |= 2;
            if (((struct Struct_020e3f1c_8*)var12)->unknown_b2_ > 0) {
                func_02033b88((struct Struct_02010604*)var12, 1);
            } else {
                func_02033b88((struct Struct_02010604*)var12, 0);
            }
            func_02037d88(var12);
        }
    }

    if (arg0->unknown_a_ == 0) {
        if (var6 != NULL) {
            func_020397cc((struct Struct_02018300_3*)var6, 1);
            var6->unknown_b2_ = 0;
        }
        for (int var13 = 0; var13 < 4; var13++) {
            GameObject* var14 = var1->GetPartyMemberByIndex(var13);
            if (var14 != NULL) {
                func_020531f0(var14);
            }
        }
        func_020a27b8((unsigned char*)var5);
        SetMainBrightness(var7, -16, 0x1e);
#if defined(jpn)
        if (func_020d3018(var10->unknown_180_->unknown_0_, data_020f2e30) == 0) {
#else
        if (var10->unknown_180_->unknown_10_ == 0x133) {
#endif
            arg0->unknown_e_ = 2;
        } else if (var10->unknown_17d_ & 4) {
            arg0->unknown_e_ = 1;
        }
        arg0->unknown_a_ = 1;
    } else if (arg0->unknown_a_ == 1) {
        if (IsMainBrightnessTransitionActive(var7)) {
            return;
        }
        struct Struct_ov009_0218aa28 var15 = var10->unknown_44_;
        struct Struct_020e3f1c* var16 = (struct Struct_020e3f1c*)func_02010828(var1);
        for (int var17 = 0; var17 < var16->unknown_f7c_; var17++) {
            struct Struct_020e3f1c_8* var18 = (struct Struct_020e3f1c_8*)var1->GetPartyMemberByIndex(var16->unknown_f78_[var17]);
            if (var18 != NULL) {
                if (func_02039874(var18) > 0) {
                    ((GameObject*)var18)->obj3D_.SetInheritedAlpha(0);
                }
                var18->unknown_44_.unknown_0_ = var15.unknown_0_;
                var18->unknown_44_.unknown_4_ = var15.unknown_4_;
                var18->unknown_44_.unknown_8_ = var15.unknown_8_ + 0x3000;
                func_020338d4((struct Struct_020338d4*)var18, &var10->unknown_44_);
                func_02039d24((unsigned char*)var18);
            }
        }
        ComputeAndDispatch020338b0((unsigned char*)monster, (int)&leader->position);
        ApplyField0x70Tail((struct GlobalObj0202e6a8*)camera, 0);
        int dist = GetField0x78_0202e800(camera);
        struct Vec3 target = camera->target;
        if (intro->cameraMode == 1) {
            int dz = FxMul(dist, 0xddb);
            int dy = FxMul(dist, 0x599);
            Camera_SetPosition((struct Vec3Target0202e5c0*)camera, target.x, target.y + dy, target.z + dz);
            ComputeAngleHeightDistance0202ea4c((struct Obj0202ea4c*)camera);
        } else if (intro->cameraMode == 2) {
            Camera_SetPosition((struct Vec3Target0202e5c0*)camera, target.x, target.y + 0x2000, target.z + 0xd800);
            ComputeAngleHeightDistance0202ea4c((struct Obj0202ea4c*)camera);
        }
        func_0202e0a4(var5);
        func_020d7aa0(func_020d7a50());
        func_02094b34(var3, 0x74, 0x20e, 0, 0);
        func_ov017_021c3e18(0);
        arg0->unknown_a_ = 2;
    } else if (arg0->unknown_a_ == 2) {
        SetMainBrightness(var7, 0, 0x3c);
        arg0->unknown_a_ = 3;
    } else if (arg0->unknown_a_ == 3) {
        if (IsMainBrightnessTransitionActive(var7)) {
            return;
        }
        if (!func_02094b4c(var3)) {
            return;
        }
#if defined(jpn)
        arg0->unknown_c_ = var0->QueueLoadFile(data_020f2e3b, NULL);
#else
        char var23[16];
        sprintf(var23, data_020f2cd4, var8);
        arg0->unknown_c_ = var0->QueueLoadFileInGP2(data_020f2ce4, var23, NULL);
#endif
        arg0->unknown_a_ = 4;
    } else if (arg0->unknown_a_ == 4) {
        if (!var0->GetTaskStatus(arg0->unknown_c_)) {
            return;
        }
        if (var0->GetDetailedTaskStatus(arg0->unknown_c_) != 2) {
            func_ov004_0216fa48(arg0);
            return;
        }
        void* var24;
        unsigned int var25;
        var0->GetLoadedFileByID(arg0->unknown_c_, &var24, &var25);
        if (var24 == NULL) {
            func_ov004_0216fa48(arg0);
            return;
        }
#if defined(jpn)
        char var26[16];
        sprintf(var26, data_020f2e4d, var8);
        const void* var27 = NULL;
        unsigned int var28 = 0;
        if (!GetFileInNarc(var24, var26, &var27, &var28, 0)) {
            return;
        }
        void* var30 = func_02012d88(&data_02114e20, 0x400);
        if (var30 == NULL) {
            func_ov004_0216fa48(arg0);
            return;
        }
        SafeAllocator var31;
        var31.ResetAllocatorPointer();
        var31.CreateTypeA(var30, 0x400);
        struct Struct_020727d8 var29;
        func_020727d8(&var29);
        func_020728ac(&var29, &var31, (void*)var27, var28, 0, 0, 0);
        var0->RemoveTask(arg0->unknown_c_);
        arg0->unknown_c_ = -1;
        void* var33 = func_02072a68((struct Struct_02072a68_2*)&var29, var8);
#else
        void* var30 = func_02012d88(&data_02114e20, 0x500);
        if (var30 == NULL) {
            func_ov004_0216fa48(arg0);
            return;
        }
        SafeAllocator alloc;
        alloc.ResetAllocatorPointer();
        alloc.CreateTypeA(buf, 0x500);
        struct Struct020dfc40 table;
        ResetAndReturnSelf020dfc2c(&table);
        KeyTable_Reset(&table);
        KeyTable_Load(&table, &alloc, fileData, size);
        loader->RemoveTask(intro->taskId);
        intro->taskId = -1;
        void* entry = (void*)KeyTable_Get((struct Container020e0310*)&table, bossId);
#endif
        if (var33 == NULL) {
            var31.Destroy();
            func_02012da4(&data_02114e20, var30);
            func_ov004_0216fa48(arg0);
            return;
        }
        var2->unknown_19b2_ = 1;
        var2->unknown_99c_ = 1;
        func_02046574((struct Struct_02046574_2*)var2, 0, var6->unknown_134_);
#if defined(jpn)
        func_0204500c(var2, var33, 0);
#else
        func_0204500c(var2, var33, 0, 0xe3);
#endif
        var2->unknown_998_ = 1;
        var31.Destroy();
        func_02012da4(&data_02114e20, var30);
        arg0->unknown_a_ = 5;
    } else if (arg0->unknown_a_ == 5) {
        var2->unknown_99c_ = 1;
        if (var2->unknown_998_ == 0) {
            var2->unknown_99c_ = 0;
            func_02043124(var2);
            func_ov004_0216fa48(arg0);
        }
    }
}
