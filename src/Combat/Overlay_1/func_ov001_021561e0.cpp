#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "World/ZoneChest.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/Brightness.h"


#if defined(jpn)
#define RG(u, j) (j)
#else
#define RG(u, j) (u)
#endif

struct Struct_ov001_021561e0_4 {
    char unknown_0_[8];
    unsigned short unknown_8_;
    unsigned short unknown_a_;
    char unknown_c_[0x44];
    unsigned short unknown_50_;
    char unknown_52_[RG(0x2a, 0x26)];
    SafeAllocator unknown_7c_;
    char unknown_90_[0x6c];
    unsigned char unknown_fc_;
    char unknown_fd_[6];
    unsigned char unknown_103_;
    char unknown_104_[2];
    unsigned char unknown_106_;
    char unknown_107_[0x13];
    unsigned short unknown_11a_;
    char unknown_11c_[8];
    SafeAllocator unknown_124_;
    SafeAllocator* unknown_138_;
    char unknown_13c_[0x20];
    int unknown_15c_;
    void* unknown_160_;
};
struct Struct_ov001_021561e0 { char unknown_0_[RG(0x5cac, 0x5a4c)]; unsigned char unknown_5cac_; };
struct Struct_ov001_021561e0_2 { Object3D unknown_0_; char unknown_ac_[RG(0xe0, 0xd4)]; unsigned int unknown_18c_; };
struct Struct_ov001_021561e0_3 { char unknown_0_[0x8c]; unsigned char unknown_8c_[1]; };
struct Struct_020fdd44;
struct Struct_02018300_2;
extern "C" int func_ov001_02153994();
extern "C" int* func_0202ae18();
extern "C" void func_ov001_0215aac8();
extern "C" void func_ov027_021d8c20(void*);
extern "C" void func_ov001_0215aaa8(int, int);
extern "C" void func_ov001_02154974(void*);
void AllocatorUnion_Free(AllocatorUnion*, void*);
void DestroyActiveAllocators_0215aa5c();
extern "C" void* Zone3D_GetInstance();
void* ZoneFeatures_GetFirstOfType(unsigned char*, unsigned int);
Entry_02028bd0* ZoneRecords_GetInstance();
Obj02028c64* FindInlineEntryById(Entry_02028bd0*, int);
void ZoneRecord_SetDoorOpened(Obj02028c64*, int);
extern "C" EventFlags021561e0* Scenario_GetInstance();
extern "C" void Scenario_SetFlag(void*, unsigned char*, int, int);
int CheckField0NonZero_0202b7d8(int*);
extern "C" int func_0202c508(void*);
extern "C" void func_ov017_021d0490(int);
extern AllocatorUnion g_mainAllocator;

// USA: func_ov001_021561e0
extern "C" ARM int func_ov001_021561e0(CleanupState021561e0* state) {
    if (InitAndCheckField3c_02153994() != 1) return state->state;
    state->complete = 1;
    if (!AlwaysTrue02094b4c(FontBankLoader_GetInstance())) return 11;
    GameResources* resources = GetGameResources();
    GameState* game = GameState::GetInstance();
    int* manager = func_0202ae18();
    if (state->resetGameFlag) ((GameFlag021561e0*)game)->active = 0;
    func_ov001_0215aac8();
    if (arg0->unknown_160_) {
        func_ov027_021d8c20(arg0->unknown_160_);
        arg0->unknown_160_ = 0;
    }
    if (arg0->unknown_50_ & 4) func_ov001_0215aaa8(1, 0);
    func_ov001_02154974(arg0);
    if ((arg0->unknown_50_ & 2) || (arg0->unknown_50_ & 8)) {
        SignedAllocatorHeader* var3 = arg0->unknown_124_.GetSignedAllocator();
        if (var3) {
            arg0->unknown_124_.Destroy();
            arg0->unknown_7c_.Free(var3);
        }
        if (state->externalAllocator) {
            SignedAllocatorHeader* external = state->externalAllocator->GetSignedAllocator();
            if (external) {
                state->externalAllocator->Destroy();
                AllocatorUnion_Free(&g_mainAllocator, external);
                state->externalAllocator = 0;
            }
        }
    }
    if (!TestFlags00(resources, 0x1000) || !state->keepResources) {
        SignedAllocatorHeader* buffer = state->allocator.GetSignedAllocator();
        if (buffer) {
            state->allocator.Destroy();
            AllocatorUnion_Free(&g_mainAllocator, buffer);
        }
        func_ov001_0215aa5c();
    }
    Zone3D* area = (Zone3D*)Zone3D_GetInstance();
    ZoneFeatures::Opcode6aEntry* node = (ZoneFeatures::Opcode6aEntry*)ZoneFeatures_GetFirstOfType((unsigned char*)&area->substruct_6c_, 2);
    while (node) {
        if (node->unk_2c.type2.flags & 0x200) {
            int index = Zone3D_GetDoorIndex(area, node);
            Obj02028c64* entry = FindInlineEntryById(ZoneRecords_GetInstance(), area->currentZoneID_);
            if (entry) ZoneRecord_SetDoorOpened(entry, index);
            node->unk_2c.type2.flags &= ~0x200;
        }
        var7 = var7->unknown_70_;
    }
    if (state->id == 0x730a) {
        EventFlags021561e0* events = Scenario_GetInstance();
        Scenario_SetFlag(events, events->flags, 0x1142, 0);
    }
    for (int var11 = 0; var11 < 4; ++var11) {
        Struct_ov001_021561e0_2* var12 = (Struct_ov001_021561e0_2*)func_0200ff1c(var1, var11);
        if (var12) {
            var12->unknown_0_.DisableFlag(0x800000);
            var12->unknown_18c_ &= ~2;
        }
    }
    if (!func_0202b7d8(var2) || func_0202c508(var2)) return 10;
    func_ov017_021d0490(0);
    arg0->unknown_fc_ = 0;
    arg0->unknown_103_ = 0;
    return 16;
}
