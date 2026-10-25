#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
#include <NitroSDK/Graphics.h>
#include "Resource/Brightness.h"


struct Struct_02018300_3;
struct Struct_02038598_5;
struct Struct_ov017_021b688c {
#if defined(jpn)
    char unknown_0_[0x218];
#else
    char unknown1_0_[0x330];
#endif
    unsigned int unknown_330_;
#if defined(jpn)
    char unknown_21c_[0x2a8 - 0x21c];
#else
    char unknown_334_[0x480 - 0x334];
#endif
    short unknown_480_;
    char unknown_482_[0x4a1 - 0x482];
    unsigned char unknown_4a1_;
    char unknown_4a2_[0x22];
};
struct Struct_ov017_021b688c_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    char unknown_2_[6];
    SafeAllocator unknown_8_;
    unsigned char unknown_1c_;
    unsigned char unknown_1d_;
    unsigned char unknown_1e_;
    unsigned char unknown_1f_;
    signed char unknown_20_;
    char unknown_21_[3];
    Struct_ov017_021b688c* unknown_24_;
};
struct PartySlots { char pad_0[0xf78]; signed char slots[4]; unsigned char count; };
void GameObject_DisableControl(Obj020397cc*, int);
int GetFieldIfFlag4_020100f8(char*);
void SetFlagsAt0x244_020a28a0(unsigned char*, unsigned char);
extern "C" void func_020a0cc4(int);
void* AllocatorUnion_AllocateRounded(AllocatorUnion*, unsigned int);
extern AllocatorUnion g_mainAllocator;
extern "C" void func_020a0c0c();
void PushInputLogA_020a1df8(int);
extern "C" void func_ov003_0215f9c0(MenuData*, int);
extern "C" void func_ov003_0215f8cc(MenuData*, SafeAllocator*);
void ClearIntAt0x23c_020a27b8(unsigned char*);
extern "C" int func_ov003_0215fce8(MenuData*, unsigned int);
extern "C" void func_ov003_0215fb94(MenuData*);
extern "C" void func_ov017_021b67d8(MenuWork*);
int ListContainsId(ListHead02046b60*, int);
void GameObject_EnableControl(void*);
extern "C" int func_ov017_021959b4();
void SetField0x23cTrue_020a27ac(void*);
void ClearFlagBits_020a28b0(unsigned char*, int);
extern "C" void* Scenario_GetInstance();
void* GameState_GetParty(GameState*);
extern "C" void func_0206e424(void*, int);

// Overlay 17, originally func_ov017_021b688c (USA/EUR 0x021b688c, JPN 0x021b6e40)
extern "C" ARM void FieldTask_PartyPlanning(MenuWork* work) {
    GameState* game = GameState::GetInstance();
    Obj020397cc* object = (Obj020397cc*)game->GetUnknownGameObject();
    GameObject_DisableControl(object, 1);
    GameResources* resources = game->GetResources();
    SetFlags04(resources, 0xc0);
    SetFlagsAt0x244_020a28a0((unsigned char*)GetFieldIfFlag4_020100f8((char*)game), 1);
    if (work->state == 0) {
        func_020a0cc4(0x1b800);
        void* memory = AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x1b800);
        if (!memory) {
            func_020a0c0c();
            arg0->unknown_1_ = 1;
            return;
        }
        arg0->unknown_8_.CreateTypeA(var3, 0x1b800);
        arg0->unknown_8_.Reset();
        arg0->unknown_24_ = (Struct_ov017_021b688c*)arg0->unknown_8_.Allocate(sizeof(Struct_ov017_021b688c));
        if (!arg0->unknown_24_) {
            func_020a0c0c();
            arg0->unknown_1_ = 1;
            return;
        }
        PushInputLogA_020a1df8(3);
        func_ov003_0215f9c0(work->data, work->mode);
        work->data->flags = work->flags;
        work->data->selection = work->selection;
        func_ov003_0215f8cc(work->data, &work->allocator);
        ClearIntAt0x23c_020a27b8((unsigned char*)GetFieldIfFlag4_020100f8((char*)game));
        work->state++;
    } else if (work->state == 1) {
        if (!func_ov003_0215fce8(work->data, game->GetTickCount())) return;
        FontBankLoader* global = FontBankLoader_GetInstance();
        BlankFunction02094b40(global);
        FontBankLoader_CancelLoads(global);
        BlankFunction02094b34(global, 0x6f, 0x1388, 1, 1);
        work->state++;
    } else if (work->state == 2) {
        if (!AlwaysTrue02094b4c(FontBankLoader_GetInstance())) return;
        func_ov003_0215fb94(work->data);
        work->state++;
    } else if (work->state == 3) {
        DISPCNT = (work->data->displayMode << 8) | (DISPCNT & ~0x1f00);
        work->state++;
        func_ov017_021b67d8(work);
        work->complete = 1;
        ListHead02046b60* list = (ListHead02046b60*)resources->fieldTaskQueue_;
        if (ListContainsId(list, 4) || ListContainsId(list, 0x18)) {
            GameObject_DisableControl(object, 1);
            return;
        }
        ClearFlags04(resources, 0xc0);
        GameObject_EnableControl(object);
        unsigned char* flags = (unsigned char*)GetFieldIfFlag4_020100f8((char*)game);
        if (!func_ov017_021959b4()) SetField0x23cTrue_020a27ac(flags);
        ClearFlagBits_020a28b0(flags, 2);
        void* party = Scenario_GetInstance();
        GameState_GetParty(game);
        PartySlots* slots = (PartySlots*)GameState_GetParty(game);
        for (int i = 0; i < slots->count; i++) func_0206e424(party, slots->slots[i]);
    }
}
