#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
#define RG(u, j) (j)
extern "C" void func_02042638(char *arg0, int arg1, int arg2);
#define func_02041fac func_02042638
#else
#define RG(u, j) (u)
#endif

struct Struct_0201099c_3;

extern "C" void *func_0202ae18(void);
extern "C" int func_ov002_02159774(void *self, int idx, int a, int b, int c);
void AppendFrameTag02041c08(char *buf, int x, int a, int b, int c, int d);
void AppendCursorTag_02041ea4(char *buf, int x);
const char *KeyTable_Get(Container020e0310 *tbl, int key);
void AppendFormatted02041fac(char *buf, int str, int n);
void AppendPaletteTag_02041e70(char *buf, int pal);
void AppendNameTag_02041b70(char *buf, int i, const char *str);
void AppendString02042058(char *buf, const char *str);

// USA: func_ov002_0215c72c
extern "C" ARM void func_ov002_0215c72c(char *arg0, char *arg1, int arg2) {
    if (arg1 == 0) return;
    func_0202ae18();
    void *gs = GameState::GetInstance();
    short x  = *(short *) (self + RG(0x1be6, 0x1aae));
    int n    = 0;
    if (frame) AppendFrameTag02041c08(buf, x, 8, 5, 5, 5);
    AppendCursorTag_02041ea4(buf, x);
    AppendFormatted02041fac(
        buf, (int) KeyTable_Get((Container020e0310 *) (self + RG(0x20, 0x8)), 0x44c), 0x18);
    for (int i = 0; i < *(signed char *) (self + RG(0x1c73, 0x1b37)); i++) {
        unsigned char *m = (unsigned char *)((GameState*)gs)->GetPartyMemberByIndex(((signed char *) (self + RG(0x1c6e, 0x1b32)))[i]);
        if (m != 0) {
            AppendPaletteTag_02041e70(buf, func_ov002_02159774(self, ((signed char *) (self + RG(0x1c6e, 0x1b32)))[i], 0, 1, 1));
            AppendNameTag_02041b70(buf, n, *(const char **) (m + 0x134));
            AppendPaletteTag_02041e70(buf, 0xf);
            AppendString02042058(buf, *(const char **) (self + RG(0x1bdc, 0x1aa4)));
            n++;
        }
    }
    AppendNameTag_02041b70(buf, n, KeyTable_Get((Container020e0310 *) (self + RG(0x20, 0x8)), 0x44d));
    if (*(unsigned char *) (self + RG(0x2485, 0x22b5)) == 0) {
        AppendString02042058(buf, *(const char **) (self + RG(0x1bdc, 0x1aa4)));
        AppendNameTag_02041b70(buf, n + 1, KeyTable_Get((Container020e0310 *) (self + RG(0x20, 0x8)), 0x44e));
    }
}
