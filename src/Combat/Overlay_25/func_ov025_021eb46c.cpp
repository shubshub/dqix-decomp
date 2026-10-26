#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct Struct_ov025_021eb46c {
    char pad0[0x20];
    unsigned short combatantId;
};

struct Struct_ov025_021eb46c_2 {
    char pad0[8];
    unsigned char kind;
};

struct Struct_ov025_021eb46c_3 {
    char pad0[0x56b];
    unsigned char look : 4;
};

struct Struct_ov025_021eb46c_4 {
#if defined(jpn)
    char pad0[0x144];
#else
    char pad0[0x150];
#endif
    Struct_ov025_021eb46c_3* appearance;
};

struct Struct_ov025_021eb46c_5 {
    unsigned char type;
    unsigned char field1;
    unsigned short combatantId;
    unsigned short packageID;
    char pad6[2];
    Struct_ov025_021eb46c_5* next;
};

struct Struct_ov025_021e9778 {
    char pad0[0x10];
    SafeAllocator* allocators[8];
    unsigned char unknown_30_;
    char unknown_31_[0x1c4 - 0x31];
    unsigned int flags;
    int state;
    int unknown_1cc_;
    int unknown_1d0_;
    int unknown_1d4_;
    Struct_ov025_021eb46c_5* unknown_1d8_;
};

extern "C" void* func_ov000_02160130(void);
extern "C" void* func_ov000_02160f20(void* obj);
extern "C" void func_02072c9c(int id, char* out);
struct Struct_ov000_0215440c_2;
extern "C" Struct_ov025_021eb46c* func_ov000_02160094(Struct_ov000_0215440c_2*, int);
struct Struct_ov025_021e267c_3;
struct Struct_ov025_021e267c_2;
extern "C" void func_ov025_021e8bac(Struct_ov025_021e267c_2*, Struct_ov025_021e267c_3*);

extern char data_ov025_021ef8fc[];
extern char data_ov025_021ef916[];
extern char data_ov025_021ef91f[];
extern Struct_ov025_021e9778* data_ov025_021ef994;

// USA: func_ov025_021eb46c
extern "C" ARM int func_ov025_021eb46c(Struct_ov025_021e9778* ctx) {
    char stats[20];
    char path[20];
    ObjectArchiveLoadInfo info;
    void* fileData;
    unsigned int fileLength;

    if (ctx->flags & 2) {
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        int var6;
        SafeAllocator* alloc = ctx->allocators[ctx->unknown_30_];

        if (ctx->state == 0) {
            Struct_ov025_021eb46c_2* slot = (Struct_ov025_021eb46c_2*)func_ov000_02160f20(func_ov000_02160130());
            ctx->unknown_1cc_ = -1;
            if (slot->kind == 1 && func_ov000_02160094((Struct_ov000_0215440c_2*)slot, 0) != NULL) {
                int id = func_ov000_02160094((Struct_ov000_0215440c_2*)slot, 0)->combatantId;
                Struct_ov025_021eb46c_4* c = (Struct_ov025_021eb46c_4*)func_0200ff1c(GameState::GetInstance(), id);
                bool isParty;
                if (id >= 0 && id <= 3) {
                    isParty = true;
                } else {
                    isParty = false;
                }
                if (isParty && c != NULL) {
                    int look = c->appearance != NULL ? c->appearance->look : 0;
                    if (look == 1) {
                        sprintf(path, data_ov025_021ef8fc);
                        ctx->unknown_1cc_ = loader->QueueLoadFile(path, alloc);
                    } else {
                        func_02072c9c(id, stats);
                        sprintf(path, data_ov025_021ef916, stats);
                        ctx->unknown_1cc_ = loader->QueueLoadFileInGP2(data_ov025_021ef91f, path, alloc);
                    }
                }
            }
            if (ctx->unknown_1cc_ < 0) {
                ctx->flags &= ~2;
                return 0;
            }
            ctx->state++;
        } else if (loader->GetTaskStatus(ctx->unknown_1cc_) != 0) {
            loader->GetLoadedFileByID(ctx->unknown_1cc_, &fileData, &fileLength);
            if (fileData != NULL) {
                void* slot = func_ov000_02160f20(func_ov000_02160130());
                if (func_ov000_02160094((Struct_ov000_0215440c_2*)slot, 0) != NULL) {
                    var6 = func_ov000_02160094((Struct_ov000_0215440c_2*)slot, 0)->combatantId;
                    GameObject* c = func_0200ff1c(GameState::GetInstance(), var6);
                    if (c != NULL) {
                        Struct_ov025_021eb46c_5* node = (Struct_ov025_021eb46c_5*)alloc->Allocate(sizeof(Struct_ov025_021eb46c_5));
                        if (node != NULL) {
                            info.unk_0 = 0;
                            info.fileData = fileData;
                            info.fileSize = fileLength;
                            info.unk_10 = 0;
                            info.unk_14 = 0;
                            info.unk_18 = 0;
                            info.packageID = 0;
                            info.allocator = alloc;
                            info.packageID = data_ov025_021ef994->unknown_30_ + 4;
                            c->obj3D_.LoadFromCCHROrCMOTArchive(&info, NULL);
                            node->type = 0;
                            node->combatantId = var6;
                            node->packageID = info.packageID;
                            func_ov025_021e8bac((Struct_ov025_021e267c_2*)ctx, (Struct_ov025_021e267c_3*)node);
                        }
                    }
                }
            }
            loader->RemoveTask(ctx->unknown_1cc_);
            memset(&ctx->state, 0, 0x10);
            ctx->flags &= ~2;
            return 0;
        }
        return 1;
    }
    return 0;
}
