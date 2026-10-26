#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "NitroSDK/OverlayId.h"
#include "World/Object3D.h"
#include "Input/Input.h"
#include "Resource/Brightness.h"



struct Struct_02018300_3;
struct Struct_0209494c;
struct Struct_0203d028;
struct Struct_02010834;
struct Struct_0206f81c_2;
struct Struct_0206f81c_3;
struct Struct_0206f81c_4;
struct Struct_0206f81c_5;
struct Struct_0201bdac_2;
struct Struct_0201bdac;
struct Struct_020469f8;
struct Struct_020469f8_2;
struct Struct_ov003_021638e4_2;

#if defined(jpn)
struct Obj02046574;
void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
extern "C" void func_0204500c(void* obj, const char* text, int value);
extern "C" char data_ov017_021d7f3b;
enum { Enum_ov017_021acdf4_17582 = 0x41fe, Enum_ov017_021acdf4_17584 = 0x4200, Enum_ov017_021acdf4_6578 = 0x17e2, Enum_ov017_021acdf4_2456 = 0x868, Enum_ov017_021acdf4_32648 = 0x7cb4, Enum_ov017_021acdf4_32636 = 0x7ca8 };
#else
enum { Enum_ov017_021acdf4_17582 = 0x44ae, Enum_ov017_021acdf4_17584 = 0x44b0, Enum_ov017_021acdf4_6578 = 0x19b2, Enum_ov017_021acdf4_2456 = 0x998, Enum_ov017_021acdf4_32648 = 0x7f88, Enum_ov017_021acdf4_32636 = 0x7f7c };
#endif

struct Struct_ov017_021abba8_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[0xf];
    unsigned char unknown_10_;
    unsigned char unknown_11_0_ : 1;
    unsigned char unknown_11_1_ : 1;
    unsigned char unknown_11_2_ : 1;
    unsigned char unknown_11_3_ : 1;
    unsigned char unknown_11_4_ : 1;
    unsigned char unknown_11_5_ : 1;
    unsigned char unknown_11_6_ : 1;
    unsigned char unknown_11_7_ : 1;
    short unknown_12_;
    short unknown_14_;
    short unknown_16_;
    short unknown_18_;
    short unknown_1a_;
    short unknown_1c_;
    short unknown_1e_;
    int unknown_20_;
    int unknown_24_;
    int unknown_28_;
    Vector3i unknown_2c_;
    int unknown_38_;
    int unknown_3c_;
    int unknown_40_;
    Vector3i unknown_44_;
};

struct Struct_ov017_021acdf4 {
    char unknown_0_;
    unsigned char unknown_1_;
    char unknown_2_[6];
    SafeAllocator unknown_8_;
    char unknown_1c_[0x1c - 8 - sizeof(SafeAllocator)];
    unsigned char unknown1_1c_;
    unsigned char unknown_1d_;
    unsigned char unknown_1e_;
    unsigned char unknown_1f_;
    Vector3i unknown_20_;
    char unknown_2c_[0x14];
    short unknown_40_;
    char unknown_42_[2];
#if defined(jpn)
    unsigned char unknown_44_[0x20c - 0x44];
#else
    unsigned char unknown_44_[0x27c - 0x44];
#endif
    unsigned char unknown_27c_;
    unsigned char unknown_27d_;
    unsigned char unknown_27e_;
    unsigned char unknown_27f_;
    unsigned char unknown_280_;
    unsigned char unknown_281_;
    unsigned char unknown_282_;
};

