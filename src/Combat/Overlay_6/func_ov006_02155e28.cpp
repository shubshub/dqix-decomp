#include "Combat/MenuNodeChain.h"
#if defined(jpn)
#define R(j,u) (j)
#define func_0207f914 func_02080654
#define data_ov006_0215ff54 data_ov006_021612b8
#define data_ov006_0215ff64 data_ov006_021612c8
#define data_ov006_021600af data_ov006_0216140f
#define data_ov006_021600c4 data_ov006_02161424
#define data_ov006_021600d7 data_ov006_02161437
#define data_ov006_021600f7 data_ov006_02161454
#define data_ov006_0216010b data_ov006_02161468
#define data_ov006_02160125 data_ov006_02161482
#define data_ov006_0216013d data_ov006_0216149a
#define data_ov006_02160156 data_ov006_021614b3
#define data_ov006_02160172 data_ov006_021614cf
#define data_ov006_0216018b data_ov006_021614e8
#define data_ov006_02160190 data_ov006_021614ed
#define data_ov006_02160195 data_ov006_021614f2
#define data_ov006_0216019a data_ov006_021614f7
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"
#include "World/Object3D.h"
#include "Resource/GameResources.h"

extern "C" void __clear(void* arg0, int arg1);
extern "C" int sprintf(char* arg0, const char* arg1, ...);

extern "C" void func_0205a444(char* arg0);
struct Struct_02020cb8_4;
extern "C" int func_02046900(struct Struct_02020cb8_4* arg0);
struct Struct_02020aec;
extern "C" void* func_020467f0(struct Struct_02020aec* arg0, int arg1, void** arg2, int* arg3);
extern "C" void func_0205a528(void* arg0, void* arg1, int arg2, void* arg3);

struct Struct_02020cb8 {
    unsigned char unknown_0_[0x1c];
    unsigned char unknown_1c_0_ : 4;
    unsigned char unknown_1c_4_ : 4;
    unsigned char unknown_1d_[3];
};
extern "C" void func_0204af64(struct Struct_02020cb8* arg0);
extern "C" void func_0204b11c(unsigned char* arg0, int arg1);
extern "C" void func_0204b5b4(void* arg0, int arg1);
struct Struct_0204b12c;
extern "C" void func_0204b12c(struct Struct_0204b12c* arg0, SafeAllocator* arg1);
struct Struct_02020cb8_5;
extern "C" void func_0204b5e8(struct Struct_02020cb8_5* arg0, int arg1, int arg2);
struct Struct_0204b010;
extern "C" void func_0204b010(struct Struct_0204b010* arg0, void* arg1);
extern "C" void func_0204b174(void* arg0, void* arg1, void* arg2, int arg3);

struct Struct_0204c7a8 {
    int unknown_0_;
    struct Struct_02020cb8* unknown_4_;
    unsigned char unknown_8_[0xe0 - 8];
};
extern "C" void func_0204c684(void* arg0);
extern "C" void func_0204c7a8(struct Struct_0204c7a8* arg0, SafeAllocator* arg1, int arg2, unsigned int arg3);

struct Struct_0207f7f0_2;
struct Struct_0207f914;
#if defined(jpn)
extern "C" void func_0207f914(struct Struct_0207f914* arg0, int arg1, int arg2);
#else
extern "C" void func_0207f914(struct Struct_0207f914* arg0, int arg1, int arg2, int arg3);
#endif
extern "C" int func_0207f9f4(void* arg0);
extern "C" void func_0207f7f0(struct Struct_0207f7f0* arg0, struct Struct_0207f7f0_2* arg1, int arg2);

struct Struct_ov006_02155e28 {
    short unknown_0_;
    unsigned char unknown_2_[0x14];
    unsigned char unknown_16_0_ : 1;
    unsigned char unknown_17_;
};
struct Struct_ov006_02155e28_2 {
    unsigned char unknown_0_[8];
    struct Struct_ov006_02155e28* unknown_8_;
    unsigned char unknown_c_[8];
    unsigned short unknown_14_;
};
extern "C" void func_ov023_021e20c0(void* arg0);
extern "C" void func_ov023_021e20f0(void* arg0, void* arg1, void* arg2, unsigned int arg3);

