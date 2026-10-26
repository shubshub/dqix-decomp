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


struct HeadList020469f8;
struct HeadNode020469f8;
struct ListHead02046b60;
struct Actor0209c20c;
struct Actor0209c678;
struct Bytes02033b88;
struct Struct_020a0810;
struct Struct_020a01ec;
struct Struct_0205859c;
struct Struct_020a27cc;
struct Struct_020a2800;
struct Struct_02070900_2;
struct Struct_02070900;
struct Struct_020707c8;

struct Struct_ov017_021b790c {
    char pad0[0x8e14];
    signed char mode;
};

struct Controller021b790c {
    void* obj;
#if defined(jpn)
    char pad4[0x868 - 0x4];
    int unknown_998_;
    char unknown_86c_[0x1789 - 0x86c];
    unsigned char unknown_195b_;
    char unknown_178a_[0x17e1 - 0x178a];
#else
    char pad4[0x998 - 0x4];
    int unknown_998_;
    char unknown_99c_[0x195b - 0x99c];
    unsigned char unknown_195b_;
    char unknown_195c_[0x19b1 - 0x195c];
#endif
    unsigned char unknown_19b1_;
    unsigned char unknown_19b2_;
};

struct Search021b790c {
    char pad0[0xfc0];
    int busy;
};

struct BattleScene021b790c {
    unsigned char field_0;
    unsigned char done;
    char pad2[0x1c - 0x2];
    unsigned char info[0x24 - 0x1c];
    unsigned short id;
    char unknown_26_[0x28 - 0x26];
    int field_28;
    char pad2c[0x3e - 0x2c];
    unsigned short unknown_3e_;
    char unknown_40_[0x46 - 0x40];
    unsigned char member;
    char unknown_47_;
    int unknown_48_;
    char unknown_4c_[0x6ac - 0x4c];
    void* unknown_6ac_;
    Struct_ov017_021b790c* context;
    unsigned short state;
    unsigned short flags;
    unsigned int timer;
    char unknown_6bc_[0x6c6 - 0x6bc];
    unsigned char unknown_6c6_;
    unsigned char unknown_6c7_;
    unsigned short unknown_6c8_;
};

struct Struct_ov017_021b790c_5 {
    char pad0[0x68];
    char sub[0xb0 - 0x68];
};

struct Party021b790c {
    char pad0[0xf78];
    unsigned char ids[4];
    unsigned char count;
};

struct Struct_ov017_021b790c_7 {
    char pad0[0xc];
    unsigned char lo : 5;
    unsigned char mode : 2;
    unsigned char hi : 1;
};

struct Struct_02064a08 {
    char pad0[0x18];
    int field_18;
    char unknown_1c_[0x34 - 0x1c];
};

struct Struct_ov017_021b790c_8 {
    char data[0xc];
};

struct Struct_01ff87a4_2 {
#if defined(jpn)
    char pad[0x97];
#else
    char pad[0x9b];
#endif
    unsigned char active;
    void inline_ov017_021b790c(unsigned char v) { active = v; }
};

static inline Struct_01ff87a4_2* inline_ov017_021b790c_2(GameResources* res) {
    return (Struct_01ff87a4_2*)res->unknown_ptr_array_371c[6];
}

extern char g_bgmPlayer[];

