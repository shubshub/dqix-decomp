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
int AppendFrameTag02041c08(char *dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag_02041ea4(char *dst, int cursor);
int AppendFormatted02041fac(char *buf, int a, int b);
int AppendPaletteTag_02041e70(char *dst, int palette);
int AppendNameTag_02041b70(char *dst, int n, const char *name);
int AppendString02042058(char *dst, const char *src);
extern "C" int func_ov002_02159774(void *base, int id, int a2, int a3, int a4);

// USA: func_ov002_0215d72c
extern "C" ARM void func_ov002_0215d72c(unsigned char *arg0, char *arg1, int arg2) {
    if (arg1 == NULL) return;

    GameState::GetInstance();
    int var0 = *(short *) (arg0 + RG(0x1bee, 0x1ab6));

    if (arg2) {
        func_02041c08(arg1, var0, 8, 5, 5, 5);
    }
    func_02041ea4(arg1, var0);

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
            AppendNameTag_02041b70(dst, i,
                          (const char *) KeyTable_Get(
                              (struct Container020e0310 *) (base + RG(0x20, 0x8)), 0x515));
            return;
        }
        int var4 = func_ov002_02159774(arg0, var3, 1, 0, 0);
        func_02041e70(arg1, var4);
        func_02041b70(arg1, var2, (const char *) (arg0 + RG(0x1ab0, 0x1a08) + var3 * RG(0x3c, 0x18)));
        func_02041e70(arg1, 0xf);
        func_02042058(arg1, *(const char **) (arg0 + RG(0x1000 + 0xbdc, 0x1000 + 0xaa4)));
    }
}
