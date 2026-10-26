#include <globaldefs.h>
#include "Combat/ActorAction.h"
#include <std_library_functions.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "Resource/Brightness.h"
#include "Resource/GameResources.h"
#include "NitroSDK/Memory.h"
#if defined(jpn)
#define func_ov017_021a7c28 func_ov017_021a85b8
#endif

struct Obj020397cc;
struct Base02010834;
struct Foo0207df50 { unsigned int words[28]; };
struct ResourceState021a6c2c { char pad0[0xc40]; Foo0207df50 unknown_c40_; };
struct Dispatcher021a6c2c { unsigned char fields[0xd0]; };
struct Zone021a6c2c {
    unsigned short id;
#if defined(jpn)
    char pad2[0x64 - 2];
#else
    char pad2[0x44 - 2];
#endif
    int originX, unknown_48_;
#if defined(jpn)
    char unknown_6c_[0x27f4 - 0x6c];
#else
    char unknown_4c_[0x27b4 - 0x4c];
#endif
    short unknown_27b4_;
    char unknown_27b6_[0x12]; int unknown_27c8_, unknown_27cc_;
};
struct Struct_ov017_021a6c2c_5 {
    Object3D object; char unknown_ac_[0xe0 - 0xac]; unsigned char flags;
};
struct Encounter021a6c2c {
    unsigned short id; unsigned char active, pad3, field4, field5, field6, unknown_7_;
    unsigned char field8, field9, fielda; signed char unknown_b_; unsigned char fieldc, unknown_d_[3];
    int x, y, z; short field1c, unknown_1e_; int unknown_20_[4];
    char unknown_30_[0x3c]; short unknown_6c_; short unknown_6e_;
};
struct Struct_ov017_021a6c2c {
    unsigned char kind; char pad1[15]; unsigned char enabled;
    unsigned char bit0:1, unknown_11_1_:1, bit2:1, unknown_11_3_:1, unknown_11_4_:1, unknown_11_5_:1, unknown_11_6_:1, unknown_11_7_:1;
    unsigned short field12; short field14, unknown_16_, field18, unknown_1a_, field1c, pad1e;
    int unknown_20_[3]; Vector3fix position; int unknown_38_[3]; Vector3fix scale;
};
struct Event021a6c2c {
    unsigned char pad0, done; char pad2[6]; int stage, timer;
    unsigned char special; char unknown_11_[0x1f]; SafeAllocator allocator; int task;
};
extern "C" void* func_02057924();
extern "C" void* LinkSession_GetInstance();
extern "C" void* MessageSystem_GetInstance();
extern "C" Zone021a6c2c* Zone3D_GetInstance();
extern "C" void func_020a0cc4(unsigned int);
extern "C" void func_ov017_021d1cb8();
extern "C" void GameObject_DisableControl(Obj020397cc*, int);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion*, unsigned int);
extern "C" void VramState_Rewind(Foo0207df50*);
void CleanInvalidateCacheRange(const void*, unsigned int);
extern "C" void func_02057e6c(void*, int, SafeAllocator*, void*, unsigned int, Foo0207df50*);
extern "C" void SePlayer_UnloadExtraArchiveB(void*);
extern "C" void GameState_GetPartyMemberIds(Base02010834*, int, int*, int*);
extern "C" void func_02057fb4(void*, int, void*);
extern "C" void SePlayer_LoadExtraArchiveB(void*, int, int);
extern "C" void SePlayer_PlayExtra(void*, int, int);
extern "C" int GameObject_IsClimbingLadder(char*);
extern "C" void* GameState_GetZoneTransition(GameState*);
#if defined(jpn)
#define func_ov017_021a7280 func_ov017_021a7c28
#define data_ov017_021d777c data_ov017_021d7bb8
#endif
extern "C" void func_ov017_021a7280(Event021a6c2c*);
extern char data_ov017_021d777c[];
extern AllocatorUnion g_mainAllocator;
extern Dispatcher021a6c2c g_sePlayer;
static inline ResourceState021a6c2c* inline_ov017_021a6c2c(GameResources* resources) {
    return (ResourceState021a6c2c*)resources->vramStates_;
}

