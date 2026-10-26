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

extern "C" void __clear(void* dst, int size);
extern "C" int sprintf(char* dst, const char* fmt, ...);

extern "C" void SpriteContext_Init(char* obj);
struct PacRecord;
extern "C" int Pac_CountFiles(struct PacRecord* data);
extern "C" void* Pac_GetFile(struct PacRecord* data, int index, void** outRec, int* outSize);
extern "C" void SpriteContext_LoadFile(void* a, void* ptr, int val, void* d);

extern "C" void Background_Init(struct BackgroundGraphics* list);
extern "C" void Background_SetMapSize(unsigned char* list, int value);
extern "C" void Background_SetPriority(void* list, int priority);
struct BackgroundGraphics;
extern "C" void Background_AllocateMap(struct BackgroundGraphics* list, SafeAllocator* alloc);
extern "C" void Background_SetScroll(struct BackgroundGraphics* list, int a, int b);
extern "C" void Background_ClearMap(struct BackgroundGraphics* list, void* buffer);
extern "C" void Background_LoadFile(void* list, void* data, void* alloc, int size);

extern "C" void WindowPane_Init(void* node);
extern "C" void WindowPane_AllocateBuffer(struct WindowPane* node, SafeAllocator* alloc, int a, unsigned int size);

struct Node0207f7f0;
struct Struct_0207f914;
#if defined(jpn)
extern "C" void func_0207f914(struct Struct_0207f914* mgr, int alloc, int nameA);
#else
extern "C" void func_0207f914(struct Struct_0207f914* mgr, int alloc, int nameA, int nameB);
#endif
extern "C" int func_0207f9f4(void* mgr);
extern "C" void func_0207f7f0(struct Manager0207f7f0* mgr, struct Node0207f7f0* nodes, int count);

struct Struct_ov006_02155e28 {
    short id;
    unsigned char pad2[0x14];
    unsigned char enabled : 1;
    unsigned char unknown_17_;
};
struct Struct_ov006_02155e28_2 {
    unsigned char pad0[8];
    struct Struct_ov006_02155e28* entries;
    unsigned char unknown_c_[8];
    unsigned short count;
};
extern "C" void func_ov023_021e20c0(void* table);
extern "C" void func_ov023_021e20f0(void* table, void* alloc, void* data, unsigned int size);

struct Progress02012fe4 {
    unsigned char pad0[0xb3c];
    int chapter;
};
extern "C" void* Zone3D_GetInstance(void);
static inline struct Progress02012fe4* GetProgress(void* run) {
    return (struct Progress02012fe4*)((char*)run + R(0x1860,0x1840));
}

extern "C" int GameState_GetFollowCamera(char* gs);
extern "C" void GameState_SetCamera(GameState* gs, int value);
struct Foo0207df50;
extern "C" void VramState_Rewind(struct Foo0207df50* p);
extern "C" void VramState_Restore(char* obj);
extern "C" void VramState_Save(char* obj);
struct Fields020407b4;
extern "C" void func_020407b4(struct Fields020407b4* dst, int a, int b, int c);
struct Struct_02059cfc_2;
struct Struct_02059cfc_3;
extern "C" void func_02059f38(struct Struct_02059cfc_2* dst, struct Struct_02059cfc_3* src);
extern "C" void func_ov006_021542f4(void* entry);
struct Struct_ov006_0215426c;
extern "C" void func_ov006_0215426c(struct Struct_ov006_0215426c* obj);
void SetModelRenderContextRenderCommandHook(ModelRenderContext* context, void (*hook)(RenderCommandHandler*), int a, int b, int c);
extern "C" void ColorEffect_ConfigureAlphaBlend(unsigned int* reg, int planeA, int planeB, int evA, int evB);
struct Struct_020dbf18 {
    unsigned char pad0[0x10];
    int status;
};
extern "C" void func_020dbf18(struct Struct_020dbf18* task, int name, int alloc, int tables, int count);