struct Struct_ov003_0217d53c_4 {
    unsigned char unknown_0_[0xb3c];
    int unknown_b3c_;
};
extern "C" void* func_02012fe4(void);
static inline struct Struct_ov003_0217d53c_4* inline_ov003_0216e714_2(void* arg0) {
    return (struct Struct_ov003_0217d53c_4*)((char*)arg0 + R(0x1860,0x1840));
}

int GetFieldIfFlag4_020100f8(char* gs);
void SetField0x3b0Value_020100c4(GameState* gs, int value);
struct Foo0207df50;
void CopyInternalFields0207df50(struct Foo0207df50* p);
void RestorePairTables0207df90(char* obj);
void BackupPairTables0207dfac(char* obj);
struct Fields020407b4;
void SetFields0x44(struct Fields020407b4* dst, int a, int b, int c);
struct Target02059f38;
struct Vec3_02059f38;
void CopyVec3ToField0x44(struct Target02059f38* dst, struct Vec3_02059f38* src);
void InitCombatEntry021542f4(void* entry);
struct Obj0215426c;
void ProcessPendingCommands0215426c(struct Obj0215426c* obj);
void SetModelRenderContextRenderCommandHook(ModelRenderContext* context, void (*hook)(RenderCommandHandler*), int a, int b, int c);
extern "C" void ColorEffect_ConfigureAlphaBlend(unsigned int* reg, int planeA, int planeB, int evA, int evB);
struct Struct_020dbf18 {
    unsigned char unknown_0_[0x10];
    int unknown_10_;
};
extern "C" void func_020dbf18(struct Struct_020dbf18* arg0, int arg1, int arg2, int arg3, int arg4);

struct Struct_ov006_0215ff54 { unsigned char unknown_0_[3]; };
struct Struct_ov006_0215ff64 { signed char unknown_0_[8]; };

extern const char data_ov006_021600af[];
extern struct Struct_ov006_0215ff54 data_ov006_0215ff54;
extern const char data_ov006_021600c4[];
extern const char data_ov006_021600d7[];
extern const char data_ov006_021600f0[];
extern const char data_ov006_021600f7[];
extern struct Struct_ov006_0215ff64 data_ov006_0215ff64;
extern const char data_ov006_0216010b[];
extern const char data_ov006_02160125[];
extern const char data_ov006_0216013d[];
extern const char data_ov006_02160156[];
extern const char data_ov006_02160172[];
extern const char data_ov006_02160080[];
extern int data_ov006_02160380[3];
extern int data_ov006_02160380_dup[3];
extern const char data_ov006_0216018b[];
extern const char data_ov006_02160190[];
extern const char data_ov006_02160195[];
extern const char data_ov006_0216019a[];

struct Struct_ov006_02155e28_3 {
    unsigned char unknown_0_[0x40];
    int unknown_40_;
    unsigned char unknown_44_[8];
    short unknown_4c_;
    unsigned char unknown_4e_[2];
    unsigned char unknown_50_;
    unsigned char unknown_51_[3];
};

struct Struct_ov006_02155e28_4 {
#if !defined(jpn)
    unsigned char unknown_0_[0x180];
#endif
    SafeAllocator* unknown_180_;
    unsigned char unknown_184_[8];
    SafeAllocator unknown_18c_;
    int unknown_1a0_;
    int unknown_1a4_;
    unsigned char unknown_1a8_[0x20];
    struct Struct_ov006_02155e28_2* unknown_1c8_;
    struct Struct_02020cb8* unknown_1cc_;
    struct Struct_0204c7a8* unknown_1d0_;
    struct Struct_0207f7f0* unknown_1d4_;
    unsigned char unknown_1d8_[8];
    int unknown_1e0_;
    struct Struct_ov006_02155e28_3 unknown_1e4_;
    Object3D unknown_238_[5];
    unsigned char unknown_594_[0x5cc - 0x594];
    unsigned char unknown_5cc_[0xad4 - 0x5cc];
    int unknown_ad4_;
    int unknown_ad8_;
    unsigned char unknown_adc_;
    unsigned char unknown_add_;
    unsigned char unknown_ade_[4];
    unsigned short unknown_ae2_;
    unsigned char unknown_ae4_[R(0x121c,0x12a0) - 0xae4];
    struct Struct_020dbf18 unknown_12a0_;
};

static inline SafeAllocator* inline_ov000_02166804(GameResources* arg0, int arg1) {
    return &arg0->allocator_array_38[arg1];
}

