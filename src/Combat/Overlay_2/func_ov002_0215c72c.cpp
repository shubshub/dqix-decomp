#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
#define RG(u, j) (j)
extern "C" void func_02042638(char *buf, int str, int n);
#define func_02041fac func_02042638
#else
#define RG(u, j) (u)
#endif

struct Container020e0310;

extern "C" void *LinkSession_GetInstance(void);
extern "C" int func_ov002_02159774(void *self, int idx, int a, int b, int c);
extern "C" void Text_AppendFrameTag(char *buf, int x, int a, int b, int c, int d);
extern "C" void Text_AppendCursorTag(char *buf, int x);
extern "C" const char *KeyTable_Get(Container020e0310 *tbl, int key);
extern "C" void func_02041fac(char *buf, int str, int n);
extern "C" void Text_AppendPaletteTag(char *buf, int pal);
extern "C" void Text_AppendNTag(char *buf, int i, const char *str);
extern "C" void Text_Append(char *buf, const char *str);

// USA: func_ov002_0215c72c
extern "C" ARM void func_ov002_0215c72c(char *self, char *buf, int frame) {
    if (buf == 0) return;
    LinkSession_GetInstance();
    void *gs = GameState::GetInstance();
    short x  = *(short *) (self + RG(0x1be6, 0x1aae));
    int n    = 0;
    if (frame) Text_AppendFrameTag(buf, x, 8, 5, 5, 5);
    Text_AppendCursorTag(buf, x);
    func_02041fac(
        buf, (int) KeyTable_Get((Container020e0310 *) (self + RG(0x20, 0x8)), 0x44c), 0x18);
    for (int i = 0; i < *(signed char *) (self + RG(0x1c73, 0x1b37)); i++) {
        unsigned char *m = (unsigned char *)((GameState*)gs)->GetPartyMemberByIndex(((signed char *) (self + RG(0x1c6e, 0x1b32)))[i]);
        if (m != 0) {
            Text_AppendPaletteTag(buf, func_ov002_02159774(self, ((signed char *) (self + RG(0x1c6e, 0x1b32)))[i], 0, 1, 1));
            Text_AppendNTag(buf, n, *(const char **) (m + 0x134));
            Text_AppendPaletteTag(buf, 0xf);
            Text_Append(buf, *(const char **) (self + RG(0x1bdc, 0x1aa4)));
            n++;
        }
    }
    Text_AppendNTag(buf, n, KeyTable_Get((Container020e0310 *) (self + RG(0x20, 0x8)), 0x44d));
    if (*(unsigned char *) (self + RG(0x2485, 0x22b5)) == 0) {
        Text_Append(buf, *(const char **) (self + RG(0x1bdc, 0x1aa4)));
        Text_AppendNTag(buf, n + 1, KeyTable_Get((Container020e0310 *) (self + RG(0x20, 0x8)), 0x44e));
    }
}