extern "C" void* LinkSession_GetInstance(void);
extern "C" void* func_02057924(void);
void SetupAndDispatch0205c904(unsigned char* obj, int value);
void GameObject_DisableControl(Obj020397cc* obj, int arg1);
StateFlags3c9* GetGlobal02109030_020936f8(void);
int CheckFlag0x3c9Bit0OrByteNonPositive_0209494c(StateFlags3c9* g);
extern "C" void func_020a0cc4(unsigned int size);
extern "C" void ROMFilesystem_InitFileTables(void);
void InitCombatPairAndResetGlobal_021adb50(char* self);
unsigned char* GameState_GetZoneTransition(GameState* gs);
void InitStruct02070378(char* obj);
void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
void VramState_Rewind(Foo0207df50* p);
void ResetGlobalObjAndInitSelfPointer0205ce94(unsigned char* obj);
extern "C" int func_02057e6c(void* mgr, int id, SafeAllocator* alloc, void* data, unsigned int length, Foo0207df50* fields);
void GameState_GetPartyMemberIds(Base02010834* base, int index, int* out, int* outCount);
extern "C" int LinkSession_IsHostOrSolo(void* p);
void FindNodeAndProcess02057fb4(void* list, int id, void* params);
int LinkSession_IsActive(int* p);
void EnqueueEventTag17_021ce014(int id, unsigned short a, unsigned short b, unsigned short c);
void SePlayer_LoadExtraArchiveB(void* obj, int arg1, int arg2);
void SePlayer_PlayExtra(void* obj, int a, int b);
void SetBrightness(GameResources* resources, int brightness, int duration);
void InitAndAppendState61_021a65c4(void* obj, unsigned char mode, int arg);
void FieldTask_InitEnterZone(unsigned char* obj, int arg);
void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);
void ClearSubstructBytes_0200fb40(void* obj);
int CheckBitsInField0x63dc_02011b50(void* obj, int mask);
void InitObjState_021b2174(unsigned char* obj);
void SetNameChecked_021b2ba0(S021b2ba0* obj, char* name);
void SetFields30And34_021b2bd0(void* obj, int a, int b);
void SetBit4_021b2bf4(S021b2bf4* obj, unsigned int v);
void SetBit5_021b2c0c(S021b2c0c* obj, unsigned int v);
void SetBit3_021b2bdc(S021b2bdc* obj, unsigned int v);
void AllocateAndCopyBuf20_021689d8(SafeAllocator* a, void* target);
extern "C" void* Scenario_GetInstance(void);
extern "C" void Scenario_SetFlag(void* unused, unsigned char* array, int bit, int value);
int IsBrightnessTransitionActive(GameResources* resources);
extern "C" void func_02057f00(void* mgr, int id);
void SePlayer_UnloadExtraArchiveB(void* obj);
void CallListIfFlagsSet_02197528(void);
void GameObject_EnableControl(void* obj);
void GameObject_ClearHidden(unsigned char* obj);
extern "C" void func_ov017_021c37a4(void);
void InitState39_021b11b0(Struct021b11b0* obj);
void PrependNodeToHead(HeadList020469f8* list, HeadNode020469f8* node);
int MessageSystem_GetInstance(void);
void InitObjFromCombatant020e4c74(void* out, GameObject* obj);
int StandardStrings_Get(int value);
#if !defined(jpn)
extern "C" void func_0204500c(void* arg0, int arg1, int arg2, int arg3);
#endif
int GameState_GetFollowCamera(char* gs);
void Camera_Shake(unsigned char* obj, int a, int b);
int GetField0x21c020a277c(void* obj);
void SetField0x21c_020a2770(void* obj, short v);
void Forward0205ec20(void* obj, void* a, int b);
extern "C" void Party_ReformLine(GameResources* res, int a, int b, int c, int d);
void MessageSystem_Reset(char* obj);
extern "C" void func_ov017_021adb1c(Battle021acdf4* self);

extern AllocatorUnion g_mainAllocator;
extern char data_ov017_021d795c;
extern char data_ov017_021d7978;
extern char g_sePlayer;
extern char data_ov017_021d798f;

struct Struct_01ff91ac_21 {
    char unknown_0_[0xa];
    unsigned char unknown_a_;
    void inline_ov017_021acdf4(unsigned char arg0) { unknown_a_ = arg0; }
};

static inline BattleHud021acdf4* GetBattleHud(GameResources* res) {
    return (BattleHud021acdf4*)res->fieldTasks_[0x24];
}

