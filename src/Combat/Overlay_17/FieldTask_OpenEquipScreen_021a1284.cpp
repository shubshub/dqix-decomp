#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
#include <World/Zone3D.h>
#include "Resource/Brightness.h"
#include "Resource/MessageSystem.h"

#if defined(jpn)
enum { Enum_ov017_021a1284_1253 = 0x4e1, Enum_ov017_021a1284_1276 = 0x4f8, Enum_ov017_021a1284_1588 = 0x56c, Enum_ov017_021a1284_1608 = 0x578, Enum_ov017_021a1284_716 = 0x27c, Enum_ov017_021a1284_14080 = 0x34f0, Enum_ov017_021a1284_1060 = 0x444, TransferBufferSize = 0x16c00, Enum_ov017_021a1284_336 = 0x144 };
#else
enum { Enum_ov017_021a1284_1253 = 0x4e5, Enum_ov017_021a1284_1276 = 0x4fc, Enum_ov017_021a1284_1588 = 0x634, Enum_ov017_021a1284_1608 = 0x648, Enum_ov017_021a1284_716 = 0x2cc, Enum_ov017_021a1284_14080 = 0x3700, Enum_ov017_021a1284_1060 = 0x424, TransferBufferSize = 0x17600, Enum_ov017_021a1284_336 = 0x150 };
#endif

struct Foo0207df50;
struct Obj020397cc;
struct Struct_0203de2c_3;
struct Struct_02058564_2;
struct ArrayContainsByteStruct;
struct Struct_ov017_021a1284_7;
struct Struct_ov017_021a1284_8 {
    char unknown_0_[4];
    SafeAllocator* unknown_4_;
    void* internal;
    SafeAllocator* unknown_c_;
    SafeAllocator* unknown_10_;
    SafeAllocator* unknown_14_;
    char unknown_18_[Enum_ov017_021a1284_1253 - 0x18];
    signed char mode;
    signed char result;
    char unknown_4e7_[0x15];
    int parameter;
    char unknown_500_[Enum_ov017_021a1284_1588 - Enum_ov017_021a1284_1276 - 4];
    unsigned short flags;
};
struct TransferEvent021a1284 {
    char unknown_0_[1];
    unsigned char unknown_1_;
    char unknown_2_[6];
    SafeAllocator allocator;
    Struct_ov017_021a1284_8* unknown_1c_;
    unsigned char mode;
    unsigned char parameter;
    unsigned char stage;
};
struct Struct_ov017_021a1284_2 { char bytes[0x5b0]; };
struct ResourceTransfer021a1284 {
    char unknown_0_[Enum_ov017_021a1284_716];
    Struct_ov017_021a1284_2 initial;
    char restored[1];
    char unknown_87d_[Enum_ov017_021a1284_14080 - Enum_ov017_021a1284_716 - 0x5b1];
    void** pending;
};
struct ZoneTransfer021a1284 {
    char unknown_0_[Enum_ov017_021a1284_1060];
    int pending;
    char unknown_428_[0x418];
    char range[1];
};
struct Struct_ov017_021a1284_5 {
    char unknown_0_[0xb0];
    unsigned short unknown_b0_;
    unsigned short unknown_b2_;
    unsigned short field_b4;
    char unknown_b6_[Enum_ov017_021a1284_336 - 0xb6];
    void* settings;
};
struct Struct_ov017_021a1284_6 { char unknown_0_[0x56b]; unsigned char unknown_56b_0_ : 4; unsigned char reserved : 4; };

