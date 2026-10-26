#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"
#include "Memory/SafeAllocator.h"
#include "Resource/Brightness.h"

struct PairTables021539d8 {
    char storage[0x70];
};

struct Struct_ov001_021539d8_8 {
    int unused0;
    void* data;
    unsigned int size;
    SafeAllocator* allocator;
    int flag;
    int unknown_14_;
    int pad18;
    int mode;
};

struct Struct_ov001_021539d8_9 {
    unsigned int flag : 1;
};

struct Struct_ov001_021539d8_10 {
    char pad0[0x54];
    NSBXXInternalModel* model;
};

struct Obj021539d8 {
    unsigned short flags;
    char pad2[6];
    struct Struct_ov001_021539d8_10* holder;
    struct Struct_ov001_021539d8_9* state;
    char pad10[0x34];
    int posX;
    int unknown_48_;
    int unknown_4c_;
    char unknown_50_[0x84];
    unsigned char active : 1;
    char unknown_d5_[0x5b];
    unsigned int* status;
};

struct Stream021539d8 {
    int owner;
    char pad4[0x4c];
    unsigned int flags;
};

struct Struct_ov001_021539d8 {
    unsigned int flags;
    int unk4;
    void* name;
    void* record;
    int unk10;
    struct Stream021539d8* stream;
    struct Obj021539d8* object;
    int unknown_1c_;
};

struct Struct_ov001_021539d8_2 {
    char pad0[2];
    unsigned char kind;
#if defined(jpn)
    char pad3[0xd];
#else
    char pad3;
#endif
    char text[0x10];
};

struct Struct_ov001_021539d8_3 {
    unsigned char type : 4;
    unsigned char unused : 4;
    unsigned char index;
    short slot;
    unsigned char flags;
    char pad5[3];
    union {
        int key;
        char name[0x24];
    };
    int task;
    unsigned char kind;
    unsigned char done;
    char unknown_32_[2];
    struct Struct_ov001_021539d8_3* next;
};

struct Struct_ov001_021539d8_4 {
    unsigned char index;
    char pad1[0x23];
    int task;
    struct Struct_ov001_021539d8_4* next;
    unsigned char pending;
};

struct Struct_ov001_021539d8_5 {
    char pad0[0x98];
    unsigned int flags;
};

struct Struct_ov001_021539d8_6 {
    char pad0[0x50];
    unsigned short flags;
#if defined(jpn)
    char unknown_52_[0x7a];
#else
    char unknown1_52_[0x7e];
#endif
    struct Struct_ov001_021539d8_3* unknown_d0_;
    struct Struct_ov001_021539d8_4* unknown_d4_;
    char unknown_d8_[0x1c];
    int task;
    unsigned int mode : 27;
};

#if defined(jpn)
#define data_ov001_02164bb0 data_ov001_02166150
#define data_ov001_02164bb6 data_ov001_02166156
#define data_ov001_02164bc0 data_ov001_02166160
#define data_ov001_02164bc5 data_ov001_02166165
#define data_ov001_02164bc8 data_ov001_02166168
#define data_ov001_02164bcb data_ov001_0216616b
#define PAIR_TABLES_021539d8 0x27c
#else
#define PAIR_TABLES_021539d8 0x2cc
#endif
extern char data_ov001_02164bb0[];
extern char data_ov001_02164bb6[];
extern char data_ov001_02164bc0[];
extern char data_ov001_02164bc5[];
extern char data_ov001_02164bc8[];
extern char data_ov001_02164bcb[];