// Overlay 17, originally func_ov017_021a6c2c (USA/EUR 0x021a6c2c, JPN 0x021a75d4)
extern "C" ARM void FieldTask_WarpToStarflight(Event021a6c2c* self) {
    GameState* game = GameState::GetInstance();
    GameObject* leader = game->GetLeader();
    GameResources* resources = GetGameResources();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    void* manager = func_02057924();
    LinkSession_GetInstance();
    MessageSystem_GetInstance();
    Zone021a6c2c* zone = Zone3D_GetInstance();
    if (self->stage == 0) {
        if (self->special) {
            Vector3fix position = game->GetLeader()->obj3D_.position_;
            int id = zone->id;
            if (id >= 0x4e20 && id <= 0x752f) {
                zone->unknown_27c8_ = position.x + zone->originX;
                zone->unknown_27cc_ = position.z + zone->unknown_48_;
            } else {
                zone->unknown_27c8_ = zone->originX;
                zone->unknown_27cc_ = zone->unknown_48_;
            }
        }
        func_020a0cc4(0x7000);
        if (zone->id != 0x4e27) {
            if (zone->id == 0x4e42) zone->unknown_27b4_ = 4;
        } else zone->unknown_27b4_ = 2;
        func_ov017_021d1cb8();
        GameObject_DisableControl((Obj020397cc*)leader, 1);
        self->stage++;
    } else if (self->stage == 1) {
        self->task = loader->QueueLoadFile(data_ov017_021d777c, 0);
        self->stage++;
    } else if (self->stage == 2) {
        if (!loader->GetTaskStatus(self->task)) return;
        void* file; unsigned int length;
        loader->GetLoadedFileByID(self->task, &file, &length);
        self->allocator.CreateTypeA(AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x7000), 0x7000);
        self->allocator.Reset();
        Foo0207df50* fields = &inline_ov017_021a6c2c(resources)->unknown_c40_;
        VramState_Rewind(fields);
        void* data = self->allocator.Allocate(length);
        memcpy(data, file, length);
        CleanInvalidateCacheRange(data, length);
        func_02057e6c(manager, 13, &self->allocator, data, length, fields);
        loader->RemoveTask(self->task);
        self->task = -1; self->timer = 0; self->stage++;
    } else if (self->stage == 3) {
        self->timer += game->GetTickCount();
        if (self->timer <= 50) return;
        SePlayer_UnloadExtraArchiveB(&g_sePlayer);
        int ids[4], count;
        GameState_GetPartyMemberIds((Base02010834*)game, leader->obj3D_.actorIndex_, ids, &count);
        Struct_ov017_021a6c2c entries[4];
        for (int i = 0; i < count; i++) {
            GameObject* actor = game->GetGameObjectByIndex(ids[i]);
            if (!actor) continue;
            entries[i].kind = 0; entries[i].enabled = 1; entries[i].field12 = 0;
            entries[i].field14 = -1; entries[i].unknown_16_ = -1; entries[i].field18 = -1; entries[i].unknown_1a_ = -1;
            entries[i].field1c = -0x1000;
            entries[i].unknown_20_[0] = 0; entries[i].unknown_20_[1] = 0; entries[i].unknown_20_[2] = 0;
            entries[i].position.x = 0; entries[i].position.y = 0; entries[i].position.z = 0;
            entries[i].unknown_38_[0] = 0; entries[i].unknown_38_[1] = 0; entries[i].unknown_38_[2] = 0;
            entries[i].scale.x = 0x1000; entries[i].scale.y = 0x1000; entries[i].scale.z = 0x1000;
            Struct_ov017_021a6c2c* entry = &entries[i];
            Vector3fix* position = &actor->obj3D_.position_;
            entry->bit0 = 0; entry->unknown_11_1_ = 0; entry->bit2 = 1; entry->unknown_11_3_ = 0;
            entry->unknown_11_4_ = 0; entry->unknown_11_5_ = 0; entry->unknown_11_6_ = 0; entry->unknown_11_7_ = 0;
            entry->position = *position;
            entry->scale = actor->obj3D_.GetScale();
            func_02057fb4(manager, 13, entry);
        }
        SePlayer_LoadExtraArchiveB(&g_sePlayer, 0xa2, 0xa2);
        SePlayer_PlayExtra(&g_sePlayer, 2, 0);
        self->timer = 0; self->stage++;
    } else if (self->stage == 4) {
        self->timer += game->GetTickCount();
        if (self->timer < 38) return;
        int ids[4], count;
        GameState_GetPartyMemberIds((Base02010834*)game, leader->obj3D_.actorIndex_, ids, &count);
        for (int i = 0; i < count; i++) {
            GameObject* actor = game->GetGameObjectByIndex(ids[i]);
            if (actor) actor->obj3D_.MakeHidden();
        }
        self->stage++;
    } else if (self->stage == 5) {
        self->timer += game->GetTickCount();
        if (self->timer < 80) return;
        SetBrightness(resources, -16, 30);
        self->stage++;
    } else if (self->stage == 6) {
        if (IsBrightnessTransitionActive(resources)) return;
        if (GameObject_IsClimbingLadder((char*)leader)) {
            SubBlock02038508* block = GameObject_GetLadderClimb(leader);
            LadderClimb_Reset(block);
            ((Struct_ov017_021a6c2c_5*)leader)->flags &= ~1;
            leader->obj3D_.DisableFlag(0x1180);
            LinkMessageQueue_SendLadderClimb(block, 0, 1);
        }
        Encounter021a6c2c* encounter = (Encounter021a6c2c*)GameState_GetZoneTransition(game);
        VectorizedMemset(encounter, 0, 0x70);
        encounter->field4 = 1; encounter->field8 = 1; encounter->field9 = 1;
        encounter->unknown_b_ = -1;
        encounter->unknown_20_[0] = -1; encounter->unknown_20_[1] = -1;
        encounter->unknown_20_[2] = -1; encounter->unknown_20_[3] = -1;
        encounter->unknown_1e_ = -1; encounter->fieldc = 0; encounter->unknown_6c_ = -1;
        encounter->active = 1; encounter->unknown_7_ = 1; encounter->field5 = 1;
        if (self->special) encounter->id = 0x2774;
        else {
            encounter->id = 0x1901; encounter->x = 0x14cc;
            encounter->y = 0x199; encounter->z = -0x1000;
        }
        int ids[4], count;
        GameState_GetPartyMemberIds((Base02010834*)game, leader->obj3D_.actorIndex_, ids, &count);
        for (int i = 0; i < count; i++) {
            GameObject* actor = game->GetGameObjectByIndex(ids[i]);
            if (actor) actor->obj3D_.MakeVisible();
        }
        func_ov017_021a7280(self); self->done = 1;
    }
}
