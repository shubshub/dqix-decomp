#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "NitroSDK/OverlayId.h"
#include "Resource/Brightness.h"

struct AllocatorUnion;
struct Struct_02018300_3;
struct Struct_020d7aa0_2;
struct Struct_0202b2f0;
struct Struct_ov008_02189284;
struct Struct_ov008_0218936c;

extern "C" SearchStruct* LinkSession_GetInstance(void);
void GameObject_DisableControl(Obj020397cc* obj, int flag);
extern "C" void func_020a0cc4(unsigned int size);
extern "C" void ROMFilesystem_InitFileTables(void);
void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
Obj020d7aa0* TextQueue_GetInstance();
void TextQueue_Reset(Obj020d7aa0* obj);
void PushInputLogB_020a1ef0(int value);
void PopStack1AndTrigger_020a1f4c(int value);
extern "C" void Overlay_Load(unsigned int id);
extern "C" void func_ov008_02188f5c(void* scene, int index, int arg);
void SetupAllocators_02189284(Layout02189284* layout, SafeAllocator* allocator);
unsigned char Dispatch0218936c(Manager0218936c* manager, unsigned int ticks);
int LinkSession_IsSlotLost(SearchStruct* search, int index);
extern "C" void func_ov008_0218b240(void* scene);
extern "C" void func_ov008_021894b8(void* scene);
void GameObject_EnableControl(void* obj);
extern char g_mainAllocator;

struct Struct_ov017_021a9768 {
    char unknown_0_[0x14];
    int unknown_14_;
};

struct Struct_ov017_021a9768_2 {
    char unknown_0_;
    unsigned char unknown_1_;
    char unknown_2_[8 - 2];
    unsigned char unknown_8_;
    char unknown_9_[0xc - 9];
    SafeAllocator unknown_c_;
    Struct_ov017_021a9768* unknown_20_;
    signed char unknown_24_;
    char unknown_25_[0x54 - 0x25];
    int unknown_54_;
};

extern "C" void func_ov017_021a9714(Struct_ov017_021a9768_2* arg0);

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
        arg0->unknown_c_.CreateTypeA(var4, 0x1c704);
#else
        arg0->unknown_c_.CreateTypeA(var4, 0x1c70c);
#endif
        task->allocator.Reset();
        PushInputLogB_020a1ef0(1);
        Overlay_Load(OVERLAY_ID(8));
#if defined(jpn)
        arg0->unknown_20_ = (Struct_ov017_021a9768*)arg0->unknown_c_.Allocate(0xec4);
#else
        arg0->unknown_20_ = (Struct_ov017_021a9768*)arg0->unknown_c_.Allocate(0xecc);
#endif
        if (arg0->unknown_54_ == 0) {
            func_ov008_02188f5c(arg0->unknown_20_, arg0->unknown_24_, 0);
        } else {
            func_ov008_02188f5c(arg0->unknown_20_, -1, arg0->unknown_54_);
        }
        func_ov008_02189284((Struct_ov008_02189284*)arg0->unknown_20_, &arg0->unknown_c_);
        arg0->unknown_8_++;
        return;
    }
    if (arg0->unknown_8_ == 1) {
        if (func_ov008_0218936c((Struct_ov008_0218936c*)arg0->unknown_20_, var0->GetTickCount())) {
            arg0->unknown_8_++;
        }
        if (LinkSession_IsSlotLost(search, 0)) {
            func_ov008_0218b240(task->scene);
        }
        int var5 = 0;
        if (arg0->unknown_24_ >= 0 && arg0->unknown_24_ <= 3) {
            var5 = 1;
        }
        if (!var5) {
            return;
        }
        if (gs->GetGameObjectByIndex(task->index) != NULL && !LinkSession_IsSlotLost(search, task->index)) {
            return;
        }
        func_ov008_0218b240(arg0->unknown_20_);
        return;
    }
    if (arg0->unknown_8_ == 2) {
        func_ov008_021894b8(arg0->unknown_20_);
        arg0->unknown_8_++;
        return;
    }
    if (arg0->unknown_8_ != 3) {
        return;
    }
    GameObject_EnableControl(GameState::GetInstance()->GetLeader());
    *(volatile unsigned int*)0x4000000 = (task->scene->planes << 8) | (*(volatile unsigned int*)0x4000000 & ~0x1f00);
    task->scene = NULL;
    PopStack1AndTrigger_020a1f4c(1);
    func_ov017_021a9714(task);
    ROMFilesystem_InitFileTables();
    ClearFlags04((GameResources*)res, 0x80);
    task->failed = 1;
}
