#include <globaldefs.h>

#if defined(jpn)
#define SCENE_NODES_021b790c 0x4ec
#define SCENE_NODE_021b790c 0x93c
#define SCENE_ID_BASE_021b790c 0x4200
#define SCENE_ID_OFFSET_021b790c 0x12
#define SCENE_EVENT_FLAG_021b790c 0xc2
#define SCENE_COMBATANT_FLAGS_021b790c 0x180
#define SCENE_ZONE_LOCKS_021b790c 0x444
#define SCENE_ZONE_FLAG_021b790c 0x125
#define SCENE_COMBATANT_ID_021b790c 0x1a6
extern "C" char data_ov017_021d8358[];
extern "C" char data_ov017_021d8395[];
extern "C" char data_ov017_021d83c0[];
#else
#define SCENE_NODES_021b790c 0x6fc
#define SCENE_NODE_021b790c 0xb5c
#define SCENE_ID_BASE_021b790c 0x4400
#define SCENE_ID_OFFSET_021b790c 0xc2
#define SCENE_EVENT_FLAG_021b790c 0x2e2
#define SCENE_COMBATANT_FLAGS_021b790c 0x18c
#define SCENE_ZONE_LOCKS_021b790c 0x424
#define SCENE_ZONE_FLAG_021b790c 0x105
#define SCENE_COMBATANT_ID_021b790c 0x1b2
#endif
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "Filesystem/BackgroundLoader.h"
#include "World/Zone3D.h"
#include "Graphics/LightingManager.h"
#include "Resource/Brightness.h"


struct Struct_020469f8;
struct Struct_020469f8_2;
struct Struct_02038598_5;
struct Struct_02109bf4_3;
struct Struct_02109bf4_4;
struct Struct_02010604;
struct Struct_020a0810;
struct Struct_020a01ec;
struct Struct_0205859c;
struct Struct_020a27cc;
struct Struct_020a2800;
struct Struct_02070900_2;
struct Struct_02070900;
struct Struct_020707c8;

struct Struct_ov017_021b790c {
    char unknown_0_[0x8e14];
    signed char unknown_8e14_;
};

struct Struct_ov017_021b790c_2 {
    void* unknown_0_;
#if defined(jpn)
    char unknown_4_[0x868 - 0x4];
    int unknown_998_;
    char unknown_86c_[0x1789 - 0x86c];
    unsigned char unknown_195b_;
    char unknown_178a_[0x17e1 - 0x178a];
#else
    char unknown1_4_[0x998 - 0x4];
    int unknown_998_;
    char unknown_99c_[0x195b - 0x99c];
    unsigned char unknown_195b_;
    char unknown_195c_[0x19b1 - 0x195c];
#endif
    unsigned char unknown_19b1_;
    unsigned char unknown_19b2_;
};

struct Struct_ov017_021b790c_3 {
    char unknown_0_[0xfc0];
    int unknown_fc0_;
};

struct Struct_ov017_021b790c_4 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    char unknown_2_[0x1c - 0x2];
    unsigned char unknown_1c_[0x24 - 0x1c];
    unsigned short unknown_24_;
    char unknown_26_[0x28 - 0x26];
    int unknown_28_;
    char unknown_2c_[0x3e - 0x2c];
    unsigned short unknown_3e_;
    char unknown_40_[0x46 - 0x40];
    unsigned char unknown_46_;
    char unknown_47_;
    int unknown_48_;
    char unknown_4c_[0x6ac - 0x4c];
    void* unknown_6ac_;
    Struct_ov017_021b790c* unknown_6b0_;
    unsigned short unknown_6b4_;
    unsigned short unknown_6b6_;
    unsigned int unknown_6b8_;
    char unknown_6bc_[0x6c6 - 0x6bc];
    unsigned char unknown_6c6_;
    unsigned char unknown_6c7_;
    unsigned short unknown_6c8_;
};

struct Struct_ov017_021b790c_5 {
    char unknown_0_[0x68];
    char unknown_68_[0xb0 - 0x68];
};

struct Struct_ov017_021b790c_6 {
    char unknown_0_[0xf78];
    unsigned char unknown_f78_[4];
    unsigned char unknown_f7c_;
};

struct Struct_ov017_021b790c_7 {
    char unknown_0_[0xc];
    unsigned char unknown_c_0_ : 5;
    unsigned char unknown_c_5_ : 2;
    unsigned char unknown_c_7_ : 1;
};

