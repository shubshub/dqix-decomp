#include <globaldefs.h>
#include "GameState/GameState.h"

class GameState;
struct Struct_0201099c_3;
struct Struct_ov002_0215b8c8 {
    char *unknown_0_;
};
struct Struct_020465c0;

extern "C" void func_ov002_02157480(void *self, int *slots);
unsigned char *GetFieldAt0x150_02053c6c(unsigned char *c);
const char *KeyTable_Get(Container020e0310 *tbl, int key);
extern "C" void __clear(void *buffer, unsigned long size);
void AppendTaggedString_0215b8c8(DstHolder0215b8c8 *dst, const char *src, int n);
void AppendFormatted02041fac(char *buf, int str, int n);
void *GetGlobalField0x1c020421a0();
extern "C" void func_02046380(void *messages);
void StoreInArray0x8b0_020465c0(StoreStruct *messages, int index, int value);
void SetByteInRange_020465f0(unsigned char *messages, int index, unsigned char digits);
void SetByteAtIndex_020465d8(unsigned char *messages, int index, unsigned char value);
void AppendHeightTag_02041b00(char *buf, int h);
extern "C" void func_02046608(void *messages, int a, const char *format, char *output, int size, int b, int c);
void AppendString02042058(char *buf, const char *str);

#if defined(jpn)
#define func_02041fac func_02042638
extern "C" int func_02042638(char *arg0, int arg1, int arg2);
extern "C" void func_020474a8(void *arg0, int arg1, const char *arg2, char *arg3);
extern char data_ov002_0216da30[];
extern char data_ov002_0216da4a[];
#endif

// USA: func_ov002_021605d4
extern "C" ARM void func_ov002_021605d4(char *arg0, char *arg1) {
#if defined(jpn)
    int var0[4];
    char var1[0x40];
    if (arg1 == 0) return;
    GameState *var2 = GameState::GetInstance();
    short var3     = *(short *) (arg0 + 0x1ad0);
    func_ov002_02157480(arg0, var0);
    int var4 = var0[var3];
    int var5   = (var4 >= 0 && var4 <= 3);
    if (!var5) return;
    unsigned char *var6 = (unsigned char *) func_0200ff1c(var2, var4);
    if (var6 == 0) return;
    unsigned char *var7 = func_02053c6c(var6);
    if (var7 == 0) return;
    func_02041fac(arg1, (int) data_ov002_0216da30, 0x10);
    void *var8 = func_020421a0();
    func_02046380(var8);
    func_020465c0((Struct_020465c0 *) var8, 0, *(unsigned short *) (var7 + 0x564));
    func_020465f0((unsigned char *) var8, 0, 4);
    func_020465d8((unsigned char *) var8, 0, 1);
    __clear(var1, sizeof(var1));
    func_020474a8(var8, 8, data_ov002_0216da4a, var1);
    func_02042058(arg1, var1);
#else
    char text[0x80];
    int slots[4];
    char line[0x40];
    DstHolder0215b8c8 holder;
    if (buf == 0) return;
    GameState *gs = GameState::GetInstance();
    short idx     = *(short *) (self + 0x1c08);
    func_ov002_02157480(self, slots);
    int slot = slots[idx];
    int ok   = (slot >= 0 && slot <= 3);
    if (!ok) return;
    unsigned char *c = (unsigned char *) GetCombatantWithFlag0x100_0200ff1c(gs, slot);
    if (c == 0) return;
    unsigned char *f = GetFieldAt0x150_02053c6c(c);
    if (f == 0) return;
    const char *name = KeyTable_Get((Container020e0310 *) (self + 0x20), 0x1005);
    __clear(text, sizeof(text));
    holder.dst = text;
    AppendTaggedString_0215b8c8(&holder, name, 0);
    AppendFormatted02041fac(buf, (int) text, 0x10);
    void *msg = GetGlobalField0x1c020421a0();
    func_02046380(msg);
    StoreInArray0x8b0_020465c0((StoreStruct *) msg, 0, *(unsigned short *) (f + 0x564));
    SetByteInRange_020465f0((unsigned char *) msg, 0, 4);
    SetByteAtIndex_020465d8((unsigned char *) msg, 0, 1);
    __clear(line, sizeof(line));
    AppendHeightTag_02041b00(buf, -1);
    func_02046608(msg, 8, KeyTable_Get((Container020e0310 *) (self + 0x20), 0x1006), line,
                  0x100, 0, 0);
    func_02042058(arg1, var11);
#endif
}
