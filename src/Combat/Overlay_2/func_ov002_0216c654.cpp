#if defined(jpn)
#define func_ov013_021846a0 func_ov013_021856dc
#endif

#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/Brightness.h"
#include <globaldefs.h>

struct Struct_020e28dc;
struct Struct_020e25e8;
struct Struct_02012de8;
struct Struct_02038598_4;

char *MessageSystem_GetInstance();
void MessageSystem_Reset(char *);
int GetInnerFlagBit0020e28dc(struct Outer020e28dc *);
void ResetSelectionState020e25e8(struct Obj020e25e8 *);
void SetSubBrightness(GameResources *, int, int);
int IsSubBrightnessTransitionActive(GameResources *);
extern "C" void func_ov023_021dca88(char *);
extern "C" void func_020dc2d0(int);
extern "C" void func_ov023_021e7340(char *);
extern "C" void func_ov023_021eb414(char *);
extern "C" void func_ov023_021eb26c(char *);
extern "C" void func_ov013_02186fa0(char *);
extern "C" void func_ov013_021846a0(char *);
void *GlobalFlags_GetInstance();
int TestFlags02046708(struct FlagWord02046708 *, unsigned int);
void FlagWord_ClearBits(struct FlagWord020466f4 *, unsigned int);
void PopStack1AndTrigger_020a1f4c(int);

#define S32(o) (*(int *) (arg0 + (o)))

#if defined(jpn)
enum { Enum_ov002_0216c654_0 = -0x138, Enum_ov002_0216c654_0_2 = -0x13c, Enum_ov002_0216c654_0_3 = -0x1d0, Enum_ov002_0216c654_0_4 = -0x1cc, Enum_ov002_0216c654_0_5 = -0x18,
       Enum_ov002_0216c654_0_6 = -0x9c, Enum_ov002_0216c654_0_7 = -0x150, Enum_ov002_0216c654_43 = 0x2e };
#else
enum { Enum_ov002_0216c654_0 = 0, Enum_ov002_0216c654_0_2 = 0, Enum_ov002_0216c654_0_3 = 0, Enum_ov002_0216c654_0_4 = 0, Enum_ov002_0216c654_0_5 = 0, Enum_ov002_0216c654_0_6 = 0,
       Enum_ov002_0216c654_0_7 = 0, Enum_ov002_0216c654_43 = 0x2b };
#endif

