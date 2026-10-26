#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "NitroSDK/OverlayId.h"
#include "World/Object3D.h"
#include "Input/Input.h"
#include "Resource/Brightness.h"



struct Obj020397cc;
struct Struct_0209494c;
struct Foo0207df50;
struct Base02010834;
struct Struct_0206f81c_2;
struct Struct_0206f81c_3;
struct Struct_0206f81c_4;
struct Struct_0206f81c_5;
struct TailList020469b4;
struct TailNode020469b4;
struct HeadList020469f8;
struct HeadNode020469f8;
struct Struct021b11b0;

#if defined(jpn)
struct Obj02046574;
extern "C" void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
extern "C" void func_0204500c(void* obj, const char* text, int value);
extern "C" char data_ov017_021d7f3b;
enum { Enum_ov017_021acdf4_17582 = 0x41fe, Enum_ov017_021acdf4_17584 = 0x4200, Enum_ov017_021acdf4_6578 = 0x17e2, Enum_ov017_021acdf4_2456 = 0x868, Enum_ov017_021acdf4_32648 = 0x7cb4, Enum_ov017_021acdf4_32636 = 0x7ca8 };
#else
enum { Enum_ov017_021acdf4_17582 = 0x44ae, Enum_ov017_021acdf4_17584 = 0x44b0, Enum_ov017_021acdf4_6578 = 0x19b2, Enum_ov017_021acdf4_2456 = 0x998, Enum_ov017_021acdf4_32648 = 0x7f88, Enum_ov017_021acdf4_32636 = 0x7f7c };
#endif

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

struct Battle021acdf4 {
    char pad0;
    unsigned char done;
    char pad2[6];
    SafeAllocator allocator;
    char pad8[0x1c - 8 - sizeof(SafeAllocator)];
    unsigned char state;
    unsigned char timer;
    unsigned char members;
    unsigned char savedField;
    Vector3i savedPos;
    char pad2c[0x14];
    short task;
    char unknown_42_[2];
#if defined(jpn)
    unsigned char unknown_44_[0x20c - 0x44];
#else
    unsigned char unknown_44_[0x27c - 0x44];
#endif
    unsigned char unknown_27c_;
    unsigned char mode;
    unsigned char unknown_27e_;
    unsigned char unknown_27f_;
    unsigned char special;
    unsigned char unknown_281_;
    unsigned char unknown_282_;
};

