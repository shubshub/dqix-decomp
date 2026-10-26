#include <globaldefs.h>
#include <GameState/GameState.h>
#include <World/Zone3D.h>
#include <NitroSDK/Cache.h>
#include <std_library_functions.h>
#include "Resource/Brightness.h"

struct Struct_02109bf4_4;
struct Struct_0209c3b4_2;
struct Struct_02018300_3;
struct Struct_020979c0;
struct Struct_02074b64;
struct Struct_02074bd0;
struct Struct_02074bf4;
struct Struct_0203d028;
struct Struct_0201bdac_2;
struct Struct_0201bdac;
struct Struct_ov017_021b1564_7 {
    unsigned char unknown_0_, unknown_1_;
    char unknown_2_[6];
    SafeAllocator unknown_8_;
    Struct_020979c0* unknown_1c_;
    char unknown_20_[0x10];
    unsigned char unknown_30_, unknown_31_;
    char unknown_32_[2];
    unsigned int unknown_34_, unknown_38_;
    unsigned int unknown_3c_, unknown_40_, unknown_44_;
    unsigned char unknown_48_, unknown_49_, unknown_4a_;
};
struct Struct_ov017_021b1564_8 {
#if defined(jpn)
    char unknown_0_[0x28];
#else
    char unknown1_0_[0x5c];
#endif
    signed char* unknown_5c_;
#if defined(jpn)
    char unknown_2c_[0x868 - 0x2c];
#else
    char unknown_60_[0x998 - 0x60];
#endif
    int unknown_998_;
};
struct Overlay006021b1564 { char pad_0[0x394]; unsigned short flags; char pad_396[0x9e]; unsigned char result; };
struct BufferTail021b1564 { char pad_0[0x1000]; char work[1]; };
struct Buffer021b1564 { char pad_0[0x820]; BufferTail021b1564 tail; };
struct PlayerView021b1564 { char pad_0[0xae]; short angle; };
struct ResourceBlock021b1564 { char initial[0x5b0]; char restored[1]; };
struct EntryNode021b1564 { char pad_0[0x114]; void* entry; char pad_118[0xc]; int id; char pad_128[0x11]; unsigned char active; };
unsigned int* GlobalFlags_GetInstance();
Controller021b1564* MessageSystem_GetInstance();
unsigned char* GameState_GetFollowCamera(char*);
void ClearIntAt0x23c_020a27b8(unsigned char*);
void GameObject_DisableControl(Obj020397cc*, int);
#if defined(jpn)
extern "C" void func_0204500c(void*, signed char*, int);
enum { Enum_ov017_021b1564_248832 = 0x3b000, Enum_ov017_021b1564_255008 = 0x3c820 };
#else
extern "C" void func_0204500c(void*, signed char*, int, int);
enum { Enum_ov017_021b1564_248832 = 0x3cc00, Enum_ov017_021b1564_255008 = 0x3e420 };
#endif
void MessageSystem_Reset(char*);
extern "C" int func_020457e0(void*);
extern "C" void func_020a27ac(void*);
void SetBrightness(GameResources*, int, int);
void BgmPlayer_FadeOut(Actor0209c678*, int);
void FlagWord_SetBits(unsigned int*, unsigned int);
int IsBrightnessTransitionActive(GameResources*);
extern "C" void func_020dc2bc();
extern "C" void func_020a0cc4(unsigned int);
void* AllocatorUnion_AllocateRounded(AllocatorUnion*, unsigned int);
extern "C" void ROMFilesystem_InitFileTables();
extern "C" void MessageSystem_Stop(void*);
void PushInputLogA_020a1df8(int);
void PushInputLogB_020a1ef0(int);
void SetPowCnt1Bit15_021b1ca8(int);
void InitStruct020979c0(Obj020979c0*, unsigned char);
extern "C" void func_ov006_02157a60(Overlay006021b1564*);
extern "C" void func_ov006_021576a0(Overlay006021b1564*, SafeAllocator*, void*);
extern "C" int func_02097a04(Obj020979c0*);
extern "C" void func_02074af4(void*);
void BackupSubBgControlRegisters(SubBgControlBackup02074b64*);
void* GetGlobalPtr021075f4_0203cf4c();
extern "C" Zone3D* Zone3D_GetInstance();
extern "C" void func_0203e0a0(void*, unsigned short);
extern "C" void func_ov017_0219bf74();
extern "C" int func_020981e4(int, int);
extern "C" void func_ov017_021a316c(GameResources*);
extern "C" void func_0203d008(unsigned char*);
extern "C" int func_ov006_02157d7c(Struct_ov017_021b1564*, unsigned int);
extern "C" void func_ov006_02157cc0(Struct_ov017_021b1564*);
extern "C" void func_02097b34(Struct_020979c0*);
extern "C" void func_ov017_021b14ec(Struct_ov017_021b1564_7*);
extern "C" void func_0209c3b4(Struct_0209c3b4_2*, int);
extern "C" void func_02074bd0(Struct_02074bd0*);
extern "C" void func_02074bf4(Struct_02074bf4*);
extern "C" void LoadToMainBG1CharacterData(void*, int, unsigned int);
extern "C" void LoadToMainBG2CharacterData(void*, int, unsigned int);
extern "C" void LoadToMainBG1ScreenData(void*, int, unsigned int);
extern "C" void LoadToMainBG2ScreenData(void*, int, unsigned int);
void AllocatorUnion_Free(AllocatorUnion*, void*);
void ProcessCombatantsIfFlagged_0218f79c(void*);
void SetAndLockMainBrightness(GameResources*, int, int);
extern "C" void func_ov017_021921fc(Vector3i*, short, int);
extern "C" void func_ov017_0219bd1c(int, int, int, int);
extern "C" void func_ov017_021a2fa0(GameResources*);
extern "C" void func_ov017_0219b624(GameResources*);
extern "C" void func_ov017_0219ba0c(GameResources*, int);
void VramState_Rewind(Foo0207df50*);
void VramState_Restore(char*);
extern "C" void func_020432c4(void*);
void VramState_Save(char*);
void UnlockAndSetMainBrightness(GameResources*, int, int);
int* FindEntryPointerByKey0203df78(void*, int);
void* GetField0x8_02040528(int*);
extern "C" void func_ov017_021b8d1c(EntryNode021b1564*);
void AppendNodeToTail(TailList020469b4*, TailNode020469b4*);
void GameObject_EnableControl(void*);
extern char g_bgmPlayer[];
extern AllocatorUnion g_mainAllocator;
extern Overlay006021b1564* data_ov017_021d83ec;
#define REG_MAIN_DISPLAY (*(volatile unsigned int*)0x04000000)
#define REG_SUB_DISPLAY (*(volatile unsigned int*)0x04001000)

