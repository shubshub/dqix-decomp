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
#include "Graphics/Window.h"
#include "Graphics/Background.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"
#include "World/Object3D.h"
#include "Resource/GameResources.h"

extern "C" void __clear(void* arg0, int arg1);
extern "C" int sprintf(char* arg0, const char* arg1, ...);

void SpriteContext_Init(char* obj);
struct PacRecord;
int Pac_CountFiles(struct PacRecord* data);
void* Pac_GetFile(struct PacRecord* data, int index, void** outRec, int* outSize);
extern "C" void SpriteContext_LoadFile(void* a, void* ptr, int val, void* d);

void Background_Init(struct BackgroundGraphics* list);
void Background_SetMapSize(unsigned char* list, int value);
extern "C" void Background_SetPriority(void* list, int priority);
struct BackgroundGraphics;
void Background_AllocateMap(struct BackgroundGraphics* list, SafeAllocator* alloc);
void Background_SetScroll(struct BackgroundGraphics* list, int a, int b);
void Background_ClearMap(struct BackgroundGraphics* list, void* buffer);
extern "C" void Background_LoadFile(void* list, void* data, void* alloc, int size);

extern "C" void WindowPane_Init(void* node);
void WindowPane_AllocateBuffer(struct WindowPane* node, SafeAllocator* alloc, int a, unsigned int size);

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
extern "C" void* Zone3D_GetInstance(void);
static inline struct Progress02012fe4* GetProgress(void* run) {
    return (struct Progress02012fe4*)((char*)run + R(0x1860,0x1840));
}

int GetFieldIfFlag4_020100f8(char* gs);
void GameState_SetCamera(GameState* gs, int value);
struct Foo0207df50;
void VramState_Rewind(struct Foo0207df50* p);
void VramState_Restore(char* obj);
void VramState_Save(char* obj);
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
    SafeAllocator* allocs;
    unsigned char pad184[8];
    SafeAllocator modelAlloc;
    int field1a0;
    int field1a4;
    unsigned char pad1a8[0x20];
    struct Table021e20f0* table;
    struct BackgroundGraphics* lists;
    struct WindowPane* nodes;
    struct Manager0207f7f0* mgr;
    unsigned char pad1d8[8];
    int field1e0;
    struct Records0205a444 records;
    Object3D objs[5];
    unsigned char pad594[0x5cc - 0x594];
    unsigned char entry[0xad4 - 0x5cc];
    int taskId;
    int taskB;
    unsigned char result;
    unsigned char state;
    unsigned char padade[4];
    unsigned short flags;
    unsigned char padae4[R(0x121c,0x12a0) - 0xae4];
    struct BattleTask020dbf18 task;
};

static inline SafeAllocator* inline_ov000_02166804(GameResources* arg0, int arg1) {
    return &arg0->allocator_array_38[arg1];
}

