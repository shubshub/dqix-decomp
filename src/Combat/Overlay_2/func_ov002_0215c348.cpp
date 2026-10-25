#include "GameState/GameState.h"
#include <globaldefs.h>

#if defined(jpn)
#define RG(u, j) (j)
extern "C" int func_02042638(char *arg0, int arg1, int arg2);
#define func_02041fac func_02042638
extern "C" char data_ov002_0216d92c[];
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

// USA: func_ov002_0215c348
extern "C" ARM void func_ov002_0215c348(unsigned char *arg0, char *arg1, int arg2) {
    GameState *var0 = GameState::GetInstance();
    int var1    = *(short *) (arg0 + RG(0x1be2, 0x1aaa));
    int var2         = 0;

    if (flag) {
        Text_AppendFrameTag(dst, cursor, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursor);

#if defined(jpn)
    int var3 = (int) data_ov002_0216d92c;
#else
    int field = KeyTable_Get((struct Container020e0310 *) (base + 0x20), 0x5dc);
#endif
    func_02041fac(arg1, var3, 0x16);

    unsigned char count = *(base + RG(0x1c73, 0x1b37));
    unsigned char *ids  = base + RG(0x1c6e, 0x1b32);
    for (unsigned char i = 0; i < count; i++) {
        int id        = ids[i];
        GameObject *m = bs->GetPartyMemberByIndex(id);
        if (m != NULL) {
            int pal = func_ov002_02159774(base, id, 0, 1, 1);
            Text_AppendPaletteTag(dst, pal);
            Text_AppendNTag(dst, n, *(const char **) ((char *) m + 0x134));
            Text_AppendPaletteTag(dst, 0xf);
            n++;
            if (i != count - 1) {
                Text_Append(dst, *(const char **) (base + 0x1000 + RG(0xbdc, 0xaa4)));
            }
        }
    }
}
