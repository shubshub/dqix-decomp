#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "NitroSDK/OverlayId.h"
#include "Resource/Brightness.h"

struct AllocatorUnion;
struct Obj020397cc;
struct Obj020d7aa0;
struct SearchStruct;
struct Struct_ov008_02189284;
struct Struct_ov008_0218936c;

extern "C" SearchStruct* LinkSession_GetInstance(void);
extern "C" void GameObject_DisableControl(Obj020397cc* obj, int flag);
extern "C" void func_020a0cc4(unsigned int size);
extern "C" void ROMFilesystem_InitFileTables(void);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern "C" Obj020d7aa0* TextQueue_GetInstance();
extern "C" void TextQueue_Reset(Obj020d7aa0* obj);
extern "C" void func_020a1ef0(int value);
extern "C" void func_020a1f4c(int value);
extern "C" void Overlay_Load(unsigned int id);
extern "C" void func_ov008_02188f5c(void* scene, int index, int arg);
extern "C" void func_ov008_02189284(Struct_ov008_02189284* layout, SafeAllocator* allocator);
extern "C" unsigned char func_ov008_0218936c(Struct_ov008_0218936c* manager, unsigned int ticks);
extern "C" int LinkSession_IsSlotLost(SearchStruct* search, int index);
extern "C" void func_ov008_0218b240(void* scene);
extern "C" void func_ov008_021894b8(void* scene);
extern "C" void GameObject_EnableControl(void* obj);
extern char g_mainAllocator;

struct Struct_ov017_021a9768 {
    char pad[0x14];
    int unknown_14_;
};

struct Task021a9768 {
    char pad0;
    unsigned char failed;
    char pad1[8 - 2];
    unsigned char step;
    char pad2[0xc - 9];
    SafeAllocator allocator;
    Struct_ov017_021a9768* scene;
    signed char index;
    char pad3[0x54 - 0x25];
    int unknown_54_;
};

extern "C" void func_ov017_021a9714(Task021a9768* task);

// Overlay 17, originally func_ov017_021a9768 (USA/EUR 0x021a9768, JPN 0x021a9f3c)
extern "C" ARM void FieldTask_TalkToPlayerCharacter(Task021a9768* task) {
    GameState* gs = GameState::GetInstance();
    GameResources* res = GetGameResources();
    GameObject* unknown = gs->GetLeader();
    SearchStruct* search = LinkSession_GetInstance();
    GameObject_DisableControl((Obj020397cc*)unknown, 1);
    SetFlags04((GameResources*)res, 0xc0);
    if (task->step == 0) {
#if defined(jpn)
        func_020a0cc4(0x1c704);
        void* buffer = AllocatorUnion_AllocateRounded((AllocatorUnion*)&g_mainAllocator, 0x1c704);
#else
        func_020a0cc4(0x1c70c);
        void* buffer = AllocatorUnion_AllocateRounded((AllocatorUnion*)&g_mainAllocator, 0x1c70c);
#endif
        if (buffer == NULL) {
            ROMFilesystem_InitFileTables();
            task->failed = 1;
            return;
        }
        TextQueue_Reset(TextQueue_GetInstance());
#if defined(jpn)
        task->allocator.CreateTypeA(buffer, 0x1c704);
#else
        task->allocator.CreateTypeA(buffer, 0x1c70c);
#endif
        task->allocator.Reset();
        func_020a1ef0(1);
        Overlay_Load(OVERLAY_ID(8));
#if defined(jpn)
        task->scene = (Struct_ov017_021a9768*)task->allocator.Allocate(0xec4);
#else
        task->scene = (Struct_ov017_021a9768*)task->allocator.Allocate(0xecc);
#endif
        if (task->unknown_54_ == 0) {
            func_ov008_02188f5c(task->scene, task->index, 0);
        } else {
            func_ov008_02188f5c(task->scene, -1, task->unknown_54_);
        }
        func_ov008_02189284((Struct_ov008_02189284*)task->scene, &task->allocator);
        task->step++;
        return;
    }
    if (task->step == 1) {
        if (func_ov008_0218936c((Struct_ov008_0218936c*)task->scene, gs->GetTickCount())) {
            task->step++;
        }
        if (LinkSession_IsSlotLost(search, 0)) {
            func_ov008_0218b240(task->scene);
        }
        int var5 = 0;
        if (task->index >= 0 && task->index <= 3) {
            var5 = 1;
        }
        if (!var5) {
            return;
        }
        if (gs->GetGameObjectByIndex(task->index) != NULL && !LinkSession_IsSlotLost(search, task->index)) {
            return;
        }
        func_ov008_0218b240(task->scene);
        return;
    }
    if (task->step == 2) {
        func_ov008_021894b8(task->scene);
        task->step++;
        return;
    }
    if (task->step != 3) {
        return;
    }
    GameObject_EnableControl(GameState::GetInstance()->GetLeader());
    *(volatile unsigned int*)0x4000000 = (task->scene->unknown_14_ << 8) | (*(volatile unsigned int*)0x4000000 & ~0x1f00);
    task->scene = NULL;
    func_020a1f4c(1);
    func_ov017_021a9714(task);
    ROMFilesystem_InitFileTables();
    ClearFlags04((GameResources*)res, 0x80);
    task->failed = 1;
}
