#include <globaldefs.h>
#include "Combat/BattleHeapOwner.h"
#include "Resource/FontBankLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "NitroSDK/Graphics.h"
#include "Resource/Brightness.h"

struct Struct_02018300_3;
struct Struct_ov017_021b2c88;

void GameObject_DisableControl(Obj020397cc* obj, int arg1);
int GameState_GetFollowCamera(char* obj);
void SetFlagsAt0x244_020a28a0(unsigned char* obj, unsigned char mask);
void ClearFlagBits_020a28b0(unsigned char* obj, int mask);
void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
void PushInputLogA_020a1df8(int id);
void PushInputLogB_020a1ef0(int id);
void GameObject_EnableControl(void* obj);
extern "C" void func_020a0cc4(unsigned int size, int ticks);
extern "C" void ROMFilesystem_InitFileTables(void);
extern "C" void func_ov003_02174114(void* obj);
extern "C" int func_ov003_021745fc(void* obj);
extern "C" void func_ov003_02174454(void* obj);
extern "C" void func_ov017_021b2c88(Obj021b2c88* self);

struct Struct_ov017_021b2ce8 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    char unknown_2_[6];
    int unknown_8_;
    SafeAllocator unknown_c_;
};

extern AllocatorUnion g_mainAllocator;

// Overlay 17, originally func_ov017_021b2ce8 (USA/EUR 0x021b2ce8, JPN 0x021b33f8)
extern "C" ARM void FieldTask_VisitShop(Task_021b2ce8* self) {
#if defined(jpn)
 enum { Enum_ov017_021b2ce8_4176 = 0xfcc };
#else
 enum { Enum_ov017_021b2ce8_4176 = 0x1050 };
#endif
    GameState* gs = GameState::GetInstance();
    GameResources* res = gs->GetResources();
    SetFlags04(res, 0xc0);
    GameObject* leader = gs->GetLeader();
    GameObject_DisableControl((Obj020397cc*)leader, 1);
    unsigned char* camera = (unsigned char*)GameState_GetFollowCamera((char*)gs);
    SetFlagsAt0x244_020a28a0(camera, 3);
    int ticks = gs->GetTickCount();
    if (ticks < 0) {
        ticks = 1;
    }

    if (self->state == 0) {
        func_020a0cc4(0x33820, ticks);
        void* buffer = AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x32000);
        if (buffer == NULL) {
            ROMFilesystem_InitFileTables();
            self->done = 1;
            return;
        }
        arg0->unknown_c_.CreateTypeA(var5, 0x32000);
        arg0->unknown_c_.Reset();
        data_ov017_021d840c = static_cast<Struct_ov003_02173f70*>(arg0->unknown_c_.Allocate(Enum_ov017_021b2ce8_4176));
        if (data_ov017_021d840c == NULL) {
            ROMFilesystem_InitFileTables();
            self->done = 1;
            return;
        }
        func_020a1df8(3);
        func_020a1ef0(1);
        func_ov003_02174114(data_ov017_021d840c);
        func_ov003_02173f70(data_ov017_021d840c, &arg0->unknown_c_);
        SetFlags00(var1, 0x6000);
        arg0->unknown_8_++;
    } else if (arg0->unknown_8_ == 1) {
        if (func_ov003_021745fc(data_ov017_021d840c)) {
            FontBankLoader* g = FontBankLoader_GetInstance();
            BlankFunction02094b40(g);
            FontBankLoader_CancelLoads(g);
            BlankFunction02094b34(g, 0x6f, 5000, 1, 1);
            self->state++;
        }
    } else if (self->state == 2) {
        if (AlwaysTrue02094b4c(FontBankLoader_GetInstance())) {
            func_ov003_02174454(data_ov017_021d840c);
            arg0->unknown_8_++;
        }
    } else {
        ClearFlags04(res, 0xc0);
        DISPCNT = (data_ov017_021d840c->bgMode << 8) | (DISPCNT & ~0x1f00);
        ClearFlagBits_020a28b0(camera, 3);
        func_ov017_021b2c88((Obj021b2c88*)self);
        ROMFilesystem_InitFileTables();
        self->done = 1;
        ClearFlags00(res, 0x6000);
        GameObject_EnableControl(leader);
    }
}
