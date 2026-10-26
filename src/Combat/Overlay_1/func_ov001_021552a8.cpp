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
struct Obj0208b8c4;
struct Pool020401fc;
struct PacRecord;
struct Foo0207df50;
struct SetFlagStruct;

struct Struct_ov001_021552a8_3 {
    char unknown_0_[0x3c];
    void* unknown_3c_;
    Struct_02043368_2* unknown_40_;
    char unknown_44_[8];
    unsigned short unknown_4c_;
    char unknown_4e_[2];
    unsigned char unknown_50_;
};

struct Struct_ov001_021552a8_4 {
    int unknown_0_;
    char unknown_4_[3];
    unsigned char unknown_7_;
    char unknown_8_[0x38];
    unsigned short unknown_40_;
    unsigned short unknown_42_;
    unsigned short unknown_44_;
    char unknown_46_[0x22];
};

struct Struct_ov001_021552a8 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    char unknown_2_[8];
    unsigned short unknown_a_;
    Struct_ov001_021552a8_4 unknown_c_;
    int unknown_74_;
#if !defined(jpn)
    int unknown_78_;
#endif
    SafeAllocator unknown_7c_;
    char unknown_90_[4];
    int unknown_94_;
    char unknown_98_[4];
    unsigned char unknown_9c_;
    char unknown_9d_[0x107 - 0x9d];
    unsigned char unknown_107_;
    char unknown_108_[8];
    int unknown_110_;
    char unknown_114_[0xc];
    void* unknown_120_;
    SafeAllocator unknown_124_;
    char unknown_138_[0x30];
    Struct_ov001_021552a8_3* unknown_168_;
    void* unknown_16c_;
    Struct_02043368_2* unknown_170_;
};

struct Struct_ov001_021552a8_2 {
    char unknown_0_[0x45b];
    unsigned char unknown_45b_[0x20];
};

char* GameState_GetFollowCamera(char* obj);
void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
extern "C" void func_0209c2e0(void* obj, int a, int b);
extern "C" void func_ov017_021bb27c(void* obj);
extern "C" void func_0208b9a0(void* obj, unsigned char flag);
char* MessageSystem_GetInstance(void);
void InitAllocatorsAndBuffers0208b8c4(Obj0208b8c4* obj, SafeAllocator* alloc);
void* GetGlobalPtr021075f4_0203cf4c(void);
void* EmptyStub0203d004(void* p);
void InitPool020401fc(Pool020401fc* pool, unsigned int count, SafeAllocator* alloc);
void Sprite_Init(Struct0205a198* p);
void ClearField0And40205a234(ClearTarget0205a234* p);
void SpriteContext_Init(char* p);
int Pac_CountFiles(PacRecord* entry);
void* Pac_GetFile(PacRecord* rec, int index, void** out, int* out44);
extern "C" int SpriteContext_LoadFile(void* obj, void* data, int arg2, void* arg3);
extern "C" void func_ov001_0215a850(SafeAllocator* alloc);
extern "C" void func_ov001_0215a8dc(void);
void InitOrClearAllocState_021538d4(int p0, void* unused1, SafeAllocator* alloc);
void ClearAllocSlotsAndStore_0215aa14(SafeAllocator* alloc);
void SetArrVal0215aaa8(int idx, int val);
void ForwardArgsAndClearFlag8c_0215acf8(int a, int b);
void VramState_Rewind(Foo0207df50* p);
int StoreArgIfMatched_02153948(unsigned short arg);
extern "C" Events021552a8* Scenario_GetInstance(void);
extern "C" void* Zone3D_GetInstance(void);
extern "C" void Scenario_SetFlag(void* unused, unsigned char* array, int bit, int value);
extern "C" void* LinkSession_GetInstance(void);
void* GameState_GetParty(GameState* gs);
void* GlobalFlags_GetInstance(void);
void Zone3D_SaveAndOverrideElementVisibility(void* area, int arg);
Object3D* GetField4334_021bdbc0(unsigned char* base);
void FollowCamera_DisableFollow(void* obj);
void ClearIntAt0x23c_020a27b8(unsigned char* obj);
void MapDisplay_SetHoldSubScreenDark(SetFlagStruct* p, int value);

extern AllocatorUnion g_mainAllocator;
extern char g_bgmPlayer;
#if defined(jpn)
extern const char data_ov001_021661d7[];
extern const char data_ov001_021661dc[];
#endif

static inline void inline_ov001_021552a8(Struct_ov001_021552a8_3* arg0, Struct_02043368_2* arg1, unsigned short arg2) {
    arg0->unknown_40_ = arg1;
    arg0->unknown_4c_ = arg2;
}

