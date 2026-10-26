#include "GameState/GameState.h"
#include <globaldefs.h>

#if defined(jpn)
#define RG(u, j) (j)
extern "C" int func_02042638(char *buf, int a, int b);
#define func_02041fac func_02042638
#else
#define RG(u, j) (u)
#endif

struct Container020e0310;
extern "C" int KeyTable_Get(struct Container020e0310 *c, int key);
extern "C" int Text_AppendFrameTag(char *dst, int a1, int a2, int a3, int a4, int a5);
extern "C" int Text_AppendCursorTag(char *dst, int cursor);
extern "C" int func_02041fac(char *buf, int a, int b);
extern "C" int Text_AppendPaletteTag(char *dst, int palette);
extern "C" int Text_AppendNTag(char *dst, int n, const char *name);
extern "C" int Text_Append(char *dst, const char *src);
extern "C" int func_ov002_02159774(void *base, int id, int a2, int a3, int a4);

// USA: func_ov002_0215d72c
extern "C" ARM void func_ov002_0215d72c(unsigned char *base, char *dst, int flag) {
    if (dst == NULL) return;

    GameState::GetInstance();
    int cursor = *(short *) (base + RG(0x1bee, 0x1ab6));

    if (flag) {
        Text_AppendFrameTag(dst, cursor, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursor);

    int field = KeyTable_Get((struct Container020e0310 *) (base + RG(0x20, 0x8)), 0x514);
    func_02041fac(dst, field, 0x10);

    for (int i = 0; i < *(base + RG(0x1c6d, 0x1b31)) + 1; i++) {
        int id;
        if (i < *(base + RG(0x1c6d, 0x1b31))) {
            id = *(base + RG(0x1c68, 0x1b2c) + i);
        } else {
            id = 4;
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
