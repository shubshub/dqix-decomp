#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"
#include "Memory/SafeAllocator.h"
#include "Resource/Brightness.h"

struct Struct_ov001_021539d8_7 {
    char unknown_0_[0x70];
};

struct Struct_ov001_021539d8_8 {
    int unknown_0_;
    void* unknown_4_;
    unsigned int unknown_8_;
    SafeAllocator* unknown_c_;
    int unknown_10_;
    int unknown_14_;
    int unknown_18_;
    int unknown_1c_;
};

struct Struct_ov001_021539d8_9 {
    unsigned int unknown_0_0_ : 1;
};

struct Struct_ov001_021539d8_10 {
    char unknown_0_[0x54];
    NSBXXInternalModel* unknown_54_;
};

struct Struct_ov001_021539d8_11 {
    unsigned short unknown_0_;
    char unknown_2_[6];
    struct Struct_ov001_021539d8_10* unknown_8_;
    struct Struct_ov001_021539d8_9* unknown_c_;
    char unknown_10_[0x34];
    int unknown_44_;
    int unknown_48_;
    int unknown_4c_;
    char unknown_50_[0x84];
    unsigned char unknown_d4_0_ : 1;
    char unknown_d5_[0x5b];
    unsigned int* unknown_130_;
};

struct Struct_ov001_021539d8_12 {
    int unknown_0_;
    char unknown_4_[0x4c];
    unsigned int unknown_50_;
};

struct Struct_ov001_021539d8 {
    unsigned int unknown_0_;
    int unknown_4_;
    void* unknown_8_;
    void* unknown_c_;
    int unknown_10_;
    struct Struct_ov001_021539d8_12* unknown_14_;
    struct Struct_ov001_021539d8_11* unknown_18_;
    int unknown_1c_;
};

struct Struct_ov001_021539d8_2 {
    char unknown_0_[2];
    unsigned char unknown_2_;
#if defined(jpn)
    char unknown_3_[0xd];
#else
    char unknown1_3_;
#endif
    char unknown_4_[0x10];
};

struct Struct_ov001_021539d8_3 {
    unsigned char unknown_0_0_ : 4;
    unsigned char unknown_0_4_ : 4;
    unsigned char unknown_1_;
    short unknown_2_;
    unsigned char unknown_4_;
    char unknown_5_[3];
    union {
        int unknown_8_;
        char unknown1_8_[0x24];
    };
    int unknown_2c_;
    unsigned char unknown_30_;
    unsigned char unknown_31_;
    char unknown_32_[2];
    struct Struct_ov001_021539d8_3* unknown_34_;
};

struct Struct_ov001_021539d8_4 {
    unsigned char unknown_0_;
    char unknown_1_[0x23];
    int unknown_24_;
    struct Struct_ov001_021539d8_4* unknown_28_;
    unsigned char unknown_2c_;
};

struct Struct_ov001_021539d8_5 {
    char unknown_0_[0x98];
    unsigned int unknown_98_;
};

