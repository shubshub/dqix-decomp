#include <globaldefs.h>
#include "GameState/GameState.h"

struct BattleStruct021b9bcc;
int GameState_GetStoryStep(char* obj);

struct Struct_ov017_021d8438 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    int unknown_4_;
    int unknown_8_;
    int unknown_c_;
    int unknown_10_;
    void* unknown_14_;
    int unknown_18_;
    char unknown_1c_[4];
    int unknown_20_;
};
extern struct Struct_ov017_021d8438 data_ov017_021d8438;

// USA: func_ov017_021b9bcc
extern "C" ARM int func_ov017_021b9bcc(int arg0, void* arg1) {
    struct Struct_ov017_021b9bcc* var0 = (struct Struct_ov017_021b9bcc*)GameState::GetInstance();
    int var1 = arg0 % 80;
    int var2 = var1 / 16;
    int var3 = var1 % 16;
    int var4 = arg0 / 80;
    int var5 = data_ov017_021d8438.unknown_8_;
    if (var4 != var5 / 80) return 0;

    if (var2 == 0) {
        if (var3 <= data_ov017_021d8438.unknown_18_) {
            data_ov017_021d8438.unknown_14_ = arg1;
        } else {
            return 0;
        }
    } else if (var2 == 1) {
        if (var3 <= data_ov017_021d8438.unknown_20_) {
            data_ov017_021d8438.unknown_14_ = arg1;
        } else {
            return 0;
        }
    } else if (var2 == 2) {
        if (arg0 == var5) {
            data_ov017_021d8438.unknown_14_ = arg1;
        } else {
            return 0;
        }
    } else if (var2 == 3) {
        if (arg0 == var5) {
            data_ov017_021d8438.unknown_14_ = arg1;
        } else {
            return 0;
        }
    } else if (day == 4) {
        int v = GameState_GetStoryStep((char*)battleStruct);
        if (pos <= v && pos >= data_ov017_021d8438.fieldC) {
            data_ov017_021d8438.field14 = b;
            data_ov017_021d8438.fieldC = pos;
        } else {
            return 0;
        }
    }
    return 1;
}
