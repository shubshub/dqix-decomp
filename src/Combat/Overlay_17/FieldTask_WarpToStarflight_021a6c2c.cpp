#include <globaldefs.h>
#include "Combat/ActorAction.h"
#include <std_library_functions.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "Resource/Brightness.h"
#include "Resource/GameResources.h"
#include "NitroSDK/Memory.h"

struct Struct_02018300_3;
struct Struct_02010834;
struct Struct_0203d028 { unsigned int unknown_0_[28]; };
struct Struct_ov017_021a6c2c_3 { char unknown_0_[0xc40]; Struct_0203d028 unknown_c40_; };
struct Struct_02108760_5 { unsigned char unknown_0_[0xd0]; };
struct Struct_ov017_021a6c2c_4 {
    unsigned short unknown_0_;
#if defined(jpn)
    char unknown_2_[0x64 - 2];
#else
    char unknown1_2_[0x44 - 2];
#endif
    int unknown_44_, unknown_48_;
#if defined(jpn)
    char unknown_6c_[0x27f4 - 0x6c];
#else
    char unknown_4c_[0x27b4 - 0x4c];
#endif
    short unknown_27b4_;
    char unknown_27b6_[0x12]; int unknown_27c8_, unknown_27cc_;
};
struct Struct_ov017_021a6c2c_5 {
    Object3D unknown_0_; char unknown_ac_[0xe0 - 0xac]; unsigned char unknown_e0_;
};
struct Struct_ov017_021a6c2c_6 {
    unsigned short unknown_0_; unsigned char unknown_2_, unknown_3_, unknown_4_, unknown_5_, unknown_6_, unknown_7_;
    unsigned char unknown_8_, unknown_9_, unknown_a_; signed char unknown_b_; unsigned char unknown_c_, unknown_d_[3];
    int unknown_10_, unknown_14_, unknown_18_; short unknown_1c_, unknown_1e_; int unknown_20_[4];
    char unknown_30_[0x3c]; short unknown_6c_; short unknown_6e_;
};
struct Struct_ov017_021a6c2c {
    unsigned char unknown_0_; char unknown_1_[15]; unsigned char unknown_10_;
    unsigned char unknown_11_0_:1, unknown_11_1_:1, unknown_11_2_:1, unknown_11_3_:1, unknown_11_4_:1, unknown_11_5_:1, unknown_11_6_:1, unknown_11_7_:1;
    unsigned short unknown_12_; short unknown_14_, unknown_16_, unknown_18_, unknown_1a_, unknown_1c_, unknown_1e_;
    int unknown_20_[3]; Vector3fix unknown_2c_; int unknown_38_[3]; Vector3fix unknown_44_;
};
struct Struct_ov017_021a6c2c_2 {
    unsigned char unknown_0_, unknown_1_; char unknown_2_[6]; int unknown_8_, unknown_c_;
    unsigned char unknown_10_; char unknown_11_[0x1f]; SafeAllocator unknown_30_; int unknown_44_;
};
extern "C" void* func_02057924();
extern "C" void* func_0202ae18();
void* MessageSystem_GetInstance();
extern "C" Zone021a6c2c* Zone3D_GetInstance();
extern "C" void func_020a0cc4(unsigned int);
void CheckAndEnqueueTag_021d1cb8_021d1cb8();
void GameObject_DisableControl(Obj020397cc*, int);
void* AllocatorUnion_AllocateRounded(AllocatorUnion*, unsigned int);
void VramState_Rewind(Foo0207df50*);
void CleanInvalidateCacheRange(const void*, unsigned int);
extern "C" void func_02057e6c(void*, int, SafeAllocator*, void*, unsigned int, Foo0207df50*);
void SePlayer_UnloadExtraArchiveB(void*);
void CopyCountedBytesToIntArray02010834(Base02010834*, int, int*, int*);
void FindNodeAndProcess02057fb4(void*, int, void*);
void SePlayer_LoadExtraArchiveB(void*, int, int);
void SePlayer_PlayExtra(void*, int, int);
int GetByte0x26c_02039d7c(char*);
void* GetField0x3f8Address_0200fd0c(GameState*);
#if defined(jpn)
#define func_ov017_021a7280 func_ov017_021a7c28
#define data_ov017_021d777c data_ov017_021d7bb8
#endif
extern "C" void func_ov017_021a7280(Struct_ov017_021a6c2c_2*);
extern char data_ov017_021d777c[];
extern AllocatorUnion g_mainAllocator;
extern Dispatcher021a6c2c g_sePlayer;
static inline ResourceState021a6c2c* ResourceStateBuffer021a6c2c(GameResources* resources) {
    return (ResourceState021a6c2c*)resources->vramStates_;
}

