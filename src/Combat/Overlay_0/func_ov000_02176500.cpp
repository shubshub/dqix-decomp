#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Main/BattleList.h"

struct Struct_0201099c_3;

int Text_AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5);
int Text_AppendCursorTag(char* dst, int cursor);
int Text_AppendNTag(char* dst, int n, const char* name);
int Text_AppendPaletteTag(char* dst, int palette);
int AppendXTag_02041a28(char* dst, int x);
int KeyTable_Get(struct Container020e0310* c, int key);
int Text_Append(char* dst, const char* src);

struct Struct_ov000_02176500 {
    char unknown_0_[0x3b];
    unsigned char unknown_3b_0_ : 1;
    unsigned char unknown_3b_1_ : 1;
    unsigned char unknown_3b_2_ : 1;
    unsigned char unknown_3b_3_ : 1;
};

struct Struct_ov000_02176500_2 {
    char unknown_0_[0x138];
    struct Struct_ov000_02176500* unknown_138_;
};

struct Struct_ov000_02176500_3 {
    char unknown_0_[4];
    struct Struct_0201099c_3* unknown_4_;
    char unknown_8_[0x1c - 0x8];
    signed char unknown_1c_;
    char unknown_1d_[0x4c - 0x1d];
    int unknown_4c_;
};

extern int data_ov000_021834f8[6];

// USA: func_ov000_02176500
extern "C" ARM void func_ov000_02176500(struct Struct_ov000_02176500_3* arg0, char* arg1, int arg2) {
    if (arg1 == NULL || arg0->unknown_4_ == NULL) {
        return;
    }
    GameObject* var0 = func_0200ff1c(GameState::GetInstance(), arg0->unknown_4c_);
    if (var0 == NULL) {
        return;
    }
    int var1 = 0;
    if (((struct Struct_ov000_02176500_2*)var0)->unknown_138_->unknown_3b_3_) {
        var1 = 1;
    }
    int cursor = menu->cursor;
    if (framed) {
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
            func_02041a28(arg1, 0x45);
        }
        Text_AppendPaletteTag(dst, 0xf);
    }
}