// USA: func_ov006_02155e28
extern "C" ARM void func_ov006_02155e28(struct Struct_ov006_02155e28_4* arg0) {
    BackgroundLoader* var0 = BackgroundLoader::GetInstance();
    unsigned char var1 = arg0->unknown_add_;

    if (state == 0) {
        SpriteContext_Init((char*)&self->records);
        self->records.count = 0;
        self->records.owner = self->field1e0;
        self->records.capacity = 0x11;
        self->taskId = loader->QueueLoadFile(data_ov006_021600af, NULL);
        self->state++;
    } else if (state == 1) {
        if (loader->GetTaskStatus(self->taskId) == 0) return;
        void* rec;
        void* data;
        unsigned int size;
        int recSize;
        loader->GetLoadedFileByID(self->taskId, &data, &size);
        int count = Pac_CountFiles((struct PacRecord*)data);
        SafeAllocator* alloc = self->allocs;
        alloc->Reset();
        for (int i = 0; i < count; i++) {
            void* found = Pac_GetFile((struct PacRecord*)data, i, &rec, &recSize);
            if (found != NULL) {
                SpriteContext_LoadFile(&self->records, found, recSize, alloc);
            }
        }
        loader->RemoveTask(self->taskId);
        self->taskId = -1;
        self->state++;
    } else if (state == 2) {
        volatile unsigned short* bg = (volatile unsigned short*)0x400000a;
        bg[0] = (bg[0] & 0x43) | 0x1d00;
        bg[1] = (bg[1] & 0x43) | 0x1e00;
        bg[2] = (bg[2] & 0x43) | 0x1f08;
        SafeAllocator* alloc = &self->allocs[2];
        alloc->Reset();
        struct Bytes3_0215ff54 priority = data_ov006_0215ff54;
        for (unsigned char i = 0; i < 2; i++) {
            struct BackgroundGraphics* list = &self->lists[i];
            Background_Init(list);
            list->subScreen_ = 0;
            list->bgNumber_ = i + 1;
            Background_SetMapSize((unsigned char*)list, 0);
            Background_SetPriority(list, priority.v[i]);
            Background_AllocateMap((struct BackgroundGraphics*)list, alloc);
            Background_SetScroll((struct BackgroundGraphics*)list, 0, 0);
        }
        Background_ClearMap((struct BackgroundGraphics*)&self->lists[0], NULL);
        Background_ClearMap((struct BackgroundGraphics*)&self->lists[1], NULL);
        SafeAllocator* nodeAlloc = self->allocs;
        nodeAlloc[3].Reset();
        for (unsigned char j = 0; j < 1; j++) {
            struct WindowPane* node = &self->nodes[j];
            WindowPane_Init(node);
            WindowPane_AllocateBuffer(node, &nodeAlloc[3], self->field1a4, 0x1c0);
            node->layer_ = self->lists;
        }
        self->taskId = loader->QueueLoadFile(data_ov006_021600c4, NULL);
        self->state++;
    } else if (state == 3) {
        if (loader->GetTaskStatus(self->taskId) == 0) return;
        void* rec;
        void* data;
        unsigned int size;
        int recSize;
        loader->GetLoadedFileByID(self->taskId, &data, &size);
        int count = Pac_CountFiles((struct PacRecord*)data);
        SafeAllocator* alloc = self->allocs;
        for (int i = 0; i < count; i++) {
            void* found = Pac_GetFile((struct PacRecord*)data, i, &rec, &recSize);
            if (found != NULL) {
                Background_LoadFile(self->lists, found, &alloc[2], recSize);
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
    } else if (state == 8) {
        int chapter = (signed char)GetProgress(Zone3D_GetInstance())->chapter;
        char path[0x20];
        __clear(path, 0x20);
        if (chapter < 1) {
            chapter = 1;
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
            VramState_Rewind((struct Foo0207df50*)res->vramStates_);
            VramState_Restore(res->vramStates_);
            ObjectArchiveLoadInfo info;
            info.fileData = data;
            info.fileSize = size;
            info.allocator = alloc;
            info.unk_10 = 1;
            self->objs[0].LoadFromCHRArchive(&info);
            self->objs[0].SetAnimationByIndex(0, 0);
            VramState_Save(res->vramStates_);
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
            VramState_Restore(res->vramStates_);
            ObjectArchiveLoadInfo info;
            info.fileData = data;
            info.fileSize = size;
            info.allocator = alloc;
            info.unk_10 = 1;
            self->objs[1].LoadFromCCHROrCMOTArchive(&info, NULL);
            self->objs[1].SetAnimationByIndex(0, 0);
            VramState_Save(res->vramStates_);
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
            VramState_Restore(res->vramStates_);
            ObjectArchiveLoadInfo info;
            info.fileData = data;
            info.fileSize = size;
            info.allocator = alloc;
            info.unk_10 = 1;
            self->objs[2].LoadFromCCHROrCMOTArchive(&info, NULL);
            self->objs[2].SetAnimationByIndex(0, 0);
            VramState_Save(res->vramStates_);
            self->objs[2].SetScale(0x10a, 0x10a, 0x10a);
            CopyVec3ToField0x44((struct Target02059f38*)&self->objs[2], (struct Vec3_02059f38*)&self->objs[1].position_);
        }
        loader->RemoveTask(self->taskId);
        self->taskId = -1;
        self->state++;
    } else if (state == 14) {
        self->taskId = loader->QueueLoadFile(data_ov006_02160156, NULL);
        self->state++;
    } else if (state == 15) {
        if (loader->GetTaskStatus(self->taskId) == 0) return;
        GameResources* res = GetGameResources();
        self->modelAlloc.CreateTypeA(res->allocator_array_38[0].Allocate(0x8000), 0x8000);
        self->modelAlloc.Reset();
        VramState_Restore(res->vramStates_);
        void* data;
        unsigned int size;
        loader->GetLoadedFileByID(self->taskId, &data, &size);
        if (data != NULL && self->modelAlloc.GetSignedAllocator() != NULL) {
            self->objs[3].Initialize();
            ObjectArchiveLoadInfo info;
            info.fileData = data;
            info.fileSize = size;
            info.allocator = &self->modelAlloc;
            info.unk_10 = 1;
            self->objs[3].LoadFromCHRArchive(&info);
            self->objs[3].SetScale(&self->objs[1].GetScale());
            CopyVec3ToField0x44((struct Target02059f38*)&self->objs[3], (struct Vec3_02059f38*)&self->objs[1].position_);
            self->objs[3].StopCurrentAnimation();
        }
        VramState_Save(res->vramStates_);
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
            VramState_Restore(res->vramStates_);
            ObjectArchiveLoadInfo info;
            info.fileData = data;
            info.fileSize = size;
            info.allocator = alloc;
            info.unk_10 = 1;
            Object3D* obj = &self->objs[4];
            obj->LoadFromCCHROrCMOTArchive(&info, NULL);
            obj->SetAnimationByIndex(0, 0);
            VramState_Save(res->vramStates_);
            obj->SetScale(0x10a, 0x10a, 0x10a);
            CopyVec3ToField0x44((struct Target02059f38*)obj, (struct Vec3_02059f38*)&self->objs[1].position_);
            obj->StopCurrentAnimation();
            obj->SetAnimationByName(data_ov006_02160080, 9);
            obj->DisableFlag(0x1000);
            for (int i = 0; i < 3; i++) {
                data_ov006_02160380[i] = -1;
            }
            Model3D* model = self->objs[4].pModel_;
            if (model != NULL) {
                data_ov006_02160380_dup[0] = model->GetBoneIndex(data_ov006_0216018b);
                data_ov006_02160380_dup[1] = model->GetBoneIndex(data_ov006_02160190);
                data_ov006_02160380_dup[2] = model->GetBoneIndex(data_ov006_02160195);
                ModelRenderContext* context;
                if (!model->loaded_) {
                    context = NULL;
                } else {
                    var66 = &var65->renderContext_;
                }
                if (var66 != NULL) {
                    SetModelRenderContextRenderCommandHook(var66, (void (*)(RenderCommandHandler*))func_ov006_0215426c, 0, 6, 3);
                }
            }
        }
        loader->RemoveTask(self->taskId);
        self->taskId = -1;
        self->state++;
    } else if (state == 18) {
        self->objs[1].StopCurrentAnimation();
        self->objs[2].StopCurrentAnimation();
        self->objs[1].SetAnimationByIndex(0, 0);
        self->objs[2].SetAnimationByIndex(0, 0);
        GameState* gs = GameState::GetInstance();
        self->field1a0 = GetFieldIfFlag4_020100f8((char*)gs);
        InitCombatEntry021542f4(self->entry);
        GameState_SetCamera(gs, (int)self->entry);
        struct Manager0207f7f0* mgr = self->mgr;
        mgr->lists = self->lists;
        mgr->mode = 2;
        InitNodeChain0207f7f0(self->mgr, (struct Node0207f7f0*)self->nodes, 1);
        self->mgr->active = 1;
        volatile unsigned int* dispcnt = (volatile unsigned int*)0x4000000;
        *dispcnt = (*dispcnt & ~0x1f00) | 0x1f00;
        ColorEffect_ConfigureAlphaBlend((unsigned int*)0x4000050, 4, 1, 10, 6);
        self->flags = self->flags | 0x1000;
        self->flags = self->flags & ~0x40;
        GameResources* res = gs->GetResources();
        BeginTask020dbf18(&self->task, (int)data_ov006_0216019a, (int)&self->allocs[5],
                          (int)res->vramStates_, 0x18);
        self->state++;
    } else if (state == 19) {
        if (self->task.status == 2) {
            self->result = 1;
            self->state = 0;
        }
    }
}
