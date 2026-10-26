#if defined(jpn)
#define func_ov013_021846a0 func_ov013_021856dc
#endif

#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/Brightness.h"
#include <globaldefs.h>

struct Struct_020e28dc;
struct Struct_020e25e8;
struct FlagWord02046708;
struct FlagWord020466f4;

extern "C" char *MessageSystem_GetInstance();
extern "C" void MessageSystem_Reset(char *);
extern "C" int func_020e28dc(struct Struct_020e28dc *);
extern "C" void func_020e25e8(struct Struct_020e25e8 *);
void SetSubBrightness(GameResources *, int, int);
int IsSubBrightnessTransitionActive(GameResources *);
extern "C" void func_ov023_021dca88(char *);
extern "C" void func_020dc2d0(int);
extern "C" void func_ov023_021e7340(char *);
extern "C" void func_ov023_021eb414(char *);
extern "C" void func_ov023_021eb26c(char *);
extern "C" void func_ov013_02186fa0(char *);
extern "C" void func_ov013_021846a0(char *);
extern "C" void *GlobalFlags_GetInstance();
extern "C" int FlagWord_TestBits(struct FlagWord02046708 *, unsigned int);
extern "C" void FlagWord_ClearBits(struct FlagWord020466f4 *, unsigned int);
extern "C" void func_020a1f4c(int);

#define S32(o) (*(int *) (self + (o)))

#if defined(jpn)
enum { regionalState = -0x138, Enum_ov002_0216c654_0_2 = -0x13c, Enum_ov002_0216c654_0_3 = -0x1d0, Enum_ov002_0216c654_0_4 = -0x1cc, Enum_ov002_0216c654_0_5 = -0x18,
       Enum_ov002_0216c654_0_6 = -0x9c, Enum_ov002_0216c654_0_7 = -0x150, Enum_ov002_0216c654_43 = 0x2e };
#else
enum { regionalState = 0, Enum_ov002_0216c654_0_2 = 0, Enum_ov002_0216c654_0_3 = 0, Enum_ov002_0216c654_0_4 = 0, Enum_ov002_0216c654_0_5 = 0, Enum_ov002_0216c654_0_6 = 0,
       Enum_ov002_0216c654_0_7 = 0, Enum_ov002_0216c654_43 = 0x2b };
#endif

// USA: func_ov002_0216c654
extern "C" ARM void func_ov002_0216c654(char *self) {
    GameResources *res = GameState::GetInstance()->GetResources();
    int state          = S32(0x1bc0 + regionalState);
    if (state == 0) {
        MessageSystem_Reset(MessageSystem_GetInstance());
        if (S32(4) != 0 && func_020e28dc((struct Struct_020e28dc *) S32(4))) {
            func_020e25e8((struct Struct_020e25e8 *) S32(4));
        }
        *(short *) (self + 0x1c14 + regionalState) = 0;
        if ((S32(0x247c + Enum_ov002_0216c654_0_3) & 1) || *(unsigned char *) (self + 0x1cc3 + Enum_ov002_0216c654_0_2) != 0 || *(unsigned char *) (self + 0x2472 + Enum_ov002_0216c654_0_3) != 0) {
            SetSubBrightness(res, -16, 0);
        }
        S32(0x1bc0 + regionalState) = 1;
    } else if (state == 1) {
        if (S32(0x247c + Enum_ov002_0216c654_0_3) & 1) {
            func_ov023_021dca88(self + 0x50 + Enum_ov002_0216c654_0_5);
        }
        if (*(unsigned char *) (self + 0x1cc3 + Enum_ov002_0216c654_0_2) != 0 || *(unsigned char *) (self + 0x2472 + Enum_ov002_0216c654_0_3) != 0 ||
            *(unsigned char *) (self + 0x2456 + Enum_ov002_0216c654_0_4) != 0)
        {
            SetSubBrightness(res, -16, 0);
            if (*(unsigned char *) (self + 0x1cc3 + Enum_ov002_0216c654_0_2) != 0) S32(0x1bc0 + regionalState) = 2;
            if (*(unsigned char *) (self + 0x2472 + Enum_ov002_0216c654_0_3) != 0) S32(0x1bc0 + regionalState) = 3;
            if (*(unsigned char *) (self + 0x2456 + Enum_ov002_0216c654_0_4) != 0) S32(0x1bc0 + regionalState) = 6;
        } else {
            S32(0x1bc0 + regionalState) = 7;
        }
    } else if (state == 2) {
        if (IsSubBrightnessTransitionActive(res)) return;
        func_020dc2d0(0);
        func_ov023_021e7340(self + 0xb4 + 0x800 + Enum_ov002_0216c654_0_6);
        *(unsigned char *) (self + 0x1cc3 + Enum_ov002_0216c654_0_2) = 0;
        S32(0x1bc0 + regionalState)                        = 7;
    } else if (state == 3) {
        if (IsSubBrightnessTransitionActive(res)) return;
        S32(0x1bc0 + regionalState) = 5;
        if (S32(0x2468 + Enum_ov002_0216c654_0_3) == 0) return;
        func_ov023_021eb414((char *) S32(0x2468 + Enum_ov002_0216c654_0_3));
        S32(0x1bc0 + regionalState) = 4;
    } else if (state == 4) {
        if (*(unsigned short *) (S32(0x2468 + Enum_ov002_0216c654_0_3) + 0x400 + 0x38) & 4) {
            S32(0x1bc0 + regionalState) = 5;
        }
    } else if (state == 5) {
        if (S32(0x2468 + Enum_ov002_0216c654_0_3) != 0) {
            func_ov023_021eb26c((char *) S32(0x2468 + Enum_ov002_0216c654_0_3));
            ((SafeAllocator *) (self + 0x28 + 0x800 + Enum_ov002_0216c654_0_6))->Reset();
            ((SafeAllocator *) (self + 0x64 + 0x800 + Enum_ov002_0216c654_0_6))->Reset();
            S32(0x2468 + Enum_ov002_0216c654_0_3) = 0;
            S32(0x246c + Enum_ov002_0216c654_0_3) = 0;
        }
        *(unsigned char *) (self + 0x2470 + Enum_ov002_0216c654_0_3) = 0;
        *(unsigned char *) (self + 0x2471 + Enum_ov002_0216c654_0_3) = 0;
        S32(0x1bc0 + regionalState)                        = 7;
    } else if (state == 6) {
        if (IsSubBrightnessTransitionActive(res)) return;
        func_ov013_02186fa0(self + 0x104 + 0x1c00 + Enum_ov002_0216c654_0_2);
        ((SafeAllocator *) (self + 0x850 + Enum_ov002_0216c654_0_6))->Reset();
        func_ov013_021846a0(self + 0xd70 + 0x1000 + Enum_ov002_0216c654_0_7);
        S32(0x1bc0 + regionalState) = 7;
    } else if (state == 7) {
        void *flags = GlobalFlags_GetInstance();
        if (FlagWord_TestBits((struct FlagWord02046708 *) flags, 1) ||
            !IsSubBrightnessTransitionActive(res))
        {
            FlagWord_ClearBits((struct FlagWord020466f4 *) flags, 1);
            func_020dc2d0(0);
        }
        if (*(unsigned char *) (self + 0x1c33 + regionalState) != 0) {
            func_020a1f4c(1);
            *(unsigned char *) (self + 0x1c33 + regionalState) = 0;
        }
        S32(0x1bb8 + regionalState) = Enum_ov002_0216c654_43;
        S32(0x1bc0 + regionalState) = 0;
    }
}
