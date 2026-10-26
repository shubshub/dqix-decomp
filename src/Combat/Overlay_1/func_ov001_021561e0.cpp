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
    char field_0[8];
    unsigned short id;
    unsigned short state;
    char unknown_c_[0x44];
    unsigned short flags;
    char unknown_52_[RG(0x2a, 0x26)];
    SafeAllocator allocator;
    char unknown_90_[0x6c];
    unsigned char active;
    char unknown_fd_[6];
    unsigned char pending;
    char unknown_104_[2];
    unsigned char unknown_106_;
    char unknown_107_[0x13];
    unsigned short unknown_11a_;
    char unknown_11c_[8];
    SafeAllocator unknown_124_;
    SafeAllocator* externalAllocator;
    char unknown_13c_[0x20];
    int unknown_15c_;
    void* allocation;
};
struct Struct_ov001_021561e0 { char field_0[RG(0x5cac, 0x5a4c)]; unsigned char active; };
struct Struct_ov001_021561e0_2 { Object3D object; char field_ac[RG(0xe0, 0xd4)]; unsigned int flags; };
struct EventFlags021561e0 { char field_0[0x8c]; unsigned char flags[1]; };
struct Entry_02028bd0;
struct Obj02028c64;
extern "C" int func_ov001_02153994();
extern "C" int* LinkSession_GetInstance();
extern "C" void func_ov001_0215aac8();
extern "C" void func_ov027_021d8c20(void*);
extern "C" void func_ov001_0215aaa8(int, int);
extern "C" void func_ov001_02154974(void*);
extern "C" void AllocatorUnion_Free(AllocatorUnion*, void*);
extern "C" void func_ov001_0215aa5c();
extern "C" void* Zone3D_GetInstance();
extern "C" void* ZoneFeatures_GetFirstOfType(unsigned char*, unsigned int);
extern "C" Entry_02028bd0* ZoneRecords_GetInstance();
extern "C" Obj02028c64* ZoneRecords_Find(Entry_02028bd0*, int);
extern "C" void ZoneRecord_SetDoorOpened(Obj02028c64*, int);
extern "C" EventFlags021561e0* Scenario_GetInstance();
extern "C" void Scenario_SetFlag(void*, unsigned char*, int, int);
extern "C" int LinkSession_IsActive(int*);
extern "C" int LinkSession_IsHostOrSolo(void*);
extern "C" void func_ov017_021d0490(int);
extern AllocatorUnion g_mainAllocator;

// USA: func_ov001_021561e0
extern "C" ARM int func_ov001_021561e0(Struct_ov001_021561e0_4* state) {
    if (func_ov001_02153994() != 1) return state->state;
    state->unknown_106_ = 1;
    if (!func_02094b4c(FontBankLoader_GetInstance())) return 11;
    GameResources* resources = GetGameResources();
    GameState* game = GameState::GetInstance();
    int* manager = LinkSession_GetInstance();
    if (state->unknown_15c_) ((Struct_ov001_021561e0*)game)->active = 0;
    func_ov001_0215aac8();
    if (state->allocation) {
        func_ov027_021d8c20(state->allocation);
        state->allocation = 0;
    }
    if (state->flags & 4) func_ov001_0215aaa8(1, 0);
    func_ov001_02154974(state);
    if ((state->flags & 2) || (state->flags & 8)) {
        SignedAllocatorHeader* buffer = state->unknown_124_.GetSignedAllocator();
        if (buffer) {
            state->unknown_124_.Destroy();
            state->allocator.Free(buffer);
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
    if (!TestFlags00(resources, 0x1000) || !state->unknown_11a_) {
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
            Obj02028c64* entry = ZoneRecords_Find(ZoneRecords_GetInstance(), area->currentZoneID_);
            if (entry) ZoneRecord_SetDoorOpened(entry, index);
            node->unk_2c.type2.flags &= ~0x200;
        }
        node = node->pNext;
    }
    if (state->id == 0x730a) {
        EventFlags021561e0* events = Scenario_GetInstance();
        Scenario_SetFlag(events, events->flags, 0x1142, 0);
    }
    for (int i = 0; i < 4; ++i) {
        Struct_ov001_021561e0_2* member = (Struct_ov001_021561e0_2*)func_0200ff1c(game, i);
        if (member) {
            member->object.DisableFlag(0x800000);
            member->flags &= ~2;
        }
    }
    if (!LinkSession_IsActive(manager) || LinkSession_IsHostOrSolo(manager)) return 10;
    func_ov017_021d0490(0);
    state->active = 0;
    state->pending = 0;
    return 16;
}
