#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Struct_02072e34 {
    int unknown_0_[11];
};
extern "C" void func_02072e34(int arg0, struct Struct_02072e34* arg1);

struct Foo0207df50;
void CopyInternalFields0207df50(struct Foo0207df50* p);
void VramState_Restore(char* obj);
void VramState_Save(char* obj);
void ApplyCombatantEffectByIndex020730e0(int id, int index);
extern "C" int NSBXX_Model_GetMaterialPolygonID(NSBXXInternalModel* model, unsigned int materialIndex);
extern "C" int func_ov017_021b8470(void* arg0);
extern "C" unsigned char* func_ov017_021b8478(void* arg0);
extern "C" int func_020a35e0(unsigned char* arg0, unsigned char arg1);

struct Struct_0203d028_11;
extern "C" void func_0203dafc(struct Struct_0203d028_11* arg0);
struct Struct_02013fb4;
extern "C" void func_ov000_0216d1c4(int arg0, struct Struct_02013fb4* arg1, int arg2, int* arg3);

struct Struct_02053cf8;
extern "C" void func_02053cf8(struct Struct_02053cf8* arg0);
struct Struct_02053e10;
extern "C" void func_02053e10(struct Struct_02053e10* arg0);
extern "C" void func_ov017_021917f0(int arg0, int arg1);
extern "C" void func_02026bc8(unsigned char* arg0, int arg1);
struct Struct_02010604;
extern "C" int func_02033b88(struct Struct_02010604* arg0, int arg1);
struct Struct_0202b2f0;
extern "C" struct Struct_0202b2f0* func_0202ae18(void);
extern "C" GameObject* func_0200ff58(GameState* arg0, int arg1);
extern "C" int func_020546a8(void* arg0);
extern "C" int func_0202be08(struct Struct_0202b2f0* arg0, int arg1);
struct Struct_02054000;
extern "C" void* func_02054000(struct Struct_02054000* arg0);
extern "C" int func_02053c6c(unsigned char* arg0);
extern "C" int func_020483f0(unsigned char* arg0, unsigned short arg1);
extern "C" void func_02083e28(void* arg0, int arg1);
void ApplyCombatantBuffs(int world, int id);
extern "C" void func_ov017_021c6bc8(void);
extern "C" void func_ov017_021cf078(int arg0, int arg1, int arg2);
struct Struct_02015ef4_4;
extern "C" unsigned short func_020de234(struct Struct_02015ef4_4* arg0, int arg1);

struct Struct_ov017_021d6b34 {
    int unknown_0_[8];
};
#if defined(jpn)
#define data_ov017_021d6b34 data_ov017_021d6f2c
#define data_ov017_021d7add data_ov017_021d821f
#define data_ov017_021d7ae3 data_ov017_021d8225
#endif
extern struct Struct_ov017_021d6b34 data_ov017_021d6b34;
extern char data_ov017_021d7add[];
extern char data_ov017_021d7ae3[];

struct Struct_ov017_021b3e14 {
    char unknown_0_[8];
    short unknown_8_;
    short unknown_a_;
    int unknown_c_;
    int unknown_10_[14];
};

typedef unsigned char Type_ov017_021b3e14[11];

struct Struct_ov017_021b3e14_2 {
    char unknown_0_[0x274];
    char unknown_274_[0x49c - 0x274];
    unsigned char unknown_49c_0_ : 1;
};

struct Struct_ov017_021b3e14_3 {
    Object3D unknown_0_;
    char unknown_ac_[0x130 - 0xac];
    int* unknown_130_;
    BaseCombatStats* unknown_134_;
    ModifiableCombatStats* unknown_138_;
    int* unknown_13c_;
#if defined(jpn)
    char unknown_140_[0x144 - 0x140];
#else
    char unknown1_140_[0x150 - 0x140];
#endif
    struct Struct_ov017_021b3e14_2* unknown_150_;
    GameResources::Substruct_12C8* unknown_154_;
#if defined(jpn)
    char unknown_14c_[0x180 - 0x14c];
#else
    char unknown_158_[0x18c - 0x158];
#endif
    int unknown_18c_;
};

#if defined(jpn)
#define POLYGON_ID_ROWS_021b3e14 0x41ac
#define EXT150_WORD_021b3e14 0x8b8
#else
#define POLYGON_ID_ROWS_021b3e14 0x445c
#define EXT150_WORD_021b3e14 0x950
#endif

