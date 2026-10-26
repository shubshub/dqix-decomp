#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "World/Object3D.h"
#include "Resource/GameResources.h"

struct Task021b2fac {
    char pad0[1];
    unsigned char done;
    char pad2[6];
    short combatantId;
    signed char state;
    unsigned char unknown_b_;
    char unknown_c_[4];
    int taskId;
};

struct Struct_ov017_021b2fac_2 {
    char pad0[0x56b];
    unsigned char kind : 4;
    unsigned char : 4;
};

struct Struct_ov017_021b2fac_3 {
    char pad0[0xcc];
    char tables[1];
};

struct Struct_ov017_021b2fac_4 {
    char pad0[4];
    short field4;
    char pad6[0x9c - 6];
    unsigned short unknown_9c_;
#if defined(jpn)
    char padA0[0x144 - 0x9e];
#else
    char padA0[0x150 - 0x9e];
#endif
    struct Struct_ov017_021b2fac_2* stats;
    struct Struct_ov017_021b2fac_3* alloc;
    char unknown_158_[0x1c4 - 0x158];
    unsigned char* entry;
};

extern "C" void func_ov017_021b33d8(void* p);
extern "C" int func_ov017_021b3444(struct Task021b2fac* t);
extern "C" int func_ov017_021b38c8(struct Task021b2fac* t);
extern "C" void PartyMember_RecalculateStats(void* p, int v);
extern "C" int func_ov017_021b3560(struct Task021b2fac* t);
extern "C" void func_ov017_021b3678(struct Task021b2fac* t);
extern "C" int func_ov017_021b3780(struct Task021b2fac* t);
extern "C" int func_ov017_021b3e14(struct Task021b2fac* t);
extern "C" void func_ov017_0218fcf8(int, int, int);
extern "C" void func_020d3c08(char* p);
struct Struct_020d3c28;
struct StreamHeader;
extern "C" void func_020d3c84(Struct_020d3c28*, StreamHeader*, int);
struct Struct_020d3d90;
extern "C" void* func_020d3d90(Struct_020d3d90*, int);
extern "C" void func_ov017_02191508(int id, void* e);
struct Struct_203dafc;
extern "C" void func_0203dafc(Struct_203dafc*);
extern "C" void VramState_Restore(char* p);
extern "C" void VramState_Save(char* p);
struct Bytes02033b88;
extern "C" void GameObject_ForceMotionState(Bytes02033b88*, int);
extern "C" void func_02039d48(unsigned char*);
extern "C" void func_ov017_02191fec(void* p, int v);

#if defined(jpn)
#define data_ov017_021d7a78 data_ov017_021d81c8
#define data_ov017_021d7a9c data_ov017_021d81dc
enum { Enum_ov017_021b2fac_184 = 0xa4, Enum_ov017_021b2fac_36 = 0x20, Enum_ov017_021b2fac_17 = 0xc };
#else
enum { Enum_ov017_021b2fac_184 = 0xb8, Enum_ov017_021b2fac_36 = 0x24, Enum_ov017_021b2fac_17 = 0x11 };
#endif
extern char data_ov017_021d7a78[];
extern char data_ov017_021d7a8c[];
extern char data_ov017_021d7a9c[];