struct Struct_ov006_0215ff54 { unsigned char v[3]; };
struct Struct_ov006_0215ff64 { signed char v[8]; };

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
    unsigned char pad0[0x40];
    int owner;
    unsigned char unknown_44_[8];
    short capacity;
    unsigned char unknown_4e_[2];
    unsigned char count;
    unsigned char unknown_51_[3];
};

struct Struct_ov006_02155e28_4 {
#if !defined(jpn)
    unsigned char pad0[0x180];
#endif
    SafeAllocator* allocs;
    unsigned char unknown_184_[8];
    SafeAllocator unknown_18c_;
    int field1a0;
    int field1a4;
    unsigned char unknown_1a8_[0x20];
    struct Struct_ov006_02155e28_2* table;
    struct BackgroundGraphics* lists;
    struct WindowPane* nodes;
    struct Manager0207f7f0* mgr;
    unsigned char unknown_1d8_[8];
    int unknown_1e0_;
    struct Struct_ov006_02155e28_3 records;
    Object3D objs[5];
    unsigned char unknown_594_[0x5cc - 0x594];
    unsigned char entry[0xad4 - 0x5cc];
    int taskId;
    int unknown_ad8_;
    unsigned char result;
    unsigned char state;
    unsigned char unknown_ade_[4];
    unsigned short flags;
    unsigned char unknown_ae4_[R(0x121c,0x12a0) - 0xae4];
    struct Struct_020dbf18 task;
};

static inline SafeAllocator* inline_ov000_02166804(GameResources* res, int index) {
    return &res->allocator_array_38[index];
}

// USA: func_ov006_02155e28
extern "C" ARM void func_ov006_02155e28(struct Struct_ov006_02155e28_4* self) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    unsigned char state = self->state;

    if (state == 0) {
        SpriteContext_Init((char*)&self->records);
        self->records.count = 0;
        self->records.owner = self->unknown_1e0_;
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
        struct Struct_ov006_0215ff54 priority = data_ov006_0215ff54;
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
        loader->RemoveTask(self->taskId);
        self->taskId = -1;
        self->state++;
        self->flags |= 1;
    } else if (state == 4) {
        volatile unsigned short* bg = (volatile unsigned short*)0x4000008;
        bg[0] = (bg[0] & ~3) | 2;
        bg[1] = (bg[1] & ~3) | 0;
        bg[2] = (bg[2] & ~3) | 1;
        bg[3] = (bg[3] & ~3) | 3;
        SafeAllocator* alloc = self->allocs;
        alloc[4].Reset();
        func_0207f84c(self->mgr);
        func_0207f914((struct Struct_0207f914*)self->mgr, (int)&alloc[4],
#if defined(jpn)
                                            (int)data_ov006_021600d7);
#else
                                            (int)data_ov006_021600d7, (int)data_ov006_021600f0);
