#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Main/BattleList.h"

struct Container020e0310;

extern "C" int Text_AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5);
extern "C" int Text_AppendCursorTag(char* dst, int cursor);
extern "C" int Text_AppendNTag(char* dst, int n, const char* name);
extern "C" int Text_AppendPaletteTag(char* dst, int palette);
extern "C" int func_02041a28(char* dst, int x);
extern "C" int KeyTable_Get(struct Container020e0310* c, int key);
extern "C" int Text_Append(char* dst, const char* src);

struct Struct_ov000_02176500 {
    char pad0[0x3b];
    unsigned char unknown_3b_0_ : 1;
    unsigned char flag1 : 1;
    unsigned char flag2 : 1;
    unsigned char unknown_3b_3_ : 1;
};

struct Struct_ov000_02176500_2 {
    char pad0[0x138];
    struct Struct_ov000_02176500* stats;
};

struct Struct_ov000_02176500_3 {
    char pad0[4];
    struct Container020e0310* messages;
    char pad8[0x1c - 0x8];
    signed char cursor;
    char unknown_1d_[0x4c - 0x1d];
    int combatantId;
};

extern int data_ov000_021834f8[6];

// USA: func_ov000_02176500
extern "C" ARM void func_ov000_02176500(struct Struct_ov000_02176500_3* menu, char* dst, int arg2) {
    if (dst == NULL || menu->messages == NULL) {
        return;
    }
    GameObject* c = func_0200ff1c(GameState::GetInstance(), menu->combatantId);
    if (c == NULL) {
        return;
    }
    int flag = 0;
    if (((struct Struct_ov000_02176500_2*)c)->stats->unknown_3b_3_) {
        flag = 1;
    }
    int cursor = menu->cursor;
    if (arg2) {
        Text_AppendFrameTag(dst, cursor, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursor);
    for (int i = 0; i < 6; i++) {
        int item = data_ov000_021834f8[i];
        if (flag == 0 && item == 5) {
            Text_AppendPaletteTag(dst, 3);
        }
        Text_AppendNTag(dst, item, (const char*)KeyTable_Get(menu->messages, (short)(item + 0x7534)));
        if (i == 5) {
            return;
        }
        if (i & 1) {
            Text_Append(dst, (const char*)KeyTable_Get(menu->messages, 0));
        } else {
            func_02041a28(dst, 0x45);
        }
        Text_AppendPaletteTag(dst, 0xf);
    }
}
