#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include <globaldefs.h>
#include "Combat/EntryGetterTypes.h"
#include "Resource/GameResources.h"

#if defined(jpn)
enum { Enum_ov003_0215d4fc_0 = 0x18, Enum_ov003_0215d4fc_0_2 = -0x130, Enum_ov003_0215d4fc_1808 = 0x500 };
#else
enum { Enum_ov003_0215d4fc_0 = 0, Enum_ov003_0215d4fc_0_2 = 0, Enum_ov003_0215d4fc_1808 = 0x710 };
#endif

struct Struct_ov003_02154af4_3 {
    char unknown_0_[0x64];
    char unknown_64_[0x98 - 0x64 + Enum_ov003_0215d4fc_0];
    char unknown_98_[0x3b8 - 0x98];
    unsigned char unknown_3b8_;
    char unknown_3b9_[2];
    unsigned char unknown_3bb_;
    unsigned char unknown_3bc_;
    char unknown_3bd_[0x3c4 - 0x3bd];
    unsigned char unknown_3c4_[4];
    char unknown_3c8_[4];
    unsigned int unknown_3cc_;
    char unknown_3d0_[0x3d8 - 0x3d0];
    float unknown_3d8_;
    char unknown_3dc_[4];
    float unknown_3e0_;
    char unknown_3e4_[4];
    int unknown_3e8_;
    unsigned char unknown_3ec_;
    unsigned char unknown_3ed_;
    char unknown_3ee_[2];
    unsigned char unknown_3f0_;
    unsigned char unknown_3f1_;
    char unknown_3f2_;
    unsigned char unknown_3f3_;
    unsigned char unknown_3f4_;
    unsigned char unknown_3f5_;
    char unknown_3f6_[2];
    int unknown_3f8_;
};

struct Struct_ov003_0215d150_2 {
    char unknown_0_[0x998 + Enum_ov003_0215d4fc_0_2];
    int unknown_998_;
};

struct Struct_ov003_0215d4fc {
    char unknown_0_[0x12c];
    int unknown_12c_;
};

extern int g_bgmPlayer;
extern int g_sePlayer;

extern "C" int *LinkSession_GetInstance();
Ctl *MessageSystem_GetInstance();
void *GetGlobalPtr021075f4_0203cf4c();
unsigned char *GetData02153637_020e2ff8();
extern "C" int LinkSession_IsHostOrSolo(int *);
void MessageSystem_Reset(char*);
struct Container020e0310;
void * KeyTable_Get(Container020e0310*, int);
extern "C" void func_ov003_0215cab0(Scene *, void *);
void *FindEntryPointerByKey0203df78(void *, int);
struct Entry_0205d6a0;
void Window_ClosePane(Entry_0205d6a0*, int);
struct Actor0209c678;
void BgmPlayer_FadeOut(Actor0209c678*, int);
struct GameResources;
void SetBrightness(GameResources*, int, int);
extern "C" void func_0205e944(void *, int);
int IsBrightnessTransitionActive(GameResources*);
struct Struct_02109bf4_3;
extern "C" void func_0209c20c(Struct_02109bf4_3*);
extern "C" void func_0209c6d8(void*, int);
extern "C" void func_020e3368(unsigned char *, unsigned char);
struct Struct_0208ab34;
extern "C" int func_020e34bc(Struct_0208ab34*, int);
extern "C" char *func_0200ff94(GameState *, int);
extern "C" void func_ov017_021c9e00(int, int, int, int);
extern "C" void func_020e3428(void *, int);
struct Struct_0208ab34_2;
extern "C" void func_020e3468(Struct_0208ab34_2*, int);
extern "C" void func_ov017_021a2fa0(void *);
extern "C" void Zone3D_GetInstance();
extern "C" void func_ov017_0219bd1c(int, int, int, int);
extern "C" void func_ov017_021921fc(void *, int, int);
int IsAnimationActive0209ca2c(void *);
void StopAndReset0209c7fc(void *);
struct Obj02040b2c;
void PropagateValueToActiveSlot02040b2c(Obj02040b2c*, int);
struct Obj02046574;
void MessageSystem_SetStringArgument(Obj02046574*, int, char*);

