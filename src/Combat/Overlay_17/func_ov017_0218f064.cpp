#include <globaldefs.h>
#include <GameState/GameState.h>
#include <World/Zone3D.h>

#if defined(jpn)
#define func_020c9be0 func_020cb6ac
#endif

struct Struct_0203d028;
struct Struct_ov017_0218f064_6;
struct Struct_02048104;
struct Struct_02054664;
struct Struct_020415d8;
struct Struct_02010604;
struct Struct_020545b8 {
    short unknown_0_;
    unsigned short unknown_2_;
    char unknown_4_[0x5d4];
    SafeAllocator unknown_5d8_;
};
struct Struct_ov017_0218f064_8 { char unknown_0_[0x70]; };
#if defined(jpn)
struct Struct_ov017_0218f064_9 { char unknown_0_[0x27c]; Struct_ov017_0218f064_8 unknown_2cc_[22]; };
struct Struct_ov017_0218f064 { char unknown_0_[0x4114]; Object3D* unknown_4334_; Object3D* unknown_4338_; Object3D* unknown_433c_; Object3D* unknown_4340_; };
struct Struct_ov017_0218f064_10 { char unknown_0_[0x1b58]; Struct_020545b8* unknown_1b58_; char* unknown_1b5c_; };
struct Struct_ov017_0218f064_3 {
    char unknown_0_[0x860];
    Struct_ov017_0218f064_10 unknown_860_;
    Struct_ov017_0218f064_10* inline_ov017_0218f064_3() { return &unknown_860_; }
};
#else
struct Struct_ov017_0218f064_9 { char unknown_0_[0x2cc]; Struct_ov017_0218f064_8 unknown_2cc_[22]; };
struct Struct_ov017_0218f064 { char unknown_0_[0x4334]; Object3D* unknown_4334_; Object3D* unknown_4338_; Object3D* unknown_433c_; Object3D* unknown_4340_; };
struct Struct_ov017_0218f064_2 { char unknown_0_[0xb58]; Struct_020545b8* unknown_b58_; char* unknown_b5c_; };
struct Struct_ov017_0218f064_3 { char unknown_0_[0x1840]; Struct_ov017_0218f064_2 unknown_1840_; };
static inline Struct_ov017_0218f064_2* inline_ov017_0218f064(Zone3D* arg0) { SDK_NULL_ASSERT(arg0); return &((Struct_ov017_0218f064_3*)arg0)->unknown_1840_; }
#endif
struct Struct_ov017_0218f064_4 { char unknown_0_[0x10]; Vector3i unknown_10_; short unknown_1c_; };
struct Struct_ov017_0218f064_5 {
    Object3D unknown_0_;
    char unknown_ac_[4];
    unsigned short unknown_b0_, unknown_b2_, unknown_b4_;
#if defined(jpn)
    char unknown_b6_[0x148 - 0xb6];
#else
    char unknown1_b6_[0x9e];
#endif
    Struct_020545b8* unknown_154_;
    char unknown_158_[0x17a];
    unsigned char unknown_2d2_;
};
struct Struct_ov017_0218f064_7 { Object3D unknown_0_[11]; };
#if defined(jpn)
enum { Enum_ov017_0218f064_720 = 0x2c4, Enum_ov017_0218f064_724 = 0x2c8, Enum_ov017_0218f064_760 = 0x2ec };
#else
enum { Enum_ov017_0218f064_720 = 0x2d0, Enum_ov017_0218f064_724 = 0x2d4, Enum_ov017_0218f064_760 = 0x2f8 };
#endif
void* GetField0x3f8Address_0200fd0c(GameState*);
extern "C" Zone3D* Zone3D_GetInstance();
extern "C" void func_0202ae18();
void VramState_Rewind(Foo0207df50*);
void DestroyAllocators020545b8(T020545b8*);
extern "C" void func_020542b4(T020545b8*, SafeAllocator*, InternalBlock0218f064*);
extern "C" int func_ov017_021925e0();
extern "C" void* func_ov017_021a11b4(Struct_ov017_0218f064_6*);
extern "C" void func_02054464(Struct_020545b8*, SafeAllocator*, Struct_ov017_0218f064_8*);
extern "C" void func_02037d10(Struct_ov017_0218f064_5*);
extern "C" void func_02048104(Struct_02048104*);
extern "C" void func_02054664(Struct_02054664*);
extern "C" int func_ov017_02192548();
extern "C" void func_020415d8(Struct_020415d8*);
extern "C" void func_020c9be0();
extern "C" void func_0200fd38(GameState*, int, GameObject*);
extern "C" void func_0203db34(unsigned char*, int, int, int);
extern "C" void func_02033b88(Struct_02010604*, int);
extern "C" void func_02053c4c(char*, char*);
extern "C" void func_02053c74(char*, int);
extern "C" void func_ov017_0218f57c(void*, int);
extern "C" int func_ov017_0218f5a4(GameResources*, int, int, int, int);
#if defined(jpn)
#define data_ov017_021d73a4 data_ov017_021d7804
#endif
extern const char data_ov017_021d73a4[];

