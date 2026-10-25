#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/Brightness.h"
#include <globaldefs.h>
#include "Input/Input.h"

#if defined(jpn)
#define RG(u, j) (j)
#else
#define RG(u, j) (u)
#endif

struct Struct_0205de24_2;
struct Struct_0205def8;
struct PMFObj021e7bc4;
void *GlobalFlags_GetInstance();
void FlagWord_SetBits(unsigned int *p, unsigned int mask);
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
void SetElementFlag0x20ByKey0205def8(struct Struct_0205def8 *s, int a, int b);
void CreateThreeAllocators_021e71b4(void *p, SafeAllocator *alloc);
void OrGlobalFlag0x40_020dc2bc();
void SetCombatModeFromCase020dc2d0(int c);
void DispatchEntryByIndex_021e7bc4(struct PMFObj021e7bc4 *o, unsigned int idx, int v);
int GameState_GetProtagonistIndex(GameState *gs);
int CheckFlagOrThreshold_02161b48(char *base, int a);
extern "C" void func_020dc7e8(int a, int b);
extern "C" void func_ov002_02161cf0(void *base);
extern "C" void func_ov002_0215e44c(void *base);
extern "C" void func_ov002_02156e90(void *base);
extern "C" short func_020dc428();
extern "C" void func_ov023_021e7220(void *arg0, int arg1);
extern "C" int func_ov023_021e76c4(void *arg0);
extern "C" void func_ov023_021e7b34(void *arg0, int arg1);
extern "C" void func_ov023_021e7340(void *arg0);
extern "C" unsigned char data_ov002_0216cc88[];

// USA: func_ov002_021650d4
extern "C" ARM void func_ov002_021650d4(char *base) {
    GameState *gs      = GameState::GetInstance();
    GameResources *res = gs->GetResources();
    if (*(unsigned char *) (base + 0x1000 + RG(0xcc3, 0xb87)) == 0) {
        int state = *(int *) (base + 0x1000 + RG(0xbc0, 0xa88));
        if (state == 0) {
            FlagWord_SetBits((unsigned int *) GlobalFlags_GetInstance(), 1);
            func_020dc7e8(1, -1);
            func_0205de24((struct Struct_0205de24_2 *) (arg0 + RG(0x2c8, 0) + RG(0xc00, 0xe20)), 0, 3);
            func_ov002_02161cf0(arg0);
            func_ov002_0215e44c(arg0);
            for (int var3 = 0; var3 < 3; var3++) {
                func_0205def8((struct Struct_0205def8 *) (arg0 + RG(0x2c8, 0) + RG(0xc00, 0xe20)), 0,
                                                                        data_ov002_0216cc88[var3]);
            }
            SetSubBrightness(var1, -16, 0xf);
            *(unsigned char *) (arg0 + 0x1000 + RG(0xcc3, 0xb87)) = 1;
            ((SafeAllocator *) (arg0 + RG(0x64, 0x3c8) + RG(0x800, 0x400)))->Reset();
            func_ov023_021e7220(arg0 + RG(0xb4, 0x18) + 0x800, 0);
            func_ov023_021e71b4(arg0 + RG(0xb4, 0x18) + 0x800, (SafeAllocator *) (arg0 + RG(0x64, 0x3c8) + RG(0x800, 0x400)));
            *(int *) (arg0 + 0x1000 + RG(0xbc0, 0xa88)) += 1;
        } else if (var2 == 6) {
            *(int *) (arg0 + 0x1000 + RG(0xbc0, 0xa88)) = var2 + 1;
        } else if (var2 == 7) {
            func_ov002_02156e90(arg0);
            func_ov002_02156e90(arg0);
            *(int *) (arg0 + 0x1000 + RG(0xbb8, 0xa80))  = RG(0xe, 0xf);
            *(short *) (arg0 + RG(0x1b00, 0x1a00) + RG(0xf6, 0xbe)) = func_020dc428();
            *(int *) (arg0 + 0x1000 + RG(0xbc0, 0xa88))  = 0;
        }
    } else {
        int st = *(int *) (base + 0x1000 + RG(0xbc0, 0xa88));
        if (st == 1) {
            if (IsSubBrightnessTransitionActive(res)) return;
            OrGlobalFlag0x40_020dc2bc();
            *(int *) (base + 0x1000 + RG(0xbc0, 0xa88)) += 1;
        } else if (st == 2) {
            if (!func_ov023_021e76c4(base + RG(0xb4, 0x18) + 0x800)) return;
            func_ov023_021e7b34(base + RG(0xb4, 0x18) + 0x800, GameState_GetProtagonistIndex(gs));
            DispatchEntryByIndex_021e7bc4((struct PMFObj021e7bc4 *) (base + RG(0xb4, 0x18) + 0x800), 0,
                                                                 GameState_GetProtagonistIndex(gs));
            *(int *) (base + 0x1000 + RG(0xbc0, 0xa88)) += 1;
        } else if (st == 3) {
            SetSubBrightness(res, 0, 0xf);
            *(int *) (base + 0x1000 + RG(0xbc0, 0xa88)) += 1;
        } else if (st == 4) {
            if (!CheckFlagOrThreshold_02161b48(base, 1) && g_touchInput.pressed_ == 0) return;
            SetSubBrightness(res, -16, 0xa);
            *(int *) (base + 0x1000 + RG(0xbc0, 0xa88)) += 1;
        } else if (st == 5) {
            if (IsSubBrightnessTransitionActive(res)) return;
            SetCombatModeFromCase020dc2d0(0);
            func_ov023_021e7340(base + RG(0xb4, 0x18) + 0x800);
            *(unsigned char *) (base + 0x1000 + RG(0xcc3, 0xb87)) = 0;
            *(int *) (base + 0x1000 + RG(0xbc0, 0xa88)) += 1;
        }
    }
}
