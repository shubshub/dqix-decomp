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
struct Struct_0205d81c;
struct Struct_0205bcdc;
struct ShortArrays0204c610;
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
int Window_GetSelectedIndex(struct Struct_0205c570 *s);
int Window_IsSelectionTouched(struct Obj_0205da38* obj, int key);
void SePlayer_Play(struct SePlayer *o, int a, int b);
int CheckFlagOrThreshold_02161b48(char *base, int a);
char *FindElementByC40205d81c(struct Struct_0205d81c *s, int key);
void GetFourShortsAtIndex(struct ShortArrays0204c610 *p, int idx, short *a, short *b, short *c, short *d);
void SetIndexIfValid0205bcdc(struct Struct_0205bcdc *s, int idx);
void SyncModeIfChanged0215b268(char *base);
extern "C" void GridCursor_SetSelectedIndex(void *p, int idx);
extern "C" void func_ov002_02161cf0(void *base);
extern "C" void func_ov002_02160c68(void *base);
extern "C" void func_ov002_02156e90(void *base);
extern "C" void func_ov002_0215b9a4(char *self, unsigned char key, int flag);
extern "C" char g_sePlayer[];

// USA: func_ov002_02169bb0
extern "C" ARM void func_ov002_02169bb0(char *base) {
    int state = *(int *) (base + 0x1000 + RG(0xbc0, 0xa88));
    if (state == 0) {
        *(short *) (base + RG(0x1c00 + 0xe, 0x1a00 + 0xd6)) = 0;
        *(unsigned int *) (base + 0x2000 + RG(0x47c, 0x2ac)) &= ~4;
        FindAndLinkMatchingEntry0205de24((struct Struct0205de24 *) (base + RG(0x2c8 + 0xc00, 0xe20)), 0, 2);
        func_ov002_02161cf0(base);
        func_ov002_02160c68(base);
        *(int *) (base + 0x1000 + RG(0xbc0, 0xa88)) += 1;
    } else if (state == 1) {
        *(unsigned int *) (base + 0x2000 + RG(0x47c, 0x2ac)) |= 4;
        *(short *) (base + RG(0x1c00 + 0xe, 0x1a00 + 0xd6)) =
            Window_GetSelectedIndex((struct Struct_0205c570 *) (base + RG(0x2c8 + 0xc00, 0xe20)));
        unsigned char *vals[2];
        vals[0] = (unsigned char *) (base + RG(0x2c + 0x1c00, 0x2f4 + 0x1800));
        vals[1] = (unsigned char *) (base + RG(0x2d + 0x1c00, 0xf5 + 0x1a00));
        if (g_touchInput.pressed_ != 0) {
            int tx, ty;
            short x0, y0, w, h;
            g_touchInput.GetTouchPoint(&tx, &ty);
            char *e = FindElementByC40205d81c((struct Struct_0205d81c *) (base + RG(0x2c8 + 0xc00, 0xe20)), RG(0x23, 0x26));
            if (e != NULL) {
                short key = 3;
                for (unsigned char i = 0; i < 2; i++) {
                    for (unsigned char v = 1; v <= 5; v++) {
                        short ex = *(short *) (e + 0xac);
                        short ey = *(short *) (e + 0xae);
                        GetFourShortsAtIndex((struct ShortArrays0204c610 *) e, key++, &x0, &y0, &w, &h);
                        x0 += (short) (ex * 8);
                        y0 += (short) (ey * 8);
                        if (tx >= x0 && x0 + w > tx && ty >= y0 && y0 + h > ty) {
                            *(short *) (base + RG(0x1c00 + 0xe, 0x1a00 + 0xd6)) = i;
                            *vals[i]                         = v;
                            int sel                          = *(short *) (base + RG(0x1c00 + 0xe, 0x1a00 + 0xd6));
                            char *list                       = base + RG(0x2c8 + 0xc00, 0xe20);
                            SetIndexIfValid0205bcdc((struct Struct_0205bcdc *) (list + 4), sel);
                            GridCursor_SetSelectedIndex(list + 0x54, sel);
                            func_ov002_0215b9a4(base, RG(0x23, 0x26), 0);
                            SyncModeIfChanged0215b268(base);
                            return;
                        }
                    }
                }
            }
        } else {
            short var16 = *(short *) (arg0 + RG(0x1c00 + 0xe, 0x1a00 + 0xd6));
            if (var16 != 2) {
                unsigned char *var17 = var1[var16];
                int var18            = 0;
                if (g_keyManager.TestKeysPressed(0x20)) {
                    var18 = -1;
                } else if (g_keyManager.TestKeysPressed(0x10)) {
                    var18 = 1;
                }
                if (var18 != 0) {
                    *var17 += var18;
                    if (*var17 == 0) *var17 = 1;
                    if (*var17 > 5) *var17 = 5;
                    func_ov002_0215b9a4(arg0, RG(0x23, 0x26), 0);
                    func_ov002_0215b268(arg0);
                    return;
                }
            }
        }
        int a = g_keyManager.TestKeysPressed(0x601);
        int b = Window_IsSelectionTouched((struct Obj_0205da38*)(base + RG(0x2c8 + 0xc00, 0xe20)), 0x14);
        if (((a | b) ? 1 : 0) && *(short *) (base + RG(0x1c00 + 0xe, 0x1a00 + 0xd6)) == 2) {
            SePlayer_Play((struct SePlayer *) g_sePlayer, 1, 0);
            *(unsigned int *) (base + 0x2000 + RG(0x47c, 0x2ac)) &= ~4;
            func_ov002_02156e90(base);
        } else if (CheckFlagOrThreshold_02161b48(base, 1)) {
            *(unsigned int *) (base + 0x2000 + RG(0x47c, 0x2ac)) &= ~4;
            func_ov002_02156e90(base);
        }
    }
}