static inline int inline_ov017_021b1564(Zone3D* arg0) { SDK_NULL_ASSERT(arg0); return arg0->currentZoneID_; }

// Overlay 17, originally func_ov017_021b1564 (USA/EUR 0x021b1564, JPN 0x021b1bf0)
extern "C" ARM void FieldTask_PerformAlchemy(Transition021b1564* self, TailList020469b4* list) {
    GameState* game = GameState::GetInstance();
    GameResources* resources = game->GetResources();
    unsigned int* global = GlobalFlags_GetInstance();
    Controller021b1564* controller = MessageSystem_GetInstance();
    unsigned char* field = GameState_GetFollowCamera((char*)game);
    GameObject* player = game->GetLeader();
    if (field) ClearIntAt0x23c_020a27b8(field);
    if (self->stage == 0) {
        self->savedFlags = GetFlags00(resources);
        self->savedFlags4 = GetFlags04(resources);
        self->savedFlags8 = GetFlags08(resources);
        SetFlags04(resources, 0x40);
        if (!self->alternate) {
            GameObject* current = game->GetLeader();
            if (current) GameObject_DisableControl((Obj020397cc*)current, 1);
            if (*controller->action) {
#if defined(jpn)
                func_0204500c(var3, var3->unknown_5c_, 0);
#else
                func_0204500c(var3, var3->unknown_5c_, 0, 0xe3);
#endif
                controller->busy = 1;
            } else MessageSystem_Reset((char*)controller);
            self->stage = 100;
            return;
        }
        ++arg0->unknown_48_;
        return;
    } else if (self->stage == 100) {
        if (controller->busy) return;
        if (func_020457e0(controller) == 1) {
            MessageSystem_Reset((char*)controller);
            self->inactive = 1;
            if (field) SetField0x23cTrue_020a27ac(field);
            return;
        }
        MessageSystem_Reset((char*)controller);
        SetBrightness(resources, -16, 16);
        BgmPlayer_FadeOut((Actor0209c678*)g_bgmPlayer, 15);
        FlagWord_SetBits(global, 1);
        self->stage = 1;
        return;
    } else if (arg0->unknown_48_ == 1) {
        if (IsBrightnessTransitionActive(var1)) return;
        func_020dc2bc();
        ++arg0->unknown_48_;
        return;
    } else if (self->stage == 2) {
        func_020a0cc4(TransitionAllocationSize);
        Buffer021b1564* buffer = (Buffer021b1564*)AllocatorUnion_AllocateRounded(&g_mainAllocator, TransitionAllocationSize);
        if (!buffer) {
            ROMFilesystem_InitFileTables();
            self->inactive = 1;
            if (field) SetField0x23cTrue_020a27ac(field);
            return;
        }
        BufferTail021b1564* tail = &buffer->tail;
        Controller021b1564* current = MessageSystem_GetInstance();
        MessageSystem_Reset((char*)current);
        MessageSystem_Stop(current);
        self->allocator.CreateTypeA(buffer, TransitionArenaSize);
        self->allocator.Reset();
        self->plugin = (Obj020979c0*)self->allocator.Allocate(0x20);
        data_ov017_021d83ec = (Overlay006021b1564*)self->allocator.Allocate(0x438);
        if (!self->plugin || !data_ov017_021d83ec) {
            ROMFilesystem_InitFileTables();
            self->inactive = 1;
            if (field) SetField0x23cTrue_020a27ac(field);
            return;
        }
        func_020a1df8(6);
        func_020a1ef0(1);
        func_ov017_021b1ca8(1);
        func_020979c0(arg0->unknown_1c_, 2);
        func_ov006_02157a60(data_ov017_021d83ec);
        if (arg0->unknown_49_) data_ov017_021d83ec->unknown_394_ |= 2;
        func_ov006_021576a0(data_ov017_021d83ec, &arg0->unknown_8_, var8->unknown_1000_);
        ++arg0->unknown_48_;
        return;
    } else if (self->stage == 3) {
        if (!func_02097a04(self->plugin)) return;
        ++self->stage;
        self->mainFlag = 0;
        self->subFlag = 0;
        func_02074af4(self->displayBackup);
        self->mainDisplay = (REG_MAIN_DISPLAY & 0x1f00) >> 8;
        BackupSubBgControlRegisters((SubBgControlBackup02074b64*)self->displayBackup);
        self->subDisplay = (REG_SUB_DISPLAY & 0x1f00) >> 8;
        SetFlags04(resources, 0x8de);
        void* entries = GetGlobalPtr021075f4_0203cf4c();
        Zone3D* zone = Zone3D_GetInstance();
        func_0203e0a0(entries, zone->currentZoneID_);
        ResetOverlayAndAllocator_0219bf74();
        if (IsIdInRange020981e4((int)zone->unk_840, CurrentZone021b1564(zone))) {
            func_ov017_021a316c(resources);
            resources->allocator_array_38[7].Reset();
        }
        func_0203d008((unsigned char*)var10);
        SetFlags00(var1, 16);
        return;
    } else if (arg0->unknown_48_ == 4) {
        func_0203d008((unsigned char*)func_0203cf4c());
        unsigned int var12 = GameState::GetInstance()->GetTickCount();
        if (!func_ov006_02157d7c(data_ov017_021d83ec, var12)) return;
        arg0->unknown_4a_ = data_ov017_021d83ec->unknown_434_;
        ++arg0->unknown_48_;
        return;
    } else if (arg0->unknown_48_ == 5) {
        if (arg0->unknown_49_) {
            func_ov006_02157cc0(data_ov017_021d83ec);
            func_02097b34(self->plugin);
            func_ov017_021b14ec(self);
            ROMFilesystem_InitFileTables();
            self->inactive = 1;
            if (field) SetField0x23cTrue_020a27ac(field);
            return;
        }
        SetStateAndDispatch0209c3b4((Actor0209c3b4*)g_bgmPlayer, 7);
        func_ov006_02157cc0(data_ov017_021d83ec);
        data_ov017_021d83ec = 0;
        SetPowCnt1Bit15_021b1ca8(0);
        func_02097b34(self->plugin);
        ClearFlag0x10IfSet((Struct02074bd0*)self->displayBackup);
        REG_MAIN_DISPLAY = (REG_MAIN_DISPLAY & ~0x1f00) | (self->mainDisplay << 8);
        ClearFlag0x11IfSet((Struct02074bf4*)self->displayBackup);
        REG_SUB_DISPLAY = (REG_SUB_DISPLAY & ~0x1f00) | (self->subDisplay << 8);
        void* empty = AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x800);
        if (empty) {
            memset(empty, 0, 0x800);
            CleanInvalidateCacheRange(empty, 0x20);
            LoadToMainBG1CharacterData(empty, 0, 0x20);
            LoadToMainBG2CharacterData(empty, 0, 0x20);
            CleanInvalidateCacheRange(empty, 0x800);
            LoadToMainBG1ScreenData(empty, 0, 0x800);
            LoadToMainBG2ScreenData(empty, 0, 0x800);
            AllocatorUnion_Free(&g_mainAllocator, empty);
        }
        ClearFlags00(var1, ~0u);
        ClearFlags04(var1, ~0u);
        ClearFlags08(var1, ~0u);
        SetFlags00(var1, arg0->unknown_3c_);
        SetFlags04(var1, arg0->unknown_40_);
        SetFlags08(var1, arg0->unknown_44_);
        func_ov017_0218f79c(var1);
        SetAndLockMainBrightness(var1, -16, 1);
        func_ov017_021921fc(&var5->obj3D_.position_, ((Struct_ov017_021b1564_4*)var5)->unknown_ae_, 1);
        func_ov017_0219bd1c(1, 0, 0, 0);
        func_ov017_021a2fa0(resources);
        func_ov017_0219b624(resources);
        func_ov017_0219ba0c(resources, 0);
        ResourceBlock021b1564* block = (ResourceBlock021b1564*)resources->vramStates_;
        Controller021b1564* current = MessageSystem_GetInstance();
        VramState_Rewind((Foo0207df50*)block->restored);
        VramState_Restore(block->restored);
        func_020432c4(current);
        VramState_Save(block->restored);
        ++self->stage;
        return;
    } else if (arg0->unknown_48_ == 6) {
        func_ov017_021b14ec(arg0);
        if (arg0->unknown_49_) SetBrightness(var1, 0, 8);
        ++arg0->unknown_48_;
        return;
    } else if (arg0->unknown_48_ == 7) {
        int var16 = 0;
        if (arg0->unknown_49_) {
            if (!IsBrightnessTransitionActive(var1)) var16 = 1;
        } else {
            UnlockAndSetMainBrightness(resources, 0, 15);
            finished = 1;
            if (!self->result) {
                int* entry = FindEntryPointerByKey0203df78(GetGlobalPtr021075f4_0203cf4c(), 100);
                void* info;
                if (entry) info = GetField0x8_02040528(entry);
                EntryNode021b1564* node = (EntryNode021b1564*)resources->unknown_ptr_array_3700[4];
                func_ov017_021b8d1c(node);
                node->entry = info;
                node->id = 0xc4;
                node->active = 1;
                AppendNodeToTail(list, (TailNode020469b4*)node);
            }
        }
        if (!finished) return;
        GameObject* current = game->GetLeader();
        if (current) GameObject_EnableControl(current);
        ROMFilesystem_InitFileTables();
        self->inactive = 1;
    }
}