extern "C" {
extern "C" struct Struct_ov001_021539d8_5* func_0203cf4c(void);

void* LinkSession_GetInstance(void);
int LinkSession_IsHostOrSolo(void* obj);
extern "C" unsigned char GameState_GetLeaderIndex(GameState* gs);
extern "C" int GameState_GetProtagonistIndex(GameState* gs);
extern "C" void VramState_Rewind(struct PairTables021539d8* p);
extern "C" void VramState_Restore(struct PairTables021539d8* p);
extern "C" void VramState_Save(struct PairTables021539d8* p);
void func_ov001_0215ab54(int kind, int id, int index);
extern "C" struct Struct_ov001_021539d8* func_0203df78(void* list, int key);
extern "C" int func_0203dfdc(void* list, int key);
extern "C" void func_0200fd38(GameState* gs, int id, struct Obj021539d8* obj);
extern "C" SafeAllocator* func_ov001_0215aab8(void);
void _ZN8Object3D10InitializeEv(struct Obj021539d8* obj);
void _ZN8Object3D11MakeVisibleEv(struct Obj021539d8* obj);
void _ZN8Object3D10MakeHiddenEv(struct Obj021539d8* obj);
void _ZN8Object3D10EnableFlagEi(struct Obj021539d8* obj, int mask);
void _ZN8Object3D18LoadFromCHRArchiveEP21ObjectArchiveLoadInfo(struct Obj021539d8* obj, struct Struct_ov001_021539d8_8* info);
void _ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(struct Obj021539d8* obj, struct Struct_ov001_021539d8_8* info, void* callback);
void _ZN8Object3D8SetScaleEiii(struct Obj021539d8* obj, int x, int y, int z);
void _ZN8Object3D19SetAnimationByIndexEii(struct Obj021539d8* obj, int a, int b);
void _ZN8Object3D16SetModelFromFileEP13SafeAllocatorPvjN7Model3D18TextureStagingModeE(struct Obj021539d8* obj, SafeAllocator* allocator, void* data, unsigned int size, int mode);
void Zone3D_GetInstance(void);
extern "C" void func_020404c0(struct Struct_ov001_021539d8* arg0);
extern "C" void func_0206bf2c(void* record);
extern "C" void NpcWalker_Init(struct Stream021539d8* stream);
char* strstr(const char* text, const char* arg1);
void* memcpy(void* dst, const void* src, unsigned int size);
int sprintf(char* dst, const char* format, ...);
extern "C" void func_02040530(struct Struct_ov001_021539d8* arg0, void* record);
extern "C" void func_02040520(struct Struct_ov001_021539d8* arg0, struct Struct_ov001_021539d8_2* label);
extern "C" void func_0203f02c(struct Stream021539d8* stream, char* name, SafeAllocator* allocator, struct PairTables021539d8* pair, void* data, unsigned int size);
void func_0203f138(struct Stream021539d8* stream, int enabled);
extern "C" void func_020408c8(struct Struct_ov001_021539d8* arg0, int a, int b, int c);
extern "C" int func_0203e03c(void* list);
extern "C" void func_0203dd10(void* list, int index, struct Struct_ov001_021539d8* arg2);
int _Z26FindFilesInNarcBySubstringPKvPKcPS0_Pjj(void* narc, const char* text, void** arg2, unsigned int* outSize, unsigned int count);
void* _Z36DecompressLZ77FileIntoAllocatedSpaceR13SafeAllocatorPKvRj(SafeAllocator* allocator, void* file, unsigned int* outSize);
void NSBXX_Model_SetPolygonID(NSBXXInternalModel* model, int id);
void __clear(unsigned char* flags, int count);
}

extern "C" int func_0203d004(void* list);

static inline void inline_ov001_021539d8(struct Struct_ov001_021539d8* arg0, char* name, SafeAllocator* allocator,
                                        struct PairTables021539d8* pair, void* data, unsigned int size) {
    if (arg0->stream != 0) {
        func_0203f02c(arg0->stream, name, allocator, pair, data, size);
    }
}

static inline void inline_ov001_021539d8_2(struct Struct_ov001_021539d8* arg0, int enabled) {
    if (arg0->stream != 0) {
        func_0203f138(arg0->stream, enabled);
    }
}