struct Struct_ov001_021539d8_6 {
    char unknown_0_[0x50];
    unsigned short unknown_50_;
#if defined(jpn)
    char unknown_52_[0x7a];
#else
    char unknown1_52_[0x7e];
#endif
    struct Struct_ov001_021539d8_3* unknown_d0_;
    struct Struct_ov001_021539d8_4* unknown_d4_;
    char unknown_d8_[0x1c];
    int unknown_f4_;
    unsigned int unknown_f8_0_ : 27;
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
struct Struct_ov001_021539d8_5* func_0203cf4c(void);

void* LinkSession_GetInstance(void);
int LinkSession_IsHostOrSolo(void* obj);
unsigned char _Z24GameState_GetLeaderIndexP9GameState(GameState* gs);
int _Z29GameState_GetProtagonistIndexP9GameState(GameState* gs);
void _Z16VramState_RewindP11Foo0207df50(struct PairTables021539d8* p);
void _Z17VramState_RestorePc(struct PairTables021539d8* p);
void _Z14VramState_SavePc(struct PairTables021539d8* p);
void func_ov001_0215ab54(int kind, int id, int index);
struct Emitter021539d8* _Z29FindEntryPointerByKey0203df78Pvi(void* list, int key);
int _Z22FindEntryByKey0203dfdcPvi(void* list, int key);
void _Z30RegisterCombatantSlot_0200fd38P9GameStateiP10GameObject(GameState* gs, int id, struct Obj021539d8* obj);
SafeAllocator* _Z22GetGlobalValue0215aab8v(void);
void _ZN8Object3D10InitializeEv(struct Obj021539d8* obj);
void _ZN8Object3D11MakeVisibleEv(struct Obj021539d8* obj);
void _ZN8Object3D10MakeHiddenEv(struct Obj021539d8* obj);
void _ZN8Object3D10EnableFlagEi(struct Obj021539d8* obj, int mask);
void _ZN8Object3D18LoadFromCHRArchiveEP21ObjectArchiveLoadInfo(struct Obj021539d8* obj, struct ArchiveInfo021539d8* info);
void _ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(struct Obj021539d8* obj, struct ArchiveInfo021539d8* info, void* callback);
void _ZN8Object3D8SetScaleEiii(struct Obj021539d8* obj, int x, int y, int z);
void _ZN8Object3D19SetAnimationByIndexEii(struct Obj021539d8* obj, int a, int b);
void _ZN8Object3D16SetModelFromFileEP13SafeAllocatorPvjN7Model3D18TextureStagingModeE(struct Obj021539d8* obj, SafeAllocator* allocator, void* data, unsigned int size, int mode);
void Zone3D_GetInstance(void);
void _Z12Init020404c0Pi(struct Emitter021539d8* emitter);
void _Z23ClearWorkRecord0206bf2cP11Rec0206bf2c(void* record);
void _Z14NpcWalker_InitPv(struct Stream021539d8* stream);
char* strstr(const char* text, const char* needle);
void* memcpy(void* dst, const void* src, unsigned int size);
int sprintf(char* dst, const char* format, ...);
void _Z20SetField0xc_02040530Pii(struct Emitter021539d8* emitter, void* record);
void _Z20SetField0x8_02040520Pii(struct Emitter021539d8* emitter, struct Label021539d8* label);
void _Z27UpdateElementStream0203f02cP11Obj0203f02ciiPcii(struct Stream021539d8* stream, char* name, SafeAllocator* allocator, struct PairTables021539d8* pair, void* data, unsigned int size);
void func_0203f138(struct Stream021539d8* stream, int enabled);
void _Z28SetActiveChildShorts020408c8P12Node020408c8sss(struct Emitter021539d8* emitter, int a, int b, int c);
int _Z18FindEmptySlotIndexP18SlotArray_0203e03c(void* list);
void _Z21SetSlotIfIndexBelow32P17SlotArray0203dd10ji(void* list, int index, struct Emitter021539d8* emitter);
int _Z26FindFilesInNarcBySubstringPKvPKcPS0_Pjj(void* narc, const char* text, void** outFile, unsigned int* outSize, unsigned int count);
void* _Z36DecompressLZ77FileIntoAllocatedSpaceR13SafeAllocatorPKvRj(SafeAllocator* allocator, void* file, unsigned int* outSize);
void NSBXX_Model_SetPolygonID(NSBXXInternalModel* model, int id);
void __clear(unsigned char* arg0, int arg1);
}

extern "C" int func_0203d004(void* arg0);

static inline void inline_ov001_021539d8(struct Struct_ov001_021539d8* arg0, char* arg1, SafeAllocator* arg2,
                                        struct Struct_ov001_021539d8_7* arg3, void* arg4, unsigned int arg5) {
    if (arg0->unknown_14_ != 0) {
        func_0203f02c(arg0->unknown_14_, arg1, arg2, arg3, arg4, arg5);
    }
}

