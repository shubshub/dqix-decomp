#include <globaldefs.h>
#include "Resource/ItemTable.h"
#include "Resource/FontBankLoader.h"
#include "Resource/TextQueue.h"
#include <std_library_functions.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "World/ZoneLootableRecord.h"
#include "Resource/GameResources.h"

struct Bytes02033b88;
struct Obj020397cc;
struct Obj02033b68;
struct SePlayer;
struct Vec3copy0202ec84;
struct Vec3Target0203a46c;
struct StructAt020473c8;
struct StructDE234_020de234 {
    int fields[4]; unsigned int low:10, mid:10, kind:8, unused:4;
};
struct Struct_02015ef4_5 { unsigned int unknown_0_[28]; };
struct Struct_ov017_021ae85c_4 { char unknown_0_[0x230]; Struct_02015ef4_5 unknown_230_; };
struct Struct_ov017_021ae85c_5 {
#if defined(jpn)
    char unknown_0_[0x620];
#else
    char unknown1_0_[0x600];
#endif
    Struct_02012fa4 unknown_600_[6];
#if defined(jpn)
    char unknown_950_[0x2794 - 0x950];
#else
    char unknown_930_[0x2754 - 0x930];
#endif
    ItemTable container;
};
struct Struct_ov017_021ae85c {
#if defined(jpn)
    char unknown_0_[0x228];
#else
    char unknown1_0_[0x2d8];
#endif
    int unknown_2d8_; char unknown_2dc_[0xa]; unsigned char unknown_2e6_;
};
struct Struct_ov017_021ae85c_2 {
    unsigned char unknown_0_, unknown_1_; char unknown_2_[6]; unsigned char unknown_8_, unknown_9_;
    unsigned short unknown_a_; short unknown_c_; char unknown_e_[2]; int unknown_10_;
    Vector3fix unknown_14_; int unknown_20_, unknown_24_; Struct_02012fa4* unknown_28_; SafeAllocator unknown_2c_;
};
struct TextContext021ae85c {
    SafeAllocator allocator; char list[0x18]; ItemTable* container;
    int field30, field34;
};
extern "C" Zone021ae85c* Zone3D_GetInstance();
extern "C" void* func_0202ae18();
extern "C" int func_0202c540(void*);
extern "C" void func_ov017_021aeea8(Event021ae85c*);
void SetByte0xbeShiftPrev(Bytes02033b88*, int);
void GameObject_DisableControl(Obj020397cc*, int);
void GameObject_SetMotionState(Obj02033b68*, int);
void SePlayer_Play(SePlayer*, int, int);
StructDE234_020de234* ItemTable_Find(ItemTable*, int);
int GameState_GetProtagonistIndex(GameState*);
unsigned short ItemRecord_GetFileNumber(StructDE234_020de234*, int);
void GameObject_EnableControl(void*);
void* AllocatorUnion_AllocateRounded(AllocatorUnion*, unsigned int);
void VramState_CopyCurrentTo(State0207dfc8*, State0207dfc8*);
void VramState_Restore(char*);
void SprSprite_LoadFile(void*, int, int, int);
void VramState_Save(char*);
Controller021ae85c* MessageSystem_GetInstance();
extern "C" void __clear(void*, int);
void* ItemTable_Construct(void*);
void InitStruct0207cbe8(char*);
extern "C" int func_0207d538(void*, int, int, char*, int);
void* TextQueue_GetInstance();
void Camera_WorldToScreen(void*, Vec3copy0202ec84*, int*, int*);
void SetVec3At0x1c(Vec3Target0203a46c*, int, int, int);
void RenderFlaggedIndexedEntry(StructAt020473c8*, int);
extern SePlayer g_sePlayer;
#if defined(jpn)
#define data_ov017_021d79a8 data_ov017_021d80dc
#endif
extern const char data_ov017_021d79a8[];
extern AllocatorUnion g_mainAllocator;
static inline ResourceState021ae85c* ResourceStateBuffer021ae85c(GameResources* resources) {
    return (ResourceState021ae85c*)resources->vramStates_;
}