struct Struct_02064a08 {
    char unknown_0_[0x18];
    int unknown_18_;
    char unknown_1c_[0x34 - 0x1c];
};

struct Struct_ov017_021b790c_8 {
    char unknown_0_[0xc];
};

struct Struct_01ff87a4_2 {
#if defined(jpn)
    char unknown_0_[0x97];
#else
    char unknown1_0_[0x9b];
#endif
    unsigned char unknown_9b_;
    void inline_ov017_021b790c(unsigned char arg0) { unknown_9b_ = arg0; }
};

static inline Struct_01ff87a4_2* inline_ov017_021b790c_2(GameResources* arg0) {
    return (Struct_01ff87a4_2*)arg0->unknown_ptr_array_371c[6];
}

extern char g_bgmPlayer[];

extern "C" Search021b790c* func_0202ae18(void);
Controller021b790c* MessageSystem_GetInstance(void);
unsigned int* GlobalFlags_GetInstance(void);
void PushInputLogA_020a1df8(int id);
void ResetInputLogB_020a1edc();
extern "C" void func_ov017_021b71d8(BattleScene021b790c* self);
extern "C" void func_ov017_021b7284(BattleScene021b790c* self);
int GetState0209ca68(char* p);
extern "C" void func_ov017_021b621c(void* node, void* allocator, void* obj);
void PrependNodeToHead(HeadList020469f8* list, HeadNode020469f8* node);
extern "C" void func_ov000_02160620(void* p);
int IsCombatWorkFlag0x400Set_ov000_02161264(void* p);
GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState* gs, int id);
void ApplyFlag0x80ToBit0x1ClearFlag0x100_02054248(void* obj);
unsigned char GetField0x5729Value_02010750(char* gs);
void SetField0x5729Value_0201075c(char* gs, unsigned char value);
int TestBitAt0x34_020a35e0(unsigned char* obj, unsigned char index);
extern "C" void func_ov017_021aa4cc(void* res, int flag);
int LoadBattleBlock020ac4c0(void* dst);
void AddClamped24BitFieldAt0x40_020a0810(S_a0810* s, unsigned int v);
void AddClamped16BitFieldAt0x18_020a01ec(S_a01ec* s, unsigned int v);
int CopyInBattleField0x7540_020ac494(void* src);
extern "C" unsigned char* Zone3D_GetInstance(void);
void SetOrClearBit_0201bf98(unsigned char* obj, int bit, int set);
extern "C" int func_ov000_0215e9fc(void* battle, short* buf, int max, int start);
extern "C" int func_ov017_021959b4(void);
extern "C" void* Scenario_GetInstance(void);
int ClearField0x498Dispatch10_02064a24(void*, Desc021b790c*);
int ClearField0x498Dispatch0F_02064a08(void*, Desc021b790c*);
extern "C" void EventQuery_RunQueuedCommands(void* p);
int IsField0xcNonNegative_020a3694(int* obj);
void ResetMpForFlaggedCombatants02010604(GameState* gs, int a, int b, int c);
extern "C" void func_0209c530(void* p);
int ListContainsId(ListHead02046b60* list, int id);
void InitActorContext0209c20c(Actor0209c20c* actor);
void BgmPlayer_FadeOut(Actor0209c678* actor, int arg);
extern "C" int func_0202c540(void* p);
extern "C" void func_02048150(GameObject* m, int a, int b);
int SetByte0xbeShiftPrev(Bytes02033b88* p, int val);
int GameState_GetProtagonistIndex(GameState* gs);
extern "C" void func_ov017_021cedf4(int id, int a, int b);
extern "C" void func_ov017_021c9e00(int id, int a, int b, int c);
extern "C" void func_ov017_02191108(void* self, int a, int b, int c, int d);
void GameObject_EnableControl(void* obj);
extern "C" void func_02015438(void* zone);
extern "C" MainBlock0205859c* func_02057924(void);
void ResetBattleEncounterState0205859c(MainBlock0205859c* p);
int GetFieldIfFlag4_020100f8(char* gs);
void SetVec3ComponentsAndApply020a27cc(Struct020a27cc* s);
void ConfigureVec3AndApply020a2800(Struct020A2800* s);
void InitVec3ParamsVariant8b33_020a2830(void* s);
void SetMainBrightness(GameResources* res, int level, int b);
void SetFieldForMatchingCombatant_021c98f4(int target, int flag);
extern "C" void func_ov017_021b6f9c(BattleScene021b790c* self);
void* TextQueue_GetInstance(void);
extern "C" void func_02046380(void* obj);
extern "C" void __clear(void* buf, int n);
void InitObjFromCombatant020e4c74(void* out, GameObject* obj);
int StandardStrings_Get(int value);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern "C" void MessageSystem_FormatText(void* ctrl, int a, char* fmt, char* dst, int b, int c, int d);
extern "C" int abs(int x);
extern "C" void* func_020704fc(void);
extern "C" void func_02070900(Struct_02070900_2* arg0, Struct_02070900* arg1, unsigned int arg2);
extern "C" void func_020707c8(Struct_020707c8* arg0);
#if defined(jpn)
extern "C" void func_0204500c(void* arg0, char* arg1, int arg2);
#else
extern "C" void func_0204500c(void* arg0, char* arg1, int arg2, int arg3);
#endif
extern "C" void func_02042b3c(void* arg0);
#if defined(jpn)
extern "C" void TextQueue_Push(void* receiver, char* input, int style, int flag, int a);
#else
extern "C" void TextQueue_Push(void* receiver, char* input, int style, int flag, int a, int b);
#endif
void FlagWord_SetBits(unsigned int* obj, unsigned int mask);
void EnqueueEventTag128_021cbf18(unsigned char a, unsigned short b);
extern "C" void func_ov017_021b86f8(BattleScene021b790c* self, int id, int showMessage, int arg3);
extern "C" int func_ov017_02195658(void* res);
void ClearBitAt0x34_020a367c(unsigned char* obj, int index);
void SetIntField0x264_02039758(void* obj, int v);
void MessageSystem_Reset(char* obj);
extern "C" void MessageSystem_Stop(void* obj);
int GameState_GetLeaderIndex(GameState* gs);
void NameText_InitFromPartyMember(void* obj, int combatantId);
int GetSignedByte0x1ca_02039888(void* obj);

