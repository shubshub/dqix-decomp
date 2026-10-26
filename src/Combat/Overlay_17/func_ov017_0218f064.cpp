#include <globaldefs.h>
#include <GameState/GameState.h>
#include <World/Zone3D.h>


struct Foo0207df50;
struct Struct_ov017_0218f064_6;
struct Struct_02048104;
struct Struct_02054664;
struct Struct_020415d8;
struct Bytes02033b88;
struct Struct_020545b8 {
    short id;
    unsigned short index;
    char unknown_4_[0x5d4];
    SafeAllocator allocator;
};
struct Struct_ov017_0218f064_8 { char bytes[0x70]; };
#if defined(jpn)
struct Struct_ov017_0218f064_9 { char unknown_0_[0x27c]; Struct_ov017_0218f064_8 blocks[22]; };
struct Struct_ov017_0218f064 { char unknown_0_[0x4114]; Object3D* first; Object3D* second; Object3D* third; Object3D* unknown_4340_; };
struct ZoneEntryContext0218f064 { char unknown_0_[0x1b58]; Struct_020545b8* special; char* unknown_1b5c_; };
struct ZoneOwner0218f064 {
    char unknown_0_[0x860];
    ZoneEntryContext0218f064 entries;
    ZoneEntryContext0218f064* GetEntries() { return &entries; }
};
#else
struct Struct_ov017_0218f064_9 { char unknown_0_[0x2cc]; Struct_ov017_0218f064_8 blocks[22]; };
struct Struct_ov017_0218f064 { char unknown_0_[0x4334]; Object3D* first; Object3D* second; Object3D* third; Object3D* unknown_4340_; };
struct Struct_ov017_0218f064_2 { char unknown_0_[0xb58]; Struct_020545b8* special; char* unknown_b5c_; };
struct ZoneOwner0218f064 { char unknown_0_[0x1840]; Struct_ov017_0218f064_2 tail; };
static inline Struct_ov017_0218f064_2* inline_ov017_0218f064(Zone3D* zone) { SDK_NULL_ASSERT(zone); return &((ZoneOwner0218f064*)zone)->tail; }
#endif
struct Ticket0218f064 { char unknown_0_[0x10]; Vector3i position; short rotation; };
struct Combatant0218f064 {
    Object3D object;
    char unknown_ac_[4];
    unsigned short unknown_b0_, unknown_b2_, field_b4;
#if defined(jpn)
    char unknown_b6_[0x148 - 0xb6];
#else
    char unknown1_b6_[0x9e];
#endif
    Struct_020545b8* entry;
    char unknown_158_[0x17a];
    unsigned char unknown_2d2_;
};
struct Struct_ov017_0218f064_7 { Object3D objects[11]; };
#if defined(jpn)
enum { Enum_ov017_0218f064_720 = 0x2c4, Enum_ov017_0218f064_724 = 0x2c8, Enum_ov017_0218f064_760 = 0x2ec };
#else
enum { Enum_ov017_0218f064_720 = 0x2d0, Enum_ov017_0218f064_724 = 0x2d4, Enum_ov017_0218f064_760 = 0x2f8 };
#endif
extern "C" void* GameState_GetZoneTransition(GameState*);
extern "C" Zone3D* Zone3D_GetInstance();
extern "C" void LinkSession_GetInstance();
extern "C" void VramState_Rewind(Foo0207df50*);
extern "C" void func_020545b8(Struct_020545b8*);
extern "C" void func_020542b4(Struct_020545b8*, SafeAllocator*, Struct_ov017_0218f064_8*);
extern "C" int func_ov017_021925e0();
extern "C" void* func_ov017_021a11b4(Struct_ov017_0218f064_6*);
extern "C" void func_02054464(Struct_020545b8*, SafeAllocator*, Struct_ov017_0218f064_8*);
extern "C" void GameObject_InitPartyMember(Combatant0218f064*);
extern "C" void func_02048104(Struct_02048104*);
extern "C" void func_02054664(Struct_02054664*);
extern "C" int func_ov017_02192548();
extern "C" void func_020415d8(Struct_020415d8*);
extern "C" void HaltSystem();
extern "C" void func_0200fd38(GameState*, int, GameObject*);
extern "C" void func_0203db34(unsigned char*, int, int, int);
extern "C" void GameObject_ForceMotionState(Bytes02033b88*, int);
extern "C" void func_02053c4c(char*, char*);
extern "C" void func_02053c74(char*, int);
extern "C" void func_ov017_0218f57c(void*, int);
extern "C" int func_ov017_0218f5a4(GameResources*, int, int, int, int);
#if defined(jpn)
#define data_ov017_021d73a4 data_ov017_021d7804
#endif
extern const char data_ov017_021d73a4[];

