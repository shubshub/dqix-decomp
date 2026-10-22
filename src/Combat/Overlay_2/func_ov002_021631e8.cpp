#include "GameState/GameState.h"
#include <globaldefs.h>
#include "Input/Input.h"

struct Struct_0205de24_2;
struct Struct_0205c570;
struct Obj_0205da38;
struct SePlayer;
struct Struct_0205d81c;
struct Container020dedd0;
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
int GetActiveScaledSum0205d794(struct Struct_0205c570 *s);
int IsActiveElementFlag2Set0205da38(struct Obj_0205da38* obj, int key);
void SePlayer_Play(struct SePlayer *o, int a, int b);
int CheckFlagOrThreshold_02161b48(char *base, int a);
void SetElementFieldC2_0205deb4(struct Struct_0205d81c *s, int a, int b);
unsigned char *GetFieldAt0x150_02053c6c(unsigned char *p);
void InitBattleTag0215ccc4(char *base);
int IsFlagAt130Bit0Set_0216364c(void *member);
char *FindElementByKey020dedd0(struct Container020dedd0 *c, int key);
void SetupTargetAndApplyState021575d4(char *base);
int GetInventoryItemFlagField_02157500(char *base, int, int);
int CheckAndClearEntryStatus_0215b7d0(char* base);
extern "C" void func_ov002_02161cf0(char *base);
extern "C" void func_ov002_0215b814(char *base);
extern "C" int func_ov002_0215b720(char *self, int id);
extern "C" void func_ov002_02157634(char *base);
extern "C" void func_ov002_02156e90(char *base);
extern "C" char g_sePlayer[];

#if defined(jpn)
#define RG(u, j) (j)
#else
#define RG(u, j) (u)
#endif

static inline int inline_02000c9c_7(int arg0) {
    return (arg0 >= 0 && arg0 <= 3) ? 1 : 0;
}