// USA: func_ov001_021552a8
extern "C" ARM int func_ov001_021552a8(Self021552a8* self) {
    char* sub;
    GameState* gs = GameState::GetInstance();
    GameResources* res = GetGameResources();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    char* hud = GameState_GetFollowCamera((char*)gs);
    GameObject* leader = gs->GetLeader();
    sub = res->vramStates_;

    if (var3->GetTaskStatus(arg0->unknown_74_) == 0) {
        return arg0->unknown_a_;
    }
#if !defined(jpn)
    if (var3->GetTaskStatus(arg0->unknown_78_) == 0) {
        return arg0->unknown_a_;
    }
#endif
    if (arg0->unknown_c_.unknown_44_ & 0x200) {
        if (var3->GetTaskStatus(arg0->unknown_110_) == 0) {
            return arg0->unknown_a_;
        }
    }
#if defined(jpn)
    if (var3->GetDetailedTaskStatus(arg0->unknown_74_) != 2) {
#else
    if (var3->GetDetailedTaskStatus(arg0->unknown_74_) != 2 || var3->GetDetailedTaskStatus(arg0->unknown_78_) != 2) {
#endif
        SignedAllocatorHeader* header = self->allocator.GetSignedAllocator();
        self->allocator.Destroy();
        AllocatorUnion_Free(&g_mainAllocator, header);
        loader->RemoveTask(self->taskA);
#if !defined(jpn)
        var3->RemoveTask(arg0->unknown_78_);
#endif
        loader->RemoveTask(self->taskC);
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
    var3->GetLoadedFileByID(arg0->unknown_74_, &var7, &var9);
#if !defined(jpn)
    var3->GetLoadedFileByID(arg0->unknown_78_, &var8, &var10);
#endif

    if (self->params.flags & 2) {
        self->timer = self->allocator.Allocate(0xe4);
        func_0208b9a0(self->timer, 0);
        char* msg = MessageSystem_GetInstance();
        self->childAllocator.CreateTypeA(self->allocator.Allocate(0xa000), 0xa000);
        self->childAllocator.Reset();
        InitAllocatorsAndBuffers0208b8c4((Obj0208b8c4*)self->timer, &self->childAllocator);
#if defined(jpn)
        *(void**)(var11 + 0x4c) = arg0->unknown_120_;
#else
        *(void**)(var11 + 0x8c) = arg0->unknown_120_;
#endif
    }
    if ((arg0->unknown_c_.unknown_44_ & 1) || (arg0->unknown_c_.unknown_44_ & 4)) {
        func_020401fc((Struct_0203d028_6*)func_0203d004(func_0203cf4c()), 0xc, &arg0->unknown_7c_);
    }
    if (self->params.flags & 0x200) {
        self->allocator.GetMaxPossibleAllocation();
        self->entries = (Struct0205a198*)self->allocator.Allocate(0x230);
        self->list = (List021552a8*)self->allocator.Allocate(0x54);
        self->slots = self->allocator.Allocate(8);
        for (int i = 0; i < 0xe; i++) {
            Sprite_Init((Struct0205a198*)((char*)self->entries + i * 0x28));
        }
        ClearField0And40205a234((ClearTarget0205a234*)self->slots);
        SpriteContext_Init((char*)self->list);
        self->list->active = 0;
        SetListEntries(self->list, self->entries, 0xe);
        self->list->slots = self->slots;

        void* out;
        void* dataC;
        unsigned int lengthC;
        int size;
        loader->GetLoadedFileByID(self->taskC, &dataC, &lengthC);
        int count = Pac_CountFiles((PacRecord*)dataC);
        for (int j = 0; j < count; j++) {
            void* rec = Pac_GetFile((PacRecord*)dataC, j, &out, &size);
            SpriteContext_LoadFile(self->list, rec, size, &self->allocator);
        }
        var3->RemoveTask(arg0->unknown_110_);
        arg0->unknown_110_ = -1;
    }

#if defined(jpn)
    const void* var8;
    unsigned int var10;
    if (FindFilesInNarcBySubstring(var7, data_ov001_021661d7, &var8, &var10, 1) == 0) {
        func_ov017_021bb27c(arg0);
        arg0->unknown_1_ = 1;
        return arg0->unknown_a_;
    }
    func_ov001_0215a850(&arg0->unknown_7c_);
    func_ov001_0215a8dc();
    func_ov001_021538d4((int)var8, 0, &arg0->unknown_7c_);
#else
    func_ov001_0215a850(&arg0->unknown_7c_);
    func_ov001_0215a8dc();
    func_ov001_021538d4((int)var7, 0, &arg0->unknown_7c_);
#endif
    func_ov001_0215aa14(&arg0->unknown_7c_);
    if (arg0->unknown_c_.unknown_44_ & 4) {
        func_ov001_0215aaa8(1, (int)&var2->allocator_array_38[7]);
    }
#if defined(jpn)
    if (FindFilesInNarcBySubstring(var7, data_ov001_021661dc, &var8, &var10, 1) != 0)
#endif
    func_ov001_0215acf8((int)var8, var10);
    GameObject* var20 = var1->GetPartyMemberByIndex(0);
    if (var20 != NULL && (**(unsigned int**)((char*)var20 + 0x130) & 1)) {
        arg0->unknown_107_ = 1;
    }
    var3->RemoveTask(arg0->unknown_74_);
#if !defined(jpn)
    var3->RemoveTask(arg0->unknown_78_);
#endif
    VramState_Rewind((Foo0207df50*)(sub + 0xbd0));

    if (func_ov001_02153948(arg0->unknown_c_.unknown_40_) == 0) {
        SignedAllocatorHeader* var21 = arg0->unknown_124_.GetSignedAllocator();
        if (var21 != NULL) {
            arg0->unknown_124_.Destroy();
            arg0->unknown_7c_.Free(var21);
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

    unsigned char arg = self->field9c;
    Params021552a8 params = self->params;
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
    if (params.hide != 0) {
        Object3D* obj = GetField4334_021bdbc0((unsigned char*)resources);
        if (obj != NULL) {
            obj->MakeHidden();
        }
    }

    FollowCamera_DisableFollow(hud);
    ClearIntAt0x23c_020a27b8((unsigned char*)hud);
    *(short*)((char*)leader + 0xb2) = 0;
    MapDisplay_SetHoldSubScreenDark((SetFlagStruct*)res->unknown_ptr_36d0, 0);
    return 3;
}