// USA: func_ov002_0216c654
extern "C" ARM void func_ov002_0216c654(char *self) {
    GameResources *res = GameState::GetInstance()->GetResources();
    int state          = S32(0x1bc0 + regionalState);
    if (state == 0) {
        MessageSystem_Reset(MessageSystem_GetInstance());
        if (S32(4) != 0 && GetInnerFlagBit0020e28dc((struct Outer020e28dc *) S32(4))) {
            ResetSelectionState020e25e8((struct Obj020e25e8 *) S32(4));
        }
        *(short *) (arg0 + 0x1c14 + Enum_ov002_0216c654_0) = 0;
        if ((S32(0x247c + Enum_ov002_0216c654_0_3) & 1) || *(unsigned char *) (arg0 + 0x1cc3 + Enum_ov002_0216c654_0_2) != 0 || *(unsigned char *) (arg0 + 0x2472 + Enum_ov002_0216c654_0_3) != 0) {
            SetSubBrightness(var0, -16, 0);
        }
        S32(0x1bc0 + Enum_ov002_0216c654_0) = 1;
    } else if (var1 == 1) {
        if (S32(0x247c + Enum_ov002_0216c654_0_3) & 1) {
            func_ov023_021dca88(arg0 + 0x50 + Enum_ov002_0216c654_0_5);
        }
        if (*(unsigned char *) (arg0 + 0x1cc3 + Enum_ov002_0216c654_0_2) != 0 || *(unsigned char *) (arg0 + 0x2472 + Enum_ov002_0216c654_0_3) != 0 ||
            *(unsigned char *) (arg0 + 0x2456 + Enum_ov002_0216c654_0_4) != 0)
        {
            SetSubBrightness(var0, -16, 0);
            if (*(unsigned char *) (arg0 + 0x1cc3 + Enum_ov002_0216c654_0_2) != 0) S32(0x1bc0 + Enum_ov002_0216c654_0) = 2;
            if (*(unsigned char *) (arg0 + 0x2472 + Enum_ov002_0216c654_0_3) != 0) S32(0x1bc0 + Enum_ov002_0216c654_0) = 3;
            if (*(unsigned char *) (arg0 + 0x2456 + Enum_ov002_0216c654_0_4) != 0) S32(0x1bc0 + Enum_ov002_0216c654_0) = 6;
        } else {
            S32(0x1bc0 + Enum_ov002_0216c654_0) = 7;
        }
    } else if (var1 == 2) {
        if (IsSubBrightnessTransitionActive(var0)) return;
        func_020dc2d0(0);
        func_ov023_021e7340(arg0 + 0xb4 + 0x800 + Enum_ov002_0216c654_0_6);
        *(unsigned char *) (arg0 + 0x1cc3 + Enum_ov002_0216c654_0_2) = 0;
        S32(0x1bc0 + Enum_ov002_0216c654_0)                        = 7;
    } else if (var1 == 3) {
        if (IsSubBrightnessTransitionActive(var0)) return;
        S32(0x1bc0 + Enum_ov002_0216c654_0) = 5;
        if (S32(0x2468 + Enum_ov002_0216c654_0_3) == 0) return;
        func_ov023_021eb414((char *) S32(0x2468 + Enum_ov002_0216c654_0_3));
        S32(0x1bc0 + Enum_ov002_0216c654_0) = 4;
    } else if (var1 == 4) {
        if (*(unsigned short *) (S32(0x2468 + Enum_ov002_0216c654_0_3) + 0x400 + 0x38) & 4) {
            S32(0x1bc0 + Enum_ov002_0216c654_0) = 5;
        }
    } else if (var1 == 5) {
        if (S32(0x2468 + Enum_ov002_0216c654_0_3) != 0) {
            func_ov023_021eb26c((char *) S32(0x2468 + Enum_ov002_0216c654_0_3));
            ((SafeAllocator *) (arg0 + 0x28 + 0x800 + Enum_ov002_0216c654_0_6))->Reset();
            ((SafeAllocator *) (arg0 + 0x64 + 0x800 + Enum_ov002_0216c654_0_6))->Reset();
            S32(0x2468 + Enum_ov002_0216c654_0_3) = 0;
            S32(0x246c + Enum_ov002_0216c654_0_3) = 0;
        }
        *(unsigned char *) (self + 0x2470 + regionalFlags) = 0;
        *(unsigned char *) (self + 0x2471 + regionalFlags) = 0;
        S32(0x1bc0 + regionalState)                        = 7;
    } else if (state == 6) {
        if (IsSubBrightnessTransitionActive(res)) return;
        func_ov013_02186fa0(self + 0x104 + 0x1c00 + regionalMode);
        ((SafeAllocator *) (self + 0x850 + regionalHeap))->Reset();
        func_ov013_021846a0(self + 0xd70 + 0x1000 + regionalCombat);
        S32(0x1bc0 + regionalState) = 7;
    } else if (state == 7) {
        void *flags = GlobalFlags_GetInstance();
        if (TestFlags02046708((struct FlagWord02046708 *) flags, 1) ||
            !IsSubBrightnessTransitionActive(res))
        {
            FlagWord_ClearBits((struct FlagWord020466f4 *) flags, 1);
            SetCombatModeFromCase020dc2d0(0);
        }
        if (*(unsigned char *) (arg0 + 0x1c33 + Enum_ov002_0216c654_0) != 0) {
            func_020a1f4c(1);
            *(unsigned char *) (arg0 + 0x1c33 + Enum_ov002_0216c654_0) = 0;
        }
        S32(0x1bb8 + Enum_ov002_0216c654_0) = Enum_ov002_0216c654_43;
        S32(0x1bc0 + Enum_ov002_0216c654_0) = 0;
    }
}
