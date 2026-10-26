#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "Combat/SearchEntry.h"
#include "Filesystem/BackgroundLoader.h"
#include "Graphics/LightingManager.h"
#include "Memory/SafeAllocator.h"
#include "Resource/Brightness.h"


struct SearchStruct0202c1a4;
struct Obj02033874;
struct Struct_02053f7c_3;
struct StructDE1D4 { char data[0x20]; };

extern "C" void* LinkSession_GetInstance(void);
extern "C" void* Zone3D_GetInstance(void);
extern "C" void LinkSession_UpdateMemberCount(void*);
extern "C" void GameObject_SetLineLeader(unsigned char*, int);
extern "C" int LinkSession_IsSlotMember(SearchStruct* obj, int value);
extern "C" signed char LinkSession_GetOwnSlot(SearchStruct0202c1a4* obj);
extern "C" void Party_ReformLine(GameResources*, int, int, int, int);
extern "C" void func_ov017_021907dc(int, int, int, int, int);
extern "C" signed char GameObject_GetLineLeader(void*);
extern "C" void GameObject_SnapFacing(Obj02033874*, int);
extern "C" void func_020120d4(unsigned char*, unsigned char);
extern "C" void* GameState_GetPlayerLocation(char* p, unsigned int index);
extern "C" void func_0201206c(void*, int);
extern "C" void func_02053f7c(Struct_02053f7c_3*, unsigned short, int);
extern "C" void* Scenario_GetInstance(void);
extern "C" void func_0206dfe8(void*, int, int);
extern "C" void func_0206e70c(char*);
extern "C" void func_0206df14(unsigned char*);
extern "C" float func_020103e8(GameState*);
extern "C" void func_ov017_0219bcac(unsigned char);
extern "C" unsigned char* GameState_GetZoneTransition(GameState*);
extern "C" void* func_02094d6c();
extern "C" void* func_020965f8();
extern "C" void* ItemTable_Construct(void*);
extern "C" void ItemTable_Init(void*);
extern "C" void ItemRecord_Clear(StructDE1D4*);
extern "C" void* ExtractFileFromGP2(const char* arg0, const char* innerFilePath, unsigned int* outSize);
#if defined(jpn)
extern "C" void* func_020e08f0(int index, unsigned int* outLength);
#endif
extern "C" int func_020def44(int, int, int, short);
extern "C" void func_0207cbe8(char*);
extern "C" void func_0207cc18(void*, void*);
extern "C" void* GameState_GetParty(GameState*);
struct KeyMap020a095c;
extern "C" void func_020a095c(KeyMap020a095c*, int, int);
extern "C" void func_020dbc5c(char*, int);
extern "C" int GameState_GetLeaderIndex(GameState*);
extern "C" void func_ov017_021cee78(int, unsigned char);
extern "C" void func_ov017_02191234(GameResources*);

extern const char* data_020f2a18;
extern const char* data_020f2a0c;

struct Struct_ov017_021b0bc0 {
    char pad0[0x1b34];
    int unknown_1b34_;
    int unknown_1b38_;
    int unknown_1b3c_;
    char unknown_1b40_[0x1b48 - 0x1b40];
    int unknown_1b48_;
    char unknown_1b4c_[0x1b61 - 0x1b4c];
    unsigned char unknown_1b61_;
#if defined(jpn)
    char unknown_1b62_[0x1f94 - 0x1b62];
#else
    char unknown1_1b62_[0x1f74 - 0x1b62];
#endif
    unsigned short unknown_1f74_;
    unsigned short unknown_1f76_;
};

struct Zone021b0bc0 {
#if defined(jpn)
    char pad0[0x860];
#else
    char pad0[0x840];
#endif
    Struct_ov017_021b0bc0 state;
};

static inline Struct_ov017_021b0bc0* inline_ov017_021b0bc0(Zone021b0bc0* zone) {
    return &zone->state;
}

