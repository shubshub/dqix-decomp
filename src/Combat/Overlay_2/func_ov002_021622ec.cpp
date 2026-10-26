#include "GameState/GameState.h"
#include <globaldefs.h>
#include <Resource/ResourceNodeInsertion.h>
#include "Input/Input.h"

#if defined(jpn)
#define RG(u, j) (j)
#else
#define RG(u, j) (u)
#endif

struct Struct0205de24;
struct Struct_0205c570;
struct Obj_0205da38;
struct SePlayer;
extern "C" void func_0205de24(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
extern "C" int Window_GetSelectedIndex(struct Struct_0205c570 *s);
extern "C" int Window_IsSelectionTouched(struct Obj_0205da38* obj, int key);
extern "C" void SePlayer_Play(struct SePlayer *o, int a, int b);
extern "C" int func_ov002_02161b48(char *base, int a);
extern "C" void func_ov002_0215bf34(char *base);
extern "C" int GameState_GetProtagonistIndex(GameState *gs);
extern "C" int Scenario_TestFlag(int unused, unsigned char *arr, int index);
extern "C" char *Scenario_GetInstance(void);
extern "C" void func_ov002_02161cf0(void *base);
extern "C" void func_ov002_0215c0f8(void *base);
extern "C" void func_ov002_02161a8c(int w);
extern "C" void func_ov017_021c05f4(int a, int b, int c, int d);
extern "C" void func_ov023_021dca88(void *p);
extern "C" void Zone3D_GetInstance(void);
extern "C" void func_02017c58(void);
extern "C" char g_sePlayer[];

static inline int inline_ov002_021622ec(char *base) {
    return (g_keyManager.TestKeysPressed(0x601) |
            Window_IsSelectionTouched((struct Obj_0205da38*)(base + RG(0x2c8, 0) + RG(0xc00, 0xe20)), 0x14)) ? 1 : 0;
}

// USA: func_ov002_021622ec
extern "C" ARM void func_ov002_021622ec(char *base) {
    int state = *(int *) (base + 0x1000 + RG(0xbc0, 0xa88));
    if (state == 0) {
        *(unsigned char *) (base + 0x1000 + RG(0xc2f, 0xaf7)) = 0;
        *(short *) (base + RG(0x1b00, 0x1a00) + RG(0xe0, 0xa8))          = 0;
        func_0205de24((struct Struct0205de24 *) (base + RG(0x2c8, 0) + RG(0xc00, 0xe20)), 0, 2);
        func_ov002_0215bf34(base);
        func_ov002_02161cf0(base);
        func_ov002_0215c0f8(base);
        *(int *) (base + 0x1000 + RG(0xbc0, 0xa88)) += 1;
    } else if (state == 1) {
        *(unsigned int *) (base + 0x2000 + RG(0x47c, 0x2ac)) |= 4;
        short old = *(short *) (base + RG(0x1b00, 0x1a00) + RG(0xe0, 0xa8));
        *(short *) (base + RG(0x1b00, 0x1a00) + RG(0xe0, 0xa8)) =
            Window_GetSelectedIndex((struct Struct_0205c570 *) (base + RG(0x2c8, 0) + RG(0xc00, 0xe20)));
        if (old != *(short *) (base + RG(0x1b00, 0x1a00) + RG(0xe0, 0xa8))) return;
        if (inline_ov002_021622ec(base) || *(unsigned char *) (base + 0x1000 + RG(0xc2f, 0xaf7)) == 1) {
            GameState *gs                              = GameState::GetInstance();
            int w                                      = (int)gs->GetResources();
            *(unsigned char *) (base + 0x1000 + RG(0xc2f, 0xaf7)) = 0;
            switch (*(short *) (base + RG(0x1b00, 0x1a00) + RG(0xe0, 0xa8))) {
                case 0:
                    *(int *) (base + 0x1000 + RG(0xbb8, 0xa80)) = 3;
                    *(int *) (base + 0x1000 + RG(0xbc0, 0xa88)) = 0;
                    break;
                case 1:
                    if (*(signed char *) (base + RG(0x1c00, 0x1b00) + RG(0x73, 0x37)) != 1) {
                        *(int *) (base + 0x1000 + RG(0xbb8, 0xa80)) = 2;
                        *(int *) (base + 0x1000 + RG(0xbc0, 0xa88)) = 0;
                    } else {
                        func_ov017_021a120c((GameResources*)w, 3, GameState_GetProtagonistIndex(gs));
                        *(int *) (base + 0x1000 + RG(0xbb8, 0xa80)) = RG(0x2b, 0x2e);
                        *(int *) (base + 0x1000 + RG(0xbc0, 0xa88)) = 0;
                        Zone3D_GetInstance();
                        func_02017c58();
                    }
                    break;
                case 2:
                    *(int *) (base + 0x1000 + RG(0xbb8, 0xa80))  = RG(0xe, 0xf);
                    *(short *) (base + RG(0x1b00, 0x1a00) + RG(0xf6, 0xbe)) = 0;
                    *(int *) (base + 0x1000 + RG(0xbc0, 0xa88))  = 0;
                    break;
                case 3:
                    if (!(*(unsigned int *) (base + 0x2000 + RG(0x47c, 0x2ac)) & 0x20)) return;
                    *(int *) (base + 0x1000 + RG(0xbb8, 0xa80)) = RG(0x10, 0x11);
                    *(int *) (base + 0x1000 + RG(0xbc0, 0xa88)) = 0;
                    break;
                case 4: {
                    char *save = Scenario_GetInstance();
                    if (!Scenario_TestFlag((int) save, (unsigned char *) save + 0x8c, 0x119a)) return;
                    func_ov017_021c05f4(w, 1, 0, 0);
                    *(int *) (base + 0x1000 + RG(0xbb8, 0xa80)) = RG(0x2b, 0x2e);
                    *(int *) (base + 0x1000 + RG(0xbc0, 0xa88)) = 0;
                    break;
                }
                case 5:
                    func_ov002_02161a8c(w);
                    *(int *) (base + 0x1000 + RG(0xbb8, 0xa80)) = RG(0x15, 0x16);
                    *(int *) (base + 0x1000 + RG(0xbc0, 0xa88)) = 0;
                    break;
            }
            SePlayer_Play((struct SePlayer *) g_sePlayer, 1, 0);
        } else if (func_ov002_02161b48(base, 1)) {
            *(unsigned char *) (base + 0x1000 + RG(0xc2f, 0xaf7)) = 0;
            if (*(unsigned int *) (base + 0x2000 + RG(0x47c, 0x2ac)) & 1) {
                func_ov023_021dca88(base + RG(0x50, 0x38));
            }
            *(int *) (base + 0x1000 + RG(0xbb8, 0xa80)) = RG(0x2b, 0x2e);
        }
    }
}
