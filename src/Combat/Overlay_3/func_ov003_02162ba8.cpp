#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/CombatantRecovery.h"

struct StatusOwner02081198;
struct StatusOwner02081164;
struct Obj0208203c;
struct SePlayer;
struct Cont0207fe44;

struct Sub64 {
#if defined(jpn)
    unsigned char pad[0x228];
#else
    unsigned char pad[0x400];
#endif
    unsigned int f400;
};
struct SelfT {
    unsigned char pad[0x64];
    Sub64 cont;
};
struct Obj150 {
    unsigned char pad[0x56b];
    unsigned char lo : 4;
    unsigned char hi : 4;
};

static inline void SetF400(Sub64 *p) {
    p->f400 |= 0x800000;
}

void SetEntryNibbleByShortId(StatusOwner02081198 *, int, int);
void SetEntryFlag0x2ByShortId(StatusOwner02081164 *, int, int);
extern "C" void func_020813ec(void *, int);
int FindMappedMemberId02080468(void *, int);
void ResetWithSub0208203c(Obj0208203c *);
extern "C" void func_ov003_02165888(unsigned char *, int);
extern "C" void func_ov003_02160794(unsigned char *);
extern "C" int func_ov003_02160854(unsigned char *);
void SePlayer_Play(SePlayer *, int, int);
int CountFlaggedCombatants_02161544(void *);
void CallFunc0204c804OverAllElems(Cont0207fe44 *);
extern "C" int func_ov003_02160a68(unsigned char *);
unsigned char *GetFieldAt0x150_02053c6c(unsigned char *);
extern "C" void func_ov003_02161480(unsigned char *);
extern "C" void func_ov003_02166f40(unsigned char *);

extern int g_sePlayer;

#if defined(jpn)
#define RO(o) ((o) >= 0x464 ? (o) - 0x1d8 : (o) - 0x118)
#define RO_36 0x2a
#else
#define RO(o) (o)
#define RO_36 0x36
#endif

// USA: func_ov003_02162ba8
extern "C" ARM void func_ov003_02162ba8(unsigned char *self) {
    GameState *gs       = GameState::GetInstance();
    unsigned char state = self[RO(0x4a4)];
    void *r4            = *(void **) (self + RO(0x324));
    short *sp           = (short *) (self + RO(0x84 + 0x400));

    if (state == 0) {
        *(short *) (self + RO(0x482)) = -1;
        *(short *) (self + RO(0x488)) = 0x13;
        SetEntryNibbleByShortId((StatusOwner02081198 *) r4, 0x12, 1);
        SetEntryFlag0x2ByShortId((StatusOwner02081164 *) r4, 0x12, 1);
        func_020813ec(r4, 0x12);
        *(short *) (self + RO(0x48e))                = FindMappedMemberId02080468(r4, *(short *) (self + RO(0x488)));
        *(short *) (self + RO(0x474))                = *(short *) (self + RO(0x48e));
        *(short *) ((unsigned char *) r4 + RO_36) = *(short *) (self + RO(0x48e));
        ResetWithSub0208203c((Obj0208203c *) (self + RO(0x308)));
        *(int *) (self + RO(0x470)) = 0;
        func_ov003_02165888(self, 1);
        *(unsigned int *) (self + RO(0x464)) |= 0x580000;
        if (*(unsigned int *) (self + RO(0x464)) & 1) {
            ((SelfT *) self)->cont.f400 |= 0x800000;
        }
        self[RO(0x4a4)]++;
    } else if (state == 1) {
        func_ov003_02160794(self);
        *(short **) (self + RO(0x470)) = (short *) (self + RO(0x8e + 0x400));
        if (*(unsigned int *) (self + RO(0x464)) & 0x1000000) {
            *(unsigned int *) (self + RO(0x464)) |= 0x580000;
            if (*(unsigned int *) (self + RO(0x464)) & 1) {
                ((SelfT *) self)->cont.f400 |= 0x800000;
            }
            func_ov003_02165888(self, 1);
        }
        if (func_ov003_02160854(self) != 0) {
            short idx = *(short *) (self + RO(0x48e)) - FindMappedMemberId02080468(r4, *(short *) (self + RO(0x488)));
            if (self[RO(0x4ad)] <= idx) return;
            *(short *) (self + RO(0x482)) = (self + idx)[RO(0x4a9)];
            SePlayer_Play((SePlayer *) &g_sePlayer, 1, 0);
            ResetWithSub0208203c((Obj0208203c *) (self + RO(0x308)));
            *(int *) (self + RO(0x470)) = 0;
            if (CountFlaggedCombatants_02161544(self) == 0) {
                CallFunc0204c804OverAllElems((Cont0207fe44 *) r4);
                *(unsigned int *) (self + RO(0x464)) |= 0x80000;
                sp[0]       = 0x49;
                sp[1]       = 2;
                self[RO(0x4a3)] = 1;
                self[RO(0x4a4)] = 0;
            } else {
                CallFunc0204c804OverAllElems((Cont0207fe44 *) r4);
                *(unsigned int *) (self + RO(0x464)) |= 0x80000;
                self[RO(0x4a4)]++;
            }
        } else {
            if (func_ov003_02160a68(self) == 0) return;
            ResetWithSub0208203c((Obj0208203c *) (self + RO(0x308)));
            *(int *) (self + RO(0x470)) = 0;
            CallFunc0204c804OverAllElems((Cont0207fe44 *) r4);
            *(unsigned int *) (self + RO(0x464)) |= 0x80000;
            sp[0]       = 2;
            self[RO(0x4a3)] = 1;
            self[RO(0x4a4)] = 0;
        }
    } else if (state == 2) {
        unsigned char saved = self[RO(0x4a3)];
        self[RO(0x4a3)]         = 0x10;
        GameObject *c       = GetCombatantWithFlag0x100_0200ff1c(gs, *(short *) (self + RO(0x482)));
        if (c == 0) return;
        unsigned char *o = GetFieldAt0x150_02053c6c((unsigned char *) c);
        self[RO(0x4a3)]      = saved;
        int f            = (*(short *) (o + 0x454) > 0);
        if (c->combatFields_.savedState_130_->flags & 1) {
            sp[0]       = 0xc;
            sp[1]       = 2;
            self[RO(0x4a3)] = 1;
            self[RO(0x4a4)] = 0;
        } else {
            int n = ((Obj150 *) o)->hi;
            if (n == 2 || n == 4) {
                sp[0] = 0x54;
                if (f != 0) sp[1] = 0xe;
                self[RO(0x4a4)] = 5;
            } else if (n == 3) {
                sp[0] = 0x55;
                if (f != 0) sp[1] = 0x1f;
                self[RO(0x4a4)] = 5;
            } else {
                sp[0]       = 0xb;
                self[RO(0x4a3)] = 8;
                self[RO(0x4a4)] = 0;
                func_ov003_02161480(self);
                *(unsigned int *) (self + RO(0x464)) |= 0x202;
            }
        }
        *(unsigned int *) (self + RO(0x464)) |= 0x10;
    } else if (state == 5) {
        func_ov003_02161480(self);
        func_ov003_02166f40(self);
        sp[0]       = 2;
        self[RO(0x4a3)] = 1;
        self[RO(0x4a4)] = 0;
    }
}
