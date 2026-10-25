#include "GameState/GameState.h"
#include <globaldefs.h>

#if defined(jpn)
#define RG(u, j) (j)
extern "C" int func_02042638(char *arg0, int arg1, int arg2);
#define func_02041fac func_02042638
#else
#define RG(u, j) (u)
#endif

struct Container020e0310;
int KeyTable_Get(struct Container020e0310 *c, int key);
int Text_AppendFrameTag(char *dst, int a1, int a2, int a3, int a4, int a5);
int Text_AppendCursorTag(char *dst, int cursor);
int AppendFormatted02041fac(char *buf, int a, int b);
int Text_AppendPaletteTag(char *dst, int palette);
int Text_AppendNTag(char *dst, int n, const char *name);
int Text_Append(char *dst, const char *src);
extern "C" int func_ov002_02159774(void *base, int id, int a2, int a3, int a4);

// USA: func_ov002_0215d72c
extern "C" ARM void func_ov002_0215d72c(unsigned char *arg0, char *arg1, int arg2) {
    if (arg1 == NULL) return;

    GameState::GetInstance();
    int var0 = *(short *) (arg0 + RG(0x1bee, 0x1ab6));

    if (flag) {
        Text_AppendFrameTag(dst, cursor, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursor);

    int field = KeyTable_Get((struct Container020e0310 *) (base + RG(0x20, 0x8)), 0x514);
    AppendFormatted02041fac(dst, field, 0x10);

    for (int var2 = 0; var2 < *(arg0 + RG(0x1c6d, 0x1b31)) + 1; var2++) {
        int var3;
        if (var2 < *(arg0 + RG(0x1c6d, 0x1b31))) {
            var3 = *(arg0 + RG(0x1c68, 0x1b2c) + var2);
        } else {
            var3 = 4;
        }
        if (id == 4) {
            Text_AppendNTag(dst, i,
                          (const char *) KeyTable_Get(
                              (struct Container020e0310 *) (base + RG(0x20, 0x8)), 0x515));
            return;
        }
        int pal = func_ov002_02159774(base, id, 1, 0, 0);
        Text_AppendPaletteTag(dst, pal);
        Text_AppendNTag(dst, i, (const char *) (base + RG(0x1ab0, 0x1a08) + id * RG(0x3c, 0x18)));
        Text_AppendPaletteTag(dst, 0xf);
        Text_Append(dst, *(const char **) (base + RG(0x1000 + 0xbdc, 0x1000 + 0xaa4)));
    }
}