// USA: func_ov003_0215d4fc
extern "C" ARM void func_ov003_0215d4fc(Scene *self) {
    GameState *gs    = GameState::GetInstance();
    void *res        = (void*)gs->GetResources();
    Ctl *ctl         = MessageSystem_GetInstance();
    int *a           = LinkSession_GetInstance();
    void *b          = GetGlobalPtr021075f4_0203cf4c();
    GameObject *c    = gs->GetLeader();
    unsigned char *d = GetData02153637_020e2ff8();
    unsigned char state;
    int i;
    int sb;
    sb = 0;
    if (LinkSession_IsHostOrSolo(a) != 0) {
        if (*(short *) ((char *) gs->GetLeader() + 4) == 0) {
            sb = 1;
        }
    }
    var7 = arg0->unknown_3b8_;

    if (state == 0) {
        if (self->b3f3 != 0) {
            MessageSystem_Reset((char*)ctl);
            self->state = self->state + 1;
            return;
        }
        int key = 0x3f2;
        if (self->w3cc > *(unsigned int *) ((unsigned char *)GameState_GetParty(gs) + 0xf6c)) {
            key = 0x3fc;
            if (self->b3f0 != 0) {
                if (sb != 0) {
                    key        = 0x6c;
                    self->b3f1 = 1;
                } else {
                    var10 = 0x72;
                }
            }
            func_ov003_0215cab0(self, KeyTable_Get((Container020e0310*)self->cont64, key));
            self->state = 8;
            return;
        }
        if (arg0->unknown_3f0_ != 0) {
            var10 = 0x6a;
        }
        func_ov003_0215cab0(self, KeyTable_Get((Container020e0310*)self->cont64, key));
        self->b3bb = 2;
        void *e = FindEntryPointerByKey0203df78(b, (*(Ent **) ((char *) GetGameResources() + 0x3000 + regionalRes))->key);
        if (e != 0) {
            self->w3f8 = GetOffset0x54FromFallbackChain_02040a20((Entry_203dce4*)e);
        }
        arg0->unknown_3b8_ = arg0->unknown_3b8_ + 1;
    }
    if (var7 == 1) {
        if (var2->unknown_998_ != 0) {
            return;
        }
        Window_ClosePane((Entry_0205d6a0*)self->list98, 0);
        BgmPlayer_FadeOut((Actor0209c678*)&g_bgmPlayer, 0x10);
        SetBrightness((GameResources*)res, -16, 0x3c);
        func_0205e944(&g_sePlayer, 0);
        self->b3f5  = 1;
        self->state = self->state + 1;
    }
    if (var7 == 2) {
        if (IsBrightnessTransitionActive((GameResources*)var1) != 0) {
            return;
        }
        InitActorContext0209c20c((Actor0209c20c*)&g_bgmPlayer);
        ResetAndDispatchActorContext0209c6d8(&g_bgmPlayer, 0x37);
        self->w3e8  = 0xb4;
        self->state = self->state + 1;
    }
    if (var7 == 3) {
        func_020e3368(var6, 1);
        arg0->unknown_3b8_ = arg0->unknown_3b8_ + 1;
    }
    if (state == 4) {
        int status = GetEntryStatusForKey020e34bc((Container020e34bc*)d, 1);
        if (status == 1 || self->b3f4 != 0) {
            unsigned char *p              = (unsigned char *)GameState_GetParty(gs);
            *(unsigned int *) (p + 0xf6c) = *(unsigned int *) (p + 0xf6c) - self->w3cc;
            for (i = 0; i < 4; i++) {
                if (self->ids[i] != 0xff) {
                    char *m                                          = GetCombatantChecked_0200ff94(gs, self->ids[i]);
                    *(unsigned short *) (*(char **) (m + 0x130) + 4) = *(unsigned short *) (*(char **) (m + 0x134) + 0x30);
                    *(unsigned short *) (*(char **) (m + 0x130) + 6) = *(unsigned short *) (*(char **) (m + 0x134) + 0x32);
                    func_ov017_021c9e00(self->ids[i], 0, 0, 1);
                }
            }
            if (LinkSession_IsHostOrSolo(a) != 0) {
                switch (self->b3bc) {
                    case 2: gs->SetDayTimer(self->f3d8); break;
                    case 3: gs->SetDayTimer(self->f3e0); break;
                }
            }
            func_020e3428(var6, 1);
            arg0->unknown_3b8_ = arg0->unknown_3b8_ + 1;
        } else if ((unsigned int) (var12 - 3) <= 2) {
            func_020e3468((Struct_0208ab34_2*)var6, 1);
            arg0->unknown_3b8_ = 3;
        }
    }
    if (var7 == 5) {
        if (BackgroundLoader::GetInstance()->GetNumQueuedTasks() <= 0) {
            func_ov017_021a2fa0((void *) GetGameResources());
            Zone3D_GetInstance();
            func_ov017_0219bd1c(1, 0, 0, 0);
            func_ov017_021921fc((char *) var5 + 0x44, *(short *) ((char *) var5 + 0xae), 1);
            arg0->unknown_3b8_ = arg0->unknown_3b8_ + 1;
        }
    }
    if (state == 6) {
        if (IsAnimationActive0209ca2c(&g_bgmPlayer) != 0) {
            return;
        }
        StopAndReset0209c7fc(&g_bgmPlayer);
        SetBrightness((GameResources*)res, 0, 0x3c);
        func_0205e944(&g_sePlayer, 0x7f);
        self->b3ec = 1;
        self->b3ed = 0;
        void *e = FindEntryPointerByKey0203df78(b, (*(Ent **) ((char *) GetGameResources() + 0x3000 + regionalRes))->key);
        if (e != 0) {
            PropagateValueToActiveSlot02040b2c((Obj02040b2c*)e, self->w3f8);
        }
        arg0->unknown_3b8_ = arg0->unknown_3b8_ + 1;
    } else if (arg0->unknown_3b8_ == 7) {
        if (arg0->unknown_3ec_ != 0) {
            return;
        }
        if (IsBrightnessTransitionActive((GameResources*)var1) != 0) {
            return;
        }
        arg0->unknown_3f5_ = 0;
        if (arg0->unknown_3f4_ != 0) {
            return;
        }
        if (arg0->unknown_3f3_ != 0) {
            arg0->unknown_3b8_ = arg0->unknown_3b8_ + 1;
            return;
        }
        ctl->w998 = 1;
        MessageSystem_SetStringArgument((Obj02046574*)ctl, 0, (char*)(*(void **) ((char *) gs->GetLeader() + 0x134)));
        int key = 0x3f3;
        if (self->b3f0 != 0) {
            if (sb == 0) {
                key = 0x71;
            } else if (self->b3bc == 2) {
                key = 0x6b;
            } else {
                var16 = 0x6d;
            }
        }
        func_ov003_0215cab0(self, KeyTable_Get((Container020e0310*)self->cont64, key));
        self->state = self->state + 1;
    }
    if (arg0->unknown_3b8_ == 8 && var2->unknown_998_ == 0) {
        arg0->unknown_3bc_  = 5;
        arg0->unknown_3b8_ = 0;
    }
}
