#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "GameState/GameState.h"
#include "Resource/Brightness.h"
#define REG_DISPCNT (*(volatile unsigned int*)0x04000000)
struct Obj020397cc { char padding[0xb2]; short unknown_b2_; };
struct FlagWord02046708;
struct ListHead02046b60;
struct Struct_ov017_021a5600 {
    unsigned char flag;
    char padding[3];
    int field4, field8;
};
#if defined(jpn)
enum { Enum_ov017_021a5600_76 = 0x34, Enum_ov017_021a5600_9532 = 0x2364,
       Enum_ov017_021a5600_9552 = 0x2378, SceneHeapSize = 0x293b8, Enum_ov017_021a5600_179632 = 0x2abd8 };
#else
enum { Enum_ov017_021a5600_76 = 0x4c, Enum_ov017_021a5600_9532 = 0x253c,
       Enum_ov017_021a5600_9552 = 0x2550, SceneHeapSize = 0x2a590, Enum_ov017_021a5600_179632 = 0x2bdb0 };
#endif
struct BattleState021a5600 {
    unsigned char type, unknown_1_;
    char padding2[6];
    int state;
    SafeAllocator allocator;
    unsigned char unknown_20_, unknown_21_;
    char unknown_22_[2];
    Struct_ov017_021a5600 unknown_24_;
};
extern "C" void func_0202738c(unsigned char*, int, int, int);
extern "C" void func_02027304(unsigned char*, int);
extern "C" void func_020a0cc4(int);
extern "C" void ROMFilesystem_InitFileTables();
extern "C" void func_ov002_0215505c(char*);
extern "C" void func_ov002_02154d40(char*, SafeAllocator*);
extern "C" int func_ov002_02155960(char*, int);
extern "C" void func_ov002_021556fc(char*);
extern "C" void func_ov017_021a55b0(BattleState021a5600*);
extern "C" void Party_ReformLine(GameResources*, int, int, int, int);
extern "C" FlagWord02046708* GlobalFlags_GetInstance();
extern "C" void GameObject_DisableControl(Obj020397cc*, int);
extern "C" unsigned char* GameState_GetFollowCamera(char*);
extern "C" void func_020a28a0(unsigned char*, unsigned char);
extern "C" void func_020a28b0(unsigned char*, int);
extern "C" void func_02027288(unsigned char*, int);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion*, unsigned int);
extern "C" void func_020a1df8(int);
extern "C" void func_020a1ef0(int);
extern "C" void func_ov002_021556ec(void*, int, int);
extern "C" int func_02046b60(ListHead02046b60*, int);
extern "C" void GameObject_EnableControl(void*);
extern "C" void DebugConsole_Init();
extern "C" int FlagWord_TestBits(FlagWord02046708*, unsigned int);
extern "C" void func_ov017_021a01bc(unsigned char*);
extern "C" void GameObject_ApplyPendingControl(void*);
extern "C" void func_ov017_021a5974(char*);
extern AllocatorUnion g_mainAllocator;
extern char* data_ov017_021d83ac;
// Overlay 17, originally func_ov017_021a5600 (USA/EUR 0x021a5600, JPN 0x021a6038)
extern "C" ARM void FieldTask_OpenMenu(BattleState021a5600* self) {
    GameState* game = GameState::GetInstance();
    GameResources* resources = GetGameResources();
    Obj020397cc* actor = (Obj020397cc*)game->GetLeader();
    FlagWord02046708* flags = GlobalFlags_GetInstance();
    GameObject_DisableControl(actor, 1);
    actor->unknown_b2_ = 0;
    SetFlags04(resources, 0xc0);
    unsigned char* action = GameState_GetFollowCamera((char*)game);
    func_020a28a0(action, 3);
    int ticks = game->GetTickCount();
    if (ticks < 0) ticks = 1;
    if (self->state == 0) {
        unsigned char* var6 = (unsigned char*)resources->unknown_ptr_36d0;
        func_02027288(var6, -1);
        func_0202738c(var6, 1, 2, -1);
        func_020a0cc4(Enum_ov017_021a5600_179632);
        void* memory = AllocatorUnion_AllocateRounded(&g_mainAllocator, SceneHeapSize);
        if (!memory) {
            ROMFilesystem_InitFileTables();
            self->unknown_1_ = 1;
        } else {
            self->allocator.CreateTypeA(memory, SceneHeapSize);
            self->allocator.Reset();
            func_020a1df8(2);
            func_020a1ef0(1);
            data_ov017_021d83ac = (char*)self->allocator.Allocate(Enum_ov017_021a5600_9552);
            func_ov002_0215505c(data_ov017_021d83ac);
            func_ov002_021556ec(data_ov017_021d83ac, self->unknown_20_, self->unknown_21_);
            func_ov002_02154d40(data_ov017_021d83ac, &self->allocator);
            Struct_ov017_021a5600 var8 = self->unknown_24_;
            char* scene = data_ov017_021d83ac;
            *reinterpret_cast<unsigned char*>(scene + Enum_ov017_021a5600_9532) = var8.flag;
            *reinterpret_cast<int*>(scene + Enum_ov017_021a5600_9532 + 4) = var8.field4;
            *reinterpret_cast<int*>(scene + Enum_ov017_021a5600_9532 + 8) = var8.field8;
            ++self->state;
        }
    } else if (self->state == 1) {
        if (func_ov002_02155960(data_ov017_021d83ac, ticks)) ++self->state;
    } else if (self->state == 2) {
        func_ov002_021556fc(data_ov017_021d83ac);
        FontBankLoader* music = FontBankLoader_GetInstance();
        func_02094b40(music);
        FontBankLoader_CancelLoads(music);
        func_02094b34(music, 5000, 0x6f, 1, 1);
        ++self->state;
    } else if (self->state == 3) {
        unsigned int layer = *reinterpret_cast<unsigned int*>(data_ov017_021d83ac + Enum_ov017_021a5600_76);
        REG_DISPCNT = (layer << 8) | (REG_DISPCNT & ~0x1f00);
        data_ov017_021d83ac = 0;
        func_ov017_021a55b0(self);
        int clear = 1;
        ListHead02046b60* list = (ListHead02046b60*)resources->fieldTaskQueue_;
        if (list && (func_02046b60(list, 2) || func_02046b60(list, 47))) clear = 0;
        if (clear) {
            func_020a28b0(action, 3);
            ClearFlags04(resources, 0xc0);
            GameObject_EnableControl(actor);
        }
        Party_ReformLine(resources, 1, 1, 0, 1);
        DebugConsole_Init();
        ROMFilesystem_InitFileTables();
        if (!FlagWord_TestBits(flags, 0x100000)) {
            unsigned char* var14 = (unsigned char*)resources->unknown_ptr_36d0;
            func_0202738c(var14, 0, 2, -1);
            func_02027304(var14, -1);
        }
        func_ov017_021a01bc((unsigned char*)resources);
        GameObject_EnableControl(actor);
        GameObject_ApplyPendingControl(actor);
        self->unknown_1_ = 1;
        func_ov017_021a5974((char*)self);
    }
}
