#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "GameState/GameState.h"
#include "Resource/Brightness.h"
#define REG_DISPCNT (*(volatile unsigned int*)0x04000000)
struct Struct_02018300_3 { char unknown_0_[0xb2]; short unknown_b2_; };
struct Struct_02012de8;
struct Struct_02038598_5;
struct Struct_ov017_021a5600 {
    unsigned char unknown_0_;
    char unknown_1_[3];
    int unknown_4_, unknown_8_;
};
#if defined(jpn)
enum { Enum_ov017_021a5600_76 = 0x34, Enum_ov017_021a5600_9532 = 0x2364,
       Enum_ov017_021a5600_9552 = 0x2378, Enum_ov017_021a5600_173456 = 0x293b8, Enum_ov017_021a5600_179632 = 0x2abd8 };
#else
enum { Enum_ov017_021a5600_76 = 0x4c, Enum_ov017_021a5600_9532 = 0x253c,
       Enum_ov017_021a5600_9552 = 0x2550, Enum_ov017_021a5600_173456 = 0x2a590, Enum_ov017_021a5600_179632 = 0x2bdb0 };
#endif
struct Struct_ov017_021a5600_2 {
    unsigned char unknown_0_, unknown_1_;
    char unknown_2_[6];
    int unknown_8_;
    SafeAllocator unknown_c_;
    unsigned char unknown_20_, unknown_21_;
    char unknown_22_[2];
    Struct_ov017_021a5600 unknown_24_;
};
extern "C" void func_0202738c(unsigned char*, int, int, int);
extern "C" void func_02027304(unsigned char*, int);
extern "C" void func_020a0cc4(int);
extern "C" void func_020a0c0c();
extern "C" void func_ov002_0215505c(char*);
extern "C" void func_ov002_02154d40(char*, SafeAllocator*);
extern "C" int func_ov002_02155960(char*, int);
extern "C" void func_ov002_021556fc(char*);
extern "C" void func_ov017_021a55b0(Struct_ov017_021a5600_2*);
extern "C" void func_ov017_02191108(GameResources*, int, int, int, int);
FlagWord02046708* GlobalFlags_GetInstance();
void GameObject_DisableControl(Obj020397cc*, int);
unsigned char* GetFieldIfFlag4_020100f8(char*);
void SetFlagsAt0x244_020a28a0(unsigned char*, unsigned char);
void ClearFlagBits_020a28b0(unsigned char*, int);
void ResetOrFindStopwatch_02027288(unsigned char*, int);
void* AllocatorUnion_AllocateRounded(AllocatorUnion*, unsigned int);
void PushInputLogA_020a1df8(int);
void PushInputLogB_020a1ef0(int);
extern "C" void _Z26SetBytes485And486_021556ecPvii(void*, int, int);
int ListContainsId(ListHead02046b60*, int);
void GameObject_EnableControl(void*);
void InitPaletteTables0202ac74();
int TestFlags02046708(FlagWord02046708*, unsigned int);
void SetByteIfDataAndCheckClear_021a01bc(unsigned char*);
void CopyByteField0x253To0x252_02039830(void*);
void CheckStackAndFinalize_021a5974(char*);
extern AllocatorUnion g_mainAllocator;
extern char* data_ov017_021d83ac;
// Overlay 17, originally func_ov017_021a5600 (USA/EUR 0x021a5600, JPN 0x021a6038)
extern "C" ARM void FieldTask_OpenMenu(BattleState021a5600* self) {
    GameState* game = GameState::GetInstance();
    GameResources* resources = GetGameResources();
    Obj020397cc* actor = (Obj020397cc*)game->GetUnknownGameObject();
    FlagWord02046708* flags = GlobalFlags_GetInstance();
    GameObject_DisableControl(actor, 1);
    actor->field_b2 = 0;
    SetFlags04(resources, 0xc0);
    unsigned char* action = GetFieldIfFlag4_020100f8((char*)game);
    SetFlagsAt0x244_020a28a0(action, 3);
    int ticks = game->GetTickCount();
    if (ticks < 0) ticks = 1;
    if (self->state == 0) {
        unsigned char* stopwatch = (unsigned char*)resources->unknown_ptr_36d0;
        ResetOrFindStopwatch_02027288(stopwatch, -1);
        func_0202738c(stopwatch, 1, 2, -1);
        func_020a0cc4(SceneReservationSize);
        void* memory = AllocatorUnion_AllocateRounded(&g_mainAllocator, SceneHeapSize);
        if (!memory) {
            func_020a0c0c();
            arg0->unknown_1_ = 1;
        } else {
            arg0->unknown_c_.CreateTypeA(var7, Enum_ov017_021a5600_173456);
            arg0->unknown_c_.Reset();
            func_020a1df8(2);
            func_020a1ef0(1);
            data_ov017_021d83ac = (char*)arg0->unknown_c_.Allocate(Enum_ov017_021a5600_9552);
            func_ov002_0215505c(data_ov017_021d83ac);
            func_ov002_021556ec(data_ov017_021d83ac, arg0->unknown_20_, arg0->unknown_21_);
            func_ov002_02154d40(data_ov017_021d83ac, &arg0->unknown_c_);
            Struct_ov017_021a5600 var8 = arg0->unknown_24_;
            char* var9 = data_ov017_021d83ac;
            *reinterpret_cast<unsigned char*>(var9 + Enum_ov017_021a5600_9532) = var8.unknown_0_;
            *reinterpret_cast<int*>(var9 + Enum_ov017_021a5600_9532 + 4) = var8.unknown_4_;
            *reinterpret_cast<int*>(var9 + Enum_ov017_021a5600_9532 + 8) = var8.unknown_8_;
            ++arg0->unknown_8_;
        }
    } else if (arg0->unknown_8_ == 1) {
        if (func_ov002_02155960(data_ov017_021d83ac, var5)) ++arg0->unknown_8_;
    } else if (arg0->unknown_8_ == 2) {
        func_ov002_021556fc(data_ov017_021d83ac);
        FontBankLoader* music = FontBankLoader_GetInstance();
        BlankFunction02094b40(music);
        FontBankLoader_CancelLoads(music);
        BlankFunction02094b34(music, 5000, 0x6f, 1, 1);
        ++self->state;
    } else if (self->state == 3) {
        unsigned int layer = *reinterpret_cast<unsigned int*>(data_ov017_021d83ac + SceneDisplayOffset);
        REG_DISPCNT = (layer << 8) | (REG_DISPCNT & ~0x1f00);
        data_ov017_021d83ac = 0;
        func_ov017_021a55b0(self);
        int clear = 1;
        ListHead02046b60* list = (ListHead02046b60*)resources->fieldTaskQueue_;
        if (list && (ListContainsId(list, 2) || ListContainsId(list, 47))) clear = 0;
        if (clear) {
            ClearFlagBits_020a28b0(action, 3);
            ClearFlags04(resources, 0xc0);
            GameObject_EnableControl(actor);
        }
        func_ov017_02191108(var1, 1, 1, 0, 1);
        func_0202ac74();
        func_020a0c0c();
        if (!func_02046708(var3, 0x100000)) {
            unsigned char* var14 = (unsigned char*)var1->unknown_ptr_36d0;
            func_0202738c(var14, 0, 2, -1);
            func_02027304(var14, -1);
        }
        SetByteIfDataAndCheckClear_021a01bc((unsigned char*)resources);
        GameObject_EnableControl(actor);
        CopyByteField0x253To0x252_02039830(actor);
        self->complete = 1;
        CheckStackAndFinalize_021a5974((char*)self);
    }
}
