#include "GameState/BattleRecordSnapshot.h"
#include <globaldefs.h>

extern "C" void func_020ac614(struct Struct_020ac4f8* arg0, int amount);

// USA: func_020ac644
extern "C" ARM void func_020ac644(struct Struct_020ac4f8* arg0, int amount) {
    arg0->minutes = arg0->minutes + amount;
    unsigned char var0 = arg0->minutes;
    if (var0 <= 0x3b) return;

    unsigned short var1 = var0 / 0x3c;
    if ((int)(arg0->hours + var1) > 0x270f) {
        arg0->hours = 0x270f;
        arg0->minutes = 0x3b;
        arg0->seconds = 0x3b;
        return;
    }

    func_020ac614(arg0, var1);
    arg0->minutes = arg0->minutes % 0x3c;
}
