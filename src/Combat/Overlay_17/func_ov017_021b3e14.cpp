#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Struct_02072e34 {
    int v[11];
};
extern "C" void func_02072e34(int n, struct Struct_02072e34* out);

struct Foo0207df50;
extern "C" void VramState_Rewind(struct Foo0207df50* p);
extern "C" void VramState_Restore(char* obj);
extern "C" void VramState_Save(char* obj);
extern "C" void func_020730e0(int id, int index);
extern "C" int NSBXX_Model_GetMaterialPolygonID(NSBXXInternalModel* model, unsigned int materialIndex);
extern "C" int func_ov017_021b8470(void* obj);
extern "C" unsigned char* func_ov017_021b8478(void* obj);
extern "C" int func_020a35e0(unsigned char* obj, unsigned char index);

struct Struct_203dafc;
extern "C" void func_0203dafc(struct Struct_203dafc* obj);
struct StreamHeader;
extern "C" void func_ov000_0216d1c4(int arg0, struct StreamHeader* buffer, int length, int* out);

struct Struct_02053cf8;
extern "C" void func_02053cf8(struct Struct_02053cf8* obj);
struct Struct_02053e10;
extern "C" void func_02053e10(struct Struct_02053e10* self);
extern "C" void func_ov017_021917f0(int id, int flag);
extern "C" void MapDisplay_RecheckMember(unsigned char* obj, int index);
struct Bytes02033b88;
extern "C" int GameObject_ForceMotionState(struct Bytes02033b88* p, int val);
struct SearchStruct;
extern "C" struct SearchStruct* LinkSession_GetInstance(void);
extern "C" GameObject* func_0200ff58(GameState* battleStruct, int combatantId);
extern "C" int func_020546a8(void* obj);
extern "C" int func_0202be08(struct SearchStruct* search, int id);
struct Struct_02054000;
extern "C" void* func_02054000(struct Struct_02054000* p);
extern "C" int func_02053c6c(unsigned char* obj);
extern "C" int func_020483f0(unsigned char* obj, unsigned short flag);
extern "C" void PartyMember_RecalculateStats(void* a, int arg1);
void ApplyCombatantBuffs(int world, int id);
extern "C" void func_ov017_021c6bc8(void);
extern "C" void func_ov017_021cf078(int combatantId, int slot, int flag);
struct StructDE234_020de234;
extern "C" unsigned short ItemRecord_GetFileNumber(struct StructDE234_020de234* p, int preferMid);

struct Struct_ov017_021d6b34 {
    int v[8];
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
    char pad0[8];
    short id;
    short unknown_a_;
    int unknown_c_;
    int tasks[14];
};

typedef unsigned char Type_ov017_021b3e14[11];

struct Struct_ov017_021b3e14_2 {
    char pad0[0x274];
    char unknown_274_[0x49c - 0x274];
    unsigned char preferMid : 1;
};

struct Struct_ov017_021b3e14_3 {
    Object3D obj3D_;
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
    struct Struct_ov017_021b3e14_2* ext150;
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
    char pad0[8];
    unsigned int unknown_8_0_ : 18;
    unsigned int active : 1;
    char unknown_b_[0x18 - 0xc];
    short count;
};

static inline int inline_ov000_021682ec(struct Struct_ov017_021b3e14_3* member, int value) {
    return member->unknown_13c_ ? (*member->unknown_13c_ = value) : 0;
}

