#include "GameState/GameState.h"
#include <globaldefs.h>
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
struct ItemTable;
extern "C" void func_0205de24(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
extern "C" int Window_GetSelectedIndex(struct Struct_0205c570 *s);
extern "C" int Window_IsSelectionTouched(struct Obj_0205da38* obj, int key);
extern "C" void SePlayer_Play(struct SePlayer *o, int a, int b);
extern "C" char *ItemTable_Find(struct ItemTable *c, int key);
extern "C" int func_ov002_02161b48(char *base, int a);
extern "C" void func_ov002_02161798(char *base);
extern "C" void func_ov002_02161cf0(void *base);
extern "C" void func_ov002_02156e90(void *base);
extern "C" void func_ov002_0215a7b4(char *base, int actor, short key, int sel, int x);
extern "C" char g_sePlayer[];

// USA: func_ov002_0216bd34
extern "C" ARM void func_ov002_0216bd34(char *base) {
    char *gs  = (char *) GameState::GetInstance();
    int state = *(int *) (base + 0x1000 + RG(0xbc0, 0xa88));
    if (state == 0) {
        *(short *) (base + RG(0x1c00 + 0x14, 0x1a00 + 0xdc)) = 0;
        func_0205de24((struct Struct0205de24 *) (base + RG(0x2c8 + 0xc00, 0xe20)), 0, 2);
        func_ov002_02161cf0(base);
        func_ov002_02161798(base);
        *(signed char *) (base + 0x1000 + RG(0xc20, 0xae8)) = *(int *) (base + *(short *) (base + RG(0x1b00 + 0xe6, 0x1a00 + 0xae)) * 4 + 0x1000 + RG(0xc3c, 0xb00));
        if (*(signed char *) (base + RG(0x1c00 + 0x20, 0x1a00 + 0xe8)) < 0) {
            *(signed char *) (base + 0x1000 + RG(0xc20, 0xae8)) = 4;
        }
        *(int *) (base + 0x1000 + RG(0xbc0, 0xa88)) += 1;
    } else if (state == 1) {
        *(unsigned int *) (base + 0x2000 + RG(0x47c, 0x2ac)) |= 4;
        *(short *) (base + RG(0x1c00 + 0x14, 0x1a00 + 0xdc)) =
            Window_GetSelectedIndex((struct Struct_0205c570 *) (base + RG(0x2c8 + 0xc00, 0xe20)));
        int actor = *(signed char *) (base + RG(0x1c00 + 0x20, 0x1a00 + 0xe8));
        int key   = *(short *) (base + RG(0x1c00 + 0x22, 0x1a00 + 0xea));
        int done  = 0;
        int a     = g_keyManager.TestKeysPressed(0x601);
        int b     = Window_IsSelectionTouched((struct Obj_0205da38*)(base + RG(0x2c8 + 0xc00, 0xe20)), 0x14);
        if ((a | b) ? 1 : 0) {
            *(unsigned char *) (base + RG(0xf80, 0xed8)) = *(int *) (base + 0x1000 + RG(0xbb8, 0xa80));
            *(unsigned int *) (base + 0x2000 + RG(0x47c, 0x2ac)) &= ~4;
            switch (*(short *) (base + RG(0x1c00 + 0x14, 0x1a00 + 0xdc))) {
                case 0:
                    SePlayer_Play((struct SePlayer *) g_sePlayer, 1, 0);
                    *(unsigned char *) (base + 0x2000 + RG(0x487, 0x2b7)) = 1;
                    if (ItemTable_Find((struct ItemTable *) (base + RG(0x3ec + 0x400, 0x750)),
                                                                          (short) key) == NULL)
                        break;
#if defined(jpn)
                    *(unsigned short *) (gs + 0x6f00 + 0x9c) = key;
#else
                    *(unsigned short *) (gs + 0x7100 + 0xdc) = key;
                    *(unsigned short *) (gs + 0x7f00 + 0x58) = key;
#endif
                    if (key <= 0) break;
                    *(short *) (gs + RG(0x7100 + 0xde, 0x6f00 + 0x9e)) = actor;
                    if (actor < 0) break;
                    *(short *) (gs + RG(0x7100 + 0xe0, 0x6f00 + 0xa0)) = *(short *) (base + RG(0x1b00 + 0xe8, 0x1a00 + 0xb0));
                    if (*(short *) (base + RG(0x1b00 + 0xe8, 0x1a00 + 0xb0)) < 0) break;
                    if (*(unsigned char *) (base + 0x2000 + RG(0x486, 0x2b6)) != 0) {
                        if (actor >= 0 && actor <= 3) {
                            func_ov002_0215a7b4(base, actor, key, *(short *) (base + RG(0x1b00 + 0xe8, 0x1a00 + 0xb0)), 0);
                        } else {
                            func_ov002_0215a7b4(base, 4, key, *(short *) (base + RG(0x1b00 + 0xe8, 0x1a00 + 0xb0)), 0);
                        }
                    }
                    done = 1;
                    break;
                case 1:
                    SePlayer_Play((struct SePlayer *) g_sePlayer, 1, 0);
                    *(short *) (base + RG(0x1c00 + 0x14, 0x1a00 + 0xdc)) = -1;
                    func_ov002_02156e90(base);
                    done = 1;
                    break;
            }
        } else if (func_ov002_02161b48(base, 1)) {
            *(short *) (base + RG(0x1c00 + 0x14, 0x1a00 + 0xdc)) = 0;
            done                              = 1;
            func_ov002_02156e90(base);
        }
        if (!done) {
            char *g                                 = (char *) GameState::GetInstance();
#if defined(jpn)
            *(unsigned short *) (g + 0x6f00 + 0x9c) = 0;
#else
            *(unsigned short *) (g + 0x7100 + 0xdc) = 0;
            *(unsigned short *) (g + 0x7f00 + 0x58) = 0;
#endif
            *(short *) (g + RG(0x7100 + 0xde, 0x6f00 + 0x9e))          = -1;
            *(short *) (g + RG(0x7100 + 0xe0, 0x6f00 + 0xa0))          = -1;
        }
    }
}
