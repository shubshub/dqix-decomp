#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "NitroSDK/Matrix.h"
#include <globaldefs.h>
#include "Resource/GameResources.h"

struct Scene {
#if defined(jpn)
    char pad0[0x28c];
    unsigned int flags;
    char unknown_290_[0x2cb - 0x290];
#else
    char pad0[0x464];
    unsigned int flags;
    char unknown_468_[0x4a3 - 0x468];
#endif
    unsigned char unknown_4a3_;
    unsigned char state;
#if defined(jpn)
    char unknown_2cd_[0x2d8 - 0x2cd];
#else
    char unknown_4a5_[0x4b0 - 0x4a5];
#endif
    int unknown_4b0_;
};

struct Struct_ov000_0215b278 {
    char pad0[9];
    unsigned char unknown_9_;
#if defined(jpn)
    char unknown_a_[0xc9 - 0xa];
#else
    char unknown1_a_[0xcd - 0xa];
#endif
    unsigned char bcd;
    unsigned char unknown_ce_;
    unsigned char unknown_cf_;
};

struct Field150 {
    char pad0[0x14];
    unsigned char b14 : 1;
};

struct Holder {
    char pad0[8];
    int f8;
};

struct Struct_01ff91ac_30;
extern "C" Holder *Zone3D_GetInstance();
extern "C" void func_020daf9c(int, int, int, int);
void SetAndLockBrightness(GameResources*, int, int);
int IsBrightnessTransitionActive(GameResources*);
extern "C" GameObject *func_0200ff1c(GameState *, int);
extern "C" int GameState_GetProtagonistIndex(GameState *);
struct Obj02033874;
extern "C" void GameObject_SnapFacing(Obj02033874*, int);
extern "C" void func_ov017_021af59c(Struct_ov000_0215b278 *);
struct HeadList020469f8;
struct HeadNode020469f8;
extern "C" void func_020469f8(HeadList020469f8*, HeadNode020469f8*);
struct Struct021b11b0;
extern "C" void func_ov017_021b11b0(Struct021b11b0*);
extern "C" int *LinkSession_GetInstance();
extern "C" int LinkSession_IsActive(int *);
extern "C" void func_ov017_021d1810(int, int, signed char);
extern "C" void *func_020936f8();
extern "C" void func_02094030(void *, int, int, int);
extern "C" unsigned int *GlobalFlags_GetInstance();
struct FlagWord020466f4;
extern "C" void FlagWord_ClearBits(FlagWord020466f4*, unsigned int);
extern "C" int GameState_GetLeaderIndex(GameState *);
struct Field150Holder02052e2c;
extern "C" Field150 * func_02052e2c(Field150Holder02052e2c*);
extern "C" void func_ov017_021bbae4(Struct_ov000_0215b278 *, int, int);
struct TailList020469b4;
struct TailNode020469b4;
extern "C" void func_020469b4(TailList020469b4*, TailNode020469b4*);
struct ListHead02046b60;
extern "C" int func_02046b60(ListHead02046b60*, int);
struct GameResources;
void SetBrightness(GameResources*, int, int);
extern "C" void func_ov017_0219bd1c(int, int, int, int);
extern "C" int *GameState_GetZoneTransition(GameState *);
extern "C" char *MessageSystem_GetInstance();
extern "C" void MessageSystem_Reset(char *);
extern "C" void MessageSystem_Stop(char *);
extern "C" unsigned char *func_02053c6c(unsigned char *);
extern "C" void func_02086380(unsigned char *);
struct S021b6b8c;
extern "C" void func_ov017_021b6b8c(S021b6b8c*);
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

    if (state == 0) {
        if (!(self->flags & 0x40) || self->unknown_4b0_ != 0) {
            func_020daf9c(1, 0, 1, 0);
            SetAndLockBrightness((GameResources*)res, 0x10, 0xf);
            self->state = self->state + 1;
        }
    } else if (state == 1) {
        if (IsBrightnessTransitionActive((GameResources*)res) == 0) {
            for (int i = 0; i < gp[0xf7c]; i++) {
                GameObject *c = func_0200ff1c(gs, (gp + i)[0xf78]);
                if (c != 0) {
                    c->obj3D_.MakeHidden();
                }
            }
            self->state = self->state + 1;
        }
    } else if (state == 2) {
        if (IsBrightnessTransitionActive((GameResources*)res) == 0 && loader->GetNumQueuedTasks() <= 0) {
            if (self->flags & 0x40) {
                GameObject *c = func_0200ff1c(gs, GameState_GetProtagonistIndex(gs));
                if (c != 0) {
                    Vector3i *v = &c->obj3D_.position_;
                    v->x        = 0x5800;
                    v->y        = 0x199;
                    v->z        = -0x785;
                    GameObject_SnapFacing((Obj02033874*)c, 0);
                }
                Struct_ov000_0215b278 *n = *(Struct_ov000_0215b278 **) (res + 0x3000 + RES_NODE_A_021638e4);
                func_ov017_021af59c(n);
                n->unknown_9_ = 2;
                func_020469f8((HeadList020469f8*)list, (HeadNode020469f8*)n);
            } else {
                Struct_ov000_0215b278 *n = *(Struct_ov000_0215b278 **) (res + 0x3000 + RES_NODE_B_021638e4);
                func_ov017_021b11b0((Struct021b11b0*)n);
                func_020469f8((HeadList020469f8*)list, (HeadNode020469f8*)n);
            }
            self->state = self->state + 1;
        }
    } else if (state == 3) {
        if (self->flags & 0x40) {
            Vector3i saved[4];
            for (int i = 0; i < 4; i++) {
                GameObject *c = func_0200ff1c(gs, (gp + i)[0xf78]);
                if (c != 0) {
                    saved[i] = c->obj3D_.position_;
                    c->obj3D_.MakeVisible();
                }
            }
            if (LinkSession_IsActive(LinkSession_GetInstance()) != 0) {
                func_ov017_021d1810(0, -1, (signed char) GameState_GetProtagonistIndex(gs));
                func_02094030(func_020936f8(), 1, -1, 0);
            }
        } else {
            if (BackgroundLoader::GetInstance()->GetNumQueuedTasks() > 0) {
                return;
            }
            Vector3i tmp;
            __clear(&tmp, 12);
            GameObject *p = gs->GetPartyMemberByIndex(0);
            if (p != 0) {
                tmp = *(Vector3i *) ((char *) p + 0x44);
            }
            for (int i = 0; i < 4; i++) {
                GameObject *c = func_0200ff1c(gs, i);
                if (c != 0) {
                    c->obj3D_.MakeVisible();
                    c->obj3D_.position_ = tmp;
                }
            }
        }
        self->state = self->state + 1;
    } else if (state == 4) {
        if (IsBrightnessTransitionActive((GameResources*)res) == 0) {
            FlagWord_ClearBits((FlagWord020466f4*)GlobalFlags_GetInstance(), 0x80000);
            Holder *h   = Zone3D_GetInstance();
            Struct_ov000_0215b278 *n     = *(Struct_ov000_0215b278 **) (res + 0x3000 + RES_NODE_C_021638e4);
            Field150 *f = func_02052e2c((Field150Holder02052e2c*)(gs->GetGameObjectByIndex(GameState_GetLeaderIndex(gs))));
            func_ov017_021bbae4(n, h->f8, 2);
            n->bcd = GameState_GetLeaderIndex(gs);
            n->unknown_ce_ = f->b14;
            if (self->flags & 0x40) {
                self->flags &= ~0x40;
                if (LinkSession_IsActive(LinkSession_GetInstance()) != 0) {
                    n->unknown_cf_ = 2;
                    func_020469b4((TailList020469b4*)list, (TailNode020469b4*)n);
                }
                if (func_02046b60((ListHead02046b60*)list, 3) == 0) {
                    SetBrightness((GameResources*)res, 0, 8);
                }
            } else {
                n->unknown_cf_ = 3;
                func_020469f8((HeadList020469f8*)list, (HeadNode020469f8*)n);
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
            self->unknown_4a3_  = 0x10;
            self->state = 0;
            for (signed char i = 0; i < 4; i++) {
                GameObject *m = gs->GetPartyMemberByIndex(i);
                if (m != 0) {
                    unsigned char *fld = func_02053c6c((unsigned char *) m);
                    if (fld != 0) {
                        func_02086380(fld);
                    }
                }
            }
            func_ov017_021b6b8c((S021b6b8c*)(*(void **) (res + 0x3000 + RES_STATE_021638e4)));
        }
    }
}