struct Struct_ov017_021b3e14_4 {
    char unknown_0_[8];
    unsigned int unknown_8_0_ : 18;
    unsigned int unknown_a_2_ : 1;
    char unknown_b_[0x18 - 0xc];
    short unknown_18_;
};

static inline int inline_ov000_021682ec(struct Struct_ov017_021b3e14_3* arg0, int arg1) {
    return arg0->unknown_13c_ ? (*arg0->unknown_13c_ = arg1) : 0;
}

// USA: func_ov017_021b3e14
extern "C" ARM int func_ov017_021b3e14(struct Struct_ov017_021b3e14* arg0) {
    GameResources* var0;
    int var1;
    GameObject* var2;
    int var3;
    GameObject* var4;
    GameResources::Substruct_12C8* var5;
    Model3D* var6;
    int var7;

    GameState* var8 = GameState::GetInstance();
    var0 = GetGameResources();
    BackgroundLoader* var9 = BackgroundLoader::GetInstance();
    struct Struct_ov017_021b3e14_3* var10 = (struct Struct_ov017_021b3e14_3*)var8->GetPartyMemberByIndex(arg0->unknown_8_);
    var5 = var10->unknown_154_;
    struct Struct_02072e34 var11;
    func_02072e34(arg0->unknown_8_, &var11);

    var1 = 1;
    for (var7 = 0; var7 < 11; var7++) {
        if (arg0->unknown_10_[var7] < 0) {
            continue;
        }
        if (var9->GetTaskStatus(arg0->unknown_10_[var7]) == 0) {
            var1 = 0;
            continue;
        }
        if (var9->GetDetailedTaskStatus(arg0->unknown_10_[var7]) != 2) {
            var9->RemoveTask(arg0->unknown_10_[var7]);
            arg0->unknown_10_[var7] = -1;
            continue;
        }
        var2 = var8->GetGameObjectByIndex(var11.unknown_0_[var7]);
        if (var2 == NULL) {
            var9->RemoveTask(arg0->unknown_10_[var7]);
            arg0->unknown_10_[var7] = -1;
            continue;
        }
        void* file;
        unsigned int size;
        loader->GetLoadedFileByID(self->tasks[i], &file, &size);
        SafeAllocator* alloc = &models->allocator_array_4[i];
        char* pairs = models->unknown_cc + i * 0x70;
        CopyInternalFields0207df50((struct Foo0207df50*)pairs);
        VramState_Restore(pairs);
        obj->obj3D_.SetModelFromFile(alloc, file, size, (Model3D::TextureStagingMode)self->stagingMode);
        VramState_Save(pairs);
        model = obj->obj3D_.pModel_;
        if (i == 0) {
            model->CreateBoneMatrixAndMaterialArrays(alloc, 7);
            model->StoreBoneMatrixAndMaterialArrayPointers();
        } else if (!(i == 1 || i == 6 || i == 5 || i == 4)) {
            model->CreateBoneMatrixAndMaterialArrays(alloc, 5);
            model->StoreBoneMatrixAndMaterialArrayPointers();
        }
        if (var7 == 9) {
            var2->obj3D_.position_.x = 0x1000;
            var2->obj3D_.position_.y = 0;
            var2->obj3D_.position_.z = 0;
        }
        if (var7 == 0 || var7 == 1 || var7 == 5 || var7 == 4 || var7 == 2 || var7 == 6 || var7 == 7) {
            func_020730e0(arg0->unknown_8_, var7);
        }
        var9->RemoveTask(arg0->unknown_10_[var7]);
        arg0->unknown_10_[var7] = -1;
    }

    int var16 = 0;
    if (arg0->unknown_8_ >= 0 && arg0->unknown_8_ <= 3) {
        var16 = 1;
    }
    if (var16) {
        struct Struct_ov017_021d6b34 var17 = data_ov017_021d6b34;
        for (int var18 = 0; (var7 = var17.unknown_0_[var18]) > -1; var18++) {
            GameObject* var19 = var8->GetGameObjectByIndex(var11.unknown_0_[var7]);
            if (var19 != NULL && var19->obj3D_.pModel_ != NULL && var19->obj3D_.pModel_->rawInternalModel_ != NULL) {
                (*(Type_ov017_021b3e14*)((unsigned char*)var0 + arg0->unknown_8_ * 11 + POLYGON_ID_ROWS_021b3e14))[var7] =
                    NSBXX_Model_GetMaterialPolygonID(var19->obj3D_.pModel_->rawInternalModel_, 0);
            }
        }
    }

    int var20 = 0;
    void* var21 = var0->unknown_ptr_3718;
    var3 = func_ov017_021b8470(var21);
    unsigned char* var22 = func_ov017_021b8478(var21);
    if (((unsigned char*)var21)[2] != 0 && var22 != NULL) {
        if (func_020a35e0(var22, arg0->unknown_8_)) {
            var20 = 1;
        }
    }

    GameObject* var23 = var8->GetGameObjectByIndex(var11.unknown_0_[0]);
    var4 = var8->GetGameObjectByIndex(var11.unknown_0_[1]);
    for (int var24 = 0; var24 < 3; var24++) {
        int var25 = var24 + 11;
        if (arg0->unknown_10_[var25] < 0) {
            continue;
        }
        if (var9->GetTaskStatus(arg0->unknown_10_[var25]) == 0) {
            var1 = 0;
            continue;
        }
        if (var9->GetDetailedTaskStatus(arg0->unknown_10_[var25]) != 2) {
            var9->RemoveTask(arg0->unknown_10_[var25]);
            arg0->unknown_10_[var25] = -1;
            continue;
        }
        void* var26;
        unsigned int var27;
        var9->GetLoadedFileByID(arg0->unknown_10_[var25], &var26, &var27);
        if (var26 == NULL || var27 == 0) {
            var9->RemoveTask(arg0->unknown_10_[var25]);
            arg0->unknown_10_[var25] = -1;
            continue;
        }
        switch (var25) {
        case 11: {
            ObjectArchiveLoadInfo var28;
            func_0203dafc((struct Struct_0203d028_11*)&var28);
            var28.allocator = &var5->allocator_52c;
            var28.fileData = var26;
            var28.unk_8 = var27;
            var23->obj3D_.LoadFromCCHROrCMOTArchive(&var28, NULL);
            break;
        }
        case 13: {
            ObjectArchiveLoadInfo var29;
            func_0203dafc((struct Struct_0203d028_11*)&var29);
            var29.allocator = &var5->allocator_540;
            var29.fileData = var26;
            var29.packageID = 1;
            var29.unk_10 = 1;
            var29.unk_8 = var27;
            var23->obj3D_.LoadFromCCHROrCMOTArchive(&var29, NULL);
            if (var20) {
                const void* var30;
                unsigned int var31;
                if (FindFilesInNarcBySubstring(var26, data_ov017_021d7add, &var30, &var31, 1)) {
                    int var32;
                    func_ov000_0216d1c4((int)&var5->allocator_540, (struct Struct_02013fb4*)var30, var31, &var32);
                    inline_ov000_021682ec(var10, var32);
                }
            }
            break;
        }
        }
        var9->RemoveTask(arg0->unknown_10_[var25]);
        arg0->unknown_10_[var25] = -1;
    }

    if (var1) {
        GameResources* var33 = GetGameResources();
        func_02053cf8((struct Struct_02053cf8*)var10);
        func_02053e10((struct Struct_02053e10*)var10);
        int var34 = 0;
        if (var20) {
            var34 = 1;
        }
        func_ov017_021917f0(arg0->unknown_8_, var34);
        func_02026bc8((unsigned char*)var33->unknown_ptr_36d0, arg0->unknown_8_);

        GameObject* var35 = var8->GetGameObjectByIndex(var11.unknown_0_[3]);
        GameObject* var36 = var8->GetGameObjectByIndex(var11.unknown_0_[4]);
        if (var35 != NULL && var36 != NULL && var35->obj3D_.pModel_ != NULL && var36->obj3D_.pModel_ != NULL) {
            var35->obj3D_.pModel_->ApplyTexturesFromModel(var36->obj3D_.pModel_);
        }
        func_02033b88((struct Struct_02010604*)var10, 0);
        var10->unknown_0_.EnableFlag(4);

        if (var3 == 0) {
            struct Struct_0202b2f0* var37 = func_0202ae18();
            int var38 = var10->unknown_0_.unknown_4_;
            GameObject* var39 = func_0200ff58(var8, var38);
            if (var39 != NULL) {
                var38 = func_020546a8(var39);
            }
            int var40 = func_0202be08(var37, var38);
            if (*var10->unknown_130_ & 1) {
                if (var40 == 0) {
                    var10->unknown_18c_ |= 1;
                }
            }
        }

        if (var20) {
            var23->obj3D_.MakeHidden();
            ((unsigned char*)var10)[0xc2] |= 0x20;
            if (*(int*)((char*)var10->unknown_138_ + 0x14) & 1) {
                func_02033b88((struct Struct_02010604*)var10, 4);
            } else {
                var10->unknown_0_.MaybeSetRegularAnimation(data_ov017_021d7ae3, 0);
            }
            if (var3 != 0) {
                struct Struct_ov017_021b3e14_3* var41 = (struct Struct_ov017_021b3e14_3*)func_0200ff1c(var8, arg0->unknown_8_);
                if (var41 != NULL) {
                    struct Struct_ov017_021b3e14_4* var42 = (struct Struct_ov017_021b3e14_4*)func_02054000((struct Struct_02054000*)var41);
                    if (var42 != NULL && var42->unknown_18_ > 0 && var42->unknown_a_2_) {
                        int* var43 = (int*)func_02053c6c((unsigned char*)var41);
                        if (var43 != NULL) {
                            func_020483f0((unsigned char*)var41, 4);
                            var43[0xa8 / 4] |= 4;
                        }
                    }
                    func_02083e28(var41->unknown_150_, 0);
                    ModifiableCombatStats* var44 = var41->unknown_138_;
                    unsigned short var45 = var41->unknown_134_->primaryStats.maxMP;
                    var44->primaryStats.maxMP = var45;
                    if (var45 < var44->primaryStats.currMP) {
                        var44->primaryStats.currMP = var45;
                    }
                }
                ApplyCombatantBuffs(var3, arg0->unknown_8_);
                func_ov017_021c6bc8();
                func_ov017_021cf078(arg0->unknown_8_, (unsigned char)*(int*)((char*)var41->unknown_150_ + EXT150_WORD_021b3e14), 1);
            }
        } else {
            var10->unknown_0_.MakeVisible();
        }

        Model3D* var46 = NULL;
        Model3D* var47 = NULL;
        if (var23 != NULL) {
            var46 = var23->obj3D_.pModel_;
        }
        if (var4 != NULL) {
            var47 = var4->obj3D_.pModel_;
        }
        if (var46 != NULL && var47 != NULL) {
            var47->SetBoneMatrixRenderData(var46->GetBoneMatrixRenderData());
            var47->CreateBoneMatrixAndMaterialArrays(NULL, 0);
        }

        {
            int var48 = arg0->unknown_8_;
            GameState* var49 = GameState::GetInstance();
            GameObject* var50 = var49->GetGameObjectByIndex(var48);
            Model3D* var51;
            if (var50 != NULL && (var51 = var50->obj3D_.pModel_) != NULL) {
                var51->RemoveTextures();
                GameObject* var52 = var49->GetGameObjectByIndex(var48 * 12 + 0x17);
                if (var52 != NULL && var52->obj3D_.unknown_2_ >= 0 && var52->obj3D_.pModel_ != NULL) {
                    var51->ApplyTexturesFromModel(var52->obj3D_.pModel_);
                }
                var51->ApplyTexturesFromModel(var51);
            }
        }
        {
            short var53 = arg0->unknown_8_;
            GameState* var54 = GameState::GetInstance();
            GameObject* var55 = var54->GetGameObjectByIndex(var53 * 12 + 0x13);
            Model3D* var56;
            if (var55 != NULL && (var56 = var55->obj3D_.pModel_) != NULL) {
                var56->RemoveTextures();
                GameObject* var57 = var54->GetGameObjectByIndex(var53 * 12 + 0x19);
                if (var57 != NULL && var57->obj3D_.unknown_2_ >= 0 && var57->obj3D_.pModel_ != NULL) {
                    var56->ApplyTexturesFromModel(var57->obj3D_.pModel_);
                }
                var56->ApplyTexturesFromModel(var56);
            }
        }

        GameObject* var58 = var8->GetGameObjectByIndex(arg0->unknown_8_ * 12 + 0x14);
        if (var58 != NULL) {
            var58->obj3D_.MakeVisible();
            struct Struct_ov017_021b3e14_2* var59 = var10->unknown_150_;
            struct Struct_02015ef4_4* var60 = (struct Struct_02015ef4_4*)var59->unknown_274_;
            if (var60 != NULL) {
                if (func_020de234(var60, var59->unknown_49c_0_) / 100 == 5) {
                    var58->obj3D_.MakeHidden();
                }
            }
        }
    }
    return var1;
}