static inline void inline_ov001_021539d8_2(struct Struct_ov001_021539d8* arg0, int arg1) {
    if (arg0->unknown_14_ != 0) {
        func_0203f138(arg0->unknown_14_, arg1);
    }
}

// USA: func_ov001_021539d8
extern "C" ARM void func_ov001_021539d8(struct Self021539d8* self) {
    GameState* gs = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    struct Global021539d8* global = _Z29GetGlobalPtr021075f4_0203cf4cv();
    char* base = (char*)GetGameResources();
    void* search = LinkSession_GetInstance();
    struct LoadNode021539d8* node;
    struct MotionNode021539d8* motion;
    bool copied;
    LightingManager* lighting;
    unsigned int meshIndex;
    unsigned char* fifoBlob;
    unsigned char opcode1;
    unsigned char opcode2;
    unsigned char opcode3;
    SafeAllocator* pool;
    void* record;
    unsigned char length;
    NSBXXMesh* mesh;
    NSBXXInternalModel* model;
    struct Emitter021539d8* emitter;
    struct Label021539d8* label;
    struct PairTables021539d8* pair;

    for (node = self->loads; node != 0; node = node->next) {
        if (node->type == 1) {
            if (LinkSession_IsHostOrSolo(search) == 0 || !(self->mode & 0x10)) {
                int current = _Z24GameState_GetLeaderIndexP9GameState(gs);
                if (current != 0) {
                    struct LoadNode021539d8* other;
                    for (other = self->loads; other != 0; other = other->next) {
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

    var7 = false;
    var5 = arg0->unknown_d0_;
    while (var5 != 0) {

        if (var5->unknown_31_ != 0) {
            var5 = var5->unknown_34_;
            continue;
        }

        pair = &((struct PairTables021539d8*)(base + PAIR_TABLES_021539d8))[27];
        if (node->kind == 1) {
            pair = &((struct PairTables021539d8*)(base + PAIR_TABLES_021539d8))[7];
            if (!copied) {
                if ((self->flags & 4) || (self->flags & 1)) {
                    _Z16VramState_RewindP11Foo0207df50(pair);
                    copied = true;
                }
            }
        }

        switch (var5->unknown_0_0_) {
        case 0: {
            struct Struct_ov001_021539d8_11* var24 = (struct Struct_ov001_021539d8_11*)var0->GetPartyMemberByIndex(0);
            if (var24 == 0) {
                break;
            }
            if ((self->mode & 0x10) || !(*obj->status & 1)) {
                func_ov001_0215ab54(4, 0, node->index);
            } else if (LinkSession_IsHostOrSolo(search) != 0) {
                func_ov001_0215ab54(5, _Z24GameState_GetLeaderIndexP9GameState(gs), node->index);
            } else {
                int current = _Z29GameState_GetProtagonistIndexP9GameState(gs);
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
                if (var26 == 0) {
                    break;
                }
            }
            _ZN8Object3D11MakeVisibleEv(var24);
            break;
        }
        case 1:
            func_ov001_0215ab54(5, _Z24GameState_GetLeaderIndexP9GameState(gs), node->index);
            break;
        case 9:
        case 11:
        case 12:
        case 13:
            func_ov001_0215ab54(5, var5->unknown_2_, var5->unknown_1_);
            break;
        case 10:
            func_ov001_0215ab54(1, var5->unknown_2_, var5->unknown_1_);
            break;
        case 4: {
            struct Struct_ov001_021539d8* var27 = func_0203df78(var2, var5->unknown_8_);
            if (var27 != 0 && var27->unknown_18_ != 0) {
                var27->unknown_18_->unknown_d4_0_ = 1;
                func_0200fd38(var0, var5->unknown_2_, var27->unknown_18_);
                var27->unknown_0_ |= 0x10000;
                func_ov001_0215ab54(6, func_0203dfdc(var2, var5->unknown_8_), var5->unknown_1_);
            }
            break;
        }
        case 2: {
            char var28[0x50];
            struct Struct_ov001_021539d8_8 var29;
            void* var30;
            unsigned int var31;
            int var32;
            SafeAllocator* var33;

            if (var1->GetDetailedTaskStatus(var5->unknown_2c_) != 2) {
                var1->RemoveTask(var5->unknown_2c_);
                break;
            }
            var32 = 0;
            if (var1->GetTaskFilename(var5->unknown_2c_, var28)) {
                if (strstr(var28, data_ov001_02164bb0) != 0 || strstr(var28, data_ov001_02164bb6) != 0) {
                    var32 = 1;
                }
            }
            var33 = func_ov001_0215aab8();
            var1->GetLoadedFileByID(var5->unknown_2c_, &var30, &var31);
            struct Struct_ov001_021539d8_11* var34 = (struct Struct_ov001_021539d8_11*)var33->Allocate(0xac);
            if (var34 == 0) {
                var1->RemoveTask(var5->unknown_2c_);
                break;
            }
            _Z17VramState_RestorePc(pair);
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
            _Z14VramState_SavePc(pair);
            _ZN8Object3D8SetScaleEiii(obj, 0x10a, 0x10a, 0x10a);
            _ZN8Object3D19SetAnimationByIndexEii(obj, 0, 0);
            _Z30RegisterCombatantSlot_0200fd38P9GameStateiP10GameObject(gs, node->slot, obj);
            if (node->flags & 1) {
                Zone3D_GetInstance();
                lighting = LightingManager::GetInstance();
                model = obj->holder->model;
                NSBXXNameList* meshList = model->GetMeshListSafe();
                unsigned int readPos;
                unsigned int* operandPtr;
                int totalNumOperands;

                for (var9 = 0; var9 < var18->numMeshes_; var9++) {
                    unsigned char var39;
                    void* var40;

                    if (var35 != NULL && (var40 = var35->GetEntryv3Safe(var9)))
                        var17 = (NSBXXMesh*)var35->GetEntryFromPtrOffset(var40);
                    else
                        var17 = NULL;

                    if (!(var17->unk_4 & 2))
                        continue;

                    var10 = (unsigned char*)var17 + var17->gpuCommandsOffset_;
                    var36 = 0;
                    while (var36 < var17->gpuCommandsLength_) {
                        var39 = var10[var36];
                        var11 = var10[var36 + 1];
                        var12 = var10[var36 + 2];
                        var13 = var10[var36 + 3];
                        var36 += 4;

                        int var41 = 0;
                        var37 = (unsigned int*)(var10 + var36);

                        var38 = 0;

                        if (var8->GetFifoCommandData(var39, &var41))
                            var37[var38] = var8->ColorTransformTintBrightnessContrast(var37[var38]);
                        var38 += var41;

                        if (var8->GetFifoCommandData(var11, &var41))
                            var37[var38] = var8->ColorTransformTintBrightnessContrast(var37[var38]);
                        var38 += var41;

                        if (var8->GetFifoCommandData(var12, &var41))
                            var37[var38] = var8->ColorTransformTintBrightnessContrast(var37[var38]);
                        var38 += var41;

                        if (var8->GetFifoCommandData(var13, &var41))
                            var37[var38] = var8->ColorTransformTintBrightnessContrast(var37[var38]);
                        var38 += var41;

                        var36 += 4 * var38;
                    }
                }
            }
            func_ov001_0215ab54(1, var5->unknown_2_, var5->unknown_1_);
            var1->RemoveTask(var5->unknown_2c_);
            var5->unknown_31_ = 1;
            break;
        }
        case 5: {
            struct Struct_ov001_021539d8* var42 = func_0203df78(var2, var5->unknown_8_);
            if (var42 != 0 && var42->unknown_14_ != 0) {
                var42->unknown_0_ |= 0x10000;
                func_ov001_0215ab54(2, func_0203dfdc(var2, var5->unknown_8_), var5->unknown_1_);
            }
            break;
        }
        case 3: {
            void* var43;
            unsigned int var44;
            int var45;
            struct Struct_ov001_021539d8_12* var46;

            if (var1->GetDetailedTaskStatus(var5->unknown_2c_) != 2) {
                var1->RemoveTask(var5->unknown_2c_);
                break;
            }
            var14 = func_ov001_0215aab8();
            var1->GetLoadedFileByID(var5->unknown_2c_, &var43, &var44);
            var19 = (struct Struct_ov001_021539d8*)var14->Allocate(0x20);
            var15 = var14->Allocate(0x78);
            var20 = (struct Struct_ov001_021539d8_2*)var14->Allocate(sizeof(struct Struct_ov001_021539d8_2));
            var46 = (struct Struct_ov001_021539d8_12*)var14->Allocate(0x9c);
            if (var19 == 0 || var20 == 0 || var15 == 0 || var46 == 0) {
                var1->RemoveTask(var5->unknown_2c_);
                break;
            }
            _Z12Init020404c0Pi(emitter);
            _Z23ClearWorkRecord0206bf2cP11Rec0206bf2c(record);
            _Z14NpcWalker_InitPv(stream);
            label->kind = 3;
            if (strstr(node->name, data_ov001_02164bc0) != 0) {
                length = 5;
                if (strstr(node->name, data_ov001_02164bc5) != 0) {
                    length = 7;
                    stream->flags |= 8;
                }
                memcpy(var20->unknown_4_, var5->unknown1_8_ + 9, var16);
                if (var16 < 7u) {
                    var20->unknown_4_[var16] = 0;
                }
            } else {
                sprintf(var20->unknown_4_, data_ov001_02164bc8, var5->unknown1_8_);
            }
            var19->unknown_14_ = var46;
            func_02040530(var19, var15);
            func_02040520(var19, var20);
            var45 = func_0203d004(var2);
            if (var19->unknown_14_ != 0) {
                var19->unknown_14_->unknown_0_ = var45;
            }
            inline_ov001_021539d8(var19, var5->unknown1_8_ + 9, var14, var21, var43, var44);
            inline_ov001_021539d8_2(var19, 1);
            func_020408c8(var19, 0x8f, 0x8f, 0x8f);
            var5->unknown_2_ = func_0203e03c(var2);
            if (var5->unknown_2_ != -1) {
                func_0203dd10(var2, var5->unknown_2_, var19);
                var19->unknown_0_ |= 0x10000;
                func_ov001_0215ab54(2, var5->unknown_2_, var5->unknown_1_);
                var1->RemoveTask(var5->unknown_2c_);
                var5->unknown_31_ = 1;
            }
            break;
        }
        case 6: {
            char var47[0x50];
            struct Struct_ov001_021539d8_8 var48;
            void* var49;
            unsigned int var50;
            unsigned int var51;
            void* var52;
            unsigned int var53;
            SafeAllocator* var54;
            struct Struct_ov001_021539d8_11* var55;
            void* var56;
            int var57;

            if (var1->GetDetailedTaskStatus(var5->unknown_2c_) != 2) {
                var1->RemoveTask(var5->unknown_2c_);
                break;
            }
            var54 = func_ov001_0215aab8();
            var1->GetLoadedFileByID(var5->unknown_2c_, &var49, &var50);
            var55 = (struct Struct_ov001_021539d8_11*)var54->Allocate(0xac);
            if (var55 == 0) {
                var1->RemoveTask(var5->unknown_2c_);
                break;
            }
            var57 = 0;
            if (var1->GetTaskFilename(var5->unknown_2c_, var47)) {
                if (strstr(var47, data_ov001_02164bb0) != 0 || strstr(var47, data_ov001_02164bb6) != 0) {
                    var57 = 1;
                }
            }
            if (_Z26FindFilesInNarcBySubstringPKvPKcPS0_Pjj(var49, data_ov001_02164bcb, &var52, &var51, 1) == 0) {
                break;
            }
            var56 = _Z36DecompressLZ77FileIntoAllocatedSpaceR13SafeAllocatorPKvRj(var54, var52, &var53);
            if (var56 == 0) {
                break;
            }
            _Z17VramState_RestorePc(pair);
            _ZN8Object3D10InitializeEv(obj);
            info.data = unpacked;
            info.allocator = allocator;
            info.size = unpackedSize;
            info.flag = 1;
            if (format == 0) {
                _ZN8Object3D18LoadFromCHRArchiveEP21ObjectArchiveLoadInfo(obj, &info);
            } else if (format == 1) {
                _ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(obj, &info, 0);
            }
            _Z14VramState_SavePc(pair);
            _ZN8Object3D8SetScaleEiii(obj, 0x10a, 0x10a, 0x10a);
            _ZN8Object3D19SetAnimationByIndexEii(obj, 0, 0);
            _Z30RegisterCombatantSlot_0200fd38P9GameStateiP10GameObject(gs, node->slot, obj);
            func_ov001_0215ab54(1, node->slot, node->index);
            loader->RemoveTask(node->task);
            node->done = 1;
            break;
        }
        case 7: {
            void* var58;
            unsigned int var59;
            SafeAllocator* var60;
            void* var61;

            if (var1->GetDetailedTaskStatus(var5->unknown_2c_) != 2) {
                var1->RemoveTask(var5->unknown_2c_);
                break;
            }
            var60 = func_ov001_0215aab8();
            var1->GetLoadedFileByID(var5->unknown_2c_, &var58, &var59);
            struct Struct_ov001_021539d8_11* var62 = (struct Struct_ov001_021539d8_11*)var60->Allocate(0xac);
            if (var62 == 0) {
                var1->RemoveTask(var5->unknown_2c_);
                break;
            }
            copy = allocator->Allocate(size);
            memcpy(copy, data, size);
            _Z17VramState_RestorePc(pair);
            _ZN8Object3D10InitializeEv(obj);
            _ZN8Object3D16SetModelFromFileEP13SafeAllocatorPvjN7Model3D18TextureStagingModeE(obj, allocator, copy, size, 0);
            _Z14VramState_SavePc(pair);
            _ZN8Object3D8SetScaleEiii(obj, 0x10a, 0x10a, 0x10a);
            _ZN8Object3D19SetAnimationByIndexEii(obj, 0, 0);
            _Z30RegisterCombatantSlot_0200fd38P9GameStateiP10GameObject(gs, node->slot, obj);
            func_ov001_0215ab54(1, node->slot, node->index);
            loader->RemoveTask(node->task);
            node->done = 1;
            break;
        }
        case 8: {
            struct Struct_ov001_021539d8_8 var63;
            void* var64;
            unsigned int var65;
            SafeAllocator* var66;

            if (var1->GetDetailedTaskStatus(var5->unknown_2c_) != 2) {
                var1->RemoveTask(var5->unknown_2c_);
                break;
            }
            var66 = func_ov001_0215aab8();
            var1->GetLoadedFileByID(var5->unknown_2c_, &var64, &var65);
            struct Struct_ov001_021539d8_11* var67 = (struct Struct_ov001_021539d8_11*)var66->Allocate(0xac);
            if (var67 == 0) {
                var1->RemoveTask(var5->unknown_2c_);
                break;
            }
            _Z17VramState_RestorePc(pair);
            _ZN8Object3D10InitializeEv(obj);
            info.data = data;
            info.size = size;
            info.flag = 1;
            info.allocator = allocator;
            _ZN8Object3D18LoadFromCHRArchiveEP21ObjectArchiveLoadInfo(obj, &info);
            _Z14VramState_SavePc(pair);
            NSBXX_Model_SetPolygonID(obj->holder->model, 0x3d);
            obj->posX = 0;
            obj->posY = -0xa000;
            obj->posZ = 0x1000;
            _ZN8Object3D19SetAnimationByIndexEii(obj, 0, 0);
            _Z30RegisterCombatantSlot_0200fd38P9GameStateiP10GameObject(gs, node->slot, obj);
            _ZN8Object3D10MakeHiddenEv(obj);
            func_ov001_0215ab54(1, node->slot, node->index);
            loader->RemoveTask(node->task);
            node->done = 1;
            break;
        }
        }
        var5 = var5->unknown_34_;
    }

    var6 = arg0->unknown_d4_;
    while (var6 != 0) {
        if (var6->unknown_2c_ != 0 || var6->unknown_24_ < 0) {
            var6 = var6->unknown_28_;
            continue;
        }
        if (var1->GetDetailedTaskStatus(var6->unknown_24_) == 2) {
            struct Struct_ov001_021539d8_3* var68 = arg0->unknown_d0_;
            while (var68 != 0) {
                if (var68->unknown_1_ == var6->unknown_0_ && var68->unknown_0_0_ != 3 && var68->unknown_0_0_ != 5) {
                    struct Struct_ov001_021539d8_11* var69 = (struct Struct_ov001_021539d8_11*)var0->GetGameObjectByIndex(var68->unknown_2_);
                    if (var69 != 0) {
                        struct Struct_ov001_021539d8_8 var70;
                        void* var71;
                        unsigned int var72;
                        SafeAllocator* var73 = func_ov001_0215aab8();
                        int var74;

                        var1->GetLoadedFileByID(var6->unknown_24_, &var71, &var72);
                        var74 = 0;
                        if (var69->unknown_c_ != 0) {
                            var74 = var69->unknown_c_->unknown_0_0_;
                        }
                        var70.unknown_c_ = var73;
                        var70.unknown_4_ = var71;
                        var70.unknown_8_ = var72;
                        var70.unknown_10_ = 1;
                        var70.unknown_1c_ = 3;
                        if (var74 == 0) {
                            _ZN8Object3D18LoadFromCHRArchiveEP21ObjectArchiveLoadInfo(var69, &var70);
                        } else if (var74 == 1) {
                            _ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(var69, &var70, 0);
                        }
                        _ZN8Object3D19SetAnimationByIndexEii(obj, 0, 0);
                        break;
                    }
                }
                var68 = var68->unknown_34_;
                var6->unknown_2c_ = 1;
            }
        }
        var1->RemoveTask(var6->unknown_24_);
        var6 = var6->unknown_28_;
    }

    if (arg0->unknown_f4_ > -1) {
        var1->GetDetailedTaskStatus(arg0->unknown_f4_);
        var1->RemoveTask(arg0->unknown_f4_);
    }

    if (arg0->unknown_f8_0_ != 0) {
        if (arg0->unknown_f8_0_ & 1) {
            SetFlags04((GameResources*)var3, 8);
        }
        if (arg0->unknown_f8_0_ & 2) {
            SetFlags04((GameResources*)var3, 0x10);
        }
        if (arg0->unknown_f8_0_ & 4) {
            unsigned char var75[4];
            struct Struct_ov001_021539d8_3* var76;
            int var77;

            __clear(var75, 4);
            for (var76 = arg0->unknown_d0_; var76 != 0; var76 = var76->unknown_34_) {
                if (var76->unknown_0_0_ == 0 || var76->unknown_0_0_ == 1 || var76->unknown_0_0_ == 9) {
                    var75[var76->unknown_2_] = 1;
                }
            }
            for (var77 = 0; var77 < 4; var77++) {
                if (var75[var77] == 0) {
                    struct Struct_ov001_021539d8_11* var78 = (struct Struct_ov001_021539d8_11*)var0->GetGameObjectByIndex(var77);
                    if (var78 != 0) {
                        _ZN8Object3D10EnableFlagEi(var78, 1);
                    }
                }
            }
        }
        if (arg0->unknown_f8_0_ & 8) {
            SetFlags04((GameResources*)var3, 0x400);
        }
        if (arg0->unknown_f8_0_ & 0x20) {
            func_0203cf4c()->unknown_98_ |= 2;
        }
    }
}