extern "C" Search021b790c* LinkSession_GetInstance(void);
extern "C" Controller021b790c* MessageSystem_GetInstance(void);
extern "C" unsigned int* GlobalFlags_GetInstance(void);
extern "C" void func_020a1df8(int id);
extern "C" void func_020a1edc();
extern "C" void func_ov017_021b71d8(BattleScene021b790c* self);
extern "C" void func_ov017_021b7284(BattleScene021b790c* self);
extern "C" int func_0209ca68(char* p);
extern "C" void func_ov017_021b621c(void* node, void* allocator, void* obj);
extern "C" void func_020469f8(HeadList020469f8* list, HeadNode020469f8* node);
extern "C" void func_ov000_02160620(void* p);
extern "C" int func_ov000_02161264(void* p);
extern "C" GameObject* func_0200ff1c(GameState* gs, int id);
extern "C" void func_02054248(void* obj);
extern "C" unsigned char func_02010750(char* gs);
extern "C" void func_0201075c(char* gs, unsigned char value);
extern "C" int func_020a35e0(unsigned char* obj, unsigned char index);
extern "C" void func_ov017_021aa4cc(void* res, int flag);
extern "C" int func_020ac4c0(void* dst);
extern "C" void func_020a0810(Struct_020a0810* s, unsigned int v);
extern "C" void func_020a01ec(Struct_020a01ec* s, unsigned int v);
extern "C" int func_020ac494(void* src);
extern "C" unsigned char* Zone3D_GetInstance(void);
extern "C" void func_0201bf98(unsigned char* obj, int bit, int set);
extern "C" int func_ov000_0215e9fc(void* battle, short* buf, int max, int start);
extern "C" int func_ov017_021959b4(void);
extern "C" void* Scenario_GetInstance(void);
extern "C" int func_02064a24(void*, Struct_02064a08*);
extern "C" int func_02064a08(void*, Struct_02064a08*);
extern "C" void EventQuery_RunQueuedCommands(void* p);
extern "C" int func_020a3694(int* obj);
extern "C" void func_02010604(GameState* gs, int a, int b, int c);
extern "C" void func_0209c530(void* p);
extern "C" int func_02046b60(ListHead02046b60* list, int id);
extern "C" void func_0209c20c(Actor0209c20c* actor);
extern "C" void BgmPlayer_FadeOut(Actor0209c678* actor, int arg);
extern "C" int LinkSession_IsGuest(void* p);
extern "C" void func_02048150(GameObject* m, int a, int b);
extern "C" int GameObject_ForceMotionState(Bytes02033b88* p, int val);
extern "C" int GameState_GetProtagonistIndex(GameState* gs);
extern "C" void func_ov017_021cedf4(int id, int a, int b);
extern "C" void func_ov017_021c9e00(int id, int a, int b, int c);
extern "C" void Party_ReformLine(void* self, int a, int b, int c, int d);
extern "C" void GameObject_EnableControl(void* obj);
extern "C" void Zone3D_Update(void* zone);
extern "C" Struct_0205859c* func_02057924(void);
extern "C" void func_0205859c(Struct_0205859c* p);
extern "C" int GameState_GetFollowCamera(char* gs);
extern "C" void func_020a27cc(Struct_020a27cc* s);
extern "C" void func_020a2800(Struct_020a2800* s);
extern "C" void func_020a2830(void* s);
void SetMainBrightness(GameResources* res, int level, int b);
extern "C" void func_ov017_021c98f4(int target, int flag);
extern "C" void func_ov017_021b6f9c(BattleScene021b790c* self);
extern "C" void* TextQueue_GetInstance(void);
extern "C" void func_02046380(void* obj);
extern "C" void __clear(void* buf, int n);
extern "C" void func_020e4c74(void* out, GameObject* obj);
extern "C" int StandardStrings_Get(int value);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern "C" void MessageSystem_FormatText(void* ctrl, int a, char* fmt, char* dst, int b, int c, int d);
extern "C" int abs(int x);
extern "C" void* func_020704fc(void);
extern "C" void func_02070900(Struct_02070900_2* p, Struct_02070900* arg1, unsigned int v);
extern "C" void func_020707c8(Struct_020707c8* t);
#if defined(jpn)
extern "C" void func_0204500c(void* obj, char* buffer, int a);
#else
extern "C" void func_0204500c(void* obj, char* buffer, int a, int b);
#endif
extern "C" void func_02042b3c(void* obj);
#if defined(jpn)
extern "C" void TextQueue_Push(void* receiver, char* input, int style, int flag, int a);
#else
extern "C" void TextQueue_Push(void* receiver, char* input, int style, int flag, int a, int b);
#endif
extern "C" void FlagWord_SetBits(unsigned int* obj, unsigned int mask);
extern "C" void func_ov017_021cbf18(unsigned char a, unsigned short b);
extern "C" void func_ov017_021b86f8(BattleScene021b790c* self, int id, int arg2, int arg3);
extern "C" int func_ov017_02195658(void* res);
extern "C" void func_020a367c(unsigned char* obj, int index);
extern "C" void func_02039758(void* obj, int v);
extern "C" void MessageSystem_Reset(char* obj);
extern "C" void MessageSystem_Stop(void* obj);
extern "C" int GameState_GetLeaderIndex(GameState* gs);
extern "C" void NameText_InitFromPartyMember(void* obj, int combatantId);
extern "C" int GameObject_GetLineLeader(void* obj);