struct Struct_0203dce4_2;
extern "C" Struct_0203dce4_2* func_0203cf4c();
extern "C" Zone3D* Zone3D_GetInstance();
extern "C" Struct_02058564_2* func_02057924();
extern "C" int* LinkSession_GetInstance();
extern "C" void* MessageSystem_GetInstance();
extern "C" void GameObject_DisableControl(Obj020397cc*, int);
void SetBrightness(GameResources*, int, int);
int IsBrightnessTransitionActive(GameResources*);
extern "C" int func_02039850(void*);
extern "C" int GameState_GetProtagonistIndex(GameState*);
extern "C" void func_ov017_021a1178(GameResources*, int);
extern "C" void func_0203983c(unsigned char*, int);
extern "C" void MessageSystem_Reset(char*);
extern "C" void func_0203d008(unsigned char*);
extern "C" void func_0203e0a0(Struct_0203dce4_2*, unsigned short);
extern "C" void func_020a0cc4(unsigned int);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion*, unsigned int);
extern "C" void ROMFilesystem_InitFileTables();
extern "C" void func_ov017_0219bf74();
extern "C" void VramState_Rewind(Foo0207df50*);
extern "C" void func_ov017_0219b938(GameResources*);
extern "C" int func_020981e4(int, int);
extern "C" void func_ov017_021a316c(GameResources*);
extern "C" void func_020a1df8(int);
extern "C" void func_020a1ef0(int);
extern "C" void func_ov023_021e2dd8(Struct_ov017_021a1284_8*);
extern "C" void __clear(void*, unsigned int);
extern "C" int GameState_GetOwnPartyOrder(char*, void*);
extern "C" GameObject* func_0200ff1c(GameState*, int);
extern "C" void func_ov023_021e31b0(Struct_ov017_021a1284_7*, unsigned char*, int);
extern "C" int func_ov017_021959b4();
extern "C" void func_ov023_021e338c(char*);
extern "C" void func_ov023_021e3030(Struct_ov017_021a1284_8*);
extern "C" void func_ov017_021a18c8(TransferEvent021a1284*);
extern "C" void func_ov017_0219b624(GameResources*);
extern "C" void func_0203d018(unsigned char*);
extern "C" void func_0203de2c(Struct_0203de2c_3*);
extern "C" void func_ov017_0218f79c(void*);
extern "C" void func_ov017_021a2840(GameResources*);
extern "C" void func_02058564(Struct_02058564_2*);
extern "C" void func_02042b30(void*, void*);
extern "C" void VramState_Restore(char*);
extern "C" void func_020432c4(void*);
extern "C" void VramState_Save(char*);
extern "C" int func_ov017_0218f5a4(GameResources*, int, int, int, int);
extern "C" int LinkSession_IsActive(int*);
extern "C" int func_02086ef0(ArrayContainsByteStruct*, int);
extern "C" void func_ov017_021c3fb4(int, int);
extern "C" void func_ov017_021c4418(int, int);
extern "C" void func_ov017_0219ba0c(GameResources*, int);
extern "C" int FieldTaskQueue_IsEmpty(void**);
extern "C" void func_020732a8();
extern "C" void func_ov017_0219bd1c(int, int, int, int);
extern "C" unsigned char* GameState_GetFollowCamera(char*);
extern "C" void func_020a28b0(unsigned char*, int);
extern "C" void GameObject_EnableControl(void*);
extern AllocatorUnion g_mainAllocator;