// Overlay 17, originally func_ov017_021acdf4 (USA/EUR 0x021acdf4, JPN 0x021ad62c)
extern "C" ARM void FieldTask_Zoom(Battle021acdf4* self, HeadList020469f8* list) {
    GameState* gs = GameState::GetInstance();
    GameResources* res = GetGameResources();
    GameObject* leader = gs->GetLeader();
    void* mgr = func_02057924();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();

    if (var2 == NULL) {
        arg0->unknown_1_ = 1;
        func_ov017_021adb1c(arg0);
    }
    unsigned int tick = gs->GetTickCount();
    SetupAndDispatch0205c904(self->sub44, tick ? tick : 1);
    GameObject_DisableControl((Obj020397cc*)leader, 1);
    *(short*)((char*)leader + 0xb2) = 0;

    if (arg0->unknown1_1c_ == 0) {
        if (arg0->unknown_280_ && !func_0209494c(func_020936f8())) {
            return;
        }
        func_020a0cc4(0x7000);
        if (arg0->unknown_282_) {
            func_ov017_021adb50((char*)arg0);
        }
        if (self->initCtx) {
            unsigned char* ctx = GameState_GetZoneTransition(gs);
            InitStruct02070378((char*)ctx);
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
            arg0->unknown_40_ = var4->QueueLoadFile(&data_ov017_021d7978, &arg0->unknown_8_);
        }
        arg0->unknown1_1c_ = 0xe;
    } else if (arg0->unknown1_1c_ == 0xe) {
        if (var4->GetTaskStatus(arg0->unknown_40_) == 0) {
            return;
        }
        if (arg0->unknown_280_ && !arg0->unknown_27f_) {
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
        if (arg0->unknown_280_ && !arg0->unknown_27f_) {
            func_0205ce94(arg0->unknown_44_);
        }
        func_02057e6c(mgr, 8, &self->allocator, data, length, fields);
        loader->RemoveTask(self->task);
        self->state = 1;
    } else if (self->state == 1) {
        int count = 0;
        int ids[5];
        ObjParams02078484 params[5];
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
        int leaderId = -1;
        if (unk) {
            leaderId = *(short*)((char*)unk + 4);
        }
        for (int var18 = 0; var18 < var10; var18++) {
            GameObject* var19 = var0->GetGameObjectByIndex(var11[var18]);
            if (var19 && ((Object3D*)var19)->IsVisible() && ((Object3D*)var19)->GetInheritedAlpha()) {
                if (TestFlags04((GameResources*)var1, 4) == 0 || var17 == var11[var18]) {
                    var12[var18].unknown_0_ = 0;
                    var12[var18].unknown_10_ = 1;
                    var12[var18].unknown_12_ = 0;
                    var12[var18].unknown_14_ = -1;
                    var12[var18].unknown_16_ = -1;
                    var12[var18].unknown_18_ = -1;
                    var12[var18].unknown_1a_ = -1;
                    var12[var18].unknown_1c_ = -0x1000;
                    var12[var18].unknown_20_ = 0;
                    var12[var18].unknown_24_ = 0;
                    var12[var18].unknown_28_ = 0;
                    var12[var18].unknown_2c_.x = 0;
                    var12[var18].unknown_2c_.y = 0;
                    var12[var18].unknown_2c_.z = 0;
                    var12[var18].unknown_38_ = 0;
                    var12[var18].unknown_3c_ = 0;
                    var12[var18].unknown_40_ = 0;
                    var12[var18].unknown_44_.x = 0x1000;
                    var12[var18].unknown_44_.y = 0x1000;
                    var12[var18].unknown_44_.z = 0x1000;
                    var12[var18].unknown_11_0_ = 0;
                    var12[var18].unknown_11_1_ = 0;
                    var12[var18].unknown_11_2_ = 1;
                    var12[var18].unknown_11_3_ = 0;
                    var12[var18].unknown_11_4_ = 0;
                    var12[var18].unknown_11_5_ = 0;
                    var12[var18].unknown_11_6_ = 0;
                    var12[var18].unknown_11_7_ = 0;
                    var12[var18].unknown_2c_ = ((Object3D*)var19)->position_;
                    var12[var18].unknown_44_ = ((Object3D*)var19)->GetScale();
                    func_02057fb4(var3, 8, &var12[var18]);
                }
            }
        }
        int id;
        unsigned char members;
        if (LinkSession_IsActive((int*)LinkSession_GetInstance()) && (members = self->members) != 0) {
            id = *(short*)((char*)leader + 4);
            EnqueueEventTag17_021ce014(id, 3, (int)((Object3D*)leader)->GetField06(), members);
        }
        if (self->special) {
            SePlayer_LoadExtraArchiveB(&g_sePlayer, 0xa3, 0xa3);
            SePlayer_PlayExtra(&g_sePlayer, 5, 0);
        } else {
            SePlayer_LoadExtraArchiveB(&g_sePlayer, 0xb2, 0xb2);
            SePlayer_PlayExtra(&g_sePlayer, 0, 0);
        }
        arg0->unknown1_1c_++;
    } else if (arg0->unknown1_1c_ == 2) {
        arg0->unknown_1d_ += var0->GetTickCount();
        unsigned int var22 = arg0->unknown_280_ ? 0x19 : 0x28;
        if (var22 < arg0->unknown_1d_) {
            for (int var23 = 0; var23 < 5; var23++) {
                if (arg0->unknown_1e_ & (1 << var23)) {
                    GameObject* var24 = var0->GetGameObjectByIndex(var23 != 4 ? var23 : 0xce);
                    if (var24) {
                        ((Object3D*)var24)->EnableFlag(1);
                    }
                }
            }
            if (arg0->unknown_27e_) {
                arg0->unknown1_1c_ = 0xa;
            } else {
                arg0->unknown1_1c_++;
            }
        }
    } else if (arg0->unknown1_1c_ == 3) {
        arg0->unknown_1d_ += var0->GetTickCount();
        if (arg0->unknown_1d_ > 0x64) {
            if (arg0->unknown_27f_) {
                SetBrightness(var1, 0x10, 0x1e);
            } else {
                SetBrightness(var1, -0x10, 0x1e);
            }
            arg0->unknown1_1c_++;
        }
    } else if (arg0->unknown1_1c_ == 4) {
        arg0->unknown_1d_ += var0->GetTickCount();
        if (arg0->unknown_1d_ > 0x8c) {
            for (int var25 = 0; var25 < 5; var25++) {
                if (arg0->unknown_1e_ & (1 << var25)) {
                    GameObject* var26 = var0->GetGameObjectByIndex(var25 != 4 ? var25 : 0xce);
                    if (var26) {
                        ((Object3D*)var26)->DisableFlag(1);
                    }
                }
            }
            if (!arg0->unknown_27c_) {
                if (arg0->unknown_280_) {
                    func_ov017_021a65c4(var1, 2, arg0->unknown_27d_);
                } else {
                    func_ov017_021a65c4(var1, 0, arg0->unknown_27d_);
                }
                if (arg0->unknown_280_ && !arg0->unknown_27f_) {
                    inline_ov017_021acdf4_2(var1)->inline_ov017_021acdf4(1);
                }
            }
            if (self->skipIntro) {
                unsigned char* ctx;
                GameResources* res2;
                GameState* gs2;
                Battle021acdf4* other;
                gs2 = GameState::GetInstance();
                ctx = GameState_GetZoneTransition(gs2);
                res2 = GetGameResources();
                other = (Battle021acdf4*)res2->fieldTasks_[9];
                InitStruct02070378((char*)ctx);
                ctx[4] = 0;
                ctx[5] = 1;
                *(unsigned short*)ctx = *(unsigned short*)((char*)gs2 + GameEvent);
                *(Vector3i*)(ctx + 0x10) = *(Vector3i*)((char*)gs2 + GameEventData);
                ctx[7] = 1;
                ctx[0x62] = 1;
                ctx[0x63] = other->mode;
                if (*(unsigned short*)((char*)gs2 + GameEvent) == 0x2710) {
                    *(short*)ctx = 0x170c;
                    *(int*)(ctx + 0x10) = -0x7000;
                    *(int*)(ctx + 0x14) = 0x2e1;
                    *(int*)(ctx + 0x18) = 0;
                    if (ctx[0x63]) {
                        ctx[0x64] = 1;
                    }
                }
                FieldTask_InitEnterZone((unsigned char*)res2->unknown_ptr_array_3700[3], 0);
                AppendNodeToTail((TailList020469b4*)res2->fieldTaskQueue_, (TailNode020469b4*)res2->unknown_ptr_array_3700[3]);
                ClearSubstructBytes_0200fb40(gs2);
                InitAndAppendState61_021a65c4(res, 0, self->mode);
            } else if (CheckBitsInField0x63dc_02011b50(gs, 1)) {
                TailList020469b4* tail;
                unsigned char* node = (unsigned char*)res->fieldTasks_[0x14];
                tail = (TailList020469b4*)res->fieldTaskQueue_;
                InitObjState_021b2174(node);
                SetNameChecked_021b2ba0((S021b2ba0*)node, &data_ov017_021d798f);
                SetFields30And34_021b2bd0(node, (int)AllocateAndCopyBuf20_021689d8, OVERLAY_ID(4));
                SetBit4_021b2bf4((S021b2bf4*)node, 1);
                SetBit5_021b2c0c((S021b2c0c*)node, 1);
                SetBit3_021b2bdc((S021b2bdc*)node, 0);
                AppendNodeToTail(tail, (TailNode020469b4*)node);
            }
            if (LinkSession_IsHostOrSolo(LinkSession_GetInstance())) {
                unsigned char* flags = (unsigned char*)Scenario_GetInstance();
                Scenario_SetFlag(flags, flags + 0x8c, 0x113d, 1);
            }
            if (arg0->unknown_27f_) {
                arg0->unknown1_1c_ = 6;
            } else {
                arg0->unknown1_1c_++;
            }
        }
    } else if (arg0->unknown1_1c_ == 5) {
        if (IsBrightnessTransitionActive(var1)) {
            return;
        }
        func_02057f00(mgr, 8);
        SePlayer_UnloadExtraArchiveB(&g_sePlayer);
        CallListIfFlagsSet_02197528();
        self->done = 1;
        GameObject_EnableControl(leader);
        ((Object3D*)leader)->SetInheritedAlpha(0x1f);
        GameObject_ClearHidden((unsigned char*)leader);
        func_ov017_021adb1c(self);
        ROMFilesystem_InitFileTables();
        if (self->special) {
            func_ov017_021c37a4();
        }
        *(short*)((char*)var1 + Enum_ov017_021acdf4_17582) = 0;
        *(short*)((char*)var1 + Enum_ov017_021acdf4_17584) = 0;
    } else if (arg0->unknown1_1c_ == 6) {
        if (IsBrightnessTransitionActive(var1)) {
            return;
        }
        Struct021b11b0* node = (Struct021b11b0*)res->fieldTasks_[0xe];
        InitState39_021b11b0(node);
        PrependNodeToHead(list, (HeadNode020469f8*)node);
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
            InitObjFromCombatant020e4c74(combatant, gs->GetLeader());
            *(char**)g = combatant;
            func_0204500c(g, StandardStrings_Get(0x39), 0, 0xe3);
#endif
            g[MessageDone] = 0;
            *(int*)(g + MessageActive) = 1;
            unsigned char* obj = (unsigned char*)GameState_GetFollowCamera((char*)gs);
            Camera_Shake(obj, 0xcc, 0x3e8);
            self->savedPos = *(Vector3i*)(obj + 0x10);
            self->savedField = GetField0x21c020a277c(obj);
            SetField0x21c_020a2770(obj, -1);
            *(Vector3i*)(obj + 0x10) = self->savedPos;
            Forward0205ec20(&g_sePlayer, 0, 0);
            SePlayer_PlayExtra(&g_sePlayer, 1, 0);
            self->state++;
        }
    } else if (self->state == 0xb) {
        *(Vector3i*)((char*)GameState_GetFollowCamera((char*)gs) + 0x10) = self->savedPos;
        int settled = 1;
        for (int i = 0; i < 5; i++) {
            if (self->members & (1 << i)) {
                char* member = (char*)gs->GetPartyMemberByIndex(i != 4 ? i : 0xce);
                if (member && *(int*)(member + 0x124)) {
                    settled = 0;
                }
            }
        }
        if (var40) {
            arg0->unknown_1d_ = 0;
            arg0->unknown1_1c_++;
        }
        return;
    } else if (arg0->unknown1_1c_ == 0xc) {
        arg0->unknown_1d_ += var0->GetTickCount();
        if (arg0->unknown_1d_ > 10) {
            arg0->unknown1_1c_++;
        }
    } else if (self->state == 0xd) {
        char* g = (char*)MessageSystem_GetInstance();
        SetField0x21c_020a2770((void*)GameState_GetFollowCamera((char*)gs), self->savedField);
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
