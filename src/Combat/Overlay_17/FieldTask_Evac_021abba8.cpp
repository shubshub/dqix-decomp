#include <globaldefs.h>

#if defined(jpn)
enum { kContextPointerOffset = 0x148 };
#else
enum { kContextPointerOffset = 0x154 };
#endif

#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "NitroSDK/OverlayId.h"
#include "World/Object3D.h"
#include "Resource/Brightness.h"



struct Obj020397cc;
struct ListHead02046b60;
struct Foo0207df50;
struct Base02010834;
struct Struct_0206f81c_2;
struct Struct_0206f81c_3;
struct Struct_0206f81c_4;
struct Struct_0206f81c_5;
struct TailList020469b4;
struct TailNode020469b4;

struct Struct_ov017_021abba8_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[0xf];
    unsigned char f10;
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char unknown_11_4_ : 1;
    unsigned char unknown_11_5_ : 1;
    unsigned char unknown_11_6_ : 1;
    unsigned char unknown_11_7_ : 1;
    short f12;
    short f14;
    short unknown_16_;
    short f18;
    short unknown_1a_;
    short f1c;
    short pad1e;
    int f20;
    int f24;
    int f28;
    Vector3i position;
    int unknown_38_;
    int f3c;
    int f40;
    Vector3i scale;
};

struct Loader021abba8 {
    char pad0;
    unsigned char done;
    char pad2[6];
    unsigned char state;
    char unknown_9_;
    short timer;
    unsigned char active;
    unsigned char members;
    char unknown_e_[2];
    SafeAllocator allocator;
    int task;
};

extern "C" void* LinkSession_GetInstance(void);
extern "C" void* func_02057924(void);
extern "C" void GameObject_DisableControl(Obj020397cc* obj, int arg1);
extern "C" int func_02046b60(ListHead02046b60* list, int id);
extern "C" void func_ov017_021ac2a8(void* obj);
extern "C" void func_02046a8c(void* list, void* node);
extern "C" int FieldTaskQueue_IsEmpty(void** obj);
extern "C" int FontBankLoader_GetInstance(void);
extern "C" void FontBankLoader_CancelLoads(int g);
extern "C" void func_020a0cc4(unsigned int size);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern "C" void VramState_Rewind(Foo0207df50* p);
extern "C" int func_02057e6c(void* mgr, int id, SafeAllocator* alloc, void* data, unsigned int length, Foo0207df50* fields);
extern "C" void GameState_GetPartyMemberIds(Base02010834* base, int index, int* out, int* outCount);
extern "C" int LinkSession_IsHostOrSolo(void* p);
extern "C" void func_02057fb4(void* list, int id, void* params);
extern "C" void SePlayer_LoadExtraArchiveB(void* obj, int arg1, int arg2);
extern "C" void SePlayer_PlayExtra(void* obj, int a, int b);
void SetBrightness(GameResources* resources, int brightness, int duration);
int IsBrightnessTransitionActive(GameResources* resources);
extern "C" void func_ov017_02197528(void);
extern "C" void GameObject_EnableControl(void* obj);
extern "C" void SePlayer_UnloadExtraArchiveB(void* obj);
extern "C" void* Scenario_GetInstance(void);
extern "C" void Scenario_SetFlag(void* unused, unsigned char* array, int bit, int value);
extern "C" int func_02011b50(void* obj, int mask);
extern "C" void func_ov017_021b2174(unsigned char* obj);
extern "C" void func_ov017_021b2ba0(Struct_0206f81c_2* obj, char* name);
extern "C" void func_ov017_021b2bd0(void* obj, int a, int b);
extern "C" void func_ov017_021b2bf4(Struct_0206f81c_3* obj, unsigned int v);
extern "C" void func_ov017_021b2c0c(Struct_0206f81c_4* obj, unsigned int v);
extern "C" void func_ov017_021b2bdc(Struct_0206f81c_5* obj, unsigned int v);
extern "C" void func_020469b4(TailList020469b4* list, TailNode020469b4* node);
extern "C" void func_ov004_021689d8(SafeAllocator* a, void* target);

extern char data_ov017_021d78da;
extern char data_ov017_021d78f1;
extern char g_sePlayer;
extern AllocatorUnion g_mainAllocator;

