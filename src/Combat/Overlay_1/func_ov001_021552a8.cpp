#include <globaldefs.h>
#include "World/Zone3D.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "Resource/GameResources.h"
#include "World/Object3D.h"
#include "std_library_functions.h"
#if defined(jpn)
#include "Filesystem/FileIO.h"
#endif



struct Struct0205a198;
struct ClearTarget0205a234;
struct Struct_0208b8c4;
struct Struct_0203d028_6;
struct PacRecord;
struct Foo0207df50;
struct SetFlagStruct;

struct Struct_ov001_021552a8_3 {
    char pad0[0x3c];
    void* slots;
    Struct0205a198* entries;
    char unknown_44_[8];
    unsigned short count;
    char unknown_4e_[2];
    unsigned char active;
};

struct Struct_ov001_021552a8_4 {
    int field0;
    char pad4[3];
    unsigned char unknown_7_;
    char pad8[0x38];
    unsigned short unknown_40_;
    unsigned short unknown_42_;
    unsigned short flags;
    char unknown_46_[0x22];
};

struct Struct_ov001_021552a8 {
    unsigned char field0;
    unsigned char done;
    char pad2[8];
    unsigned short state;
    Struct_ov001_021552a8_4 params;
    int unknown_74_;
#if !defined(jpn)
    int unknown_78_;
#endif
    SafeAllocator allocator;
    char unknown_90_[4];
    int field94;
    char unknown_98_[4];
    unsigned char unknown_9c_;
    char unknown_9d_[0x107 - 0x9d];
    unsigned char unknown_107_;
    char unknown_108_[8];
    int unknown_110_;
    char unknown_114_[0xc];
    void* timer;
    SafeAllocator unknown_124_;
    char unknown_138_[0x30];
    Struct_ov001_021552a8_3* list;
    void* slots;
    Struct0205a198* entries;
};

struct Events021552a8 {
    char pad0[0x45b];
    unsigned char bits[0x20];
};

extern "C" char* GameState_GetFollowCamera(char* obj);
extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
extern "C" void func_0209c2e0(void* obj, int a, int b);
extern "C" void func_ov017_021bb27c(void* obj);
extern "C" void func_0208b9a0(void* obj, unsigned char flag);
extern "C" char* MessageSystem_GetInstance(void);
extern "C" void func_0208b8c4(Struct_0208b8c4* obj, SafeAllocator* alloc);
extern "C" void* func_0203cf4c(void);
extern "C" void* func_0203d004(void* p);
extern "C" void func_020401fc(Struct_0203d028_6* pool, unsigned int count, SafeAllocator* alloc);
extern "C" void Sprite_Init(Struct0205a198* p);
extern "C" void func_0205a234(ClearTarget0205a234* p);
extern "C" void SpriteContext_Init(char* p);
extern "C" int Pac_CountFiles(PacRecord* entry);
extern "C" void* Pac_GetFile(PacRecord* rec, int index, void** out, int* out44);
extern "C" int SpriteContext_LoadFile(void* obj, void* data, int arg2, void* arg3);
extern "C" void func_ov001_0215a850(SafeAllocator* alloc);
extern "C" void func_ov001_0215a8dc(void);
extern "C" void func_ov001_021538d4(int p0, void* unused1, SafeAllocator* alloc);
extern "C" void func_ov001_0215aa14(SafeAllocator* alloc);
extern "C" void func_ov001_0215aaa8(int idx, int val);
extern "C" void func_ov001_0215acf8(int a, int b);
extern "C" void VramState_Rewind(Foo0207df50* p);
extern "C" int func_ov001_02153948(unsigned short arg);
extern "C" Events021552a8* Scenario_GetInstance(void);
extern "C" void* Zone3D_GetInstance(void);
extern "C" void Scenario_SetFlag(void* unused, unsigned char* array, int bit, int value);
extern "C" void* LinkSession_GetInstance(void);
extern "C" void* GameState_GetParty(GameState* gs);
extern "C" void* GlobalFlags_GetInstance(void);
extern "C" void Zone3D_SaveAndOverrideElementVisibility(void* area, int arg);
extern "C" Object3D* func_ov017_021bdbc0(unsigned char* base);
extern "C" void FollowCamera_DisableFollow(void* obj);
extern "C" void func_020a27b8(unsigned char* obj);
extern "C" void MapDisplay_SetHoldSubScreenDark(SetFlagStruct* p, int value);