#endif
        self->state++;
    } else if (state == 5) {
        int r = func_0207f9f4(self->mgr);
        if (r == 0) {
            self->state++;
        }
        if (r < 0) {
            self->result = 2;
        }
    } else if (state == 6) {
        self->taskId = loader->QueueLoadFile(data_ov006_021600f7, NULL);
        self->state++;
    } else if (state == 7) {
        if (loader->GetTaskStatus(self->taskId) == 0) return;
        void* data;
        unsigned int size;
        loader->GetLoadedFileByID(self->taskId, &data, &size);
        if (data != NULL) {
            SafeAllocator* alloc = self->allocs;
            alloc[1].Reset();
            func_ov023_021e20c0(self->table);
            func_ov023_021e20f0(self->table, &alloc[1], data, size);
            struct Struct_ov006_02155e28* entry;
            struct Struct_ov006_02155e28* arr = self->table->entries;
            if (arr == NULL) {
                entry = NULL;
            } else {
                unsigned short var34 = self->table->count;
                if (var34 == 0) {
                    entry = NULL;
                } else {
                    for (unsigned short k = 0; k < var34; k++) {
                        entry = &arr[k];
                        if (entry->id == 1) {
                            goto found;
                        }
                    }
                    entry = NULL;
                }
            }
        found:
            if (entry != NULL) {
                entry->enabled = 0;
            }
        }
        loader->RemoveTask(self->taskId);
        self->taskId = -1;
        self->state++;
        if (self->flags & 8) {
            self->state = 0x12;
        }
    } else if (state == 8) {
        int chapter = (signed char)GetProgress(Zone3D_GetInstance())->chapter;
        char path[0x20];
        __clear(path, 0x20);
        if (chapter < 1) {
            chapter = 1;
        }
        if (chapter > 6) {
            chapter = 6;
        }
        struct Struct_ov006_0215ff64 var38 = data_ov006_0215ff64;
        sprintf(path, data_ov006_0216010b, var38.v[chapter]);
        self->taskId = loader->QueueLoadFile(path, NULL);
        self->state++;
    } else if (state == 9) {
        if (loader->GetTaskStatus(self->taskId) == 0) return;
        void* data;
        unsigned int size;
        loader->GetLoadedFileByID(self->taskId, &data, &size);
        if (data != NULL) {
            GameResources* res = GameState::GetInstance()->GetResources();
            SafeAllocator* alloc = inline_ov000_02166804(res, 0);
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
            func_020407b4((struct Fields020407b4*)&self->objs[0], -0x3800, -0xb3b, 0x60a3);
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
            SafeAllocator* alloc = inline_ov000_02166804(res, 0);
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
            func_020407b4((struct Fields020407b4*)&self->objs[1], -0x41, -0xaac, 0x61f3);
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
            SafeAllocator* alloc = inline_ov000_02166804(res, 0);
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
            func_02059f38((struct Struct_02059cfc_2*)&self->objs[2], (struct Struct_02059cfc_3*)&self->objs[1].position_);
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
        self->unknown_18c_.CreateTypeA(res->allocator_array_38[0].Allocate(0x8000), 0x8000);
        self->unknown_18c_.Reset();
        VramState_Restore(res->vramStates_);
        void* data;
        unsigned int size;
        loader->GetLoadedFileByID(self->taskId, &data, &size);
        if (data != NULL && self->unknown_18c_.GetSignedAllocator() != NULL) {
            self->objs[3].Initialize();
            ObjectArchiveLoadInfo info;
            info.fileData = data;
            info.fileSize = size;
            info.allocator = &self->unknown_18c_;
            info.unk_10 = 1;
            self->objs[3].LoadFromCHRArchive(&info);
            self->objs[3].SetScale(&self->objs[1].GetScale());
            func_02059f38((struct Struct_02059cfc_2*)&self->objs[3], (struct Struct_02059cfc_3*)&self->objs[1].position_);
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
            SafeAllocator* alloc = inline_ov000_02166804(res, 0);
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
            func_02059f38((struct Struct_02059cfc_2*)obj, (struct Struct_02059cfc_3*)&self->objs[1].position_);
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
                    context = &model->renderContext_;
                }
                if (context != NULL) {
                    SetModelRenderContextRenderCommandHook(context, (void (*)(RenderCommandHandler*))func_ov006_0215426c, 0, 6, 3);
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
        self->field1a0 = GameState_GetFollowCamera((char*)gs);
        func_ov006_021542f4(self->entry);
        GameState_SetCamera(gs, (int)self->entry);
        struct Manager0207f7f0* mgr = self->mgr;
        mgr->lists = self->lists;
        mgr->mode = 2;
        func_0207f7f0(self->mgr, (struct Node0207f7f0*)self->nodes, 1);
        self->mgr->active = 1;
        volatile unsigned int* dispcnt = (volatile unsigned int*)0x4000000;
        *dispcnt = (*dispcnt & ~0x1f00) | 0x1f00;
        ColorEffect_ConfigureAlphaBlend((unsigned int*)0x4000050, 4, 1, 10, 6);
        self->flags = self->flags | 0x1000;
        self->flags = self->flags & ~0x40;
        GameResources* res = gs->GetResources();
        func_020dbf18(&self->task, (int)data_ov006_0216019a, (int)&self->allocs[5],
                          (int)res->vramStates_, 0x18);
        self->state++;
    } else if (state == 19) {
        if (self->task.status == 2) {
            self->result = 1;
            self->state = 0;
        }
    }
}