// USA: func_ov006_02155e28
extern "C" ARM void func_ov006_02155e28(struct Struct_ov006_02155e28_4* arg0) {
    BackgroundLoader* var0 = BackgroundLoader::GetInstance();
    unsigned char var1 = arg0->unknown_add_;

    if (var1 == 0) {
        func_0205a444((char*)&arg0->unknown_1e4_);
        arg0->unknown_1e4_.unknown_50_ = 0;
        arg0->unknown_1e4_.unknown_40_ = arg0->unknown_1e0_;
        arg0->unknown_1e4_.unknown_4c_ = 0x11;
        arg0->unknown_ad4_ = var0->QueueLoadFile(data_ov006_021600af, NULL);
        arg0->unknown_add_++;
    } else if (var1 == 1) {
        if (var0->GetTaskStatus(arg0->unknown_ad4_) == 0) return;
        void* var2;
        void* var3;
        unsigned int var4;
        int var5;
        var0->GetLoadedFileByID(arg0->unknown_ad4_, &var3, &var4);
        int var6 = func_02046900((struct Struct_02020cb8_4*)var3);
        SafeAllocator* var7 = arg0->unknown_180_;
        var7->Reset();
        for (int var8 = 0; var8 < var6; var8++) {
            void* var9 = func_020467f0((struct Struct_02020aec*)var3, var8, &var2, &var5);
            if (var9 != NULL) {
                func_0205a528(&arg0->unknown_1e4_, var9, var5, var7);
            }
        }
        var0->RemoveTask(arg0->unknown_ad4_);
        arg0->unknown_ad4_ = -1;
        arg0->unknown_add_++;
    } else if (var1 == 2) {
        volatile unsigned short* var10 = (volatile unsigned short*)0x400000a;
        var10[0] = (var10[0] & 0x43) | 0x1d00;
        var10[1] = (var10[1] & 0x43) | 0x1e00;
        var10[2] = (var10[2] & 0x43) | 0x1f08;
        SafeAllocator* var11 = &arg0->unknown_180_[2];
        var11->Reset();
        struct Struct_ov006_0215ff54 var12 = data_ov006_0215ff54;
        for (unsigned char var13 = 0; var13 < 2; var13++) {
            struct Struct_02020cb8* var14 = &arg0->unknown_1cc_[var13];
            func_0204af64(var14);
            var14->unknown_1c_0_ = 0;
            var14->unknown_1c_4_ = var13 + 1;
            func_0204b11c((unsigned char*)var14, 0);
            func_0204b5b4(var14, var12.unknown_0_[var13]);
            func_0204b12c((struct Struct_0204b12c*)var14, var11);
            func_0204b5e8((struct Struct_02020cb8_5*)var14, 0, 0);
        }
        func_0204b010((struct Struct_0204b010*)&arg0->unknown_1cc_[0], NULL);
        func_0204b010((struct Struct_0204b010*)&arg0->unknown_1cc_[1], NULL);
        SafeAllocator* var15 = arg0->unknown_180_;
        var15[3].Reset();
        for (unsigned char var16 = 0; var16 < 1; var16++) {
            struct Struct_0204c7a8* var17 = &arg0->unknown_1d0_[var16];
            func_0204c684(var17);
            func_0204c7a8(var17, &var15[3], arg0->unknown_1a4_, 0x1c0);
            var17->unknown_4_ = arg0->unknown_1cc_;
        }
        arg0->unknown_ad4_ = var0->QueueLoadFile(data_ov006_021600c4, NULL);
        arg0->unknown_add_++;
    } else if (var1 == 3) {
        if (var0->GetTaskStatus(arg0->unknown_ad4_) == 0) return;
        void* var18;
        void* var19;
        unsigned int var20;
        int var21;
        var0->GetLoadedFileByID(arg0->unknown_ad4_, &var19, &var20);
        int var22 = func_02046900((struct Struct_02020cb8_4*)var19);
        SafeAllocator* var23 = arg0->unknown_180_;
        for (int var24 = 0; var24 < var22; var24++) {
            void* var25 = func_020467f0((struct Struct_02020aec*)var19, var24, &var18, &var21);
            if (var25 != NULL) {
                func_0204b174(arg0->unknown_1cc_, var25, &var23[2], var21);
            }
        }
        var0->RemoveTask(arg0->unknown_ad4_);
        arg0->unknown_ad4_ = -1;
        arg0->unknown_add_++;
        arg0->unknown_ae2_ |= 1;
    } else if (var1 == 4) {
        volatile unsigned short* var26 = (volatile unsigned short*)0x4000008;
        var26[0] = (var26[0] & ~3) | 2;
        var26[1] = (var26[1] & ~3) | 0;
        var26[2] = (var26[2] & ~3) | 1;
        var26[3] = (var26[3] & ~3) | 3;
        SafeAllocator* var27 = arg0->unknown_180_;
        var27[4].Reset();
        func_0207f84c(arg0->unknown_1d4_);
        func_0207f914((struct Struct_0207f914*)arg0->unknown_1d4_, (int)&var27[4],
#if defined(jpn)
                                            (int)data_ov006_021600d7);
#else
                                            (int)data_ov006_021600d7, (int)data_ov006_021600f0);
#endif
        arg0->unknown_add_++;
    } else if (var1 == 5) {
        int var28 = func_0207f9f4(arg0->unknown_1d4_);
        if (var28 == 0) {
            arg0->unknown_add_++;
        }
        if (var28 < 0) {
            arg0->unknown_adc_ = 2;
        }
    } else if (var1 == 6) {
        arg0->unknown_ad4_ = var0->QueueLoadFile(data_ov006_021600f7, NULL);
        arg0->unknown_add_++;
    } else if (var1 == 7) {
        if (var0->GetTaskStatus(arg0->unknown_ad4_) == 0) return;
        void* var29;
        unsigned int var30;
        var0->GetLoadedFileByID(arg0->unknown_ad4_, &var29, &var30);
        if (var29 != NULL) {
            SafeAllocator* var31 = arg0->unknown_180_;
            var31[1].Reset();
            func_ov023_021e20c0(arg0->unknown_1c8_);
            func_ov023_021e20f0(arg0->unknown_1c8_, &var31[1], var29, var30);
            struct Struct_ov006_02155e28* var32;
            struct Struct_ov006_02155e28* var33 = arg0->unknown_1c8_->unknown_8_;
            if (var33 == NULL) {
                var32 = NULL;
            } else {
                unsigned short var34 = arg0->unknown_1c8_->unknown_14_;
                if (var34 == 0) {
                    var32 = NULL;
                } else {
                    for (unsigned short var35 = 0; var35 < var34; var35++) {
                        var32 = &var33[var35];
                        if (var32->unknown_0_ == 1) {
                            goto found;
                        }
                    }
                    var32 = NULL;
                }
            }
        found:
            if (var32 != NULL) {
                var32->unknown_16_0_ = 0;
            }
        }
        var0->RemoveTask(arg0->unknown_ad4_);
        arg0->unknown_ad4_ = -1;
        arg0->unknown_add_++;
        if (arg0->unknown_ae2_ & 8) {
            arg0->unknown_add_ = 0x12;
        }
    } else if (var1 == 8) {
        int var36 = (signed char)inline_ov003_0216e714_2(func_02012fe4())->unknown_b3c_;
        char var37[0x20];
        __clear(var37, 0x20);
        if (var36 < 1) {
            var36 = 1;
        }
        if (var36 > 6) {
            var36 = 6;
        }
        struct Bytes8_0215ff64 stages = data_ov006_0215ff64;
        sprintf(path, data_ov006_0216010b, stages.v[chapter]);
        self->taskId = loader->QueueLoadFile(path, NULL);
        self->state++;
    } else if (state == 9) {
        if (loader->GetTaskStatus(self->taskId) == 0) return;
        void* data;
        unsigned int size;
        loader->GetLoadedFileByID(self->taskId, &data, &size);
        if (data != NULL) {
            GameResources* res = GameState::GetInstance()->GetResources();
            SafeAllocator* alloc = GetAllocator(res, 0);
            alloc->Reset();
            CopyInternalFields0207df50((struct Foo0207df50*)res->unknown_2cc);
            RestorePairTables0207df90(res->unknown_2cc);
            ObjectArchiveLoadInfo info;
            info.fileData = data;
            info.unk_8 = size;
            info.allocator = alloc;
            info.unk_10 = 1;
            self->objs[0].LoadFromCHRArchive(&info);
            self->objs[0].MaybeSetBCFGAnimation(0, 0);
            BackupPairTables0207dfac(res->unknown_2cc);
            SetFields0x44((struct Fields020407b4*)&self->objs[0], -0x3800, -0xb3b, 0x60a3);
        }
        loader->RemoveTask(self->taskId);
        self->taskId = -1;
        self->state++;
    } else if (state == 10) {
        self->taskId = loader->QueueLoadFile(data_ov006_02160125, NULL);
        self->state++;
    } else if (state == 11) {
        if (loader->GetTaskStatus(self->taskId) == 0) return;
        void* data;
        unsigned int size;
        loader->GetLoadedFileByID(self->taskId, &data, &size);
        if (data != NULL) {
            GameResources* res = GameState::GetInstance()->GetResources();
            SafeAllocator* alloc = GetAllocator(res, 0);
            RestorePairTables0207df90(res->unknown_2cc);
            ObjectArchiveLoadInfo info;
            info.fileData = data;
            info.unk_8 = size;
            info.allocator = alloc;
            info.unk_10 = 1;
            self->objs[1].LoadFromCCHROrCMOTArchive(&info, NULL);
            self->objs[1].MaybeSetBCFGAnimation(0, 0);
            BackupPairTables0207dfac(res->unknown_2cc);
            self->objs[1].SetScale(0x10a, 0x10a, 0x10a);
            SetFields0x44((struct Fields020407b4*)&self->objs[1], -0x41, -0xaac, 0x61f3);
        }
        loader->RemoveTask(self->taskId);
        self->taskId = -1;
        self->state++;
    } else if (state == 12) {
        self->taskId = loader->QueueLoadFile(data_ov006_0216013d, NULL);
        self->state++;
    } else if (state == 13) {
        if (loader->GetTaskStatus(self->taskId) == 0) return;
        void* data;
        unsigned int size;
        loader->GetLoadedFileByID(self->taskId, &data, &size);
        if (data != NULL) {
            GameResources* res = GameState::GetInstance()->GetResources();
            SafeAllocator* alloc = GetAllocator(res, 0);
            RestorePairTables0207df90(res->unknown_2cc);
            ObjectArchiveLoadInfo info;
            info.fileData = data;
            info.unk_8 = size;
            info.allocator = alloc;
            info.unk_10 = 1;
            self->objs[2].LoadFromCCHROrCMOTArchive(&info, NULL);
            self->objs[2].MaybeSetBCFGAnimation(0, 0);
            BackupPairTables0207dfac(res->unknown_2cc);
            self->objs[2].SetScale(0x10a, 0x10a, 0x10a);
            CopyVec3ToField0x44((struct Target02059f38*)&self->objs[2], (struct Vec3_02059f38*)&self->objs[1].position_);
        }
        var0->RemoveTask(arg0->unknown_ad4_);
        arg0->unknown_ad4_ = -1;
        arg0->unknown_add_++;
    } else if (var1 == 14) {
        arg0->unknown_ad4_ = var0->QueueLoadFile(data_ov006_02160156, NULL);
        arg0->unknown_add_++;
    } else if (var1 == 15) {
        if (var0->GetTaskStatus(arg0->unknown_ad4_) == 0) return;
        GameResources* var54 = GetGameResources();
        arg0->unknown_18c_.CreateTypeA(var54->allocator_array_38[0].Allocate(0x8000), 0x8000);
        arg0->unknown_18c_.Reset();
        func_0207df90(var54->unknown_2cc_);
        void* var55;
        unsigned int var56;
        var0->GetLoadedFileByID(arg0->unknown_ad4_, &var55, &var56);
        if (var55 != NULL && arg0->unknown_18c_.GetSignedAllocator() != NULL) {
            arg0->unknown_238_[3].Initialize();
            ObjectArchiveLoadInfo var57;
            var57.fileData = var55;
            var57.unk_8 = var56;
            var57.allocator = &arg0->unknown_18c_;
            var57.unk_10 = 1;
            arg0->unknown_238_[3].LoadFromCHRArchive(&var57);
            arg0->unknown_238_[3].SetScale(&arg0->unknown_238_[1].GetScale());
            func_02059f38((struct Struct_02059cfc_2*)&arg0->unknown_238_[3], (struct Struct_02059cfc_3*)&arg0->unknown_238_[1].position_);
            arg0->unknown_238_[3].StopCurrentAnimation();
        }
        BackupPairTables0207dfac(res->unknown_2cc);
        loader->RemoveTask(self->taskId);
        self->taskId = -1;
        self->state++;
    } else if (state == 16) {
        self->taskId = loader->QueueLoadFile(data_ov006_02160172, NULL);
        self->state++;
    } else if (state == 17) {
        if (loader->GetTaskStatus(self->taskId) == 0) return;
        void* data;
        unsigned int size;
        loader->GetLoadedFileByID(self->taskId, &data, &size);
        if (data != NULL) {
            GameResources* res = GameState::GetInstance()->GetResources();
            SafeAllocator* alloc = GetAllocator(res, 0);
            RestorePairTables0207df90(res->unknown_2cc);
            ObjectArchiveLoadInfo info;
            info.fileData = data;
            info.unk_8 = size;
            info.allocator = alloc;
            info.unk_10 = 1;
            Object3D* obj = &self->objs[4];
            obj->LoadFromCCHROrCMOTArchive(&info, NULL);
            obj->MaybeSetBCFGAnimation(0, 0);
            BackupPairTables0207dfac(res->unknown_2cc);
            obj->SetScale(0x10a, 0x10a, 0x10a);
            CopyVec3ToField0x44((struct Target02059f38*)obj, (struct Vec3_02059f38*)&self->objs[1].position_);
            obj->StopCurrentAnimation();
            obj->MaybeSetRegularAnimation(data_ov006_02160080, 9);
            obj->DisableFlag(0x1000);
            for (int i = 0; i < 3; i++) {
                data_ov006_02160380[i] = -1;
            }
            Model3D* var65 = arg0->unknown_238_[4].pModel_;
            if (var65 != NULL) {
                data_ov006_02160380_dup[0] = var65->GetBoneIndex(data_ov006_0216018b);
                data_ov006_02160380_dup[1] = var65->GetBoneIndex(data_ov006_02160190);
                data_ov006_02160380_dup[2] = var65->GetBoneIndex(data_ov006_02160195);
                ModelRenderContext* var66;
                if (!var65->unknown_flags_a8_0_) {
                    var66 = NULL;
                } else {
                    var66 = &var65->renderContext_;
                }
                if (var66 != NULL) {
                    SetModelRenderContextRenderCommandHook(var66, (void (*)(RenderCommandHandler*))func_ov006_0215426c, 0, 6, 3);
                }
            }
        }
        var0->RemoveTask(arg0->unknown_ad4_);
        arg0->unknown_ad4_ = -1;
        arg0->unknown_add_++;
    } else if (var1 == 18) {
        arg0->unknown_238_[1].StopCurrentAnimation();
        arg0->unknown_238_[2].StopCurrentAnimation();
        arg0->unknown_238_[1].MaybeSetBCFGAnimation(0, 0);
        arg0->unknown_238_[2].MaybeSetBCFGAnimation(0, 0);
        GameState* var67 = GameState::GetInstance();
        arg0->unknown_1a0_ = func_020100f8((char*)var67);
        func_ov006_021542f4(arg0->unknown_5cc_);
        func_020100c4(var67, (int)arg0->unknown_5cc_);
        struct Struct_0207f7f0* var68 = arg0->unknown_1d4_;
        var68->unknown_2c_ = arg0->unknown_1cc_;
        var68->unknown_38_ = 2;
        func_0207f7f0(arg0->unknown_1d4_, (struct Struct_0207f7f0_2*)arg0->unknown_1d0_, 1);
        arg0->unknown_1d4_->unknown_3a_ = 1;
        volatile unsigned int* var69 = (volatile unsigned int*)0x4000000;
        *var69 = (*var69 & ~0x1f00) | 0x1f00;
        ColorEffect_ConfigureAlphaBlend((unsigned int*)0x4000050, 4, 1, 10, 6);
        self->flags = self->flags | 0x1000;
        self->flags = self->flags & ~0x40;
        GameResources* res = gs->GetResources();
        BeginTask020dbf18(&self->task, (int)data_ov006_0216019a, (int)&self->allocs[5],
                          (int)res->unknown_2cc, 0x18);
        self->state++;
    } else if (state == 19) {
        if (self->task.status == 2) {
            self->result = 1;
            self->state = 0;
        }
    }
}
