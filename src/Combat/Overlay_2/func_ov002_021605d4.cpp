#include <globaldefs.h>
#include "GameState/GameState.h"

class GameState;
struct Container020e0310;
struct Struct_ov002_0215b8c8 {
    char *dst;
};
struct StoreStruct;

extern "C" void func_ov002_02157480(void *self, int *slots);
extern "C" unsigned char *func_02053c6c(unsigned char *c);
extern "C" const char *KeyTable_Get(Container020e0310 *tbl, int key);
extern "C" void __clear(void *buffer, unsigned long size);
extern "C" void func_ov002_0215b8c8(Struct_ov002_0215b8c8 *dst, const char *src, int n);
extern "C" void func_02041fac(char *buf, int str, int n);
extern "C" void *MessageSystem_GetInstance();
extern "C" void func_02046380(void *messages);
extern "C" void func_020465c0(StoreStruct *messages, int index, int value);
extern "C" void func_020465f0(unsigned char *messages, int index, unsigned char digits);
extern "C" void func_020465d8(unsigned char *messages, int index, unsigned char value);
extern "C" void func_02041b00(char *buf, int h);
extern "C" void MessageSystem_FormatText(void *messages, int a, const char *format, char *output, int size, int b, int c);
extern "C" void Text_Append(char *buf, const char *str);

#if defined(jpn)
#define func_02041fac func_02042638
extern "C" int func_02042638(char *buf, int a, int b);
extern "C" void func_020474a8(void *messages, int a, const char *format, char *output);
extern char data_ov002_0216da30[];
extern char data_ov002_0216da4a[];
#endif

// USA: func_ov002_021605d4
extern "C" ARM void func_ov002_021605d4(char *self, char *buf) {
#if defined(jpn)
    int slots[4];
    char line[0x40];
    if (buf == 0) return;
    GameState *gs = GameState::GetInstance();
    short idx     = *(short *) (self + 0x1ad0);
    func_ov002_02157480(self, slots);
    int slot = slots[idx];
    int ok   = (slot >= 0 && slot <= 3);
    if (!ok) return;
    unsigned char *c = (unsigned char *) func_0200ff1c(gs, slot);
    if (c == 0) return;
    unsigned char *f = func_02053c6c(c);
    if (f == 0) return;
    func_02041fac(buf, (int) data_ov002_0216da30, 0x10);
    void *msg = MessageSystem_GetInstance();
    func_02046380(msg);
    func_020465c0((StoreStruct *) msg, 0, *(unsigned short *) (f + 0x564));
    func_020465f0((unsigned char *) msg, 0, 4);
    func_020465d8((unsigned char *) msg, 0, 1);
    __clear(line, sizeof(line));
    func_020474a8(msg, 8, data_ov002_0216da4a, line);
    Text_Append(buf, line);
#else
    char text[0x80];
    int slots[4];
    char line[0x40];
    Struct_ov002_0215b8c8 holder;
    if (buf == 0) return;
    GameState *gs = GameState::GetInstance();
    short idx     = *(short *) (self + 0x1c08);
    func_ov002_02157480(self, slots);
    int slot = slots[idx];
    int ok   = (slot >= 0 && slot <= 3);
    if (!ok) return;
    unsigned char *c = (unsigned char *) func_0200ff1c(gs, slot);
    if (c == 0) return;
    unsigned char *f = func_02053c6c(c);
    if (f == 0) return;
    const char *name = KeyTable_Get((Container020e0310 *) (self + 0x20), 0x1005);
    __clear(text, sizeof(text));
    holder.dst = text;
    func_ov002_0215b8c8(&holder, name, 0);
    func_02041fac(buf, (int) text, 0x10);
    void *msg = MessageSystem_GetInstance();
    func_02046380(msg);
    func_020465c0((StoreStruct *) msg, 0, *(unsigned short *) (f + 0x564));
    func_020465f0((unsigned char *) msg, 0, 4);
    func_020465d8((unsigned char *) msg, 0, 1);
    __clear(line, sizeof(line));
    func_02041b00(buf, -1);
    MessageSystem_FormatText(msg, 8, KeyTable_Get((Container020e0310 *) (self + 0x20), 0x1006), line,
                  0x100, 0, 0);
    Text_Append(buf, line);
#endif
}
