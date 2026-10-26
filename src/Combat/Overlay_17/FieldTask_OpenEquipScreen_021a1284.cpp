#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
#include <World/Zone3D.h>
#include "Resource/Brightness.h"
#include "Resource/MessageSystem.h"

#if defined(jpn)
enum { Enum_ov017_021a1284_1253 = 0x4e1, Enum_ov017_021a1284_1276 = 0x4f8, Enum_ov017_021a1284_1588 = 0x56c, Enum_ov017_021a1284_1608 = 0x578, Enum_ov017_021a1284_716 = 0x27c, Enum_ov017_021a1284_14080 = 0x34f0, Enum_ov017_021a1284_1060 = 0x444, Enum_ov017_021a1284_95744 = 0x16c00, Enum_ov017_021a1284_336 = 0x144 };
#else
enum { Enum_ov017_021a1284_1253 = 0x4e5, Enum_ov017_021a1284_1276 = 0x4fc, Enum_ov017_021a1284_1588 = 0x634, Enum_ov017_021a1284_1608 = 0x648, Enum_ov017_021a1284_716 = 0x2cc, Enum_ov017_021a1284_14080 = 0x3700, Enum_ov017_021a1284_1060 = 0x424, Enum_ov017_021a1284_95744 = 0x17600, Enum_ov017_021a1284_336 = 0x150 };
#endif

struct Struct_0203d028;
struct Struct_02018300_3;
struct Struct_0203de2c_3;
struct Struct_02058564_2;
struct Struct_02048150;
struct Struct_ov017_021a1284_7;
struct Struct_ov017_021a1284_8 {
    char unknown_0_[4];
    SafeAllocator* unknown_4_;
    void* unknown_8_;
    SafeAllocator* unknown_c_;
    SafeAllocator* unknown_10_;
    SafeAllocator* unknown_14_;
    char unknown_18_[Enum_ov017_021a1284_1253 - 0x18];
    signed char unknown_4e5_;
    signed char unknown_4e6_;
    char unknown_4e7_[0x15];
    int unknown_4fc_;
    char unknown_500_[Enum_ov017_021a1284_1588 - Enum_ov017_021a1284_1276 - 4];
    unsigned short unknown_634_;
};
struct Struct_ov017_021a1284 {
    char unknown_0_[1];
    unsigned char unknown_1_;
    char unknown_2_[6];
    SafeAllocator unknown_8_;
    Struct_ov017_021a1284_8* unknown_1c_;
    unsigned char unknown_20_;
    unsigned char unknown_21_;
    unsigned char unknown_22_;
};
struct Struct_ov017_021a1284_2 { char unknown_0_[0x5b0]; };
struct Struct_ov017_021a1284_3 {
    char unknown_0_[Enum_ov017_021a1284_716];
    Struct_ov017_021a1284_2 unknown_2cc_;
    char unknown_87c_[1];
    char unknown_87d_[Enum_ov017_021a1284_14080 - Enum_ov017_021a1284_716 - 0x5b1];
    void** unknown_3700_;
};
struct Struct_ov017_021a1284_4 {
    char unknown_0_[Enum_ov017_021a1284_1060];
    int unknown_424_;
    char unknown_428_[0x418];
    char unknown_840_[1];
};
struct Struct_ov017_021a1284_5 {
    char unknown_0_[0xb0];
    unsigned short unknown_b0_;
    unsigned short unknown_b2_;
    unsigned short unknown_b4_;
    char unknown_b6_[Enum_ov017_021a1284_336 - 0xb6];
    void* unknown_150_;
};
struct Struct_ov017_021a1284_6 { char unknown_0_[0x56b]; unsigned char unknown_56b_0_ : 4; unsigned char unknown_56b_4_ : 4; };

