#include "GameState/BattleRecordSnapshot.h"
#include <globaldefs.h>

extern "C" void func_020ac644(struct Struct_020ac4f8* arg0, int amount);

// USA: func_020ac6b8
extern "C" ARM void func_020ac6b8(struct Struct_020ac4f8* arg0, int amount) {
    arg0->seconds = arg0->seconds + amount;
    unsigned char var0 = arg0->seconds;
    if (var0 <= 0x3b) return;

    unsigned char var1 = var0 / 0x3c;
    if (arg0->hours == 0x270f) {
        int m = arg0->minutes + var1;
        if (m > 0x3b) {
            arg0->hours = 0x270f;
            arg0->minutes = 0x3b;
            arg0->seconds = 0x3b;
            return;
        }
    }
    func_020ac644(arg0, var1);
    arg0->seconds = arg0->seconds % 0x3c;
}
