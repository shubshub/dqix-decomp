#include "GameState/GameState.h"
#include <globaldefs.h>
#include "Input/Input.h"

#if defined(jpn)
#define RG(u, j) (j)
#else
#define RG(u, j) (u)
#endif

struct Struct_0205de24_2;
struct Struct_0205c570;
struct Obj_0205da38;
struct SePlayer;
struct Container020dedd0;
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
int GetActiveScaledSum0205d794(struct Struct_0205c570 *s);
int IsActiveElementFlag2Set0205da38(struct Obj_0205da38* obj, int key);
void SePlayer_Play(struct SePlayer *o, int a, int b);
char *FindElementByKey020dedd0(struct Container020dedd0 *c, int key);
int CheckFlagOrThreshold_02161b48(char *base, int a);
void InitBattleTag02161798(char *base);
extern "C" void func_ov002_02161cf0(void *base);
extern "C" void func_ov002_02156e90(void *base);
extern "C" void func_ov002_0215a7b4(char *base, int actor, short key, int sel, int x);
extern "C" char g_sePlayer[];

// USA: func_ov002_0216bd34
extern "C" ARM void func_ov002_0216bd34(char *arg0) {
    char *var0  = (char *) GameState::GetInstance();
    int var1 = *(int *) (arg0 + 0x1000 + RG(0xbc0, 0xa88));
    if (var1 == 0) {
        *(short *) (arg0 + RG(0x1c00 + 0x14, 0x1a00 + 0xdc)) = 0;
        func_0205de24((struct Struct_0205de24_2 *) (arg0 + RG(0x2c8 + 0xc00, 0xe20)), 0, 2);
        func_ov002_02161cf0(arg0);
        func_ov002_02161798(arg0);
        *(signed char *) (arg0 + 0x1000 + RG(0xc20, 0xae8)) = *(int *) (arg0 + *(short *) (arg0 + RG(0x1b00 + 0xe6, 0x1a00 + 0xae)) * 4 + 0x1000 + RG(0xc3c, 0xb00));
        if (*(signed char *) (arg0 + RG(0x1c00 + 0x20, 0x1a00 + 0xe8)) < 0) {
            *(signed char *) (arg0 + 0x1000 + RG(0xc20, 0xae8)) = 4;
        }
        *(int *) (arg0 + 0x1000 + RG(0xbc0, 0xa88)) += 1;
    } else if (var1 == 1) {
        *(unsigned int *) (arg0 + 0x2000 + RG(0x47c, 0x2ac)) |= 4;
        *(short *) (arg0 + RG(0x1c00 + 0x14, 0x1a00 + 0xdc)) =
            func_0205d794((struct Struct_0205c570 *) (arg0 + RG(0x2c8 + 0xc00, 0xe20)));
        int var2 = *(signed char *) (arg0 + RG(0x1c00 + 0x20, 0x1a00 + 0xe8));
        int var3   = *(short *) (arg0 + RG(0x1c00 + 0x22, 0x1a00 + 0xea));
        int var4  = 0;
        int var5     = g_keyManager.TestKeysPressed(0x601);
        int var6     = func_0205da38((struct Struct_0205da38*)(arg0 + RG(0x2c8 + 0xc00, 0xe20)), 0x14);
        if ((var5 | var6) ? 1 : 0) {
            *(unsigned char *) (arg0 + RG(0xf80, 0xed8)) = *(int *) (arg0 + 0x1000 + RG(0xbb8, 0xa80));
            *(unsigned int *) (arg0 + 0x2000 + RG(0x47c, 0x2ac)) &= ~4;
            switch (*(short *) (arg0 + RG(0x1c00 + 0x14, 0x1a00 + 0xdc))) {
                case 0:
                    SePlayer_Play((struct SePlayer *) g_sePlayer, 1, 0);
                    *(unsigned char *) (base + 0x2000 + RG(0x487, 0x2b7)) = 1;
                    if (FindElementByKey020dedd0((struct Container020dedd0 *) (base + RG(0x3ec + 0x400, 0x750)),
                                                                          (short) key) == NULL)
                        break;
#if defined(jpn)
                    *(unsigned short *) (var0 + 0x6f00 + 0x9c) = var3;
#else
                    *(unsigned short *) (var0 + 0x7100 + 0xdc) = var3;
                    *(unsigned short *) (var0 + 0x7f00 + 0x58) = var3;
#endif
                    if (var3 <= 0) break;
                    *(short *) (var0 + RG(0x7100 + 0xde, 0x6f00 + 0x9e)) = var2;
                    if (var2 < 0) break;
                    *(short *) (var0 + RG(0x7100 + 0xe0, 0x6f00 + 0xa0)) = *(short *) (arg0 + RG(0x1b00 + 0xe8, 0x1a00 + 0xb0));
                    if (*(short *) (arg0 + RG(0x1b00 + 0xe8, 0x1a00 + 0xb0)) < 0) break;
                    if (*(unsigned char *) (arg0 + 0x2000 + RG(0x486, 0x2b6)) != 0) {
                        if (var2 >= 0 && var2 <= 3) {
                            func_ov002_0215a7b4(arg0, var2, var3, *(short *) (arg0 + RG(0x1b00 + 0xe8, 0x1a00 + 0xb0)), 0);
                        } else {
                            func_ov002_0215a7b4(arg0, 4, var3, *(short *) (arg0 + RG(0x1b00 + 0xe8, 0x1a00 + 0xb0)), 0);
                        }
                    }
                    var4 = 1;
                    break;
                case 1:
                    SePlayer_Play((struct SePlayer *) g_sePlayer, 1, 0);
                    *(short *) (base + RG(0x1c00 + 0x14, 0x1a00 + 0xdc)) = -1;
                    func_ov002_02156e90(base);
                    done = 1;
                    break;
            }
        } else if (func_ov002_02161b48(arg0, 1)) {
            *(short *) (arg0 + RG(0x1c00 + 0x14, 0x1a00 + 0xdc)) = 0;
            var4                              = 1;
            func_ov002_02156e90(arg0);
        }
        if (!var4) {
            char *var7                                 = (char *) GameState::GetInstance();
#if defined(jpn)
            *(unsigned short *) (var7 + 0x6f00 + 0x9c) = 0;
#else
            *(unsigned short *) (var7 + 0x7100 + 0xdc) = 0;
            *(unsigned short *) (var7 + 0x7f00 + 0x58) = 0;
#endif
            *(short *) (var7 + RG(0x7100 + 0xde, 0x6f00 + 0x9e))          = -1;
            *(short *) (var7 + RG(0x7100 + 0xe0, 0x6f00 + 0xa0))          = -1;
        }
    }
}
