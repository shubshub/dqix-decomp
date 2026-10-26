#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "NitroSDK/OverlayId.h"
#include "Resource/Brightness.h"

#if defined(jpn)
enum { ArenaSize = 0x2d0fc, Enum_ov017_021c17fc_28 = 0x14, Enum_ov017_021c17fc_5308 = 0x14f8, Enum_ov017_021c17fc_5312 = 0x14fc };
#else
enum { ArenaSize = 0x2e4c0, Enum_ov017_021c17fc_28 = 0x1c, Enum_ov017_021c17fc_5308 = 0x14bc, Enum_ov017_021c17fc_5312 = 0x14c0 };
#endif

struct AllocatorUnion;
struct Obj020397cc;

extern "C" void GameObject_DisableControl(Obj020397cc* obj, int flag);
extern "C" int GameState_GetFollowCamera(char* obj);
extern "C" void func_020a28a0(unsigned char* obj, unsigned char mask);
extern "C" void func_020a28b0(unsigned char* obj, int mask);
extern "C" void GameObject_EnableControl(void* obj);
extern "C" void func_020a0cc4(unsigned int size);
extern "C" void ROMFilesystem_InitFileTables(void);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern "C" void Overlay_Load(unsigned int id);
extern "C" void func_020a1df8(int value);
extern "C" void func_020a1ef0(int value);
extern "C" void func_ov012_021843d4(void* scene);
extern "C" void func_ov012_02184884(void* scene, SafeAllocator* allocator);
extern "C" int func_ov012_02184acc(void* scene, unsigned int tick);
extern "C" void func_ov012_02185af0(void* scene);
extern "C" void func_020dc2d0(int mode);
extern "C" void func_ov017_021a5530(char* obj);
extern "C" void func_ov017_0218d77c(GameResources* res, int flag);
extern char g_mainAllocator;

struct Struct_ov017_021c17fc {
    char pad0[Enum_ov017_021c17fc_28];
    int unknown_1c_;
    char pad1[Enum_ov017_021c17fc_5308 - Enum_ov017_021c17fc_28 - 4];
    unsigned char unknown_14bc_;
};

struct Task021c17fc {
    char pad0;
    unsigned char failed;
    char pad1[8 - 2];
    SafeAllocator allocator;
    unsigned char step;
    unsigned char unknown_1d_;
    char pad2[0x20 - 0x1e];
    Struct_ov017_021c17fc* scene;
};

extern "C" void func_ov017_021c1a24(Task021c17fc* task);

// Overlay 17, originally func_ov017_021c17fc (USA/EUR 0x021c17fc, JPN 0x021c1da4)
extern "C" ARM void FieldTask_ProfileSettings(Task021c17fc* task) {
    GameState* gs = GameState::GetInstance();
    GameResources* res = GetGameResources();
    GameObject* unknown = gs->GetLeader();
    GameObject_DisableControl((Obj020397cc*)unknown, 1);
    SetFlags04(res, 0xc0);
    unsigned char* flags = (unsigned char*)GameState_GetFollowCamera((char*)gs);
    func_020a28a0(flags, 3);
    if (task->step == 0) {
        func_020a0cc4(ArenaSize);
        void* buffer = AllocatorUnion_AllocateRounded((AllocatorUnion*)&g_mainAllocator, ArenaSize);
        if (buffer == NULL) {
            ROMFilesystem_InitFileTables();
            task->failed = 1;
            return;
        }
        task->allocator.CreateTypeA(buffer, ArenaSize);
        task->allocator.Reset();
#if !defined(jpn)
        if (task->unknown_1d_) {
            func_020a1df8(3);
        }
#endif
        Overlay_Load(OVERLAY_ID(12));
        func_020a1ef0(1);
        task->scene = (Struct_ov017_021c17fc*)task->allocator.Allocate(Enum_ov017_021c17fc_5312);
        func_ov012_021843d4(task->scene);
        func_ov012_02184884(task->scene, &task->allocator);
        task->step++;
        return;
    }
    if (task->step == 1) {
        if (func_ov012_02184acc(task->scene, gs->GetTickCount())) {
            task->step++;
        }
        return;
    }
    if (task->step == 2) {
        func_ov012_02185af0(task->scene);
        task->step++;
        return;
    }
    if (task->step != 3) {
        return;
    }
    unsigned char var5 = task->scene->unknown_14bc_;
    *(volatile unsigned int*)0x4000000 = (task->scene->unknown_1c_ << 8) | (*(volatile unsigned int*)0x4000000 & ~0x1f00);
    func_ov017_021c1a24(task);
    func_020dc2d0(0);
    if (task->unknown_1d_) {
        if (var5) {
            GameObject_EnableControl(unknown);
            func_020a28b0(flags, 3);
            ClearFlags04(res, 0xc0);
        } else {
            func_ov017_021a5530((char*)res);
        }
    } else {
        func_ov017_0218d77c(res, 1);
    }
    ROMFilesystem_InitFileTables();
    task->failed = 1;
}