// Overlay 17, originally func_ov017_021a6c2c (USA/EUR 0x021a6c2c, JPN 0x021a75d4)
extern "C" ARM void FieldTask_WarpToStarflight(Event021a6c2c* self) {
    GameState* game = GameState::GetInstance();
    GameObject* leader = game->GetUnknownGameObject();
    GameResources* resources = GetGameResources();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    void* manager = func_02057924();
    func_0202ae18();
    MessageSystem_GetInstance();
    Zone021a6c2c* zone = Zone3D_GetInstance();
    if (self->stage == 0) {
        if (self->special) {
            Vector3fix position = game->GetUnknownGameObject()->obj3D_.position_;
            int id = zone->id;
            if (id >= 0x4e20 && id <= 0x752f) {
                zone->encounterX = position.x + zone->originX;
                zone->encounterZ = position.z + zone->originZ;
            } else {
                var5->unknown_27c8_ = var5->unknown_44_;
                var5->unknown_27cc_ = var5->unknown_48_;
            }
        }
        func_020a0cc4(0x7000);
        if (zone->id != 0x4e27) {
            if (zone->id == 0x4e42) zone->field27b4 = 4;
        } else zone->field27b4 = 2;
        CheckAndEnqueueTag_021d1cb8_021d1cb8();
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
        Foo0207df50* fields = &ResourceStateBuffer021a6c2c(resources)->effectFields;
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
        CopyCountedBytesToIntArray02010834((Base02010834*)game, leader->obj3D_.actorIndex_, ids, &count);
        Entry021a6c2c entries[4];
        for (int i = 0; i < count; i++) {
            GameObject* actor = game->GetGameObjectByIndex(ids[i]);
            if (!actor) continue;
            entries[i].kind = 0; entries[i].enabled = 1; entries[i].field12 = 0;
            entries[i].field14 = -1; entries[i].field16 = -1; entries[i].field18 = -1; entries[i].field1a = -1;
            entries[i].field1c = -0x1000;
            entries[i].fields20[0] = 0; entries[i].fields20[1] = 0; entries[i].fields20[2] = 0;
            entries[i].position.x = 0; entries[i].position.y = 0; entries[i].position.z = 0;
            entries[i].fields38[0] = 0; entries[i].fields38[1] = 0; entries[i].fields38[2] = 0;
            entries[i].scale.x = 0x1000; entries[i].scale.y = 0x1000; entries[i].scale.z = 0x1000;
            Entry021a6c2c* entry = &entries[i];
            Vector3fix* position = &actor->obj3D_.position_;
            entry->bit0 = 0; entry->bit1 = 0; entry->bit2 = 1; entry->bit3 = 0;
            entry->bit4 = 0; entry->bit5 = 0; entry->bit6 = 0; entry->bit7 = 0;
            entry->position = *position;
            entry->scale = actor->obj3D_.GetScale();
            FindNodeAndProcess02057fb4(manager, 13, entry);
        }
        SePlayer_LoadExtraArchiveB(&g_sePlayer, 0xa2, 0xa2);
        SePlayer_PlayExtra(&g_sePlayer, 2, 0);
        self->timer = 0; self->stage++;
    } else if (self->stage == 4) {
        self->timer += game->GetTickCount();
        if (self->timer < 38) return;
        int ids[4], count;
        CopyCountedBytesToIntArray02010834((Base02010834*)game, leader->obj3D_.actorIndex_, ids, &count);
        for (int i = 0; i < count; i++) {
            GameObject* actor = game->GetGameObjectByIndex(ids[i]);
            if (actor) actor->obj3D_.MakeHidden();
        }
        arg0->unknown_8_++;
    } else if (arg0->unknown_8_ == 5) {
        arg0->unknown_c_ += var0->GetTickCount();
        if (arg0->unknown_c_ < 80) return;
        SetBrightness(var2, -16, 30);
        arg0->unknown_8_++;
    } else if (arg0->unknown_8_ == 6) {
        if (IsBrightnessTransitionActive(var2)) return;
        if (func_02039d7c((char*)var1)) {
            Struct_02037d10* var23 = func_020399a8(var1);
            func_02038508(var23);
            ((Struct_ov017_021a6c2c_5*)var1)->unknown_e0_ &= ~1;
            var1->obj3D_.DisableFlag(0x1180);
            func_ov017_021d3f00(var23, 0, 1);
        }
        Struct_ov017_021a6c2c_6* var24 = (Struct_ov017_021a6c2c_6*)func_0200fd0c(var0);
        VectorizedMemset(var24, 0, 0x70);
        var24->unknown_4_ = 1; var24->unknown_8_ = 1; var24->unknown_9_ = 1;
        var24->unknown_b_ = -1;
        var24->unknown_20_[0] = -1; var24->unknown_20_[1] = -1;
        var24->unknown_20_[2] = -1; var24->unknown_20_[3] = -1;
        var24->unknown_1e_ = -1; var24->unknown_c_ = 0; var24->unknown_6c_ = -1;
        var24->unknown_2_ = 1; var24->unknown_7_ = 1; var24->unknown_5_ = 1;
        if (arg0->unknown_10_) var24->unknown_0_ = 0x2774;
        else {
            var24->unknown_0_ = 0x1901; var24->unknown_10_ = 0x14cc;
            var24->unknown_14_ = 0x199; var24->unknown_18_ = -0x1000;
        }
        int ids[4], count;
        CopyCountedBytesToIntArray02010834((Base02010834*)game, leader->obj3D_.actorIndex_, ids, &count);
        for (int i = 0; i < count; i++) {
            GameObject* actor = game->GetGameObjectByIndex(ids[i]);
            if (actor) actor->obj3D_.MakeVisible();
        }
        func_ov017_021a7280(arg0); arg0->unknown_1_ = 1;
    }
}
