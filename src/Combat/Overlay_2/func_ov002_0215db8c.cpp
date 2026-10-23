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

extern "C" void func_ov002_02157424(void *self, int *slots);
extern "C" int func_ov002_02159774(void *self, int idx, int a, int b, int c);
void AppendFrameTag02041c08(char *buf, int x, int a, int b, int c, int d);
void AppendCursorTag_02041ea4(char *buf, int x);
const char *KeyTable_Get(Container020e0310 *tbl, int key);
void AppendFormatted02041fac(char *buf, int str, int n);
void AppendPaletteTag_02041e70(char *buf, int pal);
void AppendNameTag_02041b70(char *buf, int i, const char *str);
void AppendString02042058(char *buf, const char *str);

// USA: func_ov002_0215db8c
extern "C" ARM void func_ov002_0215db8c(char *self, char *buf, int frame) {
    int slots[7];
    if (buf == 0) return;
    void *gs  = GameState::GetInstance();
    short x   = *(short *) (self + RG(0x1bf0, 0x1ab8));
    short key = 0x76d;
    func_ov002_02157424(self, slots);
    if (frame) AppendFrameTag02041c08(buf, x, 8, 5, 5, 5);
    AppendCursorTag_02041ea4(buf, x);
    AppendFormatted02041fac(
        buf, (int) KeyTable_Get((Container020e0310 *) (self + RG(0x20, 0x8)), 0x76c), 0x10);
    int slot;
    int n = *(int *) (self + RG(0x1c38, 0x1afc)) + 1;
    int i;
    for (i = 0; i < n; i++) {
        slot   = slots[i];
        int ok = (slot >= 0 && slot <= 3);
        if (ok) {
            unsigned char *m = (unsigned char *)((GameState*)gs)->GetPartyMemberByIndex(slot);
            if (m != 0) {
                AppendPaletteTag_02041e70(buf, func_ov002_02159774(self, slot, 0, 1, 1));
                AppendNameTag_02041b70(buf, i, *(const char **) (m + 0x134));
                AppendPaletteTag_02041e70(buf, 0xf);
            }
        } else {
            AppendNameTag_02041b70(buf, i, KeyTable_Get((Container020e0310 *) (self + RG(0x20, 0x8)), key++));
        }
        if (var6 != var5 - 1) func_02042058(arg1, *(const char **) (arg0 + RG(0x1bdc, 0x1aa4)));
    }
}