static inline Struct_ov017_0218f064_8* inline_ov017_0218f064_2(GameResources* resources) { SDK_NULL_ASSERT(resources); return ((Struct_ov017_0218f064_9*)resources)->blocks; }

// USA: func_ov017_0218f064
// JPN: func_ov017_0218fc44
extern "C" ARM void func_ov017_0218f064(GameResources* resources, int id, int kind, int arg3, int mode) {
    GameState* game = GameState::GetInstance();
#if !defined(jpn)
    Zone3D* zone;
#endif
    Ticket0218f064* ticket = (Ticket0218f064*)GameState_GetZoneTransition(game);
#if defined(jpn)
    ZoneEntryContext0218f064* entries = ((ZoneOwner0218f064*)Zone3D_GetInstance())->GetEntries();
#else
    zone = Zone3D_GetInstance();
#endif
    LinkSession_GetInstance();
    int var4 = 1;
    SafeAllocator* allocator;
    Struct_020545b8* entry;
    if (kind == 0x4000) {
#if defined(jpn)
        entry = entries->special;
#else
        entry = inline_ov017_0218f064(zone)->special;
#endif
        if (!entry) return;
        SafeAllocator* var7 = resources->allocator_array_1a0;
        SafeAllocator* specialAllocator = &var7[3];
        allocator = &entry->allocator;
        Struct_ov017_0218f064_8* blocks = inline_ov017_0218f064_2(resources);
        specialAllocator->Reset();
        Struct_ov017_0218f064_8* block = &blocks[21];
        VramState_Rewind((Foo0207df50*)block);
        func_020545b8(entry);
        func_020542b4(entry, specialAllocator, block);
    } else {
        if (func_ov017_021925e0()) {
            for (int i = 0; i < 4; ++i) {
                if (((Struct_020545b8*)&resources->substruct_array_12c8[i])->id == id) return;
            }
        }
        entry = (Struct_020545b8*)func_ov017_021a11b4((Struct_ov017_0218f064_6*)resources);
        if (!entry) return;
        allocator = &entry->allocator;
        int index = entry->index + 1;
        SafeAllocator* primary = &resources->allocator_array_38[index];
        Struct_ov017_0218f064_8* block = &((Struct_ov017_0218f064_9*)resources)->blocks[index];
        func_020545b8(entry);
        if (kind == 4) func_02054464(entry, primary, block);
        else func_020542b4(entry, primary, block);
    }
    Struct_ov017_0218f064* var15 = (Struct_ov017_0218f064*)resources;
    if (var15->first) { var15->first->Destroy(); var15->first = 0; }
    if (var15->second) { var15->second->Destroy(); var15->second = 0; }
    if (var15->third) { var15->third->Destroy(); var15->third = 0; }
    if (var15->unknown_4340_) { var15->unknown_4340_->Destroy(); var15->unknown_4340_ = 0; }
    allocator->Reset();
    Combatant0218f064* combatant = 0;
    if (kind == 0x800) {
        combatant = (Combatant0218f064*)allocator->Allocate(Enum_ov017_0218f064_720);
        GameObject_InitPartyMember(combatant);
    } else if (kind == 0x200) {
        combatant = (Combatant0218f064*)allocator->Allocate(Enum_ov017_0218f064_720);
        func_02048104((Struct_02048104*)combatant);
    } else if (kind == 0x1000) {
        combatant = (Combatant0218f064*)allocator->Allocate(Enum_ov017_0218f064_724);
        func_02054664((Struct_02054664*)combatant);
        if (combatant) combatant->unknown_2d2_ = func_ov017_02192548();
    } else if (kind == 0x4000) {
        combatant = (Combatant0218f064*)allocator->Allocate(Enum_ov017_0218f064_760);
        func_020415d8((Struct_020415d8*)combatant);
    } else if (kind == 4) {
        combatant = (Combatant0218f064*)allocator->Allocate(Enum_ov017_0218f064_724);
        func_02054664((Struct_02054664*)combatant);
        if (combatant) combatant->unknown_2d2_ = func_ov017_02192548();
        var4 = 0;
    }
    if (!combatant) HaltSystem();
    combatant->object.actorIndex_ = (short)id;
    combatant->entry = entry;
    entry->id = (short)id;
    func_0200fd38(game, id, (GameObject*)combatant);
    if (var4) {
        Struct_ov017_0218f064_7* components = (Struct_ov017_0218f064_7*)allocator->Allocate(0x764);
        if (!components) HaltSystem();
        components->objects[0].Initialize();
        components->objects[2].Initialize();
        components->objects[1].Initialize();
        components->objects[3].Initialize();
        components->objects[4].Initialize();
        components->objects[5].Initialize();
        Object3D* var18 = &components->objects[6];
        var18->Initialize();
        Object3D* var19 = &components->objects[7];
        var19->Initialize();
        components->objects[8].Initialize();
        Object3D* var20 = &components->objects[9];
        var20->Initialize();
        Object3D* var21 = &components->objects[10];
        var21->Initialize();
        int base = id * 12;
        func_0200fd38(game, base + 0x13, (GameObject*)&components->objects[0]);
        func_0200fd38(game, base + 0x14, (GameObject*)&components->objects[1]);
        func_0200fd38(game, base + 0x15, (GameObject*)&components->objects[2]);
        func_0200fd38(game, base + 0x16, (GameObject*)&components->objects[3]);
        func_0200fd38(game, base + 0x17, (GameObject*)&components->objects[5]);
        func_0200fd38(game, base + 0x18, (GameObject*)var18);
        func_0200fd38(game, base + 0x19, (GameObject*)var19);
        func_0200fd38(game, base + 0x1a, (GameObject*)&components->objects[8]);
        func_0200fd38(game, base + 0x1b, (GameObject*)&components->objects[4]);
        func_0200fd38(game, base + 0x1c, (GameObject*)var20);
        func_0200fd38(game, base + 0x1d, (GameObject*)var21);
    }
    combatant->unknown_b0_ = 0x324;
    combatant->field_b4 = 0x189;
    combatant->object.SetHeight(0x1800);
    combatant->object.SetRadius(0x1000);
    combatant->object.SetAnimationByName(data_ov017_021d73a4, 0);
    combatant->object.position_ = ticket->position;
    func_0203db34((unsigned char*)combatant, combatant->object.rotation_.x, ticket->rotation, combatant->object.rotation_.z);
    GameObject_ForceMotionState((Bytes02033b88*)combatant, 0);
    if (kind == 0x4000) {
#if defined(jpn)
        char* var23 = entries->unknown_1b5c_;
#else
        char* var23 = inline_ov017_0218f064(zone)->unknown_b5c_;
#endif
        if (var23) func_02053c4c((char*)combatant, var23);
    } else func_02053c74((char*)combatant, id);
    if (mode > 0) func_ov017_0218f57c(combatant, mode);
    if (arg3) func_ov017_0218f5a4(resources, id, 0, 0, 0);
}

#if defined(jpn)
#undef data_ov017_021d73a4
#endif
