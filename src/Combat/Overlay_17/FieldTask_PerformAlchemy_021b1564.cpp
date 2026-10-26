#include <globaldefs.h>
#include <GameState/GameState.h>
#include <World/Zone3D.h>
#include <NitroSDK/Cache.h>
#include <std_library_functions.h>
#include "Resource/Brightness.h"

struct Actor0209c678;
struct Actor0209c3b4;
struct Obj020397cc;
struct Struct_020979c0;
struct Struct_02074b64;
struct Struct_02074bd0;
struct Struct_02074bf4;
struct Foo0207df50;
struct TailList020469b4;
struct TailNode020469b4;
struct Transition021b1564 {
    unsigned char kind, unknown_1_;
    char unknown_2_[6];
    SafeAllocator allocator;
    Struct_020979c0* unknown_1c_;
    char unknown_20_[0x10];
    unsigned char unknown_30_, unknown_31_;
    char unknown_32_[2];
    unsigned int unknown_34_, unknown_38_;
    unsigned int unknown_3c_, unknown_40_, unknown_44_;
    unsigned char stage, alternate, result;
};
struct Controller021b1564 {
#if defined(jpn)
    char unknown_0_[0x28];
#else
    char unknown1_0_[0x5c];
#endif
    signed char* action;
#if defined(jpn)
    char unknown_2c_[0x868 - 0x2c];
#else
    char unknown_60_[0x998 - 0x60];
#endif
    int busy;
};
struct Struct_ov017_021b1564 { char unknown_0_[0x394]; unsigned short flags; char unknown_396_[0x9e]; unsigned char result; };
struct Struct_ov017_021b1564_2 { char unknown_0_[0x1000]; char work[1]; };
struct Buffer021b1564 { char unknown_0_[0x820]; Struct_ov017_021b1564_2 tail; };
struct Struct_ov017_021b1564_4 { char unknown_0_[0xae]; short angle; };
struct ResourceBlock021b1564 { char initial[0x5b0]; char restored[1]; };
struct EntryNode021b1564 { char unknown_0_[0x114]; void* entry; char unknown_118_[0xc]; int id; char unknown_128_[0x11]; unsigned char active; };
extern "C" unsigned int* GlobalFlags_GetInstance();
extern "C" Controller021b1564* MessageSystem_GetInstance();
extern "C" unsigned char* GameState_GetFollowCamera(char*);
extern "C" void func_020a27b8(unsigned char*);
extern "C" void GameObject_DisableControl(Obj020397cc*, int);
#if defined(jpn)
extern "C" void func_0204500c(void*, signed char*, int);
enum { Enum_ov017_021b1564_248832 = 0x3b000, TransitionAllocationSize = 0x3c820 };
#else
extern "C" void func_0204500c(void*, signed char*, int, int);
enum { Enum_ov017_021b1564_248832 = 0x3cc00, TransitionAllocationSize = 0x3e420 };
#endif
extern "C" void MessageSystem_Reset(char*);
extern "C" int func_020457e0(void*);
extern "C" void func_020a27ac(void*);
void SetBrightness(GameResources*, int, int);
extern "C" void BgmPlayer_FadeOut(Actor0209c678*, int);
extern "C" void FlagWord_SetBits(unsigned int*, unsigned int);
int IsBrightnessTransitionActive(GameResources*);
extern "C" void func_020dc2bc();
extern "C" void func_020a0cc4(unsigned int);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion*, unsigned int);
extern "C" void ROMFilesystem_InitFileTables();
extern "C" void MessageSystem_Stop(void*);
extern "C" void func_020a1df8(int);
extern "C" void func_020a1ef0(int);
extern "C" void func_ov017_021b1ca8(int);
extern "C" void func_020979c0(Struct_020979c0*, unsigned char);
extern "C" void func_ov006_02157a60(Struct_ov017_021b1564*);
extern "C" void func_ov006_021576a0(Struct_ov017_021b1564*, SafeAllocator*, void*);
extern "C" int func_02097a04(Struct_020979c0*);
extern "C" void func_02074af4(void*);
extern "C" void func_02074b64(Struct_02074b64*);
extern "C" void* func_0203cf4c();
extern "C" Zone3D* Zone3D_GetInstance();
extern "C" void func_0203e0a0(void*, unsigned short);
extern "C" void func_ov017_0219bf74();
extern "C" int func_020981e4(int, int);
extern "C" void func_ov017_021a316c(GameResources*);
extern "C" void func_0203d008(unsigned char*);
extern "C" int func_ov006_02157d7c(Struct_ov017_021b1564*, unsigned int);
extern "C" void func_ov006_02157cc0(Struct_ov017_021b1564*);
extern "C" void func_02097b34(Struct_020979c0*);
extern "C" void func_ov017_021b14ec(Transition021b1564*);
extern "C" void func_0209c3b4(Actor0209c3b4*, int);
extern "C" void func_02074bd0(Struct_02074bd0*);
extern "C" void func_02074bf4(Struct_02074bf4*);
extern "C" void LoadToMainBG1CharacterData(void*, int, unsigned int);
extern "C" void LoadToMainBG2CharacterData(void*, int, unsigned int);
extern "C" void LoadToMainBG1ScreenData(void*, int, unsigned int);
extern "C" void LoadToMainBG2ScreenData(void*, int, unsigned int);
extern "C" void AllocatorUnion_Free(AllocatorUnion*, void*);
extern "C" void func_ov017_0218f79c(void*);
void SetAndLockMainBrightness(GameResources*, int, int);
extern "C" void func_ov017_021921fc(Vector3i*, short, int);
extern "C" void func_ov017_0219bd1c(int, int, int, int);
extern "C" void func_ov017_021a2fa0(GameResources*);
extern "C" void func_ov017_0219b624(GameResources*);
extern "C" void func_ov017_0219ba0c(GameResources*, int);
extern "C" void VramState_Rewind(Foo0207df50*);
extern "C" void VramState_Restore(char*);
extern "C" void func_020432c4(void*);
extern "C" void VramState_Save(char*);
void UnlockAndSetMainBrightness(GameResources*, int, int);
extern "C" int* func_0203df78(void*, int);
extern "C" void* func_02040528(int*);
extern "C" void func_ov017_021b8d1c(EntryNode021b1564*);
extern "C" void func_020469b4(TailList020469b4*, TailNode020469b4*);
extern "C" void GameObject_EnableControl(void*);
extern char g_bgmPlayer[];
extern AllocatorUnion g_mainAllocator;
extern Struct_ov017_021b1564* data_ov017_021d83ec;
#define REG_MAIN_DISPLAY (*(volatile unsigned int*)0x04000000)
#define REG_SUB_DISPLAY (*(volatile unsigned int*)0x04001000)

