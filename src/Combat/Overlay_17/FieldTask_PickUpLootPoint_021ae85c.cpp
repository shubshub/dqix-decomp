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
    int fields[4]; unsigned int low:10, unknown_11_2_:10, kind:8, unused:4;
};
struct State0207dfc8 { unsigned int words[28]; };
struct ResourceState021ae85c { char pad0[0x230]; State0207dfc8 spriteTables; };
struct Zone021ae85c {
#if defined(jpn)
    char pad0[0x620];
#else
    char pad0[0x600];
#endif
    Foo02048004 sprites[6];
#if defined(jpn)
    char unknown_950_[0x2794 - 0x950];
#else
    char unknown_930_[0x2754 - 0x930];
#endif
    ItemTable container;
};
struct Controller021ae85c {
#if defined(jpn)
    char pad0[0x228];
#else
    char pad0[0x2d8];
#endif
    int unknown_2d8_; char unknown_2dc_[0xa]; unsigned char unknown_2e6_;
};
struct Event021ae85c {
    unsigned char pad0, done; char pad2[6]; unsigned char stage, mode;
    unsigned short timer; short key; char unknown_e_[2]; int task;
    Vector3fix position; int angle, fade; Foo02048004* sprite; SafeAllocator allocator;
};
struct Struct_ov017_021ae85c_3 {
    SafeAllocator allocator; char list[0x18]; ItemTable* container;
    int unknown_30_, field34;
};
extern "C" Zone021ae85c* Zone3D_GetInstance();
extern "C" void* LinkSession_GetInstance();
extern "C" int LinkSession_IsGuest(void*);
extern "C" void func_ov017_021aeea8(Event021ae85c*);
extern "C" void GameObject_ForceMotionState(Bytes02033b88*, int);
extern "C" void GameObject_DisableControl(Obj020397cc*, int);
extern "C" void GameObject_SetMotionState(Obj02033b68*, int);
extern "C" void SePlayer_Play(SePlayer*, int, int);
extern "C" StructDE234_020de234* ItemTable_Find(ItemTable*, int);
extern "C" int GameState_GetProtagonistIndex(GameState*);
extern "C" unsigned short ItemRecord_GetFileNumber(StructDE234_020de234*, int);
extern "C" void GameObject_EnableControl(void*);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion*, unsigned int);
extern "C" void VramState_CopyCurrentTo(State0207dfc8*, State0207dfc8*);
extern "C" void VramState_Restore(char*);
extern "C" void SprSprite_LoadFile(void*, int, int, int);
extern "C" void VramState_Save(char*);
extern "C" Controller021ae85c* MessageSystem_GetInstance();
extern "C" void __clear(void*, int);
extern "C" void* ItemTable_Construct(void*);
extern "C" void func_0207cbe8(char*);
extern "C" int func_0207d538(void*, int, int, char*, int);
extern "C" void* TextQueue_GetInstance();
extern "C" void Camera_WorldToScreen(void*, Vec3copy0202ec84*, int*, int*);
extern "C" void SprSprite_SetPosition(Vec3Target0203a46c*, int, int, int);
extern "C" void func_020473c8(StructAt020473c8*, int);
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
    void* search = LinkSession_GetInstance();
    GameResources* resources = GetGameResources();
    if (LinkSession_IsGuest(search)) {
        if (resources->unknown_42e2_) {
            func_ov017_021aeea8(self); self->done = 1; return;
        }
        if (self->mode != 1) {
            if (self->mode == 0) return;
            if (self->mode == 2) { self->done = 1; return; }
        }
    }
    if (self->stage == 0) {
        GameObject* actor = game->GetLeader();
        if (!actor) { func_ov017_021aeea8(self); self->done = 1; return; }
        GameObject_ForceMotionState((Bytes02033b88*)actor, 0);
        GameObject_DisableControl((Obj020397cc*)actor, 1);
        self->timer = 5; self->stage = 1;
    } else if (self->stage == 1) {
        self->timer--;
        if (self->timer) return;
        GameObject* actor = game->GetLeader();
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
            GameObject_EnableControl(game->GetLeader()); return;
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
                GameObject_EnableControl(game->GetLeader());
                loader->RemoveTask(self->task); return;
            }
        }
        loader->RemoveTask(self->task);
        FontBankLoader* global = FontBankLoader_GetInstance();
        func_02094b3c(global, 10);
        func_02094b30(global, 0x1f9, 0);
        self->stage = 4;
    } else if (self->stage == 4) {
        if (!func_02094b4c(FontBankLoader_GetInstance())) return;
        MessageSystem_GetInstance();
        char text[0x80] = {};
        Zone021ae85c* zone = Zone3D_GetInstance();
        Struct_ov017_021ae85c_3 context;
        context.allocator.ResetAllocatorPointer();
        ItemTable_Construct(context.list);
        func_0207cbe8((char*)&context); func_0207cbe8((char*)&context);
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
        SprSprite_SetPosition((Vec3Target0203a46c*)self->sprite, (x - 12) << 12, (y - 40) << 12, 0);
        func_020473c8((StructAt020473c8*)self->sprite, 1);
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
            SprSprite_SetPosition((Vec3Target0203a46c*)self->sprite, (x - 12) << 12, (y - 40) << 12, 0);
            func_020473c8((StructAt020473c8*)self->sprite, 1);
            self->fade -= tick;
            self->sprite->alpha = self->fade > 31 ? 31 : self->fade;
            if (self->fade < 0) self->fade = 0;
        }
        if (!self->timer) { MessageSystem_GetInstance(); self->stage = 7; }
        else if (self->timer == 5) {
            GameObject* actor = game->GetLeader();
            GameObject_EnableControl(actor); GameObject_SetMotionState((Obj02033b68*)actor, 0);
        }
    } else if (self->stage == 7) {
        Controller021ae85c* controller = MessageSystem_GetInstance();
        controller->unknown_2d8_ = 0; controller->unknown_2e6_ = 1;
        FontBankLoader_CancelLoads(FontBankLoader_GetInstance());
        func_ov017_021aeea8(self); self->done = 1;
    }
}