// USA: func_ov001_021539d8
extern "C" ARM void func_ov001_021539d8(struct Struct_ov001_021539d8_6* self) {
    GameState* gs = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    struct Struct_ov001_021539d8_5* global = func_0203cf4c();
    char* base = (char*)GetGameResources();
    void* search = LinkSession_GetInstance();
    struct Struct_ov001_021539d8_3* node;
    struct Struct_ov001_021539d8_4* motion;
    bool copied;
    LightingManager* lighting;
    unsigned int var9;
    unsigned char* var10;
    unsigned char var11;
    unsigned char var12;
    unsigned char var13;
    SafeAllocator* pool;
    void* record;
    unsigned char length;
    NSBXXMesh* mesh;
    NSBXXInternalModel* model;
    struct Struct_ov001_021539d8* var19;
    struct Struct_ov001_021539d8_2* label;
    struct PairTables021539d8* pair;

    for (node = self->unknown_d0_; node != 0; node = node->next) {
        if (node->type == 1) {
            if (LinkSession_IsHostOrSolo(search) == 0 || !(self->mode & 0x10)) {
                int current = GameState_GetLeaderIndex(gs);
                if (current != 0) {
                    struct Struct_ov001_021539d8_3* other;
                    for (other = self->unknown_d0_; other != 0; other = other->next) {
                        if (other->type >= 0xb && other->type <= 0xd && other->slot == current) {
                            other->slot = 0;
                            other->unused = 0;
                            break;
                        }
                    }
                }
            }
            break;
        }
    }

    copied = false;
    node = self->unknown_d0_;
    while (node != 0) {

        if (node->done != 0) {
            node = node->next;
            continue;
        }

        pair = &((struct PairTables021539d8*)(base + PAIR_TABLES_021539d8))[27];
        if (node->kind == 1) {
            pair = &((struct PairTables021539d8*)(base + PAIR_TABLES_021539d8))[7];
            if (!copied) {
                if ((self->flags & 4) || (self->flags & 1)) {
                    VramState_Rewind(pair);
                    copied = true;
                }
            }
        }

        switch (node->type) {
        case 0: {
            struct Obj021539d8* obj = (struct Obj021539d8*)gs->GetPartyMemberByIndex(0);
            if (obj == 0) {
                break;
            }
            if ((self->mode & 0x10) || !(*obj->status & 1)) {
                func_ov001_0215ab54(4, 0, node->index);
            } else if (LinkSession_IsHostOrSolo(search) != 0) {
                func_ov001_0215ab54(5, GameState_GetLeaderIndex(gs), node->index);
            } else {
                int current = GameState_GetProtagonistIndex(gs);
                int i;
                for (i = 3; i > 0; i--) {
                    if (current != i) {
                        obj = (struct Obj021539d8*)gs->GetPartyMemberByIndex(i);
                        if (obj != 0 && (obj->flags & 0x1000) && !(*obj->status & 1)) {
                            func_ov001_0215ab54(5, i, node->index);
                            break;
                        }
                    }
                }
                if (i == 0) {
                    break;
                }
            }
            _ZN8Object3D11MakeVisibleEv(obj);
            break;
        }
        case 1:
            func_ov001_0215ab54(5, GameState_GetLeaderIndex(gs), node->index);
            break;
        case 9:
        case 11:
        case 12:
        case 13:
            func_ov001_0215ab54(5, node->slot, node->index);
            break;
        case 10:
            func_ov001_0215ab54(1, node->slot, node->index);
            break;
        case 4: {
            struct Struct_ov001_021539d8* var27 = func_0203df78(global, node->key);
            if (var27 != 0 && var27->object != 0) {
                var27->object->active = 1;
                func_0200fd38(gs, node->slot, var27->object);
                var27->flags |= 0x10000;
                func_ov001_0215ab54(6, func_0203dfdc(global, node->key), node->index);
            }
            break;
        }
        case 2: {
            char name[0x50];
            struct Struct_ov001_021539d8_8 info;
            void* data;
            unsigned int size;
            int format;
            SafeAllocator* allocator;

            if (loader->GetDetailedTaskStatus(node->task) != 2) {
                loader->RemoveTask(node->task);
                break;
            }
            format = 0;
            if (loader->GetTaskFilename(node->task, name)) {
                if (strstr(name, data_ov001_02164bb0) != 0 || strstr(name, data_ov001_02164bb6) != 0) {
                    format = 1;
                }
            }
            allocator = func_ov001_0215aab8();
            loader->GetLoadedFileByID(node->task, &data, &size);
            struct Obj021539d8* obj = (struct Obj021539d8*)allocator->Allocate(0xac);
            if (obj == 0) {
                loader->RemoveTask(node->task);
                break;
            }
            VramState_Restore(pair);
            _ZN8Object3D10InitializeEv(obj);
            info.allocator = allocator;
            info.data = data;
            info.size = size;
            info.flag = 1;
            if (format == 0) {
                _ZN8Object3D18LoadFromCHRArchiveEP21ObjectArchiveLoadInfo(obj, &info);
            } else if (format == 1) {
                _ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(obj, &info, 0);
            }
            VramState_Save(pair);
            _ZN8Object3D8SetScaleEiii(obj, 0x10a, 0x10a, 0x10a);
            _ZN8Object3D19SetAnimationByIndexEii(obj, 0, 0);
            func_0200fd38(gs, node->slot, obj);
            if (node->flags & 1) {
                Zone3D_GetInstance();
                lighting = LightingManager::GetInstance();
                model = obj->holder->model;
                NSBXXNameList* var35 = model->GetMeshListSafe();
                unsigned int var36;
                unsigned int* var37;
                int var38;

                for (var9 = 0; var9 < model->numMeshes_; var9++) {
                    unsigned char var39;
                    void* var40;

                    if (var35 != NULL && (var40 = var35->GetEntryv3Safe(var9)))
                        mesh = (NSBXXMesh*)var35->GetEntryFromPtrOffset(var40);
                    else
                        mesh = NULL;

                    if (!(mesh->unk_4 & 2))
                        continue;

                    var10 = (unsigned char*)mesh + mesh->gpuCommandsOffset_;
                    var36 = 0;
                    while (var36 < mesh->gpuCommandsLength_) {
                        var39 = var10[var36];
                        var11 = var10[var36 + 1];
                        var12 = var10[var36 + 2];
                        var13 = var10[var36 + 3];
                        var36 += 4;

                        int var41 = 0;
                        var37 = (unsigned int*)(var10 + var36);

                        var38 = 0;

                        if (lighting->GetFifoCommandData(var39, &var41))
                            var37[var38] = lighting->ColorTransformTintBrightnessContrast(var37[var38]);
                        var38 += var41;

                        if (lighting->GetFifoCommandData(var11, &var41))
                            var37[var38] = lighting->ColorTransformTintBrightnessContrast(var37[var38]);
                        var38 += var41;

                        if (lighting->GetFifoCommandData(var12, &var41))
                            var37[var38] = lighting->ColorTransformTintBrightnessContrast(var37[var38]);
                        var38 += var41;

                        if (lighting->GetFifoCommandData(var13, &var41))
                            var37[var38] = lighting->ColorTransformTintBrightnessContrast(var37[var38]);
                        var38 += var41;

                        var36 += 4 * var38;
                    }
                }
            }
            func_ov001_0215ab54(1, node->slot, node->index);
            loader->RemoveTask(node->task);
            node->done = 1;
            break;
        }
        case 5: {
            struct Struct_ov001_021539d8* var42 = func_0203df78(global, node->key);
            if (var42 != 0 && var42->stream != 0) {
                var42->flags |= 0x10000;
                func_ov001_0215ab54(2, func_0203dfdc(global, node->key), node->index);
            }
            break;
        }
        case 3: {
            void* data;
            unsigned int size;
            int owner;
            struct Stream021539d8* stream;

            if (loader->GetDetailedTaskStatus(node->task) != 2) {
                loader->RemoveTask(node->task);
                break;
            }
            pool = func_ov001_0215aab8();
            loader->GetLoadedFileByID(node->task, &data, &size);
            var19 = (struct Struct_ov001_021539d8*)pool->Allocate(0x20);
            record = pool->Allocate(0x78);
            label = (struct Struct_ov001_021539d8_2*)pool->Allocate(sizeof(struct Struct_ov001_021539d8_2));
            stream = (struct Stream021539d8*)pool->Allocate(0x9c);
            if (var19 == 0 || label == 0 || record == 0 || stream == 0) {
                loader->RemoveTask(node->task);
                break;
            }
            func_020404c0(var19);
            func_0206bf2c(record);
            NpcWalker_Init(stream);
            label->kind = 3;
            if (strstr(node->name, data_ov001_02164bc0) != 0) {
                length = 5;
                if (strstr(node->name, data_ov001_02164bc5) != 0) {
                    length = 7;
                    stream->flags |= 8;
                }
                memcpy(label->text, node->name + 9, length);
                if (length < 7u) {
                    label->text[length] = 0;
                }
            } else {
                sprintf(label->text, data_ov001_02164bc8, node->name);
            }
            var19->stream = stream;
            func_02040530(var19, record);
            func_02040520(var19, label);
            owner = func_0203d004(global);
            if (var19->stream != 0) {
                var19->stream->owner = owner;
            }
            inline_ov001_021539d8(var19, node->name + 9, pool, pair, data, size);
            inline_ov001_021539d8_2(var19, 1);
            func_020408c8(var19, 0x8f, 0x8f, 0x8f);
            node->slot = func_0203e03c(global);
            if (node->slot != -1) {
                func_0203dd10(global, node->slot, var19);
                var19->flags |= 0x10000;
                func_ov001_0215ab54(2, node->slot, node->index);
                loader->RemoveTask(node->task);
                node->done = 1;
            }
            break;
        }
        case 6: {
            char name[0x50];
            struct Struct_ov001_021539d8_8 info;
            void* data;
            unsigned int size;
            unsigned int fileSize;
            void* file;
            unsigned int var53;
            SafeAllocator* allocator;
            struct Obj021539d8* obj;
            void* var56;
            int format;

            if (loader->GetDetailedTaskStatus(node->task) != 2) {
                loader->RemoveTask(node->task);
                break;
            }
            allocator = func_ov001_0215aab8();
            loader->GetLoadedFileByID(node->task, &data, &size);
            obj = (struct Obj021539d8*)allocator->Allocate(0xac);
            if (obj == 0) {
                loader->RemoveTask(node->task);
                break;
            }
            format = 0;
            if (loader->GetTaskFilename(node->task, name)) {
                if (strstr(name, data_ov001_02164bb0) != 0 || strstr(name, data_ov001_02164bb6) != 0) {
                    format = 1;
                }
            }
            if (_Z26FindFilesInNarcBySubstringPKvPKcPS0_Pjj(data, data_ov001_02164bcb, &file, &fileSize, 1) == 0) {
                break;
            }
            var56 = _Z36DecompressLZ77FileIntoAllocatedSpaceR13SafeAllocatorPKvRj(allocator, file, &var53);
            if (var56 == 0) {
                break;
            }
            VramState_Restore(pair);
            _ZN8Object3D10InitializeEv(obj);
            info.data = var56;
            info.allocator = allocator;
            info.size = var53;
            info.flag = 1;
            if (format == 0) {
                _ZN8Object3D18LoadFromCHRArchiveEP21ObjectArchiveLoadInfo(obj, &info);
            } else if (format == 1) {
                _ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(obj, &info, 0);
            }
            VramState_Save(pair);
            _ZN8Object3D8SetScaleEiii(obj, 0x10a, 0x10a, 0x10a);
            _ZN8Object3D19SetAnimationByIndexEii(obj, 0, 0);
            func_0200fd38(gs, node->slot, obj);
            func_ov001_0215ab54(1, node->slot, node->index);
            loader->RemoveTask(node->task);
            node->done = 1;
            break;
        }
        case 7: {
            void* data;
            unsigned int size;
            SafeAllocator* allocator;
            void* copy;

            if (loader->GetDetailedTaskStatus(node->task) != 2) {
                loader->RemoveTask(node->task);
                break;
            }
            allocator = func_ov001_0215aab8();
            loader->GetLoadedFileByID(node->task, &data, &size);
            struct Obj021539d8* obj = (struct Obj021539d8*)allocator->Allocate(0xac);
            if (obj == 0) {
                loader->RemoveTask(node->task);
                break;
            }
            copy = allocator->Allocate(size);
            memcpy(copy, data, size);
            VramState_Restore(pair);
            _ZN8Object3D10InitializeEv(obj);
            _ZN8Object3D16SetModelFromFileEP13SafeAllocatorPvjN7Model3D18TextureStagingModeE(obj, allocator, copy, size, 0);
            VramState_Save(pair);
            _ZN8Object3D8SetScaleEiii(obj, 0x10a, 0x10a, 0x10a);
            _ZN8Object3D19SetAnimationByIndexEii(obj, 0, 0);
            func_0200fd38(gs, node->slot, obj);
            func_ov001_0215ab54(1, node->slot, node->index);
            loader->RemoveTask(node->task);
            node->done = 1;
            break;
        }
        case 8: {
            struct Struct_ov001_021539d8_8 info;
            void* data;
            unsigned int size;
            SafeAllocator* allocator;

            if (loader->GetDetailedTaskStatus(node->task) != 2) {
                loader->RemoveTask(node->task);
                break;
            }
            allocator = func_ov001_0215aab8();
            loader->GetLoadedFileByID(node->task, &data, &size);
            struct Obj021539d8* obj = (struct Obj021539d8*)allocator->Allocate(0xac);
            if (obj == 0) {
                loader->RemoveTask(node->task);
                break;
            }
            VramState_Restore(pair);
            _ZN8Object3D10InitializeEv(obj);
            info.data = data;
            info.size = size;
            info.flag = 1;
            info.allocator = allocator;
            _ZN8Object3D18LoadFromCHRArchiveEP21ObjectArchiveLoadInfo(obj, &info);
            VramState_Save(pair);
            NSBXX_Model_SetPolygonID(obj->holder->model, 0x3d);
            obj->posX = 0;
            obj->unknown_48_ = -0xa000;
            obj->unknown_4c_ = 0x1000;
            _ZN8Object3D19SetAnimationByIndexEii(obj, 0, 0);
            func_0200fd38(gs, node->slot, obj);
            _ZN8Object3D10MakeHiddenEv(obj);
            func_ov001_0215ab54(1, node->slot, node->index);
            loader->RemoveTask(node->task);
            node->done = 1;
            break;
        }
        }
        node = node->next;
    }

    motion = self->unknown_d4_;
    while (motion != 0) {
        if (motion->pending != 0 || motion->task < 0) {
            motion = motion->next;
            continue;
        }
        if (loader->GetDetailedTaskStatus(motion->task) == 2) {
            struct Struct_ov001_021539d8_3* target = self->unknown_d0_;
            while (target != 0) {
                if (target->index == motion->index && target->type != 3 && target->type != 5) {
                    struct Obj021539d8* obj = (struct Obj021539d8*)gs->GetGameObjectByIndex(target->slot);
                    if (obj != 0) {
                        struct Struct_ov001_021539d8_8 info;
                        void* data;
                        unsigned int size;
                        SafeAllocator* allocator = func_ov001_0215aab8();
                        int format;

                        loader->GetLoadedFileByID(motion->task, &data, &size);
                        format = 0;
                        if (obj->state != 0) {
                            format = obj->state->flag;
                        }
                        info.allocator = allocator;
                        info.data = data;
                        info.size = size;
                        info.flag = 1;
                        info.mode = 3;
                        if (format == 0) {
                            _ZN8Object3D18LoadFromCHRArchiveEP21ObjectArchiveLoadInfo(obj, &info);
                        } else if (format == 1) {
                            _ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(obj, &info, 0);
                        }
                        _ZN8Object3D19SetAnimationByIndexEii(obj, 0, 0);
                        break;
                    }
                }
                target = target->next;
                motion->pending = 1;
            }
        }
        loader->RemoveTask(motion->task);
        motion = motion->next;
    }

    if (self->task > -1) {
        loader->GetDetailedTaskStatus(self->task);
        loader->RemoveTask(self->task);
    }

    if (self->mode != 0) {
        if (self->mode & 1) {
            SetFlags04((GameResources*)base, 8);
        }
        if (self->mode & 2) {
            SetFlags04((GameResources*)base, 0x10);
        }
        if (self->mode & 4) {
            unsigned char used[4];
            struct Struct_ov001_021539d8_3* entry;
            int i;

            __clear(used, 4);
            for (entry = self->unknown_d0_; entry != 0; entry = entry->next) {
                if (entry->type == 0 || entry->type == 1 || entry->type == 9) {
                    used[entry->slot] = 1;
                }
            }
            for (i = 0; i < 4; i++) {
                if (used[i] == 0) {
                    struct Obj021539d8* obj = (struct Obj021539d8*)gs->GetGameObjectByIndex(i);
                    if (obj != 0) {
                        _ZN8Object3D10EnableFlagEi(obj, 1);
                    }
                }
            }
        }
        if (self->mode & 8) {
            SetFlags04((GameResources*)base, 0x400);
        }
        if (self->mode & 0x20) {
            func_0203cf4c()->flags |= 2;
        }
    }
}
