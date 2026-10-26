#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
#include <NitroSDK/Graphics.h>
#include "Resource/Brightness.h"


struct Obj020397cc;
struct ListHead02046b60;
struct Struct_ov017_021b688c {
#if defined(jpn)
    char unknown_0_[0x218];
#else
    char unknown1_0_[0x330];
#endif
    unsigned int displayMode;
#if defined(jpn)
    char unknown_21c_[0x2a8 - 0x21c];
#else
    char unknown_334_[0x480 - 0x334];
#endif
    short selection;
    char unknown_482_[0x4a1 - 0x482];
    unsigned char flags;
    char unknown_4a2_[0x22];
};
struct MenuWork {
    unsigned char field_0;
    unsigned char unknown_1_;
    char unknown_2_[6];
    SafeAllocator allocator;
    unsigned char mode;
    unsigned char state;
    unsigned char unknown_1e_;
    unsigned char flags;
    signed char selection;
    char unknown_21_[3];
    Struct_ov017_021b688c* data;
};
struct PartySlots { char unknown_0_[0xf78]; signed char slots[4]; unsigned char count; };
extern "C" void GameObject_DisableControl(Obj020397cc*, int);
extern "C" int GameState_GetFollowCamera(char*);
extern "C" void func_020a28a0(unsigned char*, unsigned char);
extern "C" void func_020a0cc4(int);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion*, unsigned int);
extern AllocatorUnion g_mainAllocator;
extern "C" void ROMFilesystem_InitFileTables();
extern "C" void func_020a1df8(int);
extern "C" void func_ov003_0215f9c0(Struct_ov017_021b688c*, int);
extern "C" void func_ov003_0215f8cc(Struct_ov017_021b688c*, SafeAllocator*);
extern "C" void func_020a27b8(unsigned char*);
extern "C" int func_ov003_0215fce8(Struct_ov017_021b688c*, unsigned int);
extern "C" void func_ov003_0215fb94(Struct_ov017_021b688c*);
extern "C" void func_ov017_021b67d8(MenuWork*);
extern "C" int func_02046b60(ListHead02046b60*, int);
extern "C" void GameObject_EnableControl(void*);
extern "C" int func_ov017_021959b4();
extern "C" void func_020a27ac(void*);
extern "C" void func_020a28b0(unsigned char*, int);
extern "C" void* Scenario_GetInstance();
extern "C" void* GameState_GetParty(GameState*);
extern "C" void func_0206e424(void*, int);

// Overlay 17, originally func_ov017_021b688c (USA/EUR 0x021b688c, JPN 0x021b6e40)
extern "C" ARM void FieldTask_PartyPlanning(MenuWork* work) {
    GameState* game = GameState::GetInstance();
    Obj020397cc* object = (Obj020397cc*)game->GetLeader();
    GameObject_DisableControl(object, 1);
    GameResources* resources = game->GetResources();
    SetFlags04(resources, 0xc0);
    func_020a28a0((unsigned char*)GameState_GetFollowCamera((char*)game), 1);
    if (work->state == 0) {
        func_020a0cc4(0x1b800);
        void* memory = AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x1b800);
        if (!memory) {
            ROMFilesystem_InitFileTables();
            work->unknown_1_ = 1;
            return;
        }
        work->allocator.CreateTypeA(memory, 0x1b800);
        work->allocator.Reset();
        work->data = (Struct_ov017_021b688c*)work->allocator.Allocate(sizeof(Struct_ov017_021b688c));
        if (!work->data) {
            ROMFilesystem_InitFileTables();
            work->unknown_1_ = 1;
            return;
        }
        func_020a1df8(3);
        func_ov003_0215f9c0(work->data, work->mode);
        work->data->flags = work->flags;
        work->data->selection = work->selection;
        func_ov003_0215f8cc(work->data, &work->allocator);
        func_020a27b8((unsigned char*)GameState_GetFollowCamera((char*)game));
        work->state++;
    } else if (work->state == 1) {
        if (!func_ov003_0215fce8(work->data, game->GetTickCount())) return;
        FontBankLoader* global = FontBankLoader_GetInstance();
        func_02094b40(global);
        FontBankLoader_CancelLoads(global);
        func_02094b34(global, 0x6f, 0x1388, 1, 1);
        work->state++;
    } else if (work->state == 2) {
        if (!func_02094b4c(FontBankLoader_GetInstance())) return;
        func_ov003_0215fb94(work->data);
        work->state++;
    } else if (work->state == 3) {
        DISPCNT = (work->data->displayMode << 8) | (DISPCNT & ~0x1f00);
        work->state++;
        func_ov017_021b67d8(work);
        work->unknown_1_ = 1;
        ListHead02046b60* list = (ListHead02046b60*)resources->fieldTaskQueue_;
        if (func_02046b60(list, 4) || func_02046b60(list, 0x18)) {
            GameObject_DisableControl(object, 1);
            return;
        }
        ClearFlags04(resources, 0xc0);
        GameObject_EnableControl(object);
        unsigned char* flags = (unsigned char*)GameState_GetFollowCamera((char*)game);
        if (!func_ov017_021959b4()) func_020a27ac(flags);
        func_020a28b0(flags, 2);
        void* party = Scenario_GetInstance();
        GameState_GetParty(game);
        PartySlots* slots = (PartySlots*)GameState_GetParty(game);
        for (int i = 0; i < slots->count; i++) func_0206e424(party, slots->slots[i]);
    }
}