static inline void inline_ov017_021b0bc0_2(Struct_ov017_021b0bc0* state, int v) { state->unknown_1b34_ = v; }
static inline void inline_ov017_021b0bc0_3(Struct_ov017_021b0bc0* state, int v) { state->unknown_1b38_ = v; }
static inline void inline_ov017_021b0bc0_4(Struct_ov017_021b0bc0* state, int v) { state->unknown_1b3c_ = v; }
static inline void inline_ov017_021b0bc0_5(Struct_ov017_021b0bc0* state, int v) { state->unknown_1b48_ = v; }
static inline void inline_ov017_021b0bc0_6(Struct_ov017_021b0bc0* state, unsigned char v) { state->unknown_1b61_ = v; }

struct Struct_ov017_021b0bc0_3 {
    unsigned char f0;
    char pad1[3];
    char unknown_4_[0x190];
    char unknown_194_[0x110];
    char block2a4[0x20];
    int unknown_2c4_;
    int unknown_2c8_;
    int unknown_2cc_;
    unsigned short unknown_2d0_;
    unsigned short unknown_2d2_;
    unsigned char unknown_2d4_;
    unsigned char unknown_2d5_;
    unsigned short ids[4];
};

struct Struct_ov017_021b0bc0_4 {
    char pad0;
    unsigned char done;
    char pad2[2];
    signed char* kind;
    char pad8;
    unsigned char mode;
    char padA[2];
    unsigned char leader;
#if defined(jpn)
    char padD[0x214 - 0xd];
#else
    char padD[0x284 - 0xd];
#endif
    unsigned char unknown_284_;
    char unknown_285_[3];
    Struct_ov017_021b0bc0_3* unknown_288_;
};

struct Struct_ov017_021b0bc0_5 {
    SafeAllocator allocator;
    char list[0x18];
    void* containerData;
    int unknown_30_;
    int field34;
};

