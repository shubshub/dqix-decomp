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
int AppendFrameTag02041c08(char *dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag_02041ea4(char *dst, int cursor);
int AppendFormatted02041fac(char *buf, int a, int b);
int AppendPaletteTag_02041e70(char *dst, int palette);
int AppendNameTag_02041b70(char *dst, int n, const char *name);
int AppendString02042058(char *dst, const char *src);
extern "C" int func_ov002_02159774(void *base, int id, int a2, int a3, int a4);

// USA: func_ov002_0215c348
extern "C" ARM void func_ov002_0215c348(unsigned char *arg0, char *arg1, int arg2) {
    GameState *var0 = GameState::GetInstance();
    int var1    = *(short *) (arg0 + RG(0x1be2, 0x1aaa));
    int var2         = 0;

    if (arg2) {
        func_02041c08(arg1, var1, 8, 5, 5, 5);
    }
    func_02041ea4(arg1, var1);

#if defined(jpn)
    int var3 = (int) data_ov002_0216d92c;
#else
    int field = KeyTable_Get((struct Container020e0310 *) (base + 0x20), 0x5dc);
#endif
    func_02041fac(arg1, var3, 0x16);

    unsigned char var4 = *(arg0 + RG(0x1c73, 0x1b37));
    unsigned char *var5  = arg0 + RG(0x1c6e, 0x1b32);
    for (unsigned char var6 = 0; var6 < var4; var6++) {
        int var7        = var5[var6];
        GameObject *var8 = var0->GetPartyMemberByIndex(var7);
        if (var8 != NULL) {
            int var9 = func_ov002_02159774(arg0, var7, 0, 1, 1);
            func_02041e70(arg1, var9);
            func_02041b70(arg1, var2, *(const char **) ((char *) var8 + 0x134));
            func_02041e70(arg1, 0xf);
            var2++;
            if (var6 != var4 - 1) {
                func_02042058(arg1, *(const char **) (arg0 + 0x1000 + RG(0xbdc, 0xaa4)));
            }
        }
    }
}
