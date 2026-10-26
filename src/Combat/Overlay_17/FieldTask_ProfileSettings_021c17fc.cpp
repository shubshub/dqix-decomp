#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "NitroSDK/OverlayId.h"
#include "Resource/Brightness.h"

#if defined(jpn)
enum { Enum_ov017_021c17fc_189632 = 0x2d0fc, Enum_ov017_021c17fc_28 = 0x14, Enum_ov017_021c17fc_5308 = 0x14f8, Enum_ov017_021c17fc_5312 = 0x14fc };
#else
enum { Enum_ov017_021c17fc_189632 = 0x2e4c0, Enum_ov017_021c17fc_28 = 0x1c, Enum_ov017_021c17fc_5308 = 0x14bc, Enum_ov017_021c17fc_5312 = 0x14c0 };
#endif

struct AllocatorUnion;
struct Struct_02018300_3;

void GameObject_DisableControl(Obj020397cc* obj, int flag);
int GameState_GetFollowCamera(char* obj);
void SetFlagsAt0x244_020a28a0(unsigned char* obj, unsigned char mask);
void ClearFlagBits_020a28b0(unsigned char* obj, int mask);
void GameObject_EnableControl(void* obj);
extern "C" void func_020a0cc4(unsigned int size);
extern "C" void ROMFilesystem_InitFileTables(void);
void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern "C" void Overlay_Load(unsigned int id);
void PushInputLogA_020a1df8(int value);
void PushInputLogB_020a1ef0(int value);
extern "C" void func_ov012_021843d4(void* scene);
extern "C" void func_ov012_02184884(void* scene, SafeAllocator* allocator);
extern "C" int func_ov012_02184acc(void* scene, unsigned int tick);
extern "C" void func_ov012_02185af0(void* scene);
void SetCombatModeFromCase020dc2d0(int mode);
void CancelActionAndInsertNode_021a5530(char* obj);
extern "C" void func_ov017_0218d77c(GameResources* res, int flag);
extern char g_mainAllocator;

struct Struct_ov017_021c17fc {
    char unknown_0_[Enum_ov017_021c17fc_28];
    int unknown_1c_;
    char unknown_20_[Enum_ov017_021c17fc_5308 - Enum_ov017_021c17fc_28 - 4];
    unsigned char unknown_14bc_;
};

struct Struct_ov017_021c17fc_2 {
    char unknown_0_;
    unsigned char unknown_1_;
    char unknown_2_[8 - 2];
    SafeAllocator unknown_8_;
    unsigned char unknown_1c_;
    unsigned char unknown_1d_;
    char unknown_1e_[0x20 - 0x1e];
    Struct_ov017_021c17fc* unknown_20_;
};

extern "C" void func_ov017_021c1a24(Struct_ov017_021c17fc_2* arg0);

// Overlay 17, originally func_ov017_021c17fc (USA/EUR 0x021c17fc, JPN 0x021c1da4)
extern "C" ARM void FieldTask_ProfileSettings(Task021c17fc* task) {
    GameState* gs = GameState::GetInstance();
    GameResources* res = GetGameResources();
    GameObject* unknown = gs->GetLeader();
    GameObject_DisableControl((Obj020397cc*)unknown, 1);
    SetFlags04(res, 0xc0);
    unsigned char* flags = (unsigned char*)GameState_GetFollowCamera((char*)gs);
    SetFlagsAt0x244_020a28a0(flags, 3);
    if (task->step == 0) {
        func_020a0cc4(ArenaSize);
        void* buffer = AllocatorUnion_AllocateRounded((AllocatorUnion*)&g_mainAllocator, ArenaSize);
        if (buffer == NULL) {
            ROMFilesystem_InitFileTables();
            task->failed = 1;
            return;
        }
        arg0->unknown_8_.CreateTypeA(var4, Enum_ov017_021c17fc_189632);
        arg0->unknown_8_.Reset();
#if !defined(jpn)
        if (arg0->unknown_1d_) {
            func_020a1df8(3);
        }
#endif
        Overlay_Load(OVERLAY_ID(12));
        PushInputLogB_020a1ef0(1);
        task->scene = (Scene021c17fc*)task->allocator.Allocate(SceneSize);
        func_ov012_021843d4(task->scene);
        func_ov012_02184884(task->scene, &task->allocator);
        task->step++;
        return;
    }
    if (arg0->unknown_1c_ == 1) {
        if (func_ov012_02184acc(arg0->unknown_20_, var0->GetTickCount())) {
            arg0->unknown_1c_++;
        }
        return;
    }
    if (arg0->unknown_1c_ == 2) {
        func_ov012_02185af0(arg0->unknown_20_);
        arg0->unknown_1c_++;
        return;
    }
    if (arg0->unknown_1c_ != 3) {
        return;
    }
    unsigned char ready = task->scene->ready;
    *(volatile unsigned int*)0x4000000 = (task->scene->planes << 8) | (*(volatile unsigned int*)0x4000000 & ~0x1f00);
    func_ov017_021c1a24(task);
    SetCombatModeFromCase020dc2d0(0);
    if (task->restore) {
        if (ready) {
            GameObject_EnableControl(unknown);
            ClearFlagBits_020a28b0(flags, 3);
            ClearFlags04(res, 0xc0);
        } else {
            func_ov017_021a5530((char*)var1);
        }
    } else {
        func_ov017_0218d77c(var1, 1);
    }
    ROMFilesystem_InitFileTables();
    task->failed = 1;
}