// Overlay 17, originally func_ov017_021abba8 (USA/EUR 0x021abba8, JPN 0x021ac40c)
extern "C" ARM void FieldTask_Evac(Loader021abba8* self, ListHead02046b60* list) {
    GameState* gs = GameState::GetInstance();
    void* search = LinkSession_GetInstance();
    GameResources* res = GetGameResources();
    GameObject* leader = gs->GetLeader();
    void* mgr = func_02057924();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    int delta = gs->GetTickCount();

    if (self->state == 0) {
        GameObject_DisableControl((Obj020397cc*)leader, 1);
        if (func_02046b60(list, 0x4e)) {
            self->done = 1;
            func_ov017_021ac2a8(self);
            if (func_02046b60(list, 3)) {
                func_02046a8c(list, res->unknown_ptr_array_3700[3]);
            }
        } else if (FieldTaskQueue_IsEmpty((void**)res->unknown_ptr_array_3700[0])) {
            SetFlags00(res, 0x10);
            FontBankLoader_CancelLoads(FontBankLoader_GetInstance());
            func_020a0cc4(0x2800);
            self->task = loader->QueueLoadFile(&data_ov017_021d78da, NULL);
            self->state++;
        }
    } else if (self->state == 1) {
        if (loader->GetTaskStatus(self->task) != 0) {
            if (loader->GetDetailedTaskStatus(self->task) != 2) {
                loader->RemoveTask(self->task);
                self->done = 1;
            }
            unsigned int length;
            void* data;
            loader->GetLoadedFileByID(self->task, &data, &length);
            self->allocator.CreateTypeA(AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x2800), 0x2800);
            self->allocator.Reset();
            Foo0207df50* fields = (Foo0207df50*)(*(char**)((char*)gs->GetLeader() + kContextPointerOffset) + 0x568);
            VramState_Rewind(fields);
            void* copy = self->allocator.Allocate(length);
            memcpy(copy, data, length);
            func_02057e6c(mgr, 5, &self->allocator, copy, length, fields);
            loader->RemoveTask(self->task);
            self->state++;
        }
    } else if (self->state == 2) {
        int count = 0;
        int ids[5];
        Struct_ov017_021abba8_2 params[5];
        if (self->active != 0) {
            GameState_GetPartyMemberIds((Base02010834*)gs, leader->obj3D_.actorIndex_, ids, &count);
            for (int i = 0; i < count; i++) {
                self->members |= 1 << ids[i];
            }
            if (gs->GetGameObjectByIndex(0xce) && LinkSession_IsHostOrSolo(search)) {
                ids[count] = 0xce;
                self->members |= 0x10;
                count++;
            }
        } else {
            for (int i = 0; i < 5; i++) {
                if (self->members & (1 << i)) {
                    if (i != 4) {
                        ids[count] = i;
                    } else {
                        ids[count] = 0xce;
                    }
                    count++;
                }
            }
        }
        for (int k = 0; k < count; k++) {
            GameObject* member = gs->GetGameObjectByIndex(ids[k]);
            if (member) {
                params[k].unknown_0_ = 0;
                params[k].f10 = 1;
                params[k].f12 = 0;
                params[k].f14 = -1;
                params[k].unknown_16_ = -1;
                params[k].f18 = -1;
                params[k].unknown_1a_ = -1;
                params[k].f1c = -0x1000;
                params[k].f20 = 0;
                params[k].f24 = 0;
                params[k].f28 = 0;
                params[k].position.x = 0;
                params[k].position.y = 0;
                params[k].position.z = 0;
                params[k].unknown_38_ = 0;
                params[k].f3c = 0;
                params[k].f40 = 0;
                params[k].scale.x = 0x1000;
                params[k].scale.y = 0x1000;
                params[k].scale.z = 0x1000;
                params[k].b0 = 0;
                params[k].b1 = 0;
                params[k].b2 = 1;
                params[k].b3 = 0;
                params[k].unknown_11_4_ = 0;
                params[k].unknown_11_5_ = 0;
                params[k].unknown_11_6_ = 0;
                params[k].unknown_11_7_ = 0;
                params[k].position = member->obj3D_.position_;
                params[k].scale = member->obj3D_.GetScale();
                func_02057fb4(mgr, 5, &params[k]);
            }
        }
        self->state++;
    } else if (self->state == 3) {
        self->timer += delta;
        if (self->timer > 8) {
            SePlayer_LoadExtraArchiveB(&g_sePlayer, 0xb1, 0xb1);
            SePlayer_PlayExtra(&g_sePlayer, 0, 0);
            self->state++;
        }
    } else if (self->state == 4) {
        self->timer += delta;
        if (self->timer > 0x32) {
            for (int i = 0; i < 5; i++) {
                if (self->members & (1 << i)) {
                    GameObject* member = gs->GetGameObjectByIndex(i != 4 ? i : 0xce);
                    if (member) {
                        member->obj3D_.EnableFlag(1);
                    }
                }
            }
            self->state++;
        }
    } else if (self->state == 5) {
        self->timer += delta;
        if (self->timer > 0x6e) {
            SetBrightness(res, -0x10, 0x1e);
            self->state++;
        }
    } else if (self->state == 6) {
        self->timer += delta;
        if (self->timer > 0xaa && !IsBrightnessTransitionActive(res)) {
            for (int i = 0; i < 5; i++) {
                if (self->members & (1 << i)) {
                    GameObject* member = gs->GetGameObjectByIndex(i != 4 ? i : 0xce);
                    if (member) {
                        member->obj3D_.DisableFlag(1);
                    }
                }
            }
            ClearFlags00(res, 0x10);
            func_ov017_02197528();
            self->done = 1;
            GameObject_EnableControl(leader);
            func_ov017_021ac2a8(self);
            SePlayer_UnloadExtraArchiveB(&g_sePlayer);
            if (LinkSession_IsHostOrSolo(search)) {
                unsigned char* flags = (unsigned char*)Scenario_GetInstance();
                Scenario_SetFlag(flags, flags + 0x8c, 0x113d, 1);
            }
            if (func_02011b50(gs, 1) && self->active != 0) {
                TailList020469b4* tail;
                unsigned char* node = (unsigned char*)res->fieldTasks_[0x14];
                tail = (TailList020469b4*)res->fieldTaskQueue_;
                func_ov017_021b2174(node);
                func_ov017_021b2ba0((Struct_0206f81c_2*)node, &data_ov017_021d78f1);
                func_ov017_021b2bd0(node, (int)func_ov004_021689d8, OVERLAY_ID(4));
                func_ov017_021b2bf4((Struct_0206f81c_3*)node, 1);
                func_ov017_021b2c0c((Struct_0206f81c_4*)node, 1);
                func_ov017_021b2bdc((Struct_0206f81c_5*)node, 0);
                func_020469b4(tail, (TailNode020469b4*)node);
            }
        }
    }
}