// USA: func_ov002_021631e8
extern "C" ARM void func_ov002_021631e8(char *arg0) {
    int var0 = *(int *) (arg0 + RG(0x1000 + 0xbc0, 0x1a88));
    if (var0 == 0) {
        *(short *) (arg0 + RG(0x1b00 + 0xea, 0x1ab2)) = 0;
        GameObject *var1                     = GameState::GetInstance()->GetProtagonist();
        if (var1 == NULL) {
            *(short *) (arg0 + RG(0x1b00 + 0xea, 0x1ab2)) = 0;
        } else {
            *(short *) (arg0 + RG(0x1b00 + 0xea, 0x1ab2)) = *(short *) (func_02053c6c((unsigned char *) var1) + RG(0x900 + 0x5c, 0x8c4));
        }
        func_0205de24((struct Struct_0205de24_2 *) (arg0 + RG(0x2c8 + 0xc00, 0xe20)), 0, 2);
        func_ov002_02161cf0(arg0);
        func_ov002_0215ccc4(arg0);
        *(int *) (arg0 + RG(0x1000 + 0xbc0, 0x1a88)) += 1;
    } else if (var0 == 1) {
        *(unsigned int *) (arg0 + RG(0x2000 + 0x47c, 0x22ac)) |= 4;
        short var2 = *(short *) (arg0 + RG(0x1b00 + 0xea, 0x1ab2));
        *(short *) (arg0 + RG(0x1b00 + 0xea, 0x1ab2)) =
            func_0205d794((struct Struct_0205c570 *) (arg0 + RG(0x2c8 + 0xc00, 0xe20)));
        if (var2 != *(short *) (arg0 + RG(0x1b00 + 0xea, 0x1ab2))) return;
        int var3 = g_keyManager.TestKeysPressed(0x601);
        int var4 = func_0205da38((struct Struct_0205da38*)(arg0 + RG(0x2c8 + 0xc00, 0xe20)), 0x14);
        if ((var3 | var4) ? 1 : 0) {
            func_ov002_0215b814(arg0);
            *(unsigned char *) (arg0 + RG(0xf80, 0xed8)) = *(int *) (arg0 + RG(0x1000 + 0xbb8, 0x1a80));
            *(unsigned int *) (arg0 + RG(0x2000 + 0x47c, 0x22ac)) &= ~4;
            GameObject *var5 = GameState::GetInstance()->GetProtagonist();
            if (var5 != NULL) {
                short var6                                                        = *(short *) (arg0 + RG(0x1b00 + 0xea, 0x1ab2));
                *(short *) (func_02053c6c((unsigned char *) var5) + RG(0x900 + 0x5c, 0x8c4)) = var6;
            }
            switch (*(short *) (arg0 + RG(0x1b00 + 0xea, 0x1ab2))) {
                case 0:
                    SePlayer_Play((struct SePlayer *) g_sePlayer, 1, 0);
                    int ok = 0;
                    int id = *(signed char *) (base + RG(0x1c00 + 0x20, 0x1ae8));
                    if (id >= 0 && id <= 3) ok = 1;
                    if (ok && IsFlagAt130Bit0Set_0216364c(
                                  GameState::GetInstance()->GetPartyMemberByIndex(*(char *) (base + RG(0x1c00 + 0x20, 0x1ae8)))))
                    {
                        *(short *) (arg0 + RG(0x1c00 + 0x28, 0x1af0)) = 0x7aa8;
                        *(short *) (arg0 + RG(0x1c00 + 0x2a, 0x1af2)) = -1;
                        *(int *) (arg0 + RG(0x1000 + 0xbb8, 0x1a80))  = RG(0x26, 0x29);
                        *(int *) (arg0 + RG(0x1000 + 0xbbc, 0x1a84))  = 5;
                        *(int *) (arg0 + RG(0x1000 + 0xbc0, 0x1a88))  = 0;
                        *(short *) (arg0 + RG(0x1b00 + 0xea, 0x1ab2)) = -1;
                        return;
                    }
                    {
                        char *var9 = func_020dedd0(
                            (struct Struct_0201099c_10 *) (arg0 + RG(0x3ec + 0x400, 0x750)), *(short *) (arg0 + RG(0x1c00 + 0x22, 0x1aea)));
                        if (var9 != NULL && func_ov002_0215b720(arg0, *(short *) (var9 + 0x14))) {
                            *(int *) (arg0 + RG(0x1000 + 0xbc0, 0x1a88)) = 2;
                            return;
                        }
                    }
                    *(short *) (arg0 + RG(0x1c00 + 0x28, 0x1af0))          = 0x232a;
                    *(short *) (arg0 + RG(0x1c00 + 0x2a, 0x1af2))          = 0x232b;
                    *(unsigned char *) (arg0 + RG(0x1000 + 0xc83, 0x1b47)) = 0;
                    *(unsigned char *) (arg0 + RG(0x1000 + 0xc85, 0x1b49)) &= ~1;
                    *(unsigned char *) (arg0 + RG(0x1000 + 0xc84, 0x1b48)) = 0;
                    func_ov002_021575d4(arg0);
                    func_ov002_02157634(arg0);
                    return;
                case 1:
                    SePlayer_Play((struct SePlayer *) g_sePlayer, 1, 0);
                    *(int *) (base + RG(0x1000 + 0xbb8, 0x1a80)) = RG(9, 0xa);
                    *(int *) (base + RG(0x1000 + 0xbc0, 0x1a88)) = 0;
                    return;
                case 2: {
                    SePlayer_Play((struct SePlayer *) g_sePlayer, 1, 0);
                    int r = GetInventoryItemFlagField_02157500(
                        base, *(short *) (base + RG(0x1b00 + 0xe8, 0x1ab0)), *(signed char *) (base + RG(0x1c00 + 0x20, 0x1ae8)));
                    if (r != 0) {
                        *(unsigned char *) (base + RG(0x1000 + 0xc32, 0x1afa)) = 0;
                        if (r == 2) *(unsigned char *) (base + RG(0x1000 + 0xc32, 0x1afa)) = 1;
                        *(int *) (base + RG(0x1000 + 0xbb8, 0x1a80))           = RG(0x26, 0x29);
                        *(int *) (base + RG(0x1000 + 0xbbc, 0x1a84))           = 5;
                        *(short *) (base + RG(0x1c00 + 0x28, 0x1af0))          = 0x2365;
                        *(short *) (base + RG(0x1c00 + 0x2a, 0x1af2))          = -1;
                        *(int *) (base + RG(0x1000 + 0xbc0, 0x1a88))           = 0;
                        *(unsigned char *) (base + RG(0x1000 + 0xc2e, 0x1af6)) = 1;
                    } else {
                        *(int *) (arg0 + RG(0x1000 + 0xbb8, 0x1a80))  = RG(0x26, 0x29);
                        *(int *) (arg0 + RG(0x1000 + 0xbbc, 0x1a84))  = 5;
                        *(short *) (arg0 + RG(0x1c00 + 0x28, 0x1af0)) = 0x2368;
                        *(short *) (arg0 + RG(0x1c00 + 0x2a, 0x1af2)) = -1;
                        *(int *) (arg0 + RG(0x1000 + 0xbc0, 0x1a88))  = 0;
                    }
                    return;
                }
                case 3:
                    *(short *) (arg0 + RG(0x1b00 + 0xea, 0x1ab2)) = -1;
                    func_ov002_02156e90(arg0);
                    return;
            }
        } else if (func_ov002_02161b48(arg0, 1)) {
            *(short *) (arg0 + RG(0x1b00 + 0xea, 0x1ab2)) = -1;
            func_ov002_02156e90(arg0);
            func_0205deb4((struct Struct_0205d81c *) (arg0 + RG(0x2c8 + 0xc00, 0xe20)), 4, 1);
        }
    } else if (var0 == 2) {
        int var11 = func_ov002_0215b7d0(arg0);
        if (var11 > 0) {
            *(short *) (arg0 + RG(0x1c00 + 0x28, 0x1af0))          = 0x232a;
            *(short *) (arg0 + RG(0x1c00 + 0x2a, 0x1af2))          = 0x232b;
            *(unsigned char *) (arg0 + RG(0x1000 + 0xc83, 0x1b47)) = 0;
            *(unsigned char *) (arg0 + RG(0x1000 + 0xc85, 0x1b49)) &= ~1;
            *(unsigned char *) (arg0 + RG(0x1000 + 0xc84, 0x1b48)) = 0;
            func_ov002_021575d4(arg0);
            func_ov002_02157634(arg0);
        } else if (var11 < 0) {
            *(short *) (arg0 + RG(0x1c00 + 0x28, 0x1af0))          = 0x7918;
            *(short *) (arg0 + RG(0x1c00 + 0x2a, 0x1af2))          = -1;
            *(short *) (arg0 + RG(0x2400 + 0x88, 0x22b8))          = 0x7919;
            *(unsigned char *) (arg0 + RG(0x2000 + 0x48a, 0x22ba)) = 1;
            *(int *) (arg0 + RG(0x1000 + 0xbb8, 0x1a80))           = RG(0x26, 0x29);
            *(int *) (arg0 + RG(0x1000 + 0xbbc, 0x1a84))           = 5;
            *(int *) (arg0 + RG(0x1000 + 0xbc0, 0x1a88))           = 0;
        }
    }
}