// Overlay 17, originally func_ov017_021ae85c (USA/EUR 0x021ae85c, JPN 0x021aef70)
extern "C" ARM void FieldTask_PickUpLootPoint(Event021ae85c* self) {
    GameState* game = GameState::GetInstance();
    Zone3D_GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    void* search = func_0202ae18();
    GameResources* resources = GetGameResources();
    if (func_0202c540(search)) {
        if (resources->unknown_flag_42e2) {
            func_ov017_021aeea8(self); self->done = 1; return;
        }
        if (arg0->unknown_9_ != 1) {
            if (arg0->unknown_9_ == 0) return;
            if (arg0->unknown_9_ == 2) { arg0->unknown_1_ = 1; return; }
        }
    }
    if (self->stage == 0) {
        GameObject* actor = game->GetUnknownGameObject();
        if (!actor) { func_ov017_021aeea8(self); self->done = 1; return; }
        SetByte0xbeShiftPrev((Bytes02033b88*)actor, 0);
        GameObject_DisableControl((Obj020397cc*)actor, 1);
        self->timer = 5; self->stage = 1;
    } else if (self->stage == 1) {
        self->timer--;
        if (self->timer) return;
        GameObject* actor = game->GetUnknownGameObject();
        if (actor) GameObject_SetMotionState((Obj02033b68*)actor, 8);
        SePlayer_Play(&g_sePlayer, 0x5b, 0);
        self->stage = 2; self->timer = 30;
    } else if (self->stage == 2) {
        self->timer--;
        if (self->timer) return;
        Zone021ae85c* zone = Zone3D_GetInstance();
        StructDE234_020de234* entry = ItemTable_Find(&zone->container, self->key);
        if (entry) {
            self->sprite = &zone->sprites[GameState_GetProtagonistIndex(game)];
            SprSprite_Unload(self->sprite);
            char filename[0x80];
            sprintf(filename, data_ov017_021d79a8, (signed char)entry->kind, ItemRecord_GetFileNumber(entry, 0));
            self->task = loader->QueueLoadFile(filename, 0);
        } else {
            func_ov017_021aeea8(self); self->done = 1;
            GameObject_EnableControl(game->GetUnknownGameObject()); return;
        }
        self->stage = 3;
    } else if (self->stage == 3) {
        if (!loader->GetTaskStatus(self->task)) return;
        void* file = 0; unsigned int length = 0;
        loader->GetLoadedFileByID(self->task, &file, &length);
        if (file) {
            void* buffer = AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x100);
            if (buffer) {
                self->allocator.ResetAllocatorPointer();
                self->allocator.CreateTypeA(buffer, 0x100); self->allocator.Reset();
                SprSprite_Unload(self->sprite); SprSprite_Init(self->sprite);
                State0207dfc8 saved;
                VramState_CopyCurrentTo(&ResourceStateBuffer021ae85c(resources)->spriteTables, &saved);
                VramState_Restore((char*)&saved);
                SprSprite_LoadFile(self->sprite, (int)file, length, (int)&self->allocator);
                VramState_Save((char*)&saved);
            } else {
                func_ov017_021aeea8(self); self->done = 1;
                GameObject_EnableControl(game->GetUnknownGameObject());
                loader->RemoveTask(self->task); return;
            }
        }
        loader->RemoveTask(self->task);
        FontBankLoader* global = FontBankLoader_GetInstance();
        BlankFunction02094b3c(global, 10);
        BlankFunction02094b30(global, 0x1f9, 0);
        self->stage = 4;
    } else if (self->stage == 4) {
        if (!AlwaysTrue02094b4c(FontBankLoader_GetInstance())) return;
        MessageSystem_GetInstance();
        char text[0x80] = {};
        Zone021ae85c* zone = Zone3D_GetInstance();
        TextContext021ae85c context;
        context.allocator.ResetAllocatorPointer();
        ItemTable_Construct(context.list);
        InitStruct0207cbe8((char*)&context); InitStruct0207cbe8((char*)&context);
        context.container = &zone->container;
        if (func_0207d538(&context, 2, (unsigned short)self->key, text, 1))
#if defined(jpn)
            TextQueue_Push(TextQueue_GetInstance(), text, 0, 0, 1);
#else
            TextQueue_Push(TextQueue_GetInstance(), text, 0, 0, 1, 1);
#endif
        SePlayer_Play(&g_sePlayer, 14, 0);
        self->stage = 5; self->timer = 20; self->fade = 61;
    } else if (self->stage == 5) {
        self->timer--;
        int tick = game->GetTickCount();
        void* camera = game->GetCamera();
        Vector3fix position = self->position;
        if (self->angle < 0x191e) self->angle += tick * 0x199;
        position.y += fix32sin(self->angle);
        int x, y;
        if (camera) {
            Camera_WorldToScreen(camera, (Vec3copy0202ec84*)&position, &x, &y);
        }
        SetVec3At0x1c((Vec3Target0203a46c*)self->sprite, (x - 12) << 12, (y - 40) << 12, 0);
        RenderFlaggedIndexedEntry((StructAt020473c8*)self->sprite, 1);
        if (!self->timer) { self->stage = 6; self->timer = 7; }
    } else if (self->stage == 6) {
        self->timer--;
        int tick = game->GetTickCount();
        void* camera = game->GetCamera();
        Vector3fix position = self->position;
        position.y += fix32sin(self->angle);
        if (self->fade) {
            int x, y;
            if (camera) {
                Camera_WorldToScreen(camera, (Vec3copy0202ec84*)&position, &x, &y);
            }
            SetVec3At0x1c((Vec3Target0203a46c*)self->sprite, (x - 12) << 12, (y - 40) << 12, 0);
            RenderFlaggedIndexedEntry((StructAt020473c8*)self->sprite, 1);
            self->fade -= tick;
            self->sprite->alpha = self->fade > 31 ? 31 : self->fade;
            if (self->fade < 0) self->fade = 0;
        }
        if (!self->timer) { MessageSystem_GetInstance(); self->stage = 7; }
        else if (self->timer == 5) {
            GameObject* actor = game->GetUnknownGameObject();
            GameObject_EnableControl(actor); GameObject_SetMotionState((Obj02033b68*)actor, 0);
        }
    } else if (self->stage == 7) {
        Controller021ae85c* controller = MessageSystem_GetInstance();
        controller->field2d8 = 0; controller->field2e6 = 1;
        FontBankLoader_CancelLoads(FontBankLoader_GetInstance());
        func_ov017_021aeea8(self); self->done = 1;
    }
}