// Overlay 17, originally func_ov017_021b790c (USA/EUR 0x021b790c, JPN 0x021b7ebc)
extern "C" ARM void FieldTask_Battle(BattleScene021b790c* self, ListHead02046b60* list) {
    GameState* gs = GameState::GetInstance();
    char* res = (char*)GetGameResources();
    GameObject* obj = gs->GetUnknownGameObject();
    Controller021b790c* ctrl = MessageSystem_GetInstance();
    Search021b790c* search = func_0202ae18();
    unsigned int* flagWord = GlobalFlags_GetInstance();

    if (!(arg0->unknown_6b6_ & 0x100)) {
        func_020a1df8(0);
        func_020a1edc();
        arg0->unknown_6b6_ |= 0x800;
        func_ov017_021b71d8(arg0);
        func_ov017_021b7284(arg0);
    }

    unsigned short state = self->state;
    if (state == 6) {
        if (GetState0209ca68(g_bgmPlayer) != 2) {
            HeadList020469f8* nodes = *(HeadList020469f8**)(res + 0x3000 + SCENE_NODES_021b790c);
            HeadNode020469f8* node = *(HeadNode020469f8**)(res + 0x3000 + SCENE_NODE_021b790c);
            func_ov017_021b621c(node, 0, 0);
            *(unsigned short*)((char*)node + 0xfe) = self->field_28;
            PrependNodeToHead(nodes, node);
        }
        self->state = 0;
    } else if (state == 0) {
        func_ov000_02160620(self->field_6ac);
        if (IsCombatWorkFlag0x400Set_ov000_02161264(self->field_6ac) == 0) return;
        void* search2 = func_0202ae18();
        self->flags |= 0x1000;
        *(unsigned short*)(res + SCENE_ID_BASE_021b790c + SCENE_ID_OFFSET_021b790c) = self->id;
        Party021b790c* party = (Party021b790c*)GameState_GetParty(gs);
        GameState* gs2 = GameState::GetInstance();
        int i;
        for (i = 0; i < 4; i++) {
            GameObject* c = GetCombatantWithFlag0x100_0200ff1c(gs2, i);
            if (c != NULL) {
                ApplyFlag0x80ToBit0x1ClearFlag0x100_02054248(c);
            }
        }
        if (arg0->unknown_6b0_->unknown_8e14_ == 2) {
            if (func_02010750((char*)var0) == 0) {
                func_0201075c((char*)var0, 1);
                for (var12 = 0; var12 < 4; var12++) {
                    GameObject* var14 = var0->GetPartyMemberByIndex(var12);
                    if (var14 != NULL && !(**(int**)((char*)var14 + 0x130) & 1) &&
                        func_020a35e0(arg0->unknown_1c_, var12) == 0) {
                        func_0201075c((char*)var0, 0);
                    }
                }
            }
            if (func_02010750((char*)var0) == 0) {
                func_ov017_021aa4cc(var1, 1);
            }
        }
        int var15 = 1;
        for (int var16 = 0; var16 < var10->unknown_f7c_; var16++) {
            GameObject* var17 = var0->GetPartyMemberByIndex(var10->unknown_f78_[var16]);
            if (var17 != NULL && !(**(int**)((char*)var17 + 0x130) & 1)) {
                var15 = 0;
            }
        }
        if (allOk) {
            BattleBlock021b790c block;
            LoadBattleBlock020ac4c0(&block);
            AddClamped24BitFieldAt0x40_020a0810((S_a0810*)&block, 1);
            AddClamped16BitFieldAt0x18_020a01ec((S_a01ec*)block.sub, 1);
            CopyInBattleField0x7540_020ac494(&block);
            SetOrClearBit_0201bf98(Zone3D_GetInstance(), 3, 1);
        }
        short var19[4];
        int var20 = func_ov000_0215e9fc(arg0->unknown_6b0_, var19, 4, 0);
        for (int var21 = 0; var21 < var20; var21++) {
            GameObject* var22 = var0->GetPartyMemberByIndex(var19[var21]);
            if (var22 != NULL) {
                *((unsigned char*)var22 + 0xc3) = 0x96;
            }
        }
        if (self->field_28 >= 0 && func_ov017_021959b4() == 0) {
            void* p = Scenario_GetInstance();
            Desc021b790c desc;
            memset(&desc, 0, sizeof(desc));
            desc.field_18 = self->field_28;
            if (self->context->mode == 2) {
                if (ClearField0x498Dispatch10_02064a24(p, &desc)) {
                    EventQuery_RunQueuedCommands(&desc);
                }
            } else {
                if (ClearField0x498Dispatch0F_02064a08(p, &desc)) {
                    EventQuery_RunQueuedCommands(&desc);
                }
            }
        }
        if (func_02010750((char*)var0) != 0) {
            if (func_020a3694((int*)arg0->unknown_1c_)) {
                func_02010604(var0, 1, 1, arg0->unknown_3e_);
                arg0->unknown_6b6_ |= 0x2000;
            } else {
                func_02010604(var0, 1, 1, 0);
                arg0->unknown_6b6_ |= 0x2000;
            }
        }
        func_0209c530(g_bgmPlayer);
        if (self->context->mode == 2 || ListContainsId(list, 4) != 0) {
            InitActorContext0209c20c((Actor0209c20c*)g_bgmPlayer);
        }
        if (ListContainsId(list, 4) != 0) {
            self->flags &= ~0x1000;
            GetHud((GameResources*)res)->SetActive(1);
            BgmPlayer_FadeOut((Actor0209c678*)g_bgmPlayer, 0);
            if (allOk && self->field_28 >= 0 && func_0202c540(search2) != 0) {
                GameObject* hero = gs->GetProtagonist();
                if (hero != NULL && (**(int**)((char*)hero + 0x130) & 1)) {
                    func_02048150(hero, 0, 1);
                    *(unsigned short*)(*(char**)((char*)hero + 0x130) + 4) = 1;
                    *(unsigned int*)((char*)hero + SCENE_COMBATANT_FLAGS_021b790c) &= ~1;
                    SetByte0xbeShiftPrev((Bytes02033b88*)hero, 0);
                }
                unsigned char id = GameState_GetProtagonistIndex(gs);
                func_ov017_021cedf4(id, 1, 0);
                func_ov017_021c9e00(id, 0, 0, 1);
            }
        }
        func_ov017_02191108(res, 1, 1, 1, 1);
        if (obj != NULL) {
            GameObject_EnableControl(obj);
        }
        unsigned char* zone = Zone3D_GetInstance();
        if (self->flags & 0x400) {
            BackgroundLoader* loader = BackgroundLoader::GetInstance();
            ((Zone3D*)zone)->SwitchZone_0201383c(*(unsigned short*)zone, 0);
            while (*(int*)(zone + SCENE_ZONE_LOCKS_021b790c) != 0) {
                loader->RemoveAllLocks();
                func_02015438(zone);
            }
        }
        func_0205859c(func_02057924());
        var27[SCENE_ZONE_FLAG_021b790c] &= ~1;
        int var29 = func_020100f8((char*)var0);
        switch ((*(Struct_ov017_021b790c_7**)(var27 + 8))->unknown_c_5_) {
        case 0:
            func_020a27cc((Struct_020a27cc*)var29);
            break;
        case 1:
            func_020a2800((Struct_020a2800*)var29);
            break;
        case 2:
            func_020a2830((void*)var29);
            break;
        default:
            func_020a2800((Struct_020a2800*)var29);
            break;
        }
        char* var30 = (char*)LightingManager::GetInstance();
        *(float*)(var30 + 0x94) = var0->GetDayTimer();
        *(int*)(var30 + 0x98) = var0->GetTimeOfDay();
        ((LightingManager*)var30)->RecomputeAdvancedLighting();
        ((LightingManager*)var30)->SubmitToRenderConfig();
        arg0->unknown_6b4_ = 5;
    } else if (var6 == 5) {
        if (arg0->unknown_6b6_ & 0x1000) {
            if (func_02046b60(*(Struct_02038598_5**)(var1 + 0x3000 + SCENE_NODES_021b790c), 3) == 0) {
                SetMainBrightness((GameResources*)var1, 0, 0x1e);
            }
        }
        func_ov017_021c98f4(*(unsigned short*)((char*)var0->GetUnknownGameObject() + SCENE_COMBATANT_ID_021b790c), 0);
        func_ov017_021b6f9c(arg0);
        arg0->unknown_1_ = 1;
    } else if (var6 == 2) {
        unsigned short var31 = arg0->unknown_6b8_;
        if (arg0->unknown_6b8_ < 500) {
            arg0->unknown_6b8_ += var0->GetEffectiveDeltaTime();
        }
        if (prev < 500 && self->timer >= 500) {
            GameObject* unk = gs->GetUnknownGameObject();
            void* reset = TextQueue_GetInstance();
#if defined(jpn)
            char var34[0x64];
            __clear(var34, sizeof(var34));
            if (var32 != NULL) {
                sprintf(var34, data_ov017_021d8358, *(char**)((char*)var32 + 0x134));
            }
#else
            func_02046380(ctrl);
            char text[0x64];
            char name[0x64];
            __clear(text, sizeof(text));
            __clear(name, sizeof(name));
            if (unk != NULL) {
                Obj021b790c who;
                InitObjFromCombatant020e4c74(&who, gs->GetUnknownGameObject());
                ctrl->obj = &who;
                sprintf(name, (const char*)StandardStrings_Get(0x20));
                MessageSystem_FormatText(ctrl, 0xc, name, text, 0xe3, 0, 1);
            }
#endif
            if (abs(GetBrightness((GameResources*)var1, false)) == 0x10) {
                void* var38 = func_020704fc();
                Struct_ov017_021b790c_8 var39;
                __clear(&var39, sizeof(var39));
                SetMainBrightness((GameResources*)var1, 0, 1);
                func_02070900((Struct_02070900_2*)var38, (Struct_02070900*)&var39, 0);
                func_020707c8((Struct_020707c8*)var38);
#if defined(jpn)
                func_0204500c(var3, var34, 0);
#else
                func_0204500c(var3, var35, 0, 0xe3);
#endif
                var3->unknown_998_ = 1;
                func_02042b3c(var3);
            } else {
#if defined(jpn)
                TextQueue_Push(reset, text, 0, 0, 1);
#else
                TextQueue_Push(reset, text, 0, 0, 1, 1);
#endif
            }
            if (IsField0xcNonNegative_020a3694((int*)self->info)) {
                FlagWord_SetBits(flagWord, 0x200);
            }
        }
        if (arg0->unknown_6c7_ == 0) {
            func_ov017_021cbf18(0, arg0->unknown_24_);
            arg0->unknown_6c7_ = 1;
            arg0->unknown_6c8_ = 0;
        } else if (arg0->unknown_6c7_ != 0 && var4->unknown_fc0_ == 0) {
            arg0->unknown_6c8_ += var0->GetEffectiveDeltaTime();
            if (arg0->unknown_6c8_ > 3000) {
                if (arg0->unknown_6c7_ == 1) {
                    func_ov017_021b86f8(arg0, arg0->unknown_24_, 1, 0);
                }
                if (arg0->unknown_6c7_ == 2) {
                    arg0->unknown_6c7_ = 0;
                }
            }
        }
        int var40 = func_ov017_02195658(var1);
        if (var40 >= 0) {
            func_020a367c(arg0->unknown_1c_, (unsigned char)var40);
        }
        if (*(unsigned char*)(var1 + 0x4000 + SCENE_EVENT_FLAG_021b790c) != 0) {
            func_ov017_021b86f8(arg0, arg0->unknown_24_, 0, 0);
            func_02039758(var2, 0);
            func_ov017_021b6f9c(arg0);
            arg0->unknown_1_ = 1;
        }
    } else if (state == 3) {
        if (ctrl->ready == 0) return;
        GameObject_EnableControl(obj);
        SetIntField0x264_02039758(obj, 0);
        func_ov017_021b6f9c(self);
        self->done = 1;
    } else if (state == 1) {
        if (*(unsigned char*)(res + 0x4000 + SCENE_EVENT_FLAG_021b790c) != 0) {
            func_ov017_021b6f9c(self);
            self->done = 1;
        }
        int var41 = func_ov017_02195658(var1);
        if (var41 >= 0) {
            func_020a367c(arg0->unknown_1c_, (unsigned char)var41);
        }
    } else if (state == 4) {
        if (self->field_6c6 != 0) {
            Controller021b790c* c = MessageSystem_GetInstance();
            MessageSystem_Reset((char*)c);
            MessageSystem_Stop(c);
            unsigned char member;
            unsigned char useLeader;
            useLeader = self->field_48;
            member = self->member;
#if defined(jpn)
            char text[0x64];
            __clear(text, sizeof(text));
            if (useLeader != 0) {
                GameObject* m = GetCombatantWithFlag0x100_0200ff1c(gs, GameState_GetLeaderIndex(gs));
                if (m != NULL) {
                    sprintf(text, data_ov017_021d8395, *(char**)((char*)m + 0x134));
                }
            } else {
                GameObject* var47 = var0->GetPartyMemberByIndex(var43);
                if (var47 != NULL) {
                    GameObject* var48 = var0->GetPartyMemberByIndex(func_02039888(var47));
                    if (var48 != NULL) {
                        sprintf(var45, data_ov017_021d83c0, *(char**)((char*)var48 + 0x134));
                    }
                }
            }
            func_0204500c(var42, var45, 0);
#else
            char text[0x100];
            Obj021b790c who;
            __clear(text, sizeof(text));
            if (useLeader != 0) {
                if (GetCombatantWithFlag0x100_0200ff1c(gs, GameState_GetLeaderIndex(gs)) != NULL) {
                    NameText_InitFromPartyMember(&who, GameState_GetLeaderIndex(gs));
                    c->obj = &who;
                    sprintf(text, (const char*)StandardStrings_Get(0x21));
                }
            } else {
                GameObject* m = gs->GetPartyMemberByIndex(member);
                if (m != NULL) {
                    GameObject* m2 = gs->GetPartyMemberByIndex(GetSignedByte0x1ca_02039888(m));
                    if (m2 != NULL) {
                        NameText_InitFromPartyMember(&who, m2->obj3D_.actorIndex_);
                        c->obj = &who;
                        sprintf(text, (const char*)StandardStrings_Get(0x22));
                    }
                }
            }
            func_0204500c(var42, var49, 0, 0xe3);
            func_02042b3c(var42);
#endif
            var42->unknown_998_ = 1;
            var42->unknown_19b2_ = 1;
            var42->unknown_19b1_ = 0;
            var42->unknown_195b_ |= 2;
            arg0->unknown_6c6_ = 0;
        }
        self->timer += gs->GetEffectiveDeltaTime();
        if (self->timer > 1000) {
            MessageSystem_Reset((char*)ctrl);
            MessageSystem_Stop(ctrl);
            self->state = 6;
        }
    }
}