extern AllocatorUnion g_mainAllocator;
extern char g_bgmPlayer;
#if defined(jpn)
extern const char data_ov001_021661d7[];
extern const char data_ov001_021661dc[];
#endif

static inline void inline_ov001_021552a8(Struct_ov001_021552a8_3* list, Struct0205a198* entries, unsigned short count) {
    list->entries = entries;
    list->count = count;
}

// USA: func_ov001_021552a8
extern "C" ARM int func_ov001_021552a8(Struct_ov001_021552a8* self) {
    char* sub;
    GameState* gs = GameState::GetInstance();
    GameResources* res = GetGameResources();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    char* hud = GameState_GetFollowCamera((char*)gs);
    GameObject* leader = gs->GetLeader();
    sub = res->vramStates_;

    if (loader->GetTaskStatus(self->unknown_74_) == 0) {
        return self->state;
    }
#if !defined(jpn)
    if (loader->GetTaskStatus(self->unknown_78_) == 0) {
        return self->state;
    }
#endif
    if (self->params.flags & 0x200) {
        if (loader->GetTaskStatus(self->unknown_110_) == 0) {
            return self->state;
        }
    }
#if defined(jpn)
    if (loader->GetDetailedTaskStatus(self->unknown_74_) != 2) {
#else
    if (loader->GetDetailedTaskStatus(self->unknown_74_) != 2 || loader->GetDetailedTaskStatus(self->unknown_78_) != 2) {
#endif
        SignedAllocatorHeader* header = self->allocator.GetSignedAllocator();
        self->allocator.Destroy();
        AllocatorUnion_Free(&g_mainAllocator, header);
        loader->RemoveTask(self->unknown_74_);
#if !defined(jpn)
        loader->RemoveTask(self->unknown_78_);
#endif
        loader->RemoveTask(self->unknown_110_);
        func_0209c2e0(&g_bgmPlayer, self->field94, 0);
        func_ov017_021bb27c(self);
        self->done = 1;
        return self->state;
    }

    void* var7;
#if !defined(jpn)
    void* var8;
#endif
    unsigned int var9;
#if !defined(jpn)
    unsigned int var10;
#endif
    loader->GetLoadedFileByID(self->unknown_74_, &var7, &var9);
#if !defined(jpn)
    loader->GetLoadedFileByID(self->unknown_78_, &var8, &var10);
#endif

    if (self->params.flags & 2) {
        self->timer = self->allocator.Allocate(0xe4);
        func_0208b9a0(self->timer, 0);
        char* msg = MessageSystem_GetInstance();
        self->unknown_124_.CreateTypeA(self->allocator.Allocate(0xa000), 0xa000);
        self->unknown_124_.Reset();
        func_0208b8c4((Struct_0208b8c4*)self->timer, &self->unknown_124_);
#if defined(jpn)
        *(void**)(msg + 0x4c) = self->timer;
#else
        *(void**)(msg + 0x8c) = self->timer;
#endif
    }
    if ((self->params.flags & 1) || (self->params.flags & 4)) {
        func_020401fc((Struct_0203d028_6*)func_0203d004(func_0203cf4c()), 0xc, &self->allocator);
    }
    if (self->params.flags & 0x200) {
        self->allocator.GetMaxPossibleAllocation();
        self->entries = (Struct0205a198*)self->allocator.Allocate(0x230);
        self->list = (Struct_ov001_021552a8_3*)self->allocator.Allocate(0x54);
        self->slots = self->allocator.Allocate(8);
        for (int i = 0; i < 0xe; i++) {
            Sprite_Init((Struct0205a198*)((char*)self->entries + i * 0x28));
        }
        func_0205a234((ClearTarget0205a234*)self->slots);
        SpriteContext_Init((char*)self->list);
        self->list->active = 0;
        inline_ov001_021552a8(self->list, self->entries, 0xe);
        self->list->slots = self->slots;

        void* out;
        void* dataC;
        unsigned int var15;
        int size;
        loader->GetLoadedFileByID(self->unknown_110_, &dataC, &var15);
        int count = Pac_CountFiles((PacRecord*)dataC);
        for (int j = 0; j < count; j++) {
            void* rec = Pac_GetFile((PacRecord*)dataC, j, &out, &size);
            SpriteContext_LoadFile(self->list, rec, size, &self->allocator);
        }
        loader->RemoveTask(self->unknown_110_);
        self->unknown_110_ = -1;
    }

#if defined(jpn)
    const void* var8;
    unsigned int var10;
    if (FindFilesInNarcBySubstring(var7, data_ov001_021661d7, &var8, &var10, 1) == 0) {
        func_ov017_021bb27c(self);
        self->done = 1;
        return self->state;
    }
    func_ov001_0215a850(&self->allocator);
    func_ov001_0215a8dc();
    func_ov001_021538d4((int)var8, 0, &self->allocator);
#else
    func_ov001_0215a850(&self->allocator);
    func_ov001_0215a8dc();
    func_ov001_021538d4((int)var7, 0, &self->allocator);
#endif
    func_ov001_0215aa14(&self->allocator);
    if (self->params.flags & 4) {
        func_ov001_0215aaa8(1, (int)&res->allocator_array_38[7]);
    }
#if defined(jpn)
    if (FindFilesInNarcBySubstring(var7, data_ov001_021661dc, &var8, &var10, 1) != 0)
#endif
    func_ov001_0215acf8((int)var8, var10);
    GameObject* member = gs->GetPartyMemberByIndex(0);
    if (member != NULL && (**(unsigned int**)((char*)member + 0x130) & 1)) {
        self->unknown_107_ = 1;
    }
    loader->RemoveTask(self->unknown_74_);
#if !defined(jpn)
    loader->RemoveTask(self->unknown_78_);
#endif
    VramState_Rewind((Foo0207df50*)(sub + 0xbd0));

    if (func_ov001_02153948(self->params.unknown_40_) == 0) {
        SignedAllocatorHeader* buffer = self->unknown_124_.GetSignedAllocator();
        if (buffer != NULL) {
            self->unknown_124_.Destroy();
            self->allocator.Free(buffer);
        }
        SignedAllocatorHeader* header = self->allocator.GetSignedAllocator();
        self->allocator.Destroy();
        AllocatorUnion_Free(&g_mainAllocator, header);
        func_ov017_021bb27c(self);
        self->done = 1;
        return self->state;
    }

    int i;
    int total;
    BmdjScriptNode* node;
    Events021552a8* events = Scenario_GetInstance();
    node = Zone3D_GetScriptNode((Zone3D*)Zone3D_GetInstance(), 0);
    total = node->scriptState.elementCount;
    if (node != NULL) {
        memset(events->bits, 0, sizeof(events->bits));
        for (i = 0; i < total; i++) {
            BmdjSceneElement* e = &node->elements[i];
            if (e != NULL && !(e->flags & BmdjElementFlag_Hidden)) {
                Scenario_SetFlag(events, events->bits, (unsigned char)i, 1);
            }
        }
    }

    unsigned char arg = self->unknown_9c_;
    Struct_ov001_021552a8_4 params = self->params;
    GameState* state = GameState::GetInstance();
    GameResources* resources = GetGameResources();
    void* area = (Zone3D*)Zone3D_GetInstance();
    LinkSession_GetInstance();
    GameState_GetParty(state);
    GlobalFlags_GetInstance();
    if (!(params.flags & 0x400)) {
        Zone3D_SaveAndOverrideElementVisibility(area, arg);
    }
    *((char*)Scenario_GetInstance() + 0x490) = -1;
    if (params.unknown_7_ != 0) {
        Object3D* obj = func_ov017_021bdbc0((unsigned char*)resources);
        if (obj != NULL) {
            obj->MakeHidden();
        }
    }

    FollowCamera_DisableFollow(hud);
    func_020a27b8((unsigned char*)hud);
    *(short*)((char*)leader + 0xb2) = 0;
    MapDisplay_SetHoldSubScreenDark((SetFlagStruct*)res->unknown_ptr_36d0, 0);
    return 3;
}