extern "C" void* LinkSession_GetInstance(void);
extern "C" void* func_02057924(void);
extern "C" void func_0205c904(unsigned char* obj, int value);
extern "C" void GameObject_DisableControl(Obj020397cc* obj, int arg1);
extern "C" Struct_0209494c* func_020936f8(void);
extern "C" int func_0209494c(Struct_0209494c* g);
extern "C" void func_020a0cc4(unsigned int size);
extern "C" void ROMFilesystem_InitFileTables(void);
extern "C" void func_ov017_021adb50(char* self);
extern "C" unsigned char* GameState_GetZoneTransition(GameState* gs);
extern "C" void func_02070378(char* obj);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern "C" void VramState_Rewind(Foo0207df50* p);
extern "C" void func_0205ce94(unsigned char* obj);
extern "C" int func_02057e6c(void* mgr, int id, SafeAllocator* alloc, void* data, unsigned int length, Foo0207df50* fields);
extern "C" void GameState_GetPartyMemberIds(Base02010834* base, int index, int* out, int* outCount);
extern "C" int LinkSession_IsHostOrSolo(void* p);
extern "C" void func_02057fb4(void* list, int id, void* params);
extern "C" int LinkSession_IsActive(int* p);
extern "C" void func_ov017_021ce014(int id, unsigned short a, unsigned short b, unsigned short c);
extern "C" void SePlayer_LoadExtraArchiveB(void* obj, int arg1, int arg2);
extern "C" void SePlayer_PlayExtra(void* obj, int a, int b);
void SetBrightness(GameResources* resources, int brightness, int duration);
extern "C" void func_ov017_021a65c4(void* obj, unsigned char mode, int arg);
extern "C" void FieldTask_InitEnterZone(unsigned char* obj, int arg);
extern "C" void func_020469b4(TailList020469b4* list, TailNode020469b4* node);
extern "C" void func_0200fb40(void* obj);
extern "C" int func_02011b50(void* obj, int mask);
extern "C" void func_ov017_021b2174(unsigned char* obj);
extern "C" void func_ov017_021b2ba0(Struct_0206f81c_2* obj, char* name);
extern "C" void func_ov017_021b2bd0(void* obj, int a, int b);
extern "C" void func_ov017_021b2bf4(Struct_0206f81c_3* obj, unsigned int v);
extern "C" void func_ov017_021b2c0c(Struct_0206f81c_4* obj, unsigned int v);
extern "C" void func_ov017_021b2bdc(Struct_0206f81c_5* obj, unsigned int v);
extern "C" void func_ov004_021689d8(SafeAllocator* a, void* target);
extern "C" void* Scenario_GetInstance(void);
extern "C" void Scenario_SetFlag(void* unused, unsigned char* array, int bit, int value);
int IsBrightnessTransitionActive(GameResources* resources);
extern "C" void func_02057f00(void* mgr, int id);
extern "C" void SePlayer_UnloadExtraArchiveB(void* obj);
extern "C" void func_ov017_02197528(void);
extern "C" void GameObject_EnableControl(void* obj);
extern "C" void GameObject_ClearHidden(unsigned char* obj);
extern "C" void func_ov017_021c37a4(void);
extern "C" void func_ov017_021b11b0(Struct021b11b0* obj);
extern "C" void func_020469f8(HeadList020469f8* list, HeadNode020469f8* node);
extern "C" int MessageSystem_GetInstance(void);
extern "C" void func_020e4c74(void* out, GameObject* obj);
extern "C" int StandardStrings_Get(int value);
#if !defined(jpn)
extern "C" void func_0204500c(void* obj, int a, int b, int c);
#endif
extern "C" int GameState_GetFollowCamera(char* gs);
extern "C" void Camera_Shake(unsigned char* obj, int a, int b);
extern "C" int func_020a277c(void* obj);
extern "C" void func_020a2770(void* obj, short v);
extern "C" void func_0205ec20(void* obj, void* a, int b);
extern "C" void Party_ReformLine(GameResources* res, int a, int b, int c, int d);
extern "C" void MessageSystem_Reset(char* obj);
extern "C" void func_ov017_021adb1c(Battle021acdf4* self);

extern AllocatorUnion g_mainAllocator;
extern char data_ov017_021d795c;
extern char data_ov017_021d7978;
extern char g_sePlayer;
extern char data_ov017_021d798f;

struct BattleHud021acdf4 {
    char pad[0xa];
    unsigned char visible;
    void inline_ov017_021acdf4(unsigned char v) { visible = v; }
};

static inline BattleHud021acdf4* inline_ov017_021acdf4_2(GameResources* res) {
    return (BattleHud021acdf4*)res->fieldTasks_[0x24];
}

