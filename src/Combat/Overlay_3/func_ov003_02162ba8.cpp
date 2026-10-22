#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/CombatantRecovery.h"

struct StatusOwner02081198;
struct StatusOwner02081164;
struct Obj0208203c;
struct SePlayer;
struct Cont0207fe44;

struct Struct_ov003_02162ba8 {
#if defined(jpn)
    unsigned char unknown_0_[0x228];
#else
    unsigned char unknown1_0_[0x400];
#endif
    unsigned int unknown_400_;
};
struct Struct_ov003_02162ba8_2 {
    unsigned char unknown_0_[0x64];
    Struct_ov003_02162ba8 unknown_64_;
};
struct Struct_ov003_02162ba8_3 {
    unsigned char unknown_0_[0x56b];
    unsigned char unknown_56b_0_ : 4;
    unsigned char unknown_56b_4_ : 4;
};

static inline void inline_02000c9c_10(Struct_ov003_02162ba8 *arg0) {
    arg0->unknown_400_ |= 0x800000;
}

extern "C" void func_02081198(Struct_02081198 *, int, int);
extern "C" void func_02081164(Struct_02081164 *, int, int);
extern "C" void func_020813ec(void *, int);
extern "C" int func_02080468(void *, int);
extern "C" void func_0208203c(Struct_02081f20_2 *);
extern "C" void func_ov003_02165888(unsigned char *, int);
extern "C" void func_ov003_02160794(unsigned char *);
extern "C" int func_ov003_02160854(unsigned char *);
void SePlayer_Play(SePlayer *, int, int);
int CountFlaggedCombatants_02161544(void *);
void CallFunc0204c804OverAllElems(Cont0207fe44 *);
extern "C" int func_ov003_02160a68(unsigned char *);
extern "C" unsigned char *func_02053c6c(unsigned char *);
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
extern "C" ARM void func_ov003_02162ba8(unsigned char *arg0) {
    GameState *var0       = GameState::GetInstance();
    unsigned char var1 = arg0[RO(0x4a4)];
    void *var2            = *(void **) (arg0 + RO(0x324));
    short *var3           = (short *) (arg0 + RO(0x84 + 0x400));

    if (var1 == 0) {
        *(short *) (arg0 + RO(0x482)) = -1;
        *(short *) (arg0 + RO(0x488)) = 0x13;
        func_02081198((Struct_02081198 *) var2, 0x12, 1);
        func_02081164((Struct_02081164 *) var2, 0x12, 1);
        func_020813ec(var2, 0x12);
        *(short *) (arg0 + RO(0x48e))                = func_02080468(var2, *(short *) (arg0 + RO(0x488)));
        *(short *) (arg0 + RO(0x474))                = *(short *) (arg0 + RO(0x48e));
        *(short *) ((unsigned char *) var2 + RO_36) = *(short *) (arg0 + RO(0x48e));
        func_0208203c((Struct_02081f20_2 *) (arg0 + RO(0x308)));
        *(int *) (arg0 + RO(0x470)) = 0;
        func_ov003_02165888(arg0, 1);
        *(unsigned int *) (arg0 + RO(0x464)) |= 0x580000;
        if (*(unsigned int *) (arg0 + RO(0x464)) & 1) {
            ((Struct_ov003_02162ba8_2 *) arg0)->unknown_64_.unknown_400_ |= 0x800000;
        }
        arg0[RO(0x4a4)]++;
    } else if (var1 == 1) {
        func_ov003_02160794(arg0);
        *(short **) (arg0 + RO(0x470)) = (short *) (arg0 + RO(0x8e + 0x400));
        if (*(unsigned int *) (arg0 + RO(0x464)) & 0x1000000) {
            *(unsigned int *) (arg0 + RO(0x464)) |= 0x580000;
            if (*(unsigned int *) (arg0 + RO(0x464)) & 1) {
                ((Struct_ov003_02162ba8_2 *) arg0)->unknown_64_.unknown_400_ |= 0x800000;
            }
            func_ov003_02165888(arg0, 1);
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
                func_0207fe44((Struct_0207fe44 *) var2);
                *(unsigned int *) (arg0 + RO(0x464)) |= 0x80000;
                arg0[RO(0x4a4)]++;
            }
        } else {
            if (func_ov003_02160a68(arg0) == 0) return;
            func_0208203c((Struct_02081f20_2 *) (arg0 + RO(0x308)));
            *(int *) (arg0 + RO(0x470)) = 0;
            func_0207fe44((Struct_0207fe44 *) var2);
            *(unsigned int *) (arg0 + RO(0x464)) |= 0x80000;
            var3[0]       = 2;
            arg0[RO(0x4a3)] = 1;
            arg0[RO(0x4a4)] = 0;
        }
    } else if (var1 == 2) {
        unsigned char var5 = arg0[RO(0x4a3)];
        arg0[RO(0x4a3)]         = 0x10;
        GameObject *var6       = func_0200ff1c(var0, *(short *) (arg0 + RO(0x482)));
        if (var6 == 0) return;
        unsigned char *var7 = func_02053c6c((unsigned char *) var6);
        arg0[RO(0x4a3)]      = var5;
        int var8            = (*(short *) (var7 + 0x454) > 0);
        if (var6->unknown_ac_.unknown_84_->unknown_0_ & 1) {
            var3[0]       = 0xc;
            var3[1]       = 2;
            arg0[RO(0x4a3)] = 1;
            arg0[RO(0x4a4)] = 0;
        } else {
            int var9 = ((Struct_ov003_02162ba8_3 *) var7)->unknown_56b_4_;
            if (var9 == 2 || var9 == 4) {
                var3[0] = 0x54;
                if (var8 != 0) var3[1] = 0xe;
                arg0[RO(0x4a4)] = 5;
            } else if (var9 == 3) {
                var3[0] = 0x55;
                if (var8 != 0) var3[1] = 0x1f;
                arg0[RO(0x4a4)] = 5;
            } else {
                var3[0]       = 0xb;
                arg0[RO(0x4a3)] = 8;
                arg0[RO(0x4a4)] = 0;
                func_ov003_02161480(arg0);
                *(unsigned int *) (arg0 + RO(0x464)) |= 0x202;
            }
        }
        *(unsigned int *) (arg0 + RO(0x464)) |= 0x10;
    } else if (var1 == 5) {
        func_ov003_02161480(arg0);
        func_ov003_02166f40(arg0);
        var3[0]       = 2;
        arg0[RO(0x4a3)] = 1;
        arg0[RO(0x4a4)] = 0;
    }
}