// Overlay 17, originally func_ov017_021a1284 (USA/EUR 0x021a1284, JPN 0x021a1d1c)
extern "C" ARM void FieldTask_OpenEquipScreen(TransferEvent021a1284* self, void* unused) {
    GameState* game = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    Zone3D* zone = Zone3D_GetInstance();
    Struct_0203dce4_2* entries = func_0203cf4c();
    Struct_02058564_2* nodes = func_02057924();
    int* search = LinkSession_GetInstance();
    GameObject* player = game->GetLeader();
    GameResources* resources = game->GetResources();
    void* global = MessageSystem_GetInstance();
    GameObject_DisableControl((Obj020397cc*)player, 1);
    ((Struct_ov017_021a1284_5*)player)->unknown_b2_ = 0;
    if (self->stage == 0) {
        SetBrightness(resources, -16, 15);
        self->stage = 1;
    } else if (self->stage == 1) {
        if (!IsBrightnessTransitionActive(resources)) self->stage = 2;
    } else if (self->stage == 2) {
        if (loader->GetNumQueuedTasks() > 0) return;
        if (func_02039850(player)) {
            player->obj3D_.unknown_2_ = -1;
            ((Struct_ov017_021a1284_5*)player)->unknown_b0_ = 0x324;
            ((Struct_ov017_021a1284_5*)player)->field_b4 = 0x189;
            player->obj3D_.SetHeight(0x1800);
            player->obj3D_.SetRadius(0x1000);
            func_ov017_021a1178(resources, GameState_GetProtagonistIndex(game));
            func_0203983c((unsigned char*)player, 0);
        }
        unsigned char flag = 0;
#if defined(jpn)
        func_0204500c((MessageSystem*)global, (char*)&flag, 0);
#else
        func_0204500c((MessageSystem*)global, (char*)&flag, 0, 0xe3);
#endif
        MessageSystem_Reset((char*)global);
        func_0203d008((unsigned char*)entries);
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
        func_ov017_0219bf74();
        SafeAllocator* current;
        SafeAllocator* primary = &resources->allocator_array_38[0];
        Struct_ov017_021a1284_2* internal = &((ResourceTransfer021a1284*)resources)->initial;
        primary->Reset();
        VramState_Rewind((Foo0207df50*)internal);
        func_ov017_0219b938(resources);
        SafeAllocator* var14 = &resources->allocator_array_38[5];
        var14->Reset();
        current = primary;
        if (((ZoneTransfer021a1284*)zone)->range && func_020981e4((int)((ZoneTransfer021a1284*)zone)->range, zone->currentZoneID_)) {
            func_ov017_021a316c(resources);
            current = &resources->allocator_array_38[7];
            current->Reset();
        }
        func_020a1df8(5);
        func_020a1ef0(1);
        self->unknown_1c_ = (Struct_ov017_021a1284_8*)current->Allocate(Enum_ov017_021a1284_1608);
        self->unknown_1c_->mode = self->mode;
        self->unknown_1c_->parameter = self->parameter;
        func_ov023_021e2dd8(self->unknown_1c_);
        self->unknown_1c_->unknown_4_ = primary;
        self->unknown_1c_->unknown_c_ = var14;
        self->unknown_1c_->unknown_10_ = current;
        self->unknown_1c_->unknown_14_ = &self->allocator;
        self->unknown_1c_->internal = internal;
        self->unknown_1c_->flags |= 0x2000;
        if (self->unknown_1c_->mode == 3) {
            unsigned char roster[4];
            __clear(roster, 4);
            unsigned char selected[4];
            unsigned char var17 = 0;
            for (int i = 0; i < 4; ++i) selected[i] = 0xff;
            int count = GameState_GetOwnPartyOrder((char*)game, roster);
            for (int i = 0; i < count; ++i) {
                GameObject* combatant = func_0200ff1c(game, roster[i]);
                if (!combatant) continue;
                Struct_ov017_021a1284_6* settings = (Struct_ov017_021a1284_6*)((Struct_ov017_021a1284_5*)combatant)->settings;
                int blocked;
                if (settings) blocked = settings->unknown_56b_0_ ? 1 : 0;
                else blocked = 0;
                if (!blocked) selected[var17++] = roster[i];
            }
            func_ov023_021e31b0((Struct_ov017_021a1284_7*)self->unknown_1c_, selected, var17);
        }
        self->stage = 3;
    } else if (self->stage == 3) {
        if (func_ov017_021959b4()) func_ov023_021e338c((char*)self->unknown_1c_);
        func_ov023_021e3030(self->unknown_1c_);
        if (self->unknown_1c_->result < 0) self->stage = 4;
    } else if (self->stage == 4) {
        func_ov017_021a18c8(self);
        func_ov017_021a316c(resources);
        resources->allocator_array_38[7].Reset();
        func_ov017_0219b624(resources);
        func_0203d018((unsigned char*)entries);
        func_0203de2c((Struct_0203de2c_3*)entries);
        func_ov017_0218f79c(resources);
        func_ov017_021a2840(resources);
        func_02058564(nodes);
        func_02042b30(global, ((ResourceTransfer021a1284*)resources)->restored);
        VramState_Rewind((Foo0207df50*)((ResourceTransfer021a1284*)resources)->restored);
        VramState_Restore(((ResourceTransfer021a1284*)resources)->restored);
        func_020432c4(global);
        VramState_Save(((ResourceTransfer021a1284*)resources)->restored);
        ArrayContainsByteStruct* party = (ArrayContainsByteStruct*)GameState_GetParty(game);
        for (int i = 0; i < 4; ++i) {
            if (func_ov017_0218f5a4(resources, i, 0, 0, 0) && LinkSession_IsActive(search) && func_02086ef0(party, i)) {
                func_ov017_021c3fb4(i, 1);
                func_ov017_021c4418(i, -1);
            }
        }
        ClearFlags00(resources, 0x10);
        func_ov017_0219ba0c(resources, 0);
        self->stage = 5;
    } else if (self->stage == 5) {
        if (!FieldTaskQueue_IsEmpty(((ResourceTransfer021a1284*)resources)->pending)) return;
        func_020732a8();
        func_ov017_0219bd1c(1, 0, 0, 0);
        if (zone->currentZoneID_ == 0x2710 || zone->currentZoneID_ == 0x2774) {
            ClearFlags04(resources, 0x601fe);
            SetFlags04(resources, 0x10004);
        } else ClearFlags04(resources, 0x601fe);
        self->stage = 6;
    } else if (self->stage == 6) {
        if (((ZoneTransfer021a1284*)Zone3D_GetInstance())->pending) return;
        func_020a28b0(GameState_GetFollowCamera((char*)game), 3);
        self->stage = 7;
    } else if (self->stage == 7) {
        if (self->mode == 3) GameObject_EnableControl(player);
        self->unknown_1_ = 1;
    }
}