static inline int inline_ov017_021b1564(Zone3D* zone) { SDK_NULL_ASSERT(zone); return zone->currentZoneID_; }

// Overlay 17, originally func_ov017_021b1564 (USA/EUR 0x021b1564, JPN 0x021b1bf0)
extern "C" ARM void FieldTask_PerformAlchemy(Transition021b1564* self, TailList020469b4* list) {
    GameState* game = GameState::GetInstance();
    GameResources* resources = game->GetResources();
    unsigned int* global = GlobalFlags_GetInstance();
    Controller021b1564* controller = MessageSystem_GetInstance();
    unsigned char* field = GameState_GetFollowCamera((char*)game);
    GameObject* player = game->GetLeader();
    if (field) func_020a27b8(field);
    if (self->stage == 0) {
        self->unknown_3c_ = GetFlags00(resources);
        self->unknown_40_ = GetFlags04(resources);
        self->unknown_44_ = GetFlags08(resources);
        SetFlags04(resources, 0x40);
        if (!self->alternate) {
            GameObject* current = game->GetLeader();
            if (current) GameObject_DisableControl((Obj020397cc*)current, 1);
            if (*controller->action) {
#if defined(jpn)
                func_0204500c(controller, controller->action, 0);
#else
                func_0204500c(controller, controller->action, 0, 0xe3);
#endif
                controller->busy = 1;
            } else MessageSystem_Reset((char*)controller);
            self->stage = 100;
            return;
        }
        ++self->stage;
        return;
    } else if (self->stage == 100) {
        if (controller->busy) return;
        if (func_020457e0(controller) == 1) {
            MessageSystem_Reset((char*)controller);
            self->unknown_1_ = 1;
            if (field) func_020a27ac(field);
            return;
        }
        MessageSystem_Reset((char*)controller);
        SetBrightness(resources, -16, 16);
        BgmPlayer_FadeOut((Actor0209c678*)g_bgmPlayer, 15);
        FlagWord_SetBits(global, 1);
        self->stage = 1;
        return;
    } else if (self->stage == 1) {
        if (IsBrightnessTransitionActive(resources)) return;
        func_020dc2bc();
        ++self->stage;
        return;
    } else if (self->stage == 2) {
        func_020a0cc4(TransitionAllocationSize);
        Buffer021b1564* buffer = (Buffer021b1564*)AllocatorUnion_AllocateRounded(&g_mainAllocator, TransitionAllocationSize);
        if (!buffer) {
            ROMFilesystem_InitFileTables();
            self->unknown_1_ = 1;
            if (field) func_020a27ac(field);
            return;
        }
        Struct_ov017_021b1564_2* tail = &buffer->tail;
        Controller021b1564* current = MessageSystem_GetInstance();
        MessageSystem_Reset((char*)current);
        MessageSystem_Stop(current);
        self->allocator.CreateTypeA(buffer, Enum_ov017_021b1564_248832);
        self->allocator.Reset();
        self->unknown_1c_ = (Struct_020979c0*)self->allocator.Allocate(0x20);
        data_ov017_021d83ec = (Struct_ov017_021b1564*)self->allocator.Allocate(0x438);
        if (!self->unknown_1c_ || !data_ov017_021d83ec) {
            ROMFilesystem_InitFileTables();
            self->unknown_1_ = 1;
            if (field) func_020a27ac(field);
            return;
        }
        func_020a1df8(6);
        func_020a1ef0(1);
        func_ov017_021b1ca8(1);
        func_020979c0(self->unknown_1c_, 2);
        func_ov006_02157a60(data_ov017_021d83ec);
        if (self->alternate) data_ov017_021d83ec->flags |= 2;
        func_ov006_021576a0(data_ov017_021d83ec, &self->allocator, tail->work);
        ++self->stage;
        return;
    } else if (self->stage == 3) {
        if (!func_02097a04(self->unknown_1c_)) return;
        ++self->stage;
        self->unknown_30_ = 0;
        self->unknown_31_ = 0;
        func_02074af4(self->unknown_20_);
        self->unknown_34_ = (REG_MAIN_DISPLAY & 0x1f00) >> 8;
        func_02074b64((Struct_02074b64*)self->unknown_20_);
        self->unknown_38_ = (REG_SUB_DISPLAY & 0x1f00) >> 8;
        SetFlags04(resources, 0x8de);
        void* entries = func_0203cf4c();
        Zone3D* zone = Zone3D_GetInstance();
        func_0203e0a0(entries, zone->currentZoneID_);
        func_ov017_0219bf74();
        if (func_020981e4((int)zone->unk_840, inline_ov017_021b1564(zone))) {
            func_ov017_021a316c(resources);
            resources->allocator_array_38[7].Reset();
        }
        func_0203d008((unsigned char*)entries);
        SetFlags00(resources, 16);
        return;
    } else if (self->stage == 4) {
        func_0203d008((unsigned char*)func_0203cf4c());
        unsigned int ticks = GameState::GetInstance()->GetTickCount();
        if (!func_ov006_02157d7c(data_ov017_021d83ec, ticks)) return;
        self->result = data_ov017_021d83ec->result;
        ++self->stage;
        return;
    } else if (self->stage == 5) {
        if (self->alternate) {
            func_ov006_02157cc0(data_ov017_021d83ec);
            func_02097b34(self->unknown_1c_);
            func_ov017_021b14ec(self);
            ROMFilesystem_InitFileTables();
            self->unknown_1_ = 1;
            if (field) func_020a27ac(field);
            return;
        }
        func_0209c3b4((Actor0209c3b4*)g_bgmPlayer, 7);
        func_ov006_02157cc0(data_ov017_021d83ec);
        data_ov017_021d83ec = 0;
        func_ov017_021b1ca8(0);
        func_02097b34(self->unknown_1c_);
        func_02074bd0((Struct_02074bd0*)self->unknown_20_);
        REG_MAIN_DISPLAY = (REG_MAIN_DISPLAY & ~0x1f00) | (self->unknown_34_ << 8);
        func_02074bf4((Struct_02074bf4*)self->unknown_20_);
        REG_SUB_DISPLAY = (REG_SUB_DISPLAY & ~0x1f00) | (self->unknown_38_ << 8);
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
        ClearFlags00(resources, ~0u);
        ClearFlags04(resources, ~0u);
        ClearFlags08(resources, ~0u);
        SetFlags00(resources, self->unknown_3c_);
        SetFlags04(resources, self->unknown_40_);
        SetFlags08(resources, self->unknown_44_);
        func_ov017_0218f79c(resources);
        SetAndLockMainBrightness(resources, -16, 1);
        func_ov017_021921fc(&player->obj3D_.position_, ((Struct_ov017_021b1564_4*)player)->angle, 1);
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
    } else if (self->stage == 6) {
        func_ov017_021b14ec(self);
        if (self->alternate) SetBrightness(resources, 0, 8);
        ++self->stage;
        return;
    } else if (self->stage == 7) {
        int var16 = 0;
        if (self->alternate) {
            if (!IsBrightnessTransitionActive(resources)) var16 = 1;
        } else {
            UnlockAndSetMainBrightness(resources, 0, 15);
            var16 = 1;
            if (!self->result) {
                int* entry = func_0203df78(func_0203cf4c(), 100);
                void* info;
                if (entry) info = func_02040528(entry);
                EntryNode021b1564* node = (EntryNode021b1564*)resources->unknown_ptr_array_3700[4];
                func_ov017_021b8d1c(node);
                node->entry = info;
                node->id = 0xc4;
                node->active = 1;
                func_020469b4(list, (TailNode020469b4*)node);
            }
        }
        if (!var16) return;
        GameObject* current = game->GetLeader();
        if (current) GameObject_EnableControl(current);
        ROMFilesystem_InitFileTables();
        self->unknown_1_ = 1;
    }
}
