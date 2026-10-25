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
void Text_AppendFrameTag(char *buf, int x, int a, int b, int c, int d);
void Text_AppendCursorTag(char *buf, int x);
const char *KeyTable_Get(Container020e0310 *tbl, int key);
void AppendFormatted02041fac(char *buf, int str, int n);
void Text_AppendPaletteTag(char *buf, int pal);
void Text_AppendNTag(char *buf, int i, const char *str);
void Text_Append(char *buf, const char *str);

// USA: func_ov002_0215db8c
extern "C" ARM void func_ov002_0215db8c(char *self, char *buf, int frame) {
    int slots[7];
    if (buf == 0) return;
    void *gs  = GameState::GetInstance();
    short x   = *(short *) (self + RG(0x1bf0, 0x1ab8));
    short key = 0x76d;
    func_ov002_02157424(self, slots);
    if (frame) Text_AppendFrameTag(buf, x, 8, 5, 5, 5);
    Text_AppendCursorTag(buf, x);
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
                Text_AppendPaletteTag(buf, func_ov002_02159774(self, slot, 0, 1, 1));
                Text_AppendNTag(buf, i, *(const char **) (m + 0x134));
                Text_AppendPaletteTag(buf, 0xf);
            }
        } else {
            Text_AppendNTag(buf, i, KeyTable_Get((Container020e0310 *) (self + RG(0x20, 0x8)), key++));
        }
        if (i != n - 1) Text_Append(buf, *(const char **) (self + RG(0x1bdc, 0x1aa4)));
    }
}