static inline Struct_ov017_0218f064_8* inline_ov017_0218f064_2(GameResources* arg0) { SDK_NULL_ASSERT(arg0); return ((Struct_ov017_0218f064_9*)arg0)->unknown_2cc_; }

// USA: func_ov017_0218f064
// JPN: func_ov017_0218fc44
extern "C" ARM void func_ov017_0218f064(GameResources* arg0, int arg1, int arg2, int arg3, int arg4) {
    GameState* var0 = GameState::GetInstance();
#if !defined(jpn)
    Zone3D* var1;
#endif
    Struct_ov017_0218f064_4* var2 = (Struct_ov017_0218f064_4*)func_0200fd0c(var0);
#if defined(jpn)
    ZoneEntryContext0218f064* entries = ((ZoneOwner0218f064*)Zone3D_GetInstance())->GetEntries();
#else
    zone = Zone3D_GetInstance();
#endif
    func_0202ae18();
    int var4 = 1;
    SafeAllocator* var5;
    Struct_020545b8* var6;
    if (arg2 == 0x4000) {
#if defined(jpn)
        var6 = var3->unknown_1b58_;
#else
        var6 = inline_ov017_0218f064(var1)->unknown_b58_;
#endif
        if (!entry) return;
        SafeAllocator* primaryAllocators = resources->allocator_array_1a0;
        SafeAllocator* specialAllocator = &primaryAllocators[3];
        allocator = &entry->allocator;
        InternalBlock0218f064* blocks = InternalBlocks0218f064(resources);
        specialAllocator->Reset();
        InternalBlock0218f064* block = &blocks[21];
        VramState_Rewind((Foo0207df50*)block);
        DestroyAllocators020545b8(entry);
        func_020542b4(entry, specialAllocator, block);
    } else {
        if (func_ov017_021925e0()) {
            for (int var11 = 0; var11 < 4; ++var11) {
                if (((Struct_020545b8*)&arg0->substruct_array_12c8[var11])->unknown_0_ == arg1) return;
            }
        }
        var6 = (Struct_020545b8*)func_ov017_021a11b4((Struct_ov017_0218f064_6*)arg0);
        if (!var6) return;
        var5 = &var6->unknown_5d8_;
        int var12 = var6->unknown_2_ + 1;
        SafeAllocator* var13 = &arg0->allocator_array_38[var12];
        Struct_ov017_0218f064_8* var14 = &((Struct_ov017_0218f064_9*)arg0)->unknown_2cc_[var12];
        func_020545b8(var6);
        if (arg2 == 4) func_02054464(var6, var13, var14);
        else func_020542b4(var6, var13, var14);
    }
    Struct_ov017_0218f064* var15 = (Struct_ov017_0218f064*)arg0;
    if (var15->unknown_4334_) { var15->unknown_4334_->Destroy(); var15->unknown_4334_ = 0; }
    if (var15->unknown_4338_) { var15->unknown_4338_->Destroy(); var15->unknown_4338_ = 0; }
    if (var15->unknown_433c_) { var15->unknown_433c_->Destroy(); var15->unknown_433c_ = 0; }
    if (var15->unknown_4340_) { var15->unknown_4340_->Destroy(); var15->unknown_4340_ = 0; }
    var5->Reset();
    Struct_ov017_0218f064_5* var16 = 0;
    if (arg2 == 0x800) {
        var16 = (Struct_ov017_0218f064_5*)var5->Allocate(Enum_ov017_0218f064_720);
        func_02037d10(var16);
    } else if (arg2 == 0x200) {
        var16 = (Struct_ov017_0218f064_5*)var5->Allocate(Enum_ov017_0218f064_720);
        func_02048104((Struct_02048104*)var16);
    } else if (arg2 == 0x1000) {
        var16 = (Struct_ov017_0218f064_5*)var5->Allocate(Enum_ov017_0218f064_724);
        func_02054664((Struct_02054664*)var16);
        if (var16) var16->unknown_2d2_ = func_ov017_02192548();
    } else if (arg2 == 0x4000) {
        var16 = (Struct_ov017_0218f064_5*)var5->Allocate(Enum_ov017_0218f064_760);
        func_020415d8((Struct_020415d8*)var16);
    } else if (arg2 == 4) {
        var16 = (Struct_ov017_0218f064_5*)var5->Allocate(Enum_ov017_0218f064_724);
        func_02054664((Struct_02054664*)var16);
        if (var16) var16->unknown_2d2_ = func_ov017_02192548();
        var4 = 0;
    }
    if (!combatant) func_020c9be0();
    combatant->object.actorIndex_ = (short)id;
    combatant->entry = entry;
    entry->id = (short)id;
    RegisterCombatantSlot_0200fd38(game, id, (GameObject*)combatant);
    if (initialize) {
        Components0218f064* components = (Components0218f064*)allocator->Allocate(0x764);
        if (!components) func_020c9be0();
        components->objects[0].Initialize();
        components->objects[2].Initialize();
        components->objects[1].Initialize();
        components->objects[3].Initialize();
        components->objects[4].Initialize();
        components->objects[5].Initialize();
        Object3D* sixth = &components->objects[6];
        sixth->Initialize();
        Object3D* seventh = &components->objects[7];
        seventh->Initialize();
        components->objects[8].Initialize();
        Object3D* ninth = &components->objects[9];
        ninth->Initialize();
        Object3D* tenth = &components->objects[10];
        tenth->Initialize();
        int base = id * 12;
        RegisterCombatantSlot_0200fd38(game, base + 0x13, (GameObject*)&components->objects[0]);
        RegisterCombatantSlot_0200fd38(game, base + 0x14, (GameObject*)&components->objects[1]);
        RegisterCombatantSlot_0200fd38(game, base + 0x15, (GameObject*)&components->objects[2]);
        RegisterCombatantSlot_0200fd38(game, base + 0x16, (GameObject*)&components->objects[3]);
        RegisterCombatantSlot_0200fd38(game, base + 0x17, (GameObject*)&components->objects[5]);
        RegisterCombatantSlot_0200fd38(game, base + 0x18, (GameObject*)sixth);
        RegisterCombatantSlot_0200fd38(game, base + 0x19, (GameObject*)seventh);
        RegisterCombatantSlot_0200fd38(game, base + 0x1a, (GameObject*)&components->objects[8]);
        RegisterCombatantSlot_0200fd38(game, base + 0x1b, (GameObject*)&components->objects[4]);
        RegisterCombatantSlot_0200fd38(game, base + 0x1c, (GameObject*)ninth);
        RegisterCombatantSlot_0200fd38(game, base + 0x1d, (GameObject*)tenth);
    }
    combatant->field_b0 = 0x324;
    combatant->field_b4 = 0x189;
    combatant->object.SetHeight(0x1800);
    combatant->object.SetRadius(0x1000);
    combatant->object.SetAnimationByName(data_ov017_021d73a4, 0);
    combatant->object.position_ = ticket->position;
    StoreVec3AtField0x50_0203db34((unsigned char*)combatant, combatant->object.rotation_.x, ticket->rotation, combatant->object.rotation_.z);
    SetByte0xbeShiftPrev((Bytes02033b88*)combatant, 0);
    if (kind == 0x4000) {
#if defined(jpn)
        char* var23 = var3->unknown_1b5c_;
#else
        char* var23 = inline_ov017_0218f064(var1)->unknown_b5c_;
#endif
        if (var23) func_02053c4c((char*)var16, var23);
    } else func_02053c74((char*)var16, arg1);
    if (arg4 > 0) func_ov017_0218f57c(var16, arg4);
    if (arg3) func_ov017_0218f5a4(arg0, arg1, 0, 0, 0);
}

#if defined(jpn)
#undef data_ov017_021d73a4
#endif