// USA: func_ov017_021b0bc0
// JPN: func_ov017_021b1258
extern "C" ARM void func_ov017_021b0bc0(Struct_ov017_021b0bc0_4* self) {
    char list[0x18];
    StructDE1D4 entry;
    Struct_ov017_021b0bc0_5 context;
    short ys[4];
    unsigned int size;

    GameState* gs = GameState::GetInstance();
    GameResources* res = GetGameResources();
    SearchStruct* search = (SearchStruct*)LinkSession_GetInstance();
    Zone021b0bc0* zone = (Zone021b0bc0*)Zone3D_GetInstance();
#if defined(jpn)
    Struct_ov017_021b0bc0* state = inline_ov017_021b0bc0(zone);
#endif
    LinkSession_UpdateMemberCount(search);

    int show = 1;
    if (self->kind != NULL && *self->kind == 10) {
        show = 0;
    }
    GameObject* leader = gs->GetPartyMemberByIndex(self->leader);
    if (leader != NULL) {
        GameObject_SetLineLeader((unsigned char*)leader, leader->obj3D_.actorIndex_);
    }
    short* y = ys;
    for (int i = 0; i < 4; i++, y++) {
        GameObject* member = gs->GetPartyMemberByIndex(i);
        if (member != NULL) {
            *y = *(short*)((char*)member + 0xae);
        }
    }

    for (int i = 0; i < 4; i++) {
        if (LinkSession_IsSlotMember(search, i) == 0) {
            continue;
        }
        if (i == LinkSession_GetOwnSlot((SearchStruct0202c1a4*)search)) {
            if (self->unknown_284_ == 0) {
                show = 0;
            }
            Party_ReformLine(res, 1, show, 1, 1);
        } else {
            func_ov017_021907dc((int)res, i, 1, show, 1);
        }
    }

    if (self->mode == 2) {
        y = ys;
        for (int i = 0; i < 4; i++, y++) {
            GameObject* member = gs->GetPartyMemberByIndex(i);
            if (member == NULL) {
                continue;
            }
            if (i == GameObject_GetLineLeader(member)) {
                continue;
            }
            if (i != 0 && !(member->obj3D_.unknown_0_ & 0x1000)) {
                continue;
            }
            GameObject_SnapFacing((Obj02033874*)member, *y);
        }
        ClearFlags00(res, 0x40);

        Struct_ov017_021b0bc0_3* snap = self->unknown_288_;
        func_020120d4((unsigned char*)gs, snap->f0);
#if defined(jpn)
        memcpy((char*)gs + 0x5a7c, snap->unknown_4_, sizeof(snap->unknown_4_));
        memcpy((char*)gs + 0x5c0c, snap->unknown_194_, sizeof(snap->unknown_194_));
#else
        memcpy((char*)gs + 0x5cdc, snap->unknown_4_, sizeof(snap->unknown_4_));
        memcpy((char*)gs + 0x5e6c, snap->unknown_194_, sizeof(snap->unknown_194_));
#endif
        memcpy(GameState_GetPlayerLocation((char*)gs, 0), snap->block2a4, sizeof(snap->block2a4));
        func_0201206c(gs, snap->unknown_2c4_);
#if defined(jpn)
        inline_ov017_021b0bc0_2(state, snap->unknown_2c8_);
        inline_ov017_021b0bc0_5(state, snap->unknown_2cc_);
        inline_ov017_021b0bc0_3(state, snap->unknown_2d0_);
        inline_ov017_021b0bc0_4(state, (unsigned char)snap->unknown_2d2_);
        inline_ov017_021b0bc0_6(state, 0);
#else
        inline_ov017_021b0bc0_2(inline_ov017_021b0bc0(zone), snap->unknown_2c8_);
        inline_ov017_021b0bc0_5(inline_ov017_021b0bc0(zone), snap->unknown_2cc_);
        inline_ov017_021b0bc0_3(inline_ov017_021b0bc0(zone), snap->unknown_2d0_);
        inline_ov017_021b0bc0_4(inline_ov017_021b0bc0(zone), (unsigned char)snap->unknown_2d2_);
        inline_ov017_021b0bc0_6(inline_ov017_021b0bc0(zone), 0);
#endif
        zone->state.unknown_1f74_ = snap->unknown_2d4_;
        zone->state.unknown_1f76_ = snap->unknown_2d5_;
        for (int i = 0; i < 4; i++) {
            GameObject* member = gs->GetPartyMemberByIndex(i);
            if (member != NULL) {
                func_02053f7c((Struct_02053f7c_3*)member, snap->ids[i], 1);
            }
        }

        void* save = Scenario_GetInstance();
        func_0206dfe8(save, 0x38e, 0x3e8);
        func_0206dfe8(save, 0x79e, 0x2bc);
        func_0206e70c((char*)save);
        func_0206df14((unsigned char*)save);
        gs->SetDayTimer(func_020103e8(gs));
        LightingManager* lighting = LightingManager::GetInstance();
        lighting->dayNightTimer_ = gs->GetDayTimer();
        lighting->timeOfDayIndex_ = gs->GetTimeOfDay();
        func_ov017_0219bcac(1);
        GameState_GetZoneTransition(gs)[0xa] = 0;
        func_02094d6c();
        func_020965f8();

        ItemTable_Construct(list);
        ItemTable_Init(list);
        ItemRecord_Clear(&entry);
        BackgroundLoader::AddLockGlobal();
#if defined(jpn)
        void* data = func_020e08f0(8, &size);
#else
        void* data = ExtractFileFromGP2(data_020f2a18, data_020f2a0c, &size);
#endif
        if (data != NULL) {
            func_020def44((int)&entry, (int)data, size, 0x5612);
        }
        BackgroundLoader::RemoveLockGlobal();
        context.allocator.ResetAllocatorPointer();
        ItemTable_Construct(context.list);
        func_0207cbe8((char*)&context);
        func_0207cbe8((char*)&context);
        func_0207cc18(&context, &entry);
        func_020a095c((KeyMap020a095c*)GameState_GetParty(gs), 0x5612, 1);
    } else if (self->mode == 0) {
        func_020dbc5c((char*)res, self->leader);
        unsigned char* slots = (unsigned char*)GameState_GetParty(gs) + 0xf78;
        for (int i = 0; i < 4; i++, slots++) {
            unsigned char id = *slots;
            if (id != GameState_GetLeaderIndex(gs)) {
                func_ov017_021cee78(id, 0);
            }
        }
    }

    func_ov017_02191234(res);
    self->done = 1;
}
