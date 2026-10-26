#include "GameState/GameState.h"
#include <globaldefs.h>

struct Container020e0310;
struct Struct0200fb08;
extern "C" int KeyTable_Get(struct Container020e0310 *c, int key);
extern "C" int Text_AppendFrameTag(char *dst, int a1, int a2, int a3, int a4, int a5);
extern "C" int Text_AppendCursorTag(char *dst, int cursor);
extern "C" int func_02041fac(char *buf, int a, int b);
extern "C" int func_02041a28(char *dst, int x);
extern "C" int func_02041a90(char *dst, int x, int y);
extern "C" int func_02041acc(char *dst, int w);
extern "C" int func_02041cc0(char *dst, int a);
extern "C" int Text_AppendPaletteTag(char *dst, int palette);
extern "C" int Text_AppendNTag(char *dst, int n, const char *name);
extern "C" int Text_Append(char *dst, const char *src);
extern "C" int GameState_GetLanguage(struct Struct0200fb08 *p);
extern "C" int GameState_GetProtagonistIndex(GameState *gs);
extern "C" unsigned char *func_02053c6c(unsigned char *p);
extern "C" int Font_GetTextWidth(int str, int a);
extern "C" void *__clear(void *dst, int count);
extern "C" int func_ov002_02159774(void *base, int id, int a2, int a3, int a4);
struct Struct_ov002_0216ca70 {
    short a;
    short b;
};
extern "C" struct Struct_ov002_0216ca70 data_ov002_0216ca70[];
extern "C" signed char data_ov002_0216ca10[];
extern "C" int data_ov002_0216ca44[];
extern "C" int data_ov002_0216ca1c[];

struct Struct_02000c9c_64 {
    char pad[0x134];
    const char *name;
};
// USA: func_ov002_0215f8b8
extern "C" ARM void func_ov002_0215f8b8(unsigned char *base, char *dst, int flag) {
    char wa[8];
    char wb[8];
    if (dst == NULL) return;

    int cursor = *(short *) (base + 0x1c00 + 2);
    if (flag) {
        Text_AppendFrameTag(dst, cursor, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursor);
    int title = KeyTable_Get((struct Container020e0310 *) (base + 0x20), 0xfa2);
    func_02041a28(dst, (0xf0 - Font_GetTextWidth(title, 0)) >> 1);
    func_02041fac(dst, title, 0xf);

    int n                    = 0;
    GameState *gs            = GameState::GetInstance();
    unsigned char count      = *(base + 0x1000 + 0xc73);
    signed char *ids         = (signed char *) (base + 0x1c00 + 0x6e);
    int mode                 = GameState_GetLanguage((struct Struct0200fb08 *) gs);
    struct Struct_ov002_0216ca70 *xs = &data_ov002_0216ca70[mode];
    signed char *var10          = &data_ov002_0216ca10[mode * 2];
    __clear(wa, 8);
    __clear(wb, 8);
    func_02041acc(wa, var10[0]);
    func_02041acc(wb, var10[1]);
    int me = GameState_GetProtagonistIndex(gs);
    int k1 = count + 1;
    int k2 = k1 + count + 1;
    for (unsigned char i = 0; i < count; i++) {
        int id        = ids[i];
        GameObject *m = gs->GetPartyMemberByIndex(id);
        if (m == NULL) continue;
        Text_AppendPaletteTag(dst, func_ov002_02159774(base, id, 0, 1, 1));
        title = (int) m->baseStats_;
        Text_Append(dst, (const char *) title);
        func_02041a28(dst, 0x4a);
        Text_AppendPaletteTag(dst, 0xf);
        short key = (signed char) *(int *) (func_02053c6c((unsigned char *) m) + 0x94c) + 0x109c;
        if (id == me) key = 0x109b;
        Text_AppendNTag(
            dst, n,
            (const char *) KeyTable_Get((struct Container020e0310 *) (base + 0x20), key));
        func_02041a28(dst, xs->a);
        Text_AppendNTag(dst, k1, wa);
        func_02041a28(dst, xs->b);
        Text_AppendNTag(dst, k2, wb);
        Text_Append(dst, *(const char **) (base + 0x1000 + 0xbdc));
        n++;
        k1++;
        k2++;
    }
    func_02041a90(dst, 0x4a, data_ov002_0216ca44[count]);
    Text_AppendNTag(
        dst, n,
        (const char *) KeyTable_Get((struct Container020e0310 *) (base + 0x20), 0x11fa));
    func_02041cc0(dst, data_ov002_0216ca1c[count]);
}