struct EntryList_203dce4;
EntryList_203dce4* GetGlobalPtr021075f4_0203cf4c();
extern "C" Zone3D* Zone3D_GetInstance();
extern "C" NodeList02058564* func_02057924();
extern "C" int* LinkSession_GetInstance();
void* MessageSystem_GetInstance();
void GameObject_DisableControl(Obj020397cc*, int);
void SetBrightness(GameResources*, int, int);
int IsBrightnessTransitionActive(GameResources*);
int GetByteField0x254_02039850(void*);
int GameState_GetProtagonistIndex(GameState*);
void ComputeAndCall_021a1178(GameResources*, int);
void SetBoolFlag0x254_0203983c(unsigned char*, int);
void MessageSystem_Reset(char*);
void SetField0x98Bit0_0203d008(unsigned char*);
extern "C" void func_0203e0a0(EntryList_203dce4*, unsigned short);
extern "C" void func_020a0cc4(unsigned int);
void* AllocatorUnion_AllocateRounded(AllocatorUnion*, unsigned int);
extern "C" void ROMFilesystem_InitFileTables();
void ResetOverlayAndAllocator_0219bf74();
void VramState_Rewind(Foo0207df50*);
extern "C" void func_ov017_0219b938(GameResources*);
extern "C" int func_020981e4(int, int);
extern "C" void func_ov017_021a316c(GameResources*);
extern "C" void func_020a1df8(int);
extern "C" void func_020a1ef0(int);
extern "C" void func_ov023_021e2dd8(Struct_ov017_021a1284_8*);
extern "C" void __clear(void*, unsigned int);
int GameState_GetOwnPartyOrder(char*, void*);
GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState*, int);
void CopyBytesToInts_021e31b0(Obj021e31b0*, unsigned char*, int);
extern "C" int func_ov017_021959b4();
extern "C" void func_ov023_021e338c(char*);
extern "C" void func_ov023_021e3030(Struct_ov017_021a1284_8*);
extern "C" void func_ov017_021a18c8(Struct_ov017_021a1284*);
extern "C" void func_ov017_0219b624(GameResources*);
void ClearField0x98Bit0_0203d018(unsigned char*);
void ReleaseRosterEntries0203de2c(Roster0203de2c*);
void ProcessCombatantsIfFlagged_0218f79c(void*);
void ProcessSlotField58_021a2840(GameResources*);
void CleanupNodeList02058564(NodeList02058564*);
void SetField0x1e28_02042b30(void*, void*);
void VramState_Restore(char*);
extern "C" void func_020432c4(void*);
void VramState_Save(char*);
extern "C" int func_ov017_0218f5a4(GameResources*, int, int, int, int);
int LinkSession_IsActive(int*);
int ArrayContainsByte_02086ef0(ArrayContainsByteStruct*, int);
extern "C" void func_ov017_021c3fb4(int, int);
extern "C" void func_ov017_021c4418(int, int);
extern "C" void func_ov017_0219ba0c(GameResources*, int);
int FieldTaskQueue_IsEmpty(void**);
void CallFuncForEachOfFour_020732a8();
extern "C" void func_ov017_0219bd1c(int, int, int, int);
unsigned char* GameState_GetFollowCamera(char*);
void ClearFlagBits_020a28b0(unsigned char*, int);
void GameObject_EnableControl(void*);
extern AllocatorUnion g_mainAllocator;

