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

// USA: func_ov002_0215e9c4
extern "C" ARM void func_ov002_0215e9c4(unsigned char *arg0, char *arg1, int arg2) {
    if (arg1 == NULL) return;

    GameState *var0 = GameState::GetInstance();
    int var1    = *(short *) (arg0 + RG(0x1bf8, 0x1ac0));

    if (arg2) {
        func_02041c08(arg1, var1, 8, 5, 5, 5);
    }
    func_02041ea4(arg1, var1);

    int field = KeyTable_Get((struct Container020e0310 *) (base + RG(0x20, 0x8)), 3);
    AppendFormatted02041fac(dst, field, 0x16);

    for (int var3 = 0; var3 < *(signed char *) (arg0 + RG(0x1c73, 0x1b37)); var3++) {
        GameObject *var4 = var0->GetPartyMemberByIndex(((signed char *) (arg0 + RG(0x1c6e, 0x1b32)))[var3]);
        if (var4 != NULL) {
            int var5 = func_ov002_02159774(arg0, ((signed char *) (arg0 + RG(0x1c6e, 0x1b32)))[var3], 0, 1, 1);
            func_02041e70(arg1, var5);
            func_02041b70(arg1, var3, *(const char **) ((char *) var4 + 0x134));
            func_02041e70(arg1, 0xf);
            if (var3 != *(signed char *) (arg0 + RG(0x1c73, 0x1b37)) - 1) {
                func_02042058(arg1, *(const char **) (arg0 + RG(0x1000 + 0xbdc, 0x1000 + 0xaa4)));
            }
        }
    }
}