// Overlay 17, originally func_ov017_021acdf4 (USA/EUR 0x021acdf4, JPN 0x021ad62c)
extern "C" ARM void FieldTask_Zoom(Battle021acdf4* self, HeadList020469f8* list) {
    GameState* gs = GameState::GetInstance();
    GameResources* res = GetGameResources();
    GameObject* leader = gs->GetLeader();
    void* mgr = func_02057924();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();

    if (leader == NULL) {
        self->done = 1;
        func_ov017_021adb1c(self);
    }
    unsigned int tick = gs->GetTickCount();
    func_0205c904(self->unknown_44_, tick ? tick : 1);
    GameObject_DisableControl((Obj020397cc*)leader, 1);
    *(short*)((char*)leader + 0xb2) = 0;

    if (self->state == 0) {
        if (self->special && !func_0209494c(func_020936f8())) {
            return;
        }
        func_020a0cc4(0x7000);
        if (self->unknown_282_) {
            func_ov017_021adb50((char*)self);
        }
        if (self->unknown_281_) {
            unsigned char* ctx = GameState_GetZoneTransition(gs);
            func_02070378((char*)ctx);
            ctx[2] = 1;
            *(unsigned short*)ctx = 0xc3b5;
            ctx[7] = 1;
            *(short*)(ctx + 0x1c) = 0;
            *(int*)(ctx + 0x10) = 0x48cc;
            *(int*)(ctx + 0x14) = 0x199;
            *(int*)(ctx + 0x18) = -0x733;
            ctx[0x66] = 1;
            ctx[0x65] = 1;
        }
        self->allocator.CreateTypeA(AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x7000), 0x7000);
        self->allocator.Reset();
        if (self->special) {
            self->task = loader->QueueLoadFile(&data_ov017_021d795c, &self->allocator);
        } else {
            self->task = loader->QueueLoadFile(&data_ov017_021d7978, &self->allocator);
        }
        self->state = 0xe;
    } else if (self->state == 0xe) {
        if (loader->GetTaskStatus(self->task) == 0) {
            return;
        }
        if (self->special && !self->unknown_27f_) {
            if (g_keyManager.TestKeysPressed(0x401) == 0 && g_touchInput.released_ == 0) {
                return;
            }
        }
        Foo0207df50* fields = (Foo0207df50*)((char (*)[0x70])res->vramStates_)[0x1c];
        VramState_Rewind(fields);
        unsigned int length;
        void* data;
        loader->GetLoadedFileByID(self->task, &data, &length);
        if (data == NULL) {
            loader->RemoveTask(self->task);
            func_ov017_021adb1c(self);
            ROMFilesystem_InitFileTables();
            self->done = 1;
            return;
        }
        if (self->special && !self->unknown_27f_) {
            func_0205ce94(self->unknown_44_);
        }
        func_02057e6c(mgr, 8, &self->allocator, data, length, fields);
        loader->RemoveTask(self->task);
        self->state = 1;
    } else if (self->state == 1) {
        int count = 0;
        int ids[5];
        Struct_ov017_021abba8_2 params[5];
        Vector3i scale;
        void* search = LinkSession_GetInstance();
        GameState_GetPartyMemberIds((Base02010834*)gs, *(short*)((char*)leader + 4), ids, &count);
        for (int i = 0; i < count; i++) {
            self->members |= 1 << ids[i];
        }
        if (gs->GetGameObjectByIndex(0xce) && LinkSession_IsHostOrSolo(search)) {
            ids[count] = 0xce;
            self->members |= 0x10;
            count++;
        }
        GameObject* unk = gs->GetLeader();
        int var17 = -1;
        if (unk) {
            var17 = *(short*)((char*)unk + 4);
        }
        for (int k = 0; k < count; k++) {
            GameObject* member = gs->GetGameObjectByIndex(ids[k]);
            if (member && ((Object3D*)member)->IsVisible() && ((Object3D*)member)->GetInheritedAlpha()) {
                if (TestFlags04((GameResources*)res, 4) == 0 || var17 == ids[k]) {
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
                    params[k].position = ((Object3D*)member)->position_;
                    params[k].scale = ((Object3D*)member)->GetScale();
                    func_02057fb4(mgr, 8, &params[k]);
                }
            }
        }
        int id;
        unsigned char members;
        if (LinkSession_IsActive((int*)LinkSession_GetInstance()) && (members = self->members) != 0) {
            id = *(short*)((char*)leader + 4);
            func_ov017_021ce014(id, 3, (int)((Object3D*)leader)->GetField06(), members);
        }
        if (self->special) {
            SePlayer_LoadExtraArchiveB(&g_sePlayer, 0xa3, 0xa3);
            SePlayer_PlayExtra(&g_sePlayer, 5, 0);
        } else {
            SePlayer_LoadExtraArchiveB(&g_sePlayer, 0xb2, 0xb2);
            SePlayer_PlayExtra(&g_sePlayer, 0, 0);
        }
        self->state++;
    } else if (self->state == 2) {
        self->timer += gs->GetTickCount();
        unsigned int limit = self->special ? 0x19 : 0x28;
        if (limit < self->timer) {
            for (int i = 0; i < 5; i++) {
                if (self->members & (1 << i)) {
                    GameObject* member = gs->GetGameObjectByIndex(i != 4 ? i : 0xce);
                    if (member) {
                        ((Object3D*)member)->EnableFlag(1);
                    }
                }
            }
            if (self->unknown_27e_) {
                self->state = 0xa;
            } else {
                self->state++;
            }
        }
    } else if (self->state == 3) {
        self->timer += gs->GetTickCount();
        if (self->timer > 0x64) {
            if (self->unknown_27f_) {
                SetBrightness(res, 0x10, 0x1e);
            } else {
                SetBrightness(res, -0x10, 0x1e);
            }
            self->state++;
        }
    } else if (self->state == 4) {
        self->timer += gs->GetTickCount();
        if (self->timer > 0x8c) {
            for (int i = 0; i < 5; i++) {
                if (self->members & (1 << i)) {
                    GameObject* member = gs->GetGameObjectByIndex(i != 4 ? i : 0xce);
                    if (member) {
                        ((Object3D*)member)->DisableFlag(1);
                    }
                }
            }
            if (!self->unknown_27c_) {
                if (self->special) {
                    func_ov017_021a65c4(res, 2, self->mode);
                } else {
                    func_ov017_021a65c4(res, 0, self->mode);
                }
                if (self->special && !self->unknown_27f_) {
                    inline_ov017_021acdf4_2(res)->inline_ov017_021acdf4(1);
                }
            }
            if (self->unknown_27c_) {
                unsigned char* ctx;
                GameResources* res2;
                GameState* gs2;
                Battle021acdf4* other;
                gs2 = GameState::GetInstance();
                ctx = GameState_GetZoneTransition(gs2);
                res2 = GetGameResources();
                other = (Battle021acdf4*)res2->fieldTasks_[9];
                func_02070378((char*)ctx);
                ctx[4] = 0;
                ctx[5] = 1;
                *(unsigned short*)ctx = *(unsigned short*)((char*)gs2 + Enum_ov017_021acdf4_32648);
                *(Vector3i*)(ctx + 0x10) = *(Vector3i*)((char*)gs2 + Enum_ov017_021acdf4_32636);
                ctx[7] = 1;
                ctx[0x62] = 1;
                ctx[0x63] = other->mode;
                if (*(unsigned short*)((char*)gs2 + Enum_ov017_021acdf4_32648) == 0x2710) {
                    *(short*)ctx = 0x170c;
                    *(int*)(ctx + 0x10) = -0x7000;
                    *(int*)(ctx + 0x14) = 0x2e1;
                    *(int*)(ctx + 0x18) = 0;
                    if (ctx[0x63]) {
                        ctx[0x64] = 1;
                    }
                }
                FieldTask_InitEnterZone((unsigned char*)res2->unknown_ptr_array_3700[3], 0);
                func_020469b4((TailList020469b4*)res2->fieldTaskQueue_, (TailNode020469b4*)res2->unknown_ptr_array_3700[3]);
                func_0200fb40(gs2);
                func_ov017_021a65c4(res, 0, self->mode);
            } else if (func_02011b50(gs, 1)) {
                TailList020469b4* tail;
                unsigned char* node = (unsigned char*)res->fieldTasks_[0x14];
                tail = (TailList020469b4*)res->fieldTaskQueue_;
                func_ov017_021b2174(node);
                func_ov017_021b2ba0((Struct_0206f81c_2*)node, &data_ov017_021d798f);
                func_ov017_021b2bd0(node, (int)func_ov004_021689d8, OVERLAY_ID(4));
                func_ov017_021b2bf4((Struct_0206f81c_3*)node, 1);
                func_ov017_021b2c0c((Struct_0206f81c_4*)node, 1);
                func_ov017_021b2bdc((Struct_0206f81c_5*)node, 0);
                func_020469b4(tail, (TailNode020469b4*)node);
            }
            if (LinkSession_IsHostOrSolo(LinkSession_GetInstance())) {
                unsigned char* flags = (unsigned char*)Scenario_GetInstance();
                Scenario_SetFlag(flags, flags + 0x8c, 0x113d, 1);
            }
            if (self->unknown_27f_) {
                self->state = 6;
            } else {
                self->state++;
            }
        }
    } else if (self->state == 5) {
        if (IsBrightnessTransitionActive(res)) {
            return;
        }
        func_02057f00(mgr, 8);
        SePlayer_UnloadExtraArchiveB(&g_sePlayer);
        func_ov017_02197528();
        self->done = 1;
        GameObject_EnableControl(leader);
        ((Object3D*)leader)->SetInheritedAlpha(0x1f);
        GameObject_ClearHidden((unsigned char*)leader);
        func_ov017_021adb1c(self);
        ROMFilesystem_InitFileTables();
        if (self->special) {
            func_ov017_021c37a4();
        }
        *(short*)((char*)res + Enum_ov017_021acdf4_17582) = 0;
        *(short*)((char*)res + Enum_ov017_021acdf4_17584) = 0;
    } else if (self->state == 6) {
        if (IsBrightnessTransitionActive(res)) {
            return;
        }
        Struct021b11b0* node = (Struct021b11b0*)res->fieldTasks_[0xe];
        func_ov017_021b11b0(node);
        func_020469f8(list, (HeadNode020469f8*)node);
        self->state = 5;
    } else if (self->state == 0xa) {
        self->timer += gs->GetTickCount();
        if (self->timer > 0x37) {
            for (int i = 0; i < 5; i++) {
                if (self->members & (1 << i)) {
                    char* member = (char*)gs->GetPartyMemberByIndex(i != 4 ? i : 0xce);
                    if (member) {
                        ((Object3D*)member)->DisableFlag(1);
                        *(short*)(member + 0x12c) = 0;
                        *(int*)(member + 0x124) = *(int*)(member + 0x48) + 0x9ccc;
                        *(int*)(member + 0x128) = *(int*)(member + 0x48);
                    }
                }
            }
            char* g = (char*)MessageSystem_GetInstance();
#if defined(jpn)
            MessageSystem_SetStringArgument((Obj02046574*)g, 0, *(char**)((char*)gs->GetLeader() + 0x134));
            func_0204500c(g, &data_ov017_021d7f3b, 0);
#else
            char combatant[0xc];
            func_020e4c74(combatant, gs->GetLeader());
            *(char**)g = combatant;
            func_0204500c(g, StandardStrings_Get(0x39), 0, 0xe3);
#endif
            g[Enum_ov017_021acdf4_6578] = 0;
            *(int*)(g + Enum_ov017_021acdf4_2456) = 1;
            unsigned char* obj = (unsigned char*)GameState_GetFollowCamera((char*)gs);
            Camera_Shake(obj, 0xcc, 0x3e8);
            self->savedPos = *(Vector3i*)(obj + 0x10);
            self->savedField = func_020a277c(obj);
            func_020a2770(obj, -1);
            *(Vector3i*)(obj + 0x10) = self->savedPos;
            func_0205ec20(&g_sePlayer, 0, 0);
            SePlayer_PlayExtra(&g_sePlayer, 1, 0);
            self->state++;
        }
    } else if (self->state == 0xb) {
        *(Vector3i*)((char*)GameState_GetFollowCamera((char*)gs) + 0x10) = self->savedPos;
        int var40 = 1;
        for (int i = 0; i < 5; i++) {
            if (self->members & (1 << i)) {
                char* member = (char*)gs->GetPartyMemberByIndex(i != 4 ? i : 0xce);
                if (member && *(int*)(member + 0x124)) {
                    var40 = 0;
                }
            }
        }
        if (var40) {
            self->timer = 0;
            self->state++;
        }
        return;
    } else if (self->state == 0xc) {
        self->timer += gs->GetTickCount();
        if (self->timer > 10) {
            self->state++;
        }
    } else if (self->state == 0xd) {
        char* g = (char*)MessageSystem_GetInstance();
        func_020a2770((void*)GameState_GetFollowCamera((char*)gs), self->savedField);
        func_02057f00(mgr, 8);
        SePlayer_UnloadExtraArchiveB(&g_sePlayer);
        for (int i = 0; i < 5; i++) {
            if (self->members & (1 << i)) {
                GameObject* member = gs->GetGameObjectByIndex(i != 4 ? i : 0xce);
                if (member) {
                    ((Object3D*)member)->DisableFlag(1);
                }
            }
        }
        self->done = 1;
        Party_ReformLine(res, 1, 1, 1, 1);
        GameObject_EnableControl(leader);
        MessageSystem_Reset(g);
        func_ov017_021adb1c(self);
        ROMFilesystem_InitFileTables();
    }
}