// Overlay 17, originally func_ov017_021a1284 (USA/EUR 0x021a1284, JPN 0x021a1d1c)
extern "C" ARM void FieldTask_OpenEquipScreen(TransferEvent021a1284* self, void* unused) {
    GameState* game = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    Zone3D* zone = Zone3D_GetInstance();
    EntryList_203dce4* entries = GetGlobalPtr021075f4_0203cf4c();
    NodeList02058564* nodes = func_02057924();
    int* search = LinkSession_GetInstance();
    GameObject* player = game->GetLeader();
    GameResources* resources = game->GetResources();
    void* global = MessageSystem_GetInstance();
    GameObject_DisableControl((Obj020397cc*)player, 1);
    ((PlayerTransfer021a1284*)player)->field_b2 = 0;
    if (self->stage == 0) {
        SetBrightness(resources, -16, 15);
        self->stage = 1;
    } else if (self->stage == 1) {
        if (!IsBrightnessTransitionActive(resources)) self->stage = 2;
    } else if (self->stage == 2) {
        if (loader->GetNumQueuedTasks() > 0) return;
        if (GetByteField0x254_02039850(player)) {
            player->obj3D_.unknown_2_ = -1;
            ((PlayerTransfer021a1284*)player)->field_b0 = 0x324;
            ((PlayerTransfer021a1284*)player)->field_b4 = 0x189;
            player->obj3D_.SetHeight(0x1800);
            player->obj3D_.SetRadius(0x1000);
            ComputeAndCall_021a1178(resources, GameState_GetProtagonistIndex(game));
            SetBoolFlag0x254_0203983c((unsigned char*)player, 0);
        }
        unsigned char var9 = 0;
#if defined(jpn)
        func_0204500c((Struct_02021b84*)var8, (char*)&var9, 0);
#else
        func_0204500c((Struct_02021b84*)var8, (char*)&var9, 0, 0xe3);
#endif
        MessageSystem_Reset((char*)global);
        SetField0x98Bit0_0203d008((unsigned char*)entries);
        func_0203e0a0(entries, zone->currentZoneID_);
        SetFlags00(resources, 0x10);
        func_020a0cc4(TransferBufferSize);
        void* buffer = AllocatorUnion_AllocateRounded(&g_mainAllocator, TransferBufferSize);
        if (!buffer) {
            ROMFilesystem_InitFileTables();
            self->stage = 4;
            return;
        }
        self->allocator.CreateTypeA(buffer, TransferBufferSize);
        self->allocator.Reset();
        ResetOverlayAndAllocator_0219bf74();
        SafeAllocator* current;
        SafeAllocator* primary = &resources->allocator_array_38[0];
        InternalResource021a1284* internal = &((ResourceTransfer021a1284*)resources)->initial;
        primary->Reset();
        VramState_Rewind((Foo0207df50*)internal);
        func_ov017_0219b938(resources);
        SafeAllocator* secondary = &resources->allocator_array_38[5];
        secondary->Reset();
        current = primary;
        if (((ZoneTransfer021a1284*)zone)->range && IsIdInRange020981e4((int)((ZoneTransfer021a1284*)zone)->range, zone->currentZoneID_)) {
            func_ov017_021a316c(resources);
            current = &resources->allocator_array_38[7];
            current->Reset();
        }
        PushInputLogA_020a1df8(5);
        PushInputLogB_020a1ef0(1);
        self->plugin = (Plugin021a1284*)current->Allocate(PluginSize);
        self->plugin->mode = self->mode;
        self->plugin->parameter = self->parameter;
        func_ov023_021e2dd8(self->plugin);
        self->plugin->primaryAllocator = primary;
        self->plugin->secondaryAllocator = secondary;
        self->plugin->currentAllocator = current;
        self->plugin->eventAllocator = &self->allocator;
        self->plugin->internal = internal;
        self->plugin->flags |= 0x2000;
        if (self->plugin->mode == 3) {
            unsigned char roster[4];
            __clear(roster, 4);
            unsigned char selected[4];
            unsigned char selectedCount = 0;
            for (int i = 0; i < 4; ++i) selected[i] = 0xff;
            int count = GameState_GetOwnPartyOrder((char*)game, roster);
            for (int i = 0; i < count; ++i) {
                GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(game, roster[i]);
                if (!combatant) continue;
                SettingsTransfer021a1284* settings = (SettingsTransfer021a1284*)((PlayerTransfer021a1284*)combatant)->settings;
                int blocked;
                if (settings) blocked = settings->unavailable ? 1 : 0;
                else blocked = 0;
                if (!blocked) selected[selectedCount++] = roster[i];
            }
            func_ov023_021e31b0((Struct_ov017_021a1284_7*)arg0->unknown_1c_, var16, var17);
        }
        self->stage = 3;
    } else if (self->stage == 3) {
        if (func_ov017_021959b4()) SetFlagt_021e338c_021e338c((char*)self->plugin);
        func_ov023_021e3030(self->plugin);
        if (self->plugin->result < 0) self->stage = 4;
    } else if (self->stage == 4) {
        func_ov017_021a18c8(self);
        func_ov017_021a316c(resources);
        resources->allocator_array_38[7].Reset();
        func_ov017_0219b624(resources);
        ClearField0x98Bit0_0203d018((unsigned char*)entries);
        ReleaseRosterEntries0203de2c((Roster0203de2c*)entries);
        ProcessCombatantsIfFlagged_0218f79c(resources);
        ProcessSlotField58_021a2840(resources);
        CleanupNodeList02058564(nodes);
        SetField0x1e28_02042b30(global, ((ResourceTransfer021a1284*)resources)->restored);
        VramState_Rewind((Foo0207df50*)((ResourceTransfer021a1284*)resources)->restored);
        VramState_Restore(((ResourceTransfer021a1284*)resources)->restored);
        func_020432c4(global);
        VramState_Save(((ResourceTransfer021a1284*)resources)->restored);
        ArrayContainsByteStruct* party = (ArrayContainsByteStruct*)GameState_GetParty(game);
        for (int i = 0; i < 4; ++i) {
            if (func_ov017_0218f5a4(resources, i, 0, 0, 0) && LinkSession_IsActive(search) && ArrayContainsByte_02086ef0(party, i)) {
                func_ov017_021c3fb4(i, 1);
                func_ov017_021c4418(i, -1);
            }
        }
        ClearFlags00(resources, 0x10);
        func_ov017_0219ba0c(resources, 0);
        self->stage = 5;
    } else if (self->stage == 5) {
        if (!FieldTaskQueue_IsEmpty(((ResourceTransfer021a1284*)resources)->pending)) return;
        CallFuncForEachOfFour_020732a8();
        func_ov017_0219bd1c(1, 0, 0, 0);
        if (zone->currentZoneID_ == 0x2710 || zone->currentZoneID_ == 0x2774) {
            ClearFlags04(resources, 0x601fe);
            SetFlags04(resources, 0x10004);
        } else ClearFlags04(resources, 0x601fe);
        self->stage = 6;
    } else if (self->stage == 6) {
        if (((ZoneTransfer021a1284*)Zone3D_GetInstance())->pending) return;
        ClearFlagBits_020a28b0(GameState_GetFollowCamera((char*)game), 3);
        self->stage = 7;
    } else if (self->stage == 7) {
        if (self->mode == 3) GameObject_EnableControl(player);
        self->inactive = 1;
    }
}
