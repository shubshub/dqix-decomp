#include "GameState/GameState.h"
#include <globaldefs.h>

struct Container020e0310;
extern "C" int KeyTable_Get(struct Container020e0310 *c, int key);
extern "C" int Text_AppendFrameTag(char *dst, int a1, int a2, int a3, int a4, int a5);
extern "C" int Text_AppendCursorTag(char *dst, int cursor);
extern "C" int func_02041fac(char *buf, int a, int b);
extern "C" int Text_AppendPaletteTag(char *dst, int palette);
extern "C" int Text_AppendNTag(char *dst, int n, const char *name);
extern "C" int Text_Append(char *dst, const char *src);
extern "C" GameObject *func_0200ff1c(GameState *gameState, int combatantId);
extern "C" int func_ov002_02159774(void *base, int id, int a2, int a3, int a4);
extern "C" void func_ov002_02157480(void *obj, int *arr);

#if defined(jpn)
#define RG(u, j) (j)
extern "C" int func_02042638(char *buf, const char *fmt, int b);
extern "C" char data_ov002_0216da1d[];
#else
#define RG(u, j) (u)
#endif

static inline int inline_ov002_0216049c(int id) {
    return (id >= 0 && id <= 3) ? 1 : 0;
}

// USA: func_ov002_0216049c
extern "C" ARM void func_ov002_0216049c(unsigned char *base, char *dst, int flag) {
    if (dst == NULL) return;

    GameState *gs = GameState::GetInstance();
    GameObject *m;
    int id;
    int cursor = *(short *) (base + RG(0x1c08, 0x1ad0));
    int ids[4];
    func_ov002_02157480(base, ids);

    if (flag) {
        Text_AppendFrameTag(dst, cursor, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursor);

#if defined(jpn)
    func_02042638(dst, data_ov002_0216da1d, 0x10);
#else
    int field = KeyTable_Get((struct Container020e0310 *) (base + 0x20), 0x1004);
    func_02041fac(dst, field, 0x10);
#endif

    for (int i = 0; i < 4; i++) {
        id = ids[i];
        if (!inline_ov002_0216049c(id)) continue;
        m = func_0200ff1c(gs, id);
        if (m == NULL) return;
        if (i != 0) {
            Text_Append(dst, *(const char **) (base + 0x1000 + RG(0xbdc, 0xaa4)));
        }
        int pal = func_ov002_02159774(base, id, 0, 1, 1);
        Text_AppendPaletteTag(dst, pal);
        Text_AppendNTag(dst, i, *(const char **) ((char *) m + 0x134));
        Text_AppendPaletteTag(dst, 0xf);
    }
}