// USA: FieldTask_ReloadMemberModel
// JPN: func_ov017_021b36bc
// Overlay 17, originally func_ov017_021b2fac (USA/EUR 0x021b2fac, JPN 0x021b36bc)
extern "C" ARM void FieldTask_ReloadMemberModel(struct Task021b2fac* task) {
    struct Struct_ov017_021b2fac_3* a5;
    void* m;
    void* src;
    BackgroundLoader* loader;
    Struct_ov017_021b2fac_4* c2;
    struct Struct_ov017_021b2fac_3* a0;
    unsigned char* ent;
    GameState* gs;
    void* mgr;
    Struct_ov017_021b2fac_4* c;
    SafeAllocator* var10;
    void* e;
    struct Struct_ov017_021b2fac_3* a4;
    int kind;
    void* file4;
    unsigned int var15;
    char handlers[Enum_ov017_021b2fac_184];
    char name[0x50];
    void* var18;
    unsigned int size5;
    ObjectArchiveLoadInfo info;
    gs = GameState::GetInstance();
    loader = BackgroundLoader::GetInstance();
    mgr = GetGameResources();
    c = (Struct_ov017_021b2fac_4*)func_0200ff1c(gs, task->combatantId);
    if (c == 0) {
        func_ov017_021b33d8(task);
        task->done = 1;
        return;
    }
    if (task->state == 0) {
        int has;
        if (c->stats != 0) {
            has = c->stats->kind != 0;
        } else {
            has = 0;
        }
        if (has != 0) {
            ((Object3D*)c)->Destroy();
            a0 = c->alloc;
            ((SafeAllocator*)((char*)a0 + 4))->Reset();
            ((SafeAllocator*)((char*)a0 + 0x18))->Reset();
#if defined(jpn)
            task->taskId = loader->QueueLoadFile(data_ov017_021d7a78, 0);
#else
            task->taskId = loader->QueueLoadFileInGP2(data_ov017_021d7a78, data_ov017_021d7a8c, 0);
#endif
            task->state = 4;
        } else if (func_ov017_021b3444(task) != 0) {
            task->state = 1;
        } else if (func_ov017_021b38c8(task) != 0) {
            PartyMember_RecalculateStats(c->stats, 0);
            task->state = 3;
        } else {
            task->done = 1;
            return;
        }
        ((Object3D*)c)->EnableFlag(0x200);
        return;
    }
    if (task->state == 1) {
        if (func_ov017_021b3560(task) != 0) {
            task->state = 2;
            func_ov017_021b3678(task);
        }
        return;
    }
    if (task->state == 2) {
        if (func_ov017_021b3780(task) != 0) {
            func_ov017_021b38c8(task);
            task->state = 3;
        }
        return;
    }
    if (task->state == 3) {
        if (func_ov017_021b3e14(task) != 0) {
            c2 = (Struct_ov017_021b2fac_4*)func_0200ff1c(gs, task->combatantId);
            if (c2->unknown_9c_ != 0) {
                m = GetGameResources();
                func_ov017_0218fcf8((int)m, task->combatantId, c2->unknown_9c_);
            }
            ((Object3D*)c2)->DisableFlag(0x200);
            if (task->unknown_b_ & 8) {
                ((Object3D*)c2)->MakeHidden();
                task->unknown_b_ &= ~8;
            }
            task->combatantId = -1;
            task->done = 1;
        }
        return;
    }
    if (task->state == 4) {
        if (loader->GetTaskStatus(task->taskId) != 0) {
            if (loader->GetDetailedTaskStatus(task->taskId) == 2) {
                loader->GetLoadedFileByID(task->taskId, &file4, &var15);
                if (file4 != 0) {
                    func_020d3c08(handlers);
                    func_020d3c84((Struct_020d3c28*)handlers, (StreamHeader*)file4, var15);
                    kind = c->stats != 0 ? c->stats->kind : 0;
                    src = func_020d3d90((Struct_020d3d90*)handlers, kind);
                    e = ((SafeAllocator*)((char*)c->alloc + 0x18))->Allocate(Enum_ov017_021b2fac_36);
                    if (e != 0) {
                        memcpy(e, src, Enum_ov017_021b2fac_36);
                        c->entry = (unsigned char*)e;
                        func_ov017_02191508(task->combatantId, e);
                    }
                }
            }
            loader->RemoveTask(task->taskId);
            task->taskId = -1;
            ent = c->entry;
            a4 = c->alloc;
            if (ent != 0) {
                sprintf(name, data_ov017_021d7a9c, ent[Enum_ov017_021b2fac_17]);
                task->taskId = loader->QueueLoadFile(name, (SafeAllocator*)((char*)a4 + 4));
            }
            task->state = 5;
        }
        return;
    }
    if (task->state == 5) {
        if (loader->GetTaskStatus(task->taskId) != 0) {
            a5 = c->alloc;
            var10 = (SafeAllocator*)((char*)a5 + 4);
            if (loader->GetDetailedTaskStatus(task->taskId) == 2) {
                loader->GetLoadedFileByID(task->taskId, &var18, &size5);
                if (var18 != 0) {
                    func_0203dafc((Struct_203dafc*)&info);
                    info.fileData = var18;
                    info.fileSize = size5;
                    info.allocator = var10;
                    VramState_Restore(a5->tables);
                    ((Object3D*)c)->LoadFromCCHROrCMOTArchive(&info, 0);
                    VramState_Save(a5->tables);
                }
            }
            ((Object3D*)c)->SetScale(0x10a, 0x10a, 0x10a);
            GameObject_ForceMotionState((Bytes02033b88*)c, 0);
            ((Object3D*)c)->DisableFlag(0x200);
            ((Object3D*)c)->SetInheritedAlpha(0);
            func_02039d48((unsigned char*)c);
            func_ov017_02191fec(mgr, c->field4);
            loader->RemoveTask(task->taskId);
            task->taskId = -1;
            task->combatantId = -1;
            task->done = 1;
        }
    }
}

#if defined(jpn)
#undef data_ov017_021d7a78
#undef data_ov017_021d7a9c
#endif
