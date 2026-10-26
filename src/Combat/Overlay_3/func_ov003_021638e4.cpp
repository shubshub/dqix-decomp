#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "NitroSDK/Matrix.h"
#include <globaldefs.h>
#include "Resource/GameResources.h"

struct Struct_ov003_02154af4_3 {
#if defined(jpn)
    char unknown_0_[0x28c];
    unsigned int unknown_464_;
    char unknown_290_[0x2cb - 0x290];
#else
    char unknown1_0_[0x464];
    unsigned int unknown_464_;
    char unknown_468_[0x4a3 - 0x468];
#endif
    unsigned char unknown_4a3_;
    unsigned char unknown_4a4_;
#if defined(jpn)
    char unknown_2cd_[0x2d8 - 0x2cd];
#else
    char unknown_4a5_[0x4b0 - 0x4a5];
#endif
    int unknown_4b0_;
};

struct Struct_ov000_0215b278 {
    char unknown_0_[9];
    unsigned char unknown_9_;
#if defined(jpn)
    char unknown_a_[0xc9 - 0xa];
#else
    char unknown1_a_[0xcd - 0xa];
#endif
    unsigned char unknown_cd_;
    unsigned char unknown_ce_;
    unsigned char unknown_cf_;
};

struct Struct_0209a678_2 {
    char unknown_0_[0x14];
    unsigned char unknown_14_0_ : 1;
};

struct Struct_020bc1ec {
    char unknown_0_[8];
    int unknown_8_;
};

struct Res;
extern "C" Holder *Zone3D_GetInstance();
void DispatchWithGlobalContext020daf9c(int, int, int, int);
void SetAndLockBrightness(GameResources*, int, int);
int IsBrightnessTransitionActive(GameResources*);
GameObject *GetCombatantWithFlag0x100_0200ff1c(GameState *, int);
int GameState_GetProtagonistIndex(GameState *);
struct Obj02033874;
void GameObject_SnapFacing(Obj02033874*, int);
extern "C" void func_ov017_021af59c(Node *);
struct HeadList020469f8;
struct HeadNode020469f8;
void PrependNodeToHead(HeadList020469f8*, HeadNode020469f8*);
struct Struct021b11b0;
void InitState39_021b11b0(Struct021b11b0*);
extern "C" int *LinkSession_GetInstance();
int LinkSession_IsActive(int *);
void EnqueueEventTag173_021d1810(int, int, signed char);
void *GetGlobal02109030_020936f8();
extern "C" void func_02094030(void *, int, int, int);
unsigned int *GlobalFlags_GetInstance();
struct FlagWord020466f4;
void FlagWord_ClearBits(FlagWord020466f4*, unsigned int);
int GameState_GetLeaderIndex(GameState *);
struct Field150Holder02052e2c;
Field150 * GetField150Ptr0x488_02052e2c(Field150Holder02052e2c*);
extern "C" void func_ov017_021bbae4(Node *, int, int);
struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(TailList020469b4*, TailNode020469b4*);
struct ListHead02046b60;
int ListContainsId(ListHead02046b60*, int);
struct GameResources;
void SetBrightness(GameResources*, int, int);
extern "C" void func_ov017_0219bd1c(int, int, int, int);
int *GameState_GetZoneTransition(GameState *);
char *MessageSystem_GetInstance();
void MessageSystem_Reset(char *);
extern "C" void MessageSystem_Stop(char *);
unsigned char *GetFieldAt0x150_02053c6c(unsigned char *);
void ResetShortFields02086380(unsigned char *);
struct S021b6b8c;
void CallIfField24ThenSetFlag_021b6b8c(S021b6b8c*);
extern "C" void __clear(void *, int);

#if defined(jpn)
#define RES_LIST_021638e4 0x4ec
#define RES_NODE_A_021638e4 0x910
#define RES_NODE_B_021638e4 0x914
#define RES_NODE_C_021638e4 0x524
#define RES_STATE_021638e4 0x8e0
#else
#define RES_LIST_021638e4 0x6fc
#define RES_NODE_A_021638e4 0xb30
#define RES_NODE_B_021638e4 0xb34
#define RES_NODE_C_021638e4 0x734
#define RES_STATE_021638e4 0xb00
#endif