// Overlay 17, originally func_ov017_021b790c (USA/EUR 0x021b790c, JPN 0x021b7ebc)
extern "C" ARM void FieldTask_Battle(BattleScene021b790c* self, ListHead02046b60* list) {
    GameState* gs = GameState::GetInstance();
    char* res = (char*)GetGameResources();
    GameObject* obj = gs->GetLeader();
    Controller021b790c* ctrl = MessageSystem_GetInstance();
    Search021b790c* search = LinkSession_GetInstance();
    unsigned int* flagWord = GlobalFlags_GetInstance();

    if (!(self->flags & 0x100)) {
        func_020a1df8(0);
        func_020a1edc();
        self->flags |= 0x800;
        func_ov017_021b71d8(self);
        func_ov017_021b7284(self);
    }

    unsigned short state = self->state;
    if (state == 6) {
        if (func_0209ca68(g_bgmPlayer) != 2) {
            HeadList020469f8* nodes = *(HeadList020469f8**)(res + 0x3000 + SCENE_NODES_021b790c);
            HeadNode020469f8* node = *(HeadNode020469f8**)(res + 0x3000 + SCENE_NODE_021b790c);
            func_ov017_021b621c(node, 0, 0);
            *(unsigned short*)((char*)node + 0xfe) = self->field_28;
            func_020469f8(nodes, node);
        }
        self->state = 0;
    } else if (state == 0) {
        func_ov000_02160620(self->unknown_6ac_);
        if (func_ov000_02161264(self->unknown_6ac_) == 0) return;
        void* search2 = LinkSession_GetInstance();
        self->flags |= 0x1000;
        *(unsigned short*)(res + SCENE_ID_BASE_021b790c + SCENE_ID_OFFSET_021b790c) = self->id;
        Party021b790c* party = (Party021b790c*)GameState_GetParty(gs);
        GameState* gs2 = GameState::GetInstance();
        int i;
        for (i = 0; i < 4; i++) {
            GameObject* c = func_0200ff1c(gs2, i);
            if (c != NULL) {
                func_02054248(c);
            }
        }
        if (self->context->mode == 2) {
            if (func_02010750((char*)gs) == 0) {
                func_0201075c((char*)gs, 1);
                for (i = 0; i < 4; i++) {
                    GameObject* m = gs->GetPartyMemberByIndex(i);
                    if (m != NULL && !(**(int**)((char*)m + 0x130) & 1) &&
                        func_020a35e0(self->info, i) == 0) {
                        func_0201075c((char*)gs, 0);
                    }
                }
            }
            if (func_02010750((char*)gs) == 0) {
                func_ov017_021aa4cc(res, 1);
            }
        }
        int allOk = 1;
        for (int j = 0; j < party->count; j++) {
            GameObject* m = gs->GetPartyMemberByIndex(party->ids[j]);
            if (m != NULL && !(**(int**)((char*)m + 0x130) & 1)) {
                allOk = 0;
            }
        }
        if (allOk) {
            Struct_ov017_021b790c_5 block;
            func_020ac4c0(&block);
            func_020a0810((Struct_020a0810*)&block, 1);
            func_020a01ec((Struct_020a01ec*)block.sub, 1);
            func_020ac494(&block);
            func_0201bf98(Zone3D_GetInstance(), 3, 1);
        }
        short ids[4];
        int count = func_ov000_0215e9fc(self->context, ids, 4, 0);
        for (int k = 0; k < count; k++) {
            GameObject* m = gs->GetPartyMemberByIndex(ids[k]);
            if (m != NULL) {
                *((unsigned char*)m + 0xc3) = 0x96;
            }
        }
        if (self->field_28 >= 0 && func_ov017_021959b4() == 0) {
            void* p = Scenario_GetInstance();
            Struct_02064a08 desc;
            memset(&desc, 0, sizeof(desc));
            desc.field_18 = self->field_28;
            if (self->context->mode == 2) {
                if (func_02064a24(p, &desc)) {
                    EventQuery_RunQueuedCommands(&desc);
                }
            } else {
                if (func_02064a08(p, &desc)) {
                    EventQuery_RunQueuedCommands(&desc);
                }
            }
        }
        if (func_02010750((char*)gs) != 0) {
            if (func_020a3694((int*)self->info)) {
                func_02010604(gs, 1, 1, self->unknown_3e_);
                self->flags |= 0x2000;
            } else {
                func_02010604(gs, 1, 1, 0);
                self->flags |= 0x2000;
            }
        }
        func_0209c530(g_bgmPlayer);
        if (self->context->mode == 2 || func_02046b60(list, 4) != 0) {
            func_0209c20c((Actor0209c20c*)g_bgmPlayer);
        }
        if (func_02046b60(list, 4) != 0) {
            self->flags &= ~0x1000;
            inline_ov017_021b790c_2((GameResources*)res)->inline_ov017_021b790c(1);
            BgmPlayer_FadeOut((Actor0209c678*)g_bgmPlayer, 0);
            if (allOk && self->field_28 >= 0 && LinkSession_IsGuest(search2) != 0) {
                GameObject* hero = gs->GetProtagonist();
                if (hero != NULL && (**(int**)((char*)hero + 0x130) & 1)) {
                    func_02048150(hero, 0, 1);
                    *(unsigned short*)(*(char**)((char*)hero + 0x130) + 4) = 1;
                    *(unsigned int*)((char*)hero + SCENE_COMBATANT_FLAGS_021b790c) &= ~1;
                    GameObject_ForceMotionState((Bytes02033b88*)hero, 0);
                }
                unsigned char id = GameState_GetProtagonistIndex(gs);
                func_ov017_021cedf4(id, 1, 0);
                func_ov017_021c9e00(id, 0, 0, 1);
            }
        }
        Party_ReformLine(res, 1, 1, 1, 1);
        if (obj != NULL) {
            GameObject_EnableControl(obj);
        }
        unsigned char* zone = Zone3D_GetInstance();
        if (self->flags & 0x400) {
            BackgroundLoader* loader = BackgroundLoader::GetInstance();
            ((Zone3D*)zone)->SwitchZone(*(unsigned short*)zone, 0);
            while (*(int*)(zone + SCENE_ZONE_LOCKS_021b790c) != 0) {
                loader->RemoveAllLocks();
                Zone3D_Update(zone);
            }
        }
        func_0205859c(func_02057924());
        zone[SCENE_ZONE_FLAG_021b790c] &= ~1;
        int flagObj = GameState_GetFollowCamera((char*)gs);
        switch ((*(Struct_ov017_021b790c_7**)(zone + 8))->mode) {
        case 0:
            func_020a27cc((Struct_020a27cc*)flagObj);
            break;
        case 1:
            func_020a2800((Struct_020a2800*)flagObj);
            break;
        case 2:
            func_020a2830((void*)flagObj);
            break;
        default:
            func_020a2800((Struct_020a2800*)flagObj);
            break;
        }
        char* lighting = (char*)LightingManager::GetInstance();
        *(float*)(lighting + 0x94) = gs->GetDayTimer();
        *(int*)(lighting + 0x98) = gs->GetTimeOfDay();
        ((LightingManager*)lighting)->RecomputeAdvancedLighting();
        ((LightingManager*)lighting)->SubmitToRenderConfig();
        self->state = 5;
    } else if (state == 5) {
        if (self->flags & 0x1000) {
            if (func_02046b60(*(ListHead02046b60**)(res + 0x3000 + SCENE_NODES_021b790c), 3) == 0) {
                SetMainBrightness((GameResources*)res, 0, 0x1e);
            }
        }
        func_ov017_021c98f4(*(unsigned short*)((char*)gs->GetLeader() + SCENE_COMBATANT_ID_021b790c), 0);
        func_ov017_021b6f9c(self);
        self->done = 1;
    } else if (state == 2) {
        unsigned short prev = self->timer;
        if (self->timer < 500) {
            self->timer += gs->GetEffectiveDeltaTime();
        }
        if (prev < 500 && self->timer >= 500) {
            GameObject* unk = gs->GetLeader();
            void* reset = TextQueue_GetInstance();
#if defined(jpn)
            char text[0x64];
            __clear(text, sizeof(text));
            if (unk != NULL) {
                sprintf(text, data_ov017_021d8358, *(char**)((char*)unk + 0x134));
            }
#else
            func_02046380(ctrl);
            char text[0x64];
            char name[0x64];
            __clear(text, sizeof(text));
            __clear(name, sizeof(name));
            if (unk != NULL) {
                Struct_ov017_021b790c_8 who;
                func_020e4c74(&who, gs->GetLeader());
                ctrl->obj = &who;
                sprintf(name, (const char*)StandardStrings_Get(0x20));
                MessageSystem_FormatText(ctrl, 0xc, name, text, 0xe3, 0, 1);
            }
#endif
            if (abs(GetBrightness((GameResources*)res, false)) == 0x10) {
                void* effect = func_020704fc();
                Struct_ov017_021b790c_8 var39;
                __clear(&var39, sizeof(var39));
                SetMainBrightness((GameResources*)res, 0, 1);
                func_02070900((Struct_02070900_2*)effect, (Struct_02070900*)&var39, 0);
                func_020707c8((Struct_020707c8*)effect);
#if defined(jpn)
                func_0204500c(ctrl, text, 0);
#else
                func_0204500c(ctrl, text, 0, 0xe3);
#endif
                ctrl->unknown_998_ = 1;
                func_02042b3c(ctrl);
            } else {
#if defined(jpn)
                TextQueue_Push(reset, text, 0, 0, 1);
#else
                TextQueue_Push(reset, text, 0, 0, 1, 1);
#endif
            }
            if (func_020a3694((int*)self->info)) {
                FlagWord_SetBits(flagWord, 0x200);
            }
        }
        if (self->unknown_6c7_ == 0) {
            func_ov017_021cbf18(0, self->id);
            self->unknown_6c7_ = 1;
            self->unknown_6c8_ = 0;
        } else if (self->unknown_6c7_ != 0 && search->busy == 0) {
            self->unknown_6c8_ += gs->GetEffectiveDeltaTime();
            if (self->unknown_6c8_ > 3000) {
                if (self->unknown_6c7_ == 1) {
                    func_ov017_021b86f8(self, self->id, 1, 0);
                }
                if (self->unknown_6c7_ == 2) {
                    self->unknown_6c7_ = 0;
                }
            }
        }
        int idx = func_ov017_02195658(res);
        if (idx >= 0) {
            func_020a367c(self->info, (unsigned char)idx);
        }
        if (*(unsigned char*)(res + 0x4000 + SCENE_EVENT_FLAG_021b790c) != 0) {
            func_ov017_021b86f8(self, self->id, 0, 0);
            func_02039758(obj, 0);
            func_ov017_021b6f9c(self);
            self->done = 1;
        }
    } else if (state == 3) {
        if (ctrl->unknown_998_ == 0) return;
        GameObject_EnableControl(obj);
        func_02039758(obj, 0);
        func_ov017_021b6f9c(self);
        self->done = 1;
    } else if (state == 1) {
        if (*(unsigned char*)(res + 0x4000 + SCENE_EVENT_FLAG_021b790c) != 0) {
            func_ov017_021b6f9c(self);
            self->done = 1;
        }
        int idx = func_ov017_02195658(res);
        if (idx >= 0) {
            func_020a367c(self->info, (unsigned char)idx);
        }
    } else if (state == 4) {
        if (self->unknown_6c6_ != 0) {
            Controller021b790c* c = MessageSystem_GetInstance();
            MessageSystem_Reset((char*)c);
            MessageSystem_Stop(c);
            unsigned char member;
            unsigned char var44;
            var44 = self->unknown_48_;
            member = self->member;
#if defined(jpn)
            char text[0x64];
            __clear(text, sizeof(text));
            if (var44 != 0) {
                GameObject* m = func_0200ff1c(gs, GameState_GetLeaderIndex(gs));
                if (m != NULL) {
                    sprintf(text, data_ov017_021d8395, *(char**)((char*)m + 0x134));
                }
            } else {
                GameObject* m = gs->GetPartyMemberByIndex(member);
                if (m != NULL) {
                    GameObject* m2 = gs->GetPartyMemberByIndex(GameObject_GetLineLeader(m));
                    if (m2 != NULL) {
                        sprintf(text, data_ov017_021d83c0, *(char**)((char*)m2 + 0x134));
                    }
                }
            }
            func_0204500c(c, text, 0);
#else
            char text[0x100];
            Struct_ov017_021b790c_8 who;
            __clear(text, sizeof(text));
            if (var44 != 0) {
                if (func_0200ff1c(gs, GameState_GetLeaderIndex(gs)) != NULL) {
                    NameText_InitFromPartyMember(&who, GameState_GetLeaderIndex(gs));
                    c->obj = &who;
                    sprintf(text, (const char*)StandardStrings_Get(0x21));
                }
            } else {
                GameObject* m = gs->GetPartyMemberByIndex(member);
                if (m != NULL) {
                    GameObject* m2 = gs->GetPartyMemberByIndex(GameObject_GetLineLeader(m));
                    if (m2 != NULL) {
                        NameText_InitFromPartyMember(&who, m2->obj3D_.actorIndex_);
                        c->obj = &who;
                        sprintf(text, (const char*)StandardStrings_Get(0x22));
                    }
                }
            }
            func_0204500c(c, text, 0, 0xe3);
            func_02042b3c(c);
#endif
            c->unknown_998_ = 1;
            c->unknown_19b2_ = 1;
            c->unknown_19b1_ = 0;
            c->unknown_195b_ |= 2;
            self->unknown_6c6_ = 0;
        }
        self->timer += gs->GetEffectiveDeltaTime();
        if (self->timer > 1000) {
            MessageSystem_Reset((char*)ctrl);
            MessageSystem_Stop(ctrl);
            self->state = 6;
        }
    }
}
