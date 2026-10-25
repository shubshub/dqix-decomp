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

// USA: func_ov002_0215e9c4
extern "C" ARM void func_ov002_0215e9c4(unsigned char *arg0, char *arg1, int arg2) {
    if (arg1 == NULL) return;

    GameState *var0 = GameState::GetInstance();
    int var1    = *(short *) (arg0 + RG(0x1bf8, 0x1ac0));

    if (flag) {
        Text_AppendFrameTag(dst, cursor, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursor);

    int field = KeyTable_Get((struct Container020e0310 *) (base + RG(0x20, 0x8)), 3);
    AppendFormatted02041fac(dst, field, 0x16);

    for (int i = 0; i < *(signed char *) (base + RG(0x1c73, 0x1b37)); i++) {
        GameObject *m = bs->GetPartyMemberByIndex(((signed char *) (base + RG(0x1c6e, 0x1b32)))[i]);
        if (m != NULL) {
            int pal = func_ov002_02159774(base, ((signed char *) (base + RG(0x1c6e, 0x1b32)))[i], 0, 1, 1);
            Text_AppendPaletteTag(dst, pal);
            Text_AppendNTag(dst, i, *(const char **) ((char *) m + 0x134));
            Text_AppendPaletteTag(dst, 0xf);
            if (i != *(signed char *) (base + RG(0x1c73, 0x1b37)) - 1) {
                Text_Append(dst, *(const char **) (base + RG(0x1000 + 0xbdc, 0x1000 + 0xaa4)));
            }
        }
    }
}