// USA: func_ov003_021638e4
extern "C" ARM void func_ov003_021638e4(Scene *self) {
    char *res;
    GameState *gs;
    unsigned char *gp;
    void *list;
    BackgroundLoader *loader;
    res    = (char *) GetGameResources();
    list   = *(void **) (res + 0x3000 + RES_LIST_021638e4);
    gs     = GameState::GetInstance();
    loader = BackgroundLoader::GetInstance();
    gp     = (unsigned char *)GameState_GetParty(gs);
    Zone3D_GetInstance();
    unsigned char state = self->state;

    if (var5 == 0) {
        if (!(arg0->unknown_464_ & 0x40) || arg0->unknown_4b0_ != 0) {
            func_020daf9c(1, 0, 1, 0);
            SetAndLockBrightness((GameResources*)var0, 0x10, 0xf);
            arg0->unknown_4a4_ = arg0->unknown_4a4_ + 1;
        }
    } else if (var5 == 1) {
        if (IsBrightnessTransitionActive((GameResources*)var0) == 0) {
            for (int var6 = 0; var6 < var2[0xf7c]; var6++) {
                GameObject *var7 = func_0200ff1c(var1, (var2 + var6)[0xf78]);
                if (var7 != 0) {
                    var7->obj3D_.MakeHidden();
                }
            }
            arg0->unknown_4a4_ = arg0->unknown_4a4_ + 1;
        }
    } else if (state == 2) {
        if (IsBrightnessTransitionActive((GameResources*)res) == 0 && loader->GetNumQueuedTasks() <= 0) {
            if (self->flags & 0x40) {
                GameObject *c = GetCombatantWithFlag0x100_0200ff1c(gs, GameState_GetProtagonistIndex(gs));
                if (c != 0) {
                    Vector3i *v = &c->obj3D_.position_;
                    v->x        = 0x5800;
                    v->y        = 0x199;
                    v->z        = -0x785;
                    GameObject_SnapFacing((Obj02033874*)c, 0);
                }
                Struct_ov000_0215b278 *var10 = *(Struct_ov000_0215b278 **) (var0 + 0x3000 + RES_NODE_A_021638e4);
                func_ov017_021af59c(var10);
                var10->unknown_9_ = 2;
                func_020469f8((Struct_020469f8*)var3, (Struct_020469f8_2*)var10);
            } else {
                Struct_ov000_0215b278 *var11 = *(Struct_ov000_0215b278 **) (var0 + 0x3000 + RES_NODE_B_021638e4);
                func_ov017_021b11b0((Struct_ov003_021638e4_2*)var11);
                func_020469f8((Struct_020469f8*)var3, (Struct_020469f8_2*)var11);
            }
            arg0->unknown_4a4_ = arg0->unknown_4a4_ + 1;
        }
    } else if (var5 == 3) {
        if (arg0->unknown_464_ & 0x40) {
            Vector3i var12[4];
            for (int var13 = 0; var13 < 4; var13++) {
                GameObject *var14 = func_0200ff1c(var1, (var2 + var13)[0xf78]);
                if (var14 != 0) {
                    var12[var13] = var14->obj3D_.position_;
                    var14->obj3D_.MakeVisible();
                }
            }
            if (LinkSession_IsActive(LinkSession_GetInstance()) != 0) {
                EnqueueEventTag173_021d1810(0, -1, (signed char) GameState_GetProtagonistIndex(gs));
                func_02094030(GetGlobal02109030_020936f8(), 1, -1, 0);
            }
        } else {
            if (BackgroundLoader::GetInstance()->GetNumQueuedTasks() > 0) {
                return;
            }
            Vector3i var15;
            __clear(&var15, 12);
            GameObject *var16 = var1->GetPartyMemberByIndex(0);
            if (var16 != 0) {
                var15 = *(Vector3i *) ((char *) var16 + 0x44);
            }
            for (int var17 = 0; var17 < 4; var17++) {
                GameObject *var18 = func_0200ff1c(var1, var17);
                if (var18 != 0) {
                    var18->obj3D_.MakeVisible();
                    var18->obj3D_.position_ = var15;
                }
            }
        }
        self->state = self->state + 1;
    } else if (state == 4) {
        if (IsBrightnessTransitionActive((GameResources*)res) == 0) {
            FlagWord_ClearBits((FlagWord020466f4*)GlobalFlags_GetInstance(), 0x80000);
            Holder *h   = Zone3D_GetInstance();
            Node *n     = *(Node **) (res + 0x3000 + RES_NODE_C_021638e4);
            Field150 *f = GetField150Ptr0x488_02052e2c((Field150Holder02052e2c*)(gs->GetGameObjectByIndex(GameState_GetLeaderIndex(gs))));
            func_ov017_021bbae4(n, h->f8, 2);
            n->bcd = GameState_GetLeaderIndex(gs);
            n->bce = f->b14;
            if (self->flags & 0x40) {
                self->flags &= ~0x40;
                if (LinkSession_IsActive(LinkSession_GetInstance()) != 0) {
                    n->bcf = 2;
                    AppendNodeToTail((TailList020469b4*)list, (TailNode020469b4*)n);
                }
                if (func_02046b60((Struct_02038598_5*)var3, 3) == 0) {
                    SetBrightness((GameResources*)var0, 0, 8);
                }
            } else {
                var20->unknown_cf_ = 3;
                func_020469f8((Struct_020469f8*)var3, (Struct_020469f8_2*)var20);
                func_ov017_0219bd1c(1, 0, 0, 1);
                int *p                         = GameState_GetZoneTransition(gs);
                p[4]                           = 0x48cc;
                p[5]                           = 0x199;
                p[6]                           = -0x733;
                *(short *) ((char *) p + 0x1c) = 0;
                *((unsigned char *) p + 0x6e)  = 0x40;
                *((unsigned char *) p + 0xa)   = 0;
            }
            char *ctl = MessageSystem_GetInstance();
            MessageSystem_Reset(ctl);
            MessageSystem_Stop(ctl);
            self->c4a3  = 0x10;
            self->state = 0;
            for (signed char i = 0; i < 4; i++) {
                GameObject *m = gs->GetPartyMemberByIndex(i);
                if (m != 0) {
                    unsigned char *fld = GetFieldAt0x150_02053c6c((unsigned char *) m);
                    if (fld != 0) {
                        ResetShortFields02086380(fld);
                    }
                }
            }
            func_ov017_021b6b8c((Struct_ov003_021638e4*)(*(void **) (var0 + 0x3000 + RES_STATE_021638e4)));
        }
    }
}
