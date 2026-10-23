#include "GameState/GameState.h"
#include <globaldefs.h>
#include <Resource/ResourceNodeInsertion.h>
#include "Input/Input.h"

#if defined(jpn)
#define RG(u, j) (j)
#define func_0205ec34 func_0205ff20
#else
#define RG(u, j) (u)
#endif

struct Struct_0205de24_2;
struct Struct_0205c570;
struct Obj_0205da38;
struct SePlayer;
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
int Window_GetSelectedIndex(struct Struct_0205c570 *s);
int Window_IsSelectionTouched(struct Obj_0205da38* obj, int key);
void SePlayer_Play(struct SePlayer *o, int a, int b);
int CheckFlagOrThreshold_02161b48(char *base, int a);
void InitBattleTag0215bf34(char *base);
int GetField0x3acValue_020100a8(GameState *gs);
int TestBitInByteArray_0206dfb0(int unused, unsigned char *arr, int index);
extern "C" char *func_0205ec34(void);
extern "C" void func_ov002_02161cf0(void *arg0);
extern "C" void func_ov002_0215c0f8(void *arg0);
extern "C" void func_ov002_02161a8c(int arg0);
extern "C" void func_ov017_021c05f4(int arg0, int arg1, int arg2, int arg3);
extern "C" void func_ov023_021dca88(void *arg0);
extern "C" void func_02012fe4(void);
extern "C" void func_02017c58(void);
extern "C" char g_sePlayer[];

static inline int inline_ov002_021622ec(char *arg0) {
    return (g_keyManager.TestKeysPressed(0x601) |
            Window_IsSelectionTouched((struct Obj_0205da38*)(base + RG(0x2c8, 0) + RG(0xc00, 0xe20)), 0x14)) ? 1 : 0;
}

// USA: func_ov002_021622ec
extern "C" ARM void func_ov002_021622ec(char *base) {
    int state = *(int *) (base + 0x1000 + RG(0xbc0, 0xa88));
    if (state == 0) {
        *(unsigned char *) (base + 0x1000 + RG(0xc2f, 0xaf7)) = 0;
        *(short *) (base + RG(0x1b00, 0x1a00) + RG(0xe0, 0xa8))          = 0;
        FindAndLinkMatchingEntry0205de24((struct Struct0205de24 *) (base + RG(0x2c8, 0) + RG(0xc00, 0xe20)), 0, 2);
        InitBattleTag0215bf34(base);
        func_ov002_02161cf0(base);
        func_ov002_0215c0f8(base);
        *(int *) (base + 0x1000 + RG(0xbc0, 0xa88)) += 1;
    } else if (state == 1) {
        *(unsigned int *) (base + 0x2000 + RG(0x47c, 0x2ac)) |= 4;
        short old = *(short *) (base + RG(0x1b00, 0x1a00) + RG(0xe0, 0xa8));
        *(short *) (base + RG(0x1b00, 0x1a00) + RG(0xe0, 0xa8)) =
            Window_GetSelectedIndex((struct Struct_0205c570 *) (base + RG(0x2c8, 0) + RG(0xc00, 0xe20)));
        if (old != *(short *) (base + RG(0x1b00, 0x1a00) + RG(0xe0, 0xa8))) return;
        if (AnyConfirm021622ec(base) || *(unsigned char *) (base + 0x1000 + RG(0xc2f, 0xaf7)) == 1) {
            GameState *gs                              = GameState::GetInstance();
            int w                                      = (int)gs->GetResources();
            *(unsigned char *) (base + 0x1000 + RG(0xc2f, 0xaf7)) = 0;
            switch (*(short *) (base + RG(0x1b00, 0x1a00) + RG(0xe0, 0xa8))) {
                case 0:
                    *(int *) (arg0 + 0x1000 + RG(0xbb8, 0xa80)) = 3;
                    *(int *) (arg0 + 0x1000 + RG(0xbc0, 0xa88)) = 0;
                    break;
                case 1:
                    if (*(signed char *) (arg0 + RG(0x1c00, 0x1b00) + RG(0x73, 0x37)) != 1) {
                        *(int *) (arg0 + 0x1000 + RG(0xbb8, 0xa80)) = 2;
                        *(int *) (arg0 + 0x1000 + RG(0xbc0, 0xa88)) = 0;
                    } else {
                        func_ov017_021a120c((GameResources*)var3, 3, func_020100a8(var2));
                        *(int *) (arg0 + 0x1000 + RG(0xbb8, 0xa80)) = RG(0x2b, 0x2e);
                        *(int *) (arg0 + 0x1000 + RG(0xbc0, 0xa88)) = 0;
                        func_02012fe4();
                        func_02017c58();
                    }
                    break;
                case 2:
                    *(int *) (arg0 + 0x1000 + RG(0xbb8, 0xa80))  = RG(0xe, 0xf);
                    *(short *) (arg0 + RG(0x1b00, 0x1a00) + RG(0xf6, 0xbe)) = 0;
                    *(int *) (arg0 + 0x1000 + RG(0xbc0, 0xa88))  = 0;
                    break;
                case 3:
                    if (!(*(unsigned int *) (arg0 + 0x2000 + RG(0x47c, 0x2ac)) & 0x20)) return;
                    *(int *) (arg0 + 0x1000 + RG(0xbb8, 0xa80)) = RG(0x10, 0x11);
                    *(int *) (arg0 + 0x1000 + RG(0xbc0, 0xa88)) = 0;
                    break;
                case 4: {
                    char *var4 = func_0205ec34();
                    if (!func_0206dfb0((int) var4, (unsigned char *) var4 + 0x8c, 0x119a)) return;
                    func_ov017_021c05f4(var3, 1, 0, 0);
                    *(int *) (arg0 + 0x1000 + RG(0xbb8, 0xa80)) = RG(0x2b, 0x2e);
                    *(int *) (arg0 + 0x1000 + RG(0xbc0, 0xa88)) = 0;
                    break;
                }
                case 5:
                    func_ov002_02161a8c(var3);
                    *(int *) (arg0 + 0x1000 + RG(0xbb8, 0xa80)) = RG(0x15, 0x16);
                    *(int *) (arg0 + 0x1000 + RG(0xbc0, 0xa88)) = 0;
                    break;
            }
            SePlayer_Play((struct SePlayer *) g_sePlayer, 1, 0);
        } else if (CheckFlagOrThreshold_02161b48(base, 1)) {
            *(unsigned char *) (base + 0x1000 + RG(0xc2f, 0xaf7)) = 0;
            if (*(unsigned int *) (base + 0x2000 + RG(0x47c, 0x2ac)) & 1) {
                func_ov023_021dca88(base + RG(0x50, 0x38));
            }
            *(int *) (arg0 + 0x1000 + RG(0xbb8, 0xa80)) = RG(0x2b, 0x2e);
        }
    }
}