// USA: func_ov017_021b3e14
extern "C" ARM int func_ov017_021b3e14(struct Struct_ov017_021b3e14* self) {
    GameResources* res;
    int done;
    GameObject* obj;
    int world;
    GameObject* head;
    GameResources::Substruct_12C8* models;
    Model3D* model;
    int i;

    GameState* gs = GameState::GetInstance();
    res = GetGameResources();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    struct Struct_ov017_021b3e14_3* member = (struct Struct_ov017_021b3e14_3*)gs->GetPartyMemberByIndex(self->id);
    models = member->unknown_154_;
    struct Struct_02072e34 table;
    func_02072e34(self->id, &table);

    done = 1;
    for (i = 0; i < 11; i++) {
        if (self->tasks[i] < 0) {
            continue;
        }
        if (loader->GetTaskStatus(self->tasks[i]) == 0) {
            done = 0;
            continue;
        }
        if (loader->GetDetailedTaskStatus(self->tasks[i]) != 2) {
            loader->RemoveTask(self->tasks[i]);
            self->tasks[i] = -1;
            continue;
        }
        obj = gs->GetGameObjectByIndex(table.v[i]);
        if (obj == NULL) {
            loader->RemoveTask(self->tasks[i]);
            self->tasks[i] = -1;
            continue;
        }
        void* file;
        unsigned int size;
        loader->GetLoadedFileByID(self->tasks[i], &file, &size);
        SafeAllocator* alloc = &models->allocator_array_4[i];
        char* pairs = models->unknown_cc_ + i * 0x70;
        VramState_Rewind((struct Foo0207df50*)pairs);
        VramState_Restore(pairs);
        obj->obj3D_.SetModelFromFile(alloc, file, size, (Model3D::TextureStagingMode)self->unknown_c_);
        VramState_Save(pairs);
        model = obj->obj3D_.pModel_;
        if (i == 0) {
            model->CreateBoneMatrixAndMaterialArrays(alloc, 7);
            model->StoreBoneMatrixAndMaterialArrayPointers();
        } else if (!(i == 1 || i == 6 || i == 5 || i == 4)) {
            model->CreateBoneMatrixAndMaterialArrays(alloc, 5);
            model->StoreBoneMatrixAndMaterialArrayPointers();
        }
        if (i == 9) {
            obj->obj3D_.position_.x = 0x1000;
            obj->obj3D_.position_.y = 0;
            obj->obj3D_.position_.z = 0;
        }
        if (i == 0 || i == 1 || i == 5 || i == 4 || i == 2 || i == 6 || i == 7) {
            func_020730e0(self->id, i);
        }
        loader->RemoveTask(self->tasks[i]);
        self->tasks[i] = -1;
    }

    int isParty = 0;
    if (self->id >= 0 && self->id <= 3) {
        isParty = 1;
    }
    if (isParty) {
        struct Struct_ov017_021d6b34 list = data_ov017_021d6b34;
        for (int j = 0; (i = list.v[j]) > -1; j++) {
            GameObject* obj = gs->GetGameObjectByIndex(table.v[i]);
            if (obj != NULL && obj->obj3D_.pModel_ != NULL && obj->obj3D_.pModel_->rawInternalModel_ != NULL) {
                (*(Type_ov017_021b3e14*)((unsigned char*)res + self->id * 11 + POLYGON_ID_ROWS_021b3e14))[i] =
                    NSBXX_Model_GetMaterialPolygonID(obj->obj3D_.pModel_->rawInternalModel_, 0);
            }
        }
    }

    int var20 = 0;
    void* var21 = res->unknown_ptr_3718;
    world = func_ov017_021b8470(var21);
    unsigned char* bits = func_ov017_021b8478(var21);
    if (((unsigned char*)var21)[2] != 0 && bits != NULL) {
        if (func_020a35e0(bits, self->id)) {
            var20 = 1;
        }
    }

    GameObject* body = gs->GetGameObjectByIndex(table.v[0]);
    head = gs->GetGameObjectByIndex(table.v[1]);
    for (int k = 0; k < 3; k++) {
        int slot = k + 11;
        if (self->tasks[slot] < 0) {
            continue;
        }
        if (loader->GetTaskStatus(self->tasks[slot]) == 0) {
            done = 0;
            continue;
        }
        if (loader->GetDetailedTaskStatus(self->tasks[slot]) != 2) {
            loader->RemoveTask(self->tasks[slot]);
            self->tasks[slot] = -1;
            continue;
        }
        void* file;
        unsigned int size;
        loader->GetLoadedFileByID(self->tasks[slot], &file, &size);
        if (file == NULL || size == 0) {
            loader->RemoveTask(self->tasks[slot]);
            self->tasks[slot] = -1;
            continue;
        }
        switch (slot) {
        case 11: {
            ObjectArchiveLoadInfo info;
            func_0203dafc((struct Struct_203dafc*)&info);
            info.allocator = &models->allocator_52c;
            info.fileData = file;
            info.fileSize = size;
            body->obj3D_.LoadFromCCHROrCMOTArchive(&info, NULL);
            break;
        }
        case 13: {
            ObjectArchiveLoadInfo info2;
            func_0203dafc((struct Struct_203dafc*)&info2);
            info2.allocator = &models->allocator_540;
            info2.fileData = file;
            info2.packageID = 1;
            info2.unk_10 = 1;
            info2.fileSize = size;
            body->obj3D_.LoadFromCCHROrCMOTArchive(&info2, NULL);
            if (var20) {
                const void* script;
                unsigned int scriptSize;
                if (FindFilesInNarcBySubstring(file, data_ov017_021d7add, &script, &scriptSize, 1)) {
                    int state;
                    func_ov000_0216d1c4((int)&models->allocator_540, (struct StreamHeader*)script, scriptSize, &state);
                    inline_ov000_021682ec(member, state);
                }
            }
            break;
        }
        }
        loader->RemoveTask(self->tasks[slot]);
        self->tasks[slot] = -1;
    }

    if (done) {
        GameResources* res2 = GetGameResources();
        func_02053cf8((struct Struct_02053cf8*)member);
        func_02053e10((struct Struct_02053e10*)member);
        int f = 0;
        if (var20) {
            f = 1;
        }
        func_ov017_021917f0(self->id, f);
        MapDisplay_RecheckMember((unsigned char*)res2->unknown_ptr_36d0, self->id);

        GameObject* dst = gs->GetGameObjectByIndex(table.v[3]);
        GameObject* src = gs->GetGameObjectByIndex(table.v[4]);
        if (dst != NULL && src != NULL && dst->obj3D_.pModel_ != NULL && src->obj3D_.pModel_ != NULL) {
            dst->obj3D_.pModel_->ApplyTexturesFromModel(src->obj3D_.pModel_);
        }
        GameObject_ForceMotionState((struct Bytes02033b88*)member, 0);
        member->obj3D_.EnableFlag(4);

        if (world == 0) {
            struct SearchStruct* search = LinkSession_GetInstance();
            int v = member->obj3D_.actorIndex_;
            GameObject* c = func_0200ff58(gs, v);
            if (c != NULL) {
                v = func_020546a8(c);
            }
            int set = func_0202be08(search, v);
            if (*member->unknown_130_ & 1) {
                if (set == 0) {
                    member->unknown_18c_ |= 1;
                }
            }
        }

        if (var20) {
            body->obj3D_.MakeHidden();
            ((unsigned char*)member)[0xc2] |= 0x20;
            if (*(int*)((char*)member->unknown_138_ + 0x14) & 1) {
                GameObject_ForceMotionState((struct Bytes02033b88*)member, 4);
            } else {
                member->obj3D_.SetAnimationByName(data_ov017_021d7ae3, 0);
            }
            if (world != 0) {
                struct Struct_ov017_021b3e14_3* c = (struct Struct_ov017_021b3e14_3*)func_0200ff1c(gs, self->id);
                if (c != NULL) {
                    struct Struct_ov017_021b3e14_4* var42 = (struct Struct_ov017_021b3e14_4*)func_02054000((struct Struct_02054000*)c);
                    if (var42 != NULL && var42->count > 0 && var42->active) {
                        int* f = (int*)func_02053c6c((unsigned char*)c);
                        if (f != NULL) {
                            func_020483f0((unsigned char*)c, 4);
                            f[0xa8 / 4] |= 4;
                        }
                    }
                    PartyMember_RecalculateStats(c->ext150, 0);
                    ModifiableCombatStats* cur = c->unknown_138_;
                    unsigned short maxMP = c->unknown_134_->primaryStats.maxMP;
                    cur->primaryStats.maxMP = maxMP;
                    if (maxMP < cur->primaryStats.currMP) {
                        cur->primaryStats.currMP = maxMP;
                    }
                }
                ApplyCombatantBuffs(world, self->id);
                func_ov017_021c6bc8();
                func_ov017_021cf078(self->id, (unsigned char)*(int*)((char*)c->ext150 + EXT150_WORD_021b3e14), 1);
            }
        } else {
            member->obj3D_.MakeVisible();
        }

        Model3D* bodyModel = NULL;
        Model3D* var47 = NULL;
        if (body != NULL) {
            bodyModel = body->obj3D_.pModel_;
        }
        if (head != NULL) {
            var47 = head->obj3D_.pModel_;
        }
        if (bodyModel != NULL && var47 != NULL) {
            var47->SetBoneMatrixRenderData(bodyModel->GetBoneMatrixRenderData());
            var47->CreateBoneMatrixAndMaterialArrays(NULL, 0);
        }

        {
            int id = self->id;
            GameState* state = GameState::GetInstance();
            GameObject* obj = state->GetGameObjectByIndex(id);
            Model3D* model;
            if (obj != NULL && (model = obj->obj3D_.pModel_) != NULL) {
                model->RemoveTextures();
                GameObject* from = state->GetGameObjectByIndex(id * 12 + 0x17);
                if (from != NULL && from->obj3D_.unknown_2_ >= 0 && from->obj3D_.pModel_ != NULL) {
                    model->ApplyTexturesFromModel(from->obj3D_.pModel_);
                }
                model->ApplyTexturesFromModel(model);
            }
        }
        {
            short id = self->id;
            GameState* state = GameState::GetInstance();
            GameObject* obj = state->GetGameObjectByIndex(id * 12 + 0x13);
            Model3D* model;
            if (obj != NULL && (model = obj->obj3D_.pModel_) != NULL) {
                model->RemoveTextures();
                GameObject* from = state->GetGameObjectByIndex(id * 12 + 0x19);
                if (from != NULL && from->obj3D_.unknown_2_ >= 0 && from->obj3D_.pModel_ != NULL) {
                    model->ApplyTexturesFromModel(from->obj3D_.pModel_);
                }
                model->ApplyTexturesFromModel(model);
            }
        }

        GameObject* extra = gs->GetGameObjectByIndex(self->id * 12 + 0x14);
        if (extra != NULL) {
            extra->obj3D_.MakeVisible();
            struct Struct_ov017_021b3e14_2* ext = member->ext150;
            struct StructDE234_020de234* packed = (struct StructDE234_020de234*)ext->unknown_274_;
            if (packed != NULL) {
                if (ItemRecord_GetFileNumber(packed, ext->preferMid) / 100 == 5) {
                    extra->obj3D_.MakeHidden();
                }
            }
        }
    }
    return done;
}
